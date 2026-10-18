#pragma once

#include <cstdint>

// Vt12b0388 - PLACEHOLDER name; 0x100-byte allocation-backed object created
// only through the aligned-alloc helper FUN_710061a808 (heap-device vcall,
// stored byte size at +0xd4, name string at ctor). Dtor pair FUN_710061a798 /
// FUN_710061a7cc at slots 0/1.
// extent 0x100 - details: doc/object/Vt12b0388.md

namespace object {
class Vt12b0388 {
 public:
  void* vtable;              // 0x00 - 0x12b0388 (GOT cell 0x130d348 holds
                             // 0x12b0378 = vt-0x10)
  char mPad08[0xcc];         // 0x08 - built by FUN_7100618fc4 (328 B ctor
                             // body); unproven
  uint32_t mByteSize_d4;     // 0xd4 - allocation byte size (helper
                             // 0x710061a80c, 0x710061a920)
  char mPadD8[0x28];         // 0xd8..0xff - helper zeroes +0xd8/+0xe0/+0xf0
                             // (three u64 pairs)
};
}  // namespace object
