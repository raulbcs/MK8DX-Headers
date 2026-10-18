#pragma once

#include <cstdint>

// Vt12d7ec8 — PLACEHOLDER name; 6-slot vtable of an embedded component installed
// at owner+0x28 by ~14 inlined ctor sites (e.g. 0x9104BC); cell 0x13123D8.
// extent 0x70 - lower bound (buffer at +0x1C spans 0x51 bytes) - details: doc/object/Vt12d7ec8.md

namespace object {
class Vt12d7ec8 {
 public:
  void* mVtable;         // 0x00 — 0x12d7ec8 (GOT cell 0x13123D8 holds vt-0x10)
  void* mSelfPtr08;      // 0x08 — set to this+0x1C by reset fn 0x9118A0
  uint32_t mField10;     // 0x10 — 0x50 at the 0x9104BC site
  uint8_t mPad14[8];     // 0x14 — zeroed at 0x910528/+0x14
  uint8_t mBuf1C[0x51];  // 0x1C — memset(0) 0x51 bytes (0x91055C); reset fn memsets same range
  uint8_t mPad6D[3];     // 0x6D — tail pad to cited extent
};
}  // namespace object
