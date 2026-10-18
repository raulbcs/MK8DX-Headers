#pragma once

#include <cstdint>

namespace object {

// Vt12b9d78 - PLACEHOLDER name; thin accessor record over the global
// descriptor table 0x12b7b28 (stride 0x38, indexed by [this+0x40]). No
// standalone C1: built inline by the registry builder at 0x6cfe14
// (operator new 0x50 via 0x60b234). Sibling of Vt12b9e38 (3 slots differ).
// extent 0x50 - details: doc/object/Vt12b9d78.md

class Vt12b9d78 {
 public:
  void* vtable;         // 0x00 - 0x12b9d78 (no GOT cell; installed by
                        // adrp/add pair at 0x6cfe14..0x6cfe24)
  void* mContext08;     // 0x08 - registry-builder x20 (0x6cfde4)
  uint32_t mId10;       // 0x10 - sequence id (0x1f, 0x20, ...;
                        // 0x6cfdc8); also the descriptor-table index
                        // source is +0x40
  uint8_t mPad14[0x4];  // 0x14 - unproven
  void* mField18;       // 0x18 - pointer picked from the x9 table
                        // (+0x1f0/+0x200/+0x230 by id compare,
                        // 0x6cfdd8..0x6cfdf0)
  void* mSelf20;        // 0x20 - points at itself (0x6cfdf4)
  void* mSelf28;        // 0x28 - points at itself (0x6cfdf4)
  void* mField30;       // 0x30 - zero (0x6cfdec)
  void* mField38;       // 0x38 - zero (0x6cfdec)
  uint32_t mIndex40;    // 0x40 - descriptor index (0x25 for this
                        // class, 0x6cfde0/0x6cfde8); consumed by the
                        // table-accessor slots
  uint32_t mField44;    // 0x44 - result of bl 0x62fd48 (0x6cfe08)
  uint32_t mField48;    // 0x48 - result of bl 0x62fd48
  uint8_t mPad4c[0x4];  // 0x4c - unproven
};

}  // namespace object
