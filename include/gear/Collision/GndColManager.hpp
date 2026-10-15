#pragma once

#include <math/seadVector.h>

#include <cstdint>
#include <gear/Course/MapUnitDefine.hpp>

#include "GndColCheckRayInfo.hpp"

namespace gear {
class GndColManager {
 public:
  void checkRay(gear::GndColCheckRayInfo*, sead::Vector3<float> const&,
                sead::Vector3<float> const&, float, uint32_t, uint32_t,
                MapUnitDefine::PointId);
};
}  // namespace gear
