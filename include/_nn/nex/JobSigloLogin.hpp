#pragma once

#include <cstdint>

// nn::nex::JobSigloLogin — RTTI-confirmed (typeinfo name N2nn3nex13JobSigloLoginE,
// base nn::nex::JobLogin via descriptor 0x12e7d40). vptr 0x12e7be0, 13 slots
// (D1/D0 + the shared 11-slot nex cluster). extent 0x230 - details: doc/_nn/nex/JobSigloLogin.md

namespace nn::nex {
class JobSigloLogin {
 public:
  void* mVtable;            // 0x00 — 0x12e7be0 (GOT cell 0x1314de0 = vptr-0x10)
  uint8_t mJobBase8[0x70];  // 0x08 — shared job init 0x588b04(this, 2, scratch)
  void* mSub78;             // 0x78 — secondary vptr 0x128d9f8 (cell 0x130b798 = vptr-0x10)
  void* m80;                // 0x80 — 0
  uint8_t mPad88[0x10];     // 0x88 — zeroed by 0x588b04
  uint8_t m98[0x8];         // 0x98 — 0 (zeroed tail of the shared init)
  uint8_t mA0[0xe0];        // 0xa0 — member region; +0xa0 destroyed by D1 via 0xa2c1e8;
                            //        0x160..0x178 zeroed by the factory (0xa43724-0xa43738)
  void* m180;               // 0x180 — 0
  void* mSub188;            // 0x188 — vptr 0x12e7ed8 (cell 0x1314da8 = vptr-0x10, 0xa4373c)
  void* m190;               // 0x190 — nullable member pointer, virtually destroyed in D1
                            //        (0xa448bc-0xa448a8)
  void* mSub198;            // 0x198 — vptr 0x128c698 (cell 0x130b4a8 = vptr-0x10); sub-object
                            //        destroyed by 0x5790b4(this+0x198) in D1
  uint8_t m1A0;             // 0x1a0 — 0
  uint8_t mPad1A1[0xf];     // 0x1a1 — unproven
  void* m1B0;               // 0x1b0 — self-pointer to +0x1a0 (0xa4376c)
  uint64_t m1B8;            // 0x1b8 — 0x10 (0xa4376c)
  uint8_t m1C0[0x28];       // 0x1c0 — member inited by 0x5896c0 (0xa43774), destroyed by
                            //        0x589720 (D1 0xa44878)
  void* mSub1E8;            // 0x1e8 — vptr 0x128c698 (0xa43784); destroyed by
                            //        0x5790b4(this+0x1e8) in D1
  uint8_t m1F0;             // 0x1f0 — 0
  uint8_t mPad1F1[0x7];     // 0x1f1 — unproven
  void* m1F8;               // 0x1f8 — 0 (unproven)
  void* m200;               // 0x200 — self-pointer to +0x1f0 (0xa43778)
  uint64_t m208;            // 0x208 — 0x10 (0xa4378c)
  uint8_t m210[0x20];       // 0x210 — unproven tail (allocation 0x230)
};
}  // namespace nn::nex
