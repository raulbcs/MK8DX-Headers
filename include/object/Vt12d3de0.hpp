#pragma once

#include <cstdint>

// object::Vt12d3de0 - PLACEHOLDER name. Stack-allocated notification record
// built by FUN_71008ab2ec and registered with the singleton at 0x12fc0368;
// dtor 0x6237f4 unregisters it. Derived from the 0x12b0538 family (base C1
// 0x6155bc). extent 0x54 (lower bound) - details: doc/object/Vt12d3de0.md

namespace object {
class Vt12d3de0 {
 public:
  void* vtable;           // 0x00 - 0x12d3de0 (installed 0x8ab39c; GOT cell
                          //        0x1311968 holds vt-0x10)
  uint8_t pad_08[0x18];   // 0x08 - 0x1F - base ctor 0x6155bc region - unproven
  uint64_t field20;       // 0x20 - zeroed by FUN_71008ab2ec (0x8ab390)
  uint64_t field28;       // 0x28 - zeroed by FUN_71008ab2ec (0x8ab390)
  void* self;             // 0x30 - intrusive self pointer (0x8ab32c/0x8ab3c4)
  uint64_t field38;       // 0x38 - zeroed (0x8ab32c)
  void* secondaryVptr;    // 0x40 - MI secondary vptr, cell 0x12fa0e28+0x10
                          //        (0x8ab3a0..0x8ab3b4) - unverified cell value
  void* field48;          // 0x48 - pointer from GOT cell 0x12fb0728 (0x8ab3b4)
  uint32_t field50;       // 0x50 - u32 = 0x20 (0x8ab354)
};
}  // namespace object
