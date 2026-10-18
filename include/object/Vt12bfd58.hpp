#pragma once

#include <cstdint>

// Vt12bfd58 (size 0x98) — 26-slot game class; PROVISIONAL name. Base sub-object
// (base vt 0x12accb0 via cell 0x130c930, base size 0x58) at +0x00; derived
// state +0x60..+0x91. Ctor 0x742048, inlined factory new(0x98) at 0x74379c.
// extent 0x98 - details: doc/object/Vt12bfd58.md

struct Vt12bfd58 {
  uint64_t vptr;                         //0x00 — 0x12bfd58 (cell 0x130ecf0 holds vt-0x10)
  uint64_t base_self;                    //0x08 — this+0x08 (base ctor 0x5a0994)
  uint64_t base_10;                      //0x10 — this+0x08
  uint64_t base_18;                      //0x18 — 0
  uint64_t base_20;                      //0x20 — 0
  uint64_t base_28;                      //0x28 — 0
  uint8_t pad30[0x10];                   //0x30 — gap, no ctor stores
  uint64_t base_40;                      //0x40 — 0
  uint64_t base_48;                      //0x48 — this+0x48
  uint64_t base_50;                      //0x50 — this+0x48
  uint64_t base_58;                      //0x58 — 0
  uint8_t pad88[0x8];                    //0x88 — padding, unmapped
  uint64_t field60;                      //0x60 — 0 (ctor 0x742048 stp xzr,xzr)
  uint64_t field68;                      //0x68 — 0
  uint64_t field70;                      //0x70 — 0
  uint64_t field78;                      //0x78 — 0
  uint64_t owner;                        //0x80 — ctor x1 param
  uint16_t field90;                      //0x90 — 0x200
  uint8_t pad92[0x6];                    //0x92 — padding to 0x98 (factory new)
};
