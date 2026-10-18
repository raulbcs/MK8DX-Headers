#pragma once

#include <cstdint>

// Vt12d63c0 — SharcArchiveRes-derived game class (base C1 0xa877dc, slot4 =
// sead::SharcArchiveRes::getFileImpl_); MI secondaries at +0x58/+0xa0/+0x1b8.
// extent 0x300 - details: doc/object/Vt12d63c0.md

namespace object {
class Vt12d63c0 {
 public:
  void* mVtable;          // 0x00 — 0x12d63c0 (GOT cell 0x1311f80 = vptr-0x10)
  uint8_t mPad8[0x50];    // 0x08 — unproven (SharcArchiveRes base body)
  void* m58;              // 0x58 — secondary vptr 0x12d6458 (offset-to-top -0xa8)
  uint8_t mPad60[0x40];   // 0x60 — unproven
  void* mA0;              // 0xa0 — vptr from cell 0x12fbd88 (overwrites 0x12cdcf8 store)
  uint8_t mPadA8[0x110];  // 0xa8 — unproven (tree walk reads ptr at +0xa8, field at +0x2a0)
  void* m1B8;             // 0x1b8 — secondary vptr 0x12cdcf8 (GOT cell 0x1310da0)
  void* m1C0;             // 0x1c0 — this+0x12c
  uint32_t m1C8;          // 0x1c8 — 0x100
  uint8_t mPad1CC[0x64];  // 0x1cc — unproven
  void* m230;             // 0x230 — zeroed
  void* m238;             // 0x238 — zeroed
  void* m240;             // 0x240 — zeroed
  void* m248;             // 0x248 — zeroed
  uint32_t m250;          // 0x250 — zeroed
  uint32_t mPad254;       // 0x254 — unproven padding
  void* m258;             // 0x258 — zeroed
  uint8_t mPad260[0xa0];  // 0x260 — unproven padding
};
}  // namespace object
