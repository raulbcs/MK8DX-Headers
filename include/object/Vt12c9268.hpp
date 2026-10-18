#pragma once

#include <cstdint>

// Vt12c9268 - PLACEHOLDER name; named-subsystem base class (base C1 takes a
// name string; CameraEngine/MiiEngine/SystemSubEngine derive from it); 38 slots.
// extent 0x200 - details: doc/object/Vt12c9268.md

namespace object {
class Vt12c9268 {
 public:
  void* vtable;              // 0x00 - 0x12c9268 (base C1 0x71007f4020, GOT cell
                             // 0x12fc358 holds 0x12c9258 = vt-0x10)
  char mPad08[0x160];        // 0x08 - unproven (SystemSubEngine factory reads a
                             // ptr at +0x58, 0x71003d72a8)
  uint16_t mField168;        // 0x168 - ctor sets 1 (0x71007f402c)
  char mPad16a[0xe];         // 0x16a - unproven
  char mSub178[0x30];        // 0x178 - sub-object ctor FUN_71007b976c (installs
                             // vptr 0x12c93a8); destroyed by FUN_71007b978c
  void* mSelf1a8;            // 0x1a8 - ctor stores this (0x71007f40dc)
  void* mListHead1b0;        // 0x1b0 - empty-list head, points at itself
                             // (0x71007f4034..0x71007f403c)
  void* mListTail1b8;        // 0x1b8 - points at the head (0x71007f403c)
  uint32_t mCount1c0;        // 0x1c0 - ctor zeroes; node-append slot bumps it
                             // (0x7100821054)
  char mPad1c4[0x4];         // 0x1c4 - unproven
  uint32_t mField1c8;        // 0x1c8 - ctor zeroes (0x71007f4048)
  char mPad1cc[0x4];         // 0x1cc - unproven
  uint32_t mEngineId1d0;     // 0x1d0 - id from parent vcall (0x71007f40d4)
  char mPad1d4[0x4];         // 0x1d4 - unproven
  void* mVptrD8;             // 0x1d8 - secondary vptr, GOT cell 0x1310298 + 0x10
                             // (0x71007f4058..0x71007f4068)
  char mPad1e0[0x18];        // 0x1e0 - ctor-zeroed block (0x71007f4060..0x71007f4068)
  void* mLastNode1f8;        // 0x1f8 - last appended node; derived ctors zero it
                             // (0x71007c34e8 / 0x7100820fc4)
};
}  // namespace object
