#pragma once

#include <cstdint>

// Vt12cc270 — PLACEHOLDER name; vptr 0x12cc270 via GOT cell 0x1310938 (holds
// vt-0x10, no typeinfo); large multi-vptr manager (secondaries at +0x50/+0x60,
// ctor builds UTF-16 TestMario/TestLuigi records in its callers).
// extent 0x3f0 (new 0x3f0 at 0x82fa44) - details: doc/object/Vt12cc270.md
namespace object {
class Vt12cc270 {
 public:
  void* mVtable;            // 0x00 — 0x12cc270 (cell 0x1310938 + 0x10)
  uint8_t mPad8[0x24];      // 0x08 — unproven padding
  uint64_t mZero2c[4];      // 0x2c..0x4c — stur xzr at 0x24/0x2c/0x34/0x3c/0x44 (ctor)
  uint32_t mZero4c;         // 0x4c — zeroed
  void* mVtable50;          // 0x50 — secondary 0x12cc240 (cell 0x13098f0 + 0x10)
  uint8_t mGap58[8];        // 0x58 — unproven gap
  void* mVtable60;          // 0x60 — secondary 0x12cc200 (cell 0x1309908 + 0x10)
  uint8_t mGap68[8];        // 0x68 — unproven gap
  uint32_t mZero70;         // 0x70 — zeroed
  uint8_t mGap74[4];        // 0x74 — unproven gap
  void* mVtable78;          // 0x78 — copy of secondary 0x12cc200
  uint8_t mGap80[8];        // 0x80 — unproven gap
  void* mVtable88;          // 0x88 — copy of secondary 0x12cc200
  void* mRec90;             // 0x90 — record walker anchor
  void* mVtable98;          // 0x98 — [cell 0x1307000+0xd8]+0x10 (rodata 0xf57d32)
  void* mSelfA0;            // 0xa0 — &this+0xac
  uint32_t mValA8;          // 0xa8 — 0x15
  uint8_t mGapAc[0x2c];     // 0xac — unproven gap (record at 0x98..0xd8 walker)
  uint8_t mBlobD8[0x20];    // 0xd8 — sub-record (vptr cell + u16 hws + 0xe8=0x1c)
  uint8_t mGapF8[0x30];     // 0xf8 — unproven gap (record 0x128/0x13c, val 0xd)
  uint8_t mBlob128[0x30];   // 0x128 — sub-record (same shape)
  uint8_t mGap158[0x30];    // 0x158 — unproven gap
  uint32_t mZero188;        // 0x188 — zeroed
  uint8_t mGap18c[0x14];    // 0x18c — unproven gap
  void* mField1a0;          // 0x1a0 — member ptr (ctor 0x82f9c4)
  uint8_t mGap1a8[8];       // 0x1a8 — unproven gap
  void* mZero1b0;           // 0x1b0 — zeroed
  uint8_t mRest1b8[0x238];  // 0x1b8 — unproven padding (ctor call 0x630f64 at +0x3cc)
};
}  // namespace object
