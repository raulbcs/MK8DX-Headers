#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object {
// Root physics body of the item/kart physics family (32 vtables share
// the KartPhysicsBody_shapePos_710001299c slot). Vtable .data 0x11ada60
// (GOT cell 0x12fb050), ctor 0x71000116a4(this, x1 = param block, w2).
//
// Concrete size 0x328: the intermediate base (KartPhysicsBodyMid,
// ctor 0x3703c) starts its own fields at 0x328. Ctor-proven writes
// only below; interior unproven gaps are pads.
//
// Derived evidence: Koura ctor 0x30d50 (vptr 0x11b0d98, n=126) calls
// the root ctor; TogezoBomb's inlined ctor (vptr 0x11b0898, n=128)
// calls the Koura ctor. Item factories inline the ctors — the
// out-of-line copies have no direct callers.
//
// Vtable slot facts (root vtable): slot 0x18 = deleting dtor
// (operator delete); slots 0x340-0x3a8 (102-115) = no-ops; slot 0x120
// = no-op; slot 0x3f8 (125) = returns 40.0f; slot 0x1f8 (61) =
// sead::SharcArchiveRes::setCurrentDirectoryImpl (shared archive-
// interface band; Koura overrides it at 0x710002ffc4). Slot 52
// (vt+0xa0) = per-core physics integration (bodyPhysicsCoreSlot52_
// 71000142d0): gate on bytes 0x1c9/0x1ca/0x1cb, applies a quarter of
// the stored impulse 0x1dc-0x1e4 to the velocity 0x160-0x168 and
// integrates position with the per-frame delta 0x154-0x15c; velocity
// is zeroed after the per-wheel integration. Slot 69 (vt+0x238) =
// driver up/basis update (bodyDriverUpBasisSlot69_7100037ff0): copies
// the driver record's rec+0x40/44/48 into 0x1dc-0x1e4 and rebuilds the
// basis vector at 0x344-0x34c (past this root; KartPhysicsBodyMid).
// Slot 96 (vt+0x310) = boost speed update (bodyBoostSpeedSlot96_
// 7100038a44): accumulates into the scalar speed at 0x150 (clamps
// 2.5f low; 15.0f upper when byte +0x216 set, 40.0f when clear) and
// writes basis*speed into 0x204-0x20c and the per-frame delta
// 0x154-0x15c. Koura slot
// 0x338 (101) writes the (0x428, 0x4c8) word pair only while 0x4c8
// has bit 31 set; slot 0x1f8 reads the byte at 0x4cc.
//
// Additional slot facts (root vtable):
// slot 28 (0xf0, bodySpawnObjSlot28_7100036aec): object spawn/update —
//   visibility-gated; submits the position (0x150 * basis 0x344-0x34c
//   + 0x350-0x358) to the object manager and raises the +0x118 virtual
//   callback on accept; reads the 0x370/0x388 setup selection.
// slot 51 (0x1a8, kartBodyReleaseResSlot51_7100014200): gated on flags
//   0x214/0x215; decrements a refcount at [result+0x80] for the word
//   id at 0x58; when guard byte 0x1f3 is clear copies word 0x2e8 to
//   0x2ec, then always sets 0x2e8 = 3 and 0x1f3 = 1.
// slot 64 (0x210, kartBodyResetSlot64_710003127c): copies the driving
//   params (0x7100037e10), stores -1 at +0x428, tail-calls
//   FUN_7100044410([this+0x40], 0).
// slot 82 (0x2a0, kartBodySlot82JudgeSpinReset_7100019954): state byte
//   0x71 must be 3 or 4; "allow" requires 0x130 >= 0 and 0x12c/0x134
//   inside rodata bounds (0x7100ed5948/0x7100ed594c); flagging the
//   spin reset (byte 0x228 = 1, halfword 0x1ee = 0xffff) fires when
//   the frame word 0x50 reaches the count at [this+0x1a8], when the
//   allow bit is clear with byte 0x1fc set, or when state == 4 and
//   word 0x1c0 is 0xf or 0x10 and word 0x74 >= 0xb4; the saturating
//   halfword 0x1ee increments with cap 0xb otherwise, bypassed when
//   byte 0x1fc is set.
// slot 86 (0x2c0, kartBodySlot86DebugDraw_7100011de0): debug-draw
//   dispatch on the collector at [this+0x278] with [this+0x68].
// slot 88 (0x2d0, kartPhysicsBodySlot88SpawnSubBody_7100038700):
//   allocates a 0x280 sub-object bound to [this+0x37c].
// slot 89 (0x2d8, bodyInitObjAndSoundsSlot89_71000322c0): binds two
//   name-tagged resources onto 0x98 / 0xd0 and stores the resolved
//   name id through the pointer at [this+0x330].
// slot 90 (0x2e0, bodyCopyDriverSetupsSlot90_7100032384): copies 4
//   wheel entries (count 0x368, array 0x370, stride 0x18) and 7 driver
//   entries (count 0x380, array 0x388, stride 0x18) into the collector
//   at [this+0x278].
// slot 91 (0x2e8, kartBodyResetStateSlot91_71000325ac): wide runtime
//   reset — rotates the 0x399/0x39a state ring, sets 0x39b = 1, zeroes
//   0x39c; resets the 0x35c-0x3d2 cluster and copies 0x12c-0x134 to
//   0x434-0x43c; sets 0x428 = -1 and 0x361 = 1 (all past this root;
//   see the derived-class headers).
// slot 92 (0x2f0, kartBodySlot92AdvanceTick_7100037d28): when state
//   0x71 == 5 fires 0x7100011468; when byte 0x360 is set, clamps
//   [this+0x128] into [1.0, vt+0x320 result] after subtracting the
//   vt+0x318 value.
// slot 98 (0x320, kouraSpinDriftSlot98_71000326b4, Koura override):
//   spin/drift item reaction gated on state 0x399 == 3; drives the
//   spinning flag byte 0x360, the basis coefficients 0x450/0x454/
//   0x458, counter 0x45c (threshold 0x257) and cap float 0x430.
// slot 108 (0x370, physBodySlot108ComputeDriftFactor_7100032110):
//   stores a drift factor into [this+0x33c], selected by race-manager
//   mode (0x7a/0x74 vs other) and [this+0x150] vs rodata 0x7100ed58bc.
// slot 109 (0x378, bodyUpdateShortPairSlot109_710003216c): invokes own
//   slots 0x3b8/0x3c8/0x3d0, then refreshes the signed halfword pair
//   0x3cc/0x3ce (skip when either is -1) via perCorePairBfs_710081a51c
//   with limit 0xc.
// slot 118 (0x3c0, bodyRespawnHandlerSlot118_710003387c): respawn /
//   start-position pick — backward scan of the manager pool entries,
//   filtered by FUN_71000312b4 over this+0x12c/0x3cc/0x3c0 vs rodata
//   500.0f/150.0f gates and an atan2 angle test against [this+0x42c]
//   degrees; fires the item trigger table on accept.
class KartPhysicsBody : public gear::Actor {
 public:
  uint64_t mField38;  // 0x38 — zeroed on ctor
  uint64_t mField40;  // 0x40 — zeroed on ctor
  uint64_t mField48;  // 0x48 — zeroed on ctor
  int64_t mField50;   // 0x50 — -1 on ctor
  uint32_t mField58;  // 0x58 — copied from *x1 (param block)
  int32_t mField5c;   // 0x5c — -1 on ctor; runtime: per-player index
                      // (<=0xb; selects [raceinfo+0x238]+idx*8 -> +0x50
                      // object in the shapePos calc 0x7100012784)
  uint32_t mField60;  // 0x60 — ctor arg w2

