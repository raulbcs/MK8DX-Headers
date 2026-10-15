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
import struct
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
#   include/_nn/account/NetworkServiceAccountId.hpp
#   include/_nn/account/Uid.hpp
#   include/_nn/ae/AppletThreadHost.hpp
#   include/_nn/ae/TimeSyncThread.hpp
#   include/_nn/atk/BiquadFilter.hpp
#   include/_nn/atk/detail/driver/SoundThread.hpp
#   include/_nn/friends/Friend.hpp
#   include/_nn/friends/FriendPresence.hpp
#   include/_nn/nex/Buffer.hpp
#   include/_nn/nex/CallContext.hpp
#   include/_nn/nex/ClientProtocol.hpp
#   include/_nn/nex/Credentials.hpp
#   include/_nn/nex/JobAcquireAccessToken.hpp
#   include/_nn/nex/JobBackEndServicesTerminate.hpp
#   include/_nn/nex/JobCallContextCallback.hpp
#   include/_nn/nex/JobDeriveKey.hpp
#   include/_nn/nex/JobHttp.hpp
#   include/_nn/nex/JobNNIDLogin.hpp
#   include/_nn/nex/ProtocolCallContext.hpp
#   include/_nn/nex/_DDL_AuthenticationInfo.hpp
#   include/_nn/pia/session/DestroySessionJob.hpp
#   include/_nn/pia/session/JoinMeshJob.hpp
#   include/_nn/pia/session/LeaveSessionJob.hpp
#   include/aal/Asset/AssetInfo.hpp
#   include/aal/Emitter.hpp
#   include/aal/Handle.hpp
#   include/aal/Param/SoundParam.hpp
#   include/aal/Resource/AudioResource.hpp
#   include/aal/Resource/AudioResourceList.hpp
#   include/aal/Result/StartResult.hpp
#   include/aal/Spatial/SpatialSetting.hpp
#   include/audio/Aud/AudResourceManager.hpp
#   include/enl/Buffer.hpp
#   include/enl/Connection/ConnectInfo.hpp
#   include/enl/ContentTransporter/ContentTransporterCommon.hpp
#   include/enl/ContentTransporter/ContentTransporterForMulti.hpp
#   include/enl/Framework.hpp
#   include/enl/Peer/UniqueID.hpp
#   include/eui/ControlBase.hpp
#   include/eui/LayoutEx.hpp
#   include/eui/Screen/Screen.hpp
#   include/eui/Screen/ScreenMgr.hpp
#   include/gear/Account/account.hpp
#   include/gear/Audio/AudSoundLinkUserBase.hpp
#   include/gear/Background/BackgroundLoadThread.hpp
#   include/gear/Collision/GndColCheckRayInfo.hpp
#   include/gear/Controller/ControllerRaceNX.hpp
#   include/gear/Course/CourseDecompThread.hpp
#   include/gear/Course/FieldDirector.hpp
#   include/gear/Director/TDirectorBase.hpp
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
#   include/gear/Item/Obj/ItemObjKouraG.hpp
#   include/gear/MapObj/IMapObjBounce.hpp
#   include/gear/MapObj/MapObjBase.hpp
#   include/gear/MapObj/MapObjCreateArg.hpp
#   include/gear/MapObj/MapObjDirector.hpp
#   include/gear/MapObj/MapObjDrawManager.hpp
#   include/gear/MapObj/MapObjManagerBase.hpp
#   include/gear/MapObj/MapObjParameter.hpp
#   include/gear/MapObj/MapUnitMapObj.hpp
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
#   include/gear/Race/RaceDirectorSetChain.hpp
#   include/gear/Race/RaceInfo.hpp
#   include/gear/Race/RaceKartInfo.hpp
#   include/gear/Race/RaceKartResult.hpp
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
#   include/gear/UI/UIPlayer.hpp
#   include/gear/UI/UITheaterThread.hpp
#   include/gear/XLink/XLinkManualEffect.hpp
#   include/gear/XLink/XLinkSlotState.hpp
#   include/gear/XLink/XLinkUser.hpp
#   include/gsys/Animation/AnimationAccessKey.hpp
#   include/gsys/Model/Model.hpp
#   include/gsys/Model/ModelInfo.hpp
#   include/gsys/Model/ModelResource.hpp
#   include/naked/Network/NetworkDataDrive.hpp
#   include/object/AI/AIUnit.hpp
#   include/object/Kart/AudioTaskThread.hpp
#   include/object/Kart/BackgroundLoadThread.hpp
#   include/object/Kart/ContentsThread.hpp
#   include/object/Kart/KartChassisEffect.hpp
#   include/object/Kart/KartDirector.hpp
#   include/object/Kart/KartFloorEffect.hpp
#   include/object/Kart/KartInfoProxy.hpp
#   include/object/Kart/KartMatrixInfo.hpp
#   include/object/Kart/KartModelBackgroundLoadThread.hpp
#   include/object/Kart/KartParamCacheVtd608.hpp
#   include/object/Kart/LowPrioWorkerThread.hpp
#   include/object/Kart/ParamMultiChanVt2808.hpp
#   include/object/Kart/ParamMultiChanVt2c40.hpp
#   include/object/Kart/ParamMultiChanVtb318.hpp
#   include/object/Kart/ParamMultiChanVtba40.hpp
#   include/object/Kart/ParamMultiChanVtbdb8.hpp
#   include/object/Kart/ParamMultiChanVtc0f0.hpp
#   include/object/Kart/ParamMultiChanVtc200.hpp
#   include/object/Kart/ParamMultiChanVtc468.hpp
#   include/object/Kart/ParamMultiChanVtd7b0.hpp
#   include/object/Kart/ParamMultiChanVtd900.hpp
#   include/object/Kart/ParamMultiChanVtda50.hpp
#   include/object/Kart/ParamNodeEnvObjName.hpp
#   include/object/Kart/ParamNodeModelBinding.hpp
#   include/object/Kart/ParamNodePseudoOcclusion.hpp
#   include/object/Kart/ParamNodeVt2198.hpp
#   include/object/Kart/ParamNodeVt2b90.hpp
#   include/object/Kart/ParamNodeVt2ea8.hpp
#   include/object/Kart/ParamNodeVt2fb0.hpp
#   include/object/Kart/ParamNodeVt32a8.hpp
#   include/object/Kart/ParamNodeVt3fd8.hpp
#   include/object/Kart/ParamNodeVt4140.hpp
#   include/object/Kart/ParamNodeVt4510.hpp
#   include/object/Kart/ParamNodeVt4688.hpp
#   include/object/Kart/ParamNodeVt4c70.hpp
#   include/object/Kart/ParamNodeVtc848.hpp
#   include/object/Kart/ParamNodeVtc8a0.hpp
#   include/object/Kart/ParamNodeVtc8f8.hpp
#   include/object/Kart/ParamNodeVtd5b0.hpp
#   include/object/Kart/ParamNodeVtde48.hpp
#   include/object/Kart/UIMovieRecreatingThread.hpp
#   include/object/Kart/VibrationThread.hpp
#   include/object/Kart/Vt3dcf3018f8.hpp
#   include/object/MapObj/MapObjItemBox.hpp
#   include/object/MapObj/MapObjVehicleBase.hpp
#   include/object/ObjectEngine.hpp
#   include/object/Race/RaceCheckerBase.hpp
#   include/object/Record/RecordFileKart.hpp
#   include/object/Record/RecordFileManager.hpp
#   include/object/Vt11bb080.hpp
#   include/object/Vt12ba010.hpp
#   include/object/Vt12ca000.hpp
#   include/object/Vt12f3160.hpp
#   include/repl/File.hpp
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
#   include/xlink2/Event.hpp
#   include/xlink2/Locator.hpp
#   include/xlink2/UserInstanceSLink.hpp
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

