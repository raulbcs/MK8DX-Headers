#pragma once

#include <cstdint>

#include "LapRankChecker.hpp"

#include <gear/Actor/Actor.hpp>

namespace object {
class RaceCheckerBase;
}  // namespace object

namespace gear {
// gear::RaceDirector — vtable 0x11b2f28, size 0x90; walks the element
// array at 0x40 every frame (calc) and tears it down (exit).
// Details: doc/gear/Race/RaceDirector.md
class RaceDirector : public Actor {
 public:
  // Slots beyond Actor's vtable; enter/calc/exit fire pre/post hook pairs.
  // Default impls (vtable 0x11b2f28, GOT cell 0x12fbc58) shared by derived
  // directors; slots 0xa8/0xc0/0xc8 exist but are not declared below.
  virtual void slot70();        //0x70 — unknown
  virtual void slot78();        //0x78 — unknown
  virtual void onEnterStart();  //0x80 — enter() announces here before walking the child array
  virtual void onEnterEnd();    //0x88 — enter() tail call
  virtual void onCalcStart();   //0x90 — calc() opens with this before the child walk
  virtual void onCalcEnd();     //0x98 — calc() tail call
  virtual void slotA0();        //0xa0 — unknown
  virtual void slotA8();        //0xa8 — no-op (ret void)
  virtual void onExitStart();   //0xb0 — exit() opens with this before the child walk
  virtual void onExitEnd();     //0xb8 — exit() tail call

  bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const*) const;                             //0x00
  sead::RuntimeTypeInfo::Interface const* getRuntimeTypeInfo() const asm("RaceDirector::getRuntimeTypeInfo");  //0x08
  void enter() asm("RaceDirector::enter");                                                                     //0x28 — RaceDirector::enter (Actor override)
  void calc() asm("RaceDirector::calc");                                                                       //0x30 — RaceDirector::calc
  void exit() asm("RaceDirector::exit");                                                                       //0x40 — RaceDirector::exit
  bool isDirector() asm("RaceDirector::isDirector");                                                           //0x48 — RaceDirector::isDirector
  void enterOuter() asm("RaceDirector::enterOuter");                                                           //0x68 — RaceDirector::enterOuter
  ~RaceDirector();                                                                                             //0x10/0x18 — D1/D0 carry the MethodTree labels via linker aliases in the

  uint32_t mActorCount;                       //0x38 — element count (ctor: 3, 0x4d818-0x4d830)
  uint8_t mPad3C[0x4];                        // 0x3C — unproven gap
  Actor** mActors;                            //0x40 — Actor array (alloc 0x18 = 3 slots)
  uint8_t mPad48[4];                          //0x48 — unproven padding
  uint32_t mInsertCursor4C;                   //0x4C — child insertion cursor (0x4d8e8-0x4d9b8)
  object::RaceCheckerBase* mRaceCheckerBase;  //0x50 — ctor arg x1 (0x4d808)
  gear::LapRankChecker* mLapRankChecker;      //0x58
  Actor* mSubActor60;                         //0x60 — new(0xB0), ctor 0x7100066448 (vtable 0x11b41c8)
  Actor* mSubActor68;                         //0x68 — new(0x1C8), ctor 0x71000490fc (vtable [0x12fbc00]+0x10)
  Actor* mSubActor70;                         //0x70 — new(0x160), ctor 0x710005c7f0 (vtable [0x12fbdb0]+0x10)
  uint8_t mPad78[8];                          //0x78 — gap: ctor writes nothing here
  void* mConfig80;                            //0x80 — new(0x2C), ctor 0x71000585e8, block [0x12fb168]
  void* mConfig88;                            //0x88 — second 0x2C config object, same ctor
};
}  // namespace gear
