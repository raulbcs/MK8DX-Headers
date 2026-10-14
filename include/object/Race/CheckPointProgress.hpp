#pragma once

#include <cstdint>

// Check-point progress reset — FUN_7100631e30 (range ..0x631e7c, 76 bytes).
// Called by FUN_7100003170, FUN_710013ed3c, FUN_71003de0fc, FUN_7100719c94,
// FUN_7100719ce0, FUN_71007b8480, FUN_71007f5a9c, FUN_7100809244.
// Per-player check manager (x0) observed fields:
//   +0x90 u32 player count; +0x98 u32* counters; +0xC4 u32 (zeroed);
//   sibling 0x7100631e80 also zeroes +0xC0 and +0x18 (separate TU).
// NOTE: manager extent unproven (access sites only) — no struct.
