#pragma once

#include <cstdint>

// Vt12c2de8 - PLACEHOLDER name; primary-base vtable of an MI complete
// class built by C-variant FUN_710078bcb8 (final vptrs 0x12c2cc0 at +0,
// secondary 0x12c2d48 at +8). extent is a lower bound.
// extent 0x3c0 (lower bound, deepest C-store +0x3b8) - details:
// doc/object/Vt12c2de8.md

namespace object {
class Vt12c2de8 {
 public:
  void* vtable;            // 0x00 - 0x12c2de8 (GOT cell 0x130f618 holds
                           // 0x12c2dd8 = vt-0x10); overwritten by the
                           // final primary vptr 0x12c2cc0 later in the C1
  uint8_t mSub08[0x2c0];   // 0x08 - sub-object constructed by 0x5ef030,
                           // later holds the MI secondary vptr 0x12c2d48;
                           // interior unproven
  uint64_t mField2c8;      // 0x2c8 - zeroed by C1 (later target of the
                           // +0x2f8 store in the derived init path)
  char mPad2d0[0x4];       // 0x2d0..0x2d3 - u32 zeroed by C1
  char mPad2d4[0x4];       // 0x2d4..0x2d7 - unproven
  void* mField2d8;         // 0x2d8 - zeroed by C1
  void* mField2e0;         // 0x2e0 - zeroed by C1
  void* mField2e8;         // 0x2e8 - zeroed by C1
  uint32_t mField2f0;      // 0x2f0 - u32 zeroed by C1
  char mPad2f4[0x4];       // 0x2f4..0x2f7 - unproven
  void* mField2f8;         // 0x2f8 - C1 allocates a 0x268-byte object
                           // (0x60afec + C1 0x773a64) and stores it here
  void* mField300;         // 0x300 - zeroed by C1
  uint16_t mField308;      // 0x308 - u16 zeroed by C1
  char mPad30a[0x6];       // 0x30a..0x30f - unproven
  uint8_t mSub310[0x40];   // 0x310 - member constructed by 0x628628
  uint8_t mField350;       // 0x350 - u8 zeroed by C1
  char mPad351[0x7];       // 0x351..0x357 - unproven
  void* mMember358;        // 0x358 - member vptr (cell 0x130fda0, later
                           // overwritten by cell 0x130f728 + 0x10)
  void* mData360;          // 0x360 - data ptr for the member; C1 writes a
                           // global byte ([0x12fada8]) into [mData360]
  uint32_t mField368;      // 0x368 - 0x20 (capacity/granularity)
  uint8_t mCursor36c[0x24];  // 0x36c..0x38f - C1 stores this+0x36c here
                           // (self/slack cursor); interior unproven
  void* mField390;         // 0x390 - zeroed by C1
  void* mField398;         // 0x398 - zeroed by C1
  void* mField3a0;         // 0x3a0 - zeroed by C1
  uint8_t mField3a8;       // 0x3a8 - u8 zeroed by C1
  char mPad3a9[0x7];       // 0x3a9..0x3af - unproven
  void* mField3b0;         // 0x3b0 - zeroed by C1
  void* mField3b8;         // 0x3b8 - zeroed by C1
};
}  // namespace object
