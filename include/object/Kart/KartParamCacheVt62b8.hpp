#pragma once

#include <cstdint>

namespace object {
// KartParamCacheVt62b8 — address-anchored name (vptr 0x12b62b8, SECONDARY
// interface row of a class whose primary vptr is 0x12b6278 at +0x00; the
// secondary sits at +0xf0). Size 0x5b0 (factory 0x71006a8cc8 -> alloc via
// 0x710069ea94). C1 0x71006a8ddc.
// extent 0x5b0 - details: doc/object/Kart/KartParamCacheVt62b8.md
class KartParamCacheVt62b8 {
 public:
  void* vptr;               // 0x00 — primary 0x12b6278 (cell 0x130dfa0 + 0x10)
  uint8_t mOwn8[0xe8];      // 0x08 — own-field region
  void* vptrF0;             // 0xf0 — secondary 0x12b62b8 (cell + 0x50);
                            // replaced by cell 0x130d848 + 0x10 in the dtor
                            // path (0x6a92c0)
  uint8_t mOwnf8[0x1d8];    // 0xf8 — own-field region
  char mMember2d0[0x28];    // 0x2d0 — member destroyed via 0x710060b984
  uint8_t mZero2f8[0x8];    // 0x2f8 — member ctor 0x7100629c08
  uint8_t mMem300[0x58];    // 0x300 — memcpy 0x30 from global [0x12fb188]
                            // (0x6a8e58-0x6a8e68); tail unproven
  uint8_t mMember358[0xd8]; // 0x358 — member ctor 0x710062bf28
  char mMember430[0x30];    // 0x430 — vptr from cell 0x130d920 (0x6a92a4)
  uint8_t mFan460[0x130];   // 0x460 — vptr fan from cell 0x130d918 into
                            // 0x460/0x480/0x4a0/0x4c0/0x4e0/0x500/0x528/
                            // 0x548/0x568/0x588 (0x6a926c-0x6a9294)
  uint8_t mPad590[0x20];    // 0x590 — unproven padding (to 0x5b0)
};
}  // namespace object