  // Embedded member at 0x68 (ctor stores vptr 0x11addf8, n=4)
  uint8_t mPad64[0x4];  // 0x64 — unproven gap
  char mSub68[8];       // 0x68 — extent to next write
  uint8_t mField70;     // 0x70 — 0 on ctor, then 0xb
  uint8_t mField71;     // 0x71 — body-state enum ring (read all over
                        // the shapePos calc 0x7100012784); on a basis
                        // reset (bytes +0x214/+0x215, slot 69) the old
                        // value moves to +0x72, this becomes 4
  uint8_t mField72;     // 0x72 — previous body-state byte of the ring
  uint8_t mField73;     // 0x73 — set to 1 alongside the ring rotation on
                        // a basis reset
  uint32_t mField74;    // 0x74 — cleared to 0 on a basis reset
  void* mSelf78;        // 0x78 — ctor stores `this` here
  void* mArray80;       // 0x80 — new[](0xb0), zeroed head
  void* mArray88;       // 0x88 — new[](0xb0)
  void* mArray90;       // 0x90 — new[](0xb0)
  void* mQueryObj98;    // 0x98 — collision/terrain query object read
                        // by the shapePos calc (vcall slot 0x80 bool,
                        // axis getters 0x71001425c4/0x71001425f0,
                        // scale setter 0x71006a1194); not ctor-written
  char mPadA0[0x30];    // 0xa0 — to 0xd0
  uint64_t mFieldD0;    // 0xd0 — zeroed on ctor
  uint64_t mFieldD8;    // 0xd8 — zeroed on ctor
  uint32_t mFieldE0;    // 0xe0 — zeroed on ctor
  int32_t mFieldE4;     // 0xe4 — -1 on ctor
  float mScaleXe8;      // 0xe8 — per-axis scale cache vs the query
  float mScaleYec;      // 0xec — object's axis getters; when one
  float mScaleZf0;      // 0xf0 — drifts from the fresh value, the calc
  float mScaleWf4;      // 0xf4 — re-applies it via 0x71006a1194
                        // (all zeroed on ctor; 1.0 = no override)
  uint32_t mFieldF8;    // 0xf8 — zeroed on ctor
  char mPadFc[4];       // 0xfc — unproven padding

