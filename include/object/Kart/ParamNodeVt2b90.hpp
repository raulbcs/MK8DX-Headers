#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt2b90 — address-anchored name (vptr 0x12b2b90, GOT cell
class ParamNodeVt2b90 {
 public:
  void* vtable;  // 0x00
  // (own fields unmapped; secondary-base offset-to-top -0x30 at vt+0xb8)
};
}  // namespace object
