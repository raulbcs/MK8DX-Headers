#pragma once

#include <cstdint>

#include "KartUnit.hpp"
#include "KartVehicleControl.hpp"
#include "KartVehicleCpu.hpp"
#include "kart/KartVehicleMove.hpp" // real 64-bit layout (the object/ stub is gone)
#include "KartVehicleNet.hpp"
#include "KartVehicleTrick.hpp"
#include "KartVehicleBody.hpp"
#include "KartVehicleReact.hpp"
#include "KartJugemRecover.hpp"
#include "KartSteerAssist.hpp"
#include "KartChassis.hpp"
#include "KartChassisAnim.hpp"
#include "KartVehicleCollision.hpp"
#include "KartVehicleBalloon.hpp"
#include "KartVehicleHeadLight.hpp"
#include "KartSusKit.hpp"
#include "KartRecorderKey.hpp"
#include "KartPathJob.hpp"
#include "KartParameter.hpp"

// Canonical KartVehicle layout (byte-exact offsets verified against the
// v400 binary by the mk8dx-400 check).
//
// Subobject allocation table (proven by operator new sites in the ctor
// 0x7100170100-0x7100170460): Control 0x70 @+0x10, Cpu 0x90 @+0x18,
// Net 0x42D8 @+0x20, Move 0x5F8 @+0x28, Trick 0x1A0 @+0x30, Body 0x160
// @+0x38, React 0x90 @+0x40, Collision 0x2D0 @+0x48 (ctor 0x139838),
// Chassis 0x510 @+0x50, ChassisAnim 0x130 @+0x58, HeadLight 0x130 @+0x60
// (ctor 0x140514), SusKit 0x128 @+0x68 (ctor 0x15dd9c), Balloon 0xAB8
// @+0x70 (ctor 0x1142e4), SteerAssist 0x120 @+0xA0 (conditional on mIsMaster).
namespace object
{

    class KartVehicle
	{
    public:
        struct ControlInfo
        {
            uint32_t mKeyPadState; //0x00
            uint32_t mPad04; //0x04
            uint32_t mPad08; //0x08
            float controlStickX; //0x0C
            float controlStickY; //0x10
        };

        // The Collision / HeadLight / SusKit / Balloon / RecorderKey / PathJob
        // classes are defined (Collision, Balloon) or size-annotated elsewhere;
        // all unnamed in the binary — sizes proven by allocation sites.

