#pragma once

#include <cstdint>

// Vt12d5d58 — PLACEHOLDER name; intermediate class of the Vt12c7d88 hierarchy
// (base ctor FUN_71007d4c9c; derived Vt12ca828 re-overrides the vptr at its
// sites). Ctor FUN_71008dce74; size 0x168 proven by operator new 0x168 at
// 0x804ed4. extent 0x168 - details: doc/object/Vt12d5d58.md

struct Vt12d5d58 : public Vt12c7d88 {
  uint8_t mPadD8[0x5c];   // 0xD8 — unproven (region between base and intermediate fields)
  uint32_t mField134;     // 0x134 — float from arg s0 (ctor 0x8dcebc..0x8dcec4)
  uint32_t mField138;     // 0x138 — float from arg s1 (ctor 0x8dcec4)
  uint32_t mField13C;     // 0x13C — float from arg s0 (ctor 0x8dcec8)
  uint64_t mField140;     // 0x140 — ptr pair copied from global [0x12fb148] (ctor 0x8dcecc)
  uint64_t mField148;     // 0x148 — u32 pair from global [0x12fb148] (ctor 0x8dced4)
  uint8_t mPad150[0x8];   // 0x150 — unproven (alignment)
  uint64_t mField158;     // 0x158 — ptr copied from global [0x12fb148] (ctor 0x8dcedc)
  uint32_t mField160;     // 0x160 — u32 pair from global [0x12fb148] (ctor 0x8dcee4)
  uint8_t mPad164[0x4];   // 0x164 — unproven (alignment)
};
