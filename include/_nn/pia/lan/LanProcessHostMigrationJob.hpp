#pragma once

#include <cstdint>

namespace nn::pia::lan {
// LanProcessHostMigrationJob — RTTI-named (typeinfo 0x12dc700, name
// "N2nn3pia3lan26LanProcessHostMigrationJobE"). Typeinfo-slot row: GOT cell
// 0x1313330 holds 0x12dc668 (= vt-0x8); installed vptr = 0x12dc678.
// extent 0x1f8 - details: doc/_nn/pia/lan/LanProcessHostMigrationJob.md
class LanProcessHostMigrationJob {
 public:
  void* vtable;         // 0x00 - 0x12dc678 (cell 0x1313330 + 0x10)
  char pad08[0x120];    // 0x08 - base subobject region (base ctor 0x710098ffbc;
                        //   flag byte at 0xd4 read by C1; unproven gap)
  char pad128[0x20];    // 0x128 - member subobject initialized by 0x7100929ec0
                        //   (size unknown, unproven gap)
  void* mZero148;       // 0x148 - C1 zero
  char pad150[0x8];     // 0x150 - unproven gap
  void* mZero158;       // 0x158 - C1 zero
  char pad160[0x82];    // 0x160 - C1 memsets 0x80 bytes here (if [0xd4] != 0)
                        //   and zeroes byte 0x1e1; unproven gap
  char pad1E2[0x6];     // 0x1e2 - unproven gap
  void* mZero1E8;       // 0x1e8 - C1 zero (stp low half)
  void* mZero1F0;       // 0x1f0 - C1 zero (stp high half)
};
}  // namespace nn::pia::lan
