#pragma once

#include <cstdint>

// Vt12d2d38 — PLACEHOLDER name; 6-slot secondary hook-band vtable at owner+0x30;
// offset-to-top -0xD0; D1/D0 thunks 0x890730/0x8907B8 restore primary 0x12D2C40.
// extent 0x8 - vptr-only band row; owner >= 0x5D8 - details: doc/object/Vt12d2d38.md

namespace object {
class Vt12d2d38 {
 public:
  void* mVtable;  // 0x00 — 0x12d2d38 (band of the class with primary 0x12d2c40)
};
}  // namespace object
