#pragma once

#include <cstdint>

// object::Vt12c7d08 (size 0x7D58) — gear::Actor-derived double ring buffer
// (2 x 2000 x 8 B entries); PLACEHOLDER name. Factory FUN_7100398750,
// new 0x7D58 at 0x3988FC; in-place ctor 0x7D4AD4 (unnamed in functions.csv).
// extent 0x7D58 - details: doc/object/Vt12c7d08.md

struct Vt12c7d08 {
  uint64_t vptr;              //0x00 — 0x12c7d08 (cell 0x130fff8 = 0x12c7cf8, +0x10)
  uint8_t actor_08[0x30];     //0x08 - 0x37 — gear::Actor base body (base ctor 0x7b976c); fields unverified
  uint32_t desc_count;        //0x38 — ring-desc {0, 2000, +0x48} (0x60b918 at 0x7d4b10)
  uint32_t desc_cap;          //0x3C — capacity 2000 (0x7D0)
  uint64_t desc_data;         //0x40 — ctor 0, then this+0x48
  uint64_t data_48[2000];     //0x48 — 2000 x 8 B entries (0x48 - 0x3EC7)
  uint32_t desc2_count;       //0x3EC8 — ring-desc {0, 2000, +0x3ED8}
  uint32_t desc2_cap;         //0x3ECC — capacity 2000
  uint64_t desc2_data;        //0x3ED0 — ctor 0, then this+0x3ED8
  uint64_t data2_3ED8[2000];  //0x3ED8 — 2000 x 8 B entries (0x3ED8 - 0x7D57)
};
