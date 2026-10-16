#pragma once

#include <cstdint>

// BoostSlot (size 0xD0) — kart boost slot; PROVISIONAL name (no MethodTree
// string; registrations at 0x6327a8 hold none). Object at KartVehicleMove+0x118
// (new 0xD0 at 0x71001815d4/0x71001815dc). Ctor 0x710017a0e4.
// Details: doc/kart/BoostSlot.md

struct BoostSlot {
  uint64_t vptr;                    //0x00 — *0x12fd648 + 0x10 (0x710017a100..0x710017a114)
  uint64_t owner_kart_vehicle;      //0x08 — owner (flags +0x1cc, counter +0x254, timer +0x298)
  uint8_t boost_active;             //0x10
  uint8_t impulse_flag;             //0x11 — 0 if drift/state 2, else (owner+0x100 != 2)
  uint8_t boost_configured_latch;   //0x12 — set in the 9534 prologue; cleared by the 94dc reset
  uint8_t boost_enabled;            //0x13 — read by BoostEnabled_71000b3928
  uint32_t boost_duration_counter;  //0x14 — frames
  float boost_scalar;               //0x18 — 1.0 default
  uint32_t counters_per_type[12];   //0x1c — per-level accumulator (BoostLevelReader); ctor memset 0 (0x710017a14c..0x710017a170)
  uint32_t counters_per_type2[12];  //0x4c — second array; ctor memset 0 (same call)
  uint32_t current_boost_level;     //0x7c — 0..10
  uint32_t last_boost_type;         //0x80
  uint32_t prev_boost_type;         //0x84
  uint32_t last_boost_type_2;       //0x88
  float profile_8c;                 //0x8c — ctor 0.07f (0x710017a174..0x710017a17c); DAT overrides 0xed5db0/0xed58ec/0xed5a4c/0xed5b04 (0x710017a180..0x710017a1c0); x0.75 case (0x710017a1c4..0x710017a1e0)
  uint32_t custom_duration_a;       //0x90 — ctor 30 (0x710017a118/0x710017a130)
  float case3_profile_a;            //0x94 — setters GliderB4WriterA..; ctor 0 (0x710017a154/0x710017a158)
  float case3_profile_b;            //0x98 — ctor 0 (same store)
  uint32_t custom_duration_b;       //0x9c — ctor 90 (0x710017a124/0x710017a15c); setter FUN_710017b184 (0x17b1a0)
  float case4_profile_a;            //0xa0 — ctor 0 (0x710017a15c); setter FUN_710017b184 (0x17b1d0); consumer 0x17a700
  float case4_profile_b;            //0xa4 — ctor 0 (0x710017a138); setter FUN_710017b184 (0x17b1d4); consumer 0x17a6f0
  uint32_t custom_duration_c;       //0xa8 — ctor 120 (0x710017a134/0x710017a138); setter FUN_710017b1e8 (0x17b204)
  float case5_profile_a;            //0xac — ctor 0 (str xzr 0xac..0xb3, 0x710017a15c); setter FUN_710017b1e8 (0x17b234); consumer 0x17a71c
  float case5_profile_b;            //0xb0 — ctor 0 (same store); setter FUN_710017b1e8 (0x17b238); consumer 0x17a70c
  uint32_t custom_duration_d;       //0xb4 — ctor 20 (0x710017a13c/0x710017a140)
  float case6_profile_a;            //0xb8 — out0 x +0xb8; ctor 0 (same store); setter FUN_710017b24c
  float case6_profile_b;            //0xbc — +0xc4: (b8-1)*0.5+1 pattern; ctor 0 (0x710017a168)
  float case7_profile_a;            //0xc0 — ctor 1.2f (0x710017a144..0x710017a148); consumer 0x17a6a0
  uint8_t machine_flag;             //0xc4 — ctor 0 (0x710017a16c); set 1 when [0x87fcd0()]+0x1a0 == 0x59 (0x710017a1e4..0x710017a1f8)
  uint8_t pad_c5[3];                //0xc5 - 0xc7 — no ctor store; no accessor evidence (unproven)
  void* owned_c8;                   //0xc8 — owned 672-byte subobject: new 0x710017a228, init 0x3aebe4, store 0x710017a244; ctor 0 otherwise (0x710017a164)
};

// Course-trigger boost entry: FUN_710017af90 (w1 = trigger type), tail-called
// from the body calc at 189534; w1 <= 0xb indexes word table 0xf24460 (data)
// and tail-calls FUN_710017a870; w1 > 0xb falls back to tier 1.
// Details: doc/kart/BoostSlot.md
