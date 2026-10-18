#pragma once

#include <cstdint>

namespace nn::pia::common {
/// RTTI "N2nn3pia6common13ISerializableE" (abstract interface, no base).
/// Typeinfo-row vtable: assigned row 0x12dd3e0, installed vptr 0x12dd3e8.
/// extent 0x18 (base-init stores; tail pad unverified) - details: doc/_nn/pia/common/ISerializable.md
struct ISerializable {
  virtual void slot0();         // 0x00 slot0 (0x97da50, `ret` stub)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97d9b4, tail `b operator delete`)
  virtual void slot10();        // 0x10 slot2 (0x97cecc, size 0x5c, unrecovered)
  virtual void slot18();        // 0x18 slot3 (0x97cf28, size 0x4c, unrecovered)
  virtual void slot20();        // 0x20 slot4 (0x97d140, unrecovered)
  virtual void slot28();        // 0x28 slot5 (0x97cf70, `ret` stub)
  virtual void slot30();        // 0x30 slot6 = 0 (null sentinel)
  void* vtable;     // 0x00 - 0x12dd3e8 (GOT cell 0x1313650 holds vptr-0x10)
  uint32_t m8;      // 0x08 - zeroed by every base-init
  char mBuffer[11]; // 0x0c - memset(0, 0xb) by every base-init
  uint8_t mPad17[1]; // 0x17 - unproven alignment tail (no store observed)
};
}  // namespace nn::pia::common
