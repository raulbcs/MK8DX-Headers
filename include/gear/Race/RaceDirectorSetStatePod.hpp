#pragma once

#include <cstdint>

// RaceDirectorSetStatePod — PROVISIONAL vtable-anchored name. 0x3C-byte
// POD state record (ctor 0x71000585c4, NO vtable). Two instances per
// RaceDirectorPlayerSet (at +0xB8 and +0xC0; the second is also stored into
// [[set+0xB0]+0x78], i.e. shared with the RaceDirectorSetLanePool child).
// Carries a hardcoded 0.25f ratio at +0x24.
// Baptism audit: POD state record (ctor 0x585c4, 0.25f ratio); two instances per PlayerSet; no name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 struct RaceDirectorSetStatePod
 {
 uint8_t zero00[0x20]; //0x00 — ctor zeroes 0x00-0x1F
 uint32_t mZero20; //0x20 — ctor zero
 float mRatio25; //0x24 — ctor sets 0.25f
 uint32_t mZero28; //0x28
 uint16_t mZero2c; //0x2C
 uint8_t pad2e[2]; //0x2E — unproven padding
 uint32_t mZero30; //0x30
 uint8_t pad34[4]; //0x34 — unproven padding
 uint32_t mZero38; //0x38
 // (0x3C total)
 };
}
