#pragma once

#include <cstdint>

// JobDataStoreGetRating — RTTI-confirmed nn::nex::JobDataStoreGetRating.
// vptr 0x12f6ce0 (typeinfo 0x12f7380); 15 slots, factory new 0x1E0.
// extent 0x1E0 - details: doc/net/JobDataStoreGetRating.md

struct JobDataStoreGetRating {
  uint8_t mPad0[0xA0];       // 0x00 — unproven padding (base subobject, base C1 0x588b04)
  uint32_t field_A0;         // 0xA0 — str wzr (0xb1ac78)
  uint8_t mPadA4[0x4];       // 0xA4 — unproven padding
  uint64_t field_A8;         // 0xA8 — stp xzr (0xb1ac7c)
  uint64_t field_B0;         // 0xB0 — stp xzr (0xb1ac7c)
  uint64_t field_B8;         // 0xB8 — stp xzr (0xb1ac90)
  uint64_t field_C0;         // 0xC0 — stp xzr (0xb1ac9c)
  uint64_t field_C8;         // 0xC8 — stp xzr (0xb1ac9c)
  uint64_t field_D0;         // 0xD0 — stp xzr (0xb1aca0)
  uint64_t field_D8;         // 0xD8 — stp xzr (0xb1aca0)
  uint64_t field_E0;         // 0xE0 — stp xzr (0xb1aca4)
  uint64_t field_E8;         // 0xE8 — stp xzr (0xb1aca4)
  uint64_t field_F0;         // 0xF0 — stp xzr (0xb1aca8)
  uint64_t field_F8;         // 0xF8 — stp xzr (0xb1aca8)
  uint64_t member_100;       // 0x100 — member C1 0xa2bf88 (0xb1acac), extends to +0x1d8
  uint8_t mPad108[0xD0];     // 0x108 — unproven padding (rest of the 0xa2bf88 member)
  uint64_t field_1D8;        // 0x1D8 — str xzr (0xb1acb0)
};
