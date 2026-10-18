#pragma once

#include <cstdint>

// KartParamCacheVt2cc8 — KartParamCache-family node (slots 6-8 are the
// paramNodeShared* stubs 0x647f48/0x647f60/0x647f68 + 0x647f6c). Element of an
// outer aggregate built at 0x2cc8 stride (C1 0x6c6550 called at +0x0, +0x2cc8,
// +0x5990, ... from 0x6cb614-0x6cb7f0).
// extent 0x2cc8 - details: doc/object/Kart/KartParamCacheVt2cc8.md

namespace object {
class KartParamCacheVt2cc8 {
 public:
  void* mVtable;          // 0x00 — vptr 0x12b6fa8 (C1 0x6c658c-0x6c6590)
  void* m8;               // 0x08 — base C1 0x66a2a4 (0x6c6574)
  uint8_t m10[0x20];      // 0x10 — first member C1 0x66a2a4 target (x0 = this+0x30);
                          //        unproven
  void* m30;              // 0x30 — member, C1 0x66a2a4 (0x6c6588); next member at
                          //        +0x60 via C1 0x64897c (0x6c6598-0x6c659c)
  uint8_t m38[0x450];     // 0x38 — unproven
  uint8_t m488[0x640];    // 0x488 — 50 x 0x20 member objects, vptr cell 0x130d908+0x10
                          //        (C1 0x662f30 loop 0x6c65b8-0x6c65d8)
  uint8_t mac8[0x640];    // 0xac8 — second 50 x 0x20 member array, same vptr
                          //        (loop 0x6c65e0-0x6c6604)
  uint8_t m1108[0x38];    // 0x1108 — C1 0x64bd90 (0x6c6610); zeroed 0x1118-0x1128;
                          //          0x1130 vptr cell 0x12fada0→0x12fdb0 (0x6c6644),
                          //          0x1138 self ptr, 0x1140 = 0x40, 0x1144 u16
  uint8_t m1140[0x58];    // 0x1140 — 0x40 @0x1140, u16 @0x1144; rest unproven
  void* m1198;            // 0x1198 — vptr cell 0x130d9b8+0x10 (0x6c66a4); member
                          //          objects 0x662f30 at +0x1198, +0x11b8, +0x11d8,
                          //          +0x11f8, +0x1218, +0x1238, ... (0x6c668c-0x6c6708)
  uint8_t m11a0[0x1b28];  // 0x11a0 — unproven member band (C1 continues to 0x6cb614;
                          //          D1 0x6cbf0c re-stamps base-cluster vptrs at
                          //          0x2aa8-0x2ca8, all < 0x2cc8)
};
}  // namespace object