  // Embedded member at 0x100 (ctor 0x8dbc50; vptr 0x12d5b98, n=14)
  char mSub100[0xc];   // 0x100..0x10c — unproven gap
  float mF10c;         // 0x10c — 1.0f
  uint64_t mField110;  // 0x110 — zeroed on ctor
  uint8_t mField118;   // 0x118 — zeroed on ctor
  char mPad119[7];     // 0x119 — unproven padding
  // 0x120-0x177: kinematic state block (ctor memset 0x58; readers are
  // the isSurfaceValid slot 0x7100013190: pos + vel*t + 0.5*accel*t^2)
  uint8_t mPad120[0xc];   // 0x120 — unproven padding
  float mPosX12c;         // 0x12c — position xyz (written by the
  float mPosY130;         // 0x130 — shapePos calc integration 0x71000137a0+;
  float mPosZ134;         // 0x134 — ==2 state branch copies them raw)
  uint8_t mPad138[0x18];  // 0x138 — unproven padding
  float mSpeed150;        // 0x150 — scalar speed accumulator: slot 96
                          // accumulates into it with a 2.5f low clamp,
                          // upper bound 15.0f when byte +0x216 is set,
                          // 40.0f when clear
  float mDeltaX154;       // 0x154 — per-frame position delta xyz: slot 52
  float mDeltaY158;       // 0x158 — integrates position as pos += velocity
  float mDeltaZ15c;       // 0x15c — + delta (mode 0xd samples a direction
                          // into it, scaled by 70.0); slot 96 tail writes
                          // basis * speed here
  float mVelX160;       // 0x160 — velocity xyz: slot 52 subtracts a
  float mVelY164;       // 0x164 — quarter of the stored impulse
  float mVelZ168;       // 0x168 — (0x1dc-0x1e4) per core step and zeroes
                        // the triple after the per-wheel integration
  char mPad16c[0xc];    // 0x16c — unproven padding
  uint16_t mField178;     // 0x178 — 1 on ctor
  char mPad17a[2];        // 0x17a — unproven padding
  float mAccX17c;         // 0x17c — acceleration xyz (written by fn
  float mAccY180;         // 0x180 — 0x7100012e20-0x13190; ctor zeroes via
  float mAccZ184;         // 0x184 — unaligned u64 stores, split here)
  float mAccW188;         // 0x188
  float mF18c;            // 0x18c — ctor 0.05f (drag/damping constant?)
  const char* mName190;   // 0x190 — rodata 0xf20ea8 (name pair 2)
  const char* mName198;   // 0x198 — rodata 0xf20eac
  const char* mName1a0;   // 0x1a0 — rodata 0xf20eb0 (name pair 1)
  const char* mName1a8;   // 0x1a8 — rodata 0xf20eb4
  uint8_t mPad190[0x20];  // 0x190 — unproven gap; [this+0x1a8] points
                          // at the per-player count word (slot 82 frames
                          // word 0x50 against it)
  uint16_t mField1b0;     // 0x1b0 — -1 on ctor
  uint16_t mField1b2;     // 0x1b2 — -1 on ctor
  uint8_t mField1b4;      // 0x1b4 — 1 on ctor
  char mPad1b5[3];        // 0x1b5 — unproven padding
  uint64_t mField1b8;     // 0x1b8 — per-core control-block table pointer
                          // (slot 52): u32 array stride 4 at +0x40,
                          // pointer array stride 8 at +0x20
  uint32_t mField1c0;     // 0x1c0 — direction-candidate bitfield, low 5
                          // bits decoded from the global candidate table
                          // winner halfword (slot 52); tested == 0xd
  uint32_t mField1c4;     // 0x1c4 — direction-candidate bitfield, low 3
                          // bits (winner halfword >> 5, slot 52)
  char mPad1c8[1];        // 0x1c8 — unproven gap (ctor zeroes u64 at
                          // unaligned 0x1c6)
  uint8_t mGate1c9;       // 0x1c9 — physics gate flag: slot 52 skips the
  uint8_t mGate1ca;       // 0x1ca — core step when all three of these are
  uint8_t mGate1cb;       // 0x1cb — clear
  char mPad1cc[0x4];      // 0x1cc — unproven gap
  uint64_t mField1d0;     // 0x1d0 — zeroed on ctor
  uint32_t mField1d8;     // 0x1d8 — zeroed on ctor
  float mImpulseX1dc;     // 0x1dc — stored impulse/driver-basis xyz:
  float mImpulseY1e0;     // 0x1e0 — slot 69 copies the driver record's
  float mImpulseZ1e4;     // 0x1e4 — rec+0x40/44/48 here; slot 52 applies
                          // a quarter of it to the velocity per step
  float mF1e8;            // 0x1e8 — 3.5f; also read as the manager/mode
                          // word by slot 52
  uint8_t mField1ec;      // 0x1ec — zeroed on ctor
  char mPad1ed[1];        // 0x1ed — unproven padding
  uint16_t mField1ee;     // 0x1ee — -1 on ctor
  uint32_t mField1f0;     // 0x1f0 — zeroed on ctor
  uint16_t mField1f4;     // 0x1f4 — zeroed on ctor
  char mPad1f6[2];        // 0x1f6 — unproven padding
  uint32_t mField1f8;     // 0x1f8 — 1 on ctor
  uint8_t mField1fc;      // 0x1fc — 1 on ctor
  char mPad1fd[3];        // 0x1fd — unproven padding
  uint64_t mField200;     // 0x200 — zeroed on ctor
  uint64_t mField208;     // 0x208 — best direction-candidate entry
                          // (threshold 0.08; published by slot 52);
                          // slot 96 also stores basis*speed into
                          // 0x204/0x208/0x20c
  char mPad210[4];        // 0x210 — best candidate score float (slot 52)
  uint8_t mFlag214;       // 0x214 — basis-reset trigger flag (slot 69)
  uint8_t mFlag215;       // 0x215 — basis-reset trigger flag (slot 69)
  uint8_t mFlag216;       // 0x216 — boost dir selector: set picks the alt
                          // path in slot 96 (speed clamp 15.0f instead
                          // of 40.0f)
  char mPad217[1];        // 0x217 — unproven gap
  uint64_t mField218;     // 0x218 — zeroed on ctor
  uint64_t mField220;     // 0x220 — zeroed on ctor; runtime: rigid-body
                          // state enum (RigidBodyUpdate dispatches on
                          // cmp #7, fn 0x7100013b2c)
  char mPad228[6];        // 0x228 — ctor zeroes u16 0x228, u8 0x22a;
                          // byte 0x228 = 1 flags a spin reset (slot 82
                          // kartBodySlot82JudgeSpinReset_7100019954 and
                          // the Koura slot 82 kouraStateSlot82_710002f374)

