#pragma once

#include <cstdint>

// Vt12c3898 — PLACEHOLDER name (15-slot context object, alloc 0xa8, created
// by manager method FUN_7100792564); vptr 0x12c3898 at +0x00.
// extent 0xa8 - details: doc/object/Vt12c3898.md

namespace object {
class Vt12c3898 {
 public:
  void* vtable;       // 0x00 — 0x12c3898 (creator 0x7925c4..0x7925e8)
  char mPad8[0x8];    // 0x08 — unproven
  void* mField10;     // 0x10 — creator zeroes (0x7925cc)
  void* mField18;     // 0x18 — creator stores arg x1 (0x7925cc)
  void* mField20;     // 0x20 — creator zeroes (0x7925c8)
  void* mField28;     // 0x28 — creator zeroes (0x7925dc)
  void* mField30;     // 0x30 — creator zeroes (0x7925dc)
  void* mField38;     // 0x38 — creator zeroes (0x7925d4)
  void* mField40;     // 0x40 — creator zeroes (0x7925d4)
  uint8_t mField48;   // 0x48 — creator sets 1 (0x7925f0)
  char mPad49[0x7];   // 0x49 — unproven
  uint8_t mField50;   // 0x50 — creator zeroes (0x7925e0)
  char mPad51[0x17];  // 0x51 — unproven
  char mField68[0x10];  // 0x68 — unproven (member ctor 0x74c630, 0x7925f4)
  float mField78;     // 0x78 — creator zeroes (0x792608)
  float mField7C;     // 0x7C — creator sets 1.0f (0x7925f8)
  float mField80;     // 0x80 — creator sets -1.0f (0x7925f8)
  float mField84;     // 0x84 — creator sets 1.0f (0x79260c)
  float mField88;     // 0x88 — creator sets -1.0f (0x79260c)
  float mField8C;     // 0x8C — creator sets 1.0f (0x792604)
  char mPad90[0x18];  // 0x90 — unproven padding to 0xa8
};
}  // namespace object
