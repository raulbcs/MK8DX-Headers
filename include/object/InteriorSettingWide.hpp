#pragma once

#include <cstdint>

namespace object {
// InteriorSettingWide - "インテリア（ワイド）" preset node (PROVISIONAL name
// from the Japanese UI string at 0xf07b55 held by factory 0x760dac). Family
// base vtable 0x12c1b10 (unmapped), size 0x40 EXACT (new 0x40 at 0x760db4).
// extent 0x40 - details: doc/object/InteriorSettingWide.md
class InteriorSettingWide {
 public:
  void* mVtable;  // 0x00 - 0x12c1a10 (GOT cell 0x130f1a8 holds vt-0x10;
                  //        factory 0x760dac installs it last)
  void* mBase8;   // 0x08 - secondary vptr, vtable 0x11ad210 (GOT cell
                  //        0x12fae28 holds vt-0x10; thunk slot 0x75174c)
  void* mName;    // 0x10 - 0xf07b55 "インテリア（ワイド）"
  float m18;      // 0x18 - ctor 1.0f (0x760e20)
  float m1C;      // 0x1c - ctor 0 (same str x8 pair)
  float m20;      // 0x20 - ctor 1.0f (0x760e24 stp)
  float m24;      // 0x24 - ctor raw 0xc0aac000 (0x760e0c/0x760e10 movk)
  float m28;      // 0x28 - ctor raw 0x4e38e380 (w21, dispatcher setup)
  float m2C;      // 0x2c - ctor 0 (0x760e04 stp w21, wzr)
  float m30;      // 0x30 - ctor raw 0x38c038e0 (0x760e40 stp)
  float m34;      // 0x34 - ctor raw 0x871c71c0
  float m38;      // 0x38 - ctor raw 0xaaaaaa80 (0x760e34 stp)
  float m3C;      // 0x3c - ctor raw 0xd5555540
};
}  // namespace object
