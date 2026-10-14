#pragma once

#include <cstdint>

// Generic allocator / alignment infra. Docblock facts.

// FUN_71006388c8 — align-up helper: return (a + 0xfff) & ~0xfff (4 KiB).

// FUN_710060b04c — heap alloc with flags = 8 (96 B). Heap singleton from
// GOT cell 0x12fa000 + 0xe48; when null falls back to FUN_7100592fd8(size);
// else FUN_710061a5f0(heap), and on success a vt+0x30 call (o, size, 8).

// FUN_7100673c94 — allocation splice into a two-level bucket allocator
// (extent 0x7100673c94..0x673f70; file_list size 0x9c is a gap-split).
// this fields: level A {count s32 +0x50, index +0x54, array +0x48},
// level B {count +0x68, index +0x6c, array +0x58}, merged {count +0x80,
// index +0x84, array +0x70}. Block header: u32 size +0x8, ptr +0x10,
// byte-count +0x18, next-chain +0x50, link head/tail +0x68/+0x70.
// Flow: [+0x28] -= block[+0x18]; chain teardown when block[+0x50]
// (FUN_71006373a4 unlabeled at 0x6373a4 when flag bit0, then
// FUN_71006373bc(block+0x50)); free into level A (FUN_710060b630(this+0x54
// + block)), [+0x50]--; level B merge scan over [+0x58] when [+0x68] >= 1
// and [+0x6c] != [+0x60]: neighbor match by [+0x8]+[+0x18] sums and
// pointer equality -> merge (block[+0x10] = other[+0x10], sizes added into
// [+0x18], other freed via FUN_710060b630/FUN_710060b618 into the merged
// [+0x70] array, [+0x68]-- / [+0x80]++), repeat while block[+0x68]/[+0x70]
// chains exist; else plain insert FUN_710060b618(this+0x58 array + [+0x6c]
// + block), [+0x68]++.
