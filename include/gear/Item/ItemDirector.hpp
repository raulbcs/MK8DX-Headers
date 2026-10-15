#pragma once

#include <cstdint>

#include <gear/Actor/Actor.hpp>
#include <gear/Item/ItemOwner.hpp>
#include <gear/Item/ItemObjManagerBase.hpp>

#include <math/seadVector.h>
#include <container/seadPtrArray.h>

#include "ItemEventManager.hpp"

namespace gear {
class ItemDirector : public Actor {
 public:
  sead::FixedPtrArray<ItemObjManagerBase, 19> mItemManagers;  // 0x38
  sead::PtrArray<ItemOwner> mItemOwners;                      // 0xE0
  uintptr_t mPadF0;                                           // 0xF0 — unproven padding
  ItemEventManager* mItemEventManager;                        //0xF8
  uint8_t mPad100[0x14];                                      // 0x100 — unproven padding
  uint32_t mFields114[23];                                    // 0x114 — written by
                                                              // calcBefore (typing pending)
// extent 0x170 (lower bound: ItemDirector::calcBefore 0x7100003208
// writes fields 0x114..0x16c — str sweep @0x3236c-0x32450; declared as
// unproven padding, field typing pending)


  ItemDirector();

  void emitItemKinoko(sead::Vector3<float> const&, sead::Vector3<float> const&, int32_t);
};
}  // namespace gear
