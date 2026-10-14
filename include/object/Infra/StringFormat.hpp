#pragma once

#include <cstdint>

// Generic string-format infra (game-side, unnamed classes). Docblock facts.

// FUN_710061cd50 (extent 0x710061cd50..0x61ce04) — bounded formatter wrapper;
// callers use (this+0x2f0, fmt, ...); holder +8 char* dst, +0x10 i32 size;
// builds the AArch64 va_list and calls FUN_7100620878; returns n < 0 ?
// size - 1 : n.
// FUN_710001b9fc (extent ..0x1bad8; file_list 428 is a gap-split — deleting-
// dtor thunk at 0x1badc, next TU 0x1bae0) — sprintf into a string object;
// buffer ptr +0x14, capacity u32 0x40 at +0x10; vtables [0x71012fda0] ->
// [0x71012fb288]; vformat FUN_710061cc70(out, fmt, &va_list).
// NOTE: string-object extent unproven (init sites only) — no struct.
