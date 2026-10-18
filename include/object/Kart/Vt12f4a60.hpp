#pragma once

#include <cstdint>

namespace object {
// Vt12f4a60 - 8-slot secondary hook-band vtable of ParamContainerVt4920
// (final stage), installed at owner+0x30.
// extent 0x8 - details: doc/object/Kart/Vt12f4a60.md
class Vt12f4a60 {
 public:
  void* vtable;  // 0x00 - 0x12f4a60 (no typeinfo; band slots 0/1 are
                 // dtor thunks, slots 2-5 shared forwarders)
};
}  // namespace object
