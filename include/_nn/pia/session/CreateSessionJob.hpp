#pragma once

#include <cstdint>

namespace nn::pia::session {
/// Typeinfo-row vtable: assigned 0x12dd980, installed vptr 0x12dd988 (GOT cell
/// 0x13136a8 holds vptr-0x10). RTTI "N2nn3pia7session16CreateSessionJobE".
/// extent 0x88 (ctor field stores; lower bound) - details: doc/_nn/pia/session/CreateSessionJob.md
struct CreateSessionJob {
  virtual void dtor();          // 0x00 slot0 (0x97e934, D1)
  virtual void dtorDeleting();  // 0x08 slot1 (0x97e968, D0)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared pia-job stub)
  virtual void slot28();        // 0x28 slot5 (0x97efe8)
  virtual void slot30();        // 0x30 slot6 (0x97ef8c)
  uint8_t mBase8[0x50];         // 0x08 - job-base region (base C1 0xb4a5e0)
  uint64_t mField58;            // 0x58 - zeroed by C1 0x97e8f4
  uint8_t mField60[0x20];       // 0x60 - member inited by 0x929ec0 (size unverified)
  uint32_t mField80;            // 0x80 - zeroed by C1 0x97e8f4
  uint8_t mPad84[4];            // 0x84 - ctor writes nothing
};
}  // namespace nn::pia::session
