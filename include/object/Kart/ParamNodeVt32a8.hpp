#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt32a8 — address-anchored name (vptr 0x12f32a8, cell 0x13152b8, n=23, site 0x9c633c, ctor 0x9c6310).
// Node class of the 0x647f40 hook-band cluster (shared trivial band
// 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
// [this+0x1c]).
// Vtable slot facts (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 10 (0x60), entry at 0x7100abb5f4: blur/gaussian dispatch. Calls
//   FUN_7100654de4(x1arg, self+0x248, self+0x170, x2arg, x3arg, 1,
//   *(0x12fadb8)), then switches on *(self+0x128): 0 -> FUN_710062c4b8
//   (stack buf, *(self+0x1c0), *(self+0x1e0), *(self+0x220) * rodata
//   0xed591c, *(self+0x200), 1.0f) then FUN_7100655ebc(x1, self+0x248, buf,
//   x2, x3, 1, *(0x12fadb8)) and FUN_710062bf28(buf); 1 -> FUN_710062e63c
//   (t, 0, *(self+0x200) * *(self+0x240)), FUN_710062c8b0(buf, t,
//   *(self+0x1c0), *(self+0x1e0)), then FUN_7100655ebc + FUN_710062bf28;
//   other values do nothing. true function size 0x128 bytes.
//   [node32a8BlurDispatchSlot10_7100abb5f4.cpp]
// - Slot 10 (0x60), entry at 0x7100abb8a4: guard-initialised static vtable
//   getter. On first call stores descriptor cell 0x712fd03d0 (+0x10) into
//   cache cell 0x710130e140 (guard byte 0x710130e138). true function size 0x58
//   bytes. [vt32a8VtGetterSlot10_7100abb8a4.cpp]
class ParamNodeVt32a8 {
 public:
  void* vtable;         // 0x00
  uint8_t mPad8[0x28];  // 0x8 — unproven gap
  uint16_t mField30;    // 0x30 — ctor-written
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
