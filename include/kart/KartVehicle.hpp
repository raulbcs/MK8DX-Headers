#pragma once

#include <cstdint>

struct KartVehicleMove; // kart/KartVehicleMove.hpp

// KartVehicle (partial layout 0x2a8 + wheel block; real object 0x14b8B) — the
// player's vehicle. Owner of KartVehicleMove (+0x28), StatBlock (+0x90),
// flags +0x1cc. PROVISIONAL: name has no MethodTree string.
struct KartVehicle
{
    uint8_t pad_000[0x18]; // 0x00
    uint64_t input_provider_a; //0x18 — providers fill the +0x170 buffer per frame
    uint64_t input_provider_b; //0x20
    KartVehicleMove* kart_vehicle_move; //0x28 — move model (0x5f8B)
    void* effect; //0x30 — boost manager (counter +0x254)
    uint8_t pad_038[0x50]; // 0x38
    void* recorder; //0x88 — RecorderKartUnit
    void* stat_block; //0x90 — StatBlock (0x1d8)
    uint8_t pad_098[8]; // 0x98
    uint64_t steering_input_controller; //0xa0 — SteeringX (0x120B)
    uint8_t player_idx; //0xa8
    uint8_t pad_0a9[0x29]; // 0xa9
    uint8_t level_mode; //0xd2 — manual level mode (KartSubSet1)
    uint8_t level_mode_1; //0xd3
    uint8_t pad_0d4[0xd]; // 0xd4
    uint8_t eval_gate; //0xe1 — race_phase >= 6 -> 1 (RacePhaseEval)
    uint8_t init_copy_a; //0xe2 — init copies +0xe3 -> +0xe2 when +0xd2 == 0
    uint8_t init_copy_b; //0xe3 — read in mode 1
    uint8_t pad_0e4[3]; // 0xe4
    uint8_t level_gate; //0xe7 — KartSubSet1: zeroes (set) or copies +0xe8 (clear)
    uint8_t level_threshold; //0xe8
    uint8_t pad_0e9[6]; // 0xe9
    uint8_t buffer_gate; //0xef — gate of the buffer bit0 in mode 1
    uint8_t pad_0f0[4]; // 0xf0
    float boost_factor_a; //0xf4 — tail of 2514
    uint8_t pad_0f8[0x18]; // 0xf8
    float boost_state_ptr; //0x110 — WARNING: read as a POINTER by 2008 (confusable with KVM+0x110)
    float boost_factor_b; //0x114 — x10 at 0x4c
    uint8_t pad_118[0x1c]; // 0x118
    uint32_t boost_manager_field; //0x134 — propagated to the effect at boost start
    uint8_t pad_138[0x38]; // 0x138
    uint8_t input_buffer; //0x170 — bit0 = A/ZL; cleared per frame
    uint8_t pad_171[0x23]; // 0x171
    uint8_t boost_request; //0x194
    uint8_t pad_195[0x37]; // 0x195
    uint32_t drift_boost_flags; //0x1cc — bits 0xb/0xf/0x11/0x12/0x14/0x15/0x18/0x19
    uint32_t mode_counter; //0x1d0 — ++ per frame after the start dash evaluation
    uint8_t pad_1d4[8]; // 0x1d4
    float anti_gravity_rate; //0x1dc — source of the recorder
    float start_dash_charge; //0x1e0 — 0.985*c + 0.017, clamp 1.0
    uint32_t drift_counter; //0x1e4 — decremented by DriftCounterDecrement
    uint32_t drift_extend_counter; //0x1e8 — DriftAnd180: < 1 resets; > 0x1bd fails
    uint8_t pad_1ec[0x30]; // 0x1ec
    uint32_t drift_active_counter; //0x21c — mode 1 of 2ab0
    uint32_t duration_counter_a; //0x220
    uint32_t boost_dir; //0x224 — boost direction
    uint32_t duration_counter_c; //0x228
    uint8_t pad_22c[4]; // 0x22c
    uint32_t drift_long_timer_a; //0x230 — 90 frames -> boost 0x40
    uint32_t drift_long_timer_b; //0x234
    uint8_t pad_238[0x10]; // 0x238
    uint32_t boost_drain_a; //0x248 — drain counters
    uint32_t boost_drain_b; //0x24c
    uint8_t pad_250[4]; // 0x250
    uint32_t boost_counter; //0x254 — real counter of the boost manager
    uint8_t pad_258[0x20]; // 0x258
    uint8_t direction_flags; //0x278 — BoostEnvelope sets it with +0x253
    uint8_t pad_279[0x1f]; // 0x279
    uint32_t boost_timer; //0x298 — visible window (90*dur+1, default 91)
    uint32_t start_dash_mode; //0x29c — 0 charging, 1 post-evaluation, 2 init
    uint8_t pad_2a0[4]; // 0x2a0
    float start_dash_ramp; //0x2a4 — mode 1: += 0.1 clamp 1.0
    uint8_t pad_2a8[0x9e4]; // 0x2a8
    uint32_t wheel_flag_c8c; //0xc8c — ==1 selects the PTR_DAT_71012f5148 table
    float wheel_f_c90; //0xc90
    uint8_t pad_c94[0x60]; // 0xc94
    float wheel_stance_base; //0xcf4 — wheel stance base (deg)
    uint8_t pad_cf8[0x4c]; // 0xcf8
    float wheel_stats[16]; //0xd44..0xd80 — per-wheel stats (getters d44..d80)
    float wheel_vecs_a[12][3]; //0xd84 — vec3 idx < 0xc (WheelVelocityRotate)
    float wheel_vecs_b[6][3]; //0xe14 — vec3 idx < 6
    uint8_t pad_e5c[0x88]; // 0xe5c
    float wheel_scale_ee4; //0xee4 — default 1.0
    float wheel_f_ee8; //0xee8 — default 1.0
    uint8_t pad_eec[0x24]; // 0xeec
    float wheel_vecs_c[4][3]; //0xf10 — vec3 idx < 4
    float wheel_vecs_d[4][3]; //0xf40 — vec3 idx < 4
    uint8_t pad_f70[0x548]; // 0xf70
};
