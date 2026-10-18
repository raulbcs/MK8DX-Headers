#pragma once

#include <cstdint>

// Vt12b23a0 — PLACEHOLDER name; vptr 0x12b23a0, 11 slots, triple vptr
// (primary + secondary + tertiary at +0x38/+0x90). Kart-param band
// (C1/D1 at 0x6489bc/0x648a80). Extent only a proven lower bound: the
// class is always embedded in larger aggregates (parents at 0x6bb394/
// 0x710bcc call its base C1 in place).
// extent 0x488 (lower bound) - details: doc/game/Vt12b23a0.md
namespace game {
class Vt12b23a0 {
 public:
  void* mVtable;        // 0x00 - primary vptr 0x12b23a0 (GOT cell 0x130d958
                        //   holds vptr-0x10; C1 adds 0x10)
  char mPad08[0x30];    // 0x08..0x37 - base object (base vptr 0x12b2360,
                        //   base C1 0x64822c; new'd buffers at +0x20/+0x30)
  void* mVtable2;       // 0x38 - secondary vptr 0x12b2408 (vptr+0x78);
                        //   secondary base subobject starts here, its C1
                        //   0x662070 runs before the vptr install
  char mPad40[0x50];    // 0x40..0x8f - string-array member inited by C1
                        //   helper 0x668d40 (0x648a04), dtor iterates it
                        //   (0x648ac4-0x648ae0)
  void* mVtable3;       // 0x90 - tertiary vptr 0x12b2450 (vptr+0xc0);
                        //   tertiary base subobject, ctor 0x668d40
  char mPad98[0x1c8];   // 0x98..0x25f - unproven (base + member state)
  uint32_t m260;        // 0x260 - zeroed by C1 (0x648a08)
  char mPad264[0x4];    // 0x264 - gap
  uint64_t m268;        // 0x268 - zeroed by C1; freed by 0x60b984 in D1
                        //   (0x648ae4-0x648ae8)
  char mPad270[0x8];    // 0x270 - zeroed by C1 (0x648a34)
  uint32_t m278;        // 0x278 - zeroed by C1 (0x648a18)
  char mPad27c[0x4];    // 0x27c - gap
  void* m280;           // 0x280 - zeroed by C1 (0x648a14)
  float m288;           // 0x288 - 1.0f, written by C1 (0x648a44)
  char mPad28c[0x4];    // 0x28c - gap
  char mPad290[0x1c8];  // 0x290..0x457 - subobject (ctor 0x628628 at
                        //   0x648a48)
  char mPad458[0x8];    // 0x458 - u32 = 2 written by C1 (0x648a60)
  char mPad460[0x28];   // 0x460..0x487 - zeroed by C1 (0x648a58-0x648a6c);
                        //   +0x468 array walked by D1 (0x648aec)
};
}  // namespace game
