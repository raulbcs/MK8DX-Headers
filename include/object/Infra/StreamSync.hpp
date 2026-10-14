#pragma once

#include <cstdint>

// Registry/filter sync and buffered stream write infra. Docblock facts.

// FUN_7100641cf8 — filter-record sync against the layer registry (extent
// 0x7100641cf8..0x641fb8, 0x2c4 bytes; caller FUN_7100642070). x0 = self:
// +0x8 payload ptr, +0x10 flags byte, +0x1C0/+0x1E0/+0x200 list objects,
// +0x218 target, +0x2D8 offset, +0x2E0 mask halfword.
// For each set list: reg = FUN_71006923d0(); name = vt[[reg] + 0x18](reg);
// walk [obj+0x14] count over the [obj+0x18] 0x10-stride array comparing
// strcmp([entry], [reg+0x8]); match -> [ [x0+8] + 0x60 ] = [entry+0xC].
// Flags [+0x10] bit0: set -> vt[[0x710130b000+0xbb0]](x0+0x218) reset, then
// clear; vt[[0x710130b000+0xba8]](x0+0x218, [reg+0x38]); emit up to 3
// {ptr, val} pairs (offset +0x2D8 added to [list]) via
// vt[[0x710130b000+0xbc0]](x0+0x218, count, sp); result&0xff -> set
// [+0x10] bit0 and [+0x2E0] = mask. If bit0 was set: FUN_7100641fbc(x0).
// Tail: if [ [x0+8] + 0x40 ], vcall [[..+0x8 vtable]](x0). Returns 0.

// FUN_7100631a14 — buffered stream write (232 B). x0 = self; o = self+8.
// Calls vt+0x18 hook on o, FUN_7100631afc(o+0x78, *o, data); busy-waits the
// flag u32 at o+0x14 (==1 spin, then CAS 0->1 with SEQ_CST fence); when
// n >= 1 heap-copies the data (FUN_710060b3fc, saturating 8*n size):
// [o+0xA8] = n, [o+0xB0] = copy; then [o+0xB8] = NULL, [o+0x6C] = 1, fence,
// and spins until the o+0x14 flag returns to 1.
