#pragma once

#include <cstdint>

// PROVISIONAL (no RTTI: typeinfo slot zero). Multi-vptr aggregate with float
// tuning banks and an embedded 0x20-capacity buffer; size proven by operator
// new 0xf0 (0x764304, 0x7660f4). extent 0xf0 - details: doc/object/Vt12c2750.md

namespace object {
class Vt12c2750 {
 public:
  void* vtable;             // 0x00 — 0x12c2750 (cell 0x130f4d8 + 0x10)
  void* mField08;           // 0x08 — secondary vptr 0x130efc8+0x10 at init
  void* mField10;           // 0x10 — static .rodata ptr 0xed60af8
  void* mField18;           // 0x18 — subobject w/ own vptr (cell 0x12fada0,
                            //        then 0x12fb728+0x10); ctor 0x61cc48
  void* mField20;           // 0x20 — points to this+0x2c (embedded buffer)
  uint32_t mField28;        // 0x28 — 0x20 (buffer capacity, ctor 0x77b354)
  uint8_t mPad2c[0x34];     // 0x2c — buffer region, filled via memcpy 0xb52740
  uint64_t mField60;        // 0x60 — zeroed
  float mField68[2];        // 0x68 — 1.0f, 1.0f
  float mField70[2];        // 0x70 — 1.0f, 1.0f
  uint32_t mField78;        // 0x78 — zeroed
  uint8_t mPad7c[0x10];     // 0x7c — zeroed (0x77b470-0x77b474)
  float mField8c[2];        // 0x8c — 200.0f, 400.0f
  float mField94[2];        // 0x94 — 100.0f, 800.0f
  float mField9c[2];        // 0x9c — 400.0f, 10.0f
  float mFieldA4;           // 0xa4 — 0.025f
  uint64_t mFieldA8;        // 0xa8 — 0x0080000000000000 (0x77b4b4)
  float mFieldB0[2];        // 0xb0 — from singleton cell 0x12fa000+0xdb8
  uint8_t mPadB8[0x8];      // 0xb8 — unproven gap
  float mFieldC0[2];        // 0xc0 — 0.025f, 0.025f
  float mFieldC8[2];        // 0xc8 — 0.025f, 0.5f
  uint64_t mFieldD0;        // 0xd0 — zeroed
  uint32_t mFieldD8;        // 0xd8 — zeroed
  uint8_t mFieldDC[3];      // 0xdc — flag bytes 1, 1, 1
  uint8_t mPadDf;           // 0xdf — unproven gap before the 0.025f bank
  float mFieldE0;           // 0xe0 — 0.025f
  uint32_t mFieldE4;        // 0xe4 — zeroed
  uint8_t mFieldE8;         // 0xe8 — zeroed
  uint8_t mPadE9[0x7];      // 0xe9 — unproven tail pad to 0xf0
};
}  // namespace object
