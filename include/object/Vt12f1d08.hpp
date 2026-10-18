#pragma once

#include <cstdint>

// object::Vt12f1d08 — PLACEHOLDER name; 0x20 forwarding adapter holding a delegate
// (nifm-area code). 19 of 21 slots forward to the delegate's vtable slots +0x10..+0x98.
// vptr 0x12f1d10 (typeinfo-row vtable; assigned row 0x12f1d08), GOT cell 0x1314fd0.
// extent 0x20 - details: doc/object/Vt12f1d08.md

namespace object {
class Vt12f1d08 {
 public:
  void* vtable;    // 0x00 — 0x12f1d10, installed by C1 0xa7ebfc
  void* mDelegate; // 0x08 — interface pointer; slot thunks do `ldr x0,[x0,#8]` then tail-call
  char mPad10[0x10];  // 0x10 — two words stored by C1 (stp x2,x3 at 0xa7ec08), unproven
};
}  // namespace object
