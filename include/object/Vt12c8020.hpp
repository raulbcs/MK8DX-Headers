#pragma once

#include <cstdint>

// object::Vt12c8020 — PLACEHOLDER name; base class of the Vt12c80f0 pair (singleton
// config snapshots + 0x7f0 scratch buffer). 21 slots; MI secondary vptr at +0x138.
// vptr 0x12c8020, GOT cell 0x1310058 holds vt-0x10.
// extent 0x3a0 - details: doc/object/Vt12c8020.md

namespace object {
class Vt12c8020 {
 public:
  void* vtable;         // 0x00 — 0x12c8020, installed by C1 0x7d8a5c
  char mPad8[0x130];    // 0x08 — base-ctor 0x8df144 region, unproven
  void* mSubVptr;       // 0x138 — secondary vptr 0x12c80d0 (dtor-pair-only secondary base)
  char mPad140[0x210];  // 0x140 — unproven; D2 deletes a member ptr at +0x218
  void* mScratch;       // 0x350 — new(0x7f0) zeroed buffer, C1 0x7d8b04-0x7d8b18
  char mPad358[0x48];   // 0x358 — counters/flags + 3 singleton-config copies, 0x7d8a78-0x7d8b00
};
}  // namespace object
