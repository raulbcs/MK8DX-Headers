#pragma once

#include <cstdint>

// Generic lookup infra (ring buffer, sorted list, hash bucket). Docblock facts.

// FUN_7100673860 — ring-buffer range search (extent 0x7100673860..0x673958,
// 0x100 bytes). x0 = self, x1/x2 = callback args, w3 = mode flag.
//   +0x58 / +0x60 : start pointers selected by mode bit0 (0x60 when set)
//   +0x68 : u32 head (must be >= 1)
//   +0x6c : i32 base
// len = start - base; loop: FUN_7100673964(self, len, x1, x2, mode&1)
// matches -> return len; next = mode&1 ? *(base+len+8) : *(base+len);
// sentinel next == self+0x58 -> return 0.

// FUN_71009b3838 — intrusive sorted-list lookup (extent 0x71009b3838..
// 0x9b386c, 52 bytes; no direct bl callers — vtable/indirect sites).
// x0 = self-terminated circular list head (first node via +8), x1 = key.
// Node: next +8, key +0x10, u32 id +0x18. Match -> id; absent -> 0xfd.

// FUN_7100854ff0 — intrusive hash-bucket lookup with signature check
// (extent 0x7100854ff0..0x71008550ac, 188 bytes; caller FUN_710083e32c).
// Walks nodes from *(self+0x1c8) while inside [self+0x1a0, self+0x1c0);
// node payload sits 0x20 before the link field. Match when *(payload) ==
// *(void**)key && payload[8] == key[8] && payload[9] == key[9]; then a
// signature check: v = FUN_71009161f8(key); FUN_710062ee88(sp, v) builds a
// temp consumed twice by FUN_710062eecc(sp); returns (ror32(node+0x10 u32,
// r2>>27) ^ r1 & 8) == 0. No match / list end -> false.
