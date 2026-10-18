#pragma once

#include <cstdint>

// nn::pia::local::LocalLeaveWithHostMigrationJobNew — RTTI-confirmed (typeinfo
// 0x12e19d0, base pia::session::LeaveWithHostMigrationJob); vptr 0x12e1988.
// extent 0xa0 - details: doc/_nn/pia/local/LocalLeaveWithHostMigrationJobNew.md
namespace nn::pia::local {
class LocalLeaveWithHostMigrationJobNew {
 public:
  void* mVtable;         // 0x00 — 0x12e1988 (GOT cell 0x1314040 = vptr-0x10)
  char mJobBase8[0x50];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  void* m58;             // 0x58 — 0 (base C1 0x985df8)
  void* m60;             // 0x60 — 0 (base C1 0x985df8)
  uint32_t m68;          // 0x68 — 5000 (base C1 0x985e0c, timeout ms?)
  uint8_t m6c;           // 0x6c — 0 (base C1 0x985df4)
  char mPad6d[0x3];      // 0x6d — unproven gap
  uint32_t m70;          // 0x70 — 0xfd (base C1 0x985e14)
  char mPad74[0x24];     // 0x74 — memset 0 (base C1 0x985e1c); 0x94-0x98 unproven gap
  void* m98;             // 0x98 — C1 arg x1 (target session; [x+0x18] used by slots 6/7)
};
}  // namespace nn::pia::local
