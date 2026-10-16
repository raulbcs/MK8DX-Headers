# KartParameter

## Identity

KartParameter — per-kart parameter object (0xb8 bytes; operator new(0xb8)
at v400 0x71001700b0 inside FUN_7100170090, stored at KartVehicle+0x78;
ctor = the stat calc FUN_710014b6d0). Initialized by the stat calc
(vehicle-class-driven weights); the kart then caches the wrapper
getters' results as bytes at KartVehicle+0xd8..0xdd
(FUN_7100170090). Name from the upstream field mirror
mKartParameter; layout below is the verified part only.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x00 — unproven padding
- 0x08 — target of the 45 wrapper accessors (KartUnit+0x08 points back to the owning KartVehicle)
- 0x10 — unproven padding
- 0x44 — f32 array region (wrapper idx arg, FUN_710014c734: fallback value for the stance calc); element count unproven
- 0xB0 — to 0xb8

## Construction / init order

No construction sequence is proven in this header's evidence.
