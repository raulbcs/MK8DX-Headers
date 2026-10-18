#pragma once

#include <cstdint>

// nn::nex::JobTerminate — RTTI-confirmed (typeinfo name N2nn3nex12JobTerminateE,
// base nn::nex::StepSequenceJob via descriptor 0x128d520). vptr 0x12e7b68, 13 slots
// (D1/D0 + the shared 11-slot nex cluster). extent 0x140 - details: doc/_nn/nex/JobTerminate.md

namespace nn::nex {
class JobTerminate {
 public:
  void* mVtable;            // 0x00 — 0x12e7b68 (GOT cell 0x1314e00 = vptr-0x10)
  uint8_t mJobBase8[0x70];  // 0x08 — shared job init 0x588b04(this, 2, scratch): flag +0x8,
                            //        counters/pointers zeroed through +0x70
  void* mSub78;             // 0x78 — secondary vptr 0x128d9f8 (cell 0x130b798 = vptr-0x10)
  void* m80;                // 0x80 — 0
  uint8_t mPad88[0x10];     // 0x88 — zeroed by 0x588b04
  void* mSub98;             // 0x98 — secondary vptr 0x128d9f8 again (0xa43e30)
  void* mOwner;             // 0xa0 — owning object back-pointer (0xa43e30)
  uint32_t mA8;             // 0xa8 — u32 arg from owner field [x21+0x18] (0xa43e2c)
  uint32_t mPadAC;          // 0xac — unproven
  void* mSubB0;             // 0xb0 — vptr 0x128cc20 (cell 0x130b740 = vptr-0x10, 0xa43dec)
  uint32_t mB8;             // 0xb8 — 1 (stlr, 0xa43dbc)
  uint8_t mBC;              // 0xbc — 0
  uint8_t mPadBD[0x3];      // 0xbd — unproven
  void* mC0;                // 0xc0 — 0
  uint32_t mC8;             // 0xc8 — 0
  uint32_t mPadCC;          // 0xcc — unproven
  void* mD0;                // 0xd0 — self-pointer (+0xd0), 0xa43df4
  void* mD8;                // 0xd8 — self-pointer (+0xd0)
  uint8_t mE0[0x28];        // 0xe0 — zeroed (0xa43dc..0xa43e4)
  uint8_t m108[0x18];       // 0x108 — member inited by 0x5788e0(this+0x108, scratch)
  void* m120;               // 0x120 — 0
  uint32_t m128;            // 0x128 — 0
  uint8_t mE12C[0x14];      // 0x12c — unproven
};
}  // namespace nn::nex
