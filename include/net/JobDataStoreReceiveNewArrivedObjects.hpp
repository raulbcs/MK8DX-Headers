#pragma once

#include <cstdint>

// JobDataStoreReceiveNewArrivedObjects — RTTI-confirmed
// nn::nex::JobDataStoreReceiveNewArrivedObjects<DataStoreApiVersionTraits<0>>.
// vptr 0x12f6ee8 (typeinfo 0x12f7480); 15 slots; factory new 0x508.
// extent 0x508 - details: doc/net/JobDataStoreReceiveNewArrivedObjects.md

struct JobDataStoreReceiveNewArrivedObjects {
  uint8_t mPad0[0xA0];       // 0x00 — unproven padding (base subobject, base C1 0x588b04)
  uint32_t field_A0;         // 0xA0 — str wzr (0xb1a6f8)
  uint8_t mPadA4[0x4];       // 0xA4 — unproven padding
  uint64_t field_A8;         // 0xA8 — stp xzr (0xb1a6e0)
  uint64_t field_B0;         // 0xB0 — stp xzr (0xb1a6e0)
  uint8_t flag_B8;           // 0xB8 — 1 (0xb1a6e4)
  uint8_t mPadB9[0x3];       // 0xB9 — unproven padding
  uint32_t field_BC;         // 0xBC — str wzr (0xb1a6e8)
  uint64_t member_C0;        // 0xC0 — member C1 0xa2bf88 (0xb1a700), arg 0
  uint8_t mPadC8[0xB8];      // 0xC8 — unproven padding
  uint64_t field_180;        // 0x180 — stp xzr (0xb1a724)
  uint64_t socket_188;       // 0x188 — Socket base vptr 0x128c698; init 0x578f98 with "" (0xed6af8)
  uint64_t member_190;       // 0x190 — self ptr to +0x190; byte zeroed (0xb1a71c/0xb1a704)
  uint64_t field_198;        // 0x198 — 0x10 (0xb1a72c)
  uint64_t field_1A0;        // 0x1A0 — ptr to +0x190 (0xb1a72c)
  uint64_t field_1A8;        // 0x1A8 — 0x10 (0xb1a72c)
  uint32_t field_1B0;        // 0x1B0 — str wzr (0xb1a744)
  uint8_t mPad1B4[0x4];      // 0x1B4 — unproven padding
  uint64_t field_1B8;        // 0x1B8 — stp xzr x2 (0xb1a748)
  uint64_t field_1C0;        // 0x1C0 — stp xzr x2 (0xb1a748)
  uint64_t field_1C8;        // 0x1C8 — stp xzr x2 (0xb1a74c)
  uint64_t field_1D0;        // 0x1D0 — stp xzr x2 (0xb1a74c)
  uint8_t buffer_1D8[0x160]; // 0x1D8 — memset 0, 0x160 bytes (0xb1a750)
  uint8_t buffer_338[0x160]; // 0x338 — memset 0, 0x160 bytes (0xb1a760)
  uint64_t field_498;        // 0x498 — str xzr (0xb1a764)
  uint64_t field_4A0;        // 0x4A0 — str xzr (0xb1a768)
  uint64_t field_4A8;        // 0x4A8 — str xzr (0xb1a76c)
  uint64_t field_4B0;        // 0x4B0 — str xzr (0xb1a770)
  uint64_t field_4B8;        // 0x4B8 — str xzr (0xb1a774)
  uint64_t field_4C0;        // 0x4C0 — str xzr (0xb1a778)
  uint64_t field_4C8;        // 0x4C8 — str xzr (0xb1a77c)
  uint8_t mPad4D0[0x38];     // 0x4D0 — unproven padding
};
