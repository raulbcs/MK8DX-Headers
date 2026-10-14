#pragma once

#include <cstdint>

namespace object {
// Item/object spawner director: double spawn of director objects, spawned-
// object init request, and cached-weight refresh of the spawned vehicle.
// Docblocks only — no class ownership proven beyond the offsets cited.

// FUN_710068640c (0x710068640c, extent 0x768) — spawn/attach up to two
// objects from the director state (tail-called from FUN_7100ada000).
// x0 = director, x1 = spawn info. Runs only when [+0x1c8] or [+0x208] set.
//  1. kind = (u16)[+0x330] mapped (0x3c -> 20, 0x3b -> 5); active =
//     ~[+0x248] & 1; FUN_71006453e8(kind) selects the record layout (bit0).
//  2. 0x50-byte stack record via FUN_710062ae2c + FUN_710062aeb0 with
//     layout-dependent fields (+0xa8/+0xa9/+0xac/+0xec for bit0 set,
//     +0xec/+0xed/+0xee otherwise), FUN_710063ed64(self+0xb90); clears
//     [self+0xbb0]/[self+0xbf0] (the +0xbb0 slot points at self+0xbf8).
//  3. FUN_71006454ac(self+0xf98, self+0x288). Mode latch at [+0xa8]:
//     mode == 3 -> [+0x114c] = 0 and (u16)[+0x114d] = 0, else 1/1; in both
//     cases an ldxr/stxr loop sets bit 2 of u32 [+0x1158] (mask 0xfffffffb).
//  4. Outer pass w26 in {0,1} (second pass only when [+0x208] != 0):
//     halved w21/w8 pair (asr #1 after the lt-increment) into
//     [self+0xb98..0xbac]; record copied into self+0xb90 via
//     FUN_710062e6c0 + FUN_710062e790; spawn id from FUN_7100644350(
//     self+0x288) clamped by (u16)[+0x2c4], overridden by [+0x1e8]
//     (pass 0) or [+0x228] (pass 1) when != -1, then min-clamped again;
//     spawn through FUN_710065b310 / FUN_710065b54c (saved u16 [+0x68]==4)
//     or FUN_710065ac28 / FUN_710065b4d8, selected by byte [+0x128], with
//     rodata 0x7100efab91 and *(cell 0x710012fae28)+0x10 as record payload.
//  5. When the count w22 >= 1, per copy: memcpy(self+0xdc8 or +0xbf8, obj,
//     0xab); FUN_710063a090(self+0xe78 or +0xca8, obj+0xb0); obj->[0x178]
//     into [self+0xf40] / [self+0xd70]; clears +0xf48/+0xd78 and
//     (u16)+0xf4a/+0xd7a; FUN_710063f9ec / FUN_710063f9c8; flag bit0 at
//     +0xf49 / +0xd79; FUN_710062ab24(self+0xb90, info) (unresolved callee
//     — no file_list entry, label kept per address); dispatch per [+0xa8]:
//     0/1 -> FUN_710065de58 variants, 2/3 -> FUN_710065dd14 /
//     FUN_710065dc60, else FUN_710065ddc8 (bit variants) or
//     FUN_710065c464 / FUN_710065c2a4.
//  6. Object stored into [self+0x620] (pass 0, plus FUN_71006454ac on
//     +0x628 and +0xf98) or [self+0x7f0] (pass 1, plus FUN_71006454ac on
//     +0x7f8). Finally, when [+0x1c8] == 0, [self+0x620] is destroyed
//     through the singleton deleter at cell 0x71001307018 via
//     FUN_710065b6b0 and cleared.

// FUN_710063f9ec (0x710063f9ec, extent 0x94) — spawned-object init
// (called from FUN_710068640c for the first object at self+0xdc8).
// x0 = spawned object self.
//  1. mgr = *(cell 0x7101309218); fn = *(cell 0x710130b9c0); call
//     fn([mgr+0x38], 0x36, &out) — global request id 54 (0x36); result
//     stored in [self+0x188].
//  2. When vptr [self+0x0] != 0: fn2 = *(cell 0x710130bea8) on
//     self + 0xb0. Else a temp record at sp via FUN_71006452a0(self, sp)
//     and fn3 = *(cell 0x710130be18) on it.
//  3. Returned word stored in [self+0x184] (also the return value).

// FUN_7100a7763c (0x7100a7763c, extent ..0xa776a4; 0xa776a8..0xa776d0 is
// an unreachable compiler-emitted cold duplicate of FUN_7100a776d0) —
// refresh the cached weight of a spawned vehicle (called by
// FUN_71006a784c / FUN_71006a7624 as (veh) or (veh + 0x18)).
// cached = float [veh+0x40]; cur = float [*([veh+0x8])]; no-op when equal.
// Dispatch index: idx = (([state+0x48] >> 11) & 0xe) | (([veh+0x7c] >> 5)
// & 1) with state = [veh+0x68]; entry = *(cell 0x1314f68) + idx*16 =
// {fn, offset}; call fn(veh + (offset >> 1)); then u32 [veh+0x40] =
// u32 [*([veh+0x8])].

// Dispatch entry behind cell 0x1314f68 (16-byte stride): +0x00 fn pointer
// of shape void(void* vehAtOffset); +0x08 s64 offset with target =
// veh + (offset >> 1).
}  // namespace object
