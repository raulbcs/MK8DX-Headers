#pragma once

#include <cstdint>

// object::Vt12c5d70 (size 0x6CB8) — gear::Actor-derived pool/buffer manager
// (nn::os reader-writer lock + ~17 ring descriptors); PLACEHOLDER name.
// Factory FUN_7100398750, new 0x6CB8 at 0x39882C; C1 FUN_71007C45D0.
// extent 0x6CB8 - details: doc/object/Vt12c5d70.md

struct Vt12c5d70 {
  uint64_t vptr;              //0x00 — 0x12c5d70 (cell 0x130ff20 = 0x12c5d60, +0x10)
  uint8_t actor_08[0x30];     //0x08 - 0x37 — gear::Actor base body (base ctor 0x7b976c); fields unverified
  uint8_t lock_38[0x30];      //0x38 - 0x67 — nn::os::InitializeReaderWriterLock (0x7c45fc)
  uint32_t zero_68;           //0x68 — ctor stores 0 (ring-desc count)
  uint32_t cap_6C;            //0x6C — capacity 1000 (0x3E8)
  uint64_t data_70;           //0x70 — set to this+0x78 by 0x60b918
  uint8_t buffers_78[0x6240]; //0x78 - 0x62B7 — ctor zeroes; large 1000-entry descs at +0x68, +0x1F48, +0x3EA0, +0x5DF8, then ~0x98-stride small descs 0x5E88..0x62C8 (u64 zeros at 0x1F50/0x1F58-style pairs precede each)
  uint8_t counters_62B8[0x4F8]; //0x62B8 - 0x67AF — ctor zero loop (str wzr [x19,x8]); u64 zeros at 0x6318, 0x67E0
  uint8_t tail_67B0[0x508];   //0x67B0 - 0x6CB7 — ctor zero loop continues; last u64 zero at 0x6CA8; 8-byte tail pad (unproven)
};
