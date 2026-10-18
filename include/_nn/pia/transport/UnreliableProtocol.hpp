#pragma once

#include <cstdint>

namespace nn::pia::transport {
// UnreliableProtocol — RTTI-named (typeinfo pointer at 0x12df6e0 ->
// {0x10, name 0xf82960}; 11 slots at vptr+0x00..+0x50 — name
// "N2nn3pia9transport18UnreliableProtocolE"); derives from the abstract pia
// protocol base (base C1 0x9a79c8). Size 0x40 proven: pool alloc 0x9a7c5c
// with size 0x40 (0x923578) before in-place C1 0x9ba8a0.
// extent 0x40 - details: doc/_nn/pia/transport/UnreliableProtocol.md
class UnreliableProtocol {
 public:
  void* mVtable;      // 0x00 - vptr 0x12df6e8 (GOT cell 0x1313cc8 holds
                      //   vptr-0x10 = 0x12df6e0; C1 adds 0x10); typeinfo
                      //   pointer at 0x12df6e0 -> embedded {0x10, name}
  char mPad08[0x20];  // 0x08..0x27 - base object (base extent 0x20)
  char mPad28[0x10];  // 0x28..0x37 - zeroed by C1 (stp xzr, xzr 0x9ba8c0)
  uint32_t m38;       // 0x38 - 0xfd (253), written by C1 0x9ba8c8
  uint32_t mPad3c;    // 0x3c - gap (C1 writes nothing)
};
}  // namespace nn::pia::transport
