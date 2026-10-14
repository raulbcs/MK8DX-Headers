#pragma once

#include <cstdint>

namespace gear {
// Spawner ring entry pushed by FUN_710065b6b4 (0x710065b6b4) into the ring
// at spawner+0x718 (cap u32 +0x710, head u16 +0x720) — extent 0x18, PROVADO
// by the 0x18 stride.
struct SpawnerRingEntry {
    uint64_t v0;              // 0x00 <- info->[0x180]->[0x50]
    uint64_t v1;              // 0x08 <- info->[0x180]->[0x58]
    uint64_t v2;              // 0x10 <- info->[0x180]->[0x60]
};
static_assert(sizeof(SpawnerRingEntry) == 0x18);
}  // namespace gear
