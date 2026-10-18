#pragma once

#include <cstdint>

// Vt12bf768 — nn-band stub object adjacent to Vt12bf718 (init 0x73ea98),
// size 0x48 EXACT (operator new(0x48, 8) at 0x734b98). One 37-slot row;
// slots 12-36 are a shared 0x5a2xxx run repeated verbatim in the sibling
// row 0x12bf8a0. extent 0x48 - details: doc/game/Vt12bf768.md
namespace game {
class Vt12bf768 {
 public:
  void* mVtable;      // 0x00 - vptr 0x12bf768 (GOT cell 0x130eca8 holds
                      //   vptr-0x10 0x12bf758)
  void* m08;          // 0x08 - 0 (init)
  uint64_t m10;       // 0x10 - 0 (init)
  uint64_t m18;       // 0x18 - 0 (init); written by slot 4 as a pair with
                      //   +0x20 (stp x1,x2)
  uint64_t m20;       // 0x20 - 0 (init)
  uint64_t m28;       // 0x28 - 0 (init); slot 5 clears it when it matches
                      //   the searched pointer
  uint64_t m30;       // 0x30 - 0 (init); slot 5 clears on match
  uint64_t m38;       // 0x38 - 0 (init); slot 5 clears on match
  uint8_t m40[0x8];   // 0x40 - 0 (init, zero run to 0x47); slot 5 clears
                      //   on match
};
}  // namespace game
