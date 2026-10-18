#pragma once

#include <cstdint>

namespace object {
/// Placeholder name. No RTTI (typeinfo slot 0); row 0x12d59a8 is the installed
/// vptr (GOT cell 0x1311d58 holds vptr-0x10). Ctor 0x8d97dc, no standalone
/// construction site found; slots mostly unrecovered.
/// extent 0x5c0 (memset bounds) - details: doc/object/Vt12d59a8.md
struct Vt12d59a8 {
  virtual void slot00();   // 0x00 (0x8da1ec)
  virtual void slot08();   // 0x08 (0x8da2b8)
  virtual void slot10();   // 0x10 (0x8da314)
  virtual void slot18();   // 0x18 (0x8da328)
  virtual void slot20();   // 0x20 (0x8d9aac)
  virtual void slot28();   // 0x28 (0x8d9acc)
  virtual void slot30();   // 0x30 (0x8da32c)
  virtual void slot38();   // 0x38 (0x8da334)
  virtual void slot40();   // 0x40 (0x8da33c)
  uint8_t mBase48[0x5b8];  // 0x08 - descriptor pair at +0x18/+0x20, scalar at +0x28,
                           // -1 at +0x30, member at +0x40 (memset 0x580)
};
}  // namespace object
