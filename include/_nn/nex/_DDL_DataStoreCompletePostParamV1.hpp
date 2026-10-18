#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo name "..33_DDL_DataStoreCompletePostParamV1E",
// ti 0x12f8b00; full nesting unverified, written as nn::nex per
// _DDL_AuthenticationInfo precedent). vptr 0x12f89f8 (n=24).
// extent 0x90 - details: doc/_nn/nex/_DDL_DataStoreCompletePostParamV1.md
class _DDL_DataStoreCompletePostParamV1 {
 public:
  void* vtable;             // 0x00 — 0x12f89f8 (cell 0x1315f38 + 0x10)
  uint8_t mPad08[0x40];     // 0x08 — unproven gap
  uint16_t mField48;        // 0x48 — u16 read back by ctor 0xb4661c
  uint8_t mPad4a[0x6];      // 0x4a — unproven padding
  uint32_t mField50[4];     // 0x50 — zeroed by base ctor 0xa27e78
  uint32_t mField60;        // 0x60 — u32 ctor param (base ctor)
  uint8_t mPad64[0xc];      // 0x64 — zeroed (base ctor)
  uint8_t mField70;         // 0x70 — zeroed (base ctor)
  uint8_t mPad71[0x7];      // 0x71 — unproven padding
  void* mField78;           // 0x78 — zeroed (base ctor)
  uint32_t mField80;        // 0x80 — zeroed (base ctor)
  uint8_t mPad84[0x4];      // 0x84 — unproven padding
  void* mField88;           // 0x88 — refcounted member released by slot0
                            // 0x90 (alloc size at virtual-new 0xb46860)
};
}  // namespace nn::nex
