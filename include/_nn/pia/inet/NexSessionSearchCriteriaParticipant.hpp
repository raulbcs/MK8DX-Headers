#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::NexSessionSearchCriteriaParticipant - RTTI-named (typeinfo
// slot 0x12da390 -> record 0x12da3c0, base nn::pia::session::SessionSearch-
// Criteria). vptr 0x12da398, 5 slots.
// extent 0x980 - details: doc/_nn/pia/inet/NexSessionSearchCriteriaParticipant.md
class NexSessionSearchCriteriaParticipant {
 public:
  void* vtable;       // 0x00 - 0x12da398 (GOT cell 0x13129a8 + 0x10)
  char pad08[8];      // pad - base SessionSearchCriteria body, unverified
  uint32_t m10;       // 0x10 - C1 sets 2
  char pad14[4];      // pad - unproven gap
  uint8_t m18[0x960]; // 0x18 - C1 zeroes 0x20-byte entries (loop to 0x978)
  uint32_t m978;      // 0x978 - C1 zero
  uint8_t m97c;       // 0x97c - C1 zero
  uint8_t m97d;       // 0x97d - C1 sets 1
  uint8_t m97e;       // 0x97e - C1 sets 1
  uint8_t m97f;       // 0x97f - C1 zero
};
}  // namespace nn::pia::inet
