#pragma once

#include <cstdint>

namespace nn::nex {
// ObjectThreadRoot — base-subobject vtable of ObjectThread<WebSocketClient,
// void>; vptr 0x12e5928 (n=3, slots 0xa26afc/0xa26b20/0xa26b44); sole
// site 0xa25944 in FUN_7100a25930 (new 0x1118).
// extent 0x1118 (writer alloc / WebSocketClient instantiation)
class ObjectThreadRoot {
 public:
  void* vtable;           // 0x00 — 0x12e5928 for the WebSocketClient instantiation
  uint8_t pad_8[0x1110];  //0x8 — unproven gap
                          // ObjectThread<WebSocketClient> is 0x1118 bytes; interior unmapped.
};
}  // namespace nn::nex
