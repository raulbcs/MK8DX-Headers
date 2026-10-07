#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object
{
    // Address-anchored name ("Vt71"). Base of the kart body
    // family: 665 vtables of 71-101 slots sharing PrePass20_7100197798 /
    // GetCurrentSpeed_7100197c90 / CoinItemInteraction_71001981ec — the
    // per-kart+driver-combination body classes. Full-family vtable analysis:
    // ALL 665 live (one cell + one construction site each), 327 distinct
    // slot-diff fingerprints, ctors SHARED across classes (vtable passed
    // as arg — data-parametrized at construction).
    //
    // Construction pattern: base ctor 0x710019888 runs for ALL
    // 665 combos; a tiny per-combo block then stores the class vptr and
    // writes the per-combo data (fields 0x38, 0x128) — the same trio the
    // slot 0x18 re-init hook rewrites (0x38/0x128/0x1a8-clear). Per-combo
    // BEHAVIOR is compiled per class (348 distinct slot-0x80 impls) — the 665 are
    // not worth per-class headers; the analysis is the combo map.
    //
    // Slot semantics (hot override band, analysis evidence):
    // - slot 0x18 (0x7100198ac8): re-init hook — base impl stores the
    //   vptr cell 0x12fd6a8 pair, writes 0x38/0x128, clears 0x1a8;
    //   differs in 664/665 classes.
    // - slots 0x80/0x88/0x90: PURE RET on the base — the family's
    //   override hooks (571/426/515 classes fill them).
    // - slot 0x98 (0x7100199798): state query on the sub-object at
    //   0x140 ([x8+8] compared against 5).
    // - slot 0xa0 (0x7100199000): packed flag query (bytes 0x166, [0x130],
    //   [0x40]).
    // - slot 0x1c0 (0x710019b440): delegates to [0x140] -> [+0x730]
    //   vtable slot 0x18, returns [+0x738] (602 classes differ).
    //
    // Vtable .data 0x11bb5c0 (GOT cell 0x12fd6a8), ctor 0x710019888, size
    // 0x208 (allocation 0x208 at 0x19d554). Ctor: Actor base 0x7b976c,
    // embedded member at 0x38 (ctor 0x86838c), zeros at 0x150-0x160,
    // u32 0x160 = 0. Derived variants add fields up to ~0x2b8 (observed
    // factory allocs 0x1f8..0x2b8).
    class KartBodyVt71 : public gear::Actor
    {
    public:
        char mSub38[0xf0];     // 0x38 — embedded member (ctor 0x86838c); the
                               // 0x140 sub-object read by slots 0x98/0x1c0
                               // lives in here ([+0x730] delegate, [+0x738] ret)
        uint64_t mField128;    // 0x128 — per-combo data/object: written by the
                               // construction block and rewritten by the
                               // re-init slot 0x18
        uint64_t mField130;    // 0x130 — byte pair read by slot 0xa0
        uint64_t mField138;    // 0x138
        uint64_t mField140;    // 0x140 — sub-object read by slots 0x98/0x1c0
                               // (delegation [+0x730] -> vcall 0x18, [+0x738])
        uint64_t mField148;    // 0x148
        uint64_t mField150;    // 0x150 — zeroed on ctor
        uint64_t mField158;    // 0x158 — zeroed on ctor
        uint32_t mField160;    // 0x160 — zeroed on ctor
        char mPad164[0x2];     // 0x164
        uint8_t mFlag166;      // 0x166 — flag read by slot 0xa0
        char mPad167[0x41];    // 0x167
        void* mField1a8;       // 0x1a8 — cleared by the re-init slot 0x18
        char mPad1b0[0x58];    // 0x1b0 — to end (0x208)
};
}

// Naming closure: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary and are not derivable from the binary alone. Address-anchored name retained.
