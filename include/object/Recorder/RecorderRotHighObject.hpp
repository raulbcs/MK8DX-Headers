#pragma once

#include <cstdint>

// RecorderRotHighObject - recorder::Channel subclass (base vtable 0x12c3c78 family);
// name string 0xf0cdf0, vptr 0x12d2238, created by FUN_710088b76c when [parent+0x292] is set
// and [parent+0x295] is set (sibling variant of RecorderRotObject).
// extent 0x290 - details: doc/object/Recorder/RecorderRotHighObject.md

namespace object {
struct RecorderRotHighObject {
  uint8_t pad_00[0x1c0];   // 0x000 — vtable ptr (row 0x12d2228); 0x04-0x1BF unproven
  uint32_t mode_1c0;       // 0x1C0 — init 0x24
  uint32_t flag_1c4;       // 0x1C4 — init 6
  uint8_t pad_1c8[0xc];    // 0x1C8 - 0x1D3 — unproven
  int32_t index_1d4;       // 0x1D4 — frame index consumed by the read/write thunks
  uint8_t pad_1d8[0x18];   // 0x1D8 - 0x1EF — unproven
  float default_1f0;       // 0x1F0 — init -71.95f (0xC28F3CF5)
  float default_1f4;       // 0x1F4 — init -1.88f (0xFEC0461F)
  float default_1f8;       // 0x1F8 — init -1.2e9f (0xCE6638CC)
  uint8_t pad_1fc[0x7c];   // 0x1FC - 0x277 — unproven
  void* ptr_278;           // 0x278 — init 0
  void* ptr_280;           // 0x280 — init 0 (unverified usage)
  void* target_288;        // 0x288 — copy of [parent+0x278]; its [+0x88] receives 9 words
};
}  // namespace object
