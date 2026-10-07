#pragma once

#include <cstdint>

namespace object
{
    // Vt12ba010 — PLACEHOLDER name (theme unproven). vptr 0x12ba010, n=9,
    // typeinfo NULL (game-side), offset-to-top -0x248 (secondary-base table
    // of a multiple-inheritance class).
    //
    // Slots: 0x6d9c88, 0x6d9cb4 (pair), then the forwarding-stub cluster
    // 0x647f40/0x647f48/0x647f4c/0x6480d8/0x647f60/0x647f68/0x647f6c.
    //
    // 29 code references, all in the SDK audio region 0x6e9000-0x6f2000
    // (FUN_71006eaaa4, FUN_71006eda14 and siblings) — the region references
    // nn::audio reverb/aux symbols and the "gsys_weight" string. The cell is
    // also .data-adjacent to the "Model(ModelFx/Opa0..3)" rodata block.
    // Likely an nn::audio/gsys aux sub-object interface; no class name
    // recoverable (no RTTI, no strings owned by the slots).
    class Vt12ba010
    {
    public:
        void* vtable;          // 0x00 — 0x12ba010
        // (extent unproven)
    };
}
