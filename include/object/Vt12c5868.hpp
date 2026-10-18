#pragma once

#include <cstdint>

// object::Vt12c5868 (size 0x59C0) — gear::Actor-derived buffer-holder base;
// PLACEHOLDER name. Concrete wrapper FUN_7100066940 re-installs final vptr
// 0x11B42C0 after C1 FUN_71007BB754. new 0x59C0 at 0x58BCC.
// extent 0x59C0 - details: doc/object/Vt12c5868.md

struct Vt12c5868 {
  uint64_t vptr;              //0x00 — C1 installs 0x12c5868 (cell 0x130feb8 = 0x12c5858, +0x10); wrapper 0x66940 overwrites with 0x11b42c0
  uint8_t actor_08[0x30];     //0x08 - 0x37 — gear::Actor base body (base ctor 0x7b976c); fields unverified
  uint64_t zero_38;           //0x38 — ctor stores 0
  uint32_t desc40_count;      //0x40 — ring-desc {0, 12, +0x50} (0x60b918)
  uint32_t desc40_cap;        //0x44 — capacity 12
  uint64_t desc40_data;       //0x48 — ctor 0, then set to this+0x50
  uint64_t data50[12];        //0x50 — 12 x 8 B entries (0x50 - 0xAF)
  uint32_t descB0_count;      //0xB0 — ring-desc {0, 12, +0xC0}
  uint32_t descB0_cap;        //0xB4 — capacity 12
  uint64_t descB0_data;       //0xB8 — ctor 0, then set to this+0xC0
  uint64_t dataC0[12];        //0xC0 — 12 x 8 B entries (0xC0 - 0x11F)
  uint8_t block120[0x5780];   //0x120 - 0x589F — ctor memset 0 (0x7bb7bc); tail region re-inited below
  uint8_t table58A0[0x110];   //0x58A0 - 0x59AF — ctor fills: -1 qwords 0x58A0-0x58DF, 0x5950/0x5958; u16 config pairs (global [x]+0x3E8) at 0x58A0/0x58A8 + 0x5920/0x5928, stride 4, 16 iters; 0x7F7FFFFF floats at 0x58E0.., 0x5960..; zeros 0x59A0-0x59AF; byte 1 at 0x59B8 is outside (see below)
  uint64_t owned_59B0;        //0x59B0 — new 0x70 (0x7bb860), init 0x7c55cc(ptr, -1)
  uint8_t flag_59B8;          //0x59B8 — ctor stores 1
  uint8_t pad_59B9[7];        //0x59B9 - 0x59BF — no ctor store; no accessor evidence (unproven)
};
