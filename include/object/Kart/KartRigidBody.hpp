#pragma once

#include <gear/RigidBody.hpp>

namespace object {
class KartRigidBody : public gear::RigidBody {
 public:
  virtual void test();
  // Class ends at 0xE0: the "mPadE0 Vector3f" here was a misread —
  // the derived ctors (Body 0x178da4, Move 0x1812b4) overwrite +0xE0
  // with a static-table pointer, which is the first field of the
  // DERIVED class, not a RigidBody field.

  KartRigidBody();
};
}  // namespace object
