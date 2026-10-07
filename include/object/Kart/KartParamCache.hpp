#pragma once

#include <cstdint>

namespace object
{
    // KartParamCache — PROVISIONAL vtable-anchored name (slot-5 evidence:
    // the shared ret stub 0x7100638e3c is named KartParamCache_vt5 in the
    // ported symbols). Base of the ~41-vtable param-cache cluster
    // (vtables 0x12b1xxx-0x12f4xxx, n=9..16, sharing the slot block
    // 0x10-0x40; per-class variance is in slots 0x0/0x8 and the tail).
    //
    // Vtable 0x12b1c30 (n=9, GOT cell 0x130d848 — raw qword, NO reloc: the
    // cluster cells are plain .got data read by adrp+ldr). Ctor 0x7100669954,
    // extent 0x40: vptr, zeros 0x10-0x27, param id @0x28 (returned by
    // 0x7100663050 on the global [0x12fc190]), zeros 0x30-0x3f. 86 direct
    // construction/reference sites — the cluster's dominant class; also used
    // as the BASE the array factories call before overwriting the vptr with
    // a derived one (e.g. KartParamCacheVt24c8, stride-0x58 arrays).
    class KartParamCache
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[8];      // 0x08
        uint64_t mZero10;      // 0x10 — ctor zero
        uint64_t mZero18;      // 0x18 — ctor zero
        uint64_t mZero20;      // 0x20 — ctor zero
        uint32_t mParamId28;   // 0x28 — ctor: 0x7100663050([global 0x12fc190]) =
                               // slot-0x18 vcall on the dictionary object +
                               // hash 0x710062fd48 (named-parameter id)
        uint8_t pad2c[4];      // 0x2c
        uint64_t mZero30;      // 0x30 — ctor zero
        uint64_t mZero38;      // 0x38 — ctor zero
        // (0x40 total)
    };
}
