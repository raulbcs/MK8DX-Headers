#pragma once

#include <cstdint>

namespace object {
// Course/mode registration and per-player render/input binding of the course
// holder. Docblock facts; extents unproven (access sites only).

// FUN_71006c0258 (0x71006c0258, extent 0x364; caller FUN_7100724984) —
// register a player into the mode-specific course systems (mode 0/1/2).
// rec = [this+0xf8] + min(u32[this+0xf0], id)*0x3e0; mode 1 binds base =
// slot(mgr,id)+0x3ce0 with mgr = [this+0x4218]; mode 2 stats snapshots via
// FUN_71006b21b8 (kinds 0x10/4/0x16/5/7 over base+0x3b30/0x35c0/0x3790/
// 0x3220/0x3960).
// FUN_71006c4c4c (0x71006c4c4c, extent 0x208) — per-player render-target
// binding; mgr = [this+0x248], base = [mgr+0x10] + min(u32[mgr+8], pl)*0x3d68
// + 0x3ce0; [desc+0xb8] = slot + 0x1108.
// FUN_71006a784c (0x71006a784c, extent 0x228, gap-split) — apply slot input;
// sel = ([this+0x10] + idx*0x18) clamped to [this+0x8]; vehicle slot =
// [this+0x40] + (idx < [this+0x38] ? idx*0xa8 : 0); refresh FUN_7100a7763c.
// FUN_710065e7b0 (0x710065e7b0, extent 0x27c, gap-split; caller
// FUN_71006c5598) — begin streaming batch request; gate byte +0x9d0; node
// list at +0x1d0 (head +0x1d8, count s32 +0x1e0) or single target +0xa30;
// state writes +0x568/+0x73c..0x740/+0x734..0x739.
// FUN_71006a1c34 (0x71006a1c34, extent 0x2bc; tail-called from
// FUN_71006a1bc4) — per-core listener drain; +0xc8 primary target, +0xd0
// secondary, +0x40 handler count, +0x48 handler table, +0x98 flag byte;
// lazy singleton init via cell 0x71012fb130.
// NOTE: OPEN — mode-player record stride 0x3e0 and arm stride 0x3d68 not
// struct-mirrored (owner extents unproven).
}  // namespace object
