#pragma once

#include <cstdint>

namespace object {
// Vt12f48e0 - 8-slot secondary hook-band vtable of ParamContainerVt4920
// (construction stage), installed at owner+0x30 then overwritten.
// extent 0x8 - details: doc/object/Kart/Vt12f48e0.md
class Vt12f48e0 {
 public:
  void* vtable;  // 0x00 - 0x12f48e0 (no typeinfo; band slots 0/1 are
                 // dtor thunks, slots 2-5 shared forwarders)
};
}  // namespace object
