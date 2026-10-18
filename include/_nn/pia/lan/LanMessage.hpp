#pragma once

#include <cstdint>

#include "_nn/pia/common/ISerializable.hpp"

namespace nn::pia::lan {
/// RTTI "N2nn3pia3lan10LanMessageE" (base nn::pia::common::ISerializable).
/// Typeinfo-row vtable: assigned row 0x12dd420, installed vptr 0x12dd428.
/// extent 0x20 (ctor stores to +0x1c; alignment tail unverified) - details: doc/_nn/pia/lan/LanMessage.md
struct LanMessage : public nn::pia::common::ISerializable {
  virtual void slot0();         // 0x00 slot0 (0x97da50, `ret` stub)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97d9b8, tail `b operator delete`)
  virtual void slot10();        // 0x10 slot2 (0x97d030, size 0x90, unrecovered)
  virtual void slot18();        // 0x18 slot3 (0x97d0c0, size 0x88, unrecovered)
  virtual uint32_t getPayloadSize();  // 0x20 slot4 (0x97d9bc: `orr w0,#0x10; ret`)
  virtual void slot28();        // 0x28 slot5 (0x97cf70, `ret` stub)
  virtual void slot30();        // 0x30 slot6 = 0 (null sentinel)
  uint32_t m18;  // 0x18 - written by C1 arg (0 by default ctor)
  uint8_t mPad1c[4];  // 0x1c - unproven alignment tail
};
}  // namespace nn::pia::lan
