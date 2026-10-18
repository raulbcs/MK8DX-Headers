#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::NexSessionSearchCriteria - RTTI-named (typeinfo slot 0x12da340
// -> record 0x12da370, "N2nn3pia4inet24NexSessionSearchCriteriaE", base
// nn::pia::session::SessionSearchCriteria). vptr 0x12da348, 5 slots.
// extent 0xd1c (lb) - details: doc/_nn/pia/inet/NexSessionSearchCriteria.md
class NexSessionSearchCriteria {
 public:
  void* vtable;       // 0x00 - 0x12da348 (GOT cell 0x1312970 + 0x10)
  char pad08[0x9c2];  // pad - base SessionSearchCriteria body, unverified
  uint8_t m9ca;       // 0x9ca - C1 sets 1
  uint8_t m9cb;       // 0x9cb - C1 sets 1
  uint32_t m9cc;      // 0x9cc - C1 zero
  void* m9d0;         // 0x9d0 - C1 zero
  void* m9d8;         // 0x9d8 - C1 zero
  void* m9e0;         // 0x9e0 - vptr of nn::pia::common::FixedString<2> row 0x12d96e8
  void* m9e8;         // 0x9e8 - points to buffer at 0x9fc
  uint32_t m9f0;      // 0x9f0 - C1 store (value from base init)
  char pad9f4[8];     // pad - C1 zero region
  uint16_t m9fc[4];   // 0x9fc - C1 zeroes (4 x u16)
  uint8_t ma04;       // 0xa04 - C1 zero
  uint8_t pada05[3];  // pad - C1 zero region
  uint8_t ma08;       // 0xa08 - C1 zero
  char pada09[0xb];   // pad - unproven gap
  uint32_t ma14;      // 0xa14 - C1 zero
  uint16_t ma18[4];   // 0xa18 - C1 sets 0xffff
  uint8_t ma20;       // 0xa20 - C1 sets 1
  uint8_t ma21;       // 0xa21 - C1 sets 1
  char pada22[6];     // pad - unproven gap
  void* ma28;         // 0xa28 - vptr of nn::pia::common::FixedString<8> row 0x12d9748
  void* ma30;         // 0xa30 - points to buffer at 0xa44
  uint32_t ma38;      // 0xa38 - C1 sets 0x20
  uint32_t ma3c[2];   // 0xa3c - C1 zeroes
  uint16_t ma44[0x11];// 0xa44 - C1 zeroes
  uint8_t ma66;       // 0xa66 - C1 zero
  char pada67;        // pad - unproven gap
  void* ma68;         // 0xa68 - vptr of FixedString<8> row 0x12d9748
  void* ma70;         // 0xa70 - points to buffer at 0xa84
  uint32_t ma78;      // 0xa78 - C1 sets 0x20
  char pada7c[8];     // pad - unproven gap
  uint16_t ma84[0x10];// 0xa84 - C1 zeroes
  char padaa4[4];     // pad - unproven gap
  void* maa8;         // 0xaa8 - vptr of FixedString<8> row 0x12d9748
  void* mab0;         // 0xab0 - points to buffer at 0xac4
  void* mab8;         // 0xab8 - points to buffer at 0xac4
  char padac0[4];     // pad - unproven gap
  char padac4[0x54];  // pad - unproven gap 0xac4..0xb17  // pad - unproven gap 0xac4..0xb17
  void* mb18;         // 0xb18 - vptr of FixedString<8> row 0x12d9748
  char padb20[0x1f8]; // pad - unproven gap 0xb20..0xd17
  uint32_t md18;      // 0xd18 - last field written by C1 0x933694
};
}  // namespace nn::pia::inet
