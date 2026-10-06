#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object
{
    // PROVISIONAL vtable-anchored name ("Vt71"). Base of the kart body
    // family: 665 vtables of 71-101 slots sharing PrePass20_7100197798 /
    // GetCurrentSpeed_7100197c90 / CoinItemInteraction_71001981ec — the
    // per-kart+driver-combination body classes. Re-census (see wip):
    // ALL 665 live (one cell + one construction site each), 327 distinct
    // slot-diff fingerprints, ctors SHARED across classes (vtable passed
    // as arg — data-parametrized at construction).
    //
    // Slot semantics (hot override band, census evidence):
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
        char mSub38[0x118];    // 0x38 — embedded member (ctor 0x86838c);
                               // runtime: the 0x140 sub-object read by
                               // slots 0x98/0x1c0 lives in here
        uint64_t mField150;    // 0x150 — zeroed on ctor
        uint64_t mField158;    // 0x158 — zeroed on ctor
        uint32_t mField160;    // 0x160 — zeroed on ctor
        char mPad164[0xa4];    // 0x164 — to end (0x208)
    };
}
