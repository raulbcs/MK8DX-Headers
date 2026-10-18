#pragma once

#include <cstdint>

namespace object {
// InteriorSetting51Ch - "インテリア（5.1ch）" preset node (PROVISIONAL name
// from the Japanese UI string at 0xf07b74 held by factory 0x760c3c). Family
// base vtable 0x12c1b10 (unmapped), size 0x40 EXACT (new 0x40 at 0x760c44).
// extent 0x40 - details: doc/object/InteriorSetting51Ch.md
class InteriorSetting51Ch {
 public:
  void* mVtable;  // 0x00 - 0x12c1a50 (GOT cell 0x130f190 holds vt-0x10;
                  //        factory 0x760c3c installs it last)
  void* mBase8;   // 0x08 - secondary vptr, vtable 0x11ad210 (GOT cell
                  //        0x12fae28 holds vt-0x10; thunk slot 0x75174c)
  void* mName;    // 0x10 - 0xf07b74 "インテリア（5.1ch）"
  float m18;      // 0x18 - ctor 1.0f (0x760cfc)
  float m1C;      // 0x1c - ctor 0 (same str x9 pair)
  float m20;      // 0x20 - ctor 1.0f (0x760d00 stp)
  float m24;      // 0x24 - ctor raw 0x15555560 (w25)
  float m28;      // 0x28 - ctor raw 0x4e38e380 (w21, 0x760cf8 stp)
  float m2C;      // 0x2c - ctor 0
  float m30;      // 0x30 - ctor raw 0x38e38e20 (w24, 0x760d0c stp)
  float m34;      // 0x34 - ctor raw 0x9c71c720 (w23)
  float m38;      // 0x38 - ctor raw 0xd5555540 (w20, 0x760d08 stp)
  float m3C;      // 0x3c - ctor raw 0xeaaaaaa0 (w22)
};
}  // namespace object
