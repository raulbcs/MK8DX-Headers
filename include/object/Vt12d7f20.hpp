#pragma once

#include <cstdint>

namespace object {
// Vt12d7f20 — PLACEHOLDER name (identity not proven); large game class whose
// vptr is re-installed by a derived C2 (0x921f78) after the base C1 runs.
// vptr 0x12d7f20 (GOT cell 0x1312428 holds vt-0x10, row header zeros). C1
// embeds member subobjects with own vptrs at +0x10 and +0x58 and repeats a
// 0x50-stride record block three times (+0x50, +0x184, +0x20c).
// extent 0x408 - details: doc/object/Vt12d7f20.md
class Vt12d7f20 {
 public:
  void* vtable;            // 0x00 — 0x12d7f20 (cell 0x1312428 + 0x10)
  uint8_t mByte8;          // 0x08 — C1 zeroes
  uint8_t mByte9;          // 0x09 — C1 zeroes; = 1 << flag when x1 flag nonzero
  uint8_t mPadA[6];        // 0x0a — unproven gap (mPadA: no ctor stores)
  void* mSub10;            // 0x10 — embedded subobject vptr (cell 0x1310c68 + 0x10)
  uint8_t mByte18;         // 0x18 — C1 zeroes
  uint8_t mPad19[3];       // 0x19 — unproven gap
  uint32_t mF1c;           // 0x1c — C1 zeroes
  uint8_t mByte20;         // 0x20 — C1 zeroes
  uint8_t mPad21[7];       // 0x21 — unproven gap to 0x28
  uint8_t mByte28;         // 0x28 — C1 zeroes
  uint8_t mPad29[7];       // 0x29 — unproven gap to 0x30
  void* mPtr30;            // 0x30 — derived C2 stores a new 0x10-byte object (0x921fb8)
  void* mPtr38;            // 0x38 — C1 stores a 0x290-relative pointer
  uint8_t mBlock40[0x10];  // 0x40 — C1 zeroes
  uint16_t mW50;           // 0x50 — C1 zeroes (record head u16, 0x911cb0)
  uint8_t mPad52[6];       // 0x52 — unproven gap to 0x58
  void* mSub58;            // 0x58 — embedded subobject vptr (cell 0x13123d8 + 0x10);
                           //   record: +0x68 = 0x50, tail byte 0xff at +0xc8
  uint8_t mRec60[0x11c];   // 0x60 — record block to +0x17c (0x51-byte memset
                           //   at 0x911cbc; +0xc8 = 0xff, +0xf0 = 0x50)
  uint32_t mF17c;          // 0x17c — C1 zeroes
  uint32_t mF180;          // 0x180 — C1 zeroes
  uint8_t mRec184[0x80];   // 0x184 — second record block (0x51-byte memset, 0x911cf4)
  uint8_t mRec204[8];      // 0x204 — C1 zeroes (tail of second block to +0x20c)
  uint8_t mRec20c[0x7c];   // 0x20c — third record block (0x911d20); +0x1d8 = 0xff
  uint16_t mW288;          // 0x288 — C1 zeroes (0x911d70)
  uint8_t mPad28a[6];      // 0x28a — unproven gap to 0x290
  uint8_t mByte290;        // 0x290 — start of last embedded member (subobject
                           //   init at 0x911d4c); exact tail size unproven
  uint8_t mPad291[0x177];  // 0x291 — unproven gap to the 0x408 factory size
};
}  // namespace object
