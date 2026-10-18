#pragma once

#include <cstdint>

namespace nn::pia::nat {
// RTTI-confirmed (compact ti record 0x12dbc50, name "N2nn3pia3nat15NatPortDetecterE");
// vptr 0x12dbbe8 via GOT cell 0x1313280 (vt-0x10); 13 slots; dtor pair 0x967184/0x9671c4.
// Derived from nn::pia::nat::NatDetecter (base ctor 0x96606c); allocated 0x518 by the
// nat manager. extent 0x518 - details: doc/_nn/pia/nat/NatPortDetecter.md
class NatPortDetecter {
 public:
  void* vtable;            // 0x00 — 0x12dbbe8
  uint8_t mBase08[0x490];  // 0x08 — nn::pia::nat::NatDetecter base region (base ctor
                           // 0x96606c stores through +0x70; full layout unproven)
  uint8_t mMem498[0x38];   // 0x498 — member object (ctor 0x9b38b8)
  uint8_t mMem4D0[0x38];   // 0x4D0 — member object (ctor 0x9b38b8)
  uint8_t mPad508[0x8];    // 0x508 — unproven padding
  uint64_t mField510;      // 0x510 — init 0 (xzr)
};
}  // namespace nn::pia::nat
