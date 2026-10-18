#pragma once

#include <cstdint>

namespace game {
// Unnamed class; derived from Vt12c7cc0 family (root ctor 0x6155bc, base
// init 0x7d34d8). Init 0x7d3184 stores center/scale params and computes a
// min/max box pair from global 0x12fb150 defaults.
// extent 0xf8 (operator-new 0xf8 at 0x139cbc / 0x8050e4) -
// details: doc/game/Vt12c7c70.md
class Vt12c7c70 {
 public:
  void* vtable;         // 0x00 - vptr 0x12c7c70 (GOT cell 0x130ffe8 holds
                        // 0x12c7c60 = vptr-0x10); root ctor 0x6155bc first
                        // installs 0x12b0058, base 0x7d34d8 installs
                        // 0x12c7cc0 (cell 0x130fff0)
  uint8_t mPad8[0x18];  // 0x08 - root region (0x8 registry node, 0x10..0x18
                        // zeroed by 0x6155bc); unproven split
  uint32_t mState20;    // 0x20 - base init 0; derived init writes 2
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
                        // granularity); 0x8c/0x94/0x9c/0xa4 read by slots
  float mParamAc;       // 0xac - param v0 (s9) copied from init arg
  float mParamB0;       // 0xb0 - param v1 (s8) copied from init arg
  uint8_t mPadB4[0x8];  // 0xb4 - [x1] 8 bytes (unproven split)
  float mFieldBc;       // 0xbc - [x1+0x8]
  float mScaleC0;       // 0xc0 - init stores param s9; getter 0x7d34c8
                        // reads [this+0xc0]
  float mFieldC4;       // 0xc4 - param v1 (s8)
  uint8_t mPadC8[0x8];  // 0xc8 - unproven (stur [x1], 8 bytes)
  float mFieldD0;       // 0xd0 - [x1+0x8]
  uint8_t mPadD4[0xc];  // 0xd4 - unproven (stur [x1], 8 bytes at 0xd4;
                        // getter 0x7d34d0 returns this+0xd4)
  float mBoxMaxE0;      // 0xe0 - global[0] * param + arg.x
  float mBoxMaxE4;      // 0xe4 - global[1] * param + arg.y
  float mBoxMaxE8;      // 0xe8 - global[2] * param + arg.z
  float mBoxMinEc;      // 0xec - global[0] * param - arg.x
  float mBoxMinF0;      // 0xf0 - global[1] * param - arg.y
  float mBoxMinF4;      // 0xf4 - global[2] * param - arg.z
};
}  // namespace game
