#pragma once

// Identity unresolved. The only KartUnit name in the binary is the
// "RecorderKartUnit" string, reached from KartVehicle+0x88 (the recorder
// pointer) — so KartUnit is recorder/replay-related, NOT the per-driver
// object in KartUnitHolder (that one is kart::KartVehicle, verified via
// FUN_710016dab0 / FUN_710016cabc and the reset helpers at
// 0x173bfc / 0x173c40). Layout: unmapped.

namespace object
{
    class KartUnit;  // TODO: identify and map (likely recorder-related)
}  // namespace object
