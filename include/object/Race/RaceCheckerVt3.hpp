#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object {
// Checker-family member: vtable .data 0x12d0e78 (GOT cell 0x1311120),
// ctor 0x7100882db0, D1 0x882e48, D0 0x882e88. Single allocation site
// in the checker graph init (new[](0x70, nothrow) at 0x87e030; back-ptr
// 0x28/0x30 wired by the creator like the other family members).
//
// Custom RTTI: dynamic typeinfo 0x882ad4 (`ldr x8,[x0,#0xb8];
// ldr w0,[x8,#0xc]; ret`) — NOT a stub; the per-object id lives in a
// channel-family field, so ids are shared across the group of 5
// vtables (0x1261178/0x12612d8/0x1261438/0x1261598 secondary bases).
//
// The ctor allocates a 0x38 recorder channel sub-object and stores it
// at +0x68; both dtors delete it and tail-jump to the Actor dtor.
// Channel layout (built inline at 0x882dd8-0x882e38):
//   +0x00 vptr        (GOT cell 0x1311228 — recorder channel subclass)
//   +0x08 fn ptr      (GOT cell 0x12fae28)
//   +0x10 name        "" (rodata 0xed6af8, empty string)
//   +0x18 vptr 2      (GOT cell 0x1311130 — secondary base)
//   +0x20 owner       this
//   +0x28 0x78
//   +0x30 1
class RaceCheckerVt3 : public gear::Actor {
 public:
  virtual void slot70();  //0x70
  virtual void slot78();  //0x78

  uint64_t mField38;  // 0x38 — zeroed on ctor
  uint32_t mField40;  // 0x40 — zeroed on ctor
  uint32_t mPad44;    // 0x44 — unproven padding
  uint64_t mField48;  // 0x48 — zeroed on ctor
  char mPad50[0x18];  // 0x50 — zeroed on ctor (to 0x68)
  void* mChannel68;   // 0x68 — owned 0x38 recorder channel sub-object
};
}  // namespace object
