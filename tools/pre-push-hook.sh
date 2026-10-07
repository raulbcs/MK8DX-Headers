#!/usr/bin/env bash
# Pre-push syntax gate: mirrors .github/workflows/syntax.yml (letter A).
# Runs clang++ -fsyntax-only over every include/**/*.hpp and fails on any
# file that is NOT in the known-failing allowlist embedded below.
#
# Install (pick one):
#   git config core.hooksPath tools/hooks
#   ln -sf ../../tools/pre-push-hook.sh .git/hooks/pre-push
set -u

cd "$(git rev-parse --show-toplevel)"

# Same allowlist as the CI workflow — keep both in sync.
is_allowlisted() {
  case "$1" in
    # BEGIN ALLOWLIST (generated; mirrors .github/workflows/syntax.yml)
    include/enl/Buffer.hpp) ;;
    include/enl/ContentTransporter/ContentTransporterCommon.hpp) ;;
    include/enl/ContentTransporter/ContentTransporterForMulti.hpp) ;;
    include/enl/Framework.hpp) ;;
    include/enl/Peer/PeerManager.hpp) ;;
    include/enl/Peer/PeerManagerCommon.hpp) ;;
    include/enl/SendManager.hpp) ;;
    include/enl/Stream.hpp) ;;
    include/enl/TransportManager.hpp) ;;
    include/eui/ControlBase.hpp) ;;
    include/eui/Screen/Screen.hpp) ;;
    include/eui/Screen/ScreenFactory.hpp) ;;
    include/eui/Screen/ScreenMgr.hpp) ;;
    include/gear/Actor/Actor.hpp) ;;
    include/gear/Audio/AudSoundLinkUserBase.hpp) ;;
    include/gear/Byaml/ByamlIter.hpp) ;;
    include/gear/Collision/GndCol.hpp) ;;
    include/gear/Controller/ControllerRaceNX.hpp) ;;
    include/gear/Framework/FrameworkGameScene.hpp) ;;
    include/gear/Framework/FrameworkUtil.hpp) ;;
    include/gear/Item/ItemDirector.hpp) ;;
    include/gear/Item/ItemEventManager.hpp) ;;
    include/gear/Item/ItemObjManagerBase.hpp) ;;
    include/gear/Item/ItemOwner.hpp) ;;
    include/gear/Item/ItemReact.hpp) ;;
    include/gear/Item/ItemSlot.hpp) ;;
    include/gear/Item/Obj/ItemObjBase.hpp) ;;
    include/gear/Item/Obj/ItemObjKouraG.hpp) ;;
    include/gear/Item/Obj/ItemObjKouraR.hpp) ;;
    include/gear/MapObj/IMapObjBounce.hpp) ;;
    include/gear/MapObj/MapObjBase.hpp) ;;
    include/gear/MapObj/MapObjDirector.hpp) ;;
    include/gear/MapObj/MapObjDrawManager.hpp) ;;
    include/gear/MapObj/MapObjParameter.hpp) ;;
    include/gear/Math/Matrix.hpp) ;;
    include/gear/Network/NetworkDataAllPlayerInfo.hpp) ;;
    include/gear/Network/NetworkDataPlayerInfo.hpp) ;;
    include/gear/Network/Transporter/NetworkTransporterAllPlayerInfo.hpp) ;;
    include/gear/Network/Transporter/NetworkTransporterPlayerInfo.hpp) ;;
    include/gear/Object/ObjectBase.hpp) ;;
    include/gear/Player/Player.hpp) ;;
    include/gear/Player/PlayerInfo.hpp) ;;
    include/gear/Player/PlayerManager.hpp) ;;
    include/gear/Race/RaceDirector.hpp) ;;
    include/gear/Race/RaceDirectorPlayer.hpp) ;;
    include/gear/Race/RaceDirectorPlayerSet.hpp) ;;
    include/gear/Race/RaceDirectorSetChain.hpp) ;;
    include/gear/Race/RaceDirectorSetChainA.hpp) ;;
    include/gear/Race/RaceDirectorSetChainB.hpp) ;;
    include/gear/Race/RaceDirectorSetChainMid.hpp) ;;
    include/gear/Race/RaceDirectorSetChild80.hpp) ;;
    include/gear/Race/RaceDirectorSetChild80Derived.hpp) ;;
    include/gear/Race/RaceDirectorSetChildActor80.hpp) ;;
    include/gear/Race/RaceDirectorSetLanePool.hpp) ;;
    include/gear/Race/RaceDirectorSubActor60.hpp) ;;
    include/gear/Race/RaceDirectorSubActor60Child.hpp) ;;
    include/gear/Race/RaceDirectorVt0dd8.hpp) ;;
    include/gear/Race/RaceDirectorVt10.hpp) ;;
    include/gear/Race/RaceDirectorVt2.hpp) ;;
    include/gear/Race/RaceDirectorVt3.hpp) ;;
    include/gear/Race/RaceDirectorVt4.hpp) ;;
    include/gear/Race/RaceDirectorVt5.hpp) ;;
    include/gear/Race/RaceDirectorVt6.hpp) ;;
    include/gear/Race/RaceDirectorVt7.hpp) ;;
    include/gear/Race/RaceDirectorVt8.hpp) ;;
    include/gear/Race/RaceDirectorVt9.hpp) ;;
    include/gear/Race/RaceKartCheckerBattle.hpp) ;;
    include/gear/Race/RaceListItemD.hpp) ;;
    include/gear/Race/RaceListItemE.hpp) ;;
    include/gear/Resource/ResourceBase.hpp) ;;
    include/gear/Resource/ResourceLoader.hpp) ;;
    include/gear/RigidBody.hpp) ;;
    include/gear/SaveData/SaveDataFile.hpp) ;;
    include/gear/SaveData/SaveDataGhostListBase.hpp) ;;
    include/gear/SaveData/SaveDataManager.hpp) ;;
    include/gear/SystemEngine.hpp) ;;
    include/gear/UI/Flow/UIFlow.hpp) ;;
    include/gear/UI/Flow/UIFlow_CrossFade.hpp) ;;
    include/gear/UI/Flow/UIFlow_Detach.hpp) ;;
    include/gear/UI/Flow/UIFlow_Open.hpp) ;;
    include/gear/UI/Input/UIInput_Touch.hpp) ;;
    include/gear/UI/Page/UIPage.hpp) ;;
    include/gear/UI/Page/UIPageCreator.hpp) ;;
    include/gear/UI/Page/UIPageManager.hpp) ;;
    include/gear/UI/UIAnimator.hpp) ;;
    include/gear/UI/UIArchive.hpp) ;;
    include/gear/UI/UIControl.hpp) ;;
    include/gear/UI/UIControlT.hpp) ;;
    include/gear/UI/UIEvent.hpp) ;;
    include/gear/UI/UIHeap.hpp) ;;
    include/gear/UI/UILoader.hpp) ;;
    include/gear/UI/UIMessageManager.hpp) ;;
    include/gear/UI/UIPlayer.hpp) ;;
    include/gear/UI/UIUtil.hpp) ;;
    include/gear/UI/UIUtilNw.hpp) ;;
    include/gsys/Model/IModelCallback.hpp) ;;
    include/gsys/Model/Model.hpp) ;;
    include/gsys/Model/ModelAnimation.hpp) ;;
    include/gsys/Model/ModelInfo.hpp) ;;
    include/gsys/Model/ModelUnit.hpp) ;;
    include/kart/KartVehicleMove.hpp) ;;
    include/object/Effect/GameEffectDirector.hpp) ;;
    include/object/Kart/KartBodyVt71.hpp) ;;
    include/object/Kart/KartBodyVt71Profile1.hpp) ;;
    include/object/Kart/KartBodyVt71Profile10.hpp) ;;
    include/object/Kart/KartBodyVt71Profile11.hpp) ;;
    include/object/Kart/KartBodyVt71Profile12.hpp) ;;
    include/object/Kart/KartBodyVt71Profile13.hpp) ;;
    include/object/Kart/KartBodyVt71Profile14.hpp) ;;
    include/object/Kart/KartBodyVt71Profile15.hpp) ;;
    include/object/Kart/KartBodyVt71Profile16.hpp) ;;
    include/object/Kart/KartBodyVt71Profile17.hpp) ;;
    include/object/Kart/KartBodyVt71Profile18.hpp) ;;
    include/object/Kart/KartBodyVt71Profile19.hpp) ;;
    include/object/Kart/KartBodyVt71Profile2.hpp) ;;
    include/object/Kart/KartBodyVt71Profile20.hpp) ;;
    include/object/Kart/KartBodyVt71Profile21.hpp) ;;
    include/object/Kart/KartBodyVt71Profile22.hpp) ;;
    include/object/Kart/KartBodyVt71Profile23.hpp) ;;
    include/object/Kart/KartBodyVt71Profile24.hpp) ;;
    include/object/Kart/KartBodyVt71Profile3.hpp) ;;
    include/object/Kart/KartBodyVt71Profile4.hpp) ;;
    include/object/Kart/KartBodyVt71Profile5.hpp) ;;
    include/object/Kart/KartBodyVt71Profile6.hpp) ;;
    include/object/Kart/KartBodyVt71Profile7.hpp) ;;
    include/object/Kart/KartBodyVt71Profile8.hpp) ;;
    include/object/Kart/KartBodyVt71Profile9.hpp) ;;
    include/object/Kart/KartCalcSpeedMini.hpp) ;;
    include/object/Kart/KartCalcSpeedMiniCore.hpp) ;;
    include/object/Kart/KartCamera.hpp) ;;
    include/object/Kart/KartDirector.hpp) ;;
    include/object/Kart/KartPhysicsBody.hpp) ;;
    include/object/Kart/KartPhysicsBodyBomhei.hpp) ;;
    include/object/Kart/KartPhysicsBodyGesso.hpp) ;;
    include/object/Kart/KartPhysicsBodyKiller.hpp) ;;
    include/object/Kart/KartPhysicsBodyKoura.hpp) ;;
    include/object/Kart/KartPhysicsBodyKouraTogezo.hpp) ;;
    include/object/Kart/KartPhysicsBodyMid.hpp) ;;
    include/object/Kart/KartPhysicsBodyPackun.hpp) ;;
    include/object/Kart/KartPhysicsBodySHorn.hpp) ;;
    include/object/Kart/KartPhysicsBodyTeresa.hpp) ;;
    include/object/Kart/KartPhysicsBodyTeresaVt108.hpp) ;;
    include/object/Kart/KartPhysicsBodyTeresaVt97.hpp) ;;
    include/object/Kart/KartPhysicsBodyUseItem.hpp) ;;
    include/object/Kart/KartPhysicsBodyVt96a.hpp) ;;
    include/object/Kart/KartPhysicsBodyVt96b.hpp) ;;
    include/object/Kart/KartPhysicsBodyVt96c.hpp) ;;
    include/object/Kart/KartPhysicsBodyVt96d.hpp) ;;
    include/object/Kart/KartPhysicsBodyVt97.hpp) ;;
    include/object/Kart/KartPhysicsBodyVt98.hpp) ;;
    include/object/Kart/KartRigidBody.hpp) ;;
    include/object/Kart/KartUnitHolder.hpp) ;;
    include/object/Kart/KartVehicle.hpp) ;;
    include/object/Kart/KartVehicleBody.hpp) ;;
    include/object/Kart/KartVehicleReact.hpp) ;;
    include/object/Kart/KartVehicleTrick.hpp) ;;
    include/object/MapObj/MapObjItemBox.hpp) ;;
    include/object/MapObj/MapObjVehicleBase.hpp) ;;
    include/object/ObjectEngine.hpp) ;;
    include/object/Race/RaceCheckerBase.hpp) ;;
    include/object/Race/RaceCheckerVt2.hpp) ;;
    include/object/Race/RaceCheckerVt3.hpp) ;;
    include/object/Race/RaceKartChecker.hpp) ;;
    include/object/Record/RecordFileKart.hpp) ;;
    include/object/Record/RecordFileManager.hpp) ;;
    include/sead/basis/seadNewWrapper.hpp) ;;
    include/sead/hostio/seadHostIONode.hpp) ;;
    include/ui/Buttons/Control_BackButton.hpp) ;;
    include/ui/Buttons/Control_BindButton.hpp) ;;
    include/ui/Buttons/Control_Button.hpp) ;;
    include/ui/Buttons/Control_CourseButton.hpp) ;;
    include/ui/Buttons/Control_CupButton.hpp) ;;
    include/ui/Buttons/Control_DLCLButton.hpp) ;;
    include/ui/Control/Control_GhostBase.hpp) ;;
    include/ui/Control/Control_GhostDetail.hpp) ;;
    include/ui/Control/Control_RaceView.hpp) ;;
    include/ui/Control/Control_RivalGhost.hpp) ;;
    include/ui/Control/Control_RivalGhostVolume.hpp) ;;
    include/ui/Control/Control_RuleList.hpp) ;;
    include/ui/Control/Control_Scroll.hpp) ;;
    include/ui/Course/CourseInfo.hpp) ;;
    include/ui/Course/DummyTex.hpp) ;;
    include/ui/Course/UICourseTex.hpp) ;;
    include/ui/Course/uiCourse.hpp) ;;
    include/ui/Heap/Heap_Common.hpp) ;;
    include/ui/Heap_CommonInfo.hpp) ;;
    include/ui/Page/Page_BGMTest.hpp) ;;
    include/ui/Page/Page_Bg.hpp) ;;
    include/ui/Page/Page_CourseBase.hpp) ;;
    include/ui/Page/Page_CourseBattle.hpp) ;;
    include/ui/Page/Page_CourseVS.hpp) ;;
    include/ui/Page/Page_Dialog.hpp) ;;
    include/ui/Page/Page_Ghost.hpp) ;;
    include/ui/Page/Page_Ghost_ScrollList.hpp) ;;
    include/ui/Page/Page_Login.hpp) ;;
    include/ui/Page/Page_Lyt_RuleList.hpp) ;;
    include/ui/Page/Page_MenuUnder.hpp) ;;
    include/ui/Page/Page_Race.hpp) ;;
    include/ui/Page/Page_RaceView.hpp) ;;
    include/ui/Page/Page_TitleSelect.hpp) ;;
    include/ui/RaceWindow.hpp) ;;
    include/ui/Rule/UIRule.hpp) ;;
    include/xlink2/BoneMtx.hpp) ;;
    include/xlink2/Locator.hpp) ;;
    # END ALLOWLIST
    *) return 1 ;;
  esac
}

INC="-Iinclude -Ivendor/nnheaders -Ivendor/nnheaders/include"

fail=0
allowlisted=0
checked=0
while IFS= read -r f; do
  checked=$((checked + 1))
  if clang++ -fsyntax-only -std=c++17 $INC "$f" 2>/dev/null; then
    continue
  fi
  if is_allowlisted "$f"; then
    allowlisted=$((allowlisted + 1))
    echo "ALLOWLISTED (known-failing): $f"
  else
    echo "ERROR (not allowlisted): $f"
    clang++ -fsyntax-only -std=c++17 $INC "$f" 2>&1 | head -5
    fail=1
  fi
done < <(find include -name '*.hpp' | sort)

echo "syntax pre-push: checked $checked headers, $allowlisted allowlisted failures"

# Advisory extent check (same as CI continue-on-error step).
if [ -f tools/check_extents.py ]; then
  python3 tools/check_extents.py || echo "WARNING: extent violations exist (advisory; see tools/check_extents.py)"
fi

exit $fail
