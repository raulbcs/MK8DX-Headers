#pragma once

#include <cstdint>

// Vt12cf618 - PLACEHOLDER name (theme unproven); vptr 0x12cf618, 54 slots.
// Ctor 0x8622f8, factory new(0x638) at 0x383784; sibling of Vt12ce230.
// extent 0x638 - details: doc/object/Vt12cf618.md

namespace object {
class Vt12cf618 {
 public:
  void* vtable;               // 0x00 - 0x12cf618
  std::uint8_t pad08[0x5a8];  // 0x08 - interior layout unproven
  std::uint64_t f5b0;         // 0x5b0 - zeroed by ctor 0x86233c
  std::uint64_t f5b8;         // 0x5b8 - zeroed by ctor 0x862338
  std::uint64_t f5c0;         // 0x5c0 - zeroed by ctor 0x86232c
  std::uint64_t f5c8;         // 0x5c8 - zeroed by ctor 0x862328
  std::uint8_t pad5d0[0x60];  // 0x5d0 - ctor writes nothing here (unproven)
  std::uint16_t f630;         // 0x630 - 0 (ctor 0x86231c; reset 0x86238c)
  std::uint8_t pad632[0x6];   // 0x632 - gap
};
}  // namespace object
