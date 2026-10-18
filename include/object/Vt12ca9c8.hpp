#pragma once

#include <cstdint>

// Vt12ca9c8 (size 0xB08) — gear::Actor/MapObj-derived map-object class;
// PROVISIONAL name. Second base vptr at +0x60; four 0xC8-stride member
// objects at +0x448/+0x510/+0x5d8/+0x6a8, each preceded at -0x28 by a
// sub-object (ctor 0x63194c). Ctor 0x807c20.
// extent 0xB08 - details: doc/object/Vt12ca9c8.md

struct Vt12ca9c8 {
  uint64_t vptr;                         //0x00 — 0x12ca9c8 (cell 0x13025e0 holds vt-0x10)
  uint8_t pad08[0x30];                   //0x08 — unmapped, no ctor stores
  uint32_t field38;                      //0x38 — 0
  uint8_t pad3c[0x4];                    //0x3c — padding before +0x40
  uint64_t field40;                      //0x40 — 0
  uint64_t field48;                      //0x48 — 0
  uint64_t field50;                      //0x50 — 0
  uint64_t field58;                      //0x58 — 0
  uint64_t base60_vptr;                  //0x60 — 0x11b3928 (cell 0x12fbd48 +0x10)
  uint32_t field68;                      //0x68 — GetSystemTick at ctor end (0x807c74..0x807c90)
  uint8_t pad6c[0x37c];                  //0x6c — array init via 0x62ee28 on +0x6c
  uint64_t field3e8_vptr;                //0x3e8 — cell 0x13100528 +0x10
  uint64_t field3f0_vptr;                //0x3f0 — cell 0x12fae28 +0x10
  uint64_t field3f8;                     //0x3f8 — 0
  uint64_t field400_vptr;                //0x400 — cell 0x13100538 +0x10
  uint64_t field408;                     //0x408 — this (self-ptr)
  uint64_t field410;                     //0x410 — cell 0x13100530 (raw)
  uint64_t field418;                     //0x418 — 0
  uint64_t sub420;                       //0x420 — sub-object (ctor 0x63194c); holds static 0x12fae78 pre-init
  uint8_t pad428[0x20];                  //0x428 — gap inside member group
  uint64_t member448;                    //0x448 — member (ctor 0x6287b4), 0xC8 stride
  uint8_t pad450[0x98];                  //0x450 — member body, unmapped
  uint64_t sub4e8;                       //0x4e8 — sub-object (ctor 0x63194c)
  uint8_t pad4f0[0x20];                  //0x4f0 — gap inside member group
  uint64_t member510;                    //0x510 — member (ctor 0x6287b4)
  uint8_t pad518[0x98];                  //0x518 — member body, unmapped
  uint64_t sub5b0;                       //0x5b0 — sub-object (ctor 0x63194c)
  uint8_t pad5b8[0x20];                  //0x5b8 — gap inside member group
  uint64_t member5d8;                    //0x5d8 — member (ctor 0x6287b4)
  uint8_t pad5e0[0x98];                  //0x5e0 — member body, unmapped
  uint16_t field678;                     //0x678 — 0; divided by 3 at 0x807d78
  uint8_t pad67a[0x6];                   //0x67a — padding after counter halfword
  uint64_t sub680;                       //0x680 — sub-object (ctor 0x63194c)
  uint8_t pad688[0x20];                  //0x688 — gap inside member group
  uint64_t member6a8;                    //0x6a8 — member (ctor 0x6287b4)
  uint8_t pad6b0[0x98];                  //0x6b0 — member body, unmapped
  uint8_t pad74a[0x3be];                 //0x74a — tail padding to 0xb08 (new size)
  uint16_t field748;                     //0x748 — 0
};
