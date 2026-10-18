#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalResendMessageJob — RTTI-confirmed (typeinfo 0x12e0d90, name
// "N2nn3pia5local21LocalResendMessageJobE", base nn::pia::common::StepSequenceJob).
// extent 0x88 - details: doc/_nn/pia/local/LocalResendMessageJob.md
class LocalResendMessageJob {
 public:
  void* mVtable;          // 0x00 - vptr 0x12e0d58 (GOT cell 0x1313e00 + 0x10)
  uint8_t mBase08[0x50];  // 0x08 - base job region (C1 0xb4a5e0), unproven gap
  void* mPtr58;           // 0x58 - zeroed by C2
  void* mPtr60;           // 0x60 - zeroed by C2
  uint32_t mValue68;      // 0x68 - 100 (C2)
  uint32_t mPad6C;        // 0x6c - padding
  void* mBuf70;           // 0x70 - heap 0x18-byte buffer (alloc 0x568aa0)
  void* mBuf78;           // 0x78 - heap 0x5d8-byte zero-filled buffer
  void* mArg80;           // 0x80 - C2 x1 argument, cleared by D1/D0
};
}  // namespace nn::pia::local
