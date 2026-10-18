#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace gear {
// RaceDirector-family director base (slot 0x90 = RaceDirector::getRuntimeTypeInfo
// 0x7ef9e4; enter/calc/exit slots shared with gear::RaceDirector). Vtable
// .data 0x12c8ee0 via GOT cell 0x1310238 (holds vt-0x10, no typeinfo).
// extent 0x1a0 (new 0x1a0 at 0xcc8b0) - details: doc/gear/Race/RaceDirectorVt12c8ee0.md
class RaceDirectorVt12c8ee0 : public Actor {
 public:
  void* mObj70;            // 0x70 — new(0x10), {ptr 0x135bf00(+0x38 if mode==0x7a), this}
  void* mObj78;            // 0x78 — new(0x10), {ptr 0x135bf00(+0x1c/+0x54), this}
  void* mObj80;            // 0x80 — copy of mObj70
  void* mObj88;            // 0x88 — copy of mObj78
  uint64_t mPad90;         // 0x90 — zeroed by ctor
  void* mObj98;            // 0x98 — new(0x70), init 0x7c55cc(this, -1)
  uint64_t mRecA0;         // 0xa0 — [cell 0x12fb148] (rodata 0xf57b7c)
  uint32_t mRecA8;         // 0xa8 — [cell 0x12fb148 + 8]
  uint8_t mBlobAc[0x24];   // 0xac — memcpy 0x24 from [cell 0x12fd1c8] (0x135e218)
  uint64_t mRecD0;         // 0xd0 — [cell 0x12fb148]
  uint32_t mRecD8;         // 0xd8 — [cell 0x12fb148 + 8]
  uint8_t mBlobDc[0x24];   // 0xdc — memcpy 0x24 from [cell 0x12fd1c8]
  uint32_t mRec100;        // 0x100 — [cell 0x12fb148]
  uint32_t mRec104;        // 0x104 — [cell 0x12fb148 + 4]
  uint32_t mRec108;        // 0x108 — [cell 0x12fb148 + 8]
  uint8_t mBlob10c[0x24];  // 0x10c — memcpy 0x24 from [cell 0x12fd1c8]
  uint8_t mBlob130[0x24];  // 0x130 — memcpy 0x24 from [cell 0x12fd1c8]
  uint64_t mRec154;        // 0x154 — [cell 0x12fb148]
  uint32_t mZero15c;       // 0x15c — zeroed
  uint32_t mZero160;       // 0x160 — zeroed
  uint32_t mRec164;        // 0x164 — [cell 0x12fb148]
  uint32_t mRec168;        // 0x168 — [cell 0x12fb148 + 4]
  uint32_t mRec16c;        // 0x16c — [cell 0x12fb148 + 8]
  uint64_t mRec170;        // 0x170 — [cell 0x12fb148]
  uint32_t mRec178;        // 0x178 — [cell 0x12fb148 + 8]
  uint64_t mRec17c;        // 0x17c — [cell 0x12fb148]
  uint32_t mRec184;        // 0x184 — [cell 0x12fb148 + 8]
  uint64_t mRec188;        // 0x188 — [cell 0x12fb150] (rodata 0xf57b94)
  uint32_t mRec190;        // 0x190 — [cell 0x12fb150 + 8]
  uint32_t mZero194;       // 0x194 — zeroed
  uint8_t mZero198;        // 0x198 — zeroed
  uint8_t mGap199[3];      // 0x199 — unproven gap
  uint32_t mZero19c;       // 0x19c — zeroed
};
}  // namespace gear
