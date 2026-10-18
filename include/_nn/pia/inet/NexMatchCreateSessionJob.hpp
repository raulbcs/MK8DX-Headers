#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet24NexMatchCreateSessionJobE). Typeinfo-row vtable:
/// assigned 0x12dada0, real vptr 0x12dada8 (GOT cell 0x1312c98 holds vptr-0x10). No construction sites found.
/// extent 0xc0 (ctor field stores; lower bound) - details: doc/_nn/pia/inet/NexMatchCreateSessionJob.md
struct NexMatchCreateSessionJob {
  virtual void dtor();          // 0x00 slot0 (0x93dd88, b 0x97e934 base dtor fwd)
  virtual void dtorDeleting();  // 0x08 slot1 (0x93dd8c)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared job slot)
  virtual void slot28();        // 0x28 slot5 (0x93ec88)
  virtual void slot30();        // 0x30 slot6 (0x93ec60)
  virtual void slot38();        // 0x38 slot7 (0x93ddb0)
  virtual void slot40();        // 0x40 slot8 (0x93eaf8)
  virtual void slot48();        // 0x48 slot9 (0x93eb14)
  uint8_t mBase8[0x80];         // 0x08 - base region (base ctor 0x97e8f4: zeroes +0x58, inits +0x60 via 0x929ec0, zeroes w +0x80)
  uint32_t mField88;            // 0x88 - zeroed by ctor 0x93dd60
  uint8_t mPad8c[0x1c];         // 0x8c - unverified gap (ctor writes nothing)
  uint64_t mFielda8;            // 0xa8 - zeroed by ctor 0x93dd60
  uint8_t mFieldb0;             // 0xb0 - zeroed by ctor 0x93dd60
  uint8_t mPadb1[7];            // 0xb1 - ctor writes nothing
  uint64_t mFieldb8;            // 0xb8 - zeroed by ctor 0x93dd60
};
}  // namespace nn::pia::inet
