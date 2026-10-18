#pragma once

#include <cstdint>

// Vt12d48b8 — PLACEHOLDER name; pia-ConnectionStatus-like base (same field
// idiom as nn::pia::local::LdnConnectionStatus): ids -1 at +8/+0x10/+0x20.
// vptr via GOT cell 0x1311a30 (holds vt-0x10, no typeinfo); embedded at
// parent+0x1d8, derived vptr overrides after init.
// extent 0x28 (ctor reach +0x24; next member at parent+0x200) - details:
// doc/object/Vt12d48b8.md
namespace object {
class Vt12d48b8 {
 public:
  void* mVtable;      // 0x00 — 0x12d48b8 (cell 0x1311a30 + 0x10)
  uint64_t mId8;      // 0x08 — -1
  uint64_t mId10;     // 0x10 — -1
  uint8_t mFlag18;    // 0x18 — 0
  uint8_t mGap19[3];  // 0x19 — unproven gap
  uint32_t mVal1c;    // 0x1c — 0
  uint32_t mId20;     // 0x20 — -1
  uint8_t mFlag24;    // 0x24 — 0
  uint8_t mGap25[3];  // 0x25 — unproven padding
};
}  // namespace object
