#pragma once

#include <cstdint>

namespace object {
// Vt12b0778 - PLACEHOLDER name; handle-backed stream buffer secondary base
// (owner+0x20; owner spans 0x80 bytes). Slots wrap open/size/read-style helpers
// (0x60df54/0x60dfc8/0x60ded4). No RTTI (null typeinfo slot).
// extent 0x60 - details: doc/object/Vt12b0778.md
class Vt12b0778 {
 public:
  void* vtable;     // 0x00 - 0x12b0778 (GOT cell 0x130d3d0 holds vt-0x10)
  void* m08;        // 0x08 - owned handle/buffer ptr (freed by D0 when
                    //   +0x58 flag set, via 0x60db1c)
  uint32_t m10;     // 0x10 - result of FUN_710060df54(m08)
  char pad14[0x4];  // 0x14..0x17 - unproven gap
  void* mVtable18;  // 0x18 - 0x128a4a0 (GOT cell 0x130b090; framework
                    //   secondary base)
  void* m20;        // 0x20 - ctor 0
  void* m28;        // 0x28 - ctor 0 (member dtor 0x60d35c in D2)
  void* m30;        // 0x30 - ctor 0
  void* m38;        // 0x38 - ctor 0
  void* m40;        // 0x40 - ctor 0
  void* m48;        // 0x48 - ctor 0
  uint32_t m50;     // 0x50 - ctor 0
  char pad54[0x4];  // 0x54..0x57 - unproven gap
  uint8_t m58;      // 0x58 - ownership flag (gates free of +0x08)
  char pad59[0x3];  // 0x59..0x5b - unproven gap
  uint32_t m5c;     // 0x5c - result of FUN_710060dfc8(m08) or 0
};
}  // namespace object
