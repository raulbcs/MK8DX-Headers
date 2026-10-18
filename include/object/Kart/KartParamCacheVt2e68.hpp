#pragma once

#include <cstdint>

namespace object {
// KartParamCacheVt2e68 — address-anchored name; SECONDARY interface vtable
// 0x12b2e68 (offset-to-top -0xd0, no RTTI) installed at [base+0x30] by the
// shared dtor pair 0x710064dc7c/0x710064dd64; primary vptr 0x12b2da0 comes
// from GOT cell 0x130d9e8+0x10.
// extent 0x200 (proven lower bound) - details: doc/object/Kart/KartParamCacheVt2e68.md
class KartParamCacheVt2e68 {
 public:
  void* vptrPrimary;     // 0x00 — 0x12b2da0 (cell 0x130d9e8 + 0x10)
  uint8_t pad08[0x28];   // 0x08 — unproven gap
  void* vptr30;          // 0x30 — secondary 0x12b2e68 (cell + 0xd8)
  uint8_t pad38[0xd8];   // 0x38 — unproven gap
  void* mChan110;        // 0x110 — ChanBase subobject vptr 0x12b3af0 (cell
  uint8_t pad118[0x20];  //   0x130d918 + 0x10); channel stride 0x28
  void* mChan138;        // 0x138 — ChanBase vptr 0x12b3af0
  uint8_t pad140[0x20];  // 0x140 — unproven gap
  void* mChan160;        // 0x160 — ChanBase vptr 0x12b3af0
  uint8_t pad168[0x20];  // 0x168 — unproven gap
  void* mChan188;        // 0x188 — ChanBase vptr 0x12b3af0
  uint8_t pad190[0x18];  // 0x190 — unproven gap (0x1b0 untouched by dtor)
  void* mChan1a8;        // 0x1a8 — ChanBase vptr 0x12b3af0
  uint8_t pad1b0[0x18];  // 0x1b0 — unproven gap
  void* mOwnedPtr1c8;    // 0x1c8 — owned ptr, deleted then cleared by D2
  void* mChan1d0;        // 0x1d0 — ChanBase vptr 0x12b3af0
  uint8_t pad1d8[0x18];  // 0x1d8 — unproven gap
  uint32_t mCount1f0;    // 0x1f0 — cleared by D2
  uint8_t pad1f4[0x4];   // 0x1f4 — unproven gap
  void* mPtr1f8;         // 0x1f8 — cleared by D2 after deleting mOwnedPtr1c8
};
}  // namespace object
