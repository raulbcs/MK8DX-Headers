#pragma once

#include <cstdint>

namespace nn::pia::session {
/// Typeinfo-row vtable: assigned 0x12dd870, installed vptr 0x12dd878 (GOT cell
/// 0x1313690 holds vptr-0x10). RTTI "N2nn3pia7session22CommunityManagementJobE".
/// extent 0x68 (ctor field stores; lower bound) - details: doc/_nn/pia/session/CommunityManagementJob.md
struct CommunityManagementJob {
  virtual void dtor();          // 0x00 slot0 (0x97dff8, D1)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97e02c, D0)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared pia-job stub)
  virtual void slot28();        // 0x28 slot5 (0x97e0b8)
  virtual void slot30();        // 0x30 slot6 (0x97e068)
  uint8_t mBase8[0x50];         // 0x08 - job-base region (base C1 0xb4a5e0)
  uint64_t mField58;            // 0x58 - zeroed by C1 0x97dfc0
  uint8_t mField60[8];          // 0x60 - member inited by 0x929ec0 (size unverified)
};
}  // namespace nn::pia::session
