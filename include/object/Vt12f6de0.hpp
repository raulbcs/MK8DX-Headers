#pragma once

#include <cstdint>

// Vt12f6de0 - PLACEHOLDER name; 0x378-byte aggregate built only through
// factory FUN_7100b18c9c (new 0x378), vtable family shared with Vt12f6f68.
// extent 0x378 - details: doc/object/Vt12f6de0.md

namespace object {
class Vt12f6de0 {
 public:
  void* vtable;           // 0x00 - 0x12f6de8 (GOT cell 0x1315938 holds
                          // 0x12f6dd8 = vt-0x10)
  char mPad08[0x1b0];     // 0x08..0x1b7 - unproven
  void* mMember1b8;       // 0x1b8 - embedded member, ctor FUN_7100b29b10
                          // (668 B)
  char mPad1c0[0x108];    // 0x1c0..0x2c7 - unproven
  void* mSecondary2c8;    // 0x2c8 - secondary vptr Vt12f7ac8 (cell 0x1315940)
  char mPad2d0[0x8];      // 0x2d0..0x2d7 - unproven
  void* mSecondary2d8;    // 0x2d8 - sead secondary vptr 0x128c698 (cell
                          // 0x130b4a8)
  char mPad2e0[0x98];     // 0x2e0..0x377 - member init at +0x358 via
                          // FUN_7100578900; unproven
};
}  // namespace object
