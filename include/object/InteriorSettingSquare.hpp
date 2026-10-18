#pragma once

#include <cstdint>

namespace object {
// InteriorSettingSquare - "インテリア（スクエア）" preset node (PROVISIONAL name
// from the Japanese UI string at 0xf07b33 held by factory 0x760d14). Family
// base vtable 0x12c1b10 (unmapped), size 0x40 EXACT (new 0x40 at 0x760d1c).
// extent 0x40 - details: doc/object/InteriorSettingSquare.md
class InteriorSettingSquare {
 public:
  void* mVtable;  // 0x00 - 0x12c19d0 (GOT cell 0x130f1a0 holds vt-0x10;
                  //        factory 0x760d14 installs it last)
  void* mBase8;   // 0x08 - secondary vptr, vtable 0x11ad210 (GOT cell
                  //        0x12fae28 holds vt-0x10; thunk slot 0x75174c)
  void* mName;    // 0x10 - 0xf07b33 "インテリア（スクエア）"
  float m18;      // 0x18 - ctor 1.0f (0x760d70)
  float m1C;      // 0x1c - ctor 0 (same str x9 pair)
  float m20;      // 0x20 - ctor 1.0f (0x760d74)
  float m24;      // 0x24 - ctor raw 0x20000000 (0x760d80 stur)
  float m28;      // 0x28 - ctor raw 0x60000000
  float m2C;      // 0x2c - ctor 0 (0x760d94 stur x10 low)
  float m30;      // 0x30 - ctor raw 0x40000000 (2.0f)
  float m34;      // 0x34 - ctor raw 0xc0000000 (-2.0f, 0x760da4 stur)
  float m38;      // 0x38 - ctor raw 0xc0000000
  float m3C;      // 0x3c - ctor raw 0xe0000000 (0x760d88)
};
}  // namespace object
