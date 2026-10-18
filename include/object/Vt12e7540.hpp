#pragma once

#include <cstdint>

#include "object/Vt12e5d00.hpp"

namespace object {
// Vt12e7540 - PLACEHOLDER name; derived from Vt12e5d00 (same 27-slot
// table, D1/D0 + 3 slots overridden); in-place init adds +0xd0..+0xe7.
// extent 0xe8 (lower bound) - details: doc/object/Vt12e7540.md
class Vt12e7540 : public Vt12e5d00 {
 public:
  uint8_t mTailD0[0x18];  // 0xd0 - ptr/0/0 triple written by init
                          // 0xa3e9d8 (0xd0/0xd8/0xe0)
                          // (0xe8 total, tail unproven)
};
}  // namespace object
