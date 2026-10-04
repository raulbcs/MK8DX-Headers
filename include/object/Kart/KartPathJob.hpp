#pragma once

#include <cstdint>

// KartPathJob — size 0x2B8, proven by operator new(0x2B8) in the KartVehicle
// init (v400 0x71001704c0, stored at KartVehicle+0x88; ctor 0x71003aed50,
// same guarded block as KartRecorderKey). The ctor registers its children
// through 0x7ac0cc(this, child, name) with names from the string cluster
// "at"/"up"/"back"/"dist"/"fovy"/"RecorderModelMiiExpression" (0xee5e30..) —
// a recorder camera rig. PROVISIONAL name; no MethodTree string.
namespace object
{
    struct KartPathJob
    {
        uint8_t pad_00[8]; // 0x00 — vtable ptr (global 0x1307890+0x10)
        uint8_t pad_08[0x108]; //0x08
        uint8_t flag110; //0x110 — ctor sets 1
        uint8_t pad_111[0x167]; //0x111 - 0x277
        void* parent_278; //0x278 — ctor: [x1+0x278] received the param struct's
            // first pointer; ctor then registers this under it:
            // 0x7ac0cc(parent, this, 0) (0x3aed98-0x3aeda4)
        uint8_t block_280[0x38]; //0x280 — part of the 0x40-byte copy from the
            // param struct (memcpy this+0x278 <- x1, 0x40 bytes, 0x3aed94)
        // Two children allocated and registered by name in the ctor:
        //   child A: new(0x288), floats 0.01f @0x1F0, 128.0f @0x1F4,
        //     0.0078125f @0x1F8, 255.0f @0x284, u32 4 @0x1C0, 1 @0x1C4
        //     (0x3aedb4-0x3aee1c)
        //   child B: new(0x280), u32 pair {4, 4} @0x1C0 (0x3aee24-0x3aee60)
        // Camera-vector init from [x1+0x18] with float 0xed59e0 (0x3aee64-0x3aee88).
    };
}
