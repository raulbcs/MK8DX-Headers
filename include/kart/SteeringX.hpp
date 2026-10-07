#pragma once

#include <cstdint>

// SteeringX (size 0x106; unpadded tail-pads to 0x108) — steering/start-dash
// object. Owned by KartDirector (kart_vehicle_ptr +0xc0). PROVISIONAL: name
// has no MethodTree string.
// Baptism audit no MethodTree string; start-dash/countdown semantics from the KartDirector consumer; name-less.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

struct SteeringX
{
 uint8_t pad_000[0x28]; // 0x00 — unproven padding
 uint32_t mode; //0x28 — {0, -1}; writer BoostWriter28b
 uint32_t mode_value; //0x2c — ctor = -1; 0 by BoostErrata
 uint8_t pad_030[0xc]; // 0x30 — unproven padding
 uint8_t process_flag; //0x3c — gate of the 2008 post-call
 uint8_t pad_03d[6]; // 0x3d — unproven padding
 uint8_t parity; //0x43 — bit&1 via BoostBitSetter
 float boost_output; //0x44 — tail of 2514
 uint8_t pad_048[4]; // 0x48 — unproven padding
 float boost_output_1; //0x4c — x10
 uint8_t pad_050[0xc]; // 0x50 — unproven padding
 uint32_t countdown; //0x5c — countdown (mode-3 epilogue after GO)
 uint8_t pad_060[0x58]; // 0x60 — unproven padding
 uint64_t cache_lazyinit; //0xb8 — *(*(*(RS+0x190+idx*8)+0x238)+0xb8), idx=4
 uint64_t kart_vehicle_ptr; //0xc0 — KartDirector back-pointer
 uint64_t kart_vehicle_move; //0xc8 — KartVehicleMove (0x5f8B)
 float decay_per_frame; //0xd0 — x0.8 per frame in the f74c main path
 uint8_t pad_0d4[0x14]; // 0xd4 — unproven padding
 float charge; //0xe8 — start dash, target 1.5
 uint32_t counter; //0xec
 uint8_t pad_0f0[0x15]; // 0xf0 — unproven padding
 uint8_t sign_latch; //0x105
};
