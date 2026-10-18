#pragma once

#include <cstdint>

// Vt12d9080 — PLACEHOLDER name; nn::pia/nn::ldn-family session object.
// 16 slots, typeinfo NULL; GOT cell 0x1312698 holds 0x12d9070 (row-0x10).
// extent 0x408 - details: doc/net/Vt12d9080.md

struct Vt12d9080 {
  uint64_t vptr;             // 0x00 — 0x12d9080 (ctor 0x921f78)
  uint8_t mPad8[0x8];        // 0x08 — unproven padding (byte flag at +0x08, base 0x911bf4)
  uint64_t field_10;         // 0x10 — vptr 0x12d7f20 (base init 0x911bf4)
  uint8_t field_18;          // 0x18 — strb wzr (0x911c58)
  uint8_t mPad19[0x3];       // 0x19 — unproven padding
  uint32_t field_1C;         // 0x1C — str wzr (0x911c64)
  uint8_t field_20;          // 0x20 — strb wzr (0x911c68)
  uint8_t mPad21[0x7];       // 0x21 — unproven padding
  uint8_t field_28;          // 0x28 — strb wzr (0x911c6c)
  uint8_t mPad29[0x7];       // 0x29 — unproven padding
  uint64_t member_30;        // 0x30 — new 0x10 object, vptr 0x12d9090 (ctor 0x921f78)
  uint8_t mPad38[0x10];      // 0x38 — unproven padding (zeroed at 0x911c74)
  uint64_t member_48;        // 0x48 — init 0x9be110 (0x911c88)
  uint8_t mPad50[0x3B8];     // 0x50 — unproven padding (0x51-byte buffers at +0x74/+0xFC/+0x184, base init 0x911bf4)
};
