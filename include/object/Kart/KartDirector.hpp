#pragma once

#include <cstdint>

#include "KartUnitHolder.hpp"

namespace object {
// Value of KartDirector::mPhase790 while each stage of the calc pipeline
// runs; observed in KartDirector::CalcPosition (0x710013ef3c).
enum CalcPhase {
  CALC_PHASE_POSITION = 1,    // CalcPosition job submitted
  CALC_PHASE_AI = 2,          // CalcAI()
  CALC_PHASE_FRAME_STEP = 3,  // per-unit AccessorFrameStepMove loop
  CALC_PHASE_MOVE = 4,        // CalcMove job submitted
  CALC_PHASE_APPLY = 5,       // KartRadar | CalcApply branch
};

// Ctor = 0x710013f968 (race-director family vtable 0x11ba328; doc
// race_director_vtable_family.md "H"): member ctors 0x6287b4 at the seven
// 0xC8 job blocks (back-pointers at block-0x28: 0x170/0x238/0x300/0x3C8/
// 0x490/0x558/0x620), member ctor 0x6286a4 at +0x708, vtable
// [0x12fbd48]+0x10 = 0x11b3928 at +0x758. Size >= 0x760.
//
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 1 (0x18): guard-protected static accessor; __cxa_guard on the guard
//   at cell 0x712fd340, first init stores cell 0x712fbc68 (+0x10) into the
//   static slot at cell 0x712fd348 and returns it (singleton vtable-holder
//   instance). 0x58 bytes true (file_list size is a gap-split artifact).
//   [kartDirectorStaticInstance_710013f90c.cpp]
// - slot 2 (0x20): ctor 0x710013f968 (see above); tail-calls
//   gear::Actor::~Actor (0x71007b978c). [directorReinitSubsDtorSlot2_710013f968.cpp]
// - slot 3 (0x28): same re-init sequence as slot 2, then ~Actor and
//   operatorDelete_710060b470(self). [directorReinitSubsDtorDeleteSlot3_710013fa10.cpp]
// - slot 14 (0x80): scenario load/init. Allocates a 0x10-entry pointer table
//   via FUN_710060b3fc into +0x40 (all entries zeroed; count mirrored at
//   +0x38, set to 2), zeroes +0x4c, calls FUN_710013dfdc, derives +0xea
//   (race manager mode == 5) and +0xe9 ((mode | 2) == 7) from the race
//   manager state, and for scenario rows resolves the flow object via the
//   phys-manager lookup (+0x190 table entries) into +0xf8 plus a second
//   node cleared when (mode|2)==7 (0x20-byte nodes via FUN_710060afec).
//   listed 0x1a0 bytes is a gap-split artifact. [directorInitSlot14_710013d588.cpp]
// - slot 15 (0x88): reset per-item weights. For each of +0xc0 entries at
//   +0xc8: writes 1.0f into *(*(*(e+0x210)) + selector 0x10/0x18 by e+0x208
//   vs 2/3) + 0x38 and copies that sub-object into +0x170, +0x300 and +0x3c8
//   via FUN_7100631df8; then via the phys-manager (+0x190 -> +0x218 -> +0x50)
//   copies the flow default into +0x620 when +0xe9 is clear; finally calls
//   vt[0x20/8] on each non-null *(e+0x28). 0x210 bytes true (gap-split).
//   [directorResetWeightsSlot15_710013e140.cpp]
// - slot 17 (0x98): per-frame tick. When race manager state is (mode==3 &&
//   phase==2), stamps a 16-byte osc timer (cell 0x71012fbd48) with
//   nn::os::GetSystemTick and +0x760, then for every kart at +0xc8 whose
//   +0xea flag is set blends a random factor into the kart +0x48 target via
//   FUN_7100137df0. When +0xe9 is clear and +0xd8 is set, resolves a scenario
//   row and stores -1 or row+0x4c into +0xf0, then releases +0x700 via
//   FUN_71006a9508. 0x174 bytes true (gap-split). [directorTickSlot17_710013eaec.cpp]
// - slot 18 (0xa0): per-frame update. If pending byte +0xeb is set, plays the
//   queued event FUN_710013e3ac(self, +0xec, +0xf0) and clears +0xeb; calls
//   FUN_710013ed3c and KartDirector::CalcPosition (0x710013ef3c); rebuilds a
//   bitset (bit i set iff byte *(ptr_i + 0x20) + 0xca != 0 for each of the
//   +0xc0 entries at +0xc8) and, when it differs from +0x748, forwards it
//   through FUN_71000c7858()/+0x1f8 -> FUN_71000c87dc and stores it at +0x748;
//   calls FUN_710013f22c and increments +0xe4. 0xdc bytes true (gap-split).
//   [directorFrameUpdateSlot18_710013ec60.cpp]
// - slot 24 (0xd0): free actors — iterates count +0xc0 / array +0xc8 and
//   calls helper 0x710016ce8c on each entry. 0x48 bytes true (gap-split).
//   [kartDirectorFreeActors_710013d0ac.cpp]
//
// Calc pipeline: CalcPosition -> CalcAI -> CalcMove -> (KartRadar |
// CalcApply), selected per phase. Each phase submits a job whose buffer
// is one of the 0xC8 work blocks at 0x170-0x6E8; the phase id lives at
// 0x790. Member offsets verified against the 4.0.0 binary.
class KartDirector {
 public:
  uint8_t pad_00[0x50];               // 0x00 — unproven padding
  void* mUnits50[12];                 // 0x50 — per-unit object pointers, indexed by unit
                                      // idx clamped < 12 (FUN_710013f430 0x13f468-0x13f478, read before
                                      // each KartUnitHolder is destroyed)
  uint8_t pad_80[0x30];               // 0x80 — unproven padding
  void* mB0;                          // 0xB0 — passed to the unit getter along with the index
  uint8_t pad_B8[0x8];                // 0xB8 — unproven padding
  int mUnitCount;                     // 0xC0
  uint8_t pad_C4[0x4];                // 0xC4 — unproven padding
  KartUnitHolder** mKartUnitHolders;  // 0xC8
  uint8_t pad_D0[0x8];                // 0xD0 — unproven padding
  void* mD8;                          // 0xD8 — when set, CalcPosition runs the KartRadar branch instead of CalcApply
  uint8_t pad_E0[0x8];                // 0xE0 — unproven padding
  uint8_t mFlagE8;                    // 0xE8 — run the post-calc hook (arg: m6F8)
  uint8_t mFlagE9;                    // 0xE9 — run the per-unit pre-reset; derived in
                                      // slot 14 as ((race manager mode | 2) == 7)
  // +0xEA — flag derived in slot 14 as (race manager mode == 5); gates the
  //   slot 17 random-blend into each kart's +0x48 target.
  // +0xE4 — frame counter, incremented each slot 18 update.
  // +0xEB — pending-event byte; when set, slot 18 plays the queued event
  //   FUN_710013e3ac(self, +0xec, +0xf0) and clears it.
  // +0xF0 — scenario row value (-1 or row+0x4c), written by slot 17; also
  //   the second word of the +0xec/+0xf0 queued event pair.
  // +0x38/+0x40 — count and 0x10-entry pointer table allocated by slot 14
  //   (FUN_710060b3fc, entries zeroed).
  // +0x700 — object released via FUN_71006a9508 in slot 17.
  // +0x708 — object initialized by member ctor 0x6286a4 (slot 2/3).
  // +0x748 — bitset of sub-actor flags (byte *(ptr_i + 0x20) + 0xca per
  //   +0xc8 entry); on change forwarded via FUN_71000c7858()/+0x1f8 ->
  //   FUN_71000c87dc and stored here (slot 18).
  // +0x758 — second vptr, cell 0x712fbd48 + 0x10 (slot 2/3 re-init).
  // +0x760 — value stamped into the slot 17 osc timer.
  uint8_t pad_EA[0x86];               // 0xEA — see field notes above

