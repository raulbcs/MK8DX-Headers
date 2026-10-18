#pragma once

#include <cstdint>

// Vt12b1050 - PLACEHOLDER name; projection/FOV-style float param object,
// embedded member (stride 0xc0 proven at FUN_71003c94xx pool init).
// extent 0xc0 - details: doc/object/Vt12b1050.md

namespace object {
class Vt12b1050 {
 public:
  void* vtable;           // 0x00 - 0x12b1050 (GOT cell 0x130d528 holds
                          // 0x12b1040 = vt-0x10; no typeinfo row)
  uint8_t mFlag08;        // 0x08 - set to 1 by both C1 overloads
  uint8_t mFlag09;        // 0x09 - set to 1 by the default C1 only
  char mPad0a[0x82];      // 0x0a..0x8b - unproven
  uint32_t mField8c;      // 0x8c - copied from global cell 0x130d510
  uint32_t mField90;      // 0x90 - copied from global cell 0x130d518
  uint32_t mField94;      // 0x94 - copied from global cell 0x130d520
  float mF98;             // 0x98 - 0.5 (default C1) / float arg
  float mF9c;             // 0x9c - 0.5 (default C1) / float arg
  float mFa0;             // 0xa0
  float mFa4;             // 0xa4 - sinf-derived in float C1
  float mFa8;             // 0xa8 - cosf-derived in float C1
  float mFac;             // 0xac - tanf-derived in float C1
  float mFb0;             // 0xb0 - 0.665 (default C1)
  uint64_t mFieldB4;      // 0xb4 - pointer copied from [[0x12fb0b00]]
  char mPadBc[0x4];       // 0xbc..0xbf - tail padding
};
}  // namespace object
