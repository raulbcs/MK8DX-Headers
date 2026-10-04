#pragma once

#include <cstdint>

#include <math/seadVector.hpp>
#include <container/seadRingBuffer.h>

#include "ItemEvent.hpp"
#include "EItemType.hpp"


typedef unsigned char uchar;

namespace gear
{
    class ItemEventManager
    {
        public:
            virtual void test1();
            virtual void test2();
            uint8_t pad_04[0x18];
            uint32_t mCurrentBufferSize; //0x1C
            uint32_t mBufferMaximum; //0x20
            ItemEvent** m_itemEventBuffer; //0x24


            ItemEventManager();

            void pushEvent_SlotDrop(int);
            void pushEvent_SlotClear(int,uchar);
            void pushEvent_ObjDrop(int, gear::EItemType, sead::Vector3<float> const&, sead::Vector3<float> const&);

    };
}