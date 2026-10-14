#pragma once

#include <cstdint>

// Generic allocator / alignment infra. Docblock facts.

// FUN_71006388c8 — align-up helper: (a + 0xfff) & ~0xfff (4 KiB).
// FUN_710060b04c (96 bytes) — heap alloc with flags = 8; heap singleton from
// GOT cell 0x12fa000 + 0xe48, fallback FUN_7100592fd8(size).
// FUN_7100673c94 (extent 0x7100673c94..0x673f70; file_list 0x9c is a
// gap-split) — splice into a two-level bucket allocator. this: level A
// {count s32 +0x50, index +0x54, array +0x48}; level B {count +0x68, index
// +0x6c, array +0x58}; merged {count +0x80, index +0x84, array +0x70}.
// Block header: u32 size +0x8, ptr +0x10, byte-count +0x18, next-chain
// +0x50, link head/tail +0x68/+0x70.
// NOTE: extents of allocator and block header unproven — no struct.
