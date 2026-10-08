#pragma once

#include <cstdint>

namespace object {
// Vt3dcf308480 — GAP PROVEN (dead vtable): never instantiated anywhere in the binary.
// Exhaustive reference scan: no adrp/add pair targets the vtable 0x12d8480, and the GOT
// cell 0x1312340 (holds 0x12d8470) is never loaded by any instruction. There is no
// materialization or consumption site; the class has no construction path.
// The previously recorded "site 0x6bd160 / ctor 0x6bcffc" was a false positive:
// FUN_71006bcffc reads [x19+0x3f60], an unrelated field of another object.
// Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor) by vtable shape only.
class Vt3dcf308480 {
 public:
  void* vtable;  // 0x00
                 // (never constructed; no field evidence can exist)
};
}  // namespace object