EXTENT_PATTERNS = [
    re.compile(r"extent\s+(?:is\s+|from\s+|of\s+|=|fixed by\s+\S+\s+at)?0x([0-9a-fA-F]+)", re.I),
    re.compile(r"concrete size\s+0x([0-9a-fA-F]+)", re.I),
    re.compile(r"news\[0x([0-9a-fA-F]+)\]", re.I),
    re.compile(r"allocation[^.]*?size\s+0x([0-9a-fA-F]+)", re.I),
    re.compile(r"\bsize\s+0x([0-9a-fA-F]+)\s*\(", re.I),
    re.compile(r"\balloc(?:ation)?[^.\n]{0,80}?\b0x([0-9a-fA-F]+)\b", re.I),
    re.compile(r"operator new\w*\(\s*0x([0-9a-fA-F]+)", re.I),
    re.compile(r"\bSize\s+0x([0-9a-fA-F]+)\s*[.;)]", re.I),
]
SUBOBJECT_LINE = re.compile(r"sub-?object|base region", re.I)
SUBOBJECT_TO = re.compile(r"extent\s+0x[0-9a-fA-F]+,?\s+to\s", re.I)

BASE_DECL = re.compile(r"\b(?:class|struct)\s+\w+\s*:\s*(?:public|protected|private)\b")
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
    r"(\w+)\s*((?:\[[^\]]*\])*)\s*(?:=[^;]*)?;"
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
            n = 1
            for d in re.findall(r"\[([^\]]*)\]", arr):
                v = array_size(d)
                if v is None:
                    n = None
                    break
                n *= v
            elem = type_size(base, bool(ptrs.strip()))
            if base in ("char", "uint8_t", "u8") or is_pad:
                size = n  # char arrays: N bytes
            elif elem is not None and n is not None:
                size = elem * n
        else:
            size = type_size(base, bool(ptrs.strip()))
        note = ""
        tail = line.split("//", 1)[1] if "//" in line else ""
        # A note is explanatory prose beyond the bare offset
        # ("// 0x38 - 0x3F" alone is NOT a note).
        after = re.sub(r"[-\u2014]?\s*0x[0-9a-fA-F]{1,5}\b", "", tail)
        after = re.sub(r"^[\s\-\u2014.,:;()]*", "", after)
        if (re.search(r"[A-Za-z]", after) or EVIDENCE.search(tail)
                or EVIDENCE.search(prev_comment)):
            note = "yes"
        fields.append(dict(line=i, name=name, off=off, size=size,
                           is_pad=is_pad, has_note=bool(note), raw=line,
                           base_region=bool(BASE_REGION_FIELD.search(tail))))
    return fields


