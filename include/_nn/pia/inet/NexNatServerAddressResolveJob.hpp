#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI "N2nn3pia4inet29NexNatServerAddressResolveJobE", derives from
/// nn::pia::common::StepSequenceJob. Installed vptr 0x12d9bc8.
/// extent 0x70 (factory new at 0x92ce44) - details: doc/_nn/pia/inet/NexNatServerAddressResolveJob.md
struct NexNatServerAddressResolveJob {
  virtual void dtor();          // 0x00 slot0 (0x930f50, tail `b 0xb4a62c` base D1)
  virtual void dtorDeleting();  // 0x08 slot1 (0x930f54)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x9310e0, releases the +0x58 subobject)
  virtual void slot28();        // 0x28 slot5 (0xb4a7a4, `ret` stub)
  uint8_t mBase8[0x50];   // 0x08 - StepSequenceJob base region (base C1 0xb4a5e0)
  void* m58;              // 0x58 - subobject ptr, zeroed by C2
  void* m60;              // 0x60 - subobject ptr, zeroed by C2
  uint32_t m68;           // 0x68 - zeroed by C2 (str wzr covers 0x68..0x6b)
  uint8_t m6c[0x4];       // 0x6c - pad to size 0x70
};
}  // namespace nn::pia::inet
