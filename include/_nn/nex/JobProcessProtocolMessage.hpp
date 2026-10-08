#pragma once

#include <cstdint>

#include <_nn/nex/Buffer.hpp>

// vtable: vptr 0x12e5b60 (GOT cell 0x1314958, n=13, ctor 0xa2917c, sole site 0xa291fc); RTTI
// _ZN2nn3nex25JobProcessProtocolMessageE. Member of the nn::nex job vtable family.

namespace nn::nex {
class JobProcessProtocolMessage {
 public:
  uint8_t mPad00[0x40];      //0x00 — unproven padding
  uint32_t mFlags;           //0x40
  uint8_t mPad44[0x9C];      //0x44 — unproven padding
  nn::nex::Buffer* mMsgBuf;  //0xE0
};
}  // namespace nn::nex
