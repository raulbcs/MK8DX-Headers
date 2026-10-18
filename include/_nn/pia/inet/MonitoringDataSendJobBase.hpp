#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI "N2nn3pia4inet21MonitoringDataSendJobE" (true carrier of this name; the
/// pre-existing include/_nn/pia/inet/MonitoringDataSendJob.hpp documents a
/// mislabeled vtable, so this uses the Base suffix). Installed vptr 0x12dba28.
/// extent 0x71 (ctor field stores; lower bound) - details: doc/_nn/pia/inet/MonitoringDataSendJobBase.md
struct MonitoringDataSendJobBase {
  virtual void dtor();          // 0x00 slot0 (0x9647a0, re-installs vptr, tail `b 0xb4a62c`)
  virtual void dtorDeleting();  // 0x08 slot1 (0x9647d4)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared pia-job stub)
  virtual void slot28();        // 0x28 slot5 (0x964970, unrecovered)
  uint8_t mBase8[0x50];  // 0x08 - StepSequenceJob base region (base C1 0xb4a5e0)
  void* m58;             // 0x58 - subobject ptr, inited by 0x929ec0
  void* m60;             // 0x60 - subobject ptr, inited by 0x929ec0
  uint8_t m68;           // 0x68 - subobject bool, zeroed by 0x929ec0 (last byte)
  uint8_t mPad69[8]; // 0x69 - unproven (extent 0x71 lower bound)
};
}  // namespace nn::pia::inet
