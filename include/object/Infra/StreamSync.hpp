#pragma once

#include <cstdint>

// Registry/filter sync and buffered stream write infra. Docblock facts.

// FUN_7100641cf8 (extent ..0x641fb8; caller FUN_7100642070) — filter-record
// sync against the layer registry; self: +0x8 payload ptr, +0x10 flags byte,
// +0x1C0/+0x1E0/+0x200 list objects, +0x218 target, +0x2D8 offset, +0x2E0
// mask halfword; per-entry match via strcmp sets [[x0+8]+0x60] = [entry+0xC].
// FUN_7100631a14 (232 bytes) — buffered stream write; o = self+8; spin/CAS
// on flag u32 o+0x14; [o+0xA8] = n, [o+0xB0] = heap copy (FUN_710060b3fc),
// [o+0xB8] = NULL, [o+0x6C] = 1.
// NOTE: extents unproven — no struct.
