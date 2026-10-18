#pragma once

#include <cstdint>

namespace nn::pia::transport {
// RttProtocol — RTTI-named (typeinfo pointer at 0x12df900 ->
// {0x10, name 0xf82b00}; 11 slots at vptr+0x00..+0x50 — name
// "N2nn3pia9transport11RttProtocolE"); derives from the abstract pia
// protocol base (base C1 0x9a79c8). Size 0x58 proven: pool alloc 0x9a7c5c
// with size 0x58 (0x9b7f18) before in-place C1 0x9bc6ec.
// extent 0x58 - details: doc/_nn/pia/transport/RttProtocol.md
class RttProtocol {
 public:
  void* mVtable;      // 0x00 - vptr 0x12df908 (GOT cell 0x1313ce0 holds
                      //   vptr-0x10 = 0x12df900; C1 adds 0x10); typeinfo
                      //   pointer at 0x12df900 -> embedded {0x10, name}
  char mPad08[0x30];  // 0x08..0x37 - base object (base extent 0x20) +
                      //   gap; C1 writes 0xfd at +0x38
  uint32_t m38;       // 0x38 - 0xfd (253), written by C1 0x9bc700
  char mPad3c[0x4];   // 0x3c - gap (C1 writes nothing)
  char mPad40[0x10];  // 0x40..0x4f - zeroed by C1 (stp xzr, xzr 0x9bc710)
  uint16_t m50;       // 0x50 - zeroed by C1 (strh wzr 0x9bc714)
  uint8_t m52;        // 0x52 - zeroed by C1 (strb wzr 0x9bc720)
  char mPad53[0x5];   // 0x53..0x57 - tail padding to 0x58
};
}  // namespace nn::pia::transport
