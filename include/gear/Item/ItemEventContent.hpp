#pragma once

#include <cstdint>

namespace gear
{
    struct ItemEventContent
    {
        uint8_t mPad00; //0x00 — unproven padding
        uint8_t mPad01; //0x01 — unproven padding
        uint16_t mItemSerial; //0x02
        // Unproven — Switch ctor not identified (no RTTI, stripped binary);
        // extent fixed by sizeof(ItemEventContent) = 0x100 (32-bit reference
        // layout preserved).
        char mPad04[0xFC]; // unproven - extent from sizeof(ItemEventContent) = 0x100 (32-bit reference)
    };
}