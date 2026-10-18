#pragma once

#include <cstdint>

// Vt12f6a10 — PLACEHOLDER name; ASSIGNED ADDR IS THE RTTI SLOT. Real vptr row
// 0x12f6a18 (n=6); typeinfo 0x12f7240 is a __vmi_class_type_info (MI root).
// extent 0x90 - lower bound (dtor frees +0x88); unverified -
// details: doc/object/Vt12f6a10.md

namespace object {
class Vt12f6a10 {
 public:
  void* mVtable;            // 0x00 — 0x12f6a18 (via GOT cell 0x1315B20)
  uint8_t mPad8[0x60];      // 0x08 — unproven padding
  void* mPtr68;             // 0x68 — pointer pair checked/freed by D0 (with +0x70)
  void* mPad70;             // 0x70 — pair partner
  uint8_t mPad78[0x8];      // 0x78 — unproven padding
  void* mPtr80;             // 0x80 — pointer pair checked/freed by D0 (with +0x88)
  void* mPad88;             // 0x88 — pair partner
};
}  // namespace object
