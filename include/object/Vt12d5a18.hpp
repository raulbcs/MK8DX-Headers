#pragma once

#include <cstdint>

// Vt12d5a18 (size 0x278) — 26-slot game class; PROVISIONAL name. Secondary
// vptr at +0xf8 (0x12d5b08, same table +0xf0); interface vptrs at +0x130
// (0x11ad0f8) and +0x188 (0x11ad158). Ctor 0x8da658, D1 0x8daa48.
// extent 0x278 - details: doc/object/Vt12d5a18.md

struct Vt12d5a18 {
  uint64_t vptr;                         //0x00 — 0x12d5a18 (cell 0x1311db8 holds vt-0x10)
  uint8_t pad08[0xf0];                   //0x08 — unmapped, no ctor stores
  uint64_t basef8_vptr;                  //0xf8 — 0x12d5b08 (vptr+0xf0, secondary group)
  uint8_t pad100[0x30];                  //0x100 — unmapped secondary-group body
  uint64_t base130_vptr;                 //0x130 — 0x11ad0f8 (cell 0x12fada0 +0x10)
  uint64_t field138;                     //0x138 — inner pointer (byte-copied from 0x12fada0 cell)
  uint8_t pad140[0x48];                  //0x140 — +0x140 = 0x40 flag
  uint64_t base188_vptr;                 //0x188 — 0x11ad158 (cell 0x12fadb0 +0x10)
  uint64_t field190;                     //0x190 — inner pointer (cell 0x12fadb0)
  uint8_t pad198[0x60];                  //0x198 — +0x198 = 0x40 flag
  uint64_t field1f8;                     //0x1f8 — 0
  uint64_t field200;                     //0x200 — 0
  uint64_t field208;                     //0x208 — 0
  uint64_t field210;                     //0x210 — 0
  uint64_t field218;                     //0x218 — 0
  uint32_t field220;                     //0x220 — 2
  uint32_t field224;                     //0x224 — -1
  uint8_t field228;                      //0x228 — 0
  uint8_t pad229[0x3];                   //0x229 — padding after flag byte
  uint32_t field22c;                     //0x22c — -1
  uint8_t pad230[0x20];                  //0x230 — gap, unmapped
  uint64_t field250;                     //0x250 — 0
  uint64_t field258;                     //0x258 — 0
  uint64_t field260;                     //0x260 — 0
  uint64_t field268;                     //0x268 — 0
  uint64_t field270;                     //0x270 — end of 0x278 block
};
