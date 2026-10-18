#pragma once

#include <cstdint>

// Vt12c7f38 — 9-slot manager-registered node of the Vt12b1480 float-defaults
// family (base C1 0x635b58 installs base vptr 0x12b1880; factory overrides with
// this vptr). No RTTI. extent 0x178 - details: doc/object/Vt12c7f38.md

namespace object {
class Vt12c7f38 {
 public:
  void* mVtable;          // 0x00 — 0x12c7f38 (GOT cell 0x1310028 holds vptr-0x10; factory
                          //        0x7d5d2c: add #0x10 -> [this]); base C1 first stores
                          //        cell 0x130d748+0x10 (0x12b1880), then cell 0x130d750+0x10
                          //        is stored by 0x635ea8 before the override
  uint8_t m8[0x8];        // 0x08 — 0 (0x635ecc)
  uint8_t m10[0x8];       // 0x10 — 0 (0x635eac)
  uint64_t m18;           // 0x18 — 0x7fffffff80000000 float-default pair (0x635eac)
  float m20;              // 0x20 — FLT_MAX 0x7f7fffff (0x635eb4)
  float m24;              // 0x24 — FLT_MAX (0x635eb4)
  uint8_t m28[0xD8];      // 0x28 — unproven float-default block (0x635ea8)
  uint32_t m100;          // 0x100 — 0x1c param (0x635ec0)
  uint32_t m104;          // 0x104 — 0x14 param (0x635ec4)
  uint8_t m108[0x30];     // 0x108 — unproven
  uint32_t m138;          // 0x138 — 0 by C1 (0x635b80); factory sets 0x12 (0x7d5d38)
  uint8_t mPad13C[0x4];   // 0x13c — unproven
  void* m140;             // 0x140 — owner manager (0x635b90)
  void* m148;             // 0x148 — intrusive list head, this+0x148 (0x635b9c)
  void* m150;             // 0x150 — list tail, this+0x148 (0x635b9c)
  uint32_t m158;          // 0x158 — 0 count (0x635b8c)
  uint32_t m15C;          // 0x15c — 8 element stride (0x635bac)
  void* m160;             // 0x160 — intrusive list head, this+0x160 (0x635bb8)
  void* m168;             // 0x168 — list tail, this+0x160 (0x635bb8)
  uint32_t m170;          // 0x170 — 0 count (0x635ba4)
  uint32_t m174;          // 0x174 — 0x168 element stride (0x635bbc)
};
}  // namespace object
