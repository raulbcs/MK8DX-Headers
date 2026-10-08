#pragma once

#include <cstdint>

namespace object {
// Vt12f3160 — PLACEHOLDER name (theme unproven). vptr 0x12f3160, n=9,
// typeinfo NULL (game-side), offset-to-top -0x218 (secondary-base table
// of a multiple-inheritance class).
//
// Slots: 0xab6404, 0xab6598, 0xab75fc, 0xab77b0, 0xab7e38, 0xab8328,
// then ret-stubs 0x63c710/0x63c724/0x63c728.
//
// Single code reference 0xaca03c in FUN_7100ac9f14: loads GOT cell
// 0x130d918 (holds vt-0x10), adds 0x10 and installs the vptr into five
// sub-object fields (+0x130/+0x150/+0x178/+0x198/+0x1c0) of one large
// heap object — a multiply-inherited facade whose bases all resolve to
// this table. Slots live in the same 0xab64xx-0xab83xx region as the
// consumer, so the concrete class is code-local; no RTTI, no owned
// strings.
class Vt12f3160 {
 public:
  void* vtable;  // 0x00 — 0x12f3160
                 // (extent unproven)
};
}  // namespace object
