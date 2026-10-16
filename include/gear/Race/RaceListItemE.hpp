#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceListItemE — PROVISIONAL vtable-anchored name ("E"). Manager list item
// of the far race family (NOT a RaceDirector child — reuses the enter/calc/
// exit slot block only). Vtable 0x11b89c8, ctor 0x71000c8138, size 0xB00.
// Details: doc/gear/Race/RaceListItemE.md

namespace gear {
class RaceListItemE : public Actor {
 public:
  void* mList70;                  //0x70 — intrusive list head
  uint8_t mGap78[0x10];           //0x78 — unproven gap
  void* mList88;                  //0x88 — list head
  void* mList90;                  //0x90 — list head
  uint32_t mFive98;               //0x98 — ctor sets 5
  uint8_t mGap9c[0xa4];           //0x9C — unproven gap
  uint8_t mNodeArrays140[0x24c];  //0x140 - 0x38B — fixed-stride node arrays (next/prev self-links)
  uint8_t mGap38c[0x24];          //0x38C — unproven gap
  uint8_t zero3B0[0x200];         //0x3B0 - 0x5AF — ctor zeroes
  uint8_t mGap5b0[8];             //0x5B0 — unproven gap
  struct Cfg30 {
    uint8_t bytes[0x30];
  };
  // 0x5B8/0x618/0x678/0x6D8 — four 0x30-byte copies of [0x12fb188]; overlays
  // f32 10.0 (+0x38) and f32 1.0 (+0x4C) per block (0x5F0/0x650/0x6B0/0x710, 0x604/0x664/0x6C4/0x724)
  Cfg30 mCfg5b8;           //0x5B8
  Cfg30 mCfg618;           //0x618
  Cfg30 mCfg678;           //0x678
  Cfg30 mCfg6d8;           //0x6D8
  void* mMember730;        //0x730 — ctor 0x62c3a8
  uint8_t pad_738[0xB8];   //0x738 — unproven gap (to next member, stride 0xC0)
  void* mMember7f0;        //0x7F0 — ctor 0x62c3a8 (stride 0xC0)
  uint8_t mGap7f8[0xb8];   //0x7F8 — unproven gap
  void* mMember8b0;        //0x8B0 — ctor 0x62c3a8
  uint8_t mGap8b8[0xb8];   //0x8B8 — unproven gap
  void* mMember970;        //0x970 — ctor 0x62c3a8
  uint8_t mGap978[0x38];   //0x978 — unproven gap
  uint8_t zero9b0[0x150];  //0x9B0 - 0xAFF — unproven (0xB00 total)
};
}  // namespace gear
