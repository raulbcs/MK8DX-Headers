#pragma once

#include <cstdint>

// Vt12d5b18 — PLACEHOLDER name; vptr 0x12d5b18, n=13, abstract interface
// (null pure-virtual slot 12); concrete variant table 0x12d5c18, size 0x30.
// extent 0x30 - details: doc/object/Vt12d5b18.md

namespace object {
class Vt12d5b18 {
 public:
  void* mVtable;    // 0x00 - 0x12d5b18 (GOT cell 0x1311dc8 holds 0x12d5b08 =
                    //   vt-0x10; installed = cell+0x10)
  uint8_t m8;       // 0x08 - flag byte, ctor 0x8dbc50 sets 1; gates slots
                    //   4 (0x8dbc70) and 7 (0x8dbca4)
  char pad9[0x27];  // 0x09..0x2f - unproven slack to the 0x30 allocation size
                    //   (derived allocation 0xd866c writes floats at +0xc..
                    //   +0x1f and 0 at +0x1c)
};
}  // namespace object
