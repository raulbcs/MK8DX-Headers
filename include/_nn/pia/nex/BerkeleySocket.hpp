#pragma once

#include <cstdint>

namespace nn::pia::nex {
// BerkeleySocketDriver::BerkeleySocket — 0x40-byte per-socket object new'd at
// the accept (0x71009d54c8) and connect (0x71009d5824) sites; two-phase vptr
// install (unnamed base 0x12e26c0, then derived 0x12e2288).
// extent 0x40 - details: doc/_nn/pia/nex/BerkeleySocket.md
class BerkeleySocketDriver {
 public:
  class BerkeleySocket {
   public:
    void* vtable;      // 0x00 - derived vptr 0x12e2288 (cell 0x13141b8 + 0x10);
                       //   base vptr 0x12e26c0 installed first from cell
                       //   0x13141b0
    uint32_t m8;       // 0x08 - stlr wzr (atomic store-release, refcnt/flag)
    uint32_t mC;       // 0x0c - socket fd (accept() result; -1 on the
                       //   connect-path ctor 0x71009d5878)
    uint32_t m10;      // 0x10 - copied from parent [x22+0x10] on accept
    uint16_t m14;      // 0x14 - state; 0x100 (accept) / 0 (connect path)
    char pad16[0x02];
    char m18[0x10];    // 0x18 - sockaddr storage, memset 0x10; +0x19 = 2
    char pad28[0x08];
    void* m30;         // 0x30 - null on init
    void* m38;         // 0x38 - &0x1361140[idx] (0x148-stride driver table;
                       //   index gated by a settings byte via cell 0x130b528)
  };
};
}  // namespace nn::pia::nex
