#pragma once

#include <cstdint>

// nn::pia::inet::NexUpdateSessionSetting — RTTI-named (embedded typeinfo at
// 0x12da440). Enclosing-object member, size 0x630 stride-proven (instances at
// enclosing+0x2b8 and +0x8e8, same C1). extent 0x630 - details:
// doc/_nn/pia/inet/NexUpdateSessionSetting.md

namespace nn::pia::inet {
class NexUpdateSessionSetting {
 public:
  void* mVtable;            // 0x00 — vptr 0x12da3e8 (GOT cell 0x13129b0
                            //   holds vptr-0x10; C1 adds 0x10, 0x935448)
  uint8_t mPad08[0x4];      // 0x08 — base region (base C1 0x99f488)
  uint16_t mField0c;        // 0x0c — 0xffff (C1 0x935428)
  uint16_t mField0e;        // 0x0e — 0xffff (C1 0x93542c)
  uint32_t mField10;        // 0x10 — zeroed (C1 0x935474)
  uint8_t mField14;         // 0x14 — zeroed (C1 0x935454)
  uint8_t mPad15[0x223];    // 0x15 — unproven gap
  uint32_t mField238;       // 0x238 — zeroed (C1 0x935458)
  uint8_t mField23c;        // 0x23c — zeroed
  uint8_t mPad23d[0x3];     // 0x23d — gap
  void* mVtable240;         // 0x240 — secondary vptr, cell 0x1312850 + 0x10
  void* mPtr248;            // 0x248 — set to this+0x25c (array self-ptr)
  uint32_t mField250;       // 0x250 — 0x80 (C1 0x93543c)
  uint32_t mField254;       // 0x254 — zeroed
  uint32_t mField258;       // 0x258 — zeroed
  uint8_t mArray25c[0x81];  // 0x25c — 43 x {u16,u8} entries zeroed by C1 loop
  uint8_t mPad2dd[0x3];     // 0x2dd — array tail gap
  void* mVtable2e0;         // 0x2e0 — same secondary vptr as +0x240
  void* mPtr2e8;            // 0x2e8 — set to this+0x2fc (array self-ptr)
  uint32_t mField2f0;       // 0x2f0 — 0x80
  uint32_t mField2f4;       // 0x2f4 — zeroed
  uint32_t mField2f8;       // 0x2f8 — zeroed
  uint8_t mArray2fc[0x81];  // 0x2fc — second 43-entry array (C1 0x9354c0)
  uint8_t mPad37d[0x3];     // 0x37d — array tail gap
  void* mVtable380;         // 0x380 — secondary vptr, cell 0x1312968 + 0x10
  uint16_t mField388;       // 0x388 — zeroed
  uint16_t mField38a;       // 0x38a — zeroed
  uint16_t mField38c;       // 0x38c — zeroed
  uint8_t mPad38e[0x1a];    // 0x38e — gap
  void* mVtable3a8;         // 0x3a8 — secondary vptr, cell 0x1312848 + 0x10
  uint8_t mPad3b0[0x28];    // 0x3b0 — gap
  void* mVtable3d8;         // 0x3d8 — secondary vptr, cell 0x1312858 + 0x10
  uint8_t mPad3e0[0x38];    // 0x3e0 — gap
  void* mVtable418;         // 0x418 — same secondary vptr as +0x3d8
  uint8_t mPad420[0x38];    // 0x420 — gap
  void* mVtable458;         // 0x458 — same secondary vptr as +0x3d8
  uint8_t mPad460[0x68];    // 0x460 — gap
  void* mVtable4c8;         // 0x4c8 — same secondary vptr as +0x3d8
  uint8_t mPad4d0[0x160];   // 0x4d0 — unverified tail to 0x630
};
}  // namespace nn::pia::inet
