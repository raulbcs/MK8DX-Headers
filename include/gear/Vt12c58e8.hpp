#pragma once

#include <cstdint>

namespace gear {
// Vt12c58e8 — PLACEHOLDER name; engine-family member subobject (base ctor
// 0x7b976c). vptr 0x12c58e8 (GOT cell 0x130fed0 holds vt-0x10); 18 slots,
// gear::Actor-derived (slot2 = gear::Actor::~Actor, slots 12/13 =
// Actor::prepareOuter/enterOuter). Constructed in place; extent is a lower
// bound. extent 0xb0 (unverified lower bound) - details: doc/gear/Vt12c58e8.md
class Vt12c58e8 {
 public:
  void* vtable;           // 0x00 — 0x12c58e8 (cell 0x130fed0 + 0x10)
  uint8_t mBase08[0x30];  // 0x08 — engine-family base region, zero-init 32B by
                          //   base ctor 0x7b976c; unproven
  uint8_t mPad38[8];      // 0x38 — ctor 0x7c0b3c zeroes
  void* mPtr40;           // 0x40 — ctor stores its x1 argument
  void* mPtr48;           // 0x48 — result of virtual call [arg vptr + 0x148]
  uint8_t mPad50[0x30];   // 0x50 — unproven gap
  uint32_t mField80;      // 0x80 — from global [cell 0x12fbc10]
  double mD84;            // 0x84 — ctor sets 1.0
  uint32_t mF8c;          // 0x8c — from global [cell 0x12fb178]
  uint8_t mPad90[4];      // 0x90 — unproven gap
  uint32_t mF94;          // 0x94 — [cell 0x12fb178 + 8]
  uint32_t mF98;          // 0x98 — ctor zeroes
  uint32_t mF9c;          // 0x9c — [cell 0x12fb148]
  uint32_t mFa0;          // 0xa0 — [cell 0x12fb148 + 8]
  uint8_t mPa4[4];        // 0xa4 — unproven gap
  uint16_t mFa8;          // 0xa8 — ctor zeroes
  uint8_t mPaa[2];        // 0xaa — unproven gap
  uint32_t mFac;          // 0xac — ctor sets -1
};
}  // namespace gear
