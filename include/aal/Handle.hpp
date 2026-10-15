#pragma once

#include <aal/Spatial/VirtualizeMode.hpp>
#include <cstdint>

namespace aal {
class Handle {
 public:
  uint8_t mPad00[0x10];  // 0x00

  void setVolume(float);
  bool isActive() const;
  bool setVirtualizeMode(aal::VirtualizeMode);
};
}  // namespace aal