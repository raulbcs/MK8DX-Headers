#pragma once

#include <cstdint>

// RaceListItemF — PROVISIONAL vtable-anchored name ("F"). Manager list item
// of the far race family (same wiring pattern as D/E; base chain 0x7d5450,
// NOT Actor). Vtable 0x11b8ab8 (GOT 0x12fcca8). Ctor 0x71000c9e04; size 0x198,
// proven by the allocation site 0x71003de7c4. Note: its typeinfo cell is
// unreliable (points at unrelated code).
// Baptism audit same wiring pattern, base chain 0x7d5450; typeinfo cell unreliable (points at unrelated code); no name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceListItemF
 {
 public:
 void* vtable; //0x00 — vtable ptr
 uint8_t pad08[0x17c];//0x08 - 0x183 — unproven padding
 uint32_t mZero184; //0x184 — ctor zero
 uint32_t mZero188; //0x188 — ctor zero
 uint32_t m21c190; //0x190 — ctor sets 0x21C
 uint32_t mZero194; //0x194 — ctor zero
 // (0x198 total)
 };
}
