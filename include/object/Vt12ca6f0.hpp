#pragma once

#include <cstdint>

namespace object {
// Vt12ca6f0 - PLACEHOLDER name; float-default parameter node installed in
// place by init 0x803d24 (no standalone C1/new found; ~28 caller ctors use it
// as an embedded member, e.g. at member offsets 0x90/0x298).
// size >= 0x56 - details: doc/object/Vt12ca6f0.md
class Vt12ca6f0 {
 public:
  void* vtable;          // 0x00 - 0x12ca6f0 (GOT cell 0x13104d0 holds 0x12ca6e0 =
                         //   vt-0x10)
  void* mParam08;        // 0x08 - init stores arg x1 (owner/config backref)
  char pad10[0x30];      // 0x10..0x3f - written by callers after init; unproven
  char mZeroed40[0x16];  // 0x40..0x55 - init zeroes 0x40..0x4f (stp) and
                         //   0x4e..0x55 (stur); read as float/vector data
};
}  // namespace object
