#pragma once

#include <cstdint>

// Vt12dc7c0 - PLACEHOLDER name; ctor FUN_71009721ac builds a 16-entry array of
// 0x60-byte polymorphic members (+0x250..+0x7f0); embedded at +0xbe0 of an
// outer object. 36 slots; assigned row is the typeinfo slot, installed vptr is
// 0x12dc7c8 (GOT cell 0x13133d8 holds 0x12dc7b8 = vt-8).
// extent 0x850 (lower bound) - details: doc/object/Vt12dc7c0.md

namespace object {
class Vt12dc7c0 {
 public:
  void* vptr;                // 0x00 - 0x12dc7c8 (ctor 0x71009721ac: cell
                             // 0x13133d8 + 0x10); +0x08 zeroed by ctor
  char mPad08[0x8];          // 0x08 - ctor zeroes (stp x8, xzr)
  uint32_t mField10;         // 0x10 - ctor zeroes (0x71009721e0)
  char mPad14[0x2];          // 0x14 - ctor zeroes (strh)
  uint8_t mField16;          // 0x16 - ctor zeroes
  char mPad17[0x19];         // 0x17 - unproven
  uint8_t mField30;          // 0x30 - ctor sets 5 (0x71009721dc)
  uint8_t mField31;          // 0x31 - ctor zeroes
  uint16_t mField32;         // 0x32 - ctor zeroes
  char mPad34[0x20];         // 0x34 - memset 0x20 (0x7100972200..0x7100972208)
  char mPad54[0x180];        // 0x54 - memset 0x180 (0x7100972208)
  uint32_t mField1d4;        // 0x1d4 - ctor zeroes
  char mPad1d8[0x78];        // 0x1d8 - string-like member (ctor 0x71009b1fe8,
                             // assign 0x71009b2130; D2 tail 0x71009b20b4)
  char mMembers250[0x600];   // 0x250 - 16 x 0x60 members at stride 0x60
                             // (+0x250/+0x2b0/../+0x7f0), member ctor
                             // FUN_71009748f8, member D FUN_71009749a0;
                             // each member has a vptr (slot-0 vcalls in ctor)
};
}  // namespace object
