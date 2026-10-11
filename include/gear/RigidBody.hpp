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
  // The ghost playback frame builder 0x71003b06c8 reads this+0x50..+0x7c
  // as an inline 3x4 matrix (columns at +0x50/+0x60/+0x70, stride 0x10;
  // translation at +0x5c/+0x6c/+0x7c) and copies it into its ctx, where
  // PosFromDots 0x71003af3f8 computes world = M*dots + T. The frame is
  // therefore a matrix, not a Vector3* dereference: for the
  // KartVehicleMove instance bound = [[kart+8]+0x28], +0x50 holds a
  // matrix. The recorded ghost translation is the T column of mTransform
  // above (+0xc/+0x1c/+0x2c), which matches mTransform as declared.
  sead::Vector3<float>* mPosition;             //0x50
  sead::Vector3<float> mVelocity;              //0x58 - 0x60
  sead::Vector3<float> mAngularVelocity;       //0x64 - 0x6C not sure about this one
  float mMass1;                                //0x70;
  float mMass2;                                //0x74;
  sead::Vector3<float> mInertiaTensor;         //0x78 - 0x80
  sead::Vector3<float> mInverseInertiaTensor;  //0x84 - 0x8C;
  float unknownArea[0x12];                     //0x90 - 0xD4
  float mTimeScale;                            //0xD8
  float mTimeScaleFraction;                    //0xDC

  RigidBody();
};
}  // namespace gear
