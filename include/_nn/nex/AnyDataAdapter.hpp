#pragma once

#include <cstdint>

// AnyDataAdapter — RTTI-confirmed (ti 0x12e77f0, name "N2nn3nex14AnyDataAdapterE").
// Row 0x12e70d8 is the typeinfo slot; installed vptr = row+8 = 0x12e70e0
// (GOT cell 0x1314d68 holds 0x12e70d0, vptr = cell+0x10). 38 slots.
// extent 0xd8 - details: doc/_nn/nex/AnyDataAdapter.md

namespace nn::nex {
class AnyDataAdapter {
 public:
  void* vtable;      // 0x00 — 0x12e70e0 (factory override 0x7100a41a50)
  char mBase8[0xb8]; // 0x08 — base subobject + members, unproven
                     //        (ctor FUN_71009e55f4)
  char mC0[0x10];    // 0xc0 — zeroed by factory (0x7100a41a48-0x7100a41a4c)
  uint32_t mD0;      // 0xd0 — zeroed by factory (0x7100a41a48)
  char mPadD4[0x4];  // 0xd4 — unproven tail
};
}  // namespace nn::nex
