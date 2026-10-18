#pragma once

#include <cstdint>

namespace nn::pia::session {
/// Typeinfo-row vtable: assigned 0x12dd630, installed vptr 0x12dd638 (GOT cell
/// 0x1313678 holds vptr-0x10). RTTI "N2nn3pia7session18BrowseMatchmakeJobE".
/// extent 0x60 (ctor field stores; lower bound) - details: doc/_nn/pia/session/BrowseMatchmakeJob.md
struct BrowseMatchmakeJob {
  virtual void dtor();          // 0x00 slot0 (0x97dc8c, tail-branch to base D1 0xb4a62c)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97dc90)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared pia-job stub)
  virtual void slot28();        // 0x28 slot5 (0x97ddbc, ret stub)
  virtual void slot30();        // 0x30 slot6 (0x97dd84)
  uint8_t mBase8[0x50];         // 0x08 - job-base region (base C1 0xb4a5e0)
  void* mField58;               // 0x58 - zeroed by C2 0x97dc58
};
}  // namespace nn::pia::session
