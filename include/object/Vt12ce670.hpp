#pragma once

#include <cstdint>

// Vt12ce670 — interface row of a stub family sibling to Vt12ce1c8: 8-slot
// abstract table (never installed), 2-slot stub row 0x12ce6c0, concrete
// row 0x12ce6e0 (2 slots) built by the 0x10-byte proxy factory FUN_7100856444.
// extent 0x10 - details: doc/object/Vt12ce670.md

namespace object {
class Vt12ce670 {
 public:
  void* vtable;  // 0x00 — vptr 0x12ce6c0 (2 slots), written last
                 //        by FUN_7100856444 (0x8564f8); 0x12ce6e0 is
                 //        stored transiently (0x8564e4)
  void* mOwner;  // 0x08 — saved owner pointer (stp x9,x8,[x0],
                 //        0x8564f8); unverified semantics
};
}  // namespace object
