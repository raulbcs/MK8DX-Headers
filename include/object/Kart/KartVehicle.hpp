#pragma once

#include <cstdint>

#include "KartChassis.hpp"
#include "KartChassisAnim.hpp"
#include "KartJugemRecover.hpp"
#include "KartParameter.hpp"
#include "KartRecorderChannels.hpp"
#include "KartRecorderKey.hpp"
#include "KartSteerAssist.hpp"
#include "KartSusKit.hpp"
#include "KartUnit.hpp"
#include "KartVehicleBalloon.hpp"
#include "KartVehicleBody.hpp"
#include "KartVehicleCollision.hpp"
#include "KartVehicleControl.hpp"
#include "KartVehicleCpu.hpp"
#include "KartVehicleHeadLight.hpp"
#include "KartVehicleNet.hpp"
#include "KartVehicleReact.hpp"
#include "KartVehicleTrick.hpp"
#include "kart/KartVehicleMove.hpp"  // real 64-bit layout (the object/ stub is gone)

// Canonical KartVehicle layout (byte-exact offsets, v400).
// Subobject sizes proven by operator new sites in ctor
// 0x7100170100-0x7100170460: Control 0x70@0x10, Cpu 0x90@0x18, Net 0x42D8@0x20,
// Move 0x5F8@0x28, Trick 0x1A0@0x30, Body 0x160@0x38, React 0x90@0x40,
// Collision 0x2D0@0x48 (ctor 0x139838), Chassis 0x510@0x50, ChassisAnim
// 0x130@0x58 (ctor 0x12289c), HeadLight 0x130@0x60 (ctor 0x140514), SusKit
// 0x128@0x68 (ctor 0x15dd9c), Balloon 0xAB8@0x70 (ctor 0x1142e4), SteerAssist
// 0x120@0xA0.
namespace object {

class KartVehicle {
 public:
  struct ControlInfo {
    uint32_t mKeyPadState;  // 0x00 — unproven padding
    uint32_t mPad04;        // 0x04 — unproven padding
    uint32_t mPad08;        // 0x08 — unproven padding
    float controlStickX;    // 0x0C
    float controlStickY;    // 0x10
  };

  // The Collision / HeadLight / SusKit / Balloon / RecorderKey / PathJob
  // classes are defined (Collision, Balloon) or size-annotated elsewhere;
  // all unnamed in the binary — sizes proven by allocation sites.

