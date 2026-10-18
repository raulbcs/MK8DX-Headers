#pragma once

#include <cstdint>

// Vt12f22e0 (size 0x88) — sead::ArchiveFileDevice derivative; PROVISIONAL name
// (no name string). Ctor 0x6896b0 parses a device path into +0x48..0x87.
// extent 0x88 - details: doc/object/Vt12f22e0.md

struct Vt12f22e0 {
  uint64_t vptr;          //0x00 — *0x130ddc0 + 0x10 = 0x12f22e0 (ctor 0x689814)
  uint64_t field_08[2];   //0x08..0x17 — base region (base ctor 0x6155bc, unverified)
  uint64_t field_18;      //0x18 — arg (SafeString base ctor arg, ctor 0x6896f8)
  uint64_t field_20[2];   //0x20..0x2f — ctor zeroes (0x6896ec)
  uint64_t field_30[2];   //0x30..0x3f — ctor stp this,xzr (0x6896f0)
  uint64_t member_40;     //0x40 — embedded object, vptr *0x12fada0+0x10 = 0x11ad0f8 (ctor 0x689720); init 0x61cc48(0x20)
  uint64_t field_48;      //0x48 — self ptr to +0x54 buffer (ctor 0x689714)
  uint8_t pad_50[4];      //0x50..0x53 — unwritten
  char path_54[0x2c];     //0x54..0x7f — device/path chars; memcpy of parsed chunk + terminator (0x689808)
  uint64_t field_80;      //0x80 — arg x1 (ctor 0x689818)
};
