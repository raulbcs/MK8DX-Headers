#pragma once

#include <cstdint>

// Vt12dfb80 — PLACEHOLDER name (nn::pia-region 8-byte interface object,
// constant-getter vtable, 1500/1500 getters); installed vptr 0x12dfb88.
// extent 0x8 - details: doc/object/Vt12dfb80.md

namespace object {
class Vt12dfb80 {
 public:
  void* vtable;  // 0x00 — 0x12dfb88 (ctor 0x71009be110, factory slot 11
                 // 0x71009be1a0 allocates 8 bytes)
};
}  // namespace object
