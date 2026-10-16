# ItemObjBase (gear::ItemObjBase)

- Extent 0x328 (allocation size 0x328 @0x71001816b0 in the KartVehicleMove ctor → 0x71003aef8c; stores reach 0x320 and match the 0x2f0..0x318 fields).

Actor-derived item-object base; full vtable (slots 0x00-0x180) declared in the header with per-slot offsets. Default-return overrides: getGndColScaleMax 2.0f (0x54), getWallColOffsetY 2.0f (0x58), getWallColRadiusRate 1.0f (0x5C), getColRadius 5.0f (0x60), getBoxColRadius 6.0f (0x64), getColRateForNetRecvKart 0.2f (0x6C), getOffsetHangY_ 5.3f (0x128), getOffsetMultiY_ 5.3f (0x130), getOffsetMultiZ_ 4.0f (0x134), getRotVelRatioMulti_ 0.05f (0x138), getAroundEquipHeightOfs 0.0f (0x13C), getAroundEquipScale_ 1.0f (0x140), isBurst false (0xF8).

## Fields

- 0x38-0x57 — unproven padding.
- 0x58 mItemType (EItemType); 0x5C unproven.
- 0x60 mObjectIdx; 0x64-0x97 unproven padding.
- 0x98 mScaleStructPtr; 0xA0 mTransform (sead::Matrix34f); 0xD0 unproven padding.
- 0xD8 mScale (sead::Vector3f); 0xE4-0x127 unproven padding.
- 0x128 mScaleFactor; 0x12C mPosition; 0x138 unproven padding.
- 0x144 mVelocity; 0x150 mSpeed; 0x154 mMoveVelocity; 0x160 unproven; 0x16C-0x197 unproven padding; 0x190 mPad190 (float*).
- 0x198-0x1B7 unproven padding.
- 0x1B8 mGroundCollision (gear::GndCol*); 0x1C0-0x1CB unproven; 0x1CC-0x1F7 unproven padding.
- 0x1F8 mReactType; 0x1FC unproven padding.
- 0x204 mThrowVelocity; 0x210-0x227 unproven padding.
- 0x228 mReflectTooMany; 0x229-0x277 unproven padding.
- 0x278 mXLinkUser (gear::XLinkUser*); 0x280-0x2EB unproven padding.
- 0x2EC mCurrentCollisionMode / 0x2F0 mPreviousCollisionMode (EColMode); 0x2F4 unproven.
- 0x2F8 mStandbyCounter; 0x2FC mEquipMultiForward; 0x308 mEquipMultiUp; 0x314 unproven padding.
- 0x318 mItemSerial; 0x31A unproven; 0x31C-0x327 unproven padding.

## Construction / init order

- Ctor ItemObjBase(gear::EItemType, int) — defined (address not separately labeled).
- Allocation proof: 0x71001816b0 (movz/alloc 0x328 in the KartVehicleMove ctor) → 0x71003aef8c; stores reach 0x320.

## Methods (non-virtual)

exitBreak, exitVanish, calcDynamicScaleAnimInner_(int,int,int,float,float), setColMode(EColMode), addRhythmSkeletalAnmFrame_(int), addSkeletalAnmFrame_(int,float), updateAntiG_(bool), updateModelDirection_(bool), calcModelMatrix_(), calcParabolicMotion_(float), checkGndCol(gear::GndCol*), getKartInfo(int) -> object::KartInfoProxy*, isDisappearState().
