#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalBackgroundProcessJob — RTTI-named, base
// nn::pia::common::StepSequenceJob. 6 slots; GOT cell 0x1313ed8 holds
// vptr-0x10 (vptr 0x12e14e8).
// extent 0x88 - details: doc/_nn/pia/local/LocalBackgroundProcessJob.md
class LocalBackgroundProcessJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e14e8 (cell 0x1313ed8 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mZero58;         // 0x58 - zeroed by C1
  uint32_t mVal60;       // 0x60 - set to 10 by C1
  uint16_t mZero64;      // 0x64 - zeroed by C1
  uint16_t mPad66;       // 0x66 - padding
  void* mZero68;         // 0x68 - zeroed by C1
  void* mPtr70;          // 0x70 - arg x1 of C1
  uint8_t mPad78[0x8];   // 0x78 - zeroed by C1 (only [0x78] proven)
  uint8_t mSub80[0x8];   // 0x80 - member subobject, tail-ctor 0xb485a8
};
}  // namespace nn::pia::local
