#pragma once

#include "ActorVisitor.hpp"
#include "gear/ArgumentObj.hpp"

#include "agl/common/aglRenderInfo.h"
#include "sead/basis/seadNewWrapper.hpp"
#include "sead/hostio/seadHostIONode.hpp"

#include <prim/seadRuntimeTypeInfo.h>

namespace gear
{
    // Inherits sead::hostio::Node: the constructor (0x71000001b4) calls a
    // base ctor with its own vtable before writing Actor's, and the vtable
    // at .data:0x11ad018 is followed by a second sub-vtable at 0x11ad098 —
    // multiple inheritance, matching the sead hostio base.
    // sead::hostio::Node resolves to the MK8DX fork override
    // (sead/hostio/seadHostIONode.hpp — hostio disabled, size 0x38); the
    // open-ead Node does not match the 4.0.0 binary. Node supplies the
    // fields at 0x08..0x30.
    class Actor : public sead::hostio::Node, public SeadGameDeallocator
    {
        public:
            virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const*) const; //0x00
            virtual sead::RuntimeTypeInfo::Interface const* getRuntimeTypeInfo() const; //0x08
            virtual ~Actor(); //0x10, 0x18
            virtual void prepare(gear::ArgumentObj const*); //0x20
            virtual void enter() {} //0x28
            virtual void calc(); //0x30
            virtual void render(agl::lyr::RenderInfo const&) const {} //0x38
            virtual void exit() {} //0x40
            virtual bool isDirector() { return false; } //0x48
            virtual void accept(gear::ActorVisitor &); //0x50
            virtual void callbackInvokeEventID(int) {} //0x58
            virtual void prepareOuter(void const* arg0); //0x60
            virtual void enterOuter(); //0x68

            static sead::RuntimeTypeInfo::Interface const* getRuntimeTypeInfoStatic();
    };
}
