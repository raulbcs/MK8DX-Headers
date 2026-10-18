#pragma once

#include <cstdint>

// Vt12dcaf0 — PLACEHOLDER name; 5-slot primary row 0x12dcaf8 (typeinfo-slot
// row 0x12dcaf0) + secondary -0x18 row 0x12dcb30 at this+0x18; owner size 0x58.
// extent 0x58 - details: doc/object/Vt12dcaf0.md

namespace object {
class Vt12dcaf0 {
 public:
  void* mVtable;        // 0x00 — 0x12dcaf8 (GOT cell 0x1313410 holds 0x12dcae8 = row-0x8)
  uint8_t mFlags8;      // 0x08 — byte flag read by slot 0x9752e4
  uint8_t mPad[0xF];    // 0x09 — pad to secondary vptr (unverified contents)
  void* mVtableSec;     // 0x18 — 0x12dcb30 (secondary, offset-to-top -0x18)
  void* mSub0;          // 0x20 — 4 subobjects ctor'd by 0x929fd4 / dtor'd by 0x92a014
  void* mSub1;          // 0x28
  void* mSub2;          // 0x30
  void* mSub3;          // 0x38
  void* mPtr40;         // 0x40 — cleared by dtors; slot 0x9752d8 stores arg here
  uint8_t mByte48;      // 0x48
  uint8_t mPad49[0x7];  // 0x49 — pad to +0x50 pointer (unverified contents)
  void* mPtr50;         // 0x50 — deref'd by slot 0x9752e4
};
}  // namespace object
