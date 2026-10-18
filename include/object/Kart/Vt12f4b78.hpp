#pragma once

#include <cstdint>

namespace object {
// Vt12f4b78 - 8-slot secondary hook-band vtable of Vt12f4bb8
// (param-cache family), row preceding primary record 0x12f4ba8.
// extent 0x8 - details: doc/object/Kart/Vt12f4b78.md
class Vt12f4b78 {
 public:
  void* vtable;  // 0x00 - 0x12f4b78 (no typeinfo; band slots 0/1 are
                 // dtor thunks, slots 2-5 shared forwarders)
};
}  // namespace object
