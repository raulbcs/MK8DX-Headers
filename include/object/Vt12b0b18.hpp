#pragma once

#include <cstdint>

namespace object {
// Vt12b0b18 — PLACEHOLDER name (no RTTI; game-side thread-attached object,
// base of Vt12b0bb8). Plain vptr row at 0x12b0b18 (offset-to-top/typeinfo 0),
// GOT cell 0x130d468 holds vt-0x10, 18 slots. Named "sead::MainThread" at
// +0x28 by ctor 0x628cb0.
// extent 0xf8 - details: doc/object/Vt12b0b18.md
class Vt12b0b18 {
 public:
  void* vtable;           // 0x00 - 0x12b0b18 (cell 0x130d468 + 0x10)
  char pad08[0x18];       // 0x08..0x1f - unproven (base ctor 0x628cb0 region)
  void* m20;              // 0x20 - inner vptr/manager cell 0x12fae28 + 0x10
  void* m28;              // 0x28 - name ("sead::MainThread" 0xef7b5b in
                          //   ctor 0x628cb0; [x21+8] in run fn 0x628a54)
  char pad30[0x58];       // 0x30..0x87 - subobject inited by 0x628868 (base
                          //   ctor); +0x88 zeroed at 0x628d18; unproven
  char pad88[0x38];       // 0x88..0xbf - unproven gap
  void* mC0;              // 0xc0 - owner/context compared in 0x629434 and
                          //   0x629480
  char padC8[0x4];        // 0xc8..0xcb - unproven gap
  uint32_t mCC;           // 0xcc - lifecycle state (3 = active, written by
                          //   finalizers 0x629200/0x62921c/0x629270; 2
                          //   written by waiter 0x629480)
  char padD0[0x28];       // 0xd0..0xf7 - unproven gap
};
}  // namespace object
