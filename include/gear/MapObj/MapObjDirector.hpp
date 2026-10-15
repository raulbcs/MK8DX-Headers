#pragma once

#include <container/seadBuffer.h>

#include <cstdint>

#include "EMapObjID.hpp"
#include "MapObjBase.hpp"
#include "MapObjCreateArg.hpp"
#include "MapObjManagerBase.hpp"
#include "MapObjParameter.hpp"
#include "container/seadPtrArray.h"
#include "gear/Actor/Actor.hpp"

namespace gear {
using MapObjCreatorFn = gear::MapObjBase* (*)(gear::MapObjCreateArg&);

class MapObjDirector : public Actor {
 public:
  sead::Buffer<MapObjManagerBase*> mManagers;     // 0x38
  uint8_t mPad48[0x08];                           // 0x48
  sead::PtrArray<MapObjParameter> mMapObjParams;  // 0x50

  void reactThunder();
  void loadParameter_();

  MapObjManagerBase* searchManager(gear::EMapObjID);
  MapObjParameter* getMapObjParameter(gear::EMapObjID);
  MapObjCreatorFn searchMapObjCreateFunc(gear::MapObjParameter const*);

  static bool append(gear::EMapObjID,
                     gear::MapObjBase* (*)(gear::MapObjCreateArg&));
  static bool appendMgr(gear::EMapObjID,
                        gear::MapObjManagerBase* (*)(gear::MapObjParameter*));
};
}  // namespace gear
