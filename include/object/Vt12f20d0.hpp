#pragma once

#include <cstdint>

// Vt12f20d0 — PLACEHOLDER name; sead::FileDevice subclass proxying a device
// at +0x80 (doIsAvailable_ 0xa8048c). Inline-constructed, no standalone C1.
// extent 0xa0 - details: doc/object/Vt12f20d0.md

namespace object {
class Vt12f20d0 {
 public:
  void* vtable;         // 0x00 — 0x12f20d0 (inline ctor 0xa80348)
  uint8_t mPad8[0x8];   // 0x08 — unproven
  uint32_t mField10;    // 0x10 — 0x100 (0xa8034c)
  uint8_t mPad14[0x6c]; // 0x14 - 0x80 - unproven
  void* mProxiedDevice;  // 0x80 — proxied sead::FileDevice (0xa80340)
  void* mField88;       // 0x88 — ptr (0xa80350)
  void* mField90;       // 0x90 — self-ptr to +0x9C (0xa80344)
  uint32_t mField98;    // 0x98 — read at 0xa80404
  uint8_t mField9c;     // 0x9C — u8 (0xa8036c)
  uint8_t mPad9d[0x3]; // 0x9D - unproven
};
}  // namespace object
