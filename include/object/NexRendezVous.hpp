#pragma once

#include <cstdint>

// nn::nex::RendezVous - RTTI'd (typeinfo record 0x12e7730, base record
// 0x12e7480 "nn::nex::BackEndServices"). Base class of nn::nex::NgsFacade
// (ext 0x1b0 lb) - details: doc/object/NexRendezVous.md

namespace object {

class NexRendezVous {
 public:
  void* vtable;         // 0x00 - installed 0x12e6f58 (GOT cell 0x1314d40
                        //        holds 0x12e6f48 = vptr-8)
  char mPad08[0x8];     // 0x08..0x0f - unproven
  uint32_t mFlag10;     // 0x10 - zeroed by init FUN_7100a35698
  char mPad14[0x4];     // 0x14..0x17 - unproven
  uint8_t mByte18;      // 0x18 - zeroed by init
  char mPad19[0x7];     // 0x19..0x1f - unproven
  void* mCell20;        // 0x20 - GOT cell 0x130b618 / 0x130b740 vptr+0x10
  uint32_t mSem28;      // 0x28 - stlr sync word written 1
  uint8_t mByte2c;      // 0x2c - zeroed by init
  char mPad2d[0x3];     // 0x2d..0x2f - unproven
  void* mPtr30;         // 0x30 - zeroed by init
  char mPad38[0x8];     // 0x38..0x3f - unproven
  void* mList40[2];     // 0x40 - intrusive list self-linked {+0x40,+0x48}
  char mPad50[0x20];    // 0x50..0x6f - zeroed by init
  void* mPtr70;         // 0x70 - zeroed by init
  void* mPtr78;         // 0x78 - zeroed by init
  char mPad80[0x20];    // 0x80..0x9f - zeroed by init
  void* mPtr90;         // 0x90 - zeroed by init
  char mPad98[0x8];     // 0x98..0x9f - unproven
  void* mPtrA0[2];      // 0xa0 - zeroed by init
  void* mPtrB0;         // 0xb0 - zeroed by init
  uint32_t mTimeoutB8;  // 0xb8 - 30000 by init
  char mPadBC[0x4];     // 0xbc..0xbf - unproven
  void* mPtrC0;         // 0xc0 - zeroed by init
  uint16_t mHwC8;       // 0xc8 - result of helper 0x9e4b6c
  char mPadCA[0x6];     // 0xca..0xcf - unproven
  void* mSubD0;         // 0xd0 - heap object (0xe bytes, zeroed) via 0x573f04
  void* mSubD8;         // 0xd8 - heap object (0x64 bytes) via 0x573f04
  char mPadE0[0x68];    // 0xe0..0x147 - zeroed by init (byte 0xe0 = 0)
  char mPad148[0x68];   // 0x148..0x1af - zeroed via stp xzr pairs
};

}  // namespace object
