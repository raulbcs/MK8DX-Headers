#pragma once

#include <cstdint>

namespace object {
// Vt12b6780 — PLACEHOLDER name; large game-side manager, no RTTI. vptr
// 0x12b6780 (GOT cell 0x130e048 holds vt-0x10), secondary vptr 0x12b6820 at
// +0x368 (cell 0x130e050); 18 slots. size 0x388 proven (new 0x388 at 0x6da608).
// extent 0x388 - details: doc/object/Vt12b6780.md
class Vt12b6780 {
 public:
  void* vtable;       // 0x00 — 0x12b6780 (cell 0x130e048 + 0x10)
  uint32_t mField08;  // 0x08 — ctor 0x6b1e14 zeroes
  uint8_t mByte0c;    // 0x0c — ctor zeroes; compared by slot2 (0x6b2834)
                      //   against caller state
  uint8_t mByte0d;    // 0x0d — ctor sets 0xff; bitfield bits 2-3 read by
                      //   slot2 (0x6b2834) against caller state
  uint8_t mPad0e[2];  // 0x0e — unproven gap
  uint32_t mCount10;  // 0x10 — element count used by slot2
  uint8_t mPad14[4];  // 0x14 — unproven gap
  void* mHeap18;      // 0x18 — heap buffer; elements 0x370 bytes
                      //   (0x370-stride fill loop 0x6b1f60-0x6b1f9c)
  void* mPtrs20[43];  // 0x20 — 43 ptrs, ctor fills from a static table
                      //   (0x6b1eac-0x6b1ed0, entries via [0xf6f0f8+i*4])
  void* mQw178[43];   // 0x178 — 43 qwords zeroed by ctor (0x6b1ed8-0x6b1ef0)
  uint8_t mPad2d0[0x40];  // 0x2d0 — unproven gap (helpers 0x6b1508/0x6b15bc
                          //   touch +0x30..+0x40, +0x148..+0x1b8, +0x1c0)
  void* mPtr310;          // 0x310 — ctor zeroes; D1 (0x6b2014) destroys target
  void* mPtr318;          // 0x318 — ctor zeroes
  uint8_t mPad320[0x10];  // 0x320 — ctor zeroes (0x320/0x328)
  void* mPtr330;          // 0x330 — ctor zeroes
  void* mPtr338;          // 0x338 — ctor zeroes
  void* mPtr340;          // 0x340 — ctor zeroes
  uint32_t mField348;     // 0x348 — ctor zeroes
  uint8_t mPad34c[8];     // 0x34c — ctor stores [GOT 0x12fadb8] (qword)
  uint8_t mPad354[8];     // 0x354 — ctor stores [GOT 0x12fadb8 + 8]
  float mF35c;            // 0x35c — ctor sets 1.0f
  float mF360;            // 0x360 — ctor sets 1.0f
  uint8_t mPad364[4];     // 0x364 — unproven gap
  void* vtable2;          // 0x368 — 0x12b6820 (cell 0x130e050 + 0x10; 2 slots
                          //   0x6b366c/0x6b3670)
  uint32_t mField370;     // 0x370 — ctor sets 1
  uint8_t mPad374[0x14];  // 0x374 — unproven tail (derived ctor 0x6ccf40
                          //   writes a byte at +0x38b)
};
}  // namespace object
