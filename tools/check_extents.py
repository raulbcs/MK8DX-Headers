#!/usr/bin/env python3
"""Strict layout linter for MK8DX-Headers.

The header package is the source of truth for layout; this script enforces it
mechanically. For every .hpp under include/ with field declarations:

Checks
  1. OVERLAP      — two fields/pads covering the same byte -> error.
  2. COVERAGE     — inside the cited extent, every byte must belong to a field
                    or to a pad carrying an evidence note ("unproven", "ctor
                    writes nothing", "gap", ...). Orphan bytes -> error; a pad
                    with no note at all -> error.
  3. ALIGNMENT    — a field of size N at an offset not a multiple of N ->
                    warning only (char arrays are exempt by design).
  4. EXTENT       — a header with fields but no cited extent must appear in
                    the embedded NO_EXTENT_ALLOWLIST below (sorted, one path
                    per line). Shrinking the allowlist is good; growth prints
                    a warning.
  5. Extent bound — max field end must not exceed the cited extent.

False positives respected: virtual declarations (slots are not fields),
docblock/comment-only lines, inheritance (base extent cited as
"base ... extent 0xNN" / "subobject at 0xNN"; otherwise coverage is only
checked from the first own field), and docblock-only headers (no fields).

Exit codes: 0 = clean (warnings allowed), 1 = violations.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INCLUDE = ROOT / "include"

OFFSET_LIMIT = 0x10000  # larger hex constants are VMAs, not offsets

# ---------------------------------------------------------------------------
# Embedded allowlist: headers WITH field declarations but WITHOUT a cited
# extent. Sorted. Keep this list shrinking; growth means a header lost its
# extent citation (suspicious) or a new header was added without one.
# ---------------------------------------------------------------------------
NO_EXTENT_ALLOWLIST = """
# Headers with field declarations but no cited extent (docblock evidence
# pending). Sorted. Keep shrinking.
#   include/_nn/account/NetworkServiceAccountId.hpp
#   include/_nn/account/Uid.hpp
#   include/_nn/ae/AppletThreadHost.hpp
#   include/_nn/ae/ErrorAppletThread.hpp
#   include/_nn/ae/OeMessageDispatchThread.hpp
#   include/_nn/ae/TimeSyncThread.hpp
#   include/_nn/atk/BiquadFilter.hpp
#   include/_nn/atk/detail/driver/SoundThread.hpp
#   include/_nn/friends/Friend.hpp
#   include/_nn/friends/FriendPresence.hpp
#   include/_nn/nex/Buffer.hpp
#   include/_nn/nex/CallContext.hpp
#   include/_nn/nex/ClientProtocol.hpp
#   include/_nn/nex/Credentials.hpp
#   include/_nn/nex/EventLog.hpp
#   include/_nn/nex/JobAcquireAccessToken.hpp
#   include/_nn/nex/JobBackEndServicesTerminate.hpp
#   include/_nn/nex/JobCallContextCallback.hpp
#   include/_nn/nex/JobDeriveKey.hpp
#   include/_nn/nex/JobHttp.hpp
#   include/_nn/nex/JobNNIDLogin.hpp
#   include/_nn/nex/JobProcessProtocolMessage.hpp
#   include/_nn/nex/ObjectThreadRoot.hpp
#   include/_nn/nex/ProtocolCallContext.hpp
#   include/_nn/nex/_DDL_AuthenticationInfo.hpp
#   include/_nn/pia/session/DestroySessionJob.hpp
#   include/_nn/pia/session/JoinMeshJob.hpp
#   include/_nn/pia/session/LeaveSessionJob.hpp
#   include/enl/Buffer.hpp
#   include/enl/Connection/ConnectInfo.hpp
#   include/enl/ContentTransporter/ContentTransporterCommon.hpp
#   include/enl/ContentTransporter/ContentTransporterForMulti.hpp
#   include/enl/Framework.hpp
#   include/enl/Peer/UniqueID.hpp
#   include/enl/TaskThread.hpp
#   include/eui/ControlBase.hpp
#   include/eui/LayoutEx.hpp
#   include/eui/Screen/Screen.hpp
#   include/eui/Screen/ScreenMgr.hpp
#   include/gear/Account/account.hpp
#   include/gear/Background/BackgroundLoadThread.hpp
#   include/gear/Controller/ControllerRaceNX.hpp
#   include/gear/Course/CourseDecompThread.hpp
#   include/gear/Framework/FrameworkGameScene.hpp
#   include/gear/Ghost/RaceTime.hpp
#   include/gear/Item/ItemDirector.hpp
#   include/gear/Item/ItemEvent.hpp
#   include/gear/Item/ItemEventContent.hpp
#   include/gear/Item/ItemEventManager.hpp
#   include/gear/Item/ItemOwner.hpp
#   include/gear/Item/ItemReact.hpp
#   include/gear/Item/ItemReactInfo.hpp
#   include/gear/Item/ItemSlot.hpp
#   include/gear/Item/Obj/ItemObjBase.hpp
#   include/gear/Item/Obj/ItemObjKouraG.hpp
#   include/gear/MapObj/IMapObjBounce.hpp
#   include/gear/MapObj/MapObjBase.hpp
#   include/gear/MapObj/MapObjDirector.hpp
#   include/gear/MapObj/MapObjDrawManager.hpp
#   include/gear/MapObj/MapObjParameter.hpp
#   include/gear/Math/Matrix.hpp
#   include/gear/Network/NetworkDataAllPlayerInfo.hpp
#   include/gear/Network/NetworkDataMenuCourseVote.hpp
#   include/gear/Network/NetworkDataPlayerInfo.hpp
#   include/gear/Network/Transporter/NetworkTransporterAllPlayerInfo.hpp
#   include/gear/NetworkTaskThread.hpp
#   include/gear/Object/ObjectBase.hpp
#   include/gear/Player/Player.hpp
#   include/gear/Player/PlayerInfo.hpp
#   include/gear/Player/PlayerManager.hpp
#   include/gear/Race/LapRankChecker.hpp
#   include/gear/Race/RaceDirectorBase38.hpp
#   include/gear/Race/RaceDirectorManager.hpp
#   include/gear/Race/RaceDirectorManagerBase.hpp
#   include/gear/Race/RaceDirectorPlayer.hpp
#   include/gear/Race/RaceDirectorPlayerBase.hpp
#   include/gear/Race/RaceDirectorPlayerSetBase.hpp
#   include/gear/Race/RaceDirectorSetChain.hpp
#   include/gear/Race/RaceDirectorSetHelper.hpp
#   include/gear/Race/RaceDirectorSetStatePod.hpp
#   include/gear/Race/RaceDirectorSubActor60.hpp
#   include/gear/Race/RaceDirectorVt10.hpp
#   include/gear/Race/RaceDirectorVt2.hpp
#   include/gear/Race/RaceDirectorVt3.hpp
#   include/gear/Race/RaceDirectorVt4.hpp
#   include/gear/Race/RaceDirectorVt5.hpp
#   include/gear/Race/RaceDirectorVt6.hpp
#   include/gear/Race/RaceDirectorVt7.hpp
#   include/gear/Race/RaceDirectorVt8.hpp
#   include/gear/Race/RaceDirectorVt9.hpp
#   include/gear/Race/RaceInfo.hpp
#   include/gear/Race/RaceKartInfo.hpp
#   include/gear/Race/RaceKartResult.hpp
#   include/gear/Race/RaceListItemE.hpp
#   include/gear/Race/RaceListItemF.hpp
#   include/gear/Race/RaceListItemG.hpp
#   include/gear/Race/RacePlayerInfo.hpp
#   include/gear/Record/RecordFile.hpp
#   include/gear/Resource/Race/ResourceGSysModelCache.hpp
#   include/gear/Resource/Race/ResourceRaceCache.hpp
#   include/gear/Resource/Race/ResourceRaceCommon.hpp
#   include/gear/Resource/ResourceLoader.hpp
#   include/gear/RigidBody.hpp
#   include/gear/SaveData.hpp
#   include/gear/SaveData/SaveDataFile.hpp
#   include/gear/SaveData/SaveDataManager.hpp
#   include/gear/SaveData/SaveDataManagerThread.hpp
#   include/gear/SystemEngine.hpp
#   include/gear/UI/Flow/UIFlow.hpp
#   include/gear/UI/Flow/UIFlow_Open.hpp
#   include/gear/UI/Input/UICursor.hpp
#   include/gear/UI/Input/UIInput_Touch.hpp
#   include/gear/UI/Page/UIPage.hpp
#   include/gear/UI/Page/UIPageCreator.hpp
#   include/gear/UI/UIAnimator.hpp
#   include/gear/UI/UIArchive.hpp
#   include/gear/UI/UIControl.hpp
#   include/gear/UI/UIEvent.hpp
#   include/gear/UI/UIHeap.hpp
#   include/gear/UI/UIInput_Key.hpp
#   include/gear/UI/UILoader.hpp
#   include/gear/UI/UIMiiThread.hpp
#   include/gear/UI/UINFPThread.hpp
#   include/gear/UI/UIPlayer.hpp
#   include/gear/UI/UITheaterThread.hpp
#   include/gsys/Animation/AnimationAccessKey.hpp
#   include/gsys/Model/Model.hpp
#   include/gsys/Model/ModelInfo.hpp
#   include/gsys/Model/ModelResource.hpp
#   include/kart/BoostSlot.hpp
#   include/kart/KartVehicleMove.hpp
#   include/kart/SteeringX.hpp
#   include/mush/Message/MessageArchive.hpp
#   include/object/Kart/AudioTaskThread.hpp
#   include/object/Kart/BackgroundLoadThread.hpp
#   include/object/Kart/ContentsThread.hpp
#   include/object/Kart/KartBodyVt71.hpp
#   include/object/Kart/KartCalcSpeedMiniCore.hpp
#   include/object/Kart/KartCamera.hpp
#   include/object/Kart/KartChassis.hpp
#   include/object/Kart/KartChassisAnim.hpp
#   include/object/Kart/KartDirector.hpp
#   include/object/Kart/KartJugemRecover.hpp
#   include/object/Kart/KartModelBackgroundLoadThread.hpp
#   include/object/Kart/KartParamCacheChan.hpp
#   include/object/Kart/KartParamCacheChanBase.hpp
#   include/object/Kart/KartParamCacheCloud.hpp
#   include/object/Kart/KartParamCacheCloudDraw.hpp
#   include/object/Kart/KartParamCacheCloudTex.hpp
#   include/object/Kart/KartParamCacheColorCorrection.hpp
#   include/object/Kart/KartParamCacheColorCorrectionSub.hpp
#   include/object/Kart/KartParamCacheCubeMap.hpp
#   include/object/Kart/KartParamCacheDecal.hpp
#   include/object/Kart/KartParamCacheDecalAo.hpp
#   include/object/Kart/KartParamCacheEnv.hpp
#   include/object/Kart/KartParamCacheLightMap.hpp
#   include/object/Kart/KartParamCacheLref.hpp
#   include/object/Kart/KartParamCacheMid2.hpp
#   include/object/Kart/KartParamCacheNodeBase.hpp
#   include/object/Kart/KartParamCacheNormalDrawer.hpp
#   include/object/Kart/KartParamCacheOfx.hpp
#   include/object/Kart/KartParamCacheProjShadow.hpp
#   include/object/Kart/KartParamCacheShadow.hpp
#   include/object/Kart/KartParamCacheShadowPP.hpp
#   include/object/Kart/KartParamCacheSky.hpp
#   include/object/Kart/KartParamCacheSsao.hpp
#   include/object/Kart/KartParamCacheVolumeMask.hpp
#   include/object/Kart/KartParamCacheVt24c8.hpp
#   include/object/Kart/KartParamCacheVt33b0.hpp
#   include/object/Kart/KartParamCacheVt36b8.hpp
#   include/object/Kart/KartParamCacheVt3df8.hpp
#   include/object/Kart/KartParamCacheVtd608.hpp
#   include/object/Kart/KartParameter.hpp
#   include/object/Kart/KartPhysicsBodyKiller.hpp
#   include/object/Kart/KartPhysicsBodyKoura.hpp
#   include/object/Kart/KartPhysicsBodyMid.hpp
#   include/object/Kart/KartPhysicsBodyPackun.hpp
#   include/object/Kart/KartPhysicsBodySHorn.hpp
#   include/object/Kart/KartPhysicsBodyTeresa.hpp
#   include/object/Kart/KartPhysicsBodyTeresaVt108.hpp
#   include/object/Kart/KartPhysicsBodyTeresaVt97.hpp
#   include/object/Kart/KartPhysicsBodyUseItem.hpp
#   include/object/Kart/KartPhysicsBodyVt96a.hpp
#   include/object/Kart/KartPhysicsBodyVt96b.hpp
#   include/object/Kart/KartPhysicsBodyVt96c.hpp
#   include/object/Kart/KartPhysicsBodyVt96d.hpp
#   include/object/Kart/KartPhysicsBodyVt97.hpp
#   include/object/Kart/KartRecorderChannels.hpp
#   include/object/Kart/KartRecorderKey.hpp
#   include/object/Kart/KartSteerAssist.hpp
#   include/object/Kart/KartSusKit.hpp
#   include/object/Kart/KartUnit.hpp
#   include/object/Kart/KartUnitHolder.hpp
#   include/object/Kart/KartVehicleBalloon.hpp
#   include/object/Kart/KartVehicleBody.hpp
#   include/object/Kart/KartVehicleCollision.hpp
#   include/object/Kart/KartVehicleControl.hpp
#   include/object/Kart/KartVehicleCpu.hpp
#   include/object/Kart/KartVehicleDrift.hpp
#   include/object/Kart/KartVehicleHeadLight.hpp
#   include/object/Kart/KartVehicleNet.hpp
#   include/object/Kart/KartVehicleReact.hpp
#   include/object/Kart/KartVehicleTrick.hpp
#   include/object/Kart/LowPrioWorkerThread.hpp
#   include/object/Kart/NetworkSendThread.hpp
#   include/object/Kart/ParamChannelVt38f8.hpp
#   include/object/Kart/ParamContainerVt29a8.hpp
#   include/object/Kart/ParamContainerVt4920.hpp
#   include/object/Kart/ParamContainerVt4aa0.hpp
#   include/object/Kart/ParamContainerVtadb8.hpp
#   include/object/Kart/ParamContainerVtb0b8.hpp
#   include/object/Kart/ParamContainerVtb1e8.hpp
#   include/object/Kart/ParamContainerVtb448.hpp
#   include/object/Kart/ParamContainerVtb578.hpp
#   include/object/Kart/ParamContainerVtb690.hpp
#   include/object/Kart/ParamContainerVtbc88.hpp
#   include/object/Kart/ParamContainerVtc338.hpp
#   include/object/Kart/ParamContainerVtdcd8.hpp
#   include/object/Kart/ParamMultiChanVt2808.hpp
#   include/object/Kart/ParamMultiChanVt2c40.hpp
#   include/object/Kart/ParamMultiChanVt2da0.hpp
#   include/object/Kart/ParamMultiChanVtb318.hpp
#   include/object/Kart/ParamMultiChanVtba40.hpp
#   include/object/Kart/ParamMultiChanVtbb50.hpp
#   include/object/Kart/ParamMultiChanVtbdb8.hpp
#   include/object/Kart/ParamMultiChanVtc0f0.hpp
#   include/object/Kart/ParamMultiChanVtc200.hpp
#   include/object/Kart/ParamMultiChanVtc468.hpp
#   include/object/Kart/ParamMultiChanVtd7b0.hpp
#   include/object/Kart/ParamMultiChanVtd900.hpp
#   include/object/Kart/ParamMultiChanVtda50.hpp
#   include/object/Kart/ParamNodeDirectionalLight.hpp
#   include/object/Kart/ParamNodeEnvObjName.hpp
#   include/object/Kart/ParamNodeModelBinding.hpp
#   include/object/Kart/ParamNodePseudoOcclusion.hpp
#   include/object/Kart/ParamNodeVt2198.hpp
#   include/object/Kart/ParamNodeVt25f0.hpp
#   include/object/Kart/ParamNodeVt26c0.hpp
#   include/object/Kart/ParamNodeVt2b90.hpp
#   include/object/Kart/ParamNodeVt2df8.hpp
#   include/object/Kart/ParamNodeVt2e50.hpp
#   include/object/Kart/ParamNodeVt2ea8.hpp
#   include/object/Kart/ParamNodeVt2fb0.hpp
#   include/object/Kart/ParamNodeVt32a8.hpp
#   include/object/Kart/ParamNodeVt35a8.hpp
#   include/object/Kart/ParamNodeVt3898.hpp
#   include/object/Kart/ParamNodeVt3f08.hpp
#   include/object/Kart/ParamNodeVt3fd8.hpp
#   include/object/Kart/ParamNodeVt4140.hpp
#   include/object/Kart/ParamNodeVt4510.hpp
#   include/object/Kart/ParamNodeVt4688.hpp
#   include/object/Kart/ParamNodeVt47a0.hpp
#   include/object/Kart/ParamNodeVt4c70.hpp
#   include/object/Kart/ParamNodeVt4eb8.hpp
#   include/object/Kart/ParamNodeVt7780.hpp
#   include/object/Kart/ParamNodeVtaf38.hpp
#   include/object/Kart/ParamNodeVtc848.hpp
#   include/object/Kart/ParamNodeVtc8a0.hpp
#   include/object/Kart/ParamNodeVtc8f8.hpp
#   include/object/Kart/ParamNodeVtd500.hpp
#   include/object/Kart/ParamNodeVtd558.hpp
#   include/object/Kart/ParamNodeVtd5b0.hpp
#   include/object/Kart/ParamNodeVtdba0.hpp
#   include/object/Kart/ParamNodeVtde48.hpp
#   include/object/Kart/UILoadThread.hpp
#   include/object/Kart/UIMovieRecreatingThread.hpp
#   include/object/Kart/UINFPArchiveThread.hpp
#   include/object/Kart/VibrationThread.hpp
#   include/object/Kart/Vt3dcf300bb8.hpp
#   include/object/Kart/Vt3dcf3018f8.hpp
#   include/object/Kart/Vt3dcf307018.hpp
#   include/object/Kart/Vt3dcf308480.hpp
#   include/object/MapObj/MapObjItemBox.hpp
#   include/object/MapObj/MapObjVehicleBase.hpp
#   include/object/ObjectEngine.hpp
#   include/object/Race/RaceCheckerBase.hpp
#   include/object/Race/RaceCheckerVt2.hpp
#   include/object/Race/RaceCheckerVt3.hpp
#   include/object/Race/RaceKartChecker.hpp
#   include/object/Record/RecordFileKart.hpp
#   include/object/Record/RecordFileManager.hpp
#   include/object/Vt11bb080.hpp
#   include/object/Vt12ba010.hpp
#   include/object/Vt12ca000.hpp
#   include/object/Vt12f3160.hpp
#   include/recorder/Recorder.hpp
#   include/repl/File.hpp
#   include/repl/SZSThread.hpp
#   include/repl/Thread.hpp
#   include/sead/Container.hpp
#   include/ui/Buttons/Control_BackButton.hpp
#   include/ui/Buttons/Control_Button.hpp
#   include/ui/Buttons/Control_CourseButton.hpp
#   include/ui/Buttons/Control_CupButton.hpp
#   include/ui/Buttons/Control_DLCLButton.hpp
#   include/ui/Control/Control_GhostBase.hpp
#   include/ui/Control/Control_GhostDetail.hpp
#   include/ui/Control/Control_RivalGhost.hpp
#   include/ui/Control/Control_RivalGhostVolume.hpp
#   include/ui/Control/Control_RuleList.hpp
#   include/ui/Control/Control_Scroll.hpp
#   include/ui/Course/CourseInfo.hpp
#   include/ui/Heap/Heap_Common.hpp
#   include/ui/Heap_CommonInfo.hpp
#   include/ui/Page/Page_BGMTest.hpp
#   include/ui/Page/Page_Bg.hpp
#   include/ui/Page/Page_CourseBase.hpp
#   include/ui/Page/Page_CourseBattle.hpp
#   include/ui/Page/Page_Dialog.hpp
#   include/ui/Page/Page_Ghost.hpp
#   include/ui/Page/Page_Ghost_ScrollList.hpp
#   include/ui/Page/Page_Login.hpp
#   include/ui/Page/Page_Race.hpp
#   include/ui/Page/Page_TitleSelect.hpp
#   include/ui/RaceWindow.hpp
#   include/ui/Rule/UIRule.hpp
#   include/ui/Texture/Bntx.hpp
#   include/ui/TimeAttack/TAData.hpp
#   include/xlink2/BoneMtx.hpp
#   include/xlink2/Locator.hpp
"""

# Words that count as an evidence note on a pad line.
EVIDENCE = re.compile(
    r"unproven|gap|ctor|unmapped|unknown|pending|reserved|padding|evidence|"
    r"remaining|rest of|undefined|unused|no layout|not laid out|to 0x|write|"
    r"memset|zero|tail|sdk|internal|proven|strb|flag",
    re.I,
)

# A "... base region ..." field annotates an embedded base sub-object that is
# ALSO mapped field-by-field right below it (e.g. nex job headers). It is an
# annotation, not an interval of its own: excluded from overlap/coverage and
# exempt from the pad-note rule.
BASE_REGION_FIELD = re.compile(r"base region", re.I)

OFFSET_COMMENT = re.compile(r"//\s*[-—]?\s*0x([0-9a-fA-F]{1,5})\b")
FIXED_BY = re.compile(r"fixed by\s+\S+\s+at\s+0x([0-9a-fA-F]+)\b", re.I)
ANY_COMMENT = re.compile(r"//")

EXTENT_PATTERNS = [
    re.compile(r"extent\s+(?:is\s+|from\s+|of\s+|=|fixed by\s+\S+\s+at)?0x([0-9a-fA-F]+)", re.I),
    re.compile(r"concrete size\s+0x([0-9a-fA-F]+)", re.I),
    re.compile(r"news\[0x([0-9a-fA-F]+)\]", re.I),
    re.compile(r"allocation[^.]*?size\s+0x([0-9a-fA-F]+)", re.I),
    re.compile(r"\bsize\s+0x([0-9a-fA-F]+)\s*\(", re.I),
]
STRICT_EXTENT_NEG = re.compile(r"extent\s*(>=)", re.I)
SUBOBJECT_LINE = re.compile(r"sub-?object|base region", re.I)
SUBOBJECT_TO = re.compile(r"extent\s+0x[0-9a-fA-F]+,?\s+to\s", re.I)

BASE_DECL = re.compile(r"\bclass\s+\w+\s*:\s*public\b")
BASE_EXTENT = re.compile(
    r"(?:base|sub-?object)[^;\n]{0,120}?(?:extent|size)\s+0x([0-9a-fA-F]+)", re.I
)
SUBOBJECT_AT = re.compile(r"sub-?object\s+at\s+0x([0-9a-fA-F]+)", re.I)

# A field declaration: TYPE NAME[ARR]; optionally trailing // comment.
# No parentheses (methods), not virtual/using/typedef/static/etc.
SKIP_PREFIX = ("virtual", "typedef", "using", "friend", "static", "enum",
               "struct", "class", "return", "}", "{", "#", "*", "/*")
DECL = re.compile(
    r"^\s*(?:inline\s+)?([A-Za-z_][\w:]*)\s*((?:\*+\s*|\s*&\s*)?)"
    r"(\w+)\s*(\[[^\]]*\])?\s*(?:=[^;]*)?;"
)

BASIC_SIZES = {
    "u64": 8, "uint64_t": 8, "s64": 8, "int64_t": 8, "unsigned": 8,
    "size_t": 8, "long": 8, "double": 8, "f64": 8,
    "u32": 4, "uint32_t": 4, "s32": 4, "int32_t": 4, "int": 4,
    "float": 4, "f32": 4, "unsigned int": 4,
    "u16": 2, "uint16_t": 2, "s16": 2, "int16_t": 2, "short": 2,
    "u8": 1, "uint8_t": 1, "s8": 1, "int8_t": 1, "char": 1,
    "bool": 1, "_Bool": 1, "sBool": 1, "wchar_t": 4,
}


def h(s):
    return int(s, 16)


def array_size(expr):
    expr = expr.strip()
    m = re.fullmatch(r"0x([0-9a-fA-F]+)", expr)
    if m:
        return h(m.group(1))
    if re.fullmatch(r"\d+", expr):
        return int(expr)
    if re.fullmatch(r"sizeof\([^)]*\)", expr):
        return None  # unknown
    return None


def type_size(base, is_ptr):
    if is_ptr:
        return 8
    base = base.strip()
    if base in BASIC_SIZES:
        return BASIC_SIZES[base]
    if base in ("unsigned int", "unsigned long"):
        return 4 if base == "unsigned int" else 8
    if re.match(r"unsigned\s+\w+", base):
        tail = base.split()[-1]
        return BASIC_SIZES.get(tail)
    return None  # unknown aggregate type


def parse_fields(text):
    """Yield (lineno, name, offset, size_or_None, is_pad, has_note, line)."""
    fields = []
    prev_comment = ""  # accumulated immediately-preceding comment block
    lines = text.splitlines()
    type_depths = []
    depth = 0
    for line in lines:
        code = line.split("//")[0]
        if re.match(r"\s*(class|struct)\b", code):
            type_depths.append(depth)
        depth += code.count("{") - code.count("}")
    baseline = min(type_depths) + 1 if type_depths else 0
    depth = 0
    for i, line in enumerate(lines, 1):
        plain = line.split("//")[0]
        depth += plain.count("{") - plain.count("}")
        code = plain.rstrip()
        stripped = line.strip()
        if stripped.startswith("//"):
            prev_comment += " " + stripped
            continue
        if not code.strip():
            continue  # blank; keep prev_comment as candidate context
        if any(stripped.startswith(p) for p in SKIP_PREFIX):
            prev_comment = ""
            continue
        if "(" in code or ")" in code or depth > baseline:
            prev_comment = ""
            continue
        m = DECL.match(line)
        prev_comment = ""
        if not m:
            continue
        base, ptrs, name, arr = m.groups()
        is_pad = name.lower().startswith("pad") or bool(arr and
                   base in ("uint8_t", "char", "u8"))
        off = None
        if is_pad:
            pm = re.search(r"pad[_]?0*([0-9a-fA-F]{1,5})", name, re.I)
            if pm:
                off = h(pm.group(1))
        if off is None:
            # Offset comment = the first hex literal after the first '//'
            # (trailing convention: `code; // 0xNN — prose with more hex`).
            tail = line[line.find("//") + 2:]
            oc = OFFSET_COMMENT.search("//" + tail)
            if oc:
                off = h(oc.group(1))
        if off is None:
            continue  # declaration without a cited offset: not layout data
        size = None
        if arr:
            n = array_size(arr.strip("[]"))
            elem = type_size(base, bool(ptrs.strip()))
            if base in ("char", "uint8_t", "u8") or is_pad:
                size = n  # char arrays: N bytes
            elif elem is not None and n is not None:
                size = elem * n
        else:
            size = type_size(base, bool(ptrs.strip()))
        note = ""
        tail = line.split("//", 1)[1] if "//" in line else ""
        if EVIDENCE.search(tail) or EVIDENCE.search(prev_comment):
            note = "yes"
        fields.append(dict(line=i, name=name, off=off, size=size,
                           is_pad=is_pad, has_note=bool(note), raw=line,
                           base_region=bool(BASE_REGION_FIELD.search(tail))))
    return fields


def extract_extent(text):
    extents = []
    for pat in EXTENT_PATTERNS:
        for m in pat.finditer(text):
            ls = text.rfind("\n", 0, m.start()) + 1
            le = text.find("\n", m.start())
            line = text[ls:le if le != -1 else len(text)]
            if SUBOBJECT_LINE.search(line) or SUBOBJECT_TO.search(line):
                continue
            v = h(m.group(1))
            if 0 < v < OFFSET_LIMIT:
                extents.append(v)
    for m in STRICT_EXTENT_NEG.finditer(text):
        pass  # lower bounds do not validate coverage
    return max(extents) if extents else None


def merge(ranges):
    ranges = sorted(ranges)
    out = []
    for a, b in ranges:
        if out and a <= out[-1][1]:
            out[-1][1] = max(out[-1][1], b)
        else:
            out.append([a, b])
    return out


def analyze(path: Path):
    text = path.read_text(errors="replace")
    fields = [f for f in parse_fields(text) if not f["base_region"]]
    # Base-region fields only set the coverage start (embedded base extent).
    for f in parse_fields(text):
        if f["base_region"]:
            text += f"\n// subobject at 0x{f['off'] + (f['size'] or 0):X}"
    if not fields:
        return None  # docblock-only / no layout data
    extent = extract_extent(text)
    errs, warns = [], []
    has_base = bool(BASE_DECL.search(text))
    base_extent = None
    m = BASE_EXTENT.search(text) or SUBOBJECT_AT.search(text)
    if m:
        base_extent = h(m.group(1))

    # known-size declared intervals (overlap check uses these only)
    known = [(f["off"], f["off"] + f["size"]) for f in fields if f["size"]]
    for i in range(len(fields)):
        for j in range(i + 1, len(fields)):
            a, b = fields[i], fields[j]
            if a["size"] and b["size"]:
                if a["off"] < b["off"] + b["size"] and b["off"] < a["off"] + a["size"]:
                    errs.append(f"line {a['line']}/{b['line']}: OVERLAP "
                                f"{a['name']}@0x{a['off']:X}(0x{a['size']:X}) vs "
                                f"{b['name']}@0x{b['off']:X}(0x{b['size']:X})")

    # alignment warnings (scalar fields only; char arrays serve everything)
    for f in fields:
        if f["size"] in (2, 4, 8) and f["off"] % f["size"] != 0 \
                and not re.search(r"\[[^]]*\]", f["raw"].split("//")[0]):
            warns.append(f"line {f['line']}: ALIGNMENT {f['name']} "
                         f"size 0x{f['size']:X} at 0x{f['off']:X}")

    # coverage
    if extent is None:
        return dict(fields=fields, extent=None, errs=[], warns=warns,
                    in_allowlist=True)
    cov_start = 0
    if has_base:
        if base_extent is not None:
            cov_start = base_extent
        else:
            cov_start = min(f["off"] for f in fields)
    intervals = [list(x) for x in known]
    unknown = [f for f in fields if not f["size"]]
    unknown.sort(key=lambda f: f["off"])
    known_starts = sorted(s for s, _ in known)
    for f in unknown:
        nxt = min([s for s in known_starts if s > f["off"]] + [extent])
        intervals.append([f["off"], min(nxt, extent)])
    cov = merge([x for x in intervals if x[1] > cov_start])
    pos = cov_start
    for a, b in cov:
        if a > pos:
            errs.append(f"ORPHAN bytes 0x{pos:X}-0x{a:X} (no field/pad)")
        pos = max(pos, b)
    if pos < extent:
        errs.append(f"ORPHAN bytes 0x{pos:X}-0x{extent:X} (no field/pad)")

    # pad evidence
    for f in fields:
        if f["is_pad"] and not f["has_note"]:
            errs.append(f"line {f['line']}: PAD WITHOUT NOTE ({f['name']})")

    # extent bound
    end = max(e for _, e in known) if known else extent
    if known and end > extent:
        errs.append(f"field end 0x{end:X} exceeds extent 0x{extent:X}")
    return dict(fields=fields, extent=extent, errs=errs, warns=warns,
                in_allowlist=False)


def main():
    check_allow = set(
        l.strip() for l in NO_EXTENT_ALLOWLIST.splitlines() if l.strip()
    )
    violations = 0
    warn_count = 0
    allow_used = set()
    by_type = {"overlap": 0, "orphan": 0, "pad-note": 0, "no-extent": 0,
               "past-extent": 0}
    checked = 0
    for path in sorted(INCLUDE.rglob("*.hpp")):
        rel = str(path.relative_to(ROOT))
        res = analyze(path)
        if res is None:
            continue
        checked += 1
        msgs = list(res["errs"])
        if res["extent"] is None:
            if rel in check_allow:
                allow_used.add(rel)
            else:
                msgs.append("NO-EXTENT: fields present but no cited extent "
                            "(add to NO_EXTENT_ALLOWLIST or fix layout)")
        for m in msgs:
            violations += 1
            key = ("overlap" if "OVERLAP" in m else
                   "orphan" if "ORPHAN" in m else
                   "pad-note" if "PAD WITHOUT NOTE" in m else
                   "no-extent" if "NO-EXTENT" in m else "past-extent")
            by_type[key] += 1
            print(f"{rel}: {m}")
        for w in res["warns"]:
            warn_count += 1
            print(f"{rel}: WARNING {w}")

    missing_allow = check_allow - allow_used
    for rel in sorted(missing_allow):
        print(f"ALLOWLIST STALE: {rel} now has a cited extent or no fields; "
              f"remove from NO_EXTENT_ALLOWLIST")
    growth = len(check_allow) - len(allow_used)
    if growth > 0:
        print(f"WARNING: allowlist shrank by {growth} (good)")
    elif growth < 0:
        print(f"WARNING: allowlist grew by {-growth} (suspicious)")

    print(f"\nchecked {checked} headers with layout data; "
          f"allowlist used {len(allow_used)}/{len(check_allow)}; "
          f"violations {violations}; warnings {warn_count}")
    print("violations by type:", {k: v for k, v in by_type.items() if v})
    if violations or missing_allow:
        sys.exit(1)
    print("layout OK")


if __name__ == "__main__":
    main()
