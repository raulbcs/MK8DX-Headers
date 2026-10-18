#pragma once

#include <cstdint>

namespace object {
// Vt12c2408 — PLACEHOLDER name; no RTTI (typeinfo slot 0). vptr 0x12c2408
// (GOT cell 0x130f400 holds vt-0x10), secondary vptr 0x12c24a8 at +0x160;
// 18 slots. size 0x178 proven (new 0x178 at 0x7502e4 and 0x775788).
// extent 0x178 - details: doc/object/Vt12c2408.md
class Vt12c2408 {
 public:
  void* vtable;          // 0x00 — 0x12c2408 (cell 0x130f400 + 0x10)
  uint8_t mPad08[0x10];  // 0x08 — ctor 0x7749d4 zeroes (stp xzr,xzr [x0,#8])
  uint8_t mSub18;  // 0x18 — subobject init by call 0x5f12b8 (size unknown)
  uint8_t mPad19[0x6f];   // 0x19 — unproven gap
  uint32_t mField88;      // 0x88 — ctor zeroes
  uint32_t mF8c;          // 0x8c — ctor sets 1
  uint32_t mF90;          // 0x90 — ctor sets 1
  uint8_t mByte94;        // 0x94 — ctor sets 1
  uint8_t mPad95[3];      // 0x95 — unproven gap
  uint8_t mSub98;         // 0x98 — subobject init 0x628628, D2 0x6286a4
  uint8_t mPad99[0x43];   // 0x99 — unproven gap
  uint8_t mPadDC[0x1c];   // 0xdc — ctor zeroes (stur xzr 0xdc/0xe4/0xe9)
  void* mSelfF8;          // 0xf8 — ctor stores this+0xf8 (self pointer)
  void* mSelf100;         // 0x100 — ctor stores this+0xf8 (same value)
  uint32_t mField108;     // 0x108 — ctor zeroes
  uint32_t mField10c;     // 0x10c — ctor sets -1, then 8
  uint8_t mSub110;        // 0x110 — subobject init 0x628628, D2 0x6286a4
  uint8_t mPad111[0x3f];  // 0x111 — unproven gap
  void* mPtr150;          // 0x150 — ctor zeroes
  uint8_t mByte158;       // 0x158 — ctor zeroes; guard read by slot4 (0x774a8c)
  uint8_t mPad159[3];     // 0x159 — unproven gap
  uint32_t mSerial15c;    // 0x15c — ++global counter [cell 0x130d250]
  void* vtable2;          // 0x160 — 0x12c24a8 (cell 0x130f408 + 0x10; ret-stub
                          //   slots 0x775168/0x77516c/0x775170)
  uint32_t mField168;     // 0x168 — ctor zeroes
  uint8_t mPad16c[4];     // 0x16c — unproven gap
  uint8_t mByte170;       // 0x170 — ctor sets 1
  uint8_t mPad171[7];     // 0x171 — unproven tail
};
}  // namespace object
