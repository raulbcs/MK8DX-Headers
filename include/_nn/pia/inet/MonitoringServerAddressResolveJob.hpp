#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI "N2nn3pia4inet33MonitoringServerAddressResolveJobE", derives from
/// nn::pia::common::StepSequenceJob. Installed vptr 0x12daa48.
/// extent 0x90 (ctor field stores; lower bound) - details: doc/_nn/pia/inet/MonitoringServerAddressResolveJob.md
struct MonitoringServerAddressResolveJob {
  virtual void dtor();          // 0x00 slot0 (0x93b38c, re-installs vptr, tail `b 0xb4a62c`)
  virtual void dtorDeleting();  // 0x08 slot1 (0x93b3c0)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared pia-job stub)
  virtual void slot28();        // 0x28 slot5 (0xb4a7a4, `ret` stub)
  uint8_t mBase8[0x50];   // 0x08 - StepSequenceJob base region (base C1 0xb4a5e0)
  void* m58;              // 0x58 - subobject ptr, inited by 0x929ec0
  void* m60;              // 0x60 - subobject ptr, inited by 0x929ec0
  uint8_t m68;            // 0x68 - subobject bool, zeroed by 0x929ec0
  uint8_t m69[0xf];       // 0x69 - pad to 0x78
  uint64_t m78;           // 0x78 - zeroed by C2
  uint32_t m80;           // 0x80 - zeroed by C2
  uint64_t m88;           // 0x88 - zeroed by C2 (last store reaches 0x8f)
  uint8_t mPad84[4]; // 0x84 - unproven (extent 0x90 lower bound)
};
}  // namespace nn::pia::inet
