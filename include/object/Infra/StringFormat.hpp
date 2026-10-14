#pragma once

#include <cstdint>

// Generic string-format infra (game-side, unnamed classes). Docblock facts.

// FUN_710061cd50 — bounded formatter wrapper (extent 0x710061cd50..0x61ce04,
// 0xb4 bytes). Callers invoke as FUN_710061cd50(this+0x2f0, fmt, ...).
// x0 = holder: +8 = char* dst buffer, +0x10 = i32 size. Saves the AAPCS
// variadic register save area to the frame and builds the AArch64 va_list
// {__stack = sp+0xb0, __gr_top = fp+0x10, __vr_top = sp, __gr_offs = -0x30,
// __vr_offs = -0x80}, then FUN_7100620878([holder+8], (i64)[holder+0x10],
// fmt, ap). Returns n < 0 ? size - 1 : n.

// FUN_710001b9fc — sprintf into a string object (extent 0xe0, ret at
// 0x1bad8; file_list size 428 is a gap-split — a deleting-dtor thunk at
// 0x1badc, next TU at 0x1bae0). x0 = out string object, x1 = fmt, x2..x7/
// q0..q7 = varargs. Layout: buffer pointer at +0x14, capacity u32 0x40 at
// +0x10; init stamps vtable [0x71012fda0]+0x10, copies the fmt tag byte
// *0x71012fda8 -> out+0x8, swaps the vtable to [0x71012fb288]+0x10, then
// FUN_710061cc48(out, fmt) and the vformat FUN_710061cc70(out, fmt, &va_list).
// Usage example in-binary: FUN_7100011e34 formats "%s%s" with "EState" +
// FUN_710001bae0(i).
