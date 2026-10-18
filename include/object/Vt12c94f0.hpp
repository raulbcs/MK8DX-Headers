#pragma once

#include <cstdint>

// object::Vt12c94f0 — placeholder game class; ctor 0x7f49ec installs three
// vptrs (+0x00 / +0x218 / +0x248) and an os::Tick; the only factory is inside
// FrameworkGameScene::preCalc, allocating 0x2e0.
// extent 0x2e0 - details: doc/object/Vt12c94f0.md

namespace object {
class Vt12c94f0 {
 public:
  void* mVtable;           // 0x00 — 0x12c94f0 (GOT cell 0x13102d8 holds 0x12c94e0)
  uint8_t mPad8[0x210];    // 0x08 — unproven padding
  void* mVtable218;        // 0x218 — 0x12c9618 (cell 0x13102e0), MI secondary
  uint32_t mZero220;       // 0x220 — zeroed by ctor
  uint8_t mPad224[0x4];    // 0x224 — unproven padding
  void* mZero228;          // 0x228 — zeroed by ctor
  uint64_t mTick230;       // 0x230 — nn::os::GetSystemTick() at 0x7f4a2c
  void* mZero238;          // 0x238 — then sub-object ctor 0x8e06ec(this+0x230)
  void* mZero240;          // 0x240
  void* mVtable248;        // 0x248 — 0x12c9650 (cell 0x13102e8)
  uint64_t mMinus250;      // 0x250 — zeroed
  uint64_t mMinus258;      // 0x258 — -1 (0x7f4a54)
  uint64_t mMinus260;      // 0x260 — zeroed
  uint64_t mMinus268;      // 0x268 — -1
  int32_t mMinus270;       // 0x270 — -1
  uint8_t mPad274[0x4];    // 0x274 — unproven padding
  uint64_t mZero278;       // 0x278 — zeroed
  uint8_t mMember280[0x30];// 0x280 — two members inited via 0x60b918(this+0x280, 4, ...)
  uint8_t mMember2b0[0x30];// 0x2b0 — second member, same init (tail call 0x7f4aa8)
};
}  // namespace object
