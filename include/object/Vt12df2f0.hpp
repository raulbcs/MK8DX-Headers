#pragma once

#include <cstdint>

// Vt12df2f0 — pooled record element (vptr 0x12df2f8, 5 slots, GOT cell 0x1313c08 holds vptr-0x10).
// Allocated as arrays of fixed-size elements with the object at element+0x10 (FUN_71009af864).
// extent 0x5a0 (lower bound; a 0x10-byte element header precedes the object, exact size unverified) -
// details: doc/object/Vt12df2f0.md

namespace object {
class Vt12df2f0 {
 public:
  void* mVtable;          // 0x00 — 0x12df2f8 (installed per element at 0x9afc74/0x9afcb8/0x9affa0)
  uint8_t mPad8[0x598];   // 0x08 — unproven padding; a 0x10-byte zero-memmed element header
                          //        precedes the object (not part of this struct)
};
}  // namespace object
