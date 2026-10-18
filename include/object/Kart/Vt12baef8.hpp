#pragma once

#include <cstdint>

namespace object {
// Vt12baef8 — address-anchored name; secondary interface row 0x12baef8
// (offset-to-top -0xd0, no RTTI) of a derived variant of the ParamNodeVt47a0
// (primary 0x12f47a0, cell 0x13154e8) family: its dtor thunks 0x71006fb7c4/
// 0x71006fb7cc adjust this -0x30 into the shared dtor 0x7100af2658.
// extent >= 0xeb0 (inherited; unproven) - details: doc/object/Kart/Vt12baef8.md
class Vt12baef8 {
 public:
  void* vptrPrimary;    // 0x00 — derived primary (row unmapped)
  uint8_t pad08[0x28];  // 0x08 — unproven gap
  void* vptr30;         // 0x30 — secondary 0x12baef8 (overrides the
                        //   0x12f48e0 slot the base dtor installs)
  uint8_t pad38[0x18];  // 0x38 — unproven gap
  // 0xec0 — manager field destroyed via 0x710060b984 (0xaf2718)
  // 0xed0/0xed4 — count-driven lists torn down at 0xaf2720..0xaf2760
};
}  // namespace object
