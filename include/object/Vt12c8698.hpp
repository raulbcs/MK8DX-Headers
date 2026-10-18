#pragma once

#include <cstdint>

// PROVISIONAL (no RTTI: typeinfo slot zero). Pose holder: 3x4f matrix copied
// from identity static 0xf57ad0 plus settings vec3; base of the Vt12c8698
// family. extent 0x70 - details: doc/object/Vt12c8698.md

namespace object {
class Vt12c8698 {
 public:
  void* vtable;             // 0x00 — 0x12c8698 (cell 0x13100f8 + 0x10)
  void* mField08;           // 0x08 — zeroed; later holds an owner/config obj
                            //        read by slot10 0x7e092c ([x8+0x98])
  float mMatrix10[12];      // 0x10 — 3x4f, memcpy 0x30 from cell 0x12fb188
                            //        (0xf57ad0 = identity) 0x7e0874-0x7e0878
  void* mField40;           // 0x40 — zeroed
  uint32_t mField48;        // 0x48 — zeroed
  uint8_t mPad4c[0x14];     // 0x4c — zeroed (0x7e0888-0x7e0894)
  float mField60[3];        // 0x60 — vec3 copied from settings singleton
                            //        cell 0x12fb148 (0x7e0898-0x7e08a4)
  uint8_t mField6c;         // 0x6c — zeroed
  uint8_t mPad6d[0x3];      // 0x6d — unproven tail pad to 0x70
};
}  // namespace object
