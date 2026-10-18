#pragma once

#include <cstdint>

// SharedCounter<ConnectionOrientedSocketManager, ConnectionOrientedSocketManager,
// SharedPtrDefaultDeleter<ConnectionOrientedSocketManager>> (RTTI-confirmed;
// ti 0x12e4500, name "N2nn3nex13SharedCounterI..."). vptr 0x12e3750 = row+8
// (row 0x12e3748 is the typeinfo slot; GOT cell 0x13146e8 = row-0x10... value
// 0x12e3740, vptr = cell+0x10).
// extent 0x4c8 - details: doc/_nn/nex/SharedCounterConnectionOrientedSocketManager.md

namespace nn::nex {
class SharedCounterConnectionOrientedSocketManager {
 public:
  void* vtable;      // 0x00 — 0x12e3750 (final override at 0x7100a033a0)
  void* m8;          // 0x08 — ctor arg x1 stored (0x7100a033a0)
  void* mVptr10;     // 0x10 — secondary vptr 0x12e33e0 (base C1 0x7100a032f8)
  void* m18;         // 0x18 — alloc(8) result (0x7100a03344/0x7100a03360)
  char mPad20[0x60]; // 0x20 — unproven member region
  char m80[0x48];    // 0x80 — zeroed by ctor (0x7100a03368-0x7100a03398)
  void* mListC8;     // 0xc8 — list head, self-looped after init (0x7100a033ac)
  void* mListD0;     // 0xd0 — list tail (0x7100a033cc)
  void* mD8;         // 0xd8 — list tail mirror (0x7100a033b0)
  void* mListE0;     // 0xe0 — second list head (0x7100a033d8)
  void* mListE8;     // 0xe8 — second list tail (0x7100a033ec/0x7100a033f0)
  void* mF0;         // 0xf0 — zeroed (0x7100a033c4)
  char mPadF8[0x3d0]; // 0xf8 — unproven tail (factory alloc 0x4c8)
};
}  // namespace nn::nex
