#pragma once

#include <cstdint>

namespace object {
// Vt12b1748 - PLACEHOLDER name; static singleton instance (pointer cached in
// GOT cell 0x130d6c0), intrusive-list node with three owned pointers. No RTTI.
// extent 0x50 (lower bound, max field store) - details: doc/object/Vt12b1748.md
class Vt12b1748 {
 public:
  void* mVtable;      // 0x00 - 0x12b1748 (GOT cell 0x130d6d0 holds vt-0x10;
                      //        static init first stores cell 0x130d128+0x10
                      //        = 0x12af920 before the final vptr)
  uint8_t m8;         // 0x08 - flag, 0 (0x634664); read by slot 14 (0x634a40)
  uint8_t mPad9[0x7];   // 0x09 - unproven
  void* m10;          // 0x10 - 0 (0x634680)
  void* m18;          // 0x18 - secondary vptr 0x12b17d0 (GOT cell 0x130d6d8
                      //        +0x10; reinstalled by D1 0x634724)
  void* m20;          // 0x20 - intrusive list head, this+0x20 (0x63464c)
  void* m28;          // 0x28 - intrusive list tail, this+0x20 (0x63464c)
  uint32_t m30;       // 0x30 - 0 (0x634668)
  uint8_t mPad34[0x4];  // 0x34 - unproven
  void* m38;          // 0x38 - owned ptr, destroyed+deleted by D1 (0x6346a4)
  void* m40;          // 0x40 - owned ptr, deleted via virtual slot 3 (0x6346f8)
  void* m48;          // 0x48 - owned ptr, deleted via virtual slot 4 (0x634710)
};
}  // namespace object
