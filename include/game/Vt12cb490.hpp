#pragma once

#include <cstdint>

namespace game {
// Byml-driven parameter-table record: derived of Vt12cb108 (C1 0x8144d0)
// with an 8-byte tail of parsed fields; built in a per-element loader
// loop (one record per parsed array element).
// extent 0x368 - details: doc/game/Vt12cb490.md
class Vt12cb490 {
 public:
  void* vtable;  // 0x00 - vptr 0x12cb490 (GOT cell 0x1310768 holds
                 // 0x12cb480 = vptr-0x10)
  uint8_t mBase8[0x358];  // 0x08 - base Vt12cb108 body (0x08..0x35f),
                          // see doc/game/Vt12cb108.md
  uint16_t mField360;  // 0x360 - u16, zeroed then parsed (key f0b0f0c)
  uint8_t mField362;   // 0x362 - byte, zeroed then parsed (key ee2098b)
  uint8_t mField363;   // 0x363 - byte, zeroed then parsed (key ee30d03)
  uint8_t mPad364[0x4];  // 0x364 - padding to extent
};
}  // namespace game
