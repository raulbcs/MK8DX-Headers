#pragma once

#include <cstdint>

// Vt12d9c20 — PLACEHOLDER name (nn::pia-region 8-byte interface object,
// constant-getter vtable); installed vptr 0x12d9c28 (table row 0x12d9c20 is
// the typeinfo slot).
// extent 0x8 - details: doc/object/Vt12d9c20.md

namespace object {
class Vt12d9c20 {
 public:
  void* vtable;  // 0x00 — 0x12d9c28 (ctor 0x7100931380, factory slot 11
                 // 0x7100931458 allocates 8 bytes)
};
}  // namespace object
