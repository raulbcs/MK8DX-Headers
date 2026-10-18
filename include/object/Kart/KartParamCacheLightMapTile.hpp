#pragma once

#include <cstdint>

// KartParamCacheLightMapTile — element (stride 0xad8) of the KartParamCacheLightMap
// pool at +0x1d8 (array-new 0x6794b0-0x6794c8, elem C1 0x6958c8); "tile" from the
// light-map slot-5 release-tile loop. vptr 0x12b5da0 at +0x00.
// extent 0xad8 - details: doc/object/Kart/KartParamCacheLightMapTile.md

namespace object {
class KartParamCacheLightMapTile {
 public:
  void* mVtable;        // 0x00 — primary vptr 0x12b5da0 (C1 0x6958f8-0x695900)
  uint8_t m8[0x30];     // 0x08 — base C1 0x64a708(this) at 0x6958e4; unproven
  void* m38;            // 0x38 — secondary vptr 0x12b5e08 = vt+0x68 (0x695908-0x695910)
  void* m40;            // 0x40 — secondary vptr 0x12b5e28 = vt+0x88
  uint8_t m48[0x120];   // 0x48 — unproven
  void* m168;           // 0x168 — 0 (0x6958f8)
  void* m170;           // 0x170 — 0
  uint32_t m178;        // 0x178 — 0 (0x6958f4)
  uint32_t mPad17c;     // 0x17c — unproven
  void* m180;           // 0x180 — 0 (0x6958e8)
  uint8_t m188[0x1c8];  // 0x188 — member C1 0x645410 (0x695914); unproven detail
  uint8_t m350[0x180];  // 0x350 — member C1 0x643fa0 (0x69591c); unproven detail
  uint8_t m4d0[0x310];  // 0x4d0 — inited table band: flag bytes (6 @0x4d0, 0xff
                        //        @0x4d4/0x4d5), 8x {2-u64 pair from rodata cell
                        //        0x1307cb8} + 8 float quads (-1.0f x3, 1.0f),
                        //        0x695980-0x695d04
  void* m7e0;           // 0x7e0 — ptr, 0 (0x695d04); D1 walks it with 0x170-stride
                        //        elements (0x695ed8-0x695f18)
  uint8_t m7e8[0x78];   // 0x7e8 — member C1 0x645934 (0x695d08); unproven detail
  uint32_t m860;        // 0x860 — 0 (0x695d10)
  uint32_t mPad864;     // 0x864 — unproven
  uint8_t m868[0x30];   // 0x868 — zero run (0x695d14-0x695d28)
  void* m898;           // 0x898 — subobject, vptr cell 0x130daa0+0x10 (0x695d2c-0x695d3c)
  uint8_t m8a0[0x158];  // 0x8a0 — member objects (C1 0x662f30 xN, 0x695d28-0x695dc8);
                        //        vptrs from cells 0x130d908/0x130d9b8/0x130d938/
                        //        0x130d910/0x130daa0; unproven detail
  uint32_t m9f8;        // 0x9f8 — 0 (0x695dac)
  uint32_t mPad9fc;     // 0x9fc — unproven
  uint8_t ma00[0xd8];   // 0xa00 — member objects (C1 0x662f30 xN, 0x695dc8-0x695e58):
                        //        +0xa18 vptr cell 0x130d910, +0xa30 pair vptr cell
                        //        0x12fada0 (ptr @0xa38, flag 0x20 @0xa40), +0xa68/
                        //        +0xa80 same pair shape, +0xab8 vptr cell 0x130daa0
                        //        (0x695e60); tail to pool stride 0xad8
};
}  // namespace object
