#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSetChain — PROVISIONAL vtable-anchored name. Base of the
// second PlayerSet dispatch chain (0x61514/0x620a0 derive from 0x628bc,
// which derives from this): ctor 0x71005f558 (Actor base), secondary vptr
// at +0x38 (GOT 0x12fbe00), zeroes 0x40-0xD8, sets [0x40]=0x01000000,
// [0xB0]=-1, owner at +0x90. Size unproven (< 0xF8).
namespace gear
{
    class RaceDirectorSetChain : public Actor
    {
        public:
            uint8_t pad38[8];    //0x38 — secondary vptr
            uint32_t mFlag40;    //0x40 — ctor sets 0x01000000
            uint8_t pad44[0x4c]; //0x44
            int32_t mB0;         //0xB0 — ctor -1
            uint8_t padB4[0x1c]; //0xB4
            void* mOwner90;      //0x90 — ctor arg x1
            uint8_t pad98[8];    //0x98
    };
}
