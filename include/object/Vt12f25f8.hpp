#pragma once

#include <cstdint>

// Vt12f25f8 - PLACEHOLDER name; 27-slot intrusive-list/container node
// (self-pointing +0xd8 head pair, +0xf8 element array, +0x100 count);
// in-place init 0xa8596c (this = x1 argument). No static ctor.
// extent 0x108 (lower bound) - details: doc/object/Vt12f25f8.md
namespace object {
class Vt12f25f8 {
 public:
  void* mVtable;        // 0x000 - 0x12f25f8 (cell 0x13150b8, +0x10)
  uint8_t mPad8[0xd0];  // 0x008 - built by init 0xa8596c / 0x618fc4
  void* mListD8;        // 0xd8 - self-pointing sentinel pair head
  void* mListE0;        // 0xe0 - (both set to this+0xd8)
  uint32_t mWE8;        // 0xe8 - 0
  uint8_t mPadEc[4];    // 0xec - unproven padding
  uint32_t mWF0;        // 0xf0 - 0
  uint8_t mPadF4[4];    // 0xf4 - unproven padding
  void** mElemsF8;      // 0xf8 - element pointer array
  uint32_t mCount100;   // 0x100 - element count
  uint8_t pad104[4];    // 0x104 - unproven gap
                        // (0x108 total, lower bound; tail unmapped)
};
}  // namespace object