def extract_extent(text):
    # join comment syntax so evidence split across comment lines matches
    # ("size 0x2B0\n// (allocation site ...)")
    text = re.sub(r"//", "", text)
    text = re.sub(r"^\s*\*\s?", "", text, flags=re.M)
    text = text.replace("/*", "").replace("*/", "")
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


def struct_segments(text):
    """Split a header into top-level class/struct blocks, each prefixed by
    its immediately preceding comment block (extent citations live there).
    Without this, fields and extents from DIFFERENT structs in one file get
    pooled into a single fake layout and produce spurious overlaps."""
    lines = text.splitlines()
    segs = []
    i = 0
    while i < len(lines):
        code = lines[i].split("//")[0]
        if not re.match(r"\s*(?:class|struct)\s+\w+", code):
            i += 1
            continue
        # preceding contiguous comment/blank block (skip namespace lines,
        # which often sit between the docblock and the struct)
        j = i - 1
        pre = []
        while j >= 0:
            s = lines[j].strip()
            if (not s or s.startswith(("//", "*", "/*"))
                    or re.match(r"^(?:namespace\b[^;{]*\{|\}\s*(?://.*|/\*.*\*/)?\s*)$", s)
                    or re.match(r"^(?:struct|class)\s+\w+\s*;", s)):
                pre.append(lines[j])
                j -= 1
                continue
            break
        pre.reverse()
        depth = 0
        seen_open = False
        k = i
        empty = False
        while k < len(lines):
            c = lines[k].split("//")[0]
            if ";" in c and not seen_open:
                empty = True  # forward declaration
                break
            depth += c.count("{") - c.count("}")
            if "{" in c:
                seen_open = True
            if seen_open and depth <= 0:
                break
            k += 1
        if not empty:
            segs.append("\n".join(pre + lines[i:k + 1]))
        i = k + 1
    return segs


def analyze_unit(text):
    fields = [f for f in parse_fields(text) if not f["base_region"]]
    # Base-region fields do not join the overlap check (they are overlaid by
    # the per-field map below them) but DO count as coverage.
    base_cov = [[f["off"], f["off"] + (f["size"] or 0)]
                for f in parse_fields(text)
                if f["base_region"] and f["size"]]
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
                    in_allowlist=False)
    cov_start = 0
    if has_base:
        if base_extent is not None:
            cov_start = base_extent
        else:
            cov_start = min(f["off"] for f in fields)
    # implicit vptr slot for polymorphic types without a declared field at 0
    if re.search(r"\bvirtual\b", text) and not any(f["off"] == 0 for f in fields):
        cov_start = max(cov_start, 8)
    intervals = [list(x) for x in known] + base_cov
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


def analyze(path: Path):
    """Header-level aggregation over per-struct analyses. A header counts as
    NO-EXTENT only if NO struct in it cites an extent; structs without an
    extent citation alongside ones with one are skipped silently."""
    text = path.read_text(errors="replace")
    segs = struct_segments(text)
    if not segs:
        segs = [text]  # no structs: legacy whole-file behavior
    errs, warns = [], []
    any_fields = False
    has_extent = False
    for seg in segs:
        res = analyze_unit(seg)
        if res is None:
            continue
        any_fields = True
        if res["extent"] is None:
            continue
        has_extent = True
        errs.extend(res["errs"])
        warns.extend(res["warns"])
    if not any_fields:
        return None
    return dict(fields=[], extent=True if has_extent else None,
                errs=errs, warns=warns, in_allowlist=not has_extent)


