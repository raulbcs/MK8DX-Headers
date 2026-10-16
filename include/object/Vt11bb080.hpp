#pragma once

#include <cstdint>

// Vt11bb080 — PLACEHOLDER name; vptr 0x11bb080, n=29, offset-to-top -8;
// thunks into cluster 0x13c924-0x13cd00.

namespace object {
class Vt11bb080 {
 public:
  void* vtable;   // 0x00 — 0x11bb080
  void* mNode08;  // 0x08 — node ptr read by every thunk
  void* mNode10;  // 0x10 — alternate node ptr read by odd slots
                  // (extent unproven)
};
}  // namespace object
