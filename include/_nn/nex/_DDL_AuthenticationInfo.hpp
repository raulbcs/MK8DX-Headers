#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex23_DDL_AuthenticationInfoE,
// ti object 0x12f90a0). vptr 0x12f9058 (n=8). Internal DDL
// (authentication/data-download layer) record class.
//
// Consumers: FUN_7100b506b0 (refs 0xb506e4 / 0xb50758) — inspects a
// u32 status at +0x58 (== 2 branch) and scans 32 dword entries starting
// at +0xc4 plus u16 flags at +0xe8/+0xec/+0xf8.
//
// Slots: 0xa457e8 (likely dtor), then 0xb4ccac, 0xb4cabc, 0xb4cb88,
// 0xb4cbb8, 0xb4cbec, 0xb4cbcc, 0xb4cbdc. Field map pending.
class _DDL_AuthenticationInfo {
 public:
  void* vtable;             // 0x00 — 0x12f9058
  uint8_t mPad08[0x58];     // 0x08 — unproven gap
  uint32_t mField58;        // 0x58 — status (2 = authenticated branch)
  uint8_t mPad5c[0x68];     // 0x5c — unproven padding
  uint32_t mEntriesC4[32];  // 0xc4 — 32 dwords scanned by the consumer
  uint16_t mFielde8;        // 0xe8 — flags checked by the consumer
  uint8_t mPadea[0x2];      // 0xea — unproven padding
  uint16_t mFieldec;        // 0xec — flags checked by the consumer
  uint8_t mPadee[0xa];      // 0xee — unproven padding
  uint16_t mFieldf8;        // 0xf8 — flags checked by the consumer
  uint8_t mPadfa[0x2];      // 0xfa — unproven padding
                            // (extent beyond 0xfc unproven)
};
}  // namespace nn::nex
