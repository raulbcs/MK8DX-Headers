#pragma once

#include <cstdint>

// Vt12b11d0 - PLACEHOLDER name; 0xf8 float-param object, sibling of
// Vt12b1050/Vt12b10d0 in the 0x62c.. projection-param family (base vptr
// 0x12b0fd0, 16-float block at +0x98, atan2f-based consumers).
// extent 0xf8 - details: doc/object/Vt12b11d0.md

namespace object {
class Vt12b11d0 {
 public:
  void* vtable;            // 0x00 - 0x12b11d0 (GOT cell 0x130d540 holds
                           // 0x12b11c0 = vt-0x10; no typeinfo row)
  uint16_t mFlags08;       // 0x08 - 0x0101 (both C1 overloads store 1 in
                           // each byte / halfword 0x101)
  char mPad0a[0x82];       // 0x0a..0x8b - unproven
  uint32_t mField8c;       // 0x8c - copied from global cell 0x130d510
  uint32_t mField90;       // 0x90 - copied from global cell 0x130d518
  uint32_t mField94;       // 0x94 - copied from global cell 0x130d520
  float mControl[16];      // 0x98..0xd4 - 4x vec4 control points; struct C1
                           // memcpy(0x40) from arg, float C1 derives them
  float mFieldD8;          // 0xd8 - zeroed by C1; slot4 getter
  float mFieldDc;          // 0xdc - zeroed by C1; slot5 getter
  float mFieldE0;          // 0xe0 - zeroed by C1; slot6 getter
  float mFieldE4;          // 0xe4 - zeroed by C1; slot7 getter
  uint32_t mFieldE8;       // 0xe8 - zeroed by C1; slot8 copies pair out
  uint32_t mFieldEc;       // 0xec - zeroed by C1; slot8 copies pair out
  uint8_t mFlagF0;         // 0xf0 - set to 1 by both C1 overloads; gate for
                           // the slot9 curve evaluation
  char mPadF1[0x7];        // 0xf1..0xf7 - tail padding
};
}  // namespace object
