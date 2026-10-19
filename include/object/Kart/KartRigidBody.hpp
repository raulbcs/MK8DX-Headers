#pragma once

#include <gear/RigidBody.hpp>

namespace object {
class KartRigidBody : public gear::RigidBody {
 public:
  virtual void test();
  // Class ends at 0xE0: +0xE0 is the first field of the DERIVED class
  // (static-table pointer written by the Body 0x178da4 and Move 0x1812b4
  // ctors), not a RigidBody field.

  KartRigidBody();
};
}  // namespace object
