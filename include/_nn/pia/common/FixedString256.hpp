#pragma once

#include <cstdint>

namespace nn::pia::common {
/// RTTI "N2nn3pia6common11FixedStringILj256EEE" (nn::pia::common::FixedString<256>,
/// 4-byte elements, derives from nn::pia::common::String). Installed vptr 0x12dabd8.
/// extent 0x41c (ctor field stores; lower bound) - details: doc/_nn/pia/common/FixedString256.md
struct FixedString256 {
  virtual void slot0();         // 0x00 slot0 (0x9118d8, shared with FixedString<16>; role unverified)
  virtual void dtorDeleting();  // 0x08 slot1 (0x93b9d4, tail `b operator delete`)
  virtual void slot10();        // 0x10 slot2 (0x92a7e8, shared, size 0x396, unrecovered)
  virtual void reset();         // 0x18 slot3 (0x93b778, zeroes buffer and re-points cursor)
  virtual void slot20();        // 0x20 slot4 (0x92adac, `ret` stub)
  virtual void slot28();        // 0x28 slot5 (0x93b9d8, reads capacity at +0x10)
  void* vtable;           // 0x00 - 0x12dabd8 (GOT cell 0x1312b88 holds vptr-0x10)
  void* mCursor;          // 0x08 - write cursor, reset() sets to this+0x1c
  uint32_t mCapacity;     // 0x10 - expected 0x400 bytes (256 x 4-byte elements), unverified
  uint32_t m14;           // 0x14 - zeroed by reset()
  uint32_t m18;           // 0x18 - unverified
  uint32_t m1cBuf[0x100]; // 0x1c - inline buffer, 0x400 bytes zeroed by reset()
};
}  // namespace nn::pia::common
