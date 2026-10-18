#pragma once

#include <cstdint>

// Vt12ca0b0 — PLACEHOLDER name; heap-allocated worker/list node of the
// named-subsystem engine family (Vt12c9268): allocated 0x88, chained at
// engine +0x240, derives from Vt12c93a8; two secondary interface vptrs.
// extent 0x88 (proven alloc) - details: doc/object/Vt12ca0b0.md

namespace object {
class Vt12ca0b0 {
 public:
  void* vtable;          // 0x00 — 0x12ca0b0 (cell 0x1310408 + 0x10)
  uint8_t mPad08[0x30];  // 0x08 — Vt12c93a8 base region
  uint32_t mField38;     // 0x38 — ctor zero
  uint8_t mPad3c[0x4];   // 0x3c — unproven padding
  void* mField40;        // 0x40 — ctor zero
  void* mField48;        // 0x48 — ctor zero
  void* mVptr50;         // 0x50 — secondary vptr 0x12ca188 (cell 0x1310410)
  void* mField58;        // 0x58 — static 0x11ad210 (cell 0x12fae28 + 0x10)
  void* mField60;        // 0x60 — rodata float table 0xed6af8
  void* mVptr68;         // 0x68 — secondary vptr 0x12ca1a0 (cell 0x1310420)
  void* mField70;        // 0x70 — self pointer (this)
  void* mField78;        // 0x78 — cell 0x1310418 + 0x10 = 0x7fa08c (unverified)
  void* mField80;        // 0x80 — ctor zero
                           // (+0x88 = proven alloc size)
};
}  // namespace object
