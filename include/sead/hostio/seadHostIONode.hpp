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
                mPad28 = nullptr; // code (ctor), not padding
                mPad30 = nullptr; // code (ctor), not padding
            }

            void* mPad08; // real field (ptr), not padding
            void* mPad10; // real field (ptr), not padding
            void* mPad18; // real field (ptr), not padding
            void* mPad20; // real field (ptr), not padding
            void* mPad28; // real field (ptr), not padding
            void* mPad30; // real field (ptr), not padding
    };
}
