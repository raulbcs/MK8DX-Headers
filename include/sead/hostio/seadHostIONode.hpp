#pragma once

// sead fork override (MK8DX 4.0.0): hostio::Node with hostio disabled.
// Node vtable: [checkDerivedRuntimeTypeInfo, getRuntimeTypeInfo, ~Node, deleting ~Node].
// Own fields at 0x28/0x30, size 0x38.

#include "prim/seadRuntimeTypeInfo.h"

namespace sead::hostio
{
    class Node
    {
        public:
            virtual bool checkDerivedRuntimeTypeInfo(const RuntimeTypeInfo::Interface* typeInfo) const;
            virtual const RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;
            virtual ~Node()
            {
                mPad28 = nullptr;
                mPad30 = nullptr;
            }

            void* mPad08;
            void* mPad10;
            void* mPad18;
            void* mPad20;
            void* mPad28;
            void* mPad30;
    };
}
