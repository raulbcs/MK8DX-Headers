#pragma once

#include <cstdint>

namespace nn::pia::lan {
/// RTTI-confirmed (N2nn3pia3lan28LanLeaveWithHostMigrationJobE). Typeinfo-row vtable:
/// assigned 0x12dcb90, real vptr 0x12dcb98 (GOT cell 0x1313418 holds vptr-0x10).
/// No construction sites found.
/// extent 0x88 (slot-store lower bound) - details: doc/_nn/pia/lan/LanLeaveWithHostMigrationJob.md
struct LanLeaveWithHostMigrationJob {
  virtual void dtor();          // 0x00 slot0 (0x9756d8)
  virtual void dtorDeleting();  // 0x08 slot1 (0x9756dc)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared `ret` stub)
  virtual void slot28();        // 0x28 slot5 (0x975788)
  virtual void slot30();        // 0x30 slot6 (0x975700, 0x140-byte step fn)
  virtual void slot38();        // 0x38 slot7 (0x9864ec, shared with InetLeaveWithHostMigrationJob)
  uint8_t mBase8[0x80];         // 0x08 - base region (session::LeaveWithHostMigrationJob)
};
}  // namespace nn::pia::lan
