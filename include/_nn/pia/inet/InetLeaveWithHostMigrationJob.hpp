#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet29InetLeaveWithHostMigrationJobE). Typeinfo-row vtable:
/// assigned 0x12da6f0, real vptr 0x12da6f8 (GOT cell 0x1312aa8 holds vptr-0x10).
/// No construction sites found.
/// extent 0x98 (slot-store lower bound) - details: doc/_nn/pia/inet/InetLeaveWithHostMigrationJob.md
struct InetLeaveWithHostMigrationJob {
  virtual void dtor();          // 0x00 slot0 (0x9381f0)
  virtual void dtorDeleting();  // 0x08 slot1 (0x9381f4)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared `ret` stub)
  virtual void slot28();        // 0x28 slot5 (0x9382a0)
  virtual void slot30();        // 0x30 slot6 (0x938218, 0x220-byte step fn)
  virtual void slot38();        // 0x38 slot7 (0x9864ec, shared with LanLeaveWithHostMigrationJob)
  uint8_t mBase8[0x90];         // 0x08 - base region (session::LeaveWithHostMigrationJob)
};
}  // namespace nn::pia::inet
