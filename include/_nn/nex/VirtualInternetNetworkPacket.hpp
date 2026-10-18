#pragma once

#include <cstdint>

namespace nn::nex {
// VirtualInternet<NetworkEmulator::NetworkPacket> — RTTI (ti 0x12e52e0; base
// TimedQueue<NetworkPacket> ti 0x12e4c80). vptr 0x12e52a8, cell 0x1314818.
// Ctor inlined into NetworkEmulator-device ctor 0xa17660 (subobjects +0x118,
// +0x180). TimedQueue + two owner ptrs.
// extent 0x30 - details: doc/_nn/nex/VirtualInternetNetworkPacket.md
class VirtualInternetNetworkPacket {
 public:
  void* mVtable;     // 0x00 - vptr 0x12e52a8 (cell 0x1314818 + 0x10)
  void* mSentinel08; // 0x08 - list sentinel, init &this+0x08
  void* mHead10;     // 0x10 - first node ptr, init &this+0x08
  uint64_t mCount18; // 0x18 - node count, init 0
  void* mOwner20;    // 0x20 - arg-derived ptr (device+0xa0)
  void* mOwner28;    // 0x28 - second arg-derived ptr (device+0xa0); written last (+0x1a8 in second instance)
};
}  // namespace nn::nex
