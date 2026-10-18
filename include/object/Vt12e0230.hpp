#pragma once

#include <cstdint>

// object::Vt12e0230 — PLACEHOLDER name; pooled 0xbe0 record objects (copy ctor
// clones a 0x480 record and six sub-objects). vptr 0x12e0238 (typeinfo-row vtable;
// assigned row 0x12e0230), GOT cell 0x1313d60 holds vptr-0x10.
// extent 0xbe0 - details: doc/object/Vt12e0230.md

namespace object {
class Vt12e0230 {
 public:
  void* vtable;        // 0x00 — 0x12e0238, installed by C1 0x9c1a80
  char mPad8[0x8];     // 0x08 — unproven gap before the secondary subobject at +0x10
  void* mSubVptr;      // 0x10 — secondary vptr 0x12e01b8 (GOT cell 0x1313d50), subobject at +0x10
  char mRecord18[0x480];  // 0x18 — 0x480-byte record, memset by C1 (0x9c1acc)
  char mElems498[0x5c0];  // 0x498 — 8 x 0xb8 elements with vptr 0x12e0308 (C1 loop 0x9c1afc; D2 destroys each)
  char mPada58[0x188]; // 0xa58 — unproven padding to 0xbe0
};
}  // namespace object
