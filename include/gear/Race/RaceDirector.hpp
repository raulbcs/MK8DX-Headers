#pragma once

#include <cstdint>

#include "LapRankChecker.hpp"

#include <gear/Actor/Actor.hpp>

namespace object {
class RaceCheckerBase;
}  // namespace object

namespace gear {
// RaceDirector walks an element array every frame (calc) and tears it
// down (exit). The element count/array live at 0x38/0x40; the race
// checkers and the lap rank checker are installed at 0x50/0x58.
// Signatures below match the 4.0.0 binary. Actor's slots 0x00/0x08 were
// corrected to return bool / const sead::RuntimeTypeInfo::Interface*
// accordingly.
class RaceDirector : public Actor {
 public:
  // Vtable .data 0x11b2f28 (GOT cell 0x12fbc58); concrete size 0x90 — the
  // 0x6f244 factory news[] it directly.
  // Slots beyond Actor's vtable; each stage of enter/calc/exit
  // fires a pre/post hook pair. slot70/78/A0/A8 are still unnamed.
  virtual void slot70();        //0x70 — unknown
  virtual void slot78();        //0x78 — unknown
  virtual void onEnterStart();  //0x80 — enter() announces here before walking the child array
  virtual void onEnterEnd();    //0x88 — enter() tail call
  virtual void onCalcStart();   //0x90 — calc() opens with this before the child walk
  virtual void onCalcEnd();     //0x98 — calc() tail call
  virtual void slotA0();        //0xa0 — unknown
  virtual void slotA8();        //0xa8 — unknown
  virtual void onExitStart();   //0xb0 — exit() opens with this before the child walk
  virtual void onExitEnd();     //0xb8 — exit() tail call

  bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const*) const;                             //0x00
  sead::RuntimeTypeInfo::Interface const* getRuntimeTypeInfo() const asm("RaceDirector::getRuntimeTypeInfo");  //0x08
  void enter() asm("RaceDirector::enter");                                                                     //0x28 — RaceDirector::enter (Actor override)
  void calc() asm("RaceDirector::calc");                                                                       //0x30 — RaceDirector::calc
  void exit() asm("RaceDirector::exit");                                                                       //0x40 — RaceDirector::exit
  bool isDirector() asm("RaceDirector::isDirector");                                                           //0x48 — RaceDirector::isDirector
  void enterOuter() asm("RaceDirector::enterOuter");                                                           //0x68 — RaceDirector::enterOuter
  ~RaceDirector();                                                                                             //0x10/0x18 — D1/D0 carry the MethodTree labels via linker aliases in the .cpp

  uint32_t mActorCount;                       //0x38 — Actor element count for calc/exit/enter
                                              // (ctor: 3 after the child array allocation succeeds)
  uint8_t mPad3C[0x4];                        // 0x3C — unproven gap
  Actor** mActors;                            //0x40 — Actor array walked by calc/exit/enter
                                              // (ctor allocs 0x18 = 3 slots, 0x4d818-0x4d830)
  uint8_t mPad48[4];                          //0x48 — unproven padding
  uint32_t mInsertCursor4C;                   //0x4C — child insertion cursor: ctor registers
                                              // each created child at mActors[cursor] and increments (0x4d8e8-0x4d9b8)
  object::RaceCheckerBase* mRaceCheckerBase;  //0x50 — ctor arg x1 (0x4d808)
  gear::LapRankChecker* mLapRankChecker;      //0x58
  Actor* mSubActor60;                         //0x60 — new(0xB0), ctor 0x7100066448
                                              // (gear/Race/RaceDirectorSubActor60.hpp, vtable 0x11b41c8),
                                              // registered as child
  Actor* mSubActor68;                         //0x68 — new(0x1C8), ctor 0x71000490fc (vtable
                                              // [0x12fbc00]+0x10; u16 +0x40 and byte +0x42 zeroed), registered
  Actor* mSubActor70;                         //0x70 — new(0x160), ctor 0x710005c7f0 (vtable
                                              // [0x12fbdb0]+0x10; bytes +0x41/+0x42 zeroed), registered
  uint8_t mPad78[8];                          //0x78 — gap: ctor writes nothing here
  void* mConfig80;                            //0x80 — new(0x2C), ctor 0x71000585e8: five u32s +
                                              // flag byte copied from the default block [0x12fb168]
  void* mConfig88;                            //0x88 — second 0x2C config object, same ctor
                                              // Class ends at 0x90: derived RaceDirectorVt2 is 0xA0 with fields
                                              // only at 0x90-0x9F (allocation proof 0x710006f108).
};
}  // namespace gear
