// Ctor 0x710013f968 (race-director vtable 0x11ba328); member ctors 0x6287b4 at the seven
// extent 0x794
#pragma once
#include <cstdint>

namespace object {
class KartUnitHolder;  // object/Kart/KartUnitHolder.hpp

class KartDirector {
 public:
  uint8_t pad_00[0x50];               // 0x00 — unproven padding
  void* mUnits50[12];                 // 0x50 — per-unit object pointers, indexed by unit
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
  uint8_t pad_EA[0x86];               // 0xEA — see field notes above

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

  void CalcAI() asm("KartDirector::CalcAI");              // KartDirector::CalcAI
  void CalcPosition() asm("KartDirector::CalcPosition");  // KartDirector::CalcPosition
};
}  // namespace object
