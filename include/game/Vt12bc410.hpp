#pragma once

#include <cstdint>

// Vt12bc410 — placeholder name; secondary vptr 0x12bc410 (offset-to-top
// -0x30) of ParamContainerVtc338 (primary 0x12bc338, cell 0x130e660).
// extent 0x370 EXACT (factory 0x712c7c, operator new(0x370, 8)) -
// details: doc/game/Vt12bc410.md

namespace object {
class Vt12bc410 {
 public:
  void* mVtable;           // 0x00 — primary vptr 0x12bc338 (cell 0x130e660 +0x10)
  uint8_t mPad8[0x28];     // 0x08 — unproven gap (pre-secondary-base)
  void* mVtable2;          // 0x30 — secondary vptr 0x12bc410 (cell +0xe8)
  uint8_t mPad38[0x2f8];   // 0x38 — unproven body region
  void* mVtable3;          // 0x330 — third vptr 0x12bc450 (cell +0x128, off-top -0x330)
  uint8_t mPad338[0x28];   // 0x338 — factory-zeroed region (0x338-0x350)
  uint8_t mPad360[0x2];    // 0x360 — u16, factory writes 0xffff
  uint8_t mPad362[0x2];    // 0x362 — unproven gap
  uint8_t mPad364[0x4];    // 0x364 — u32, factory zero
  uint8_t mPad368[0x4];    // 0x368 — unproven gap
  uint8_t mPad36c[0x2];    // 0x36c — u16 mask, factory writes 0xffff
  uint8_t mPad36e[0x2];    // 0x36e — u16, factory zero
                           // (0x370 total, factory alloc)
};

}  // namespace object
