#pragma once

#include <cstdint>

namespace nn::nex {
// DummyPacketEncDec — RTTI-named (typeinfo 0x12e4c20, name
// "N2nn3nex17DummyPacketEncDecE"; base 0x12e4270 PacketEncDecInf). GOT cell
// 0x1314708 holds vptr-0x10. Heap size 0xd0 proven (new at 0xa03880).
// extent 0xd0 - details: doc/_nn/nex/DummyPacketEncDec.md
class DummyPacketEncDec {
 public:
  void* mVtable;      // 0x00 - 0x12e4bc8 (cell 0x1314708 + 0x10)
  uint32_t m8;        // 0x08 - u32 copied from C1 arg (w22 at 0xa03894;
                      //   zeroed on the in-place path 0xa03864)
  uint8_t mPadC[4];   // 0x0c - ctor writes nothing (gap to member alignment)
  RC4PacketEncDec mEncDec;  // 0x10 - member; RC4 C1 0x9f3574 called on
                            //   this+0x10 (0xa0389c/0xa038a4)
};
}  // namespace nn::nex
