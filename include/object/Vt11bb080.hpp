#pragma once

#include <cstdint>

namespace object {
// Vt11bb080 — PLACEHOLDER name (theme unproven). vptr 0x11bb080, n=29,
// typeinfo NULL (game-side), offset-to-top -8 (secondary-base table of a
// multiple-inheritance class).
//
// All 29 slots are accessor thunks of one shape: load the node pointer at
// [this+0x8] or [this+0x10], take the owner at +0x48, tail-jump into the
// shared implementation cluster 0x13c924-0x13cd00 (slots 0x192264
// .. 0x19383c). Interface-like table rather than a polymorphic family.
//
// Sole code materialization 0x196900 inside the static initializer
// FUN_7100196728, which builds a .bss registry at 0x1320e00: float config
// words at +0x00..+0x10, neighbor tables 0x11bb1d8/0x11bb210 at +0x88/
// +0x90, and this vptr (page 0x11bb000 + 0x80) at the sub-object +0x188.
//
// .data-adjacent to the mapped gear::Race list-item/director vtables
// (0x11b93f8 RaceDirectorVt9, 0x11b9650 RaceListItemG) but no family
// link is proven — placement by neighborhood only.
class Vt11bb080 {
 public:
  void* vtable;   // 0x00 — 0x11bb080
  void* mNode08;  // 0x08 — node ptr read by every thunk
  void* mNode10;  // 0x10 — alternate node ptr read by odd slots
                  // (extent unproven)
};
}  // namespace object
