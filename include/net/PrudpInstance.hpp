#pragma once

#include <cstdint>

// PrudpInstance (size 0x1B8) — OnlineCore "prudp" instance; PROVISIONAL name
// (slot-8 thunk returns "prudp" at 0xf148e3). Factory FUN_7100a2e5b4.
// extent 0x1B8 - details: doc/net/PrudpInstance.md

struct PrudpInstance {
  uint64_t vptr;              //0x00 — *0x1314750 + 0x10 = 0x12e3888 (ctor 0xa0bd44, D2 0xa0c14c)
  uint64_t field_08;          //0x08 — unwritten by ctor
  uint64_t field_10;          //0x10 — ctor 0xa0bd2c stp xzr
  uint64_t field_18;          //0x18 — arg x2 (ctor 0xa0bd2c)
  uint16_t field_20;          //0x20 — ctor strb wzr (0xa0bd28)
  uint16_t field_22;          //0x22 — ctor strh wzr (0xa0bd38)
  uint8_t pad_24[4];          //0x24..0x27 — unwritten
  uint8_t pad_28[8];          //0x28..0x2f — unwritten
  uint64_t list_30;           //0x30 — self node (ctor 0xa0bd5c)
  uint64_t field_38;          //0x38 — ctor zero (0xa0bd58)
  uint64_t list_40;           //0x40 — self node (ctor 0xa0bd74)
  uint64_t field_48;          //0x48 — self ptr (ctor 0xa0bd74)
  uint64_t field_50;          //0x50 — ctor zero
  uint64_t field_58;          //0x58 — ctor zero
  uint8_t flag_60;            //0x60 — ctor 0 (0xa0bd80)
  uint8_t pad_61[7];          //0x61..0x67 — unwritten
  uint64_t list_68;           //0x68 — ctor zero (0xa0bd70)
  uint64_t list_70;           //0x70 — ctor zero (0xa0bd70)
  uint64_t field_78;          //0x78 — ctor zero (0xa0bd7c)
  uint64_t list_80;           //0x80 — self node (ctor 0xa0bd88)
  uint64_t field_88;          //0x88 — ctor zero
  uint64_t field_90;          //0x90 — ctor stp xzr,this+0x98 (0xa0bd94)
  uint64_t field_98;          //0x98 — this+0x98 node
  uint64_t field_a0;          //0xa0 — ctor stp this+0x98,xzr (0xa0bd98)
  uint64_t field_a8;          //0xa8 — ctor zero
  uint64_t field_b0;          //0xb0 — ctor stp xzr,xzr (0xa0bd9c)
  uint64_t field_b8;          //0xb8 — ctor zero
  uint64_t field_c0;          //0xc0 — ctor zero (0xa0bd90)
  uint8_t pad_c8[8];          //0xc8..0xcf — unwritten
  uint8_t tail_d0[0xe8];      //0xd0..0x1b7 — mutex/init state; lock/unlock vtable slots wrap +0x178 (0xa101b8/0xa101d4)
};
