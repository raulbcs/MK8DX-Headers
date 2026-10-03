#pragma once

#include <cstdint>

/*
 * Ghost/replay recorder framework (reverse-engineered from the 400
 * binary, offsets verified in the disassembly).
 *
 * A channel is a ~0x288-byte binder object ("RecorderBinder") that
 * points at the live data source and is registered by name into a
 * registry. Channel names seen in rodata:
 *   RecorderKartUnit, RecorderKartChassis, RecorderKartChassisPackun,
 *   RecorderKartTire, RecorderKartTireMark, RecorderKartDriver,
 *   RecorderKartEvent, RecorderKartVehicleMove, RecorderKartCamera,
 *   RecorderKartVehicleDrift, RecorderKartVehicleDash,
 *   RecorderKartVehicle, RecorderModelMiiExpression, RecorderAudio,
 *   RecorderVoice, RecorderItem
 * plus float channels: p_drive_speed, p_drive_speed_ratio,
 *   p_gravity_vec, p_move_mtx, _dash_charge, p_collided_ground,
 *   p_collided_wall, p_ground_pos, p_air_counter, mGndAttr,
 *   mOnDirtRate, mbAntiGColSpin, p_collided_wall_object, at/up/back/
 *   dist/fovy.
 */

namespace recorder
{
    /*
     * Channel binder (FUN_71007aae24 ctor; size 0x288).
     * Anchors: FUN_71007ac0cc (addChannel) touches +0x1e8/+0x208 and
     * links at +0xe8/+0xf8; float-channel setup FUN_71003aef8c stores
     * the source at +0x00, flags at +0x1c0 and the owner at +0x278.
     */
    struct Binder
    {
        void* source;        // 0x000 — live data source (the recorded object/field)
        uint8_t pad08[0x1b8];
        uint32_t flags;      // 0x1c0 — e.g. 4
        uint8_t pad1c4[0x24];
        void* type;          // 0x1e8 — must equal the registry's +0x1e8 and the global type cell
        uint8_t pad1f0[0x18];
        const char* name;    // 0x208 — channel registration name (set by addChannel)
        uint8_t pad210[0x68];
        void* owner;         // 0x278 — owner/target object
    };

    /*
     * Registry (owner of the channel lists).
     * FUN_71007ac0cc walks: head at +0xe0, node link at +0xe8; second
     * list head at +0xf0, link at +0xf8. Type check against +0x1e8.
     */
    struct Registry
    {
        uint8_t pad00[0xe0];
        void* head_e0;       // 0x0e0 — first channel list head
        void* next_e8;       // 0x0e8 — node link
        void* head_f0;       // 0x0f0 — second list head
        void* next_f8;       // 0x0f8 — node link
        uint8_t pad100[0xe8];
        void* type;          // 0x1e8 — vtable/owner type checked on registration
    };

    // FUN_71007ac0cc — append a binder to both registry lists and stamp
    // its name. Signature: (Registry*, Binder*, const char* name).
    // Type gate: binder->type == registry->type == *(global mgr cell
    // 0x710130f7c8) (the mgr's vtable).
    void addChannel_71007ac0cc(Registry*, Binder*, const char* name);

    /*
     * Static singletons and global cells (bss):
     *   - 0x710130f7c8  global recorder manager pointer (type check in
     *                   addChannel reads its first word as the type)
     *   - 0x7101307768..0x71013077d0  Audio/Voice/Item channel instances
     *   - 0x71013078b8..0x71013078d8  five channel instances (Warp/KartBody/
     *                   KartPart/KartWheel/KartEffect writers)
     *   - 0x71013078e8..0x7101307958  per-kart channel instances (Chassis
     *                   through Vehicle), one cell per channel class
     * Each instance getter (getRecorderInstance_* in the decomp, one per
     * descriptor cluster) returns one cell.
     */
}  // namespace recorder
