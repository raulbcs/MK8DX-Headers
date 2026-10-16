#pragma once

#include "RaceDirectorVt8.hpp"

namespace gear {
// Derived of RaceDirectorVt8: ctor 0x3a16a8 calls 0x87d9b8 then swaps
// the vptr to 0x1260dd8; same 0x168 size, no new fields.
// Details: doc/gear/Race/RaceDirectorVt0dd8.md
class RaceDirectorVt0dd8 : public RaceDirectorVt8 {
};
}  // namespace gear
