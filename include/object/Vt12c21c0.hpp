#pragma once

#include <cstdint>

// Vt12c21c0 — placeholder name; large driver-backed object (page-aligned
// alloc), primary table, RTTI-less; MI band vptr at +0x10.
// extent 0x658 - details: doc/object/Vt12c21c0.md

namespace object {
class Vt12c21c0 {
 public:
  void* mVtable;           // 0x00 — 0x12c21c0 (via GOT cell 0x130f398)
  uint32_t mU08;           // 0x08 — zero-init
  uint32_t mPad0C;         // 0x0C
  void* mVtable2;          // 0x10 — band 0x12c2200 (base subobject at +0x10)
  uint8_t mPad18[0x610];   // 0x18 — unproven (base members; slot4 touches +0x381)
  void* mOwner;            // 0x628 — back-pointer to owner+0x240 slot
  void* mPtr630;           // 0x630 — owned, deleted by D1/D0 (0x773658)
  void* mPtr638;           // 0x638 — owned, deleted by D1/D0 (0x773668)
  uint8_t mFlag640;        // 0x640 — u8 flag from factory arg
  uint8_t mPad641[0x7];    // 0x641 — unproven padding
  void* mPtr648;           // 0x648 — rodata 0xf085f5 default, else owner+0x258
  uint8_t mFlag650;        // 0x650 — u8 flag (read by slot4 at 0x7737F4)
  uint8_t mPad651[0x7];    // 0x651 — unproven padding
};
}  // namespace object
