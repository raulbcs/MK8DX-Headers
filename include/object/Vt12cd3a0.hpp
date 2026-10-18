#pragma once

#include <cstdint>

// Vt12cd3a0 - PLACEHOLDER name (theme unproven); vptr 0x12cd3a0, 71 slots.
// Ctor 0x846534, factory new(0x158) at 0x83f598; secondary vptr at 0x90.
// extent 0x158 - details: doc/object/Vt12cd3a0.md

namespace object {
class Vt12cd3a0 {
 public:
  void* vtable;              // 0x00 - 0x12cd3a0
  std::uint8_t pad08[0x68];  // 0x08 - ctor writes nothing here (unproven)
  std::uint64_t f70;         // 0x70 - zeroed by ctor 0x846578
  std::uint64_t f78;         // 0x78 - zeroed by ctor 0x846588
  void* f80;                 // 0x80 - zeroed by ctor 0x84657c
  std::uint64_t f88;         // 0x88 - zeroed by ctor 0x84657c
  void* vptr90;              // 0x90 - secondary base vt 0x12cd650 (ctor 0x846594)
  std::uint64_t f98;         // 0x98 - zeroed by ctor 0x846584
  std::uint64_t fa0;         // 0xa0 - zeroed by ctor 0x846590
  std::uint64_t fa8;         // 0xa8 - zeroed by ctor 0x846590
  std::uint8_t padb0[0xa8];  // 0xb0 - list/array built by ctor 0x846598-0x8465bc (unproven)
};
}  // namespace object
