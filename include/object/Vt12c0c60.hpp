#pragma once

#include <cstdint>

// Vt12c0c60 - PLACEHOLDER name (refcount/list-node class from the 0x742xxx factory region);
// 28-slot vtable, single vptr +0x00. Base ctor 0x5aa46c, class C1 0x749b24.
// extent 0x68 - details: doc/object/Vt12c0c60.md

namespace object {
class Vt12c0c60 {
 public:
  void* vtable;            // 0x00 - 0x12c0c60 (GOT cell 0x130ee70 + 0x10)
  void* m08;               // 0x08 - self node ptr (= this+0x08)
  void* m10;               // 0x10 - list head (= this+0x08 after base C1)
  void* m18;               // 0x18 - zeroed by base C1
  uint32_t m20;            // 0x20 - zeroed by base C1
  uint8_t m24;             // 0x24 - = 1 by base C1
  uint8_t mPad25[0x3];     // 0x25 - 0x28 padding
  uint8_t m28[0x10];       // 0x28 - zeroed by base C1 (stp xzr,xzr)
  uint32_t m38;            // 0x38 - zeroed by base C1
  uint8_t mPad3c[0x4];     // 0x3c - 0x40 padding
  void* m40;               // 0x40 - intrusive list head (= this+0x40)
  void* m48;               // 0x48 - intrusive list tail (= this+0x40)
  uint32_t m50;            // 0x50 - zeroed by C1
  uint16_t m54;            // 0x54 - zeroed by C1
  uint16_t m56;            // 0x56 - = 0x2000 by C1
  uint8_t m58[0x10];       // 0x58 - zeroed by C1 (stp xzr,xzr)
};
}  // namespace object
