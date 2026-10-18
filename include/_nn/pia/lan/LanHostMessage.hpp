#pragma once

#include <cstdint>

#include "_nn/pia/lan/LanMessage.hpp"

namespace nn::pia::lan {
/// RTTI "N2nn3pia3lan14LanHostMessageE" (base lan::LanMessage).
/// Typeinfo-row vtable: assigned row 0x12dd4a0, installed vptr 0x12dd4a8.
/// extent 0x20 (ctor stores to +0x1c; alignment tail unverified) - details: doc/_nn/pia/lan/LanHostMessage.md
struct LanHostMessage : public LanMessage {
  virtual void slot0();         // 0x00 slot0 (0x97da50, `ret` stub)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97da28, tail `b operator delete`)
  virtual void slot10();        // 0x10 slot2 (0x97d450, size 0x90, unrecovered)
  virtual void slot18();        // 0x18 slot3 (0x97d4e0, unrecovered; csv size 0x408 merges the next TU)
  virtual uint32_t getPayloadSize();  // 0x20 slot4 (0x97da2c: `orr w0,#0x10; ret`)
  virtual void slot28();        // 0x28 slot5 (0x97cf70, `ret` stub)
  virtual void slot30();        // 0x30 slot6 = 0 (null sentinel)
  // base LanMessage extent 0x20 (no own fields; tag 5 at +0x8 written by both C1s)
};
}  // namespace nn::pia::lan
