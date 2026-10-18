#pragma once

#include <cstdint>

namespace nn::pia::common {
/// RTTI "N2nn3pia6common11FixedStringILj10EEE" (FixedString<10>, 4-byte
/// elements, derives from nn::pia::common::String). Installed vptr 0x12dc918.
/// extent 0x48 (computed 0x1c + 0x28 buffer + align pad; new-size unverified) - details: doc/_nn/pia/common/FixedString10.md
struct FixedString10 {
  virtual void slot0();         // 0x00 slot0 (0x9118d8, shared `ret` stub)
  virtual void dtorDeleting();  // 0x08 slot1 (0x973824, tail `b operator delete`)
  virtual void slot10();        // 0x10 slot2 (0x92a7e8, shared assign, same impl as all N)
  virtual void reset();         // 0x18 slot3 (0x973828, reset-to-empty from this+0x1c)
  virtual void slot20();        // 0x20 slot4 (0x92adac, `ret` stub)
  virtual void slot28();        // 0x28 slot5 (0x97388c, capacity [ +0x10 ] compare helper)
  void* vtable;          // 0x00 - 0x12dc918 (GOT cell 0x13133e0 holds vptr-0x10)
  void* mCursor;         // 0x08 - data pointer, reset() re-points to this+0x1c
  uint32_t mCapacity;    // 0x10 - 0x28 (4*N, N=10) set at every init site
  uint32_t m14;          // 0x14 - zeroed at init (stp wzr,wzr +0x14/+0x18)
  uint32_t m18;          // 0x18 - zeroed at init
  uint32_t m1cBuf[0xa];  // 0x1c - inline buffer, 0x28 bytes
  uint32_t m44;          // 0x44 - unverified alignment pad (0x48 size)
};
}  // namespace nn::pia::common
