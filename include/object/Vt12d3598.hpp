#pragma once

#include <cstdint>

// Vt12d3598 — 12-slot class built in place by FUN_71008911a0 (C1
// FUN_710089bad4). GOT cell 0x13117e0 holds vt-0x10; D1 thunk 0x89c988
// adjusts to FUN_71008a7764. Deepest C1 store +0x4848; size unproven beyond
// that (outer init writes to +0x4bd0+; lower bound).
// extent 0x484c - details: doc/object/Vt12d3598.md

namespace object {
class Vt12d3598 {
 public:
  void* mVtable;          // 0x00 — vptr 0x12d3598 (cell 0x13117e0+0x10, 0x89bb58-0x89bb60)
  uint8_t m8[0x10];       // 0x08 — written by D1 helper 0x8a77b4-0x8a77c4 (u32/u8/u32)
  void* m18;              // 0x18 — ptr, virtual-destroyed by D1 (0x8a777c-0x8a7798)
  uint8_t m20[0x8];       // 0x20 — unproven
  uint8_t m28;            // 0x28 — gate flag read by D1 (0x8a7784)
  uint8_t m29[0x37];      // 0x29 — unproven
  uint8_t m60;            // 0x60 — 0 (0x89bb4c)
  uint8_t m61[0x3];       // 0x61 — unproven
  uint32_t m64;           // 0x64 — 0 (0x89bb50)
  uint8_t m68[0x10];      // 0x68 — vptr cell 0x13117e8+0x10 at +0x70 (0x89bbc0 stp)
  uint32_t m78;           // 0x78 — w12 value (0x89bb68)
  uint32_t m7C;           // 0x7c — unproven
  uint32_t m80;           // 0x80 — 0 (0x89bb6c)
  uint8_t m84[0x4];       // 0x84 — unproven
  uint8_t m88[0xE];       // 0x88 — 0 (0x89bb8c stp)
  uint8_t m96;            // 0x96 — 0 (0x89bb70 stur)
  uint8_t m97[0x3];       // 0x97 — unproven
  uint8_t m9A;            // 0x9a — 0 (0x89bb74)
  uint8_t m9B[0x5];       // 0x9b — unproven
  uint8_t mA0[0x20];      // 0xa0 — stp pairs x9/x20 at +0xa0/+0xb0 (0x89bb90-0x89bb94)
  uint32_t mC0;           // 0xc0 — 0 (0x89bb78)
  uint8_t mC4;            // 0xc4 — 0 (0x89bb7c)
  uint8_t mC5[0x3];       // 0xc5 — unproven
  void* mC8;              // 0xc8 — 0 (0x89bb80)
  uint8_t mD0;            // 0xd0 — 0 (0x89bb84)
  uint8_t mD1[0x3];       // 0xd1 — unproven
  uint32_t mD4;           // 0xd4 — 0 (0x89bb88)
  void* mD8;              // 0xd8 — 0 (0x89bba0)
  uint32_t mE0;           // 0xe0 — 0 (0x89bba4)
  uint32_t mE4;           // 0xe4 — unproven
  void* mE8;              // 0xe8 — 0 (0x89bba8)
  uint32_t mF0;           // 0xf0 — 0 (0x89bbac)
  uint32_t mF4;           // 0xf4 — unproven
  void* mF8;              // 0xf8 — 0 (0x89bbb0)
  uint32_t m100;          // 0x100 — 0 (0x89bbb4)
  uint32_t m104;          // 0x104 — unproven
  void* m108;             // 0x108 — vptr cell 0x13117e8+0x10 (0x89bbc8)
  uint32_t m110;          // 0x110 — w12 value (0x89bbb8)
  uint32_t m114;          // 0x114 — unproven
  uint32_t m118;          // 0x118 — 0 (0x89bbbc)
  uint32_t m11C;          // 0x11c — unproven
  uint8_t m120[0xA6];     // 0x120 — unproven (+0x12e byte 0 at 0x89bbc4, +0x136 at 0x89bbd0)
  uint32_t m1C6;          // 0x1c6 — unproven window start
  uint8_t m1CA[0x8E];     // 0x1ca — unproven (+0x158 0 at 0x89bbd4, +0x15c/0x160/... to +0x188)
  uint8_t m258[0x90];     // 0x258 — unproven (+0x1f0/+0x1f4/+0x1f8/+0x200/+0x204
                          //        zeroed at 0x89bc20-0x89bc30)
  uint8_t m2E8[0x18];     // 0x2e8 — stores via x22 at +0x2e8/+0x2f0/+0x2f8
                          //        (0x89bd20-0x89bd28, +0x2f8 = 0x40)
  uint8_t m300[0x44A8];   // 0x300 — unproven (+0x2d0-window notes above aside, C1
                          //        writes +0x2d0/+0x2d8/+0x2e0 then jumps to +0x47a8)
  uint8_t m47A8[0xA4];    // 0x47a8 — vptr cell 0x1311808+0x10 at +0x47a8 (0x89bdd4);
                          //        +0x47c0..+0x484b zero/fill stores (0x89bd7c-0x89be04)
};
}  // namespace object
