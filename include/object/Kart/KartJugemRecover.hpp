#pragma once
#include <cstdint>
#include <object/Race/LapRankChecker.hpp>

namespace object
{
    /*
     * Lakitu (Jugem) recover handler. Layout NOT yet
     * mapped against the 400 binary: no decompiled function touching this
     * object was identified, so no offset below is verified (including the
     * LapRankChecker pointer at +0x28, which came from the Wii U layout).
     * Field order kept as a placeholder.
     */
    class KartJugemRecover
	{
		public:
			uint8_t mPad00[0x28]; //0x00 — unverified
			LapRankChecker* mLapRankChecker; //0x28 — unverified
			uint8_t mPad30[0x170]; //0x30 — tail unmapped
	};
}  // namespace object
