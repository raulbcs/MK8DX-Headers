#pragma once
#include <cstdint>

namespace gear
{
    // rodata name table 0xf0b83e (order = table order)
    class ESceneID
    {
        public:
            enum ESceneID_ : int32_t
            {
                Invalid = -1,
                Boot,          //0x00
                Root,          //0x01
                Menu,          //0x02
                Race,          //0x03
                Select,        //0x04
                Award,         //0x05
                Theater,       //0x06
                TheaterMenu,   //0x07
                Ending         //0x08
            };

            ESceneID_ mValue;

            const char* text_(int);

            ESceneID() : mValue(ESceneID_::Invalid) {}
            ESceneID(ESceneID_ item) : mValue(item) {}
            ESceneID(int32_t item) : mValue(static_cast<ESceneID_>(item)) {}

            bool operator==(const ESceneID& other) const {
                return mValue == other.mValue;
            }
            bool operator!=(const ESceneID& other) const {
                return mValue != other.mValue;
            }
            bool operator<(const ESceneID& other) const {
                return mValue < other.mValue;
            }

            ~ESceneID() {}
    };
}
