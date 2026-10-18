#pragma once

#include <cstdint>

namespace nn::nex::ClientWebSocketDriver {
// nn::nex::ClientWebSocketDriver::ClientWebSocket — RTTI-named (typeinfo
// 0x12e2660, si-type with base nn::nex::SocketDriver::Socket); vptr 0x12e2350
// (GOT cell 0x13141c0); ctor 0x9d57e4.
// extent >= 0x178 (lower bound, unverified) - details: doc/_nn/nex/ClientWebSocket.md
class ClientWebSocket {
 public:
  void* vtable;       // 0x00 - 0x12e2350 (cell 0x13141c0 + 0x10); post-inc
                      //   store also writes the same vptr at 0x10
  char pad08[0x138];  // 0x08..0x13f - unproven gap (includes second vptr copy
                      //   at 0x10)
  void* mSocket140;   // 0x140 - Socket subobject vptr 0x128c698 (cell
                      //   0x130b4a8 + 0x10); base ctor 0x5790b4
  char pad148[0x28];  // 0x148..0x16f - unproven gap
  void* mSocket170;   // 0x170 - second Socket subobject, same vptr cell
                      //   0x130b4a8; base ctor 0x5790b4
};
}  // namespace nn::nex::ClientWebSocketDriver
