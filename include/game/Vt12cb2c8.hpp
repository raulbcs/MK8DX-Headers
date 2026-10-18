#pragma once

#include <cstdint>

namespace game {
// Byml-driven parameter-table record: derived of Vt12cb108 (C1 0x8144d0,
// base parse 0x8147d8) with a 0x10-byte tail of extra parsed fields.
// extent 0x370 - details: doc/game/Vt12cb2c8.md
class Vt12cb2c8 {
 public:
  void* vtable;  // 0x00 - vptr 0x12cb2c8 (GOT cell 0x1310710 holds
                 // 0x12cb2b8 = vptr-0x10)
  uint8_t mBase8[0x358];  // 0x08 - base Vt12cb108 body (0x08..0x35f),
                          // see doc/game/Vt12cb108.md
  uint16_t mField360;  // 0x360 - u16, zeroed before parse
  uint8_t mField362;   // 0x362 - byte, parsed (0x8d1d80, key edb0e33)
  uint8_t mPad363;     // 0x363
  uint32_t mField364;  // 0x364 - optional u32 from node (key f0b0d86)
  uint32_t mField368;  // 0x368 - optional u32 from node (key f0be2e)
  uint16_t mField36c;  // 0x36c - parsed (0x8d1414, key f0be2e)
  uint8_t mPad36e[0x2];  // 0x36e - padding to extent
};
}  // namespace game
