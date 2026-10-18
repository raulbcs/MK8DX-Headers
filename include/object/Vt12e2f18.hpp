#pragma once

#include <cstdint>

// Vt12e2f18 - PLACEHOLDER name; nn::nex/SocketDriver-region manager (ctor
// compares typeinfo names against SharedCounterInterface<qVector<SharedPtr
// <SocketDriver::Socket>>>). 15-slot primary table. extent 0x350 -
// details: doc/object/Vt12e2f18.md

namespace object {
class Vt12e2f18 {
 public:
  void* vtable;              // 0x00 - 0x12e2f20 (GOT cell 0x1314380 holds
                             // 0x12e2f10 = vt-0x8; installed = cell+0x10)
  uint8_t mPad08[0x98];      // 0x08 - unproven padding (args stored by ctor
                             // prologue 0x588b04 call)
  uint8_t mFieldA0[0x20];    // 0xa0 - initialized by FUN_71005902f8 (ctor
                             // 0x9e6724-0x9e6738, name arg from rodata
                             // 0xf140776)
  void* mFieldC0;            // 0xc0 - ctor stores 0
  uint8_t mPadC8[0x18];      // 0xc8 - FUN_71005788bc member ctor
  uint8_t mZeroedE0[0x38];   // 0xe0 - ctor stores x26/0 at +0xe0 (0x9e750),
                             // w28 at +0xf0, member ctor FUN_71005788bc
                             // at +0xf8, callback cell value at +0x108,
                             // zero +0x100-0x107, stored arg at +0x110
  void* mMemberVtable118;    // 0x118 - 0x128cc20 (GOT cell 0x130b740 holds
                             // 0x128cc10 = vt-0x8; first set to 0x128c798
                             // via cell 0x130b618, then overwritten)
  uint32_t mField120;        // 0x120 - stlr 1 (0x9e6790)
  uint8_t mField124;         // 0x124 - ctor zeroes byte
  uint8_t mPad125[0x13];     // 0x125 - unproven padding
  void* mListHead138[2];     // 0x138 - intrusive list head (both words =
                             // &this+0x138, ctor 0x9e67a8)
  void* mField148[4];        // 0x148 - ctor zeroes 0x148-0x167
  uint64_t mField168;        // 0x168 - ctor stores 0
  uint8_t mMember170[0x38];  // 0x170 - FUN_71005788e0 member ctor (w1=1);
                             // +0x1a8 gets member vptr 0x128cc20 again
  void* mField1a8;           // 0x1a8 - member vptr 0x128cc20 (0x9e67f4)
  uint8_t mPad1b0[0x54];     // 0x1b0 - ctor zeroes +0x1b4 byte, +0x188/0x190
                             // words, 0x198-0x1a7; FUN_71005788e0 members
                             // at +0x1c8 and +0x200; unproven padding
  uint8_t mPad204[0x3c];     // 0x204 - unproven padding to +0x240
  void* mField240[3];        // 0x240 - ctor stores x24/x23/x22 (0x9e6818-
                             // 0x9e6840)
  uint8_t mPad258[0xc0];     // 0x258 - ctor zeroes +0x278 byte (0x9e7980);
                             // unproven padding
  void* mField318;           // 0x318 - object pointer, target of dynamic
                             // typeinfo-name checks (0x9e7970-0x9e79c4)
  uint8_t mPad320[0x30];     // 0x320 - unproven padding to extent
};
}  // namespace object
