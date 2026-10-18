#pragma once

#include <cstdint>

namespace nn::nex {
// nn::nex::TicketGrantingProtocolClient — RTTI-named (typeinfo 0x12e6560, name
// string at 0xf85a20, base nn::nex::ClientProtocol); vptr 0x12e60c8 (GOT cell
// 0x1314a78 holds 0x12e60b8 = vt-0x10); ctor 0xa2f24c.
// extent 0x90 - details: doc/_nn/nex/TicketGrantingProtocolClient.md
class TicketGrantingProtocolClient {
 public:
  void* vtable;            // 0x00 - 0x12e60c8 (cell 0x1314a78 + 0x10)
  char pad08[0x40];        // 0x08..0x47 - unproven gap
  uint16_t mProtocolId48;  // 0x48 - ctor strh (protocol id 10 at the factory)
  char pad4a[0x6];         // 0x4a..0x4f - unproven gap
  char pad50[0x10];        // 0x50..0x5f - ctor zeroes (stp xzr,xzr)
  char pad60[0x10];        // 0x60..0x6f - unproven gap
  uint8_t m70;             // 0x70 - ctor writes 0 (strb)
  char pad71[0x7];         // 0x71..0x77 - unproven gap
  void* m78;               // 0x78 - ctor writes 0
  uint32_t m80;            // 0x80 - ctor writes 0
  char pad84[0x4];         // 0x84..0x87 - unproven gap
  void* mCredentials88;    // 0x88 - ctor writes 0 (ClientProtocol field)
};
}  // namespace nn::nex
