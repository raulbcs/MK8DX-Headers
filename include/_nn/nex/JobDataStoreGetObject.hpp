#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12f7330: nn::nex::JobDataStoreGetObject<DataStoreApiVersionTraits<DATASTORE_API_VERSION(1)>>).
// Row 0x12f6c00 is the typeinfo slot; installed vptr 0x12f6c08 (GOT cell 0x1315900 holds vptr-0x10).
// Factory-ctors 0xb18220 / 0xb1b190 both new(0x320) via alloc wrapper 0x573f04.
// extent 0x320 - details: doc/_nn/nex/JobDataStoreGetObject.md
class JobDataStoreGetObject {
 public:
  void* vtable;            // 0x00 — vptr 0x12f6c08
  uint8_t mBase08[0x98];   // 0x08 — nn::nex::ForcedCriticalSection base (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
  void* mVptrA0;           // 0xa0 — secondary vptr, row 0x12f6ca0
  uint32_t mFieldA8;       // 0xa8 — zeroed by factory
  uint8_t mPadAc[0x4];     // 0xac — unproven gap
  uint64_t mFieldB0;       // 0xb0 — zeroed (dtor treats [0xb8] subobject via this pair)
  void* mFieldB8;          // 0xb8 — subobject head; destroyed via virtual slot call
  uint8_t mPadC0;          // 0xc0 — factory B-variant sets 1, A-variant leaves 0
  uint8_t mPadC1[0x7];   // unproven gap
  uint64_t mFieldC8;       // 0xc8 — zeroed
  uint64_t mFieldD0;       // 0xd0 — zeroed
  uint64_t mFieldD8;       // 0xd8 — zeroed
  uint64_t mFieldE0;       // 0xe0 — zeroed
  uint32_t mFieldE8;       // 0xe8 — zeroed
  uint8_t mPadEc[0x14];   // unproven gap
  uint8_t mInit100;        // 0x100 — member-init call 0xa2c1e8 in D1 (size unknown)
  uint8_t mPad101[0x107];  // 0x101 — unproven gap
  uint64_t mField208;      // 0x208 — array head; elements stride 0x28, refcount-dtored
  uint64_t mField210;      // 0x210 — array end
  uint8_t mPad218[0x8];   // unproven gap
  uint64_t mField220;      // 0x220 — member vptr (GOT cell 0x1315b90), released in D1
  uint8_t mPad228[0x8];   // unproven gap
  uint8_t mInit230;        // 0x230 — member vptr (GOT cell 0x130b4a8) + ctor 0x5790b4 (size unknown)
  uint8_t mPad231[0x27];   // unproven gap
  uint64_t mField258;      // 0x258 — array head; elements stride 0x60, virtual-dtored
  uint64_t mField260;      // 0x260 — array end
  uint8_t mPad268[0x10];   // unproven gap
  uint64_t mField278;      // 0x278 — heap block released in D1 (operator delete 0x5763ac)
  uint64_t mField280;      // 0x280 — end ptr of same block
  uint8_t mPad288[0x10];   // unproven gap
  uint64_t mField298;      // 0x298 — member vptr (GOT cell 0x1315910), destroyed in D1 via 0x58c97c
  uint8_t mPad2a0[0x20];   // unproven gap
  uint64_t mField2c0;      // 0x2c0 — counter (incremented by the other factory's helper)
  uint8_t mField2c8;       // 0x2c8 — flag byte set by helper 0xb52740 path
  uint8_t mPad2c9[0x57];   // unproven gap
};
}  // namespace nn::nex
