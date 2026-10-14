#pragma once

// Player start-boost init / start-state refresh — owning class UNNAMED
// (cluster 0x7100027eb4 / 0x7100028990). Docblock-only: offsets are observed
// access sites; extent unproven.

// FUN_7100027eb4 (range 0x7100027eb4..0x7100028188) — start-boost init per
// slot via FUN_710087f030; flag bytes +0x48C+idx -> +0x498+p; body handles
// +0x328/+0x330/+0x338; sets [body+0x98] bit0, [body+0x80/0x88] = 1.0f;
// clears byte +0x4C0.
// FUN_7100028990 (true range ..0x7100028c2c; file_list 0xdc is a gap-split) —
// start-state refresh; gate bytes +0x215/+0x214/+0x449; copies 0x30 bytes
// +0x3E8+i*0xC -> +0x364+i*0x30 and +0x358+i*0x30 -> body+0x50; alternate
// head 0x7100028A60 ([+0x449]==2 path).
// NOTE: slot resolver FUN_710087f030 of the 0x71008bd374 per-context table
// cluster; -1 on gate failure. OPEN: extent unproven.
