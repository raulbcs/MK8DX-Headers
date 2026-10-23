#pragma once

#include <cstdint>
#include <gear/Actor/Actor.hpp>
#include <gear/Race/ERaceState.hpp>

namespace object {
// Concrete checkers extend the vtable beyond Actor's 0x68 with slots
// 0x70-0xb8; declared here.
class RaceStateChecker : public gear::Actor {
 public:
  virtual void slot70();  //0x70
  virtual void slot78();  //0x78
  virtual void slot80();  //0x80
  virtual void slot88();  //0x88
  virtual void slot90();  //0x90
  virtual void slot98();  //0x98
  virtual void slotA0();  //0xa0
  virtual void slotA8();  //0xa8
  virtual void slotB0();  //0xb0
  virtual void slotB8();  //0xb8

  // 0x38 — race state (gear::ERaceState) on the base checker path;
  // RaceKartChecker reuses the slot as kart index (0..11).
  uint32_t mRaceState;  // 0x38
};
}  // namespace object
