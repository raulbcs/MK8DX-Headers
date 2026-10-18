#pragma once

#include <cstdint>

// Vt12f6ff0 - PLACEHOLDER name; 0x2a8-byte aggregate built only through
// factory FUN_7100b193c8 (new 0x2a8), Vt12f6f68 vtable family.
// extent 0x2a8 - details: doc/object/Vt12f6ff0.md

namespace object {
class Vt12f6ff0 {
 public:
  void* vtable;           // 0x00 - 0x12f6ff8 (GOT cell 0x1315948 holds
                          // 0x12f6fe8 = vt-0x10)
  char mPad08[0x1b0];     // 0x08..0x1b7 - zeroed 0xa0..0xf0, subtree at
                          // +0xf8 (FUN_7100a2bf88); unproven
  void* mSecondary1b8;    // 0x1b8 - secondary vptr Vt12f7dc8 (cell
                          // 0x1315950)
  char mPad1c0[0x48];     // 0x1c0..0x207 - unproven
  void* mSecondary208;    // 0x208 - sead secondary vptr 0x128c698 (cell
                          // 0x130b4a8)
  char mPad210[0x18];     // 0x210..0x227 - self-pointer pair (+0x220)
  void* mSecondary228;    // 0x228 - secondary vptr Vt12f7e48 (cell
                          // 0x1315958)
  char mPad230[0x78];     // 0x230..0x2a7 - unproven
};
}  // namespace object