  // Job buffers (0xC8 each), reset by CalcAI before accumulation:
  // pointer at +0x00 zeroed, object at +0x28 re-initialized.
  char mWork170[0xC8];    // 0x170 — CalcPosition job block
  char mWork238[0xC8];    // 0x238 — CalcAI job block
  char mWork300[0xC8];    // 0x300 — CalcMove job block
  char mWork3C8[0xC8];    // 0x3C8 — CalcApply job block
  char mWork490[0xC8];    // 0x490 — job block (reset by CalcAI)
  char mWork558[0xC8];    // 0x558 — job block (reset by CalcAI)
  char mWork620[0xC8];    // 0x620 — KartRadar job block
  uint8_t pad_6E8[0x10];  // 0x6E8 — unproven padding
  void* m6F8;             // 0x6F8 — argument of the post-calc hook
  uint8_t pad_700[0x90];  // 0x700 — unproven padding
  int mPhase790;          // 0x790 — current CalcPhase (1..5)

  // AI calc phase: resets the work blocks, accumulates the eligible
  // units and submits the "KartDirector::CalcAI" job.
  void CalcAI() asm("KartDirector::CalcAI");  // KartDirector::CalcAI
  // Full calc pipeline: CalcPosition -> CalcAI -> CalcMove ->
  // (KartRadar|)CalcApply.
  void CalcPosition() asm("KartDirector::CalcPosition");  // KartDirector::CalcPosition
};
}  // namespace object