# ---------------------------------------------------------------------------
# ELF mining (ctor store extents / allocation sites) — data/main.elf
#
# Address convention: VAs are VMA (objdump address; header labels are
# 0x7100000000 + VMA). ELF maps LOAD off=0x788 vaddr=0, so file offset =
# VMA + 0x788. Decode notes: L bit (bit 22) must be 0 (LDR/LDP don't
# count); STR unsigned imm is scaled (byte offset = imm12 * size).
# ---------------------------------------------------------------------------
ELF_PATH = Path("/Users/raul/projects/mk8dx-400/data/main.elf")
NEW_VA = 0x60AFEC  # _Znwm VMA

_mine_f = None


def _elf_word(va):
    global _mine_f
    if _mine_f is None:
        _mine_f = ELF_PATH.read_bytes()
    return struct.unpack_from("<I", _mine_f, 0x788 + va)[0]


def func_span(va, maxspan=0x2000):
    """Function length in bytes: VMA until first ret."""
    for k in range(maxspan // 4):
        if _elf_word(va + k * 4) == 0xD65F03C0:
            return k * 4 + 4
    return maxspan


def _bl_target(w, pc):
    if (w >> 26) != 0x25:
        return None
    imm = w & 0x3FFFFFF
    if imm >= 1 << 25:
        imm -= 1 << 26
    return pc + imm * 4


def max_store_end(va, ln=None):
    """Max byte end of stores whose base reg holds `this` (x0 at entry,
    propagated through mov xN, x0). Lower bound for the object extent
    when va is a ctor."""
    if _mine_f is None:
        _elf_word(0)
    off = 0x788 + va
    if ln is None:
        ln = func_span(va)
    bases = {0}
    best = 0
    for k in range(ln // 4):
        w = struct.unpack_from("<I", _mine_f, off + k * 4)[0]
        if (w & 0xFFFFFFE0) == 0xAA0003E0:  # mov xN, x0
            bases.add(w & 31)
        if (w >> 22) & 1:  # loads don't count
            continue
        top = w >> 24
        if top in (0xA9, 0xA8):  # STP 64-bit imm
            imm = (w >> 15) & 0x7F
            if imm >= 64:
                imm -= 128
            if (w >> 5) & 31 in bases:
                best = max(best, imm * 8 + 16)
        elif top in (0xF9, 0xB9, 0x79, 0x39):  # STR x/w/h/b unsigned imm
            imm = (w >> 10) & 0xFFF
            szm = {0xF9: 3, 0xB9: 2, 0x79: 1, 0x39: 0}[top]
            if (w >> 5) & 31 in bases:
                best = max(best, imm * (1 << szm) + (1 << szm))
        elif (w >> 21) == 0x3E0:  # STUR
            imm = (w >> 12) & 0x1FF
            if imm >= 256:
                imm -= 512
            s = {0: 1, 1: 2, 2: 4, 3: 8}[(w >> 30) & 3]
            if (w >> 5) & 31 in bases:
                best = max(best, imm + s)
    return best


def _mov_imm(w):
    """Decode ORR-immediate (MOV alias) value for Wd=Xd=Wn=WZR, or None."""
    if (w >> 23) != 0b0100100100 >> 1:  # sf=0 opc=10 0010010 N
        pass
    if (w & 0xFF800000) != 0x32000000:  # 32-bit ORR imm (mov alias form)
        return None
    if w & 31 != 31 or (w >> 5) & 31 != 31:  # Rd=Rn=wzr
        return None
    n = (w >> 22) & 1
    immr = (w >> 16) & 0x3F
    imms = (w >> 10) & 0x3F
    # standard move-widener decode for 32-bit
    if n or not (imms >> 5):
        return None
    length = 6 - (imms.bit_length() - 1)  # len of run of 1s starting at msb
    if length == 0:
        return None
    imm = (1 << length) - 1
    ror = immr & (32 - 1) if False else immr  # 32-bit: use immr mod 32
    ror = immr % 32
    val = ((imm >> ror) | (imm << (32 - ror))) & 0xFFFFFFFF
    # replicate per length
    if length:
        reps = 32 // length
        val = 0
        piece = ((1 << length) - 1)
        shifted = ((piece >> ror) | (piece << (32 - ror))) & 0xFFFFFFFF if ror else piece
        for i in range(reps):
            val |= shifted << (i * length)
            val &= 0xFFFFFFFF
    return val


def alloc_sites(size, elf_size=0xB55750):
    """`mov w0,#size` (movz or orr-imm alias); bl _Znwm -> [(site, ctor)]"""
    if _mine_f is None:
        _elf_word(0)
    out = []
    for k in range(elf_size // 4):
        va = k * 4
        w = struct.unpack_from("<I", _mine_f, 0x788 + va)[0]
        if (w & 0xFFE00000) == 0x52800000:
            imm = (w >> 5) & 0xFFFF
        else:
            imm = _mov_imm(w)
            if imm is None:
                continue
        if imm != size:
            continue
        got = False
        ctor = None
        for j in range(1, 14):
            t = _bl_target(_elf_word(va + j * 4), va + j * 4)
            if t is None:
                continue
            if not got:
                if t == NEW_VA:
                    got = True
            else:
                ctor = t
                break
        if got and ctor:
            out.append((va, ctor))
    return out


def _norm_va(va):
    return va & 0xFFFFFFFF if va >= 0xB55750 else va


def mine_ctor(vas):
    for va in vas:
        va = _norm_va(va)
        print(f"ctor {va:#x}: len {func_span(va):#x} "
              f"stores -> {max_store_end(va):#x}")


def mine_alloc(sizes):
    for size in sizes:
        found = False
        for site, ctor in alloc_sites(size):
            found = True
            print(f"alloc {size:#x} @ {site:#x} -> ctor {ctor:#x} "
                  f"(len {func_span(ctor):#x}) "
                  f"stores -> {max_store_end(ctor):#x}")
        if not found:
            print(f"alloc {size:#x}: no movz+Znwm sites")


def mine_sweep(filters, apply=False):
    """Sweep NO_EXTENT_ALLOWLIST entries matching filters; docblock ctor
    VAs -> store reach. --apply appends the citation when proven."""
    violations = 0  # unused; keeps parse of args simple
    for rel in allowlist_paths():
        if filters and not any(x in rel for x in filters):
            continue
        path = ROOT / rel
        text = path.read_text()
        fe = fields_end(text)
        rows = []
        for m in re.finditer(
                r"\b(0x[0-9a-fA-F]{5,12})[^.\n]{0,60}\bctor\b", text, re.I):
            va = _norm_va(int(m.group(1), 16))
            if va < 0x1000 or va >= 0xB55750:
                continue
            rows.append((va, max_store_end(va)))
        ok = [b for _, b in rows if fe <= b <= 0x4000]
        chosen = max(ok) if ok else None
        print(f"{rel}: fields_end={fe:#x} "
              + " ".join(f"ctor{va:#x}->{b:#x}" for va, b in rows)
              + (f" CHOSEN={chosen:#x}" if chosen else ""))
        if apply and chosen:
            va = [v for v, b in rows if b == chosen][0]
            with open(path, "a") as fh:
                fh.write(f"// extent {chosen:#x} (ctor 0x{0x7100000000 + va:X} "
                         f"stores reach {chosen:#x}; lower bound — allocation "
                         f"end unproven)\n")


def fields_end(text):
    best = 0
    for seg in struct_segments(text):
        for fld in parse_fields(seg):
            if fld["size"]:
                best = max(best, fld["off"] + fld["size"])
    return best


def allowlist_paths():
    return [l.strip()[2:].strip() for l in NO_EXTENT_ALLOWLIST.splitlines()
            if l.strip().startswith("#   ")]


def main_mine(argv):
    usage = ("usage: check_extents.py --mine ctor VA... | "
             "alloc SIZE... | sweep [FILTER...] [--apply]")
    if not argv or argv[0] not in ("ctor", "alloc", "sweep"):
        print(usage)
        return 2
    cmd, rest = argv[0], argv[1:]
    apply = "--apply" in rest
    rest = [a for a in rest if a != "--apply"]
    if cmd == "sweep":
        mine_sweep(rest, apply)
        return 0
    nums = [int(a, 16) if a.lower().startswith("0x") else int(a, 0)
            for a in rest]
    if cmd == "ctor":
        mine_ctor(nums)
    else:
        mine_alloc(nums)
    return 0


def main():
    check_allow = set(
        l.strip()[2:].strip() for l in NO_EXTENT_ALLOWLIST.splitlines()
        if l.strip().startswith("#   ")
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
    import sys as _sys
    if "--mine" in _sys.argv[1:]:
        i = _sys.argv.index("--mine")
        _sys.exit(main_mine(_sys.argv[i + 1:]))
    main()
