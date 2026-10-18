#pragma once

#include <cstdint>

// Vt12c8520 (size 0x7B8) — gear::Actor-derived game class; PROVISIONAL name.
// Bases at +0x38 (vt 0x12c80f0) and +0x3d8 (vt 0x12c8470); state block
// +0x738..+0x798. Ctor 0x7de5b0, D2 0xcc108, D0 0x7df15c.
// extent 0x7B8 - details: doc/object/Vt12c8520.md

struct Vt12c8520 {
  uint64_t vptr;                         //0x00 — 0x12c8520 (cell 0x12fcd88 holds vt-0x10)
  uint8_t pad08[0x30];                   //0x08 — unmapped, no ctor stores
  uint64_t base38_vptr;                  //0x38 — 0x12c80f0 (base ctor 0x7d9d30)
  uint8_t pad40[0x398];                  //0x40 — unmapped (base-internal region)
  uint64_t base3d8_vptr;                 //0x3d8 — 0x12c8470 (base ctor 0x7dded0)
  uint8_t pad3e0[0x358];                 //0x3e0 — unmapped (base-internal region)
  uint64_t field738;                     //0x738 — 0
  uint32_t field740;                     //0x740 — -1
  uint32_t field744;                     //0x744 — 0
  uint32_t field748;                     //0x748 — -1
  uint8_t pad74c[0x14];                  //0x74c — gap, unmapped
  uint64_t field760;                     //0x760 — 0
  uint64_t field768;                     //0x768 — -1 | field76c=0, field76d=1 (ctor bytes)
  uint32_t field770;                     //0x770 — -1
  uint8_t field774;                      //0x774 — 0
  uint8_t pad775[0x3];                   //0x775 — padding after flag byte
  uint32_t field778;                     //0x778 — -1
  uint16_t field77c;                     //0x77c — 0
  uint8_t pad77e[0x1a];                  //0x77e — gap to +0x798
  uint32_t field798;                     //0x798 — 0 (caller 0xcb3c4 post-init)
  uint8_t pad79c[0x1c];                  //0x79c — tail padding to 0x7b8 (new size)
};