  // Recorder channel descriptor at 0x230 (shape of RaceCheckerVt3's
  // channel: fn cell 0x12fae28, empty-string name, owner back-ptr)
  uint8_t mPad22E[0x2];  // 0x22E — unproven gap
  void* mChan230;        // 0x230 — cell 0x12fb108+0x10
  void* mChan238;        // 0x238 — fn (cell 0x12fae28+0x10)
  const char* mChan240;  // 0x240 — ""
  uint8_t mPad240[0x8];  // 0x240 — unproven gap
  void* mChan248;        // 0x248 — cell 0x12fb110+0x10
  void* mChan250;        // 0x250 — owner = this
  void* mChan258;        // 0x258 — cell 0x12fb110+0x10 (ctor also
                         // stores cell 0x12fb118 at 0x260)
  char mPad260[0x14];    // 0x260 — ctor zeroes + stores more cells
  uint16_t mField274;    // 0x274
  uint8_t mPad276[0x2];  // 0x276 — unproven gap
  uint64_t mField278;    // 0x278 — zeroed on ctor; runtime: collision
                         // helper object (CollisionScale 0x7100013338
                         // vcalls its slots 0x98/0xa8)
  uint64_t mField280;    // 0x280 — zeroed on ctor
  uint32_t mField288;    // 0x288 — zeroed on ctor
  char mPad28c[0x30];    // 0x28c — unproven padding
  uint32_t mField2bc;    // 0x2bc — zeroed on ctor
  char mPad2c0[0x18];    // 0x2c0 — unproven padding
  uint32_t mField2d8;    // 0x2d8 — zeroed on ctor
  char mPad2dc[0xc];     // 0x2dc — unproven padding
  uint32_t mCur2e8;      // 0x2e8 — current/previous value pair: the
  uint32_t mPrev2ec;     // 0x2ec — setter fn 0x7100013278 moves the old
                         // value to 0x2ec (guard byte 0x1f3), same
                         // pattern as the axis-scale cache. 0x2fc-0x310
                         // is the rigid-body update record
                         // (RigidBodyUpdate 0x7100013adc stores the
                         // input pose u32 quad into
                         // 0x304/0x308/0x30c/0x310).
  uint16_t mField2f0;    // 0x2f0
  uint8_t mPad2F2[0x2];  // 0x2F2 — unproven gap
  int32_t mField2f4;     // 0x2f4 — -1 on ctor (update-record field)
  int32_t mField2f8;     // 0x2f8 — -1 on ctor (update-record field)
  char mPad2fc[0x18];    // 0x2fc — unproven padding
  uint32_t mField314;    // 0x314 — zeroed on ctor
  char mPad318[2];       // 0x318 — unproven padding
  uint16_t mField31a;    // 0x31a — -1 on ctor
  uint32_t mField31c;    // 0x31c — zeroed on ctor
  uint16_t mField320;    // 0x320 — -1 on ctor; runtime: rescue/player
                         // state i16 pair, read by RescueBodyStateSet2
  uint16_t mField322;    // 0x322 — (0x7100012ae8), capped against 0xa
                         // (player index bound)
  uint8_t mPad324[4];    // 0x324 — to end of root (0x328); the ctor's
                         // tail only fills the three 0xb0 arrays
};
}  // namespace object