  KartVehicle* mKartVehicle;  // 0x00
  KartUnit* mKartUnit;        // 0x08
  KartVehicleControl*
      mKartVehicleControl;          // 0x10 — FUN_7100172e90 writes a
                                    //  u8 flag at this subobject's +0x18
  KartVehicleCpu* mKartVehicleCpu;  // 0x18 — same +0x18 u8 flag
                                    // (FUN_7100172e90)
  KartVehicleNet* mKartVehicleNet;  // 0x20 — same +0x18 u8 flag
                                    // (FUN_7100172e90)
  KartVehicleMove*
      mKartVehicleMove;                  // 0x28 — deref +0x118, +0x37c (FUN_7100173234/324c)
  KartVehicleTrick* mKartVehicleTrick;   // 0x30
  KartVehicleBody* mKartVehicleBody;     // 0x38
  KartVehicleReact* mKartVehicleReact;   // 0x40
  KartVehicleCollision* mKartCollision;  // 0x48 — size 0x2D0 (ctor 0x139838)
  KartChassis* mKartChassis;             // 0x50 — size 0x510 (ctor 0x11c0c4)
  KartChassisAnim* mKartChassisAnim;     // 0x58 — size 0x130 (ctor 0x12289c,
                                         //  receives KartChassis+0x10)
  KartVehicleHeadLight* mKartHeadLight;  // 0x60 — size 0x130 (ctor 0x140514)
  KartSusKit* mSusKit;                   // 0x68 — size 0x128 (ctor 0x15dd9c); FUN_7100174f7c
                                         //  reads a float at Sus+0xD0 (>= 1.0f gate)
  KartVehicleBalloon* mKartBalloon;      // 0x70 — size 0xAB8 (ctor 0x1142e4)
  KartParameter* mKartParameter;         // 0x78 — 0xb8-byte param object; init by the
                                         //  stat calc FUN_710014b6d0, getters cached
                                         //  as bytes at +0xd8..0xdd by FUN_7100170090
  KartRecorderKey* mRecorderKey;         // 0x80 — per-kart recorder key/writer, size
                                         //  0x298 (new @ 0x7100170458, setup
                                         //  0x3ae42c); skipped for ghosts/replays
  KartRecorderChannels*
      mRecorderChannels;  // 0x88 — per-kart recorder channel
                          //  hub (recorder::Registry subclass), size 0x2B8 (new
                          //  @ 0x71001704c0, setup
                          //  recorderSetupKartStateChannels_71003aed50); int
                          //  state at +0x8
                          //  (==2 gate in the Path2Gate cluster,
                          //  FUN_7100173140)
  KartJugemRecover*
      mKartJugemRecover;              // 0x90 — size 0x1D8 (new @ 0x71001704dc,
                                      //  ctor 0x142a60 with mPlayerID); 8-byte thunks ldr
                                      //  x0,[x0,#0x90] (FUN_7100175a28 / FUN_7100175a30)
  uintptr_t mPad98;                   // 0x98 — unproven padding
  KartSteerAssist* mKartSteerAssist;  // 0xA0
  uint32_t mPlayerID;                 // 0xA8
  uint32_t mPadAC;                    // 0xAC — unproven padding
  uint32_t mBodyID;                   // mush::EBodyID 0xB0
  uint32_t mDriverID;                 // mush::EDriverID 0xB4
  uint8_t mPadB0[0x8];                // 0xB0 — unproven gap
  uint8_t mPadB8[0x10];               // 0xB8 - 0xC7 — unproven padding
  uint32_t mTeamType;                 // gear::ETeamType 0xC8
  uint8_t mPadC8[0x4];                // 0xC8 — unproven gap
  uint32_t mPadCC;                    // 0xCC — unproven padding
  bool mIsMaster;                     // 0xD0
  uint8_t mPadD1;                     // 0xD1 — unproven padding
  bool mIsCpu;                        // 0xD2
  bool mIsCpuOrKiller;                // 0xD3
  bool mIsGhost;                      // 0xD4
  uint8_t mPadD5[3];                  // 0xD5-0xD7 — unproven padding
  bool mIsBike;                       // 0xD8 — INIT: mirrored from isKartUnitState24Eq1 by
                                      //  FUN_7100170090 (0x1700d0); suggests KartUnit mode_24==1
                                      //  encodes bike
  bool mIsHangOnBike;                 // 0xD9 — INIT: isKartUnitField28Eq2 mirror (0x1700e0)
  bool mIsHangOnBike_;                // 0xDA — INIT: isKartUnitField28Eq2 mirror again
                                      // (0x1700f0)
  bool mIsBikeRideType;               // 0xDB — INIT: isKartUnitState24Eq1Or28Eq3 mirror
                                      // (0x170100)
  bool mIsATVRideType;                // 0xDC — INIT: isKartUnitState28Eq3 mirror (0x170110)
  bool mIsTrike;                      // 0xDD — INIT: isKartUnitField24Eq2 mirror (0x170120)
  bool mIsTrikeR;                     // 0xDE — INIT: isKartUnitField24Eq3 mirror (0x170130)
  uint8_t mPadDF[2];                  // 0xDF-0xE0 — unproven padding
  bool mIsEnableRun;                  // 0xE1 — setter FUN_7100172eb0
                                      //  (0x7100171b6c): *this = v & 1
  uint8_t mPadE2[3];                  // 0xE2 - 0xE4 — unproven padding
  bool mIsNetVS;                      // 0xE5 — INIT: bit3 of the manager global at 0x87fcd0->+0x24
                                      // (0x17014c)
  bool mIsNetSend;                    // 0xE6 — INIT: mIsNetVS && (param+0xd54 != 2)
                                      // (0x17015c-0x17016c)
  bool
      mIsNetRecv;  // 0xE7 — INIT: mIsNetVS && (param+0xd54 == 2) (0x170184); on
                   //  level-mode change: 0 for cpu, else copies 0xE8
                   //  (setKartVehicleLevelMode_7100172ebc)
  uint8_t
      mIsNetRecvDefault;               // 0xE8 — INIT: same as mIsNetRecv (0x170188); source
                                       //  byte copied into mIsNetRecv by
                                       //  setKartVehicleLevelMode_7100172ebc
  bool mIsPolice;                      // 0xE9
  bool mIsThief;                       // 0xEA
  bool mIsEndTeresaTrigger;            // 0xEB
  bool mIsGoalGhostAlone;              // 0xEC
  uint8_t mPadED[7];                   // 0xED - 0xF3 — unproven padding
  float mF_f4;                         // 0xF4 — factor into +0x26C via helper 0x170548
  uint8_t mPadF8[0xC];                 // 0xF8 - 0x103 — unproven padding
  uint32_t mChassisMirror19C;          // 0x104 — copied to KartChassis+0x19C by helper
                                       //  0x170548 (0x1705b8)
  uint32_t mChassisMirror1A0;          // 0x108 — -> KartChassis+0x1A0
  uint32_t mChassisMirror1A4;          // 0x10C — -> KartChassis+0x1A4
  sead::Vector3f mKartScaleVec;        // 0x110
  float mKartScaleMultiplier;          // 0x11C
  uint8_t mPad120[0x0C];               // 0x120 - 0x12B — unproven padding
  float mCameraShownHeight;            // 0x12C
  uint8_t mPad130[0x20];               // 0x130 - 0x14F — unproven padding
  float mWaterDepth;                   // 0x150 — UNCERTAIN: no accessor found; real water state
                                       // is +0x29C/+0x2A4
  uint8_t mPad154[0x10];               // 0x154 - 0x163 — unproven padding
  float mBikeConst164;                 // 0x164 — ctor picks from table 0xf20898 indexed by
                                       //  mIsHangOnBike (0x1704f4-0x17051c)
  float mBikeConst168;                 // 0x168 — same, table 0xf208a0[mIsHangOnBike]
  uint8_t mPad16C[4];                  // 0x16C - 0x16F — unproven padding
  ControlInfo kartControlInfo;         // 0x170 - 0x183
  uint8_t mPad184[0x40];               // 0x184 - 0x1C3 — unproven padding
  float mAntiGEmissionFrame;           // 0x1C4 — UNCERTAIN: no access site found
  uint32_t mPad1C8;                    // 0x1C8 — unproven padding
  uint32_t mKartStatusBits;            // 0x1CC — bits 4 (FUN_7100174ec8), 6
                                       // (FUN_7100174f5c), 0x800/0x8000/
                                       //  0x200000 (race start FUN_7100175d18->0x175e60),
                                       //  14+21 gate 0x204000 (FUN_710017a830), 29
                                       //  (FUN_7100177400, byte 0x1CF>>5)
  uint32_t mKartFrames;                // 0x1D0 — zeroed per-frame (FUN_7100173df4)
  uint8_t mPad1D4[5];                  // 0x1D4 - 0x1D8 — unproven padding
  bool mFlag1D9;                       // 0x1D9 — set true by FUN_7100173204 (SusKit call path)
  uint8_t mPad1DA[2];                  // 0x1DA - 0x1DB — unproven padding
  float mAntiGTransFrame;              // 0x1DC — UNCERTAIN: no access site found
  float mStartCharge;                  // 0x1E0 — rocket-start charge 0..1 (FUN_7100173df4,
                                       // 173ec0..173ef4);
                                       //  GO tiers 0.95/0.935/0.92/0.90 -> 0x4000/0x2000/0x1000
  uint32_t mStarFrames;                // 0x1E4 — zeroed by FUN_7100175af4
  uint32_t mGessoFrames;               // 0x1E8 — set to 1 by FUN_7100175afc (min-1
                                       // semantics)
  int32_t mTeresaFrames;               // 0x1EC — compared ==0x258/600 by FUN_7100174ce8
  float mUnknown1F0;                   // 0x1F0 — float (FUN_710017842c: ldr s)
  int mJumpActionType;                 // 0x1F4
  uint8_t mPad1F8[8];                  // 0x1F8 - 0x1FF — unproven padding
  uint32_t mTrickFramesLeft;           // 0x200
  uint32_t mTrickFrames;               // 0x204
  uint8_t mPad208[4];                  // 0x208 - 0x20B — unproven padding
  uint32_t mTrickSubstate20C;          // 0x20C — trick pose id 4/5/6/7/8/0x23; +0x208 =
                                       // timer;
                                       //  +0x1CC bit 0x40000 while mTrickFramesLeft>0
                                       //  (FUN_7100175f5c)
  uint8_t mPad210[0xc];                // 0x210 - 0x21B — unproven padding
  uint32_t mPressFrames;               // 0x21C
  float mPressScale;                   // 0x220
  uint32_t mThunderFrames;             // 0x224
  float mThunderScale;                 // 0x228
  uint32_t mPad22C;                    // 0x22C — unproven padding
  uint32_t mSlipstreamChargeFrames;    // 0x230
  uint32_t mSlipstreamDashFrames;      // 0x234
  uint8_t mPad238[0xC];                // 0x238 - 0x243 — unproven padding
  uint32_t mControlLockFrames;         // 0x244
  int32_t mBattleInvincibilityFrames;  // 0x248
  uint32_t mPad24C;                    // 0x24C — unproven padding
  uint32_t mBlinkVisualFrames;         // 0x250
  bool mIsDontSearch;                  // 0x254
  uint8_t mPad255[3];                  // 0x255 - 0x257 — unproven padding
  uint32_t mAirFramesForJugem;         // 0x258
  uint32_t mPrisonIndex;               // 0x25C
  float mKillerEndRatio;               // 0x260
  uint8_t mPad264[8];                  // 0x264 - 0x26B — unproven padding
  float
      mF26c;                             // 0x26C — ctor helper 0x170548: getKartUnitF32F90(kartParameter)
                                         //  * mF_f4 (0x170588-0x1705a4)
  bool mIsAfterOnResetPosition;          // 0x270
  uint8_t mPad271[3];                    // 0x271 - 0x273 — unproven padding
  float mUnknown274;                     // 0x274 — float (FUN_710017842c)
  float mXluAlpha;                       // 0x278 — recorder ch "p_xlu_alpha" (FUN_710017842c);
                                         // boost-envelope strb at +0x278 is NOT this field
  uint8_t mPad27C[0x1C];                 // 0x27C - 0x297 — unproven padding
  int32_t mRaceInvincibilityFrames;      // 0x298
  uint8_t mWaterState29C;                // 0x29C — water state: 0 idle, 1 in-water,
                                         //  2 forced (writer: rule == 5 -> 2, via
                                         //  getRaceCheckManager_710087fcd0 then [x0+8])
  uint8_t mPad29D[7];                    // 0x29D - 0x2A3 — unproven padding
  float mSubmergeFactor2A4;              // 0x2A4 — water submersion 0..1 (FUN_7100173df4);
                                         // sink at >0.95;
                                         //  tiers 0.90/0.92/0.935 -> 0x1000/0x2000/0x4000
                                         //  (FUN_710017a830); consumer 0x18a2b8 ->
                                         //  KartVehicleMove+0x230 water level
  float mBuoyancyOut2A8[3];              // 0x2A8 — buoyancy blend out (FUN_7100172ac8),
                                         // only when +0x2A4>0
  uint8_t mPad2B4[0xC];                  // 0x2B4 - 0x2BF — unproven padding
  uint8_t mFlag2C0;                      // 0x2C0 — zeroed by FUN_7100173204
  uint8_t mPad2C1[0x63];                 // 0x2C1 - 0x323 — unproven padding
  uint32_t mRenegadeCaughtFrames;        // 0x324
  uint32_t mCaughtRenegadeToPrisonTime;  // 0x328
  uint8_t mPad32C[8];                    // 0x32C - 0x333 — unproven padding
  uint32_t mJugemStuckCount;             // 0x334
  uint32_t mPad338;                      // 0x338 — unproven padding
  bool mIsNeedToSendJugemHang;           // 0x33C
  uint8_t mPad33D[3];                    // 0x33D - 0x33F — unproven padding
  sead::Vector2f
      mStickVolForKiller;  // 0x340 — zeroed via 8-byte store in FUN_7100173c40
  uint8_t mPad348[0x28];   // 0x348 - 0x36F — unproven padding
  uint8_t mPad370[0x748];  // 0x370 - 0xAB7 — unproven gap (region unmapped by
                           // ctor analysis)

  ControlInfo getControlInfo();

  void setMatrixAndVel(gear::MtxT const&, sead::Vector3<float>*);
  void resetAfterSetMatrix();
  void calcCamTargetPos_(sead::Vector3<float>*);
  void onResetPosition(bool);
  void onCutOffFromJugem();

  KartVehicle();
};
}  // namespace object
