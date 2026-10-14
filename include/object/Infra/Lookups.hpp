#pragma once

#include <cstdint>

// Generic lookup infra (ring buffer, sorted list, hash bucket). Docblock facts.

// FUN_7100673860 (extent ..0x673958) — ring-buffer range search; self:
// +0x58/+0x60 start pointers (mode bit0 selects), +0x68 u32 head (>= 1),
// +0x6c i32 base; matcher FUN_7100673964; sentinel next == self+0x58.
// FUN_71009b3838 (extent ..0x9b386c; no direct bl callers — vtable sites) —
// intrusive sorted-list lookup; node: next +8, key +0x10, u32 id +0x18;
// match -> id, absent -> 0xfd.
// FUN_7100854ff0 (extent ..0x71008550ac; caller FUN_710083e32c) — hash-bucket
// lookup with signature check; walks *(self+0x1c8) within [self+0x1a0,
// self+0x1c0), payload 0x20 before the link field.
// NOTE: extents unproven — no struct.
