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

  AttT* mRotationMarix;  //0x48
  // 0x50 — inline 3x4 matrix (row-major);
  MtxT mFrame;               //0x50 - 0x80
  float velocity[3];         //0x80 - 0x8B — velocity vec3 (writers 0x710001732c, 0x710011f2bc, 0x710019b7e4; read KartBody member 0x101e4)
  uint8_t pad8c[0xc];        //0x8C - 0x97
  uint8_t dirty;             //0x98 — pose-dirty flag; writers |=1: 0x1736c, 0x11f770, 0x19b95c
  uint8_t pad99[0x3c];       //0x99 - 0xD4
  float mTimeScale;          //0xD8
  float mTimeScaleFraction;  //0xDC

  RigidBody();
};
}  // namespace gear
