#pragma once

#include <cstdint>

// UserMessage (size 0xA8) — PROVISIONAL name from the "UserMessage" string
// (0xf15048) passed to base ctor 0x587544. Installed vptr is 0x12e5c30 (the
// 0x12e5c28 row is the typeinfo slot); cell 0x1314980 holds vt-0x10.
// extent 0xA8 - details: doc/object/UserMessage.md

struct UserMessage {
  uint8_t pad00[0x48];                   //0x00 — base object (ctor 0x587544), unmapped
  uint16_t field48;                      //0x48 — 0
  uint8_t pad4a[0x6];                    //0x4a — padding to +0x50
  uint64_t field50;                      //0x50 — 0
  uint8_t pad58[0x8];                    //0x58 — padding to +0x60
  uint32_t field60;                      //0x60 — flags, init 9; OR-setter 0xa2a6b8
  uint8_t pad64[0x4];                    //0x64 — padding after flags word
  uint64_t field68;                      //0x68 — 0
  uint8_t field70;                       //0x70 — 0
  uint8_t pad71[0x7];                    //0x71 — padding after flag byte
  uint64_t field78;                      //0x78 — 0
  uint32_t field80;                      //0x80 — 0
  uint8_t pad84[0x4];                    //0x84 — padding before +0x88
  uint64_t node88;                       //0x88 — this+0x90 (self-pointer)
  uint64_t node90;                       //0x90 — 0 (dtor 0xa30890 target)
  uint64_t field98;                      //0x98 — ctor x20 param
  uint8_t pada0[0x8];                    //0xa0 — tail padding to 0xa8 (new size)
};
