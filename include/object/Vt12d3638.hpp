#pragma once

#include <cstdint>

// PROVISIONAL (no RTTI: typeinfo slot zero). Secondary-base interface
// (vptr at +0x270) of a 0x9a50-byte manager object (primary vptr 0x12d3598,
// own header). Whole-object extent 0x9a50 - details: doc/object/Vt12d3638.md

namespace object {
class Vt12d3638 {
 public:
  void* vtable;                // 0x00 — PRIMARY vptr 0x12d3598 (cell
                               //   0x13117e0 + 0x10); secondaries 0x12d3698 at
                               //   +0x108, 0x12d3708 at +0x1a0, 0x12d3778 at
                               //   +0x208 (same C1 0x89bad4)
  uint8_t mBody08[0x268];      // 0x08..0x26f — manager body (see doc)
  void* mIfaceVptr;            // 0x270 — THIS vtable's vptr 0x12d3638 (cell
                               //   0x1311800 + 0x10, store 0x89bce4)
  uint8_t mIfaceBody278[0x8];  // 0x278 — interface body start
  uint8_t mTail280[0x97d0];    // 0x280..0x9a4f — manager tail (doc)
};
}  // namespace object
