#pragma once

#include <cstdint>

namespace nn::nex {
// nn::nex::UDPTransport — RTTI-named (typeinfo 0x12e4880, si-chain
// SocketTransport → RootTransport → RootObject); vptr 0x12e3e60 (GOT cell
// 0x1314520 = vt-0x10); created only via new 0x558 in factory 0x9f2474.
// extent 0x558 - details: doc/_nn/nex/UDPTransport.md
class UDPTransport {
 public:
  void* vtable;       // 0x00 - 0x12e3e60, 22 slots; slot0 = inherited D2
                      //   0x9fc7e0, slot1 = override D0 0xa191a0 (calls D2,
                      //   then delete); rest identical to SocketTransport
  char pad08[0x550];  // 0x08..0x557 - base SocketTransport layout (see
                      //   SocketTransport.hpp); UDP adds no fields
};
}  // namespace nn::nex
