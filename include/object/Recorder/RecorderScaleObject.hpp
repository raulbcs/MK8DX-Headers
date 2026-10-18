#pragma once

#include <cstdint>

// RecorderScaleObject - recorder::Channel subclass (base vtable 0x12c3c78 family);
// name string 0xf0cdb6, vptr 0x12d1ec0, created by FUN_710088b76c when [parent+0x291] is set.
// extent 0x288 - details: doc/object/Recorder/RecorderScaleObject.md

namespace object {
struct RecorderScaleObject {
  uint8_t pad_00[0x1c0];   // 0x000 — vtable ptr (row 0x12d1eb0); 0x04-0x1BF unproven
  uint32_t mode_1c0;       // 0x1C0 — init 0xC
  uint32_t flag_1c4;       // 0x1C4 — init 4
  uint8_t pad_1c8[0xc];    // 0x1C8 - 0x1D3 — unproven
  int32_t index_1d4;       // 0x1D4 — frame index consumed by the read/write thunks
  uint8_t pad_1d8[0x18];   // 0x1D8 - 0x1EF — unproven
  float default_1f0;       // 0x1F0 — init 0.01f (0x3C23D70A)
  float default_1f4;       // 0x1F4 — init 64.0f (0x42800000)
  uint8_t pad_1f8[0x80];   // 0x1F8 - 0x277 — unproven
  void* ptr_278;           // 0x278 — init 0
  void* target_280;        // 0x280 — observed object ([parent+0x278]); +0x98 vec3 scale
};
}  // namespace object
