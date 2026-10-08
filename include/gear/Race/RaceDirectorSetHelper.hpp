#pragma once

#include <cstdint>

// RaceDirectorSetHelper — PROVISIONAL vtable-anchored name. 0x40-byte
// helper bound to RaceDirectorPlayerSet: ctor 0x71000689c8 (minimal base
// 0x7c2920), vtable 0x11b4408 (GOT 0x12fbf40). Stored at set+0x50.
// Baptism audit: 0x40 helper ctor 0x689c8 off minimal base 0x7c2920, stored at set+0x50; no binary name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear {
class RaceDirectorSetHelper {
 public:
  void* vtable;      //0x00
  uint32_t u08;      //0x08 — ctor zero
  uint32_t u0c;      //0x0C — ctor zero
  void* m10;         //0x10 — ctor zero
  void* m18;         //0x18 — ctor zero
  void* mOwner20;    //0x20 — ctor arg x1 (the PlayerSet)
  uint64_t m28;      //0x28 — ctor zero
  uint32_t m30;      //0x30 — ctor zero
  uint8_t pad34[4];  //0x34 — unproven padding
  uint32_t m38;      //0x38 — ctor zero
};
}  // namespace gear
