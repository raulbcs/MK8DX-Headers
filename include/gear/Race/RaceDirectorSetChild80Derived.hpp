#pragma once

#include <cstdint>

#include "RaceDirectorSetChild80.hpp"

// RaceDirectorSetChild80Derived — PROVISIONAL vtable-anchored name. Concrete
// variant of RaceDirectorSetChild80; ctor 0x710006e9d0 only re-tags the
// vtable (0x11b4788); size 0x80, built in EVERY dispatch branch (allocs
// 0x6ece8/0x6edd8/0x6eebc/0x6efb8/0x6f280).
// Details: doc/gear/Race/RaceDirectorSetChild80Derived.md

namespace gear {
class RaceDirectorSetChild80Derived : public RaceDirectorSetChild80 {};
}  // namespace gear
