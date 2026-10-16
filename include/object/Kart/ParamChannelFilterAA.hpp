#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelFilterAA — named from ctor string evidence: ctor 0x651ae4 emits the 'aglfila' tag + FXAA param block (0xef9661-0xef97a3); channel member of the FilterAA cache (was address-anchored ParamChannelVt3218) (vptr 0x12b3218, cell 0x130daa0, n=18, site 0x651b90, ctor 0x651ae4).
class ParamChannelFilterAA : public KartParamCacheChan {
 public:
  // (no own fields beyond the Chan shape)
};
}  // namespace object
