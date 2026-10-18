#pragma once

#include <cstdint>

// Vt12c2a40 - PLACEHOLDER name (sibling of Vt12c17a0, shared base C1 0x75b1e4, factory
// 0x78af2c); 28-slot vtable, vptr +0x00, secondary subtable vptr +0x50 (0x12c2b30).
// extent 0x170 - details: doc/object/Vt12c2a40.md

namespace object {
class Vt12c2a40 {
 public:
  void* vtable;            // 0x00 - 0x12c2a40 (GOT cell 0x130f5b0 + 0x10)
  uint8_t mBase08[0x8];    // 0x08 - unverified
  void* m10;               // 0x10 - rodata ptr (float table at 0xed6xxx), by base C1
  uint8_t mPad18[0x8];     // 0x18 - base C1 stores via pre-indexed writeback; unverified
  void* m20;               // 0x20 - rodata ptr (same 0xed6xxx table), by base C1
  uint32_t m28;            // 0x28 - u32 from base C1
  uint8_t mPad2c[0x24];    // 0x2c - 0x50 padding; unverified
  void* vtable2;           // 0x50 - 0x12c2b30 (GOT cell 0x130f5b0 + 0x100); offset-to-top -80
  uint8_t mPad58[0x20];    // 0x58 - 0x78; unverified
  void* m78;               // 0x78 - self pointer (= this), by base C1
  uint8_t m80;             // 0x80 - byte, zeroed by base C1
  uint8_t mPad81[0xa7];    // 0x81 - 0x128; unverified
  uint32_t m128;           // 0x128 - u32 from helper 0x74cdec
  uint32_t m12c;           // 0x12c - zeroed by base C1
  uint32_t m130;           // 0x130 - u32 from helper 0x74cdec
  uint32_t m134;           // 0x134 - zeroed by base C1
  uint8_t m138;            // 0x138 - byte from helper 0x74cdec
  uint8_t mPad139[0x7];    // 0x139 - 0x140 padding
  uint8_t m140[0x18];      // 0x140 - zeroed by base C1 (0x140 u64 + 0x148..0x157 unverified)
  uint32_t m158;           // 0x158 - zeroed by base C1
  uint8_t mPad15c[0x14];   // 0x15c - 0x170 padding
};
}  // namespace object
