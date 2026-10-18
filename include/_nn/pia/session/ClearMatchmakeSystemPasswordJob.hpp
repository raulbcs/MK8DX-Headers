#pragma once

#include <cstdint>

namespace nn::pia::session {
/// Typeinfo-row vtable: assigned 0x12dd6a0, installed vptr 0x12dd6a8 (GOT cell
/// 0x1313680 holds vptr-0x10). RTTI "N2nn3pia7session31ClearMatchmakeSystemPasswordJobE".
/// extent 0x70 (ctor field stores; lower bound) - details: doc/_nn/pia/session/ClearMatchmakeSystemPasswordJob.md
struct ClearMatchmakeSystemPasswordJob {
  virtual void dtor();          // 0x00 slot0 (0x97ddfc, D1)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97de30, D0)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared pia-job stub)
  virtual void slot28();        // 0x28 slot5 (0x97df44)
  virtual void slot30();        // 0x30 slot6 (0x97dee8)
  uint8_t mBase8[0x50];         // 0x08 - job-base region (base C1 0xb4a5e0)
  uint32_t mField58;            // 0x58 - zeroed by C1 0x97ddc0
  uint8_t mPad5c[4];            // 0x5c - ctor writes nothing
  uint64_t mField60;            // 0x60 - zeroed by C1 0x97ddc0
  uint8_t mField68[8];          // 0x68 - member inited by 0x929ec0 (size unverified)
};
}  // namespace nn::pia::session
