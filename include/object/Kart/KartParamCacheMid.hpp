#pragma once

#include <cstdint>
#include <object/Kart/KartParamCache.hpp>

// KartParamCacheMid — address-anchored name (vptr 0x12b3478,
// extent 0x110
namespace object::Kart {
class KartParamCacheMid : public KartParamCache {
 public:
  uint8_t pad40[8];      // 0x40 — unproven padding
  uint64_t mZero48;      // 0x48 — ctor zero
  uint64_t mZero50;      // 0x50 — ctor zero
  void* mSelf58;         // 0x58 — ctor stores this; 0x60 zero
  void* mZero60;         // 0x60
  char mSub68[0x30];     // 0x68 — embedded member (ctor 0x710066a2a4)
  uint64_t mZero98;      // 0x98 — ctor zero
  uint64_t mZeroA0;      // 0xa0 — ctor zero
  uint32_t mIdA8;        // 0xa8 — ctor arg w1
  uint32_t mIdAc;        // 0xac — ctor: (w1<<8)+0x100+(w2+1)
  char mChanB0[0x20];    // 0xb0 — channel-pair member (cells 0x130d908;
  char mChanD0[0x20];    // 0xd0 — channel-pair member (flag byte at 0xe8)
  char mChanF0[0x18];    // 0xf0 — channel-pair member (to 0x108)
  int32_t mFffF108;      // 0x108 — ctor sets -1
  uint8_t mPad10C[0x4];  // 0x10C — unproven gap
};
}  // namespace object
