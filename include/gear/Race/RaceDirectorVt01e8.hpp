#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorVt01e8 — PROVISIONAL vtable-anchored name (vptr 0x12601e8,
// GOT cell 0x1307588). Far-family singleton: ctor 0x71003995d4 (cxa_guard
// getter in the same init region) runs ctor 0x71007b976c
// (RaceDirectorBase38) then its own fields. Extent 0x62 mapped;
// concrete size 0x68 (rounded to the 8-byte vptr alignment).
// Baptism audit sole getter caller is the per-mode list-node dispatcher 0x398c00-0x398e98 (wired like RaceListItemE: +0x18 self, +0x28 &mgr+0x178, +0x30 [mgr+0x1a8]); the dispatcher never names it.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorVt01e8 : public RaceDirectorBase38
 {
 public:
 uint32_t mField38; //0x38 — ctor zero
 uint8_t pad3c[4]; //0x3c — unproven padding
 uint64_t mZero40; //0x40 — ctor zero
 uint64_t mZero48; //0x48 — ctor zero
 uint32_t mField50; //0x50 — ctor sets 4
 uint8_t pad54[4]; //0x54 — unproven padding
 uint64_t mZero58; //0x58 — ctor zero
 uint8_t bFlag60; //0x60 — ctor sets 1
 uint8_t bZero61; //0x61 — ctor zero
 uint8_t pad62[6]; //0x62 — tail padding (extent 0x62)
 // (0x68 total, binary extent 0x62)
 };
}
