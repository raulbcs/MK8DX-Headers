#pragma once

#include <cstdint>
#include <object/Kart/KartParamCacheMid.hpp>

// KartParamCacheMultiFilterColorDrift — named from ctor string evidence: ctor name string 'MultiFilterColorDrift' + params drift_r/g/b (0xef9e5b-0xef9e8b) (vptr 0x12b37d8,
// extent 0x170
namespace object::Kart {
class KartParamCacheMultiFilterColorDrift : public KartParamCacheMid {
 public:
  char mChanPair110[0x60];  // 0x110 — three 0x20 channel pairs (ChanBase ctor 0x7100662f30), each with two w32 tail fields (0x128/0x12c, 0x148/0x14c, 0x168/0x16c)
};
}  // namespace object
