#pragma once

#include <cstdint>

// Vt12cb9b8 — PLACEHOLDER name; 14 slots, no RTTI; pooled object, vptr installed post-init.
// Site 0x8297ec fetches the pooled object (FUN_71006ad048), inits it (FUN_71006b5e2c), then stores this vptr.
// extent 0x318 (lower bound: FUN_71006b5e2c writes through +0x314; unverified) -
// details: doc/object/Vt12cb9b8.md

namespace object {
class Vt12cb9b8 {
 public:
  void* mVtable;         // 0x00 — 0x12cb9b8 (via GOT cell 0x1310860, cell holds vptr-0x10)
  uint8_t mPad8[0x30C];  // 0x08 — unproven padding; FUN_71006b5e2c zeroes +0x20..+0x34 and +0x300..+0x314
  uint32_t m314;         // 0x314 — FUN_71006b5e2c: -1
};
}  // namespace object
