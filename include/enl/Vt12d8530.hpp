#pragma once

#include <cstdint>

namespace enl {
// Vt12d8530 - RTTI-less 6-slot construction-stage vtable of an enl TaskThread
// worker class (rels in enl::TaskThread::ThreadHeap blobs 0x907d10/0x91cd98);
// staged over by final row 0x12d7b38 (cell 0x13122f8). Extent lower bound from
// owner C1 stores.
// extent 0x4a8 (lb) - details: doc/enl/Vt12d8530.md
class Vt12d8530 {
 public:
  void* vtable;       // 0x00 - 0x12d8530 (GOT cell 0x13122f0 + 0x10)
  void* m08;          // 0x08 - secondary vptr slot (D1 stores same row at +0x90)
  char pad10[0x80];   // pad - worker fields, split unverified
  void* m90;          // 0x90 - subobject, dtor 0x6286a4
  char pad98[0x38];   // pad - unproven gap
  void* md0;          // 0xd0 - subobject, dtor 0x6286a4
  char padd8[0x3cc];  // pad - worker fields, split unverified
  uint32_t m4a4;      // 0x4a4 - worker C1 zero store
};
}  // namespace enl