        KartVehicle* mKartVehicle; //0x00
        KartUnit* mKartUnit; //0x08
        KartVehicleControl* mKartVehicleControl; //0x10 — FUN_7100172e90 writes a
            // u8 flag at this subobject's +0x18
        KartVehicleCpu* mKartVehicleCpu; //0x18 — same +0x18 u8 flag (FUN_7100172e90)
        KartVehicleNet* mKartVehicleNet; //0x20 — same +0x18 u8 flag (FUN_7100172e90)
        KartVehicleMove* mKartVehicleMove; //0x28 — deref +0x118 (boost slot) and +0x37c;
            // FUN_7100173234/324c read its +0x8 subobject
        KartVehicleTrick* mKartVehicleTrick; //0x30
        KartVehicleBody* mKartVehicleBody; //0x38
        KartVehicleReact* mKartVehicleReact; //0x40
        KartVehicleCollision* mKartCollision; //0x48 — size 0x2D0 (ctor 0x139838)
        KartChassis* mKartChassis; //0x50 — size 0x510 (ctor 0x11c0c4)
        KartChassisAnim* mKartChassisAnim; //0x58 — size 0x130 (ctor 0x12289c,
            // receives KartChassis+0x10)
        KartVehicleHeadLight* mKartHeadLight; //0x60 — size 0x130 (ctor 0x140514)
        KartSusKit* mSusKit; //0x68 — size 0x128 (ctor 0x15dd9c); FUN_7100174f7c
            // reads a float at Sus+0xD0 (>= 1.0f gate)
        KartVehicleBalloon* mKartBalloon; //0x70 — size 0xAB8 (ctor 0x1142e4)
        KartParameter* mKartParameter; //0x78 — 0xb8-byte param object; init by the
            // stat calc FUN_710014b6d0, getters cached as bytes at +0xd8..0xdd
            // by FUN_7100170090
        KartRecorderKey* mRecorderKey; //0x80 — object size 0x298 (new @ 0x7100170458,
            // ctor 0x3ae42c); skipped for ghosts/replays (guarded block)
        KartPathJob* mPathJob; //0x88 — recorder camera rig, size 0x2B8 (new @
            // 0x71001704c0, ctor 0x3aed50); int state at +0x8 (==2 gate in the
            // Path2Gate cluster, FUN_7100173140)
        KartJugemRecover* mKartJugemRecover; //0x90 — size 0x1D8 (new @ 0x71001704dc,
            // ctor 0x142a60 with mPlayerID); 8-byte thunks ldr x0,[x0,#0x90]
            // (FUN_7100175a28 / FUN_7100175a30)
        uintptr_t mPad98; //0x98
        KartSteerAssist* mKartSteerAssist; //0xA0
        uint32_t mPlayerID; //0xA8
        uint32_t mPadAC; //0xAC
        uint32_t mBodyID; //mush::EBodyID 0xB0
        uint32_t mDriverID; //mush::EDriverID 0xB4
        uint8_t mPadB8[0x10]; //0xB8 - 0xC7
        uint32_t mTeamType; //gear::ETeamType 0xC8
        uint32_t mPadCC; //0xCC
        bool mIsMaster; //0xD0
        uint8_t mPadD1; //0xD1
        bool mIsCpu; //0xD2
        bool mIsCpuOrKiller; //0xD3
        bool mIsGhost; //0xD4
        uint8_t mPadD5[3]; //0xD5-0xD7
        bool mIsBike; //0xD8 — INIT: mirrored from isKartUnitState24Eq1 by
            // FUN_7100170090 (0x1700d0); suggests KartUnit mode_24==1 encodes bike
        bool mIsHangOnBike; //0xD9 — INIT: isKartUnitField28Eq2 mirror (0x1700e0)
        bool mIsHangOnBike_; //0xDA — INIT: isKartUnitField28Eq2 mirror again (0x1700f0)
        bool mIsBikeRideType; //0xDB — INIT: isKartUnitState24Eq1Or28Eq3 mirror (0x170100)
        bool mIsATVRideType; //0xDC — INIT: isKartUnitState28Eq3 mirror (0x170110)
        bool mIsTrike; //0xDD — INIT: isKartUnitField24Eq2 mirror (0x170120)
        bool mIsTrikeR; //0xDE — INIT: isKartUnitField24Eq3 mirror (0x170130)
        uint8_t mPadDF[2]; //0xDF-0xE0
        bool mIsEnableRun; //0xE1
        uint8_t mPadE2[3]; //0xE2 - 0xE4
        bool mIsNetVS; //0xE5 — INIT: bit3 of the manager global at 0x87fcd0->+0x24 (0x17014c)
        bool mIsNetSend; //0xE6 — INIT: mIsNetVS && (param+0xd54 != 2) (0x17015c-0x17016c)
        bool mIsNetRecv; //0xE7 — INIT: mIsNetVS && (param+0xd54 == 2) (0x170184); on
            // level-mode change: 0 for cpu, else copies 0xE8 (setKartVehicleLevelMode_7100172ebc)
        uint8_t mIsNetRecvDefault; //0xE8 — INIT: same as mIsNetRecv (0x170188); source
            // byte copied into mIsNetRecv by setKartVehicleLevelMode_7100172ebc
        bool mIsPolice; //0xE9
        bool mIsThief; //0xEA
        bool mIsEndTeresaTrigger; //0xEB
        bool mIsGoalGhostAlone; //0xEC
        uint8_t mPadED[7]; //0xED - 0xF3
        float mF_f4; //0xF4 — float; multiplied with getKartUnitF32F90 and stored
            // to +0x26C by the ctor helper 0x170548 (0x170588-0x1705a4)
        uint8_t mPadF8[0xC]; //0xF8 - 0x103
        uint32_t mChassisMirror19C; //0x104 — copied to KartChassis+0x19C by helper
            // 0x170548 (0x1705b8)
        uint32_t mChassisMirror1A0; //0x108 — -> KartChassis+0x1A0
        uint32_t mChassisMirror1A4; //0x10C — -> KartChassis+0x1A4
        sead::Vector3f mKartScaleVec; //0x110
        float mKartScaleMultiplier; //0x11C
        uint8_t mPad120[0x0C]; //0x120 - 0x12B
        float mCameraShownHeight; //0x12C
        uint8_t mPad130[0x20]; //0x130 - 0x14F
        float mWaterDepth; //0x150
        uint8_t mPad154[0x10]; //0x154 - 0x163
        float mBikeConst164; //0x164 — ctor picks from table 0xf20898 indexed by
            // mIsHangOnBike (0x1704f4-0x17051c)
        float mBikeConst168; //0x168 — same, table 0xf208a0[mIsHangOnBike]
        uint8_t mPad16C[4]; //0x16C - 0x16F
        ControlInfo kartControlInfo; //0x170 - 0x183
        uint8_t mPad184[0x40]; //0x184 - 0x1C3
        float mAntiGEmissionFrame; //0x1C4
        uint32_t mPad1C8; //0x1C8
        uint32_t mKartStatusBits; //0x1CC — evidenced bits: 4 (FUN_7100174ec8),
            // 6 (FUN_7100174f5c), 14+21 volatile 0x204000 gate (FUN_710017a830),
            // 29 (FUN_7100177400, byte 0x1CF >>5)
        uint32_t mKartFrames; //0x1D0 — zeroed per-frame (FUN_7100173df4)
        uint8_t mPad1D4[5]; //0x1D4 - 0x1D8
        bool mFlag1D9; //0x1D9 — set true by FUN_7100173204 (SusKit call path)
        uint8_t mPad1DA[2]; //0x1DA - 0x1DB
        float mAntiGTransFrame; //0x1DC
        float mStartCharge; //0x1E0
        uint32_t mStarFrames; //0x1E4 — zeroed by FUN_7100175af4
        uint32_t mGessoFrames; //0x1E8 — set to 1 by FUN_7100175afc (min-1 semantics)
        int32_t mTeresaFrames; //0x1EC — compared ==0x258/600 by FUN_7100174ce8
        float mUnknown1F0; //0x1F0 — float (FUN_710017842c: ldr s)
        int mJumpActionType; //0x1F4
        uint8_t mPad1F8[8]; //0x1F8 - 0x1FF
        uint32_t mTrickFramesLeft; //0x200
        uint32_t mTrickFrames; //0x204
        uint8_t mPad208[0x14]; //0x208 - 0x21B
        uint32_t mPressFrames; //0x21C
        float mPressScale; //0x220
        uint32_t mThunderFrames; //0x224
        float mThunderScale; //0x228
        uint32_t mPad22C; //0x22C
        uint32_t mSlipstreamChargeFrames; //0x230
        uint32_t mSlipstreamDashFrames; //0x234
        uint8_t mPad238[0xC]; //0x238 - 0x243
        uint32_t mControlLockFrames; //0x244
        uint32_t mBattleInvincibilityFrames; //0x248
        uint32_t mPad24C; //0x24C
        uint32_t mBlinkVisualFrames; //0x250
        bool mIsDontSearch; //0x254
        uint8_t mPad255[3]; //0x255 - 0x257
        uint32_t mAirFramesForJugem; //0x258
        uint32_t mPrisonIndex; //0x25C
        float mKillerEndRatio; //0x260
        uint8_t mPad264[8]; //0x264 - 0x26B
        float mF26c; //0x26C — ctor helper 0x170548: getKartUnitF32F90(kartParameter)
            // * mF_f4 (0x170588-0x1705a4)
        bool mIsAfterOnResetPosition; //0x270
        uint8_t mPad271[3]; //0x271 - 0x273
        float mUnknown274; //0x274 — float (FUN_710017842c)
        float mXluAlpha; //0x278 — float, verified (FUN_710017842c ldr/str s on a
            // base with mKartStatusBits/mKartFrames); matches recorder channel
            // "p_xlu_alpha". The strb users at +0x278 are the boost-envelope
            // struct (its own bytes 0x250-0x253), NOT this field.
        uint8_t mPad27C[0x1C]; //0x27C - 0x297
        uint32_t mRaceInvincibilityFrames; //0x298
        uint8_t mPad29C[0x24]; //0x29C - 0x2BF
        uint8_t mFlag2C0; //0x2C0 — zeroed by FUN_7100173204
        uint8_t mPad2C1[0x63]; //0x2C1 - 0x323
        uint32_t mRenegadeCaughtFrames; //0x324
        uint32_t mCaughtRenegadeToPrisonTime; //0x328
        uint8_t mPad32C[8]; //0x32C - 0x333
        uint32_t mJugemStuckCount; //0x334
        uint32_t mPad338; //0x338
        bool mIsNeedToSendJugemHang; //0x33C
        uint8_t mPad33D[3]; //0x33D - 0x33F
        sead::Vector2f mStickVolForKiller; //0x340 — zeroed via 8-byte store in FUN_7100173c40
        uint8_t mPad348[0x28]; //0x348 - 0x36F
        
        ControlInfo getControlInfo();

        void setMatrixAndVel(gear::MtxT const&, sead::Vector3<float>*);
        void onResetPosition(bool);
        
        KartVehicle();
	};
}
