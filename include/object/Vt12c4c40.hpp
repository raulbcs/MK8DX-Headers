#pragma once

#include <cstdint>

// Vt12c4c40 - PLACEHOLDER name; 35-slot named-parameter node ("scale"
// family); carries a name string pointer at +0x208 ("mRank" at one site)
// and the 0.01f/0.25f scale defaults; built inline by two sites.
// extent 0x280 - details: doc/object/Vt12c4c40.md

namespace object {
class Vt12c4c40 {
 public:
  void* mVtable;           // 0x000 - 0x12c4c40 (via GOT cell 0x130fb18)
  uint8_t mPad8[0x1B8];    // 0x008 - unproven padding
  uint32_t mF1C0;          // 0x1C0 - site-dependent (4 or caller value)
  uint32_t mF1C4;          // 0x1C4 - site-dependent (1)
  uint8_t mPad1C8[0x28];   // 0x1C8 - unproven padding
  float mF1F0;             // 0x1F0 - scale default 0.01f
  float mF1F4;             // 0x1F4 - unverified at these sites
  float mF1F8;             // 0x1F8 - scale default 0.015625f / 0.25f
  uint8_t mPad1FC[0xC];    // 0x1FC - unproven padding
  void* mName;             // 0x208 - rodata name string ptr ("mRank", 0xf0ccdc)
  uint8_t mPad210[0x68];   // 0x210 - unproven padding
  void* mOwner;            // 0x278 - owning subobject (&this->field_xxx)
};
}  // namespace object
