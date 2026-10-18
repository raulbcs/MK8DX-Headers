#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (compact ti record 0x12e4390, name "N2nn3nex16TransportAdapterE");
// vptr 0x12e34a8 via GOT cell 0x13145d0 (vt-0x10); 13 slots; dtor pair 0x9f7e98/0x9f7edc.
// singleton instance built into the .bss cell 0x13614c0 and linked into the nex
// transport ListBase (head cell 0x130b940). extent 0x1c8 (lower bound) - details: doc/_nn/nex/TransportAdapter.md
class TransportAdapter {
 public:
  void* vtable;           // 0x00 — 0x12e34a8
  uint32_t mField08;      // 0x08 — init 0 (wzr, inline ctor 0x9f74f4)
  uint8_t mPad0C[0x4];    // 0x0C — unproven padding
  uint8_t mMem10[0x90];   // 0x10 — member object (ctor/dtor 0x9d60b0/0x9d6434)
  uint8_t mMemA0[0x90];   // 0xA0 — member object (same ctor/dtor pair)
  uint8_t mMem130[0x90];  // 0x130 — member object (same ctor/dtor pair)
  uint8_t mPad1C0[0x8];   // 0x1C0 — unproven (xzr store at +0x1c0 in inline ctor)
};
}  // namespace nn::nex
