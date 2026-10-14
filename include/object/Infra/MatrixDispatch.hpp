#pragma once

#include <cstdint>

// Matrix batch helpers (physics/gfx cull and transform). Docblock facts;
// no owning class evidence — free helpers.

// FUN_71001023c0 (0x71001023c0..0x102568; file_list 868 is a gap-split —
// 0x102568..0x102574 ret padding) — 3x4 row-major float matrix (rot
// +0x00..+0x20, translation +0x24..+0x2C) applied to 3 vec3 (stride 0xC);
// out[0]/out[1] are direction-only, out[2] adds translation; unrolled
// fmul/fadd pairs, no FMA contraction.
// FUN_710070d7fc (true range 0x710070d7fc.., 0x11c; file_list 0x1c is a
// gap-split) — matrix-batched cull/dispatch; self: +0x8 item count, +0x10
// item ptr array, +0x1946 gate byte, +0x1e60 flags byte (bit5 -> return);
// per item with item->[0x1e0] & (1 << w2) calls FUN_710070c460.
// NOTE: extents unproven — no struct.
