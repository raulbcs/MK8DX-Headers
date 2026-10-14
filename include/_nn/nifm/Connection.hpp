#pragma once

#include <cstdint>

// nn::nifm connection cluster (0x710097xxx / 0x71009cxxx) as used by the
// game's network layer. Docblock facts; owning structs are larger than the
// fields shown and unnamed in the binary except where noted.

namespace nn {
namespace nifm {

// FUN_7100970938 — connection state machine step (extent
// 0x7100970938..0x70a94; all exits converge on the store-out at 0x710070a94;
// tail-called from FUN_710096c898). x0 = connection object, x8 = sret for
// the nn::Result out. Observed fields:
//   +0x28  u8 connected (set on success)
//   +0x2C  u32 gate (0 aborts)
//   +0x40  arg to the bind helper FUN_7100b4a5d4
//   +0x48/+0x50  vt+0x20 call on the +0x60 handle when [+0x50] set
//   +0x58/+0x60  handles built via FUN_71009b9704/FUN_71009b96e4 on the
//                global cell 0x71013125e0 (null handle aborts)
//   +0x68  object for vt+0x30 with self+0x36, then FUN_7100567d4c(obj, 1)
//   +0x12A0/+0x12A4  flags (12A4 != 0 composes the random profile)
//   +0x12B8/+0x12BA  flag bytes cleared each step
// When [+0x12A4] != 0: 4-word random profile — FUN_7100929FC4 seeds a
// descriptor, sead::Random::getU32 draws 4 values (FUN_710056766C-mixed)
// into +4/+8/+C/+10, FUN_71009b8fb8 registers it. Then FUN_7100970b40,
// bind attempts via FUN_7100b4a5d4 on the +0x58/+0x60 pair, optional
// vt+0x20, unbind FUN_7100b4a5bc, clear +0x12A0, vt+0x30 on [+0x68], and
// the +0x28 connected byte. Last nn::Result written to *out.

// FUN_7100970e48 — teardown (168 B, caller FUN_710096c8a0). Gate byte +0x28
// cleared first; x0 = [+0x68]: byte [x0+0x48] = 1, FUN_7100b4a6e8(x0, 5),
// virtual call [x0]->vtable+0x38; zeroes +0x12B8/+0x12BA; FUN_7100b4a5cc on
// +0x58 and +0x60; conditional FUN_7100b49cb8 for the +0x40/+0x48 sub-objs
// (when their [4] >= 1); final FUN_71009750b0([+0x60]).

// FUN_7100970f04 — global chain getter (16 B): x8 = *(cell 0x71013120880);
// return *(void**)(x8 + 0x20).

// FUN_71009c77a8 — tests *(u32*)(o + 0x3A0) == 1.
// FUN_71009c9550 — tests *(u32*)(o + 0x388) != 0.
// FUN_71009e3c98 — tests *(u32*)(o + 0x48) == 0x40.

}  // namespace nifm

// FUN_7100987978 — controller/PadState reconfiguration driver (extent
// 0x7100987978..0x987edc; file_list size 0x80 is a gap-split). x0 = manager,
// x1 = config, x8 = sret nn::Result (default 0xc0810000; -1 after the
// global-gate block when 0x71312000+0x5e0 obj + FUN_71009a34e8 non-null,
// 0x71313000+0x880 byte+1 set, and [x1]-0x3e8 < 0x7149 unsigned fails).
// Main path: when [+0xC4] FUN_71009a11cc([+0xA0], [x1+0x30], [x1+0x34],
// byte [x1+0x3C], [x1+0x38]); byte [x1+0x48] -> [+0xF3]; sub-record
// validation (count [x1+0x18], type 1..4) via FUN_7100987e70; byte
// [x1+0x8] through virtual [[+0x38] vt+0x50]; [0x130b000+0x220]+0xA1 =
// [+0xBC], [+0xC8] = [x1+0x8]; when [x1+0x18] <= 1 or [+0xCB]:
// nn::account::Initialize() then a 4-slot player reset loop (0x88/0x48
// stride tables, memset 0x40, per-slot 0x88 records cleared, counters
// [+0x154/+0x158/+0x1B0/+0x1B8], [+0x360] = 0); re-walk [x1+0x10] records:
// FUN_710092a7e8([+0x140] + slot*0x88, rec), copies of rec+0x70/0x78/0x80,
// [x1+0x20] handles appended per slot, [+0x360]++; [+0x133] = [x1+0x18],
// [+0x132] = [x1+0x19]; [[+0x18]+0x60] = 0x2710; [[+0x20]+0x64] = [x1]+0x1388;
// period scaling when the global byte is set: p = max(w, 0x3e8) >> 4,
// clamped < 0x753. (Listed in the networking sweep; the cluster is
// pad-config, not nifm proper.)
namespace hid {
struct PadStateReconfig {};  // placeholder anchor; layout unproven
}  // namespace hid
}  // namespace nn
