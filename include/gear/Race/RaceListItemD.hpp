#pragma once

#include <cstdint>

#include "RaceDirector.hpp"
#include "RaceListItemE.hpp"

// RaceListItemD — PROVISIONAL vtable-anchored name ("D"). Specializes
// RaceListItemE: create-fn 0x71000c7984 builds the 0xB00 object with the E
// ctor 0xc8138, then re-tags the vptr to 0x11b88e0. Same 0xB00 layout.
// Details: doc/gear/Race/RaceListItemD.md

namespace gear {
class RaceListItemD : public RaceListItemE {
 public:
  // Same layout as E (0xB00); D adds behavior via vtable override,
  // no extra fields observed at create time.
};
}  // namespace gear
