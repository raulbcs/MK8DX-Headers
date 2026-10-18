#pragma once

#include <cstdint>

namespace nn::pia::nat {
// NatTraversalProtocol — RTTI-named (typeinfo 0x12dbeb0, name
// "N2nn3pia3nat20NatTraversalProtocolE"); derived from the abstract pia
// protocol base (base C1 0x9a79c8). 11 slots; GOT cell 0x13132b0 holds
// vptr-0x10 (vptr 0x12dbe50).
// extent 0xe78 - details: doc/_nn/pia/nat/NatTraversalProtocol.md
class NatTraversalProtocol {
 public:
  void* mVtable;          // 0x00 - vptr 0x12dbe50 (cell 0x13132b0 + 0x10)
  uint64_t m08;           // 0x08 - zeroed by base C1 (0x9a79d4)
  uint64_t m10;           // 0x10 - zeroed by base C1
  uint16_t m18;           // 0x18 - max payload, base C1 from cell 0x1313b98
  uint8_t mPad1a[0xe];    // 0x1a - unproven gap
  uint32_t m28;           // 0x28 - C1 stores 0 (0x9692bc)
  uint8_t mPad2c[0x4];    // 0x2c - unproven
  void* mSub30;           // 0x30 - member subobject (C1/D 0x9b38b8)
  uint8_t mPad38[0x30];   // 0x38 - unproven
  void* mSub68;           // 0x68 - member subobject (C1/D 0x9b38b8)
  uint8_t mPad70[0x30];   // 0x70 - unproven
  void* mSuba0;           // 0xa0 - member subobject (C1 0x929ec0)
  uint8_t mPada8[0x20];   // 0xa8 - unproven
  void* mListc8;          // 0xc8 - node list head (D1 walks it, 0x96957c);
                          //   sentinel = this+0xc8
  uint8_t mPadd0[0x8];    // 0xd0 - unproven
  uint32_t mCountd8;      // 0xd8 - list node count (D1 loop bound)
  uint8_t mPaddc[0x4];    // 0xdc - unproven
  void* mPoolE0;          // 0xe0 - allocation pool arg for the +0xc8 list
  uint8_t mPade8[0x30];   // 0xe8 - unproven
  void* mList118;         // 0x118 - second node list head (sentinel
                          //   this+0x118)
  uint8_t mPad120[0x8];   // 0x120 - unproven
  uint32_t mCount128;     // 0x128 - second list node count
  uint8_t mPad12c[0x4];   // 0x12c - unproven
  void* mPool130;         // 0x130 - pool arg for the +0x118 list
  uint8_t mPad138[0x30];  // 0x138 - unproven
  void* mSub168;          // 0x168 - list head (sentinel this+0x168), cleared
                          //   by D1 region 0x9693bc
  uint8_t mPad170[0x24];  // 0x170 - unproven
  uint32_t mCount194;     // 0x194 - its node count
  uint8_t mPad198[0x18];  // 0x198 - unproven
  void* mSub1b0;          // 0x1b0 - member subobject (C1 0x969450)
  void* mList1b8;         // 0x1b8 - list head (sentinel this+0x1b8)
  uint8_t mPad1c0[0x24];  // 0x1c0 - unproven
  uint32_t mCount1e4;     // 0x1e4 - its node count
  uint8_t mPad1e8[0xc30]; // 0x1e8 - unproven bulk region
  void* mSube18;          // 0xe18 - member subobject (C1/D 0x9b38b8)
  uint8_t mPade20[0x30];  // 0xe20 - unproven
  uint8_t mZeroe50;       // 0xe50 - C1 stores 0 (0x969324)
  uint8_t mPade51[0x7];   // 0xe51 - unproven
  uint64_t mZeroe58;      // 0xe58 - C1 stores 0 (0x969328)
  uint64_t mZeroe60;      // 0xe60 - C1 stores 0 (0x96932c)
  void* mSube68;          // 0xe68 - member subobject (C1 0x573c38)
  uint8_t mPade70[0x8];   // 0xe70 - tail padding (member is 0x10 bytes ->
                          //   size 0xe78)
};
}  // namespace nn::pia::nat
