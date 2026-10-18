#pragma once

#include <cstdint>

namespace object {
// KartParamCacheVt3078 — address-anchored name; SECONDARY interface vtable
// 0x12b3078 (offset-to-top -0xd0, no RTTI), dtor pair 0x710064ec50/
// 0x710064ed78; primary vptr 0x12b2fa8 from GOT cell 0x130d9f8+0x10; links
// to the ColorCorrection param family (slots 0x7100650520/0x6506e0).
// extent 0x270 (proven lower bound) - details: doc/object/Kart/KartParamCacheVt3078.md
class KartParamCacheVt3078 {
 public:
  void* vptrPrimary;     // 0x00 — 0x12b2fa8 (cell 0x130d9f8 + 0x10)
  uint8_t pad08[0x28];   // 0x08 — unproven gap
  void* vptr30;          // 0x30 — secondary 0x12b3078 (cell + 0xd8)
  uint8_t pad38[0xd8];   // 0x38 — unproven gap
  void* mChan110;        // 0x110 — ChanBase vptr 0x12b3af0
  uint8_t pad118[0x20];  // 0x118 — unproven gap
  void* mChan138;        // 0x138 — ChanBase subobject vptr 0x12b3af0 (cell
  uint8_t pad140[0x20];  //   0x130d918 + 0x10); channel stride 0x28/0x20
  void* mChan160;        // 0x160 — ChanBase vptr 0x12b3af0
  uint8_t pad168[0x18];  // 0x168 — unproven gap
  void* mChan180;        // 0x180 — ChanBase vptr 0x12b3af0
  uint8_t pad188[0x18];  // 0x188 — unproven gap
  void* mChan1a0;        // 0x1a0 — ChanBase vptr 0x12b3af0
  uint8_t pad1a8[0x20];  // 0x1a8 — unproven gap
  void* mChan1c8;        // 0x1c8 — ChanBase vptr 0x12b3af0
  uint8_t pad1d0[0x20];  // 0x1d0 — unproven gap
  void* mChan1f0;        // 0x1f0 — ChanBase vptr 0x12b3af0
  uint8_t pad1f8[0x18];  // 0x1f8 — unproven gap
  void* mChan210;        // 0x210 — ChanBase vptr 0x12b3af0
  uint8_t pad218[0x18];  // 0x218 — unproven gap
  void* mChan230;        // 0x230 — ChanBase vptr 0x12b3af0
  void* mOwned238;       // 0x238 — owned ptr (pair counter 0x260, ptr
  uint8_t pad240[0x10];  //   0x268), deleted then cleared by D2
  uint32_t mCount250;    // 0x250 — cleared by D2
  uint8_t pad254[0x4];   // 0x254 — unproven gap
  void* mPtr258;         // 0x258 — owned ptr, deleted then cleared by D2
  uint32_t mCount260;    // 0x260 — cleared by D2
  uint8_t pad264[0x4];   // 0x264 — unproven gap
  void* mPtr268;         // 0x268 — cleared by D2
};
}  // namespace object
