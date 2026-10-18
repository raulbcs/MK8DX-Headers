#pragma once

#include <cstdint>

namespace nn::pia::session {
/// RTTI "N2nn3pia7session25LeaveWithHostMigrationJobE", derives from
/// nn::pia::common::StepSequenceJob (base typeinfo 0x12f8d30, base C1 0xb4a5e0).
/// extent 0x98 (ctor field stores; lower bound) - details: doc/_nn/pia/session/LeaveWithHostMigrationJob.md
struct LeaveWithHostMigrationJob {
  virtual void dtor();          // 0x00 slot0 (0x985e34, tail `b 0xb4a62c` base D1)
  virtual void dtorDeleting();  // 0x08 slot1 (0x985e38, D1 -> operator delete)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x933314)
  virtual void slot28();        // 0x28 slot5 (0x986578, logs 0xc0810000-style marker)
  virtual void slot30() = 0;    // 0x30 slot6 (null in table)
  virtual void slot38();        // 0x38 slot7 (0x9864ec, re-inits +0x70/+0x74 region)
  virtual void slot40() = 0;    // 0x40 slot8 (null in table)
  uint8_t mBase8[0x50];  // 0x08 — StepSequenceJob base region (base C1 0xb4a5e0)
  uint64_t m58;          // 0x58 — zeroed by C2 (stp xzr,xzr +0x58)
  uint64_t m60;          // 0x60 — zeroed by C2
  uint32_t m68;          // 0x68 — C2 stores 5000 (0x1388)
  uint8_t m6C;           // 0x6c — zeroed by C2
  uint8_t mPad6D[3];     // 0x6d — ctor writes nothing
  uint32_t m70;          // 0x70 — C2 stores 0xfd (253)
  uint8_t m74[0x20];     // 0x74 — zeroed by C2 memset(this+0x74, 0, 0x20)
  uint8_t m94;           // 0x94 — zeroed by C2
  uint8_t mPad95[3];     // 0x95 — unproven (extent 0x98 lower bound)
};
}  // namespace nn::pia::session
