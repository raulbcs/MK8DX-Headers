#pragma once
#include <cstdint>

namespace gear
{
    // rodata name table 0xf0b2c6 (order = table order) — course surface /
    // collision material types (ROAD..ZONE)
    class ESurfaceType
    {
        public:
            enum ESurfaceType_ : int32_t
            {
                ROAD,     //0x00
                ROAD2,    //0x01
                ROAD3,    //0x02
                ROAD4,    //0x03
                SAND,     //0x04
                LDIRT,    //0x05
                DIRT,     //0x06
                DIRT2,    //0x07
                HDIRT,    //0x08
                ICE,      //0x09
                DASH,     //0x0A
                GRAVITY,  //0x0B
                GLIDE,    //0x0C
                PULL,     //0x0D
                BELT,     //0x0E
                ITROAD,   //0x0F
                RESQ,     //0x10
                WALL,     //0x11
                WALL2,    //0x12
                WALL3,    //0x13
                LWALL,    //0x14
                ITWALL,   //0x15
                BWALL,    //0x16
                OUTF,     //0x17
                HPWALL,   //0x18
                ROAD5,    //0x19
                DIRT3,    //0x1A
                SOUND,    //0x1B
                VALLEY,   //0x1C
                JUMPHP,   //0x1D
                ZONE2,    //0x1E
                ZONE      //0x1F
            };

            ESurfaceType_ mValue;

            const char* text_(int);

            ESurfaceType() : mValue(ESurfaceType_::ROAD) {}
            ESurfaceType(ESurfaceType_ item) : mValue(item) {}
            ESurfaceType(int32_t item) : mValue(static_cast<ESurfaceType_>(item)) {}

            bool operator==(const ESurfaceType& other) const {
                return mValue == other.mValue;
            }
            bool operator!=(const ESurfaceType& other) const {
                return mValue != other.mValue;
            }
            bool operator<(const ESurfaceType& other) const {
                return mValue < other.mValue;
            }

            ~ESurfaceType() {}
    };
}
