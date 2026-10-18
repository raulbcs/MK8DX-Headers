#pragma once

#include <cstdint>

// Vt12dd1f0 — PLACEHOLDER name (43-slot class; row is the typeinfo slot,
// installed vptr 0x12dd1f8 = row+8); secondary vptr 0x12dc458 at +0x18/+0x870.
// extent 0x1e28 - details: doc/object/Vt12dd1f0.md

namespace object {
class Vt12dd1f0 {
 public:
  void* vtable;          // 0x00 — 0x12dd1f8 (ctor 0x9797a4)
  char mPad8[0x8];       // 0x08 — unproven (+0x08 pointer zeroed, 0x97986c)
  char mSub10[0x8];      // 0x10 — unproven (+0x10 u8 zeroed, 0x979878)
  char mSub18[0x858];    // 0x18 — secondary vptr 0x12dc458 at +0x18; sub-object
                         // ctor FUN_71009721ac (0x9797a8)
  char mSub870[0x858];   // 0x870 — secondary vptr 0x12dc458 at +0x870; sub-object
                         // ctor FUN_71009721ac (0x9797c4)
  char mPad10C8[0x4b8];  // 0x10c8 — unproven (sub-object ctor 0x973a74 at +0x10c8)
  char mSub1580[0x8];    // 0x1580 — ctor-built pointer (0x979818)
  void* mField1588;      // 0x1588 — ctor zeroes (0x979864)
  uint32_t mField1590;   // 0x1590 — ctor zeroes (0x979868)
  char mPad1594[0x4];    // 0x1594 — unproven
  void* mField1598;      // 0x1598 — ctor zeroes (0x979870)
  void* mField15A0;      // 0x15a0 — ctor zeroes (0x979874)
  char mSub15A8[0x878];  // 0x15a8 — sub-object ctors 0x929ec0 (+0x15a8) and
                         // 0x9721ac (+0x15c8)
  char mPad1E20[0x8];    // 0x1e20 — unproven (+0x1e20 u8 zeroed, 0x97987c)
};
}  // namespace object
