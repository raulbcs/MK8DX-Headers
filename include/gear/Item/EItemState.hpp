#pragma once
#include <cstdint>

namespace gear
{
    // rodata name table 0xed7c2f (order = table order) — held-item actor states
    class EItemState
    {
        public:
            enum EItemState_ : int32_t
            {
                Wait,         //0x00
                Keep,         //0x01
                Throw,        //0x02
                Move,         //0x03
                Stand,        //0x04
                Equip_Hang,   //0x05
                Equip_Multi,  //0x06
                Use,          //0x07
                Attacked,     //0x08
                Vanish,       //0x09
                Break         //0x0A
            };

            EItemState_ mValue;

            const char* text_(int);

            EItemState() : mValue(EItemState_::Wait) {}
            EItemState(EItemState_ item) : mValue(item) {}
            EItemState(int32_t item) : mValue(static_cast<EItemState_>(item)) {}

            bool operator==(const EItemState& other) const {
                return mValue == other.mValue;
            }
            bool operator!=(const EItemState& other) const {
                return mValue != other.mValue;
            }
            bool operator<(const EItemState& other) const {
                return mValue < other.mValue;
            }

            ~EItemState() {}
    };
}
