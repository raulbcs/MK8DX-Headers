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
  // +0x80: velocity vec3, maintained together with mFrame by the pose
  // writers (KartBody member 0x710001732c stores (KartBody+0x128) *
  // (KartBody+0xd8..0xdc) here; sink 0x710011f2bc copies its +0x1b4..0x1bc;
  // virtual 0x710019b7e4 copies +0xd0..0xd8).
  float velocity[3];                           //0x80 - 0x8B; read as vec3 by
                                               // KartBody member 0x101e4
  uint8_t pad8c[0xc];                          //0x8C - 0x97
  uint8_t dirty;                               //0x98 — pose-dirty flag; frame
                                               // writers do |=1 before
                                               // overwriting mFrame (0x1736c,
                                               // 0x11f770, 0x19b95c)
  uint8_t pad99[0x3c];                         //0x99 - 0xD4
  float mTimeScale;                            //0xD8
  float mTimeScaleFraction;                    //0xDC

  RigidBody();
};
}  // namespace gear
