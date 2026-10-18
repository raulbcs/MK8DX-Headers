#pragma once

#include <cstdint>

namespace object {
// Vt12b1880 - PLACEHOLDER name; base node of the float-defaults family
// (Vt12c7f38/Vt12c7f38-style 0x178 flavour). Two intrusive lists, singleton
// guard cells. No RTTI. extent 0x178 - details: doc/object/Vt12b1880.md
class Vt12b1880 {
 public:
  void* mVtable;          // 0x00 - 0x12b1880 (GOT cell 0x130d748 holds vt-0x10;
                          //        pre-vptr 0x12b18d8 from cell 0x130d750 is
                          //        installed first by filler 0x635ea8)
  uint8_t m8[0x8];        // 0x08 - 0 (0x635eac stp xzr,xzr,[x0,#0x10])
  uint8_t m10[0x8];       // 0x10 - 0 (0x635eac)
  uint64_t m18;           // 0x18 - 0x7fffffff80000000 float-default pair
  float m20;              // 0x20 - FLT_MAX 0x7f7fffff (0x635eb4)
  float m24;              // 0x24 - FLT_MAX (0x635eb4)
  uint8_t m28[0xD8];      // 0x28 - float-default block, 0xff7fffff pairs at
                          //        +0x28, 0.5f at +0xf0/+0xf4, 0.25f at
                          //        +0xf8 (0x635ee0-0x635ef0)
  uint32_t m100;          // 0x100 - param 0x1c, raised to 0x20 if > 0x20
  uint32_t m104;          // 0x104 - param 0x14
  uint32_t m108;          // 0x108 - param 0x18
  uint32_t m10C;          // 0x10c - param 0xf
  uint8_t m110[0x28];     // 0x110 - 0 block (0x635ef8-0x635f00)
  uint8_t m138;           // 0x138 - 0 (C1 0x635b80)
  uint8_t m139[0x7];      // 0x139 - byte pairs 0x1e/0x01 written by filler
                          //        loop 0x635f10-0x635f44
  void* m140;             // 0x140 - owner manager (C1 0x635b90)
  void* m148;             // 0x148 - intrusive list head, this+0x148
  void* m150;             // 0x150 - list tail, this+0x148
  uint32_t m158;          // 0x158 - 0 count
  uint32_t m15C;          // 0x15c - 8 element stride
  void* m160;             // 0x160 - intrusive list head, this+0x160
  void* m168;             // 0x168 - list tail, this+0x160
  uint32_t m170;          // 0x170 - 0 count
  uint32_t m174;          // 0x174 - 0x168 element stride
};
}  // namespace object
