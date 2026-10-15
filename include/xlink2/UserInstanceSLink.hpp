#pragma once

#include <aal/Emitter.hpp>
#include <cstdint>

namespace xlink2 {
class UserInstanceSLink {
 public:
  uint8_t mPad00[0xF8];    // 0x00
  aal::Emitter* mEmitter;  // 0xF8
};
}  // namespace xlink2
