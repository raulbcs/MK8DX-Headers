#pragma once

#include <cstdint>

// Vt12ba5c0 — secondary interface table (13 slots, offset-to-top -0x248) of a
// KartParamCache-family aggregate built in place at Vt12b6af8+0x1dd8
// (C1 FUN_71006e38e0). Primary vptr 0x12ba568 at +0x00; size 0x1bf0 proven by
// the next member ctor at Vt12b6af8+0x39c8. extent 0x1bf0 - details: doc/object/Vt12ba5c0.md

namespace object {
class Vt12ba5c0 {
 public:
  void* mVtablePrimary;   // 0x00 — primary vptr 0x12ba568 (cell 0x130e3d8+0x10, 9 slots)
  uint8_t m8[0x240];      // 0x08 — unproven (base ctor 0x6c6128 body)
  void* mVtableSecondary; // 0x248 — secondary vptr 0x12ba5c0 (cell 0x130e3d8+0x68);
                          //        first set by base member ctor 0x668d40, then
                          //        adjusted by C1 (0x6e3928/0x6e3964)
  uint8_t m250[0x1C8];    // 0x250 — unproven
  void* m418;             // 0x418 — 0 (0x6e3954)
  void* m420;             // 0x420 — 0 (0x6e3950)
  void* m428;             // 0x428 — 0 (0x6e394c)
  void* m430;             // 0x430 — 0 (0x6e392c)
  float m438;             // 0x438 — 1.0f (0x6e3938)
  uint16_t m43C;          // 0x43c — 0 (0x6e3958)
  uint16_t m43E;          // 0x43e — unproven
  void* m440;             // 0x440 — 0 (0x6e395c)
  uint8_t m448[0x30];     // 0x448 — member ctor 0x66a2a4(this+0x448) (0x6e3968)
  uint8_t m478[0x30];     // 0x478 — 0 (0x6e3970-0x6e3984)
  void* mA8;              // 0x4a8 — vptr cell 0x130d910+0x10 (0x6e39b8)
  uint8_t m4B0[0x10];     // 0x4b0 — unproven
  void* m4C0;             // 0x4c0 — vptr cell 0x12fada0+0x10 (0x6e39bc, adjusted 0x6e39e8)
  void* m4C8;             // 0x4c8 — this+0x4d4 (0x6e39a4)
  uint32_t m4D0;          // 0x4d0 — 0x20 (0x6e39b4)
  uint8_t m4D4;           // 0x4d4 — byte copied from rodata (0x6e39e4)
  uint8_t mPad4D5[0x23];  // 0x4d5 — unproven
  void* m4F8;             // 0x4f8 — vptr cell 0x130d910+0x10 (0x6e39f8)
  void* m500;             // 0x500 — unproven
  uint8_t m508[0x8];      // 0x508 — unproven
  void* m510;             // 0x510 — vptr cell 0x12fada0+0x10 (0x6e3a00, adjusted 0x6e3a18)
  void* m518;             // 0x518 — this+0x524 (0x6e39fc)
  uint32_t m520;          // 0x520 — 0x20 (0x6e3a04)
  uint8_t m524;           // 0x524 — byte copied from rodata (0x6e3a14)
  uint8_t mPad525[0x23];  // 0x525 — unproven
  void* m548;             // 0x548 — 0 (0x6e3a28)
  void* m550;             // 0x550 — 0 (0x6e3a24)
  uint32_t m558;          // 0x558 — 0 (0x6e3a20)
  uint32_t m55C;          // 0x55c — unproven
  void* m560;             // 0x560 — 0 (0x6e3a1c); freed by D1 (0x6e3c30)
  uint8_t m568[0x11A8];   // 0x568 — unproven members: 0x66a2a4 at +0x568/+0x19f0/+0x1a20,
                          //        0x662f30 at +0x1758..+0x17b0, fills at +0x1710
  uint8_t m1710[0x18];    // 0x1710 — fill 0x7f.. (0x6e3a44-0x6e3a54)
  uint8_t m1728[0xB8];    // 0x1728 — unproven (members at +0x1758/+0x1770/+0x1778)
  void* m17E0;            // 0x17e0 — unproven
  uint8_t m17E8[0x208];   // 0x17e8 — unproven
  uint8_t m19F0[0x30];    // 0x19f0 — member ctor 0x66a2a4 (0x6e3ab8)
  uint8_t m1A20[0x30];    // 0x1a20 — member ctor 0x66a2a4 (0x6e3ac4)
  uint8_t m1A50[0x28];    // 0x1a50 — member ctor 0x662f30, vptr cell 0x130d9c8+0x10
                          //        (0x6e3ad0-0x6e3ae0)
  void* m1A78;            // 0x1a78 — vptr cell 0x130d9b8+0x10 (0x6e3b04)
  uint8_t m1A80[0x18];    // 0x1a80 — unproven
  void* m1A98;            // 0x1a98 — vptr cell 0x130daa0+0x10 (0x6e3b20)
  uint8_t m1AA0[0x18];    // 0x1aa0 — unproven
  void* m1AB8;            // 0x1ab8 — same vptr as +0x1a98 (0x6e3b30)
  uint8_t m1AC0[0x18];    // 0x1ac0 — unproven
  void* m1AD8;            // 0x1ad8 — vptr cell 0x130d9b8+0x10 (0x6e3b40)
  uint8_t m1AE0[0x18];    // 0x1ae0 — unproven
  void* m1AF8;            // 0x1af8 — vptr cell 0x130d9b8+0x10 (0x6e3b50)
  uint8_t m1B00[0x18];    // 0x1b00 — unproven
  void* m1B18;            // 0x1b18 — vptr cell 0x130d908+0x10 (0x6e3b6c)
  uint8_t m1B20[0x18];    // 0x1b20 — unproven
  void* m1B38;            // 0x1b38 — vptr cell 0x130d9c0+0x10 (0x6e3b94)
  uint8_t m1B40[0x10];    // 0x1b40 — unproven
  uint32_t m1B50;         // 0x1b50 — *0x12fce50 (0x6e3b98)
  uint32_t m1B54;         // 0x1b54 — same value (0x6e3ba0)
  uint32_t m1B58;         // 0x1b58 — same value (0x6e3ba4)
  uint32_t m1B5C;         // 0x1b5c — *0x12fce10 (0x6e3bb0)
  void* m1B60;            // 0x1b60 — vptr cell 0x130d908+0x10 (0x6e3bc0)
  void* m1B68;            // 0x1b68 — unproven
  uint8_t m1B70[0x10];    // 0x1b70 — unproven
  void* m1B80;            // 0x1b80 — vptr cell 0x130d9b8+0x10 (0x6e3bd0)
  void* m1B88;            // 0x1b88 — unproven
  uint8_t m1B90[0x10];    // 0x1b90 — unproven
  void* m1BA0;            // 0x1ba0 — vptr cell 0x130d9b8+0x10 (0x6e3bd8)
  uint32_t m1BA8;         // 0x1ba8 — unproven
  uint32_t m1BAC;         // 0x1bac — unproven
  uint32_t m1BB0;         // 0x1bb0 — unproven
  uint32_t m1BB4;         // 0x1bb4 — unproven
  uint32_t m1BB8;         // 0x1bb8 — unproven
  uint32_t m1BBC;         // 0x1bbc — unproven
  uint32_t m1BC0;         // 0x1bc0 — 0 (0x6e3bdc); count of the +0x1bc8 array
  uint8_t m1BC4[0x4];     // 0x1bc4 — unproven
  void* m1BC8;            // 0x1bc8 — 0; 0x8d0-stride element array, freed by D1
                          //        (0x6e3c80-0x6e3d04, sub-vptr cells 0x130d830/0x130d918)
  uint32_t m1BD0;         // 0x1bd0 — 0 (0x6e3be4)
  uint32_t m1BD4;         // 0x1bd4 — unproven
  void* m1BD8;            // 0x1bd8 — 0 (0x6e3be8); 0x68-stride element array, freed by D1
                          //        (0x6e3d10-0x6e3d40)
  uint32_t m1BE0;         // 0x1be0 — 0 (0x6e3bec)
  uint32_t m1BE4;         // 0x1be4 — unproven
  void* m1BE8;            // 0x1be8 — 0 (0x6e3bf0); freed by D1 (0x6e3c54)
  uint8_t m1BF0[0];       // end — size 0x1bf0 (next Vt12b6af8 member ctor at +0x39c8)
};
}  // namespace object
