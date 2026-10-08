#pragma once

#include <cstdint>

namespace nn::mii {
class CharInfoElement {
 public:
  // SDK-internal; no game-side ctor evidence (nn SDK lib layout).
  uint8_t mPad[0x5C];  // SDK-internal; no game-side ctor evidence (nn SDK lib layout)
};
}  // namespace nn::mii
