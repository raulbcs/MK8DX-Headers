#pragma once

#include <container/seadBuffer.h>

#include <cstdint>
#include <eui/ControlBase.hpp>
#include <gear/UI/Page/UIPage.hpp>
#include <gear/UI/UIControlT.hpp>
#include <ui/RaceWindow.hpp>

namespace ui {
class Page_Race : public gear::UIPage {
 public:
  // 0x1D0 — page-event record passed to the 0x8cab10 thunk by the pause
  // toggle (0x7100535114); the thunk copies mPageId to +0x8 and tail-calls
  // the record's vtable slot 0x10. Interior layout unproven.
  uint8_t mPad1D0[0xE8];  // 0x1D0

  // 0x2B8 — control/context object targeted by per-player input records:
  // the pause gate (0x710053509c) requires *(input+0x10) == this + 0x2B8.
  // Interior layout unproven.
  uint8_t mPad2B8[0x30];  // 0x2B8

  // 0x2E8 — race phase holder; the u32 at +0x38 is the race phase (6 =
  // race running) and gates the pause toggle. The RoGamer97 "Allow Pause
  // Before Race Start" patch relaxes this compare (0x5350c4).
  uintptr_t mRacePhaseHolder;  // 0x2E8

  uint8_t mPad2F0[0x30];                                 // 0x2F0 unproven

  gear::UIControlT<eui::ControlBase>* mRacePageControl;  // 0x320
  uint8_t mPad328[0x8];                                  // 0x328

  sead::Buffer<ui::RaceWindow*> mRaceWindows;            // 0x330

  uint8_t mPad340[0x48];  // 0x340 unproven

  // 0x388 — pause subsystem list fanned out by the pause propagation
  // (0x7100535748): for each entry call 0x8be388(entry, on).
  uint32_t mPauseSubsystemCount;  // 0x388
  uint32_t mPad38C;               // 0x38C
  void** mPauseSubsystems;        // 0x390

  uint8_t mPad398[0x5B];  // 0x398 unproven

  // 0x3F3 — pause flag, stored/compared as a signed byte: 0 = unpaused,
  // >= 1 = paused; the pause-off path (0x7100535bb4) writes 0xF6.
  int8_t mPauseFlag;  // 0x3F3

  uint8_t mPad3F4;  // 0x3F4

  // 0x3F5 — combined with input+0x30 bit0/3/4 by the pause gate when the
  // page substate is not the pause-enabled one.
  uint8_t mPauseInputFlag;  // 0x3F5
};
}  // namespace ui
