#pragma once

#include <cstdint>

// Vt12f6e60 - PLACEHOLDER name; 0x3a8-byte aggregate, in-place C1
// FUN_7100b2acdc called from factory FUN_7100b18a2c (new 0x3a8).
// extent 0x3a8 - details: doc/object/Vt12f6e60.md

namespace object {
class Vt12f6e60 {
 public:
  void* vtable;           // 0x00 - 0x12f6e68 (GOT cell 0x1315c50 holds
                          // 0x12f6e58 = vt-0x10)
  char mPad08[0x1b0];     // 0x08..0x1b7 - zeroed 0xa0..0xf0, subtree at
                          // +0xf8 (FUN_7100a2bf88); unproven
  void* mSecondary1b8;    // 0x1b8 - secondary vptr Vt12cc438 (cell
                          // 0x1310978)
  char mPad1c0[0x8];      // 0x1c0..0x1c7 - unproven
  void* mSecondary1c8;    // 0x1c8 - sead secondary vptr 0x128c698 (cell
                          // 0x130b4a8)
  char mPad1d0[0x60];     // 0x1d0..0x22f - vector-ish +0x1e0/+0x1f8,
                          // subtree +0x240 region; unproven
  void* mSecondary230;    // 0x230 - secondary vptr Vt12cc4f8 (cell
                          // 0x1310980)
  char mPad238[0x20];     // 0x238..0x257 - unproven
  void* mSecondary258;    // 0x258 - duplicate Vt12cc4f8 vptr
  char mPad260[0x148];    // 0x260..0x3a7 - subtrees +0x268, +0x290..+0x2a8
                          // zeroed; unproven
};
}  // namespace object
