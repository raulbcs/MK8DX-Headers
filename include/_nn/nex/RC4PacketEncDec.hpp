#pragma once

#include <cstdint>

namespace nn::nex {
// RC4PacketEncDec — RTTI-named (typeinfo 0x12e4290, name
// "N2nn3nex15RC4PacketEncDecE"; base 0x12e4270 PacketEncDecInf). GOT cell
// 0x1314560 holds vptr-0x10; C1/D1 add 0x10.
// extent 0xc0 - details: doc/_nn/nex/RC4PacketEncDec.md
class RC4PacketEncDec {
 public:
  void* mVtable;            // 0x00 - 0x12e3240 (cell 0x1314560 + 0x10)
  void* mVec8Begin;         // 0x08 - vector begin (heap, alloc 8 via 0x576368;
                            //   C1 0x9f35a4)
  void* mVec10End;          // 0x10 - vector end; C1 pushes one null element
  void* mVec18Cap;          // 0x18 - capacity end (begin + 8)
  void* mVec20Begin;        // 0x20 - second vector begin (alloc 8, one null
                            //   element; C1 0x9f35d0)
  void* mVec28End;          // 0x28 - second vector end
  void* mVec30Cap;          // 0x30 - second vector capacity end
  void* m38;                // 0x38 - heap object (0x573f04 alloc), body
                            //   init 0x583dc8 + 0x584230; D1 releases via
                            //   [vt+8] (0x9f371c)
  uint8_t mPad40[0x28];     // 0x40 - member, init 0x58b7dc, destroyed by
                            //   0x58bc04 (0x9f3740)
  uint8_t mPad68[0x28];     // 0x68 - member, init 0x58b958(., 0x20), destroyed
                            //   by 0x58bc04 (0x9f3738)
  uint8_t mPad90[0x28];     // 0x90 - member, init 0x58b958(., 0x20), destroyed
                            //   by 0x58bc04 (0x9f3730)
  uint8_t mB8;              // 0xb8 - zeroed by C1 (0x9f3610)
  uint8_t mPadB9;           // 0xb9 - unproven gap
  uint16_t mBa;             // 0xba - set to 1 by C1 (0x9f3614)
  uint32_t mPadBc;          // 0xbc - unproven gap
};
}  // namespace nn::nex
