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

// Ctor 0x710013f968 (race-director vtable 0x11ba328); member ctors 0x6287b4 at the seven
// 0xC8 job blocks (back-pointers block-0x28: 0x170/0x238/0x300/0x3C8/0x490/0x558/0x620),
// member ctor 0x6286a4 at +0x708, second vptr [0x12fbd48]+0x10 = 0x11b3928 at +0x758.
// Size >= 0x760. Vtable slots: 1 (0x18) singleton getter (guard 0x712fd340, cell 0x712fd348,
// static instance 0x710013f90c); 2 (0x20) ctor/dtor 0x710013f968; 3 (0x28) reinit+delete
// 0x710013fa10; 14 (0x80) scenario init 0x710013d588; 15 (0x88) reset weights 0x710013e140;
// 17 (0x98) tick 0x710013eaec; 18 (0xa0) frame update 0x710013ec60; 24 (0xd0) free actors
// 0x710013d0ac. Shuffle helper FUN_710013e524 (range through 0x710013eae8); profiler flush
// FUN_71006328b8 (end of Calc pipeline).
//
// Calc pipeline: CalcPosition -> CalcAI -> CalcMove -> (KartRadar | CalcApply); phase id at
// 0x790; each phase uses one of the 0xC8 work blocks at 0x170-0x6E8.
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
  uint8_t mFlagE9;                    // 0xE9 — per-unit pre-reset flag ((mode|2)==7, slot 14)
  // Offset facts: +0xEA gate flag (mode==5, slot 14); +0xE4 frame counter (slot 18);
  // +0xEB pending-event byte; +0xEC/+0xF0 queued event pair; +0xF0 = -1 or row+0x4c (slot 17);
  // +0x38/+0x40 count + 0x10-entry ptr table (slot 14, FUN_710060b3fc); +0x700 released in
  // slot 17 (FUN_71006a9508); +0x748 sub-actor bitset (slot 18); +0x758 second vptr;
  // +0x760 u32 seed + osc timer value; +0x764 rng state (FUN_710062ee88); +0x778 12 i16 draw
  // slots = -1 (shuffle FUN_710013e524). +0xA0-region profiler fields (flush FUN_71006328b8):
  // +0x78 unit count, +0x80 unit ptrs, +0x88 capacity, +0x90 records, +0x98 count, +0x9c active,
  // +0xa0 idle-frame u32, +0xa8 latched GetSystemTick.
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
