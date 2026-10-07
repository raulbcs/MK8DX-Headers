#pragma once

#include <cstdint>

/*
* Layout reference (32-bit era; offsets re-derived for the 64-bit binary):
* https://github.com/EpicUsername12/mk8-cafeloader-ctcode/blob/2dd1c7d0ef0c547d7df51aaf5e32b3d9a1f764f1/include/mk8/enl/Peer.h
*/

namespace enl {

    class UniqueID
    {
    public:
        uint64_t mStationId; // 0x00
        uint8_t mPlayerId; // 0x08
        uint8_t mPad09; // 0x09 — unproven padding
        uint8_t mPad0A[0x6]; // 0x0A — unproven padding

    public:
        inline bool isStationValid() {
            return this->mStationId != 253;
        }

        inline bool isFullyEqual(const UniqueID& rhs) const {
            return (this->mStationId == rhs.mStationId) && (this->mPlayerId == rhs.mPlayerId) && (this->mPad09 == rhs.mPad09); // code, not padding: mPad09 is a real compared field
        }

        friend bool operator==(const UniqueID& lhs, const UniqueID& rhs) {
            return (lhs.mStationId == rhs.mStationId) && (lhs.mPlayerId == rhs.mPlayerId) && (lhs.mPad09 == rhs.mPad09); // code, not padding: mPad09 is a real compared field
        }

        UniqueID() = default;
    };
}