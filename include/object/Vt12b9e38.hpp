#pragma once

#include <cstdint>

namespace object {

// Vt12b9e38 - PLACEHOLDER name; sibling of Vt12b9d78 (shares 19 of 22
// slots byte-for-byte; differs at +0x88/+0x90/+0xa8). No standalone C1:
// built inline by the registry builder at 0x6cfec8 (operator new 0x50 via
// 0x60b234). extent 0x50 - details: doc/object/Vt12b9e38.md

class Vt12b9e38 {
 public:
  void* vtable;         // 0x00 - 0x12b9e38 (no GOT cell; installed by
                        // adrp/add pair at 0x6cfec8..0x6cfed8)
  void* mContext08;     // 0x08 - registry-builder x20 (0x6cfe90)
  uint32_t mId10;       // 0x10 - sequence id (0x20 here; 0x6cfe68)
  uint8_t mPad14[0x4];  // 0x14 - unproven
  void* mField18;       // 0x18 - pointer picked from the x9 table
                        // (+0x200 branch, 0x6cfe80..0x6cfe94)
  void* mSelf20;        // 0x20 - points at itself (0x6cfea8)
  void* mSelf28;        // 0x28 - points at itself (0x6cfea8)
  void* mField30;       // 0x30 - zero (0x6cfea0)
  void* mField38;       // 0x38 - zero (0x6cfea0)
  uint32_t mIndex40;    // 0x40 - descriptor index (0x26 here,
                        // 0x6cfe88/0x6cfea4); consumed by the
                        // table-accessor slots
  uint32_t mField44;    // 0x44 - result of bl 0x62fd48 (0x6cfebc)
  uint32_t mField48;    // 0x48 - result of bl 0x62fd48
  uint8_t mPad4c[0x4];  // 0x4c - unproven
};

}  // namespace object
