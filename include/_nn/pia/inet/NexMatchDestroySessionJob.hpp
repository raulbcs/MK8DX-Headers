#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet25NexMatchDestroySessionJobE). Typeinfo-row vtable:
/// assigned 0x12dae20, real vptr 0x12dae28 (GOT cell 0x1312d00 holds vptr-0x10). No construction sites found.
/// extent 0x88 (base-region stores; lower bound) - details: doc/_nn/pia/inet/NexMatchDestroySessionJob.md
struct NexMatchDestroySessionJob {
  virtual void dtor();          // 0x00 slot0 (0x93ecbc, b 0x97f0d4 base dtor fwd)
  virtual void dtorDeleting();  // 0x08 slot1 (0x93ecc0)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared job slot)
  virtual void slot28();        // 0x28 slot5 (0x93f0e4)
  virtual void slot30();        // 0x30 slot6 (0x93f0e0)
  virtual void slot38();        // 0x38 slot7 (0x93ece4)
  virtual void slot40();        // 0x40 slot8 (0x93ecec)
  virtual void slot48();        // 0x48 slot9 (0x93ed08)
  uint8_t mBase8[0x80];         // 0x08 - base region (base ctor 0x97f094: zeroes +0x58, inits +0x60 via 0x929ec0, zeroes +0x80)
};
}  // namespace nn::pia::inet
