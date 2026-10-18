#pragma once

#include <cstdint>

namespace object {
// Vt12b05a0 - PLACEHOLDER name; SSO-style string/token buffer (0x78 bytes),
// constructed inline inside FUN_7100623af8 (alloc 0x7100623b4c). Secondary
// vptr at +0x40 (cell 0x12fada0). No RTTI (null typeinfo slot).
// extent 0x78 - details: doc/object/Vt12b05a0.md
class Vt12b05a0 {
 public:
  void* vtable;       // 0x00 - 0x12b05a0 (GOT cell 0x130d3a0 holds vt-0x10)
  char pad08[0x18];   // 0x08..0x1f - unproven (not touched by the observed init)
  void* m20;          // 0x20 - ctor 0
  void* m28;          // 0x28 - ctor 0
  void* m30Self;      // 0x30 - self pointee (this+0x30)
  void* m38;          // 0x38 - ctor 0
  void* mVtable2;     // 0x40 - 0x11ad0f8 (GOT cell 0x12fada0; secondary base)
  char* mBuffer48;    // 0x48 - points to this+0x54 (SSO buffer)
  uint32_t mCap50;    // 0x50 - ctor 0x20 (buffer capacity)
  char mBuf54[0x20];  // 0x54..0x73 - inline buffer; fill byte read from
                      //   [GOT cell 0x12fada8]
  char pad74[0x4];    // 0x74..0x77 - unproven gap
};
}  // namespace object
