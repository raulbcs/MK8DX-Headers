#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt2b90 — address-anchored name (vptr 0x12b2b90, GOT cell
// 0x130da00 holds 0x12b2b80; stored vptr = cell+0x10 = 0x12b2b90). CLOSED AS
// PROVEN GAP (): semantic name not recoverable from the binary.
//
// Proven structure:
// - Node class of the 0x647f40 hook-band cluster (shared trivial band
// 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
// [this+0x1c]). No RTTI anywhere in the family (vtable[-8] == 0, like
// ParamNodeVt2ea8).
// - Secondary base at +0x30 of a composite class: offset-to-top -0x30
// entry at vt+0xb8 with its own D1/D0 pair 0x64f200/0x64f238 (this
// pre-adjusted by -0x30). Primary composite dtors: D2 0x64f044 (tail
// 0x6472c8), D1 0x64f074, D0 0x64f0c4 (+ operator delete).
// - The composite embeds a ParamNodeVtdba0 node at +0xe0..+0x138 (vptr
// stores [x0+0x110]/[x0+0x138] = cell 0x130e918+0x10).
// - Guarded global singleton: guard cells 0x130da08/0x130da10 (init
// writes [0x12fd3d0]+0x10); data cell 0x130da18 -> .bss 0x1357600;
// slot 0xb0 = 0x64f1ec reads an s16 from [[0x130da18]].
// - Slot 0xa8 = 0x647924: merges [this+0xc8]/[this+0x10] with the
// argument's pair, tail-calls 0x66a65c.
//
// Why no name: no RTTI/typeinfo, no symbol or assert names, and no name
// string is ever tied to this class (the only sites that materialize cell
// 0x130da00 are its own dtor family). Renaming would be invention.
// Ctor-evidence correction: recorded "ctor 0x710064eea8" is a float-vector
// normalize helper (square/add/fsqrtf/reciprocal-scale of the triple at
// [x19..x19+0x8]); it performs no vptr store and is not a ctor.
// Vtable slot facts (evidence TU under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 22 (0xc0): ID getter. Returns the signed halfword at offset 0 of
//   the object pointed to by the global pointer cell at 0x130da18 (deref of
//   the cell, then deref of that pointer); self is unused.
//   true function size 0x10 bytes (gap-split artifact).
//   [paramNode2b90IdGetterSlot22_710064f1ec.cpp]
class ParamNodeVt2b90 {
 public:
  void* vtable;  // 0x00
  // (own fields unmapped; secondary-base offset-to-top -0x30 at vt+0xb8)
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
