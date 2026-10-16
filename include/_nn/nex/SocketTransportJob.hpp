#pragma once

#include <cstdint>

namespace nn::nex {
// SocketTransportJob — nn::nex::SocketTransport::TransportJob; RTTI-
// confirmed; vptr 0x12e4af8 (GOT 0x13146a0, n=12); factory 0x9fd140.
class SocketTransportJob {
 public:
  void* vtable;           // 0x00
  uint8_t pad_8[0x58];    //0x8 — unproven gap
  uint8_t mBase08[0x58];  // 0x08 — job base region (object is only 0x70 bytes; smaller than
                          // the 0xa0 ForcedCriticalSection extent of the larger jobs)
  uint8_t mPad60[0x1];    // 0x60 — unproven gap
  uint8_t mField61;       // 0x61 — ctor-written (strb wzr at construction site 0x9fd1a4)
  uint8_t mPad62[0x6];    // 0x62 — unproven gap
  uint64_t mField68;      // 0x68 — ctor-written (owner back-pointer, str x19 at 0x9fd1a0)
  // Object size 0x70 (factory new 0x9fd140; ctor 0x582804); layout and
  // disambiguation notes: doc/_nn/nex/SocketTransportJob.md.
};
}  // namespace nn::nex
