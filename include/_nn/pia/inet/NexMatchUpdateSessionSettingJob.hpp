#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet31NexMatchUpdateSessionSettingJobE). Typeinfo-row vtable:
/// assigned 0x12db390, real vptr 0x12db398 (GOT cell 0x1313118 holds vptr-0x10). No construction sites found.
/// extent 0x8c (ctor field store; lower bound) - details: doc/_nn/pia/inet/NexMatchUpdateSessionSettingJob.md
struct NexMatchUpdateSessionSettingJob {
  virtual void dtor();          // 0x00 slot0 (0x9536c4, b 0x99f51c base dtor fwd)
  virtual void dtorDeleting();  // 0x08 slot1 (0x9536c8)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared job slot)
  virtual void slot28();        // 0x28 slot5 (0x954498)
  virtual void slot30();        // 0x30 slot6 (0x953f2c)
  virtual void slot38();        // 0x38 slot7 (0x9536ec)
  virtual void slot40();        // 0x40 slot8 (0x99f6f8)
  virtual void slot48();        // 0x48 slot9 (0x99f708)
  uint8_t mBase8[0x80];         // 0x08 - base region (base ctor 0x99f4e4: zeroes +0x58, inits +0x60, zeroes w +0x80)
  uint32_t mField88;            // 0x88 - zeroed by ctor 0x9536a8
};
}  // namespace nn::pia::inet
