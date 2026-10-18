#pragma once

#include <cstdint>

// PROVISIONAL (no RTTI: typeinfo slot 0x12f7070 -> 0x12f7220 is not a
// typeinfo struct). Sibling of the nn::nex _DDL_DataStore* classes; shares
// base ctor 0xa27e78 and slots 2-23. extent 0x90 - details: doc/object/Vt12f7070.md

namespace object {
class Vt12f7070 {
 public:
  void* vtable;             // 0x00 — 0x12f7078 (cell 0x1315d98 + 0x10)
  uint8_t mPad08[0x40];     // 0x08 — unproven gap
  uint16_t mField48;        // 0x48 — u16 read back by ctor 0xb33d54
  uint8_t mPad4a[0x6];      // 0x4a — unproven padding
  uint32_t mField50[4];     // 0x50 — zeroed by base ctor 0xa27e78
  uint32_t mField60;        // 0x60 — u32 ctor param (base ctor)
  uint8_t mPad64[0xc];      // 0x64 — zeroed (base ctor)
  uint8_t mField70;         // 0x70 — zeroed (base ctor)
  uint8_t mPad71[0x7];      // 0x71 — unproven padding
  void* mField78;           // 0x78 — zeroed (base ctor)
  uint32_t mField80;        // 0x80 — zeroed (base ctor)
  uint8_t mPad84[0x4];      // 0x84 — unproven padding
  void* mField88;           // 0x88 — refcounted member released by slot0
                            // 0x90 (alloc size at virtual-new 0xb38b40)
};
}  // namespace object
