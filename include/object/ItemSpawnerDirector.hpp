#pragma once

#include <cstdint>

namespace object {
// Item/object spawner director. Docblock facts — owning classes unnamed.

// Dispatch entry behind cell 0x1314f68 (PROVADO: idx*0x10 indexing in
// FUN_7100a7763c) — extent 0x10.
struct WeightDispatchEntry {
    void* fn;                 // 0x00 void(void* vehAtOffset)
    int64_t offset;           // 0x08 target = veh + (offset >> 1)
};
static_assert(sizeof(WeightDispatchEntry) == 0x10);

// FUN_710068640c (0x710068640c) — spawn/attach up to two objects; state at
// director +0x1c8/+0x208/+0x248/+0x330, 0x50-byte record at +0xb90 copied
// into +0xdc8/+0xbf8, objects stored at +0x620/+0x7f0.
// FUN_710063f9ec (0x710063f9ec) — spawned-object init; request id 0x36 via
// cell 0x710130b9c0, results at self+0x188/self+0x184.
// FUN_7100a7763c (0x7100a7763c; 0xa776a8..0xa776d0 is an unreachable cold
// duplicate of FUN_7100a776d0) — cached-weight refresh; float veh+0x40 vs
// *(*[veh+0x8]); entry = *(cell 0x1314f68) + idx*0x10.
// NOTE: struct fields of the director itself unproven (access sites only).
}  // namespace object
