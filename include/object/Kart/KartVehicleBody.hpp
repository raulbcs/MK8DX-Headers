#pragma once

#include <cstdint>

#include "KartRigidBody.hpp"

// KartVehicleBody — size 0x160, proven by operator new(0x160) in the
// KartVehicle ctor (0x7100170218, stored at KartVehicle+0x38; ctor
// 0x7100178da4 calls the KartRigidBody base 0x710014ddb4). NOTE: the
// 74-slot vtable family whose impl touches +0x240 is a DIFFERENT class —
// it cannot be this one (offsets beyond 0x160 are out of bounds).
namespace object {
struct KartVehicle;  // KartVehicle.hpp

class KartVehicleBody : public KartRigidBody {
 public:
  void* static_table_e0;           //0xE0 — ctor overwrites with a static-table
                                   // pointer (0x178df0: [0x12fd630]+0x40)
  uint8_t pad_e8[0x10];            //0xE8 - 0xF7 — unproven padding
  KartVehicle* mOwnerKartVehicle;  //0xF8 — ctor arg (0x178dbc)
  float mF100;                     //0x100
  float mF104;                     //0x104 — ctor sets -4.0f (0xc0800000)
  uint64_t mU108;                  //0x108
  float mF110[3];                  //0x110..0x11B — ctor/reset (0x178e84) set all to 1.0f;
                                   // body-velocity-layer vector .
                                   // Writers: hop charge tick FUN_710017bea0 (0x17bec4..0x17bf1c,
                                   // from Drift+0xCC clamped [0.1, 0.8]) and jump action
                                   // FUN_710017e838 (0x17ea4c..0x17eb04, +/-1.0/0.0); the trick
                                   // trigger FUN_7100175f5c reads -this+0x110 at 0x17b8f8..0x17b914
  uint8_t mFlag11C;                //0x11C
  uint8_t mPad11D[3];              //0x11D — unproven padding
  uint64_t mU120;                  //0x120
  uint64_t mU128;                  //0x128 — ctor zero (stp 0x128/0x130)
  uint64_t mU130;                  //0x130
  uint8_t mPad138[4];              //0x138 — unproven padding
  float mF13C[3];                  //0x13C..0x147 — ctor/reset set all to 1.0f
  uint64_t mU148;                  //0x148
  uint64_t mU150;                  //0x150 — ctor zero (stp 0x150/0x158)
  uint64_t mU158;                  //0x158
};
}  // namespace object
