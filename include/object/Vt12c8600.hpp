#pragma once

#include <cstdint>

// Vt12c8600 — mid-chain base class of the 0x7d8-0x7df derivation family
// (C1 FUN_71007dfb80 over base C1 FUN_7100a890f0; derived ctors 0x8df144,
// 0x7d8a5c). Primary vptr 0x12c8600 at +0x00, 2-slot secondary 0x12c8678 at
// +0x138. Deepest store +0x344; exact size unproven (lower bound).
// extent 0x348 - details: doc/object/Vt12c8600.md

namespace object {
class Vt12c8600 {
 public:
  void* mVtable;          // 0x00 — vptr 0x12c8600 (cell 0x13100f0+0x10)
  uint8_t m8[0x108];      // 0x08 — unproven (base C1 FUN_7100a890f0 body)
  uint8_t m110[0x4];      // 0x110 — unproven
  uint32_t m114;          // 0x114 — 0 (0x7dfc00)
  uint8_t m118[0x98];     // 0x118 — unproven
  void* m1B0;             // 0x1b0 — unproven
  uint8_t m1B8[0x10];     // 0x1b8 — 0 (0x7dfc10 stp)
  uint32_t m1C8;          // 0x1c8 — 1.0f bit pattern 0x3f800000 (0x7dfbc8)
  uint32_t m1CC;          // 0x1cc — unproven
  uint32_t m1D0;          // 0x1d0 — 0 (0x7dfba4)
  uint32_t m1D4;          // 0x1d4 — unproven
  uint8_t m1D8;           // 0x1d8 — 0 (0x7dfbe0)
  uint8_t m1D9[0x3];      // 0x1d9 — unproven
  uint8_t m1DC;           // 0x1dc — 0 (0x7dfbe4)
  uint8_t m1DD[0x3];      // 0x1dd — unproven
  uint8_t m1E0[0x8];      // 0x1e0 — 0 (0x7dfc20)
  void* m1E8[2];          // 0x1e8 — -1, -1 (0x7dfc1c stp)
  void* m1F8;             // 0x1f8 — 0 (0x7dfbe8)
  void* m200;             // 0x200 — 0 (0x7dfbec)
  uint8_t m208;           // 0x208 — 0 (0x7dfbf0)
  uint8_t m209[0x3];      // 0x209 — unproven
  uint32_t m20C;          // 0x20c — 1 (0x7dfbf4)
  void* m210;             // 0x210 — 0 (0x7dfbf8)
  uint32_t m218;          // 0x218 — 0 (0x7dfbfc)
  uint32_t m21C;          // 0x21c — 0 byte (0x7dfc08)
  uint8_t m220[0x10];     // 0x220 — unproven
  uint8_t m230;           // 0x230 — 0 byte (0x7dfc0c)
  uint8_t m231[0x3];      // 0x231 — unproven
  uint32_t m234;          // 0x234 — 0 (0x7dfbc4)
  uint16_t m238;          // 0x238 — 0 (0x7dfc2c)
  uint16_t m23A;          // 0x23a — unproven
  uint8_t m23C;           // 0x23c — 0 (0x7dfbc0 strh covers 0x23c/0x23d)
  uint8_t m23D;           // 0x23d — 0 (0x7dfc04)
  uint8_t m23E[0x2];      // 0x23e — unproven
  uint8_t m240[0x70];     // 0x240 — memcpy from rodata 0xf739a4, 0x70 bytes
                          //        (0x7dfc24-0x7dfc40)
  uint8_t m2B0[0x10];     // 0x2b0 — unproven
  uint8_t m2C0;           // 0x2c0 — 0 (0x7dfb94)
  uint8_t m2C1[0x83];     // 0x2c1 — unproven
  uint32_t m344;          // 0x344 — 0 (0x7dfba0)
};
}  // namespace object
