#pragma once

#include "RaceDirectorVt8.hpp"

namespace gear {
// Derived of RaceDirectorVt8: ctor 0x3a16a8 calls 0x87d9b8 then swaps
// the vptr to 0x1260dd8. Same 0x168 size (alloc 0x398964 feeds the
// derived ctor; the derived ctor adds no fields).
class RaceDirectorVt0dd8 : public RaceDirectorVt8 {
};
}  // namespace gear
