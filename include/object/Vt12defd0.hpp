#pragma once

#include <cstdint>

// Vt12defd0 — serialized-record class (vptr 0x12defd8, 5 slots, GOT cell 0x1313bb0 holds vptr-0x10).
// Instances are embedded (member of a composite built by FUN_71009a8514) and packed big-endian by FUN_71009a8a54.
// extent 0x40 (lower bound; nested member at +0x30, exact size unverified) -
// details: doc/object/Vt12defd0.md

namespace object {
class Vt12defd0 {
 public:
  void* mVtable;          // 0x00 — 0x12defd8 (installed at 0x9a85a0-fragment and 0x9a8a54)
  uint64_t mZero8;        // 0x08 — zeroed by ctor fragment
  uint64_t mZero10;       // 0x10 — zeroed by ctor fragment (read as u16 @+0x10 when packing, unverified)
  uint64_t mZero18;       // 0x18 — zeroed by ctor fragment
  uint64_t mZero20;       // 0x20 — zeroed by ctor fragment
  uint8_t mFlag28;        // 0x28 — zeroed by ctor fragment
  uint8_t mPad29[0x7];    // 0x29 — unproven padding
  uint8_t mNested[0x10];  // 0x30 — member ctor'd via 0x92a1e0 (installs vptr from GOT cell 0x1312438); size unverified
};
}  // namespace object
