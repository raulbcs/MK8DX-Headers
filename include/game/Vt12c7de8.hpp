#pragma once

#include <cstdint>

namespace game {
// Unnamed class; sibling of Vt12c7c70 in the Vt12c7cc0 family (root ctor
// 0x6155bc, base init 0x7d34d8). Init 0x7d5164 copies a param struct and
// global 0x12fb148 values; byte flag at +0xe4.
// extent 0xe8 (operator-new 0xe8 at 0x804e20) -
// details: doc/game/Vt12c7de8.md
class Vt12c7de8 {
 public:
  void* vtable;         // 0x00 - vptr 0x12c7de8 (GOT cell 0x1310018 holds
                        // 0x12c7dd8 = vptr-0x10); root ctor 0x6155bc first
                        // installs 0x12b0058, base 0x7d34d8 installs
                        // 0x12c7cc0 (cell 0x130fff0)
  uint8_t mPad8[0x18];  // 0x08 - root region (0x8 registry node, 0x10..0x18
                        // zeroed by 0x6155bc); unproven split
  uint32_t mState20;    // 0x20 - base init 0; derived init writes 1
  uint8_t mPad24[0x4];  // 0x24 - unproven
  float mField28;       // 0x28 - base init 0.0f
  float mField2c;       // 0x2c - base init 30.0f (0x41f00000)
  uint8_t mPad30[0x8];  // 0x30 - unproven
  void* mField38;       // 0x38 - 0x7f7ac0() scene lookup result
  uint32_t mField40;    // 0x40 - [x8+0x0] of 0x7f7ac0 base
  uint32_t mField44;    // 0x44 - [x8+0x4]
  uint32_t mField48;    // 0x48 - [x8+0x8]
  uint32_t mField4c;    // 0x4c - 0
  uint32_t mField50;    // 0x50 - global 0x12fb148+0x0
  uint32_t mField54;    // 0x54 - global 0x12fb148+0x4
  uint32_t mField58;    // 0x58 - global 0x12fb148+0x8
  uint8_t mPad5c[0x8];  // 0x5c - unproven (stur x8, 8 bytes)
  uint32_t mField64;    // 0x64 - global 0x12fb148+0x8
  uint8_t mField68;     // 0x68 - 0
  uint8_t mPad69[0x43]; // 0x69 - zeroed 0x6c..0xac by base init (unproven
                        // granularity)
  float mParamAc;       // 0xac - param s8 copied from init arg
  uint8_t mPadB0[0x8];  // 0xb0 - [x1] 8 bytes (unproven split)
  uint8_t mPadB8[0x4];  // 0xb8 - [x1+0x8] (u32)
  float mParamBc;       // 0xbc - param s8 copied again
  uint8_t mPadC0[0x8];  // 0xc0 - [x1] 8 bytes (unproven split)
  uint32_t mFieldC8;    // 0xc8 - [x1+0x8]
  uint8_t mPadCc[0x4];  // 0xcc - global 0x12fb148+0x0 (getters
                        // 0x7d513c/0x7d514c read +0xcc)
  float mFieldD0;       // 0xd0 - getter 0x7d5144 reads
  uint8_t mPadD4[0x4];  // 0xd4 - global 0x12fb148+0x8
  uint8_t mPadD8[0x8];  // 0xd8 - global 0x12fb148+0x0 8 bytes
  uint32_t mFieldE0;    // 0xe0 - global 0x12fb148+0x8
  uint8_t mFlagE4;      // 0xe4 - 0
  uint8_t mPadE5[0x3];  // 0xe5 - padding to 0xe8
};
}  // namespace game
