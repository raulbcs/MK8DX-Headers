#pragma once

#include <cstdint>

namespace nn::pia::common {
/// Typeinfo-row vtable: assigned 0x12d9610 (ti slot -> RTTI record 0x12d9648,
/// "N2nn3pia6common6StringE"); installed vptr 0x12d9618 (GOT cell 0x1312820
/// holds vptr-0x10). Base of the pia::common::FixedString<N> family.
/// extent 0x1c (ctor field stores; lower bound) - details: doc/_nn/pia/common/String.md
struct String {
  virtual void slot00();  // 0x00 slot0 (0x9118d8, shared `ret` stub)
  virtual void dtorDeleting();  // 0x08 slot1 (0x92adb0, tail-branch operator delete - trivial dtor)
  virtual void assign(const String&);  // 0x10 slot2 (0x92a7e8, shared; reads [src+0x8])
  virtual void slot18();  // 0x18 slot3 (0x92aa5c, class-specific, unrecovered)
  virtual void slot20();  // 0x20 slot4 (0x92adac, shared `ret` stub)
  virtual void slot28();  // 0x28 slot5 (0x92a6e4, class-specific, unrecovered)

  void* mData;        // 0x08 - char*/u16* buffer pointer (C1 arg)
  uint32_t mField10;  // 0x10 - zeroed by both ctors (capacity for FixedString)
  uint32_t mLength;   // 0x14 - strlen/strlen16 of source, written by C1
  uint32_t mMode;     // 0x18 - 1 = char (0x92a664), 2 = char16 (0x92a6a4)
};
}  // namespace nn::pia::common
