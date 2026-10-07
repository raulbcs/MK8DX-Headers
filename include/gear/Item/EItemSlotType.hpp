#pragma once
#include <cstdint>

namespace gear
{
    // rodata name table 0xee51e1 (order = table order)
    class EItemSlotType
    {
        public:
            enum EItemSlotType_ : int32_t
            {
                Invalid = -1,
                All,          //0x00
                KouraOnly,    //0x01
                BananaOnly,   //0x02
                KinokoOnly,   //0x03
                BomOnly,      //0x04
                NoItem,       //0x05
                NoItemCoin,   //0x06
                Dynamic,      //0x07
                Stoic,        //0x08
                ItemSwitch    //0x09
            };

            EItemSlotType_ mValue;

            const char* text_(int);

            EItemSlotType() : mValue(EItemSlotType_::Invalid) {}
            EItemSlotType(EItemSlotType_ item) : mValue(item) {}
            EItemSlotType(int32_t item) : mValue(static_cast<EItemSlotType_>(item)) {}

            bool operator==(const EItemSlotType& other) const {
                return mValue == other.mValue;
            }
            bool operator!=(const EItemSlotType& other) const {
                return mValue != other.mValue;
            }
            bool operator<(const EItemSlotType& other) const {
                return mValue < other.mValue;
            }

            ~EItemSlotType() {}
    };
}
