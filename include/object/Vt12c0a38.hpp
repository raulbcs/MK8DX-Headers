#pragma once

#include <cstdint>

namespace object {
// Vt12c0a38 - PLACEHOLDER name; keyed-entry registry base (intrusive list of
// Vt12c0a78 nodes, create + find-by-key virtuals, guarded-global pair).
// No RTTI. Base subobject of the 0x180 composite from factory 0x8ca25c.
// extent 0x58 - details: doc/object/Vt12c0a38.md
class Vt12c0a38 {
 public:
  void* mVtable;     // 0x00 - 0x12c0a38 (GOT cell 0x130edf8 holds vt-0x10)
  uint8_t m8[0x20];  // 0x08 - 0x27 - no C1 stores; derived composite
                     //        installs a secondary vptr at +0x8 (GOT cell
                     //        0x130de8) before this C1 runs (0x8ca2b8)
  void* mListHead;   // 0x28 - intrusive list head, init to this+0x28
                     //        (C1 0x747598 stp x10, x10)
  void* mListTail;   // 0x30 - list tail, init to this+0x28
  uint32_t m38;      // 0x38 - entry count, ctor 0 (0x747588)
  uint32_t m3C;      // 0x3c - entry node offset, ctor 0x20 (0x7475a0)
  uint32_t m40;      // 0x40 - ctor 0 (0x7475a8 stp w8, wzr low)
  uint32_t m44;      // 0x44 - ctor 0 (same stp high)
  void* m48;         // 0x48 - ctor 0 (0x747584); unused by this C1
  uint8_t m50;       // 0x50 - ctor 1 (0x7475a4)
  uint8_t m51[0x7];  // 0x51 - 0x57 - no ctor stores (unproven padding)
};
}  // namespace object
