#pragma once

// Race-director-cluster single-word helpers (0x710087xxx / 0x710088xxx;
// owning classes unnamed — same neighborhood as getRaceCheckManager_
// 710087FCD0 and the FUN_710087F030 slot resolver). Docblock-only facts:

// FUN_71008797F0 — RaceDirector-family vtable slot 0xA8 implementation:
// *(u8*)(o + 0x40) = 1 (set state flag byte, returns void).
// FUN_7100889308 — *(u32*)(o + 0x19C) += 1 (bare counter increment).
