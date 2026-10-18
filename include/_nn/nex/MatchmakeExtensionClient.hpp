#pragma once

#include <cstdint>

namespace nn::nex {
// MatchmakeExtensionClient — RTTI-named (typeinfo 0x12f5310, name
// "N2nn3nex24MatchmakeExtensionClientE"; base typeinfo 0x12f5990). Only 10
// slots in this row (unrelated rodata strings follow at 0x12f5008). GOT cell
// 0x13155f0 holds vptr-0x10. extent 0x1d8 - details:
// doc/_nn/nex/MatchmakeExtensionClient.md
class MatchmakeExtensionClient {
 public:
  void* mVtable;            // 0x00 - 0x12f4fb0 (cell 0x13155f0 + 0x10)
  uint8_t mPad8[0x58];    // 0x08 - base region (base C1 installs cell
                          //   0x1310bb8 vptr; unproven gap)
  uint8_t m60;            // 0x60 - zeroed by C1
  uint8_t mPad61[0x7];    // 0x61 - unproven gap
  void* mZero68[2];       // 0x68 - zeroed by C1
  void* mZero78;          // 0x78 - zeroed by C1
  uint8_t mPad80[0x8];    // 0x80 - unproven gap
  void* mZero88[2];       // 0x88 - zeroed by C1
  void* mZero98;          // 0x98 - zeroed by C1
  uint8_t mPada0[0x8];    // 0xa0 - unproven gap
  void* mZeroa8[2];       // 0xa8 - zeroed by C1
  uint8_t mPadb8[0x10];   // 0xb8 - unproven gap
  void* mc8;              // 0xc8 - vptr cell 0x1313170 + 0x10 (embedded obj)
  uint8_t mPadd0[0x8];    // 0xd0 - unproven gap
  void* md8;              // 0xd8 - C1 stores this+0xe0
  void* mZeroe0[2];       // 0xe0 - zeroed by C1
  uint8_t mPadf0[0x8];    // 0xf0 - unproven gap
  void* mf8;              // 0xf8 - vptr cell 0x130b4a8 + 0x10
  uint8_t mPad100;        // 0x100 - zeroed by C1
  uint8_t mPad101[0x27];  // 0x101 - unproven gap
  void* m128;             // 0x128 - vptr cell 0x130b4a8 + 0x10
  uint8_t mPad130;        // 0x130 - zeroed by C1
  uint8_t mPad131[0xf];   // 0x131 - unproven gap
  uint8_t mSub140[0x98];  // 0x140 - member subobject (init 0x7100b14df4,
                          //   destroyed by 0x7100a3045c; fills to 0x1d8)
};
}  // namespace nn::nex
