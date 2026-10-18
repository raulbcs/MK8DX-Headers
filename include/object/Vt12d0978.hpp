#pragma once

#include <cstdint>

namespace object {
// Vt12d0978 - PLACEHOLDER name; vtable shared by a family of byte-identical
// stub directors (slot 0/1 are code clones of RaceDirector's custom-RTTI
// pair). Static global instance at 0x133f3f8 (guard 0x1307618, instance cell
// 0x1307620); secondary vptrs from runtime cell 0x12fb0d48 at +0x50/+0x70/+0x90.
// extent 0x98 - details: doc/object/Vt12d0978.md
class Vt12d0978 {
 public:
  void* vtable;      // 0x00 - 0x12d0978 (GOT cell 0x1307600 holds 0x12d0968 =
                     //   vt-0x10); no RTTI
  char pad08[0x30];  // 0x08..0x37 - unproven; ctor variant 0x710087c5a4
                     //   zeroes +0x38 after base ctor 0x71007b976c
  char pad38[0x0c];  // 0x38..0x43 - ctor-variant zero (+0x38) and halfwords
                     //   +0x40; unproven
  uint32_t m44;      // 0x44 - ctor variant 0x710087c5a4 stores 0
  char pad48[0x04];  // 0x48..0x4b - unproven gap
  uint32_t m4c;      // 0x4c - ctor variant stores -1
  char pad50[0x20];  // 0x50..0x6f - subobject #1: secondary vptr (cell
                     //   0x12fb0d48 + 0x10) installed at +0x50 by every dtor
                     //   clone; layout unproven
  char pad70[0x20];  // 0x70..0x8f - subobject #2, same secondary vptr at +0x70
  char pad90[0x08];  // 0x90..0x97 - subobject #3 header, same secondary vptr
                     //   at +0x90; only 8 bytes covered here (extent is a
                     //   lower bound: max proven store 0x97)
};
}  // namespace object
