#pragma once

#include <cstdint>
#include <object/Kart/KartParamCacheChanBase.hpp>

// KartParamCacheChan — address-anchored name (vptr 0x12b21e0,
// extent 0x20
namespace object::Kart {
class KartParamCacheChan : public KartParamCacheChanBase {
 public:
  char mTail18[8];  // 0x18 — filled by the 0x7100662f70 init
};
}  // namespace object
