#pragma once

#include <cstdint>

namespace nn::pia::transport {
// nn::pia::transport::Protocol — RTTI-named (typeinfo slot 0x12e0360 ->
// 0x12e03c0, "N2nn3pia9transport8ProtocolE"). vptr 0x12e0368 (GOT cell
// 0x1312470 holds 0x12e0358 = vt-0x10).
// extent 0x30 - details: doc/_nn/pia/transport/Protocol.md
class Protocol {
 public:
  void* vtable;      // 0x00 - 0x12e0368 (cell 0x1312470 + 0x10)
  uint32_t m08;      // 0x08 - C1 zero
  uint32_t m0c;      // 0x0c - C1 sets 0x14
  uint32_t m10;      // 0x10 - C1 zero
  uint16_t m14;      // 0x14 - factory sets 0xffff
  uint16_t m16;      // 0x16 - factory sets 0xffff
  uint8_t m18;       // 0x18 - factory sets 1
  uint8_t m19;       // 0x19 - factory sets 0
  char pad1a[0x06];  // pad - unproven gap
  void* m20;         // 0x20 - factory zero
  uint32_t m28;      // 0x28 - factory zero
  uint32_t m2c;      // 0x2c - factory zero
};
}  // namespace nn::pia::transport
