#pragma once

#include <cstdint>

// nn::nex::AcquireNsaIdTokenClient — RTTI-confirmed (typeinfo name
// N2nn3nex23AcquireNsaIdTokenClientE, base nn::nex::StepSequenceJob via 0x128d520).
// vptr 0x12e7c78, 14 slots. extent 0x150 - details: doc/_nn/nex/AcquireNsaIdTokenClient.md

namespace nn::nex {
class AcquireNsaIdTokenClient {
 public:
  void* mVtable;            // 0x00 — 0x12e7c78 (GOT cell 0x1314e28 = vptr-0x10)
  uint8_t mJobBase8[0x70];  // 0x08 — shared job init 0x588b04(this, 2, scratch)
  void* mSub78;             // 0x78 — secondary vptr 0x128d9f8 (cell 0x130b798 = vptr-0x10)
  void* m80;                // 0x80 — 0
  uint8_t mPad88[0x10];     // 0x88 — zeroed by 0x588b04
  uint8_t m98[0x8];         // 0x98 — 0 (zeroed tail of the shared init)
  uint32_t mA0;             // 0xa0 — 0 (0xa44e68)
  uint32_t mPadA4;          // 0xa4 — unproven
  uint8_t mA8[0x20];        // 0xa8 — nn::account::AsyncContext (C1 0xa44e78, D1 0xa45318)
  uint8_t mC8;              // 0xc8 — busy flag: gates HasDone/Cancel/Wait in D1 (0xa452bc)
  uint8_t mPadC9[0x7];      // 0xc9 — unproven
  uint8_t mD0[0x28];        // 0xd0 — nn::os::SystemEventType (WaitSystemEvent 0xa452f4,
                            //        DestroySystemEvent 0xa45310 when +0xf8 set)
  uint8_t mF8;              // 0xf8 — event-created flag (0xa45304)
  uint8_t mPadF9[0x7];      // 0xf9 — unproven
  uint32_t m100;            // 0x100 — 0 (0xa44e88)
  uint32_t mPad104;         // 0x104 — unproven
  uint8_t m108[0x28];       // 0x108 — member inited by 0x5896c0 (0xa44e8c), destroyed by
                            //        0x589720 (D1 0xa452fc)
  uint8_t m130[0x20];       // 0x130 — zeroed (0xa44e90-0xa44e94)
};
}  // namespace nn::nex
