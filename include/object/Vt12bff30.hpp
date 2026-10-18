#pragma once

#include <cstdint>

// Vt12bff30 — PLACEHOLDER name; vptr 0x12bff30 (GOT cell 0x130ed20 = vptr-0x10),
// 16 slots, no RTTI. Three intrusive list sentinels at +0x18/+0x28/+0x38.
// extent 0x48 - details: doc/object/Vt12bff30.md

namespace object {
class Vt12bff30 {
 public:
  void* mVtable;  // 0x00 — 0x12bff30
  void* m8;       // 0x08 — C1 arg x1
  void* m10;      // 0x10 — C1 arg x2
  void* m18;      // 0x18 — sentinel node {this+0x18, this+0x18}
  void* m20;      // 0x20
  void* m28;      // 0x28 — sentinel node {this+0x28, this+0x28}
  void* m30;      // 0x30
  void* m38;      // 0x38 — sentinel node {this+0x38, this+0x38}
  void* m40;      // 0x40
};
}  // namespace object
