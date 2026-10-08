#pragma once
#include <gear/Math/Matrix.hpp>

namespace object {
class KartCamera {
 public:
  // Unproven — Switch ctor not identified (no RTTI, stripped binary);
  // extent fixed by the first proven field at 0x08 (setMatrix target
  // range begins there).
  char pad_00[8];  // unproven - extent fixed by first proven field at 0x08

  void setMatrix(gear::MtxT const& transform);
};
}  // namespace object
