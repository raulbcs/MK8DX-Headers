#pragma once

#include <cstdint>

// Vt12ceb70 — PLACEHOLDER name; vptr 0x12ceb70, 54 slots, GOT cell 0x1310e80.
// Derived from Vt12ced30 (its C1 runs first); intrusive node chain at +0x4D8..+0x618.
// extent 0x680 - details: doc/object/Vt12ceb70.md

namespace object {
class Vt12ceb70 {
 public:
  void* mVtable;            // 0x00 — 0x12ceb70 (via GOT cell 0x1310e80)
  uint8_t mPad8[0x58];      // 0x08 — Vt12ced30 base layout
  uint32_t mField60;        // 0x60 — base ctor arg w2
  uint8_t mPad64[0x1C];     // 0x64 — unproven padding
  void* mArray80;           // 0x80 — counted 0x130-byte-element array (base C1)
  uint8_t mPad88[0x450];    // 0x88 — unproven padding
  void* mNode4D8;           // 0x4D8 — head of intrusive chain (see doc)
  uint8_t mPad4E0[0x198];   // 0x4E0 — unproven padding (self-referential node fields)
  uint16_t mField678;       // 0x678 — set to 0x100 by C1
  uint8_t mPad67A[0x6];     // 0x67A — unproven padding
};
}  // namespace object
