#pragma once

#include <cstdint>

namespace nn::pia::common {
/// RTTI "N2nn3pia6common11FixedStringILj16EEE" (nn::pia::common::FixedString<16>,
/// 4-byte elements, derives from nn::pia::common::String). Installed vptr 0x12d99a8.
/// extent 0x60 (factory new at 0x932124) - details: doc/_nn/pia/common/FixedString16.md
struct FixedString16 {
  virtual void slot0();         // 0x00 slot0 (0x9118d8, shared with FixedString<256>; role unverified)
  virtual void dtorDeleting();  // 0x08 slot1 (0x92efcc, tail `b operator delete`)
  virtual void slot10();        // 0x10 slot2 (0x92a7e8, shared, size 0x396, unrecovered)
  virtual void reset();         // 0x18 slot3 (0x92ee5c, zeroes buffer and re-points cursor)
  virtual void slot20();        // 0x20 slot4 (0x92adac, `ret` stub)
  virtual void slot28();        // 0x28 slot5 (0x92efd0, reads capacity at +0x10)
  void* vtable;          // 0x00 - 0x12d99a8 (GOT cell 0x13128d8 holds vptr-0x10)
  void* mCursor;         // 0x08 - write cursor, reset() sets to this+0x1c
  uint32_t mCapacity;    // 0x10 - 0x40 (bytes) set by the factory ctor
  uint32_t m14;          // 0x14 - zeroed by ctor and reset()
  uint32_t m18;          // 0x18 - zeroed by factory ctor (0x932138)
  uint32_t m1cBuf[0x10]; // 0x1c - inline buffer, 0x40 bytes zeroed by ctor
  uint32_t m5c;          // 0x5c - unverified padding (0x60 allocation tail)
};
}  // namespace nn::pia::common
