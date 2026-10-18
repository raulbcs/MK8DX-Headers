#pragma once

#include <cstdint>

// Vt12c13d8 — placeholder name (theme unproven; stream-parse object family,
// slot2 0x756940 shared with Vt12c17a0/Vt12c2a40/Vt12c26e8). C1 0x754a50,
// vptr 0x12c13d8 at +0x00. Trivial dtor pair (D1 ret, D0 operator delete).
// extent 0xe8 - details: doc/object/Vt12c13d8.md

namespace object {
class Vt12c13d8 {
 public:
  void* mVtable;        // 0x00 — vptr 0x12c13d8 (C1 0x754bcc-0x754bd0, overwrites
                        //         the base-class vptr from 0x754aa8/0x754afc)
  uint8_t m8[0x58];     // 0x08 — parse base: member 0x61c9bc(this+0x08, this+0x18);
                        //         0x20 buffer ptr (self+0x2c base, 0x754a8c),
                        //         0x28 = this+0x2c, 0x2c u32 = 0x20 (0x754abc);
                        //         delimiter search against byte cell 0x12fada8
  uint8_t m60[0x10];    // 0x60 — floats 0.0f / 1.0f (0x754be0); u32 @0x60 read by
                        //         the tail switch (0x754c68)
  uint32_t m70;         // 0x70 — 1.0f (0x754bdc)
  uint32_t m74;         // 0x74 — 0.5f
  uint32_t m78;         // 0x78 — 0
  uint32_t m7c;         // 0x7c — 0x7f7fffff (FLT_MAX, 0x754c50), recomputed at end
  uint16_t m80;         // 0x80 — 0
  uint8_t mPad82[0x2];  // 0x82 — unproven
  uint32_t m84;         // 0x84 — 200.0f (0x43480000, 0x754bec)
  uint32_t m88;         // 0x88 — 300.0f (0x43960000)
  uint32_t m8c;         // 0x8c — 100.0f (0x42c80000)
  uint32_t m90;         // 0x90 — 800.0f (0x44480000)
  uint32_t m94;         // 0x94 — 10.0f (0x41200000, 0x754c00)
  uint32_t m98;         // 0x98 — 0.1f (0x3dcccccd, 0x754c08)
  uint32_t m9c;         // 0x9c — 0.1f again (0x754c10)
  double ma0;           // 0xa0 — 200.0 (0x40a0000000000000 with low 0x80,
                        //        0x754c1c-0x754c24)
  void* ma8;            // 0xa8 — rodata ptr cell 0x12fadb8+0x0 (0x754c54)
  void* mb0;            // 0xb0 — rodata ptr cell 0x12fadb8+0x8 (0x754c2c)
  uint32_t mb8;         // 0xb8 — 0.1f (0x754c34)
  uint32_t mbc;         // 0xbc — 0.1f
  uint32_t mc0;         // 0xc0 — 0.1f
  uint32_t mc4;         // 0xc4 — 0.5f
  void* mc8;            // 0xc8 — 0
  uint32_t md0;         // 0xd0 — 0
  uint8_t md4;          // 0xd4 — 1
  uint8_t md5;          // 0xd5 — 1
  uint8_t md6;          // 0xd6 — 1
  uint8_t mPadD7;       // 0xd7 — unproven
  uint32_t md8;         // 0xd8 — 0.1f (0x754c40)
  uint32_t mdc;         // 0xdc — 0
  uint64_t me0;         // 0xe0 — byte 0 at 0xe0 (0x754c64), tail to extent
};
}  // namespace object
