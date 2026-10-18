#pragma once

#include <cstdint>

// Vt12d2a80 — PLACEHOLDER name; 6-slot secondary hook-band vtable installed at
// owner+0x30 by factory 0x88E8DC; offset-to-top -0xD0; forwarders 0x648094.
// extent 0x8 - vptr-only band row; owner is 0x340 bytes - details: doc/object/Vt12d2a80.md

namespace object {
class Vt12d2a80 {
 public:
  void* mVtable;  // 0x00 — 0x12d2a80 (band of the 0x340-byte owner class)
};
}  // namespace object
