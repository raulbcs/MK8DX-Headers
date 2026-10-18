#pragma once

#include <cstdint>

// sead::SharcArchiveRes — base-class vtable row 0x12f2740 (offset-to-top row
// 0x12f2730 = 0, RTTI slot NULL); GOT cell 0x1315128 = vptr-0x10. Base C1 of the
// game subclass object::Vt12d63c0. extent 0x54 (lower bound) - details: doc/object/Vt12f2740.md

namespace object {
class Vt12f2740 {
 public:
  void* mVtable;        // 0x00 — 0x12f2740 (14 slots)
  uint8_t mPad8[0x10];  // 0x08 — Resource/DirectResource body (unproven)
  void* m18;            // 0x18 — 0 (0xa877ec base C1 0x6232fc region)
  uint8_t mPad20[0x8];  // 0x20 — unproven
  void* m28;            // 0x28 — 0 (SharcArchiveRes::mArchiveBlockHeader)
  void* m30;            // 0x30 — 0 (mFATBlockHeader)
  void* m38;            // 0x38 — 0 (mFATEntrys count/base, cleared 0xa877fc)
  void* m40;            // 0x40 — 0 (mFNTBlock / mDataBlock, cleared 0xa87814)
  void* m48;            // 0x48 — 0
  uint32_t m50;         // 0x50 — 1 (0xa87818)
};
}  // namespace object
