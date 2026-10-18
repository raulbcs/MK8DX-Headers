#pragma once

#include <cstdint>

// Vt12b9ef8 — PLACEHOLDER name; vptr 0x12b9ef8, 8 slots, no typeinfo (game-side).
// Allocation/dispatch helper built on-stack; D1 re-links into a global registry list.
// extent 0x48 (lower bound; in-place instance stores reach +0x40) - details: doc/object/Vt12b9ef8.md

namespace object {
class Vt12b9ef8 {
 public:
  void* mVtable;          // 0x00 — 0x12b9ef8 (via GOT cell 0x130e280, holds vt-0x10)
  void* mF8;              // 0x08 — param pointer stored by caller (x21 at the 0x6d4858 site)
  uint8_t mPad10[0x30];   // 0x10 — padding, unproven
  uint32_t mF40;          // 0x40 — 4 at one call site (0x6d48ec)
  uint8_t mPad44[0x4];    // 0x44 — padding, rest of the word
};
}  // namespace object
