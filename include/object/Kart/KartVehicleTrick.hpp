#pragma once

#include <cstdint>

#include "KartRigidBody.hpp"

// KartVehicleTrick — size 0x1A0, proven by operator new(0x1A0) in the
// KartVehicle ctor (v400 0x7100170200, stored at KartVehicle+0x30; ctor
// 0x7100195768 calls the KartRigidBody base 0x710014ddb4).
namespace object {
struct KartVehicle;  // KartVehicle.hpp

class KartVehicleTrick : public KartRigidBody {
 public:
  void* static_table_e0;           //0xE0 — ctor writes a static-table pointer here
  uint8_t pad_e8[0x10];            //0xE8 - 0xF7 — unproven padding
  KartVehicle* mOwnerKartVehicle;  //0xF8 — ctor arg (0x195768-0x1957f8)
  float mF100[3];                  //0x100..0x10B — ctor sets all three to 1.0f
  uint8_t mPad10C[0x94];           //0x10C - 0x19F — tail zeroed in ctor blocks
                                   // (+0x10C/+0x114/... u64 zeros, +0x14C=1.0f, memset 0x150..0x19B)

  // Trick lifetime (FUN_7100175f5c start / FUN_71001744a4 air tick):
  // trick start writes the rotation triples +0x11C/+0x120/+0x124 and
  // +0x134/+0x138/+0x13C, selects the anim id (0xE/0xA/0x10 by stick sign)
  // and calls the anim method FUN_71001961b4. Landing boost gate: needs
  // mTrickFrames >= 21 when Move+0x201 != 0 and Move+0x212 == 0; dispatch
  // FUN_710017a830(boostSlot, 0x100, 0) (or tier 1 when Move+0x213 != 0).
};
}  // namespace object
