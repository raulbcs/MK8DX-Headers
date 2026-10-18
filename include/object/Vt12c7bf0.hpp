#pragma once

#include <cstdint>

// object::Vt12c7bf0 (size 0xBBD8) — gear::Actor-derived double ring buffer
// (2 x 3000 x 8 B entries); PLACEHOLDER name. Factory FUN_7100398750,
// new 0xBBD8 at 0x398894; C1 FUN_71007D2FA4.
// extent 0xBBD8 - details: doc/object/Vt12c7bf0.md

struct Vt12c7bf0 {
  uint64_t vptr;              //0x00 — 0x12c7bf0 (cell 0x130ffd0 = 0x12c7be0, +0x10)
  uint8_t actor_08[0x30];     //0x08 - 0x37 — gear::Actor base body (base ctor 0x7b976c); fields unverified
  uint32_t desc_count;        //0x38 — ring-desc {0, 3000, +0x48} (0x60b918 at 0x7d2fe0)
  uint32_t desc_cap;          //0x3C — capacity 3000 (0xBB8)
  uint64_t desc_data;         //0x40 — ctor 0, then this+0x48
  uint64_t data_48[3000];     //0x48 — 3000 x 8 B entries (0x48 - 0x5E07)
  uint32_t desc2_count;       //0x5E08 — ring-desc {0, 3000, +0x5E18}
  uint32_t desc2_cap;         //0x5E0C — capacity 3000
  uint64_t desc2_data;        //0x5E10 — ctor 0, then this+0x5E18
  uint64_t data2_5E18[3000];  //0x5E18 — 3000 x 8 B entries (0x5E18 - 0xBBD7)
};
