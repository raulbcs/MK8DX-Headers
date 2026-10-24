#pragma once

#include <cstdint>
#include <object/Kart/KartCalcSpeedMiniCore.hpp>

// Kart speed calculation runtime, "mini" variant — derives the core
// (factory 0x34c620: new(0x358), calls the core ctor 0x34d2d8, then
// installs vtable 0x710124ccf8 whose +0x80/+0x88/+0x90 wrappers call the
// core versions and notify the registry at mListenersE8).
namespace object::Kart {
class KartCalcSpeedMini : public KartCalcSpeedMiniCore {
 public:
  // 0x300..0x357 — mini tail (core extent 0x300; concrete object 0x358).
  uint32_t mCloneCount300;        // 0x300 — clone array count (init 0)
  uint32_t mCloneCap304;          // 0x304 — clone array capacity (init 0)
  KartCalcSpeedMiniCore** mCloneArray308;  // 0x308 — clone array, cap 8
                                  //  (alloc 0x710060b930 at 0x34c6b4); append
                                  //  in slot +0x2b8 (0x34d198: new(0x300) +
                                  //  core ctor @0x34d1cc, append @0x34d1d0)
  void* mIface310;                // 0x310 — [GOT 0x71012fb038]+0x10; copied-to
                                  //  array in onCreate (0x34c774-0x34c7a4) and
                                  //  notify target (0x34ca78)
  uint32_t mZero318;              // 0x318 — init 0
  uint8_t mPad31C[4];             // 0x31C - 0x31F — unproven gap
  uint8_t mFlag320;               // 0x320 — init 0
  uint8_t mPad321[7];             // 0x321 - 0x327 — unproven gap
  void* mIface328;                // 0x328 — third copy/notify target
                                  //  (0x34c774-0x34c7a4, 0x34c880-0x34c890)
  uint32_t mZero330;              // 0x330 — init 0
  uint8_t mPad334[4];             // 0x334 - 0x337 — unproven gap
  uint8_t mFlag338;               // 0x338 — init 0
  uint8_t mPad339[7];             // 0x339 - 0x33F — unproven gap
  void* mIface340;                // 0x340 — copy/notify target
                                  //  (0x34c7a4, 0x34ca8c-0x34cad8)
  uint32_t mZero348;              // 0x348 — init 0
  uint8_t mPad34C[4];             // 0x34C - 0x34F — unproven gap
  uint8_t mFlag350;               // 0x350 — init 0
  uint8_t mPad351[7];             // 0x351 - 0x357 — unproven gap

  // extent 0x358 (factory 0x34c620: operator new(0x358) at 0x34c630)
};
}  // namespace object::Kart
