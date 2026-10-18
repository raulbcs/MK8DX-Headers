#pragma once

#include <cstdint>

#include "_nn/pia/lan/LanMessage.hpp"

namespace nn::pia::lan {
/// RTTI "N2nn3pia3lan20LanGetSessionMessageE" (base lan::LanMessage).
/// Typeinfo-row vtable: assigned row 0x12dd4e0, installed vptr 0x12dd4e8.
/// extent 0x348 (stores to +0x344; alignment tail unverified) - details: doc/_nn/pia/lan/LanGetSessionMessage.md
struct LanGetSessionMessage : public LanMessage {
  virtual void slot0();         // 0x00 slot0 (0x97da50, `ret` stub)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97da34, tail `b operator delete`)
  virtual void slot10();        // 0x10 slot2 (0x97d678, size 0x664, unrecovered)
  virtual void slot18();        // 0x18 slot3 (0x97d76c, unrecovered; inside the 0x97d678 TU per csv)
  virtual uint32_t getPayloadSize();  // 0x20 slot4 (0x97da38: ldr w0,[this+0x340]; add w0,#0x18)
  virtual void slot28();        // 0x28 slot5 (0x97cf70, `ret` stub)
  virtual void slot30();        // 0x30 slot6 = 0 (null sentinel)
  // base LanMessage extent 0x20 (tag 6 at +0x8 written by both C1s)
  uint16_t m20[0x190];  // 0x20 - inline payload buffer, 0x320 bytes (copy capped at 0x320 by the C1-with-arg; contents unverified)
  uint32_t m340;        // 0x340 - payload size (0 by default C1; capped at 0x320 by C1-with-arg)
  uint8_t mPad344[4];   // 0x344 - unproven alignment tail
};
}  // namespace nn::pia::lan
