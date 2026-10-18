#pragma once

#include <cstdint>

// Vt12b69c8 - PLACEHOLDER name; 0x318 resource-entry object: derives the
// Vt12be2d0-family base (ctor calls 0x732a90) and adds an 88-entry
// pointer table at +0x38 filled by slot2 from a context record.
// extent 0x318 - details: doc/object/Vt12b69c8.md

namespace object {
class Vt12b69c8 {
 public:
  void* vtable;            // 0x00 - 0x12b69c8 (GOT cell 0x130e070 holds
                           // 0x12b69b8 = vt-0x10; base C1 first installs
                           // the Vt12be350 base row, then this overwrite)
  void* mSource08;         // 0x08 - context/source record; set via slot2
                           // (0x732ab4) param x1, read by most slots
  uint16_t mField10;       // 0x10 - u16; slot2 writes [mSource08+0x1618]
  char mPad12[0x2];        // 0x12..0x13 - unproven
  uint16_t mIndex14;       // 0x14 - entry index (stride 0x68 into
                           // [mSource08+0x108]); loop count for the dtor
  uint16_t mField16;       // 0x16 - copy of [entry+0x5e] (slot2); also
                           // passed as arg by slot13
  char mPad18[0x8];        // 0x18..0x1f - unproven
  void* mField20;          // 0x20 - [entry+0x50] (slot2); entry table head
  void* mField28;          // 0x28 - [[mSource08+0x110] + (u16<<7)] + 0x88
  uint16_t mField30;       // 0x30 - u16, zeroed by C1
  uint8_t mFlags32;        // 0x32 - bit1 = "entry+0xd != 0" (slot2);
                           // bit0 tested by D1
  uint8_t mFlag33;         // 0x33 - set to 1 by C1
  char mPad34[0x4];        // 0x34..0x37 - tail padding
  void* mEntries38[88];    // 0x38..0x2f7 - slot2 fills all 88 with the
                           // shared default 0x1357f58; dtor frees non-null
                           // entries in 0x18-stride via virtual slot 0x1f8
  void* mField2f8;         // 0x2f8 - zeroed by C1
  uint32_t mField300;      // 0x300 - zeroed by C1
  char mPad304[0x4];       // 0x304..0x307 - unproven
  void* mField308;         // 0x308 - zeroed by C1; entry array head freed
                           // by D1 (0x18-stride elements)
  uint16_t mField310;      // 0x310 - u16, zeroed by C1
  char mPad312[0x2];       // 0x312..0x313 - unproven
  int32_t mField314;       // 0x314 - -1 sentinel, written by C1
};
}  // namespace object
