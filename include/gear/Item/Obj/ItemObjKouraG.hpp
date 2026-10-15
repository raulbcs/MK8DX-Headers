#pragma once

#include <math/seadVector.h>

#include <cstdint>

#include "ItemObjBase.hpp"

namespace gear {
class ItemObjKouraG : public ItemObjBase {
 public:
  uint8_t mPad328[0x1C];      // 0x328 — unproven padding
  sead::Vector3f mDirection;  // 0x344
  uint8_t mPad350[0x40];      // 0x350 — unproven padding
  // 0x390
// extent 0x390 (docblock 0x390; base chain of ItemObjKouraR (0x460 proven))

};
}  // namespace gear
