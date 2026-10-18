#pragma once

#include <cstdint>

namespace nn::pia::transport {
// ReliableProtocol — RTTI-named (typeinfo pointer at 0x12df230 ->
// {0x10, name 0xf825d0}; 11 slots at vptr+0x00..+0x50 — name
// "N2nn3pia9transport16ReliableProtocolE"); derives from the abstract pia
// protocol base (base C1 0x9a79c8). Size 0x58 proven: pool alloc 0x9a7c5c
// with size 0x58 (0x9235f4) before in-place C1 0x9aecb0.
// extent 0x58 - details: doc/_nn/pia/transport/ReliableProtocol.md
class ReliableProtocol {
 public:
  void* mVtable;      // 0x00 - vptr 0x12df238 (GOT cell 0x1313bf8 holds
                      //   vptr-0x10 = 0x12df230; C1 adds 0x10); typeinfo
                      //   pointer at 0x12df230 -> embedded {0x10, name}
  char mPad08[0x20];  // 0x08..0x27 - base object (base extent 0x20)
  uint32_t m28;       // 0x28 - 0xfd (253), written by C1 0x9aece0
  char mPad2c[0x4];   // 0x2c - gap (C1 writes nothing)
  uint64_t m30;       // 0x30 - zeroed by C1 (0x9aeccc)
  uint64_t m38;       // 0x38 - zeroed by C1 (0x9aecd0)
  char mPad40[0x10];  // 0x40..0x4f - zeroed by C1 (stp xzr, xzr 0x9aecd4)
  uint64_t m50;       // 0x50 - zeroed by C1 (0x9aece8)
};
}  // namespace nn::pia::transport
