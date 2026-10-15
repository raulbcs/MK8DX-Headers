#pragma once

#include <cstdint>
#include <gear/Course/FieldDirector.hpp>
#include <gear/Item/ItemDirector.hpp>
#include <gear/MapObj/MapObjDirector.hpp>
#include <gear/Race/RaceDirector.hpp>
#include <object/Directors/RecorderDirector.hpp>
#include <object/Effect/GameEffectDirector.hpp>
#include <object/Kart/KartDirector.hpp>

namespace object {
class ObjectEngine {
 public:
  // Unproven — Switch ctor not identified (no RTTI, stripped binary);
  // extent fixed by mRaceDirector at 0x218. The Wii U (32-bit) layout
  // suggests per-director init state inside this range.
  uint8_t mPad00[0x1F8];  // unproven - extent fixed by mRaceDirector at 0x218
  gear::GndColManager* mGndColManager;               // 0x1F8
  uint8_t mPad200[0x18];                             // 0x200
  gear::RaceDirector* mRaceDirector;                 // 0x218
  gear::FieldDirector* mFieldDirector;               // 0x220
  uintptr_t mPad228;                                 // 0x228 — unproven padding
  object::RecorderDirector* mRecorderDirector;       // 0x230
  object::KartDirector* mKartDirector;               // 0x238
  gear::ItemDirector* mItemDirector;                 // 0x240
  uintptr_t mPad248;                                 // 0x248 — unproven padding
  gear::MapObjDirector* mMapObjDirector;             // 0x250
  char pad_13C[0x8];                                 // 0x13C — unproven padding
  object::GameEffectDirector* m_gameEffectDirector;  // 0x144

  static ObjectEngine* getEngine();
};
}  // namespace object
