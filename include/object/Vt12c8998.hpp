#pragma once

#include <cstdint>

// Vt12c8998 — PLACEHOLDER name (transform/record class, identity not proven).
// vptr 0x12c8998, 31 slots; C1 FUN_71007e5f30 over base C1 FUN_71007e0848.
// size 0x110 (operator new 0x110 at 0xCC884 in FUN_71000cc644) -
// details: doc/object/Vt12c8998.md

namespace object {
class Vt12c8998 {
 public:
  void* mVtable;         // 0x00 — 0x12c8998 (via GOT cell 0x1310190)
  uint64_t mZero8;       // 0x08 — zeroed by base ctor
  float mMat10[12];      // 0x10 — memcpy 0x30 from rodata 0xf57ad0 (identity-like)
  uint64_t mZero40;      // 0x40 — zeroed by base ctor
  uint8_t mFlag48;       // 0x48 — bool, zeroed by base ctor
  uint8_t mPad49[0x3];   // 0x49 — base ctor writes nothing
  uint64_t mZero4c;      // 0x4c — zeroed by base ctor
  uint64_t mZero54;      // 0x54 — zeroed by base ctor
  uint8_t mFlag5c;       // 0x5c — bool, zeroed by base ctor
  uint8_t mPad5d[0x3];   // 0x5d — base ctor writes nothing
  uint64_t mF60;         // 0x60 — static [0x12fb148] qword
  uint32_t mF68;         // 0x68 — static [0x12fb148+8] word
  uint8_t mFlag6c;       // 0x6c — bool, zeroed by base ctor
  uint8_t mPad6d[0x3];   // 0x6d — base ctor writes nothing
  uint64_t mZero70;      // 0x70 — zeroed by derived ctor
  float mV78;            // 0x78 — static [0xf57b7c+0] float (0.0f)
  float mV7c;            // 0x7c — static [0xf57b7c+4] float (0.0f)
  float mV80;            // 0x80 — static [0xf57b7c+8] float (1.0f)
  float mMat84[9];       // 0x84 — memcpy 0x24 from static 0x135e218 (.bss)
  uint64_t mFa8;         // 0xa8 — static [0x12fb148] qword
  float mFb0;            // 0xb0 — static [0x12fb148+8] word as float (unverified)
  uint8_t mFlagb4;       // 0xb4 — bool, zeroed by derived ctor
  uint8_t mPadb5[0x3];   // 0xb5 — derived ctor writes nothing
  uint64_t mFb8;         // 0xb8 — static [0x12fb148] qword
  uint32_t mFc0;         // 0xc0 — static [0x12fb148+8] word
  float mMatc4[9];       // 0xc4 — memcpy 0x24 from static 0x135e218 (.bss)
  uint64_t mFe8;         // 0xe8 — static [0x12fb148] qword
  uint32_t mFf0;         // 0xf0 — static [0x12fb148+8] word
  uint64_t mFf4;         // 0xf4 — static [0x12fb148] qword
  uint32_t mFfc;         // 0xfc — static [0x12fb148+8] word
  uint64_t mF100;        // 0x100 — static [0x12fb148] qword
  uint32_t mF108;        // 0x108 — static [0x12fb148+8] word
  uint8_t mPad10c[0x4];  // 0x10c — derived ctor writes nothing
};
}  // namespace object
