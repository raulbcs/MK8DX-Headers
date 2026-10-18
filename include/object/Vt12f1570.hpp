#pragma once

#include <cstdint>

// Vt12f1570 (size 0xA8) — base class of Vt12f1440; PROVISIONAL name (no name
// string). Slots are accessors into a 12-byte record at [this+0x20].
// extent 0xA8 - details: doc/object/Vt12f1570.md

struct Vt12f1570 {
  uint64_t vptr;            //0x00 — *0x1314f38 + 0x10 = 0x12f1578 (ctor 0xa6d618)
  uint64_t field_08;        //0x08..0x0f — base ctor 0x59e1f8 region (unverified)
  uint64_t field_10;        //0x10..0x17 — base ctor 0x59e1f8 region (unverified)
  uint64_t field_18;        //0x18..0x1f — unwritten
  uint64_t record_20;       //0x20 — pointer to the 12-byte record read by the accessor slots
  uint8_t member_28[0x18];  //0x28..0x3f — embedded object; vptr at +0x28, final *0x1314f40+0x10 = 0x12f16a8 (ctor 0xa6d690); init 0x59e1d0(+0x28,0,0xc,...)
  uint8_t flag_40;          //0x40 — ctor 0
  uint8_t pad_41[7];        //0x41..0x47 — unwritten
  int64_t field_48;         //0x48 — ctor -1 (0xa6d634/0xa6d65c/0xa6d69c)
  uint8_t pad_50[0x10];     //0x50..0x5f — unwritten
  uint64_t field_60;        //0x60 — ctor zero (0xa6d6b8)
  uint64_t field_68;        //0x68 — ctor zero (0xa6d6b8)
  uint64_t field_70;        //0x70 — ctor zero (0xa6d6b8)
  uint64_t field_78;        //0x78 — ctor zero (0xa6d6b8)
  uint32_t field_80;        //0x80 — ctor 0 (0xa6d6a4)
  uint8_t tail_84[4];       //0x84..0x87 — padding to 0xa8
  uint8_t tail_88[0x20];    //0x88..0xa7 — tail to sizeof 0xa8 (derived array stride), unwritten by ctor
};
