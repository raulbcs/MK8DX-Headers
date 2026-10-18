#pragma once

#include <cstdint>

namespace nn::pia::lan {
/// RTTI-confirmed (N2nn3pia3lan24LanMatchCreateSessionJobE). Typeinfo-row vtable:
/// assigned 0x12dcc70, real vptr 0x12dcc78 (GOT cell 0x1313440 holds vptr-0x10). No construction sites found.
/// extent 0x98 (ctor field stores; lower bound) - details: doc/_nn/pia/lan/LanMatchCreateSessionJob.md
struct LanMatchCreateSessionJob {
  virtual void dtor();          // 0x00 slot0 (0x975bf4, b 0x97e934 base dtor fwd)
  virtual void dtorDeleting();  // 0x08 slot1 (0x975bf8, base dtor + operator delete)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared job slot)
  virtual void slot28();        // 0x28 slot5 (0x97618c)
  virtual void slot30();        // 0x30 slot6 (0x976168)
  virtual void slot38();        // 0x38 slot7 (0x975c1c)
  virtual void slot40();        // 0x40 slot8 (0x975f40)
  virtual void slot48();        // 0x48 slot9 (0x975fc0)
  uint8_t mBase8[0x7c];         // 0x08 - base region (base ctor 0x97e8f4: zeroes +0x58, inits +0x60 via 0x929ec0, zeroes w +0x80)
  uint32_t mField84;            // 0x84 - zeroed by ctor 0x975bcc
  uint64_t mField88;            // 0x88 - zeroed by ctor 0x975bcc
  uint8_t mField90;             // 0x90 - set to 1 by ctor 0x975bcc
  uint8_t mPad91[7];            // 0x91 - ctor writes nothing
};
}  // namespace nn::pia::lan
