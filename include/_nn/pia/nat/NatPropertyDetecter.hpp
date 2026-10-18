#pragma once

#include <cstdint>

namespace nn::pia::nat {
// nn::pia::nat::NatPropertyDetecter - RTTI-confirmed (typeinfo slot 0x12dbdb0
// -> record 0x12dbe20, name exact "N2nn3pia3nat19NatPropertyDetecterE");
// base subobject +0x00..+0x3f7.
// extent 0x4a0 - details: doc/_nn/pia/nat/NatPropertyDetecter.md
class NatPropertyDetecter {
 public:
  void* vtable;       // 0x00 - 0x12dbdb8 (GOT cell 0x13132a8 holds 0x12dbda8 =
                      //   vt-0x8; row 0x12dbdb0 is the typeinfo slot, installed
                      //   vptr = row+8 = cell+0x10)
  char pad08[0x3f0];  // 0x08..0x3f7 - base subobject (base C1 0x96606c installs
                      //   base vptr 0x12dbb08 = cell 0x1313240 + 0x10, then
                      //   0xb49bb8 at this+8 and init at this+0x1c; base D2
                      //   0x96616c re-installs the base vptr and processes
                      //   this+0x3f8); unproven
  char pad3F8[0xa0];  // 0x3f8..0x497 - base tail region walked by base D2
                      //   0x96616c and used as cursor base by slots 2/3; unproven
  void* m498;         // 0x498 - ctor 0x968c40 zeroes; later holds a heap block
                      //   pointer (slot 2 0x968c9c stores [sp] here and uses
                      //   this+0x3f8 as cursor base)
};
}  // namespace nn::pia::nat
