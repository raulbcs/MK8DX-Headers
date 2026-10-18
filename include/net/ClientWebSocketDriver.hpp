#pragma once

#include <cstdint>

// ClientWebSocketDriver — RTTI-confirmed nn::nex::ClientWebSocketDriver.
// vptr 0x12e25a8 (typeinfo 0x12e2640); MI: nn::nex::Socket base at +0x10.
// extent 0x40 (lower bound, unverified) - details: doc/net/ClientWebSocketDriver.md

struct ClientWebSocketDriver {
  uint64_t vptr;             // 0x00 — 0x12e25a8; 15 slots
  uint8_t mPad8[0x8];        // 0x08 — unproven padding
  uint64_t socket_10;        // 0x10 — Socket base vptr 0x128c698 (base init 0x5790b4)
  uint8_t innerCws_18[0x10]; // 0x18 — inner ClientWebSocket storage (init 0x9dfc44), unproven
  uint64_t selfPtr_28;       // 0x28 — ptr to +0x18 (singleton init 0x9e26d4)
  uint64_t field_30;         // 0x30 — 0x10 (0x9e2704); deepest proven field
  uint8_t mPad38[0x8];       // 0x38 — unproven padding
};
