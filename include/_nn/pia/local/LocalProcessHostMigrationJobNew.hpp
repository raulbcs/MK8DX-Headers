#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalProcessHostMigrationJobNew — RTTI-named (typeinfo 0x12e0ad0, name
// "N2nn3pia5local31LocalProcessHostMigrationJobNewE"). Typeinfo-slot row:
// GOT cell 0x1313dc8 holds 0x12e0a38 (= vt-0x8); vptr = 0x12e0a48.
// extent 0x148 - details: doc/_nn/pia/local/LocalProcessHostMigrationJobNew.md
class LocalProcessHostMigrationJobNew {
 public:
  void* vtable;      // 0x00 - 0x12e0a48 (cell 0x1313dc8 + 0x10)
  char pad08[0x11C]; // 0x08 - base subobject region (base ctor 0x710098ffbc;
                     //   unproven gap)
  uint32_t mZero124; // 0x124 - C1 zero (member subobject init 0x7100929fd4)
  uint16_t mZero128; // 0x128 - C1 zero (upper half of the +0x124 member)
  char pad12A[0x2];  // 0x12a - unproven gap
  uint32_t mZero12C; // 0x12c - C1 zero (member subobject init 0x7100929fd4)
  uint16_t mZero130; // 0x130 - C1 zero (upper half of the +0x12c member)
  char pad132[0x6];  // 0x132 - unproven gap
  void* m138;        // 0x138 - C1 arg (x1)
  uint8_t mZero140;  // 0x140 - C1 zero
  char pad141[0x7];  // 0x141 - unproven gap
};
}  // namespace nn::pia::local
