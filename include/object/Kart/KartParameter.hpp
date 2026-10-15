#pragma once

#include <cstdint>

namespace object {
struct KartUnit;  // kart/KartUnit.hpp

// KartParameter — per-kart parameter object (0xb8 bytes; operator new(0xb8)
// at v400 0x71001700b0 inside FUN_7100170090, stored at KartVehicle+0x78;
// ctor = the stat calc FUN_710014b6d0). Initialized by the stat calc
// (vehicle-class-driven weights); the kart then caches the wrapper
// getters' results as bytes at KartVehicle+0xd8..0xdd
// (FUN_7100170090). Name from the upstream field mirror
// mKartParameter; layout below is the verified part only.
struct KartParameter {
  uint8_t pad_000[8];     // 0x00 — unproven padding
  KartUnit* kart_unit;    //0x08 — target of the 45 wrapper accessors
                          // (KartUnit+0x08 points back to the owning KartVehicle)
  uint8_t pad_010[0x34];  // 0x10 — unproven padding
  uint8_t arrRegion_44[0x6C]; //0x44 — f32 array region (wrapper idx arg,
                          // FUN_710014c734: fallback value for the stance
                          // calc); element count unproven
  uint8_t pad_b0[0x8];    // 0xB0 — to 0xb8
};
}  // namespace object
