#pragma once

#include <cstdint>

namespace nn::nex {
// VirtualModem<NetworkEmulator::NetworkPacket> — RTTI (ti 0x12e5280; base
// TimedQueue<NetworkPacket> ti 0x12e4c80). vptr 0x12e5248, cell 0x1314810.
// Ctor inlined into NetworkEmulator-device ctor 0xa17660 (subobject +0xe8).
// extent 0x30 - details: doc/_nn/nex/VirtualModemNetworkPacket.md
class VirtualModemNetworkPacket {
 public:
  void* mVtable;        // 0x00 - vptr 0x12e5248 (cell 0x1314810 + 0x10)
  void* mSentinel08;    // 0x08 - list sentinel, init &this+0x08
  void* mHead10;        // 0x10 - first node ptr, init &this+0x08
  uint64_t mCount18;    // 0x18 - node count, init 0
  void* mOwner20;       // 0x20 - arg-derived ptr (device+0xa0 passed by ctor 0xa17660)
  uint8_t mPad28[0x8];  // 0x28 - padding (extent 0x30)
};
}  // namespace nn::nex
