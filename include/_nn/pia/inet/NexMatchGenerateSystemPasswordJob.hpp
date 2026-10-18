#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet33NexMatchGenerateSystemPasswordJobE). Typeinfo-row vtable:
/// assigned 0x12daea0, real vptr 0x12daea8 (GOT cell 0x1312d38 holds vptr-0x10).
/// Ctor zeroes [this+0x88]; no other construction sites found.
/// extent 0x158 (slot-store lower bound) - details: doc/_nn/pia/inet/NexMatchGenerateSystemPasswordJob.md
struct NexMatchGenerateSystemPasswordJob {
  virtual void dtor();          // 0x00 slot0 (0x93f11c)
  virtual void dtorDeleting();  // 0x08 slot1 (0x93f120)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared `ret` stub)
  virtual void slot28();        // 0x28 slot5 (0x93f42c)
  virtual void slot30();        // 0x30 slot6 (0x93f408)
  virtual void slot38();        // 0x38 slot7 (0x93f144)
  uint8_t mBase8[0x150];        // 0x08 - base region (session::GenerateMatchmakeSystemPasswordJob)
};
}  // namespace nn::pia::inet
