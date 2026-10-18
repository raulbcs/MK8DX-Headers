#pragma once

#include <cstdint>

// object::Vt12c3118 (size 0x48) — small MI class; PLACEHOLDER name (no string
// evidence). Secondary vptr 0x12c3118 at +0x28 (cell 0x130f6e8 = vt-0x10);
// primary vptr 0x12c3330 at +0x00. Factory FUN_7100792518, new 0x48.
// extent 0x48 - details: doc/object/Vt12c3118.md

struct Vt12c3118 {
  uint64_t vptr_primary;      //0x00 — 0x12c3330 (cell 0x130f6e0 = 0x12c3320, +0x10)
  uint8_t base_08[0x20];      //0x08 - 0x27 — base ctor 0x79deec runs before vptr installs; individual fields unverified
  uint64_t vptr_secondary;    //0x28 — 0x12c3118 (cell 0x130f6e8 = 0x12c3108, +0x10); installed with [this+0x30] = 0
  uint64_t zero_30;           //0x30 — ctor stores 0
  uint64_t self_38;           //0x38 — ctor stores `this` (back/next pointer of an intrusive node, unverified)
  uint64_t global_40;         //0x40 — ctor stores [[cell 0x12fc390]] = [0x1359a50] (global singleton/list head)
};
