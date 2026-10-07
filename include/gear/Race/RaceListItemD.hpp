#pragma once

#include <cstdint>

#include "RaceDirector.hpp"
#include "RaceListItemE.hpp"

// RaceListItemD — PROVISIONAL vtable-anchored name ("D"). Specializes
// RaceListItemE (create-fn 0x71000c7984 builds the 0xB00 object with the E
// ctor 0xc8138, then overwrites the vptr to 0x11b88e0 / GOT 0x12fcc38).
// Invoked indirectly (function pointer, rela addend 0xc7984). Reads a
// config table [GOT 0x12fc328]->+0x48->+0x708 indexed by an id; registers
// into manager+0x1F8 and bumps manager+0x1C0.
// Baptism audit create-fn 0xc7984 re-tags E's ctor; dispatched by function pointer (rela addend); mode dispatcher 0x398xxx never names it.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceListItemD : public RaceListItemE
 {
 public:
 // Same layout as E (0xB00); D adds behavior via vtable override,
 // no extra fields observed at create time.
 };
}
