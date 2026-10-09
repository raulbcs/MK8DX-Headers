#pragma once

#include <cstdint>

namespace gear {

/*
 * EObjTriggerType — class of touch-reactive course objects (objflow
 * entries) that fire interaction events when the kart passes through
 * them. Most classes push a BoostSlot tier through FUN_710017a870; the
 * glide-open path shares the same dispatcher.
 *
 * Reconstructed (no RTTI in the 400 binary): the type byte is
 * course-file data (objflow.byaml), read from the descriptor at
 * entry+0x8 by 0x7100396138 and dispatched through the word table
 * 0xf24460 (type -> BoostSlot tier) -> FUN_710017a870. Proven
 * identities and effect table: mk8dx-400 docs/MECHANICS_101.md,
 * section "Course triggers" (commits 42a2241f, 98550f99).
 */
enum EObjTriggerType : int32_t {
  ObjTrigger_Default = 0,   // tier 0x10000: 10f, level 0, no impulse (weakest path)
  ObjTrigger_TrickRamp = 1, // tier 0x2: 45f, level 1, impulse (only literal add in the binary)
  ObjTrigger_DashMini = 2,  // tier 0x200: 20f, level 2, no impulse
  ObjTrigger_BoostPadWeak = 3,    // tier 0x4:  duration from slot+0x90 (param), level 3
  ObjTrigger_BoostPadMedium = 4,  // tier 0x8:  duration from slot+0x9c (param), level 4
  ObjTrigger_BoostPadStrong = 5,  // tier 0x10: duration from slot+0xa8 (param), level 5
  ObjTrigger_TrickRampGlider = 6, // tier 0x100: duration slot+0xB4, level 6, glider checks (17a950)
  ObjTrigger_Unknown7 = 7,        // tier 0x80: 30f, level 7
  ObjTrigger_Unknown8 = 8,        // tier 0x40: 135f, level 8 (longest boost)
  ObjTrigger_Unknown9 = 9,        // tier 0x8000: 60f, level 9
  ObjTrigger_DashPanel = 10,      // tier 0x20: 60f, level 10, impulse; KCL attr DASH=0xa cross-link proven (18af54)
  ObjTrigger_Unknown11 = 11,      // tier 0x1: 90f, level 11, impulse (mushroom-class)
};

/*
 * Provenance notes (2026-10-09 sessions):
 * - The type byte originates from course-file data (objflow.byaml),
 *   read from descriptor entry+0x8/+0x9 at 0x7100396198/0x71003961c4 —
 *   never an immediate in code. t0/t2/t11 identities therefore live in
 *   content data, not the binary (mk8dx-400 data/content/objflow.byaml).
 * - t3/4/5 are one object family with parameter {1,2,3}
 *   (selector 0x7100183648). t10 cross-links to KCL attr
 *   ESurfaceType::DASH (0xa) at 0x710018af54.
 * - Dispatch: FUN_710017af90 (tail-b of body calc 189534) indexes the
 *   word table and falls back to tier 1 for types > 0xb.
 */
}  // namespace gear
