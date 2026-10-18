#pragma once

#include <cstdint>

namespace nn::pia::lan {
/// RTTI-confirmed (N2nn3pia3lan25LanMatchDestroySessionJobE). Typeinfo-row vtable:
/// assigned 0x12dccf0, real vptr 0x12dccf8 (GOT cell 0x1313468 holds vptr-0x10). No construction sites found.
/// extent 0x88 (base-region stores; lower bound) - details: doc/_nn/pia/lan/LanMatchDestroySessionJob.md
struct LanMatchDestroySessionJob {
  virtual void dtor();          // 0x00 slot0 (0x9761c0, b 0x97f0d4 base dtor fwd)
  virtual void dtorDeleting();  // 0x08 slot1 (0x9761c4, base dtor + operator delete)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared job slot)
  virtual void slot28();        // 0x28 slot5 (0x976334)
  virtual void slot30();        // 0x30 slot6 (0x976330)
  virtual void slot38();        // 0x38 slot7 (0x9761e8)
  virtual void slot40();        // 0x40 slot8 (0x9761f0)
  virtual void slot48();        // 0x48 slot9 (0x97620c)
  uint8_t mBase8[0x80];         // 0x08 - base region (base ctor 0x97f094: zeroes +0x58, inits +0x60 via 0x929ec0, zeroes +0x80)
};
}  // namespace nn::pia::lan
