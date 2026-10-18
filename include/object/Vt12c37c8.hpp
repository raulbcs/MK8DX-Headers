#pragma once

#include <cstdint>

// Vt12c37c8 — PLACEHOLDER name (15-slot context object, alloc 0x80, created
// by manager method FUN_71007900c0); vptr 0x12c37c8 at +0x00.
// extent 0x80 - details: doc/object/Vt12c37c8.md

namespace object {
class Vt12c37c8 {
 public:
  void* vtable;      // 0x00 — 0x12c37c8 (creator 0x7900fc..0x79011c)
  void* mField8;     // 0x08 — creator zeroes (0x7900f0)
  void* mField10;    // 0x10 — creator stores arg x1 (0x7900f0)
  char mPad18[0x8];  // 0x18 — unproven
  void* mField20;    // 0x20 — creator zeroes (0x79010c)
  void* mField28;    // 0x28 — creator zeroes (0x79010c)
  void* mField30;    // 0x30 — creator zeroes (0x790104)
  void* mField38;    // 0x38 — creator zeroes (0x790104)
  uint32_t mField40; // 0x40 — creator zeroes (0x7900f8)
  char mPad44[0x4];  // 0x44 — unproven
  uint8_t mField48;  // 0x48 — creator sets 1 (0x790124)
  char mPad49[0x7];  // 0x49 — unproven
  uint8_t mField50;  // 0x50 — creator zeroes (0x79014c)
  char mPad51[0x3];  // 0x51 — unproven
  uint32_t mField54; // 0x54 — creator zeroes (0x790108)
  uint8_t mField58;  // 0x58 — creator zeroes (0x790114)
  char mPad59[0x7];  // 0x59 — unproven
  void* mField60;    // 0x60 — creator zeroes (0x790118)
  int32_t mField68;  // 0x68 — creator sets -1 (0x79012c)
  char mPad6C[0x4];  // 0x6C — unproven
  int32_t mField70;  // 0x70 — creator copies u32 at 0xf6e5f4 (0x790138)
  int32_t mField74;  // 0x74 — creator copies u32 at 0xf6e5f4 (0x79013c)
  int32_t mField78;  // 0x78 — creator copies u32 at 0xf6e5f0 (0x790148)
  int32_t mField7C;  // 0x7C — creator copies u32 at 0xf6e5f0 (0x790148)
};
}  // namespace object
