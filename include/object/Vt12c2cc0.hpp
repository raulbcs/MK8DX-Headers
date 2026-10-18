#pragma once

#include <cstdint>

// Vt12c2cc0 — PLACEHOLDER name (15-slot MI class, size 0x3c0, lazy singleton
// created at 0x7757b0); vptr 0x12c2cc0 at +0x00, secondary 0x12c2d48 at +0x08.
// extent 0x3c0 - details: doc/object/Vt12c2cc0.md

namespace object {
class Vt12c2cc0 {
 public:
  void* vtable;         // 0x00 — 0x12c2cc0 (C1 0x78bcb8 stores cell+0x10)
  void* vtable2;        // 0x08 — 0x12c2d48 secondary (cell+0x98); base-ctor
                        //        0x5ef030 first installs 0x12c2de8 here
  char mPad10[0x2b8];   // 0x10 — unproven (base-ctor-managed)
  void* mField2C8;      // 0x2C8 — C1 zeroes (0x78bce0)
  char mPad2D0[0xc];    // 0x2D0 — unproven (C1 zeroes +0x2D0..0x308 fields)
  char mPad2DC[0x8];    // 0x2DC — C1 zeroes (0x78bcf4..0x78bd14)
  char mPad2E4[0x14];   // 0x2E4 — unproven
  uint16_t mField2F8;   // 0x2F8 — C1 zeroes halfword (0x78bd0c); later holds
                        //        new 0x268 sub-object (ctor 0x773a64)
  char mPad2FA[0x6];    // 0x2FA — unproven
  void* mField300;      // 0x300 — C1 zeroes (0x78bd10)
  void* mField308;      // 0x308 — C1 zeroes (0x78bcf4)
  char mPad310[0x40];   // 0x310 — unproven (member ctor 0x628628)
  char mField350;       // 0x350 — C1 zeroes byte (0x78bd24)
  char mPad351[0x7];    // 0x351 — unproven
  void* mField358;      // 0x358 — embedded member, vptr from GOT 0x12fada0
                        //        +0x10 (0x78bd30..0x78bd3c)
  void* mField360;      // 0x360 — C1 sets = this+0x36C (0x78bd2c)
  uint32_t mField368;   // 0x368 — C1 sets 0x20 (0x78bd40)
  char mPad36C[0x4];    // 0x36C — unproven
  void* mField370;      // 0x370 — C1 zeroes (0x78bd78)
  void* mField378;      // 0x378 — C1 zeroes (0x78bd78)
  void* mField380;      // 0x380 — C1 zeroes (0x78bd78)
  char mPad388[0x18];   // 0x388 — unproven (C1 zeroes +0x390..0x3B0)
  char mField3A0;       // 0x3A0 — C1 zeroes byte (0x78bd70)
  char mPad3A1[0x17];   // 0x3A1 — unproven
  void* mField3B8;      // 0x3B8 — C1 zeroes (0x78bd68)
};
}  // namespace object
