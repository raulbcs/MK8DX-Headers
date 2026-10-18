#pragma once

#include <cstdint>

// Vt12d8000 — PLACEHOLDER name; vptr 0x12d8000 (GOT cell 0x1312498 = vptr-0x10),
// >=31 slots, no RTTI. Large aggregate: four Vt12d7ec8-family elements then
// owned children (deepest member at +0xf38, each >=0xe0).
// extent 0x1020 (unverified round-up; proven lower bound 0x1018) - details: doc/object/Vt12d8000.md

namespace object {
class Vt12d8000 {
 public:
  void* mVtable;            // 0x00 — 0x12d8000
  uint8_t mPad8[0x8];       // 0x08/0x09 — bytes init'd by C1
  void* m10;                // 0x10 — zeroed
  void* m18;                // 0x18 — child ptr (new 0x68, ctor 0x923080)
  void* m38;                // 0x38 — child ptr (new 0x5da8, ctor 0x912cc0)
  uint8_t mPad20[0x18];     // 0x20/0x28 — zeroed
  uint32_t m40;             // 0x40 — C1 arg w0
  uint16_t m44;             // 0x44 — C1 arg h (ldr [x20,#4])
  uint16_t mPad46;          // 0x46 — unproven padding
  void* mElement0;          // 0x48 — element vptr 0x12d7ec8; stride 0x88
  uint8_t mElement0Data[0x80];  // 0x50 — memset 0x51 @ +0x64, filler 0xff @ +0xb8, count 0x50 @ +0x7c
  void* mElement1;          // 0xd0
  uint8_t mElement1Data[0x80];  // 0xd8 — element fields
  void* mElement2;          // 0x158
  uint8_t mElement2Data[0x80];  // 0x160 — element fields
  void* mElement3;          // 0x1e0
  uint8_t mElement3Data[0x80];  // 0x1e8 — element fields
  void* m268;               // 0x268 — owned child (new 0x5da8, ctor 0x912cc0)
  uint8_t mPad270[0x34];    // 0x270 — zeroed by C1 (0x270..0x2a4)
  uint8_t mPad2a4[0x1];     // 0x2a4 — embedded obj (ctor 0x931380)
  uint8_t mPad2a5[0xd7b];   // 0x2a5 — embedded objs at +0x2b8/+0x8e8 (0x935408) and +0xf38 (0x922af4)
};
}  // namespace object
