#pragma once

#include <cstdint>

// Unnamed 6-slot game class (no RTTI; placeholder Vt12f2c60). Float param
// block + embedded component at +0x78; base subobject of a larger class.
// size 0xf0 lower bound - details: doc/object/Vt12f2c60.md

namespace object {

class Vt12f2c60 {
 public:
  void* vtable;        // 0x00 - installed 0x12f2c60 (GOT cell 0x13151f8
                       //        holds 0x12f2c50 = vptr-0x10; typeinfo slot
                       //        0x12f2c58 = 0, no RTTI)
  uint32_t mFlag08;    // 0x08 - zeroed by ctor, then |= 1
  char mPad0C[0x30];   // 0x0c..0x3b - unproven
  float mF03C[6];      // 0x3c - 1.0f x6 by ctor
  float mF054;         // 0x54 - 1.0f
  float mF058;         // 0x58 - 0.0f
  char mPad5C[0x4];    // 0x5c..0x5f - unproven
  float mF060;         // 0x60 - 0.0f
  float mF064;         // 0x64 - 0.1f (0x3dcc0000)
  float mF068;         // 0x68 - 100.0f (0x42c80000)
  float mF06C;         // 0x6c - 1.0f
  char mPad70[0x8];    // 0x70..0x77 - unproven
  char mComp78[0x3c];  // 0x78 - embedded component (ctor 0x645934, D2
                       //        0x645970, D0 0x645984, 60 B ctor)
  char mPadB4[0x3c];   // 0xb4..0xef - unproven (base boundary at 0xf0:
                       //        derived ctor installs next vptr at +0xf0)
};

}  // namespace object
