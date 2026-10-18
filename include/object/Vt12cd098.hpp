#pragma once

#include <cstdint>

// Vt12cd098 - PLACEHOLDER name (theme unproven); vptr 0x12cd098, 71 slots.
// Ctor 0x845340, factory new(0xb0) at 0x83f5a4; secondary vptr at 0x90.
// extent 0xb0 - details: doc/object/Vt12cd098.md

namespace object {
class Vt12cd098 {
 public:
  void* vtable;              // 0x00 - 0x12cd098
  std::uint8_t pad08[0x68];  // 0x08 - ctor writes nothing here (unproven)
  std::uint64_t f70;         // 0x70 - zeroed by ctor 0x845384
  std::uint64_t f78;         // 0x78 - zeroed by ctor 0x845394
  void* f80;                 // 0x80 - buffer from 0x60b3fc (ctor 0x8453c8)
  std::uint64_t f88;         // 0x88 - zeroed by ctor 0x845388
  void* vptr90;              // 0x90 - secondary base vt 0x12cd360 (ctor 0x8453a4)
  std::uint64_t f98;         // 0x98 - zeroed by ctor 0x845398
  std::uint64_t fa0;         // 0xa0 - zeroed by ctor 0x84539c
  std::uint64_t fa8;         // 0xa8 - zeroed by ctor 0x84539c
};
}  // namespace object
