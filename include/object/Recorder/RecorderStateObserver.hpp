#pragma once

#include <cstdint>

// RecorderStateObserver - recorder::Channel subclass (base vtable 0x12c3c78 family);
// name string 0xf0ce29, vptr 0x12d2360, out-of-line C1 0x88c5a4 storing an observed u8 at +0x9.
// extent 0x288 - details: doc/object/Recorder/RecorderStateObserver.md

namespace object {
struct RecorderStateObserver {
  uint8_t pad_00[0x1c0];   // 0x000 — vtable ptr (row 0x12d2350); 0x04-0x1BF unproven
  uint32_t mode_1c0;       // 0x1C0 — init 4
  uint32_t flag_1c4;       // 0x1C4 — init 1
  uint8_t pad_1c8[0xc];    // 0x1C8 - 0x1D3 — unproven
  int32_t index_1d4;       // 0x1D4 — frame index consumed by the read/write thunks
  uint8_t pad_1d8[0xa0];   // 0x1D8 - 0x277 — unproven
  void* ptr_278;           // 0x278 — init 0
  void* target_280;        // 0x280 — observed object (C1 arg x1); its u8 +0x9 is mirrored
};
}  // namespace object
