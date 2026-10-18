#pragma once

#include <cstdint>

namespace object {
// Vt12b0808 - PLACEHOLDER name; fixed-capacity write buffer secondary base
// (owner+0x20). Slots are clamped memcpy write / write / seek over
// [+0x08] buffer with cap [+0x10] and pos [+0x14]. No RTTI.
// extent 0x18 (lower bound; ctor stores) - details: doc/object/Vt12b0808.md
class Vt12b0808 {
 public:
  void* vtable;  // 0x00 - 0x12b0808 (GOT cell 0x130d3f0 holds vt-0x10)
  void* m08;     // 0x08 - buffer pointer (param1)
  uint32_t m10;  // 0x10 - capacity (param2 / w2)
  uint32_t m14;  // 0x14 - write position, ctor 0
};
}  // namespace object
