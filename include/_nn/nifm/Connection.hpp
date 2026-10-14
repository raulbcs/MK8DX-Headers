#pragma once

#include <cstdint>

// nn::nifm connection cluster (0x710097xxx / 0x71009cxxx). Docblock facts;
// owning structs unnamed, extents unproven.

// FUN_7100970938 (extent 0x7100970938..0x710070a94, tail-called from
// FUN_710096c898) — connection state machine step; x8 = sret nn::Result.
// Fields: +0x28 u8 connected; +0x2C u32 gate (0 aborts); +0x40 bind arg
// (FUN_7100b4a5d4); +0x48/+0x50, +0x58/+0x60 handles (FUN_71009b9704/
// FUN_71009b96e4 on cell 0x71013125e0); +0x68 object; +0x12A0/+0x12A4 flags;
// +0x12B8/+0x12BA flag bytes cleared each step. When [+0x12A4] != 0 a 4-word
// random profile is drawn (FUN_7100929FC4 / sead::Random::getU32 via
// FUN_710056766C / FUN_71009b8fb8) into +4/+8/+C/+10 of the descriptor.
// FUN_7100970e48 (168 bytes) — teardown; gate byte +0x28 cleared first,
// zeroes +0x12B8/+0x12BA, FUN_7100b4a5cc on +0x58/+0x60.
// FUN_7100970f04 (16 bytes) — global chain getter: *(cell 0x71013120880)+0x20.
// FUN_71009c77a8 — *(u32*)(o + 0x3A0) == 1. FUN_71009c9550 — *(u32*)(o +
// 0x388) != 0. FUN_71009e3c98 — *(u32*)(o + 0x48) == 0x40.
// FUN_7100987978 (extent ..0x987edc; file_list 0x80 is a gap-split) —
// pad-config driver, not nifm proper: manager +0xC4/+0xA0/+0xF3/+0x140
// (stride 0x88 records), counters +0x154/+0x158/+0x1B0/+0x1B8, +0x360;
// config x1 fields +0x8/+0x10/+0x18/+0x30/+0x34/+0x38/+0x3C/+0x48.
// NOTE: hid placeholder anchor kept (layout unproven); OPEN: none.
namespace nn {
namespace nifm {
}  // namespace nifm

namespace hid {
struct PadStateReconfig {};  // placeholder anchor; layout unproven
}  // namespace hid
}  // namespace nn
