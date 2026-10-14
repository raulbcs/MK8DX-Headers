#pragma once

#include <cstdint>

namespace object {
// Course/mode registration and per-player render/input binding of the
// course holder ("this" below; mode-player record stride 0x3e0 at
// this->[0xf8], count this->[0xf0]; per-player arm array stride 0x3d68
// rooted at this->[0x248]+0x10 with count at this->[0x248]+0x8, base
// offset +0x3ce0). Docblocks only.

// FUN_71006c0258 (0x71006c0258, extent 0x364) — register a player into the
// mode-specific course systems (called by FUN_7100724984). Args:
// (this, mode w1, player x2 with name at [player+0x18], u8 id at
// [player+0x20]). rec = [this+0xf8] + min(u32[this+0xf0], id)*0x3e0.
//  - mode 0: when [rec+0xa] bit0 clear — FUN_7100aeceec([this+0x5d38],
//    name, [rec+8]); u16 [player+0x36] |= 2; [rec+0xa] |= 1.
//  - mode 1 (physics/kart binding): mgr = [this+0x4218]; base = slot(mgr,
//    id)+0x3ce0; FUN_71006e8688(this+0x1dd8, name, rec, 0);
//    [player+0xc8] = base + 0x3b30; when slot([this+0x2250 family], id)
//    has [s2+0x548]: p = s2 + 0x9a8, [rec+0x20] = [rec+0x28] = p,
//    [player+0x48] = [player+0x50] = p; FUN_71006dc0d0(this+0x3cd0, name,
//    rec, mgr, this+0x1dd8); callback vt+0x38(kind 5) when [this+0x5cf8];
//    FUN_7100724984(base, name, id, [this+0x5148] when
//    FUN_71006df768(this+0x4d00) bit0, else 0); FUN_7100723f80(base, name,
//    1); FUN_71006b1370(player, [base+0xc]); tail
//    FUN_710062bd1c(player+0x1c0, name).
//  - mode 2 (stat-snapshot setup): base as in mode 1;
//    FUN_71006b21b8(rec, kind, src) with (0x10, base+0x3b30),
//    (4, base+0x35c0), (0x16, base+0x3790), (5, base+0x3220),
//    (7, base+0x3960); FUN_7100724f2c(base, name, ...); callbacks
//    vt+0x38(kind 1 / 7); FUN_71006c4ff4(this+0x3fd0, name, rec, 1) /
//    FUN_71006c50fc(this+0x3fd0, name, rec); FUN_7100724e24 /
//    FUN_7100723f80(base, name, ...).

// FUN_71006c4c4c (0x71006c4c4c, extent 0x208) — per-player render-target
// binding (called by FUN_7100724984). Args: (this, ctx, desc x2, extra x3);
// pl = byte [desc+0x8]; mgr = [this+0x248];
// base = [mgr+0x10] + min(u32[mgr+8], pl)*0x3d68 + 0x3ce0.
//  1. FUN_710072473c(base, [this+8] + 0x1c10 index [desc+0x8], pl).
//  2. FUN_710063fb78(base + 0x990, ctx).
//  3. When the [this+8 base+0x1c10+8] bit0 is clear:
//     RenderBufferContext NLD(ctx, ([this+0xd18] & 0x10) ? 0x14 : 9, 1).
//  4. [desc+0xb8] = slot + 0x1108 (same clamped arm array).
//  5. FUN_7100709824(mgr, ctx, pl, 0x1800, 0, 1, 0).
//  6. [desc+0xc0] = slot((([this+0xd18] >> 5) & 1) * 0x1c8 into the
//     +0x1108 array) + (([this+0xd18] & 0x40) ? +0x2020 : +0x1108).
//  7. [this+8 base+0x1c10+8] bit0 set -> FUN_71006df768(extra);
//     x3b = (result & 1) ? [extra+0x448] : 0; FUN_7100724984(base, ctx,
//     pl, x3b); FUN_7100723f80(base, ctx, 0).
//  8. w22 = [base+0x2664]; when *(cell 0x12fce58)->[+0x35] bit set and
//     [desc+0x389] bit1: FUN_710070347c(ctx, [desc+0x398], 1).
//  9. FUN_71006cd5a8(desc, ctx, mgr, 17, 2, w22, 0) then (18, 2, w22, 0)
//     (tail).

// FUN_71006a784c (0x71006a784c, extent 0x228, gap-split) — apply slot
// input to a player (called by FUN_71006a5f88 / FUN_71006a5d6c). Args:
// (this, playerIdx w1, ctx x2). rec = [this+0x10]; cnt = [this+8]; sel =
// (cnt > idx) ? rec + idx*0x18 : rec. [this+0xb0] = ctx;
// tailDst = [ctx+0x100].
//  - Path A (u16 [sel+0x10] == 1): vehIdx = u16 [sel+0x8];
//    FUN_71006a5fd4(this, idx, vehIdx, ctx); veh = [this+0x40] +
//    ([this+0x38] > vehIdx ? vehIdx*0xa8 : 0); FUN_7100a7763c(veh);
//    vt slot 0 of [this+0x88](this, ctx, ...) when set; tail
//    FUN_7100a776d0(veh, tailDst).
//  - Path B (multi): u16 [this+0x22] = [ctx+0x50]; FUN_7100a78e7c(
//    this+0x18); n = min(u32[ctx], u16[sel+0x10]); per i: vehIdx =
//    u16 [sel+0x8 + i*2], [this+0xae] = vehIdx, FUN_71006a5fd4(...);
//    veh = clamped slot; [veh+0xa0] bit0 -> FUN_7100a78ea0(this+0x18,
//    veh+0x18, f32 [veh+0x10]) else record i as failed; vt slot 1 of
//    [this+0x88]; FUN_7100a78f50(this+0x18, tailDst); per failed idx:
//    FUN_7100a7763c(veh+0x18) then FUN_7100a776d0(veh+0x18, tailDst).

// FUN_710065e7b0 (0x710065e7b0, extent 0x27c, gap-split) — begin a
// streaming batch request (called by FUN_71006c5598). Args: (this, param
// x1, ctx x2). Gate: byte [this+0x9d0] != 0. Node list at this+0x1d0
// (head [this+0x1d8], count s32 [this+0x1e0]) or the single target
// [this+0xa30] gated by [this+0xaf8] + FUN_7100692c68(this+0x988) bit0.
// State writes: [this+0x568] = ctx; [this+0x73c..0x73f] = {2, 3, 4,
// byte [this+0x980]}; u16 [this+0x734] = 0x101; [this+0x736] = 1;
// u16 [this+0x737] = 0x707; [this+0x739] = 7; [this+0x578] =
// u16 [ctx+0xa8]; [this+0x984] = 0; flag u32 [this+0x740] |= 1|2|4 and
// final value = (old & ~5) | 2. Per target: vt slot 0x58/8(target, param,
// this+0x568); message via FUN_710065ed6c([this+0xad8], ...) /
// [t+0xa8]; FUN_7100073798(..., str 0xef9ad2, 1, ...). When [this+0x570]:
// FUN_71006454ac([this+0x570], this+0x580); [this+0x734] = [this+0x735] =
// byte [this+0xa28]; [this+0x736] = 1; [this+0x740] = (old & ~5) | 4.

// FUN_71006a1c34 (0x71006a1c34, extent 0x2bc) — per-core listener drain
// (tail-called from FUN_71006a1bc4). Args: (this, flags w1, arg x2).
// Layout: +0xc8 primary target, +0xd0 secondary target, +0x40 handler
// count, +0x48 handler table (ptr per entry), +0x98 flag byte.
//  1. [+0xc8] != 0 -> vt+0x00(it, this); flags bit0 ->
//     FUN_71006a5d6c([+0xc8], this, arg); bit1 -> FUN_71006a626c([+0xc8],
//     this).
//  2. [+0xd0] != 0 -> vt+0x08(it, this); FUN_71006a1908(this, handler,
//     arg) over the +0x48 table x [+0x40]; vt+0x10.
//  3. Both targets 0 -> handler loop only, plus the guarded lazy init of
//     the singleton at cell 0x71012fb130 (__cxa_guard; value =
//     [cell 0x71012fb138]+0x10 into cell 0x71012fb140); with flags bit0
//     and a non-zero vt+0x00 result also FUN_71006a5f88([+0xc8],
//     u16[target+0x1c], obj, 1, arg).
//  4. Clears bit0 of [+0x98].
}  // namespace object
