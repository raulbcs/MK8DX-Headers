#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet30NexMatchClearSystemPasswordJobE). Typeinfo-row vtable:
/// assigned 0x12daca0, real vptr 0x12daca8 (GOT cell 0x1312bd8 holds vptr-0x10).
/// Ctor zeroes [this+0x88]; no other construction sites found.
/// extent 0xa8 (slot-store lower bound) - details: doc/_nn/pia/inet/NexMatchClearSystemPasswordJob.md
struct NexMatchClearSystemPasswordJob {
  virtual void dtor();          // 0x00 slot0 (0x93c5c0, b 0x97ddfc fwd)
  virtual void dtorDeleting();  // 0x08 slot1 (0x93c5c4)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared `ret` stub)
  virtual void slot28();        // 0x28 slot5 (0x93c8d0)
  virtual void slot30();        // 0x30 slot6 (0x93c8ac)
  virtual void slot38();        // 0x38 slot7 (0x93c5e8)
  uint8_t mBase8[0xa0];         // 0x08 - base region (session::ClearMatchmakeSystemPasswordJob)
};
}  // namespace nn::pia::inet
