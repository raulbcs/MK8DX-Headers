#pragma once

#include <cstdint>

// Matrix batch helpers (physics/gfx cull and transform). Docblock facts;
// no owning class evidence — free helpers.

// FUN_71001023c0 — 3x4 matrix transform of 3 points (addresses
// 0x71001023c0..0x102568, 424 bytes; file_list size 868 is a gap-split —
// 0x102568..0x102574 ret padding). x0 = row-major 3x4 float matrix
// (3x3 rotation +0x00..+0x20, translation +0x24..+0x2C), x1 = out array
// of 3 vec3, x2 = in array of 3 vec3 (stride 0xC).
//   out[0] = M3x3 * in[0]   (direction, no translation)
//   out[1] = M3x3 * in[1]   (direction, no translation)
//   out[2] = M3x3 * in[2] + translation
// Unrolled fmul/fadd pairs per component (no FMA contraction).

// FUN_710070d7fc — matrix-batched cull/dispatch (0x710070d7fc..
// true size 0x11c; file_list size 0x1c is a gap-split). x0 = self:
//   +0x8    item count
//   +0x10   item pointer array
//   +0x1946 gate byte (0 -> return)
//   +0x1e60 flags byte (bit5 -> return; passed as u8 to the callee)
// Builds an NEON 4x4 mat34 product (rows from x4 and x3) into a 0x40-byte
// local (reproducible as 4 scalar dot products with broadcast w), then for
// each item with item->[0x1e0] & (1 << w2) calls FUN_710070c460([item],
// x1, &localMat, (u8)[self+0x1e60]).
