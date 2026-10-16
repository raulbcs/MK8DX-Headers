#pragma once

#include <cstdint>

namespace gear {

// EObjTriggerType — touch-reactive course objflow entries; type byte from
// objflow.byaml (entry+0x8, read 0x7100396138); word table 0xf24460 ->
// FUN_710017a870. No RTTI in the 400 binary.
enum EObjTriggerType : int32_t {
  ObjTrigger_Default = 0,          // tier 0x10000: 10f, level 0, no impulse (weakest path)
  ObjTrigger_TrickRamp = 1,        // tier 0x2: 45f, level 1, impulse (only literal add in the binary)
  ObjTrigger_DashMini = 2,         // tier 0x200: 20f, level 2, no impulse
  ObjTrigger_BoostPadWeak = 3,     // tier 0x4:  duration from slot+0x90 (param), level 3
  ObjTrigger_BoostPadMedium = 4,   // tier 0x8:  duration from slot+0x9c (param), level 4
  ObjTrigger_BoostPadStrong = 5,   // tier 0x10: duration from slot+0xa8 (param), level 5
  ObjTrigger_TrickRampGlider = 6,  // tier 0x100: duration slot+0xB4, level 6, glider checks (17a950)
  ObjTrigger_Unknown7 = 7,         // tier 0x80: 30f, level 7
  ObjTrigger_Unknown8 = 8,         // tier 0x40: 135f, level 8 (longest boost)
  ObjTrigger_Unknown9 = 9,         // tier 0x8000: 60f, level 9
  ObjTrigger_DashPanel = 10,       // tier 0x20: 60f, level 10, impulse; KCL attr DASH=0xa cross-link proven (18af54)
  ObjTrigger_Unknown11 = 11,       // tier 0x1: 90f, level 11, impulse (mushroom-class)
};
