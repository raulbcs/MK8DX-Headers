#pragma once

#include <cstdint>

// Vt12be590 - PLACEHOLDER name (theme unproven); vptr 0x12be590, 67 slots.
// Base ctor 0x734414, D1 (slot 0) 0x7344d0; derived class overrides vptr.
// extent 0xe8 - details: doc/object/Vt12be590.md

namespace object {
class Vt12be590 {
 public:
  void* vtable;              // 0x00 - 0x12be590
  std::uint8_t pad08[0x18];  // 0x08 - ctor writes nothing here (unproven)
  std::uint64_t f20[2];      // 0x20 - zeroed by ctor 0x734434
  std::uint64_t f30;         // 0x30 - zeroed by ctor 0x734468
  void* f38;                 // 0x38 - this+0x38 (ctor 0x734450)
  void* f40;                 // 0x40 - this+0x38 (ctor 0x73446c)
  void* f48;                 // 0x48 - this+0x48 (ctor 0x734454)
  void* f50;                 // 0x50 - this+0x48 (ctor 0x734474)
  std::uint64_t f58;         // 0x58 - zeroed by ctor 0x734474
  std::uint64_t f60[2];      // 0x60 - zeroed by ctor 0x73443c
  void* f70[2];              // 0x70 - list head, self-init (ctor 0x734448)
  void* f80[2];              // 0x80 - list head, self-init (ctor 0x734458)
  std::uint32_t f90;         // 0x90 - 0 (ctor 0x7344bc)
  std::uint32_t f94;         // 0x94 - 8 (ctor 0x7344b8)
  std::uint32_t f98;         // 0x98 - 0 (ctor 0x734430)
  std::uint32_t pad9c;       // 0x9c - gap
  std::int32_t fa0;          // 0xa0 - -1 (ctor 0x734460); -1 skips slot-0 free
  void* vptrA8;              // 0xa8 - secondary base vt 0x11ad210 (ctor 0x734490)
  void* vptrB0;              // 0xb0 - secondary base vt 0xf57d40 (ctor 0x734490)
  std::uint64_t fb8[4];      // 0xb8 - zeroed by ctor 0x73448c/0x7344c0
  float fd8;                 // 0xd8 - 0x3f490fdb (ctor 0x734494)
  std::uint8_t fdc;          // 0xdc - 0xff (ctor 0x7344a0)
  std::uint8_t pddd[0x8];    // 0xdd - zeroed by ctor 0x734488 (unproven)
  std::uint8_t fe5;          // 0xe5 - 0 (ctor 0x734484)
  std::uint8_t fe6;          // 0xe6 - 1 (ctor 0x7344ac)
  std::uint8_t fe7;          // 0xe7 - 3 (ctor 0x7344b0)
};
}  // namespace object
