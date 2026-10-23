#pragma once

#include <cstdint>
#include <object/Kart/KartParamCacheMid2.hpp>

// KartParamCacheBgb — named from ctor string evidence: ctor string tag 'gsysbgb' + params scale/blur_offset/enable_expand_blur/background_buffer (0xf05894-0xf0596a) (vptr 0x12bd030,
// GOT cell 0x130e840, n=?). Mid2-derived variant: ctor zeroes 0x1d0/0x1d8 and writes to 0x330.
namespace object::Kart {
class KartParamCacheBgb : public KartParamCacheMid2 {
 public:
};

}  // namespace object
