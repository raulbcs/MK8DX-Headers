#pragma once

#include <cstdint>

// Vt12d7d78 — PLACEHOLDER name; vptr 0x12d7d78 (GOT cell 0x13123d0 = vptr-0x10),
// >=24 slots, no RTTI. Embeds four 0x88-byte elements of the Vt12d7ec8 family.
// extent 0x278 - details: doc/object/Vt12d7d78.md

namespace object {
class Vt12d7d78 {
 public:
  void* mVtable;            // 0x00 — 0x12d7d78
  uint8_t mPad8[0x18];      // 0x08/0x09/0x0a — bytes init'd by C1
  uint32_t m20;             // 0x20 — C1 arg (w8, 0x910648)
  uint8_t mPad24[0x4];      // 0x24 — unproven padding
  void* mElement0;          // 0x28 — element vptr 0x12d7ec8; stride 0x88
  uint8_t mElement0Data[0x80];  // 0x30 — memset 0x51 @ +0x4c, filler 0xff @ +0xa8, count 0x50 @ +0x38
  void* mElement1;          // 0xb0
  uint8_t mElement1Data[0x80];  // 0xb8 — element fields
  void* mElement2;          // 0x138
  uint8_t mElement2Data[0x80];  // 0x140 — element fields
  void* mElement3;          // 0x1c0
  uint8_t mElement3Data[0x80];  // 0x1c8 — element fields
  uint8_t mPad248[0x20];    // 0x248 — zeroed tail (0x248..0x268)
  void* m268;               // 0x268 — zeroed by C1 (0x910640)
  void* m270;               // 0x270 — zeroed by C1 (0x91061c)
};
}  // namespace object
