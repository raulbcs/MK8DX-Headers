#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorVta260 — PROVISIONAL vtable-anchored name (vptr 0x12ca260,
// GOT cell 0x1310470). Far-family singleton: ctor 0x71007fd3d4 (cxa_guard
// getter 0x71007fd410 in the same region) runs ctor 0x71007b976c
// (RaceDirectorBase38), zeroes 0x38 and 0x40..0x4f, then zeroes
// 0xb0..0xbf. Everything between 0x50 and 0xaf is untouched by the ctor.
// Extent 0xc0.
// Baptism audit sole getter caller 0x13cfa4 sits in the nn::ldn/LAN init region (MakeIpv4Address + ErrorResultVariant setup) but never names the singleton; near-zero ctor gives no semantics.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorVta260 : public RaceDirectorBase38
 {
 public:
 uint32_t mField38; //0x38 — ctor zero
 uint8_t pad3c[4]; //0x3c — unproven padding
 uint64_t mZero40; //0x40 — ctor zero
 uint64_t mZero48; //0x48 — ctor zero
 uint8_t mPad50[0x60]; //0x50 — untouched by ctor
 uint64_t mZeroB0; //0xb0 — ctor zero (final stp covers
 // 0xb0..0xbf, so extent 0xc0)
 uint64_t mZeroB8; //0xb8 — ctor zero
 // (0xc0 total)
 };
}
