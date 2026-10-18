#pragma once

#include <cstdint>

// recorder::MatrixChannel — quantized recorder channel (16 values), created per-index by the
// channel-array loop in setup FUN_71007b100c and registered under a NULL name.
// Initialized with recorderBinderCtor_71007aae24 after `new 0x298`; vptr cell 0x130fb20.
// extent 0x298 - details: doc/recorder/MatrixChannel.md

namespace recorder {
class MatrixChannel {
 public:
  void* mVtable;           // 0x00 — 0x12c4538 (GOT cell 0x130fb20 holds 0x12c4528; vptr = cell+0x10)
  uint8_t mPad8[0x1b8];    // 0x08 — unproven padding
  uint32_t mNumValues;     // 0x1c0 — 0x10 (store 0x700000010, 0x7b12e0)
  uint32_t mTokenBytes;    // 0x1c4 — 7 (same store; token-size reading per QuantChannel doc,
                           //        unverified for this class)
  uint8_t mPad1c8[0xb0];   // 0x1c8 — unproven padding
  void* mOwner;            // 0x278 — setup arg x19 (owning object), 0x7b12c0
  void* mPeer280;          // 0x280 — [owner+0x278] (first channel of the owner), 0x7b12c8
  uint32_t mChannelIndex;  // 0x288 — loop counter (w23), 0x7b12d0
  uint8_t mFlag28c;        // 0x28c — zeroed, 0x7b12d4
  uint8_t mPad28d[0x3];    // 0x28d — unproven padding
  float mThreshold290;     // 0x290 — 0.1f (0x7b12d8)
  float mThreshold294;     // 0x294 — 0.1f (0x7b12dc)
};
}  // namespace recorder
