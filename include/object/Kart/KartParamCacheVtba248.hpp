#pragma once

#include <cstdint>

namespace object {
// KartParamCacheVtba248 — address-anchored name (vptr 0x12ba248, SECONDARY
// interface vtable at +0x248 of a class whose primary vptr is 0x12ba1f0 at
// +0x00). Size bounded 0x7b8 (member slot [outer+0x4d00, outer+0x54b8) in
// ctor 0x71006bb300). C1 0x71006dd190.
// extent 0x7b8 - details: doc/object/Kart/KartParamCacheVtba248.md
class KartParamCacheVtba248 {
 public:
  void* vptr;               // 0x00 — primary 0x12ba1f0 (cell 0x130e330 + 0x10,
                            // site 0x6dd204)
  uint8_t mOwn8[0x240];     // 0x08 — own-field region (base stub 0x71006c6128,
                            // name 0xf028cf at 0x6dd1d8)
  void* vptr248;            // 0x248 — secondary 0x12ba248 (cell + 0x68)
  uint8_t mOwn250[0x1f0];   // 0x250 — own-field region; ctor zeros at
                            // 0x418-0x438 (0x6dd1e8-0x6dd21c)
  uint8_t mPad440[0x48];   // 0x440 — unproven padding
  char mMember488[0x108];   // 0x488 — member init entered at 0x6dd214;
                            // interior unproven
  uint8_t mField590[0x108]; // 0x590 — ctor-assigned words (0x6dd87c-0x6dd894)
  uint8_t mPad6a0[0x70];   // 0x6a0 — unproven padding
  void* mPtr698;            // 0x698 — member ptr (0x6dd784)
  uint32_t mField710;       // 0x710 — zeroed (0x6dd790/0x6dd8a0)
  uint8_t mPad714[4];       // 0x714 — unproven padding
  char mChan718[0x18];      // 0x718 — channel-pair member (ctor pair
                            // 0x7100662f30/0x7100662f70, 0x6dd7a4-0x6dd7cc)
  uint32_t mField730;       // 0x730 — ctor value (0x6dd7e4)
  uint8_t mPad734[4];       // 0x734 — unproven padding
  char mChan738[0x18];      // 0x738 — channel-pair member (0x6dd7f4-0x6dd810)
  uint32_t mField750;       // 0x750 — ctor value (0x6dd818)
  uint8_t mPad754[4];       // 0x754 — unproven padding
  uint32_t mZero758[2];     // 0x758 — ctor zeros
  void* mZero760;           // 0x760 — ctor zero
  uint32_t mZero768;        // 0x768 — ctor zero
  uint8_t mPad76c[0x24];    // 0x76c — unproven padding
  void* mZero790;           // 0x790 — ctor zero
  void* mPtr798;            // 0x798 — ptr (0x6dd870)
  uint32_t mField7a0;       // 0x7a0 — ctor value (0x6dd864)
  uint8_t mPad7a4[0x14];    // 0x7a4 — unproven padding (to the 0x7b8 bound)
};
}  // namespace object
