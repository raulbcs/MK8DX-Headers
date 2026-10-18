#pragma once

#include <cstdint>

#include "_nn/pia/lan/LanMessage.hpp"

namespace nn::pia::lan {
/// RTTI "N2nn3pia3lan17LanGetHostMessageE" (base lan::LanMessage).
/// Typeinfo-row vtable: assigned row 0x12dd460, installed vptr 0x12dd468.
/// extent 0xa0 (member at +0x20 sized >=0x80; tail unverified) - details: doc/_nn/pia/lan/LanGetHostMessage.md
struct LanGetHostMessage : public LanMessage {
  virtual void dtorComplete();  // 0x00 slot0 (0x97d9c4: re-install own vptr, destroy +0x20 member)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97d9d8: same then `b operator delete` tail)
  virtual void slot10();        // 0x10 slot2 (0x97d224, size 0xd4, unrecovered)
  virtual void slot18();        // 0x18 slot3 (0x97d2f8, size 0x9c, unrecovered)
  virtual uint32_t getPayloadSize();  // 0x20 slot4 (0x97da0c: member fn 0x9b21c0(this+0x20) + 0x10)
  virtual void slot28();        // 0x28 slot5 (0x97cf70, `ret` stub)
  virtual void slot30();        // 0x30 slot6 = 0 (null sentinel)
  // base LanMessage extent 0x20 (tag 4 at +0x8 written by both C1s)
  struct Member {  // 0x20 - sub-object, vptr from GOT cell 0x1313c40
    void* vtable;       // +0x00 - 0x1313c50
    uint8_t mPad8[0x78];  // +0x08 - unproven: C1 0x9b1fe8 inits sub-objects at +0x08 and +0x40 (0x40 stride); full extent unverified
  };
  Member m20;    // 0x20 - extent 0xa0 is a lower bound (member tail unverified)
};
}  // namespace nn::pia::lan
