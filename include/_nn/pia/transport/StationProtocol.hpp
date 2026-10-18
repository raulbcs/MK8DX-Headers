#pragma once

#include <cstdint>

namespace nn::pia::transport {
// StationProtocol — RTTI-named (typeinfo pointer at 0x12df550 ->
// {0x10, name 0xf82790}; 11 slots at vptr+0x00..+0x50 — name
// "N2nn3pia9transport15StationProtocolE"); derives from the abstract pia
// protocol base (base C1 0x9a79c8). Size 0x30 proven: pool alloc 0x9a7c5c
// with size 0x30 (0x9b7ec4) before in-place C1 0x9b5fcc.
// extent 0x30 - details: doc/_nn/pia/transport/StationProtocol.md
class StationProtocol {
 public:
  void* mVtable;      // 0x00 - vptr 0x12df558 (GOT cell 0x1313c70 holds
                      //   vptr-0x10 = 0x12df550; C1 adds 0x10); typeinfo
                      //   pointer at 0x12df550 -> embedded {0x10, name}
  char mPad08[0x20];  // 0x08..0x27 - base object (base extent 0x20)
  uint32_t m28;       // 0x28 - 0x2710 (10000), written by C1 0x9b5ff0
  uint32_t mPad2c;    // 0x2c - gap (C1 writes nothing)
};
}  // namespace nn::pia::transport
