#pragma once

#include <cstdint>

#include "LapRankChecker.hpp"

#include <gear/Actor/Actor.hpp>


namespace object { class RaceCheckerBase; } // object/Race/RaceCheckerBase.hpp (mRaceState @0x38 over Actor)

namespace gear
{
    // RaceDirector walks an element array every frame (calc) and tears it
    // down (exit). The element count/array live at 0x38/0x40; the race
    // checkers and the lap rank checker are installed at 0x50/0x58.
    // Signatures below match the 4.0.0 binary. Actor's slots 0x00/0x08 were
    // corrected to return bool / const sead::RuntimeTypeInfo::Interface*
    // accordingly.
    class RaceDirector : public Actor
    {
        public:
            // Slots beyond Actor's vtable; each stage of enter/calc/exit
            // fires a pre/post hook pair. slot70/78/A0/A8 are still unnamed.
            virtual void slot70();               //0x70 — unknown
            virtual void slot78();               //0x78 — unknown
            virtual void onEnterStart();         //0x80 — enter() announces here before walking the child array
            virtual void onEnterEnd();           //0x88 — enter() tail call
            virtual void onCalcStart();          //0x90 — calc() opens with this before the child walk
            virtual void onCalcEnd();            //0x98 — calc() tail call
            virtual void slotA0();               //0xa0 — unknown
            virtual void slotA8();               //0xa8 — unknown
            virtual void onExitStart();          //0xb0 — exit() opens with this before the child walk
            virtual void onExitEnd();            //0xb8 — exit() tail call

            bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const*) const; //0x00
            sead::RuntimeTypeInfo::Interface const* getRuntimeTypeInfo() const asm("RaceDirector::getRuntimeTypeInfo"); //0x08
            void enter() asm("RaceDirector::enter"); //0x28 — RaceDirector::enter (Actor override)
            void calc() asm("RaceDirector::calc");   //0x30 — RaceDirector::calc
            void exit() asm("RaceDirector::exit");   //0x40 — RaceDirector::exit
            bool isDirector() asm("RaceDirector::isDirector"); //0x48 — RaceDirector::isDirector
            void enterOuter() asm("RaceDirector::enterOuter"); //0x68 — RaceDirector::enterOuter
            ~RaceDirector(); //0x10/0x18 — D1/D0 carry the MethodTree labels via linker aliases in the .cpp

            uint32_t mActorCount; //0x38 — Actor element count for calc/exit/enter
            Actor** mActors;     //0x40 — Actor array walked by calc/exit/enter
            char mPad48[0x8];    //0x48
            object::RaceCheckerBase* mRaceCheckerBase; //0x50
            gear::LapRankChecker* mLapRankChecker;     //0x58
            char mPad60[0x20];   //0x60
            void* mUnknown80;    //0x80 — deleted by the destructor
            void* mUnknown88;    //0x88 — deleted by the destructor
            char mPad90[0x90];   //0x90
    };
}
