#pragma once

#include <cstdint>

// ServiceClient — RTTI-confirmed nn::nex::ServiceClient (base nn::nex::RootObject, descriptor 0x12e73c0).
// vptr 0x12e7368 (GOT cell 0x1314b58 holds vptr-0x10; nex typeinfo descriptor 0x12e73c0 at vptr-8); C1 0xa326c8.
// extent 0x20 lower bound - details: doc/net/ServiceClient.md

struct ServiceClient {
  uint64_t vptr;       // 0x00 — 0x12e7368, installed by C1 0xa326c8 and D2 0xa32868
  uint32_t field_8;    // 0x08 — C1 stores w1 (caller-supplied id/flag)
  uint8_t mPadC[0x4];  // 0x0C — unproven padding
  uint64_t field_10;   // 0x10 — refcounted ptr (xzr in C1; D2 decrements [ptr+8])
  uint8_t field_18;    // 0x18 — strb wzr in C1
  uint8_t mPad19[0x7]; // 0x19 — unproven (extent 0x20 lower bound)
};
