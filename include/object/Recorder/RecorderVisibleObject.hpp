#pragma once

#include <cstdint>

// RecorderVisibleObject - recorder::Channel subclass (base vtable 0x12c3c78 family);
// name string 0xf0cda0, vptr 0x12d1d98, created by FUN_710088b76c when [parent+0x294] is set.
// extent 0x288 - details: doc/object/Recorder/RecorderVisibleObject.md

namespace object {
struct RecorderVisibleObject {
  uint8_t pad_00[0x1c0];   // 0x000 — vtable ptr (row 0x12d1d98); 0x04-0x1BF unproven
  uint32_t mode_1c0;       // 0x1C0 — init 4
  uint32_t flag_1c4;       // 0x1C4 — init 0
  uint8_t pad_1c8[0xc];    // 0x1C8 - 0x1D3 — unproven
  int32_t index_1d4;       // 0x1D4 — frame index consumed by the read/write thunks
  uint8_t pad_1d8[0xa0];   // 0x1D8 - 0x277 — unproven
  void* ptr_278;           // 0x278 — init 0 (scalar ctor) or copy of [parent+0x278]
  void* target_280;        // 0x280 — observed object ([parent+0x278]); +0xa4 bit0 = visible
};
}  // namespace object
