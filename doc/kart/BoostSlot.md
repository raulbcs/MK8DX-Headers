# BoostSlot

- Class: `BoostSlot` (PROVISIONAL name), size 0xD0.
- Identity: no MethodTree string in the ELF; strings and method-tree registrations at 0x6327a8 cover only graphics/profiling and the `MapObjBase::calc*`-family entries; custom-RTTI predicates hold no name string. The name stays PROVISIONAL.
- Placement: object at KartVehicleMove+0x118 (pointer there). `operator new(0xD0)` in the KartVehicleMove ctor (0x71001815d4/0x71001815dc) → ctor 0x710017a0e4; stores reach 0xD0 (owner @0x8, flags @0x10, scalar @0x18).
- Consumers: the FUN_710017a* boost helpers and KartVehicleMove+0x118.
- Details: // details: doc/kart/BoostSlot.md

## Layout

| Offset | Field | Evidence |
|---|---|---|
| 0x00 | vptr | ctor stores `*0x12fd648 + 0x10` (0x710017a100..0x710017a114) |
| 0x08 | owner_kart_vehicle | owner (flags +0x1cc, counter +0x254, timer +0x298) |
| 0x10 | boost_active | — |
| 0x11 | impulse_flag | 0 if drift/state 2, else (owner+0x100 != 2) |
| 0x12 | boost_configured_latch | set in the 9534 prologue; cleared by the 94dc reset |
| 0x13 | boost_enabled | read by BoostEnabled_71000b3928 |
| 0x14 | boost_duration_counter (u32) | frames |
| 0x18 | boost_scalar (f32) | 1.0 default |
| 0x1c | counters_per_type[12] | accumulator per level (BoostLevelReader); ctor memset 0 (0x710017a14c..0x710017a170) |
| 0x4c | counters_per_type2[12] | second array; ctor memset 0 (same call) |
| 0x7c | current_boost_level | 0..10 |
| 0x80 | last_boost_type | — |
| 0x84 | prev_boost_type | — |
| 0x88 | last_boost_type_2 | — |
| 0x8c | profile_8c (f32) | ctor default 0.07f (0x3D8F5C29, 0x710017a174..0x710017a17c); overridden by owner-conditioned DAT loads 0xed5db0 / 0xed58ec / 0xed5a4c / else 0xed5b04 (0x710017a180..0x710017a1c0); x0.75 when owner+0x100==2 && owner+0xdc (0x710017a1c4..0x710017a1e0) |
| 0x90 | custom_duration_a (u32) | ctor 30 (0x710017a118/0x710017a130) |
| 0x94 | case3_profile_a (f32) | setters GliderB4WriterA..; ctor 0 (0x710017a154/0x710017a158) |
| 0x98 | case3_profile_b (f32) | ctor 0 (same store) |
| 0x9c | custom_duration_b (u32) | ctor 90 (0x710017a124/0x710017a15c); setter FUN_710017b184 (0x17b1a0) |
| 0xa0 | case4_profile_a (f32) | ctor 0 (0x710017a15c); setter FUN_710017b184 stores it (0x17b1d0); consumer FUN_710017a30c word-copies it (0x17a700) |
| 0xa4 | case4_profile_b (f32) | ctor 0 (0x710017a138); setter FUN_710017b184 (0x17b1d4); consumer multiplies by it (0x17a6f0) |
| 0xa8 | custom_duration_c (u32) | ctor 120 (0x710017a134/0x710017a138); setter FUN_710017b1e8 (0x17b204) |
| 0xac | case5_profile_a (f32) | ctor 0 (0x710017a15c `str xzr` 0xac..0xb3); setter FUN_710017b1e8 (0x17b234); consumer FUN_710017a30c word-copies it (0x17a71c) |
| 0xb0 | case5_profile_b (f32) | ctor 0 (same store); setter FUN_710017b1e8 (0x17b238); consumer multiplies by it (0x17a70c) |
| 0xb4 | custom_duration_d (u32) | ctor 20 (0x710017a13c/0x710017a140) |
| 0xb8 | case6_profile_a (f32) | out0 x +0xb8; ctor 0 (same store); setter FUN_710017b24c stores it |
| 0xbc | case6_profile_b (f32) | +0xc4: (b8-1)*0.5+1 pattern; ctor 0 (0x710017a168) |
| 0xc0 | case7_profile_a (f32) | ctor 1.2f (0x3F99999A, 0x710017a144..0x710017a148); consumer FUN_710017a30c reads it (0x17a6a0) |
| 0xc4 | machine_flag (u8) | ctor 0 (0x710017a16c); set to 1 when `[0x87fcd0()]+0x1a0 == 0x59` (0x710017a1e4..0x710017a1f8) |
| 0xc5 | pad_c5[3] | no ctor store (byte store only); no accessor evidence — unproven, never accessed in range 0xc5-0xc7 |
| 0xc8 | owned_c8 (void*) | owned 672-byte subobject: `operator new` at 0x710017a228, init 0x3aebe4, store 0x710017a244; ctor 0 otherwise (0x710017a164) |

## Course triggers — the 12 types

Course-trigger boost entry: FUN_710017af90(BoostSlot* x0, w1 = trigger type, w2 passed through), tail-called from the body calc at 189534. If w1 <= 0xb it indexes word table 0xf24460 (12 entries, data — NOT a code jump table) and tail-calls FUN_710017a870 with the resulting boost tier; w1 > 0xb falls back to tier 1 (same fallback as the trick-landing +0x213 variant).

| type | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| tier | 0x10000 | 0x2 | 0x200 | 0x4 | 0x8 | 0x10 | 0x100 | 0x80 | 0x40 | 0x8000 | 0x20 | 0x1 |
| id | default | t1 | antigrav | pad-w | pad-m | pad-s | trick | ? | ? | ? | dash | mushroom-class |

Related: gear/Course/TriggerRegistry.hpp.

## Construction / init order

1. `operator new(0xD0)` in the KartVehicleMove ctor (0x71001815d4/0x71001815dc).
2. Ctor 0x710017a0e4 (store sites in ascending address order):
   - vptr store `*0x12fd648 + 0x10` (0x710017a100..0x710017a114).
   - custom_duration_a = 30 (0x710017a118/0x710017a130).
   - custom_duration_b = 90 (0x710017a124/0x710017a15c).
   - custom_duration_c = 120 (0x710017a134/0x710017a138).
   - custom_duration_d = 20 (0x710017a13c/0x710017a140).
   - case7_profile_a = 1.2f (0x710017a144..0x710017a148).
   - memset 0 of counters_per_type and counters_per_type2 (0x710017a14c..0x710017a170).
   - case3_profile_a = 0 / case3_profile_b = 0 (0x710017a154/0x710017a158).
   - case4_profile_a = 0 (0x710017a15c); `str xzr` covering 0xac..0xb3 (case5 fields, 0x710017a15c).
   - owned_c8 = 0 (0x710017a164).
   - case6_profile_b = 0 (0x710017a168).
   - machine_flag = 0 (0x710017a16c).
   - profile_8c = 0.07f (0x710017a174..0x710017a17c).
   - owner-conditioned DAT overrides of profile_8c: 0xed5db0 / 0xed58ec / 0xed5a4c / else 0xed5b04 (0x710017a180..0x710017a1c0); x0.75 branch (0x710017a1c4..0x710017a1e0).
   - machine_flag = 1 when `[0x87fcd0()]+0x1a0 == 0x59` (0x710017a1e4..0x710017a1f8).
3. Owned subobject: `operator new` 0x710017a228 → init 0x3aebe4 → store at +0xc8 (0x710017a244).
