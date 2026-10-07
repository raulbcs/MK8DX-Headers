#pragma once

#include <cstdint>

namespace object
{
    // Vt12ca000 — PLACEHOLDER name (theme unproven). vptr 0x12ca000, n=14,
    // typeinfo NULL (game-side), offset-to-top -0xf0 (secondary-base table
    // of a multiple-inheritance class).
    //
    // Slots: 0x110328, 0x1103f4 (early .text thunks), 0x7f9d6c, 0x7f9d70,
    // 0x7f8bc4, 0x7f8ca8, 0x7f8ecc, 0x1c6c, 0x1c70, 0x1c74, 0x1c7c, 0x1cbc
    // (tiny forwarding stubs), 0x7b97a8, 0x7b97b4.
    //
    // 8 code references: FUN_71007fd97c (0x7fe3fc-0x7fe89c — calls slot
    // +0x10 with the object, result compared >= 1; then slot +0x8 with an
    // index, returning a pointer to u16 pairs compared against fields
    // +0x8c/+0x8e of a related object) and FUN_7100801d04 (0x801e98,
    // 0x8022b0, 0x80279c). Query/interface-shaped usage; class name not
    // recoverable (no RTTI, no owned strings).
    class Vt12ca000
    {
    public:
        void* vtable;          // 0x00 — 0x12ca000
        // (extent unproven)
    };
}
