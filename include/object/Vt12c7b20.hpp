#pragma once

#include <cstdint>

// object::Vt12c7b20 (size 0x16D8) — gear::Actor-derived six-channel buffer
// bank (6 x 0x320 arrays + 100-entry ring desc); PLACEHOLDER name.
// Factory FUN_7100398750, new 0x16D8 at 0x3987C4; C1 FUN_71007CD364.
// extent 0x16D8 - details: doc/object/Vt12c7b20.md

struct Vt12c7b20 {
  uint64_t vptr;              //0x00 — 0x12c7b20 (cell 0x130ffb0 = 0x12c7b10, +0x10)
  uint8_t actor_08[0x30];     //0x08 - 0x37 — gear::Actor base body (base ctor 0x7b976c); fields unverified
  uint64_t vptr_secondary;    //0x38 — 0x12c7ba0 (cell+0x90; 2-slot dtor-thunk group 0x7cd4e0/0x7cd578); member init 0x6155bc(this+0x38)
  uint8_t sub_40[0x18];       //0x40 - 0x57 — sub-object body (init 0x6155bc at +0x38); unverified
  uint8_t sub_58[0x70];       //0x58 - 0xC7 — member initialized by 0x628628(this+0x58); size unverified, bounded by the +0xC8 buffer
  uint8_t chan_C8[0x320];     //0xC8 - 0x3E7 — channel buffer 0, ctor memset 0x320 (0x7cd3d8)
  uint8_t chan_3E8[0x320];    //0x3E8 - 0x707 — channel buffer 1, memset (0x7cd3f0); u32 zero at +0x1388 is outside
  uint8_t chan_708[0x320];    //0x708 - 0xA27 — channel buffer 2, memset (0x7cd408)
  uint8_t chan_A28[0x320];    //0xA28 - 0xD47 — channel buffer 3, memset (0x7cd420)
  uint8_t chan_D48[0x320];    //0xD48 - 0x1067 — channel buffer 4, memset (0x7cd438)
  uint8_t chan_1068[0x320];   //0x1068 - 0x1387 — channel buffer 5, memset (0x7cd454)
  uint32_t count_1388;        //0x1388 — ctor 0 (per-channel counters 0x1388..0x139C)
  uint32_t count_138C;        //0x138C — ctor 0
  uint32_t count_1390;        //0x1390 — ctor 0
  uint32_t count_1394;        //0x1394 — ctor 0
  uint32_t count_1398;        //0x1398 — ctor 0
  uint32_t zero_139C;         //0x139C — ctor 0 (0x7cd45c)
  uint32_t desc_count;        //0x13A0 — ring-desc {0, 100, +0x13B0} (0x60b918 at 0x7cd3bc)
  uint32_t desc_cap;          //0x13A4 — capacity 100 (0x64)
  uint64_t desc_data;         //0x13A8 — ctor 0, then this+0x13B0
  uint64_t data_13B0[100];    //0x13B0 — 100 x 8 B entries (0x13B0 - 0x16CF)
  float max_16D0;             //0x16D0 — ctor FLT_MAX 0x7f7fffff (0x7cd3d4)
  uint32_t pad_16D4;          //0x16D4 - 0x16D7 — no ctor store; alignment tail (unproven)
};
