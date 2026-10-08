#pragma once

#include <cstdint>

// BoostSlot (size 0x258) — kart boost slot. PROVISIONAL: name has no
// MethodTree string. Embedded in KartVehicleMove at +0x118 (pointer there).
// Baptism audit: no MethodTree string; consumers are the FUN_710017a* boost helpers and KartVehicleMove+0x118; behavior-rich, name-less.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

struct BoostSlot {
  uint8_t pad_00[8];                // 0x00 — unproven padding
  uint64_t owner_kart_vehicle;      //0x08 — owner (flags +0x1cc, counter +0x254, timer +0x298)
  uint8_t boost_active;             //0x10
  uint8_t impulse_flag;             //0x11 — 0 if drift/state 2, else (owner+0x100 != 2)
  uint8_t boost_configured_latch;   //0x12 — set in the 9534 prologue; cleared by the 94dc reset
  uint8_t boost_enabled;            //0x13 — read by BoostEnabled_71000b3928
  uint32_t boost_duration_counter;  //0x14 — frames
  float boost_scalar;               //0x18 — 1.0 default
  uint32_t counters_per_type[12];   //0x1c — accumulator per level (BoostLevelReader)
  uint32_t counters_per_type2[12];  //0x4c — second array
  uint32_t current_boost_level;     //0x7c — 0..10
  uint32_t last_boost_type;         //0x80
  uint32_t prev_boost_type;         //0x84
  uint32_t last_boost_type_2;       //0x88
  uint8_t pad_8c[4];                // 0x8c — unproven padding
  uint32_t custom_duration_a;       //0x90 — custom duration types 4/8/16/256
  float case3_profile_a;            //0x94 — setters GliderB4WriterA..
  float case3_profile_b;            //0x98
  uint32_t custom_duration_b;       //0x9c
  uint8_t pad_a0[8];                // 0xa0 — unproven padding
  uint32_t custom_duration_c;       //0xa8
  uint8_t pad_ac[8];                // 0xac — unproven padding
  float case6_profile_a;            //0xb4 — out0 x +0xb4
  float case6_profile_b;            //0xb8 — +0xc4: (b8-1)*0.5+1
  uint32_t custom_duration_d;       //0xbc
  uint8_t pad_c0[0x194];            // 0xc0 — unproven padding
  uint32_t counter_mirror;          //0x254 — mirror of the real counter (KartVehicle+0x254)
};
