#pragma once

#include <cstdint>

// NexNatRelayInterface — RTTI-confirmed nn::pia::inet::NexNatRelayInterface.
// vptr 0x12d9af0 (typeinfo row 0x12d9b70); concrete impl object size 0x1D8.
// extent 0x1D8 - details: doc/net/NexNatRelayInterface.md

struct NexNatRelayInterface {
  uint8_t mPad0[0x28];       // 0x00 — unproven padding (heap-zeroed before C1, 0x92cdbc loop)
  uint64_t vptr;             // 0x28 — 0x12d9af0 (C1 0x92f434); 16 slots
  uint64_t field_30;         // 0x30 — C1 stp xzr (0x92f444)
  uint64_t field_38;         // 0x38 — stp xzr (0x92f448)
  uint64_t field_40;         // 0x40 — stp xzr (0x92f448)
  uint8_t mPad48[0x10];      // 0x48 — unproven padding
  uint64_t localAddr_58;     // 0x58 — nn::pia::local::LocalAddress, C1 0x929fd4 (0x92f44c)
  uint64_t field_60;         // 0x60 — str xzr (0x92f454)
  uint64_t field_68;         // 0x68 — str xzr (0x92f460)
  uint64_t field_70;         // 0x70 — str xzr (0x92f474)
  uint32_t field_78;         // 0x78 — str wzr (0x92f48c)
  uint32_t field_7C;         // 0x7C — 0x40 (0x92f480)
  uint8_t body_80[0x158];    // 0x80 — further init (0x92f464-0x92f4bc), unproven
};
