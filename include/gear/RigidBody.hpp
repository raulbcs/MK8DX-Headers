#pragma once

#include <gear/Math/Matrix.hpp>
#include <math/seadVector.hpp>
#include <math/seadQuat.hpp>

namespace gear {
class RigidBody {
 public:
  virtual void test();

  MtxT mTransform;              //0x8 - 0x34
  sead::Quat<float> mRotation;  // 0x38 - 0x44

  AttT* mRotationMarix;                        //0x48
  // 0x50 is an inline 3x4 (row-major, 16-byte rows; translation at
  // +0x5c/+0x6c/+0x7c). The ghost frame builder 0x71003b06c8 loads
  // +0x50/+0x60/+0x70, +0x54/+0x64/+0x74, +0x58/+0x68/+0x78 and
  // +0x5c/+0x6c/+0x7c as 12 floats and feeds PosFromDots 0x71003af3f8
  // (world = M*dots + T), so it is a matrix, not a Vector3* dereference.
  MtxT mFrame;                                 //0x50 - 0x80
  uint8_t pad80[0x10];                         //0x80 - 0x8F
  float unknownArea[0x12];                     //0x90 - 0xD4
  float mTimeScale;                            //0xD8
  float mTimeScaleFraction;                    //0xDC

  RigidBody();
};
}  // namespace gear
