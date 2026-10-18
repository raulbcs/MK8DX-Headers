#pragma once

#include <cstdint>

// Vt12d27a0 - MI secondary-base vtable (ot -0x208) of the RenderEngine-family
// complete object (size 0x770, C1 0x88e6b8, name string "RenderEngine").
// extent 0x770 (complete object) - details: doc/object/Vt12d27a0.md

namespace object {

// Row-only interface: slots below belong to the secondary base subobject
// installed at [this+0x208] (install site unverified).
class Vt12d27a0 {
 public:
  void* vtable;      // 0x00 of the subobject - 0x12d27a0 (ot row 0x12d2790
                     // holds -0x208; no typeinfo, no GOT cell of its own)
  uint8_t mGap8[0x768];  // 0x08 - unproven (row-only interface; outer object
                     // extent cited as 0x770)
};

}  // namespace object
