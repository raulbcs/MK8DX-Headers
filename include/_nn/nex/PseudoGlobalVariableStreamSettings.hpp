#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12e4f70:
// nn::nex::PseudoGlobalVariable<nn::nex::StreamSettings>). Large
// settings-profile entry with three embedded sub-interface vptrs and
// default constants (10000/1000/1.25/50/750/2000/250); C1 FUN_71009f7068
// runs 8x in a loop from global-table init.
// size >= 0x210 - details: doc/_nn/nex/PseudoGlobalVariableStreamSettings.md
class PseudoGlobalVariableStreamSettings {
 public:
  void* vtable;           // 0x00 - vptr 0x12e4f28 (GOT cell 0x13145b0 holds
                          // 0x12e4f18 = vptr-0x10; typeinfo slot 0x12e4f20)
  char mPad08[0x8];       // 0x08..0x0f - unproven
  void* mIface18;         // 0x18 - vptr cell 0x13145b8 +0x10 (vt 0x12e3458)
  char mPad20[0x28];      // 0x20..0x47 - unproven
  void* mIface50;         // 0x50 - vptr cell 0x13145c0 +0x10 (vt 0x12e3438)
  uint8_t mFlag58;        // 0x58 - set to 0 by C1
  uint32_t mField5c;      // 0x5c - set to 0 by C1
  uint64_t mField60;      // 0x60 - 0
  int64_t mSized68;       // 0x68 - -1
  int64_t mSized70;       // 0x70 - -1
  char mPad78[0xc0];      // 0x78..0x137 - unproven (subobject ctor/dtor
                          // 0x574a70/0x576340 at 0x78)
  char mPad138[0x28];     // 0x138..0x15f - unproven (subobject at 0x168)
  int32_t mS158;          // 0x158 - -1
  char mPad15c[0x4];      // 0x15c..0x15f - unproven
  void* mIface160;        // 0x160 - vptr cell 0x13145b8 +0x10
  char mPad168[0x30];     // 0x168..0x197 - unproven (subobject 0x574a70)
  void* mIface198;        // 0x198 - vptr cell 0x13145c0 +0x10
  char mPad1a0[0x8];      // 0x1a0..0x1a7 - unproven
  int64_t mS1a8;          // 0x1a8 - 0 / -1
  char mPad1b0[0x10];     // 0x1b0..0x1bf - unproven
  char mPad1c0[0x48];     // 0x1c0..0x207 - unproven (subobject 0x574a70)
  uint32_t mField208;     // 0x208 - C1 writes 20
};
}  // namespace nn::nex
