#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSetChain — PROVISIONAL vtable-anchored name. Base of the
// second PlayerSet dispatch chain (0x61514/0x620a0 derive from 0x628bc,
// which derives from this): ctor 0x710005f558 (Actor base), secondary vptr
// at +0x38 (GOT 0x12fbe00), zeroes 0x40-0xD8, sets [0x40]=0x01000000,
// [0xB0]=-1, owner at +0x90. Size unproven (< 0xF8).
// Baptism audit: secondary-vptr chain base (0x628bc); consumers are the factory branches only; no binary name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorSetChain : public Actor
 {
 public:
 void* mSecondary38; //0x38 — secondary vptr
 uint32_t mFlag40; //0x40 — ctor sets 0x01000000
 uint8_t pad44[0x4c]; //0x44 - 0x8F — unproven padding
 void* mOwner90; //0x90 — ctor arg x1
 uint8_t pad98[0x18]; //0x98 - 0xAF — unproven padding
 int32_t mB0; //0xB0 — ctor -1
 uint8_t padB4[0xc]; //0xB4 - 0xBF — unproven padding
 };
}
