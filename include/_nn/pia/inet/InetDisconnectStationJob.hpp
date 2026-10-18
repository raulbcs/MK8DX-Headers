#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet24InetDisconnectStationJobE). Typeinfo-row vtable:
/// assigned 0x12da550, real vptr 0x12da558 (GOT cell 0x1312a38 holds vptr-0x10).
/// No construction sites found.
/// extent 0x80 (slot-store lower bound) - details: doc/_nn/pia/inet/InetDisconnectStationJob.md
struct InetDisconnectStationJob {
  virtual void dtor();          // 0x00 slot0 (0x937598, b 0x9a2f04 base dtor fwd)
  virtual void dtorDeleting();  // 0x08 slot1 (0x93759c, base dtor + operator delete)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared job slot)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared job slot)
  virtual void slot20();        // 0x20 slot4 (0x933314, shared `ret` stub)
  virtual void slot28();        // 0x28 slot5 (0x9376e4)
  virtual void slot30();        // 0x30 slot6 (0x9375c0)
  virtual void slot38();        // 0x38 slot7 (0x9a2f38)
  uint8_t mBase8[0x78];         // 0x08 - base region (pia StepSequenceJob-family job base)
};
}  // namespace nn::pia::inet
