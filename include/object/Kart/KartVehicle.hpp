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

// Canonical KartVehicle layout (byte-exact offsets, ).
// Subobject sizes proven by operator new sites in ctor
// 0x7100170100-0x7100170460: Control 0x70@0x10, Cpu 0x90@0x18, Net 0x42D8@0x20,
// Move 0x5F8@0x28, Trick 0x1A0@0x30, Body 0x160@0x38, unknown-obj ~0x90@0x40 (NOT
// React — React 0xD8 lives at KartVehicleMove+0x120, ctor 0x710017eb94),
// Collision 0x2D0@0x48 (ctor 0x139838), Chassis 0x510@0x50, ChassisAnim
// 0x130@0x58 (ctor 0x12289c), HeadLight 0x130@0x60 (ctor 0x140514), SusKit
// 0x128@0x68 (ctor 0x15dd9c), Balloon 0xAB8@0x70 (ctor 0x1142e4), SteerAssist
// 0x120@0xA0.
namespace object {

namespace Kart { struct KartSteerAssist; }  // KartSteerAssist.hpp

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
  void* mUnknownObj40;                    // 0x40 — NOT KartVehicleReact: own class
                                          //  (ctor 0x7100191f50, vtables 0x71011baf68
                                          //  [60 slots] + 0x71011bb168 @+8; alloc size
                                          //  UNCERTAIN ~0x90, no mov w0 at the site
                                          //  0x7100170238). React lives at
                                          //  KartVehicleMove+0x120.
  KartVehicleCollision* mKartCollision;  // 0x48 — object of 0x2D0 bytes (ctor 0x139838)
  KartChassis* mKartChassis;             // 0x50 — object of 0x510 bytes (ctor 0x11c0c4)
  KartChassisAnim* mKartChassisAnim;     // 0x58 — object of 0x130 bytes (ctor 0x12289c,
                                         //  receives KartChassis+0x10)
  KartVehicleHeadLight* mKartHeadLight;  // 0x60 — object of 0x130 bytes (ctor 0x140514)
  KartSusKit* mSusKit;                   // 0x68 — object of 0x128 bytes (ctor 0x15dd9c); FUN_7100174f7c
                                         //  reads a float at Sus+0xD0 (>= 1.0f gate)
  KartVehicleBalloon* mKartBalloon;      // 0x70 — object of 0xAB8 bytes (ctor 0x1142e4)
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
      mKartJugemRecover;              // 0x90 — object of 0x1D8 bytes (new @ 0x71001704dc,
                                      //  ctor 0x142a60 with mPlayerID); 8-byte thunks ldr
                                      //  x0,[x0,#0x90] (FUN_7100175a28 / FUN_7100175a30)
  uintptr_t mPad98;                   // 0x98 — unproven padding
  Kart::KartSteerAssist* mKartSteerAssist;  // 0xA0
  uint32_t mPlayerID;                 // 0xA8
  uint32_t mPadAC;                    // 0xAC — u32 read by ctor-continuation
                                      //  (0x71001706c4)
  uint32_t mBodyID;                   // 0xB0 — mush::EBodyID
  uint32_t mDriverID;                 // 0xB4 — mush::EDriverID
  uint8_t mPadB8[0x10];               // 0xB8 - 0xC7 — unproven padding; 0xB8 u32
                                      //  read at 0x7100170624/0x7100170adc
  uint32_t mTeamType;                 // 0xC8 — gear::ETeamType
  uint32_t mPadCC;                    // 0xCC — u32, mode-of-race dependent store
                                      //  (0x710016fe84/0x710016fec0)
  bool mIsMaster;                     // 0xD0
  uint8_t mPadD1;                     // 0xD1 — unproven padding
  bool mIsCpu;                        // 0xD2
  bool mIsCpuOrKiller;                // 0xD3
  bool mIsGhost;                      // 0xD4
  bool mPadD5;                        // 0xD5 — bool (0x7100170004/0x7100170030,
                                      //  0x7100174ac4, 0x710017855c)
  uint8_t mPadD6[2];                  // 0xD6-0xD7 — unproven padding
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
  bool mFlagED;                       // 0xED — bool (0x7100174b6c/0x7100174bdc/
                                      //  0x7100174ad4, 0x71001786d4)
  uint8_t mPadEE[6];                  // 0xEE - 0xF3 — unproven padding
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
  float mF130;                         // 0x130 — f32 init 0x71001709e8, read
                                       //  0x7100172d00 (buoyancy FUN_7100172ac0)
  float mF134;                         // 0x134 — f32 init 0x71001709f8
  float mF138;                         // 0x138 — f32 init 0x7100170a10
  float mF13C;                         // 0x13C — f32 (0x71001735fc, 0x7100174a6c)
  uint8_t mPad140[4];                  // 0x140 - 0x143 — unproven gap
  uint8_t mPad144[4];                  // 0x144 - 0x147 — unproven gap
  sead::Vector3f mGroundRaycast148;    // 0x148 — ground raycast hit (0x273d4c);
                                       //  z component read as float at +0x150
  float mHeight154;                    // 0x154 — f32, init -1.0
  uint8_t mPad158[0xC];                // 0x158 - 0x163 — unproven padding
  float mWaterDepth;                   // 0x150 — UNCERTAIN: no accessor found; real water state
                                       // is +0x29C/+0x2A4
  float mBikeConst164;                 // 0x164 — ctor picks from table 0xf20898 indexed by
                                       //  mIsHangOnBike (0x1704f4-0x17051c)
  float mBikeConst168;                 // 0x168 — same, table 0xf208a0[mIsHangOnBike]
  uint8_t mPad16C[4];                  // 0x16C - 0x16F — unproven padding
  ControlInfo kartControlInfo;         // 0x170 - 0x183
  uint8_t mPad184[0x40];               // 0x184 - 0x1C3 — unproven padding
  float mAntiGAmount1C4;               // 0x1C4 — anti-G amount f32 0..1 (not
                                       //  frames): set 1.0 + status bit 0x1000
                                       //  (0x172a20), ramp ±0.04/frame (0x173904),
                                       //  blend (0x179280)
  uint32_t mPad1C8;                    // 0x1C8 — unproven padding
  uint32_t mKartStatusBits;            // 0x1CC — bits 4 (FUN_7100174ec8), 6
                                       // (FUN_7100174f5c), 0x800/0x8000/
                                       //  0x200000 (race start FUN_7100175d18->0x175e60),
                                       //  14+21 gate 0x204000 (FUN_710017a830), 29
                                       //  (FUN_7100177400, byte 0x1CF>>5)
  uint32_t mKartFrames;                // 0x1D0 — zeroed per-frame (FUN_7100173df4)
  float mF1D4;                         // 0x1D4 — f32 (FUN_7100173df4:
                                       //  0x7100173f80/0x7100173fd8)
  uint8_t mPad1D8;                     // 0x1D8 — unproven padding
  bool mFlag1D9;                       // 0x1D9 — set true by FUN_7100173204 (SusKit call path)
  uint8_t mPad1DA[2];                  // 0x1DA - 0x1DB — unproven padding
  float mAntiGBlend1DC;                // 0x1DC — anti-G blend amount f32 (not
                                       //  frames; ramp site 0x173904 family)
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
  uint32_t mField208;                  // 0x208 — u32; 8-byte zero store covers
                                       //  0x208..0x20F (0x7100172414)
  uint32_t mTrickSubstate20C;          // 0x20C — trick pose id 4/5/6/7/8/0x23; +0x208 =
                                       // timer;
                                       //  +0x1CC bit 0x40000 while mTrickFramesLeft>0
                                       //  (FUN_7100175f5c)
  float mChannel210;                   // 0x210 — f32 ramp channel, gated by
                                       //  status bits 0x80/0x800000
  float mChannel214;                   // 0x214 — f32 ramp channel (same gate)
  uint8_t mPad218[4];                  // 0x218 - 0x21B — unproven padding
  uint32_t mPressFrames;               // 0x21C
  float mPressScale;                   // 0x220
  uint32_t mThunderFrames;             // 0x224
  float mThunderScale;                 // 0x228
  float mF22C;                         // 0x22C — f32 init 0x7100172438; reads
                                       //  0x710017a33c, 0x710017b650, 0x710017d274
  uint32_t mSlipstreamChargeFrames;    // 0x230
  uint32_t mSlipstreamDashFrames;      // 0x234
  uint32_t mPad238;                    // 0x238 — unproven padding
  float mF23c;                         // 0x23C — f32 0..1
  float mF240;                         // 0x240 — f32, mirror ±1 of steer
  uint32_t mControlLockFrames;         // 0x244
  int32_t mBattleInvincibilityFrames;  // 0x248
  uint32_t mCounter24C;                // 0x24C — counter (FUN_7100173df4:
                                       //  0x71001742e0/0x71001742ec; FUN_7100176400
                                       //  0x7100176a1c)
  uint32_t mBlinkVisualFrames;         // 0x250
  uint32_t mCountdown254;              // 0x254 — u32 countdown, 180 frames
                                       //  (set 0x177688, tick decrement)
  uint32_t mAirFramesForJugem;         // 0x258
  uint32_t mPrisonIndex;               // 0x25C
  float mKillerEndRatio;               // 0x260
  bool mFlag264;                       // 0x264 — bool (0x7100172470, 0x71001737b8,
                                       //  0x71001763cc)
  uint8_t mPad265[3];                  // 0x265 - 0x267 — unproven padding
  uint32_t mField268;                  // 0x268 — u32 (FUN_7100173df4:
                                       //  0x7100174328/0x7100174334)
  float
      mF26c;                             // 0x26C — ctor helper 0x170548: getKartUnitF32F90(kartParameter)
                                         //  * mF_f4 (0x170588-0x1705a4)
  uint32_t mCountdown270;              // 0x270 — u32 countdown, 180 frames
                                       //  (set 0x173124, tick decrement)
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
  uint8_t mPad2C1[0x1B];               // 0x2C1 - 0x2DB — unproven padding
  uint32_t mSlotTable2DC[14];          // 0x2DC - 0x313 — slot array init'd by the
                                       //  ctor-continuation (twin blocks
                                       //  0x7100170b2c..0x7100172050); per-slot
                                       //  semantics open
  float mBuoyancyF314[3];              // 0x314 - 0x31F — buoyancy group
                                       //  (FUN_7100172ac0: 0x7100172d5c-0x7100172d84)
  uint32_t mField320;                  // 0x320 — zeroed as an 8-byte pair with
                                       //  mRenegadeCaughtFrames (str xzr
                                       //  0x7100172498); read 0x7100177a84/
                                       //  0x7100177cfc
  uint32_t mRenegadeCaughtFrames;        // 0x324
  uint32_t mCaughtRenegadeToPrisonTime;  // 0x328
  uint8_t mPad32C[8];                    // 0x32C - 0x333 — unproven padding
  uint32_t mJugemStuckCount;             // 0x334
  uint32_t mPad338;                      // 0x338 — unproven padding
  bool mIsNeedToSendJugemHang;           // 0x33C
  uint8_t mPad33D[3];                    // 0x33D - 0x33F — unproven padding
  sead::Vector2f
      mStickVolForKiller;  // 0x340 — zeroed via 8-byte store in FUN_7100173c40
  bool mFlag348;                       // 0x348 — bool (0x7100178358, FUN_71001782f8)
  uint8_t mPad349[3];                  // 0x349 - 0x34B — unproven padding
  // 0x34C..0x36F — f32 group accessed by FUN_71001819b0/FUN_7100182f38
  // (0x7100182350-0x7100182424, 0x71001866a4) — object attribution UNCERTAIN
  // (this may be KartVehicleMove, a 0x5F8-byte object); left unpadded.
  uint8_t mPad34C[0x24];               // 0x34C - 0x36F — unproven padding

  // Extent 0x370 — allocation site 0x710016ddcc (mov w0,#0x370; bl 0x710060b234;
  // bl ctor 0x710016f868; str x27,[x19,#0x18]). The ctor is ONE fallthrough
  // chain that file_list.yml slices into 5 FUNs (0x16f868/0x16fe8c/0x170090/
  // 0x1703f0/0x170548); x19 stays live across all of them.
  // extent 0x370

  ControlInfo getControlInfo();

  void setMatrixAndVel(gear::MtxT const&, sead::Vector3<float>*);
  void resetAfterSetMatrix();
  void calcCamTargetPos_(sead::Vector3<float>*);
  void onResetPosition(bool);
  void onCutOffFromJugem();

  KartVehicle();
};
}  // namespace object
