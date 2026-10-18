#pragma once

#include <cstdint>

// Vt12c81c8 — PLACEHOLDER name; gear::Actor-derived (base C1 0x7b976c), 14 slots, no RTTI.
// C1 0x7da1e8; secondary vptr table 0x12c8248 at +0x38; slot2 FUN_71007dc378 re-installs the primary vptr.
// extent 0x59C0 (nothrow new[] 0x59C0 at factory 0x7d63ac) -
// details: doc/object/Vt12c81c8.md

namespace object {
class Vt12c81c8 {
 public:
  void* mVtable;            // 0x00 — 0x12c81c8 (via GOT cell 0x1310080, cell holds vptr-0x10)
  uint8_t mPad8[0x30];      // 0x08 — unproven padding (gear::Actor base C1 0x7b976c zeroes +0x10..+0x38)
  void* mVtable2;           // 0x38 — 0x12c8248 (via GOT cell 0x1310088); slots FUN_71007dc5b8/FUN_71007dc63c/.../FUN_71007dc700
  void* mList40Fwd;         // 0x40 — empty intrusive list head, self-pointer (this+0x40)
  void* mList40Bwd;         // 0x48 — self-pointer
  uint32_t m50;             // 0x50 — ctor: 0
  uint32_t mPad54;          // 0x54 — unproven padding
  void* m58;                // 0x58 — ctor: null
  void* mList60Fwd;         // 0x60 — empty intrusive list head, self-pointer (this+0x60)
  void* mList60Bwd;         // 0x68 — self-pointer
  uint32_t m70;             // 0x70 — ctor: 0
  uint32_t mPad74;          // 0x74 — unproven padding
  void* m78;                // 0x78 — ctor: this+0x8C
  void* m80;                // 0x80 — ctor: this+0x8C
  uint32_t m88;             // 0x88 — ctor: 0 then 0x80
  uint8_t mPad8c[0x4770];   // 0x8C — node-list head; 63 nodes at +0x11C, stride 0x120 (ctor loop 0x7da254-0x7da26c); rest unproven padding
  uint32_t m47fc;           // 0x47FC — ctor: 0
  uint8_t mPad4800[0x90];   // 0x4800 — unproven padding; sub-init FUN_7100628628 at +0x4890
  uint8_t mPad4890[0x40];   // 0x4890 — sub-object region inited by FUN_7100628628 (unverified layout)
  uint8_t mPad48d0[0x520];  // 0x48D0 — memset 0x518 at +0x48D8 then FUN_71007da74c; +0x4DE8=1, +0x4DFC=0, +0x4E00/+0x4E08 self-ptrs to +0x4E10, +0x4E14=-1, +0x4E18=0, +0x4E20=1.0f pair
  uint8_t mPad4df0[0xbd0];  // 0x4DF0 — unproven padding; memset 0x15C at +0x4E28, alternating +-1.0f at +0x4E2C..+0x4E74
};
}  // namespace object
