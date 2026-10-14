#pragma once

#include <cstdint>

// Check-point progress reset — FUN_7100631e30 (range 0x7100631e30..0x631e7c,
// 76 bytes, ret at 0x631e7c). Called by FUN_7100003170, FUN_710013ed3c,
// FUN_71003de0fc, FUN_7100719c94, FUN_7100719ce0, FUN_71007b8480,
// FUN_71007f5a9c, FUN_7100809244. Returns 1 always.
//
// x0 = per-player check manager, observed fields:
//   +0x90 : u32 player count
//   +0x98 : u32* per-player counters array
//   +0xC4 : u32 (reset to 0)
//
// Semantics: for i in [0, count) (idx clamped via csel to count), zeroes
// counters[idx]; then +0xC4 = 0.
//
// Sibling 0x7100631e80 does the same reset plus +0xC0 = NULL and +0x18 = 0
// (separate TU, not this extent).
