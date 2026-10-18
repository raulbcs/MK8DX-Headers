#pragma once

#include <cstdint>

namespace nn::nex {
// TimedQueue<NetworkEmulator::NetworkPacket> — RTTI (ti 0x12e4c80; secondary
// base ResolveMethodContainerInterface ti 0x12e4c98, root 0x128c3b0). vptr
// 0x12e4c48, cell 0x1314820. Slots: drain D0/D1 pair + enqueue + interface
// trio. Intrusive refcounted packet queue.
// extent 0x30 - details: doc/_nn/nex/TimedQueueNetworkPacket.md
class TimedQueueNetworkPacket {
 public:
  void* mVtable;        // 0x00 - vptr 0x12e4c48 (cell 0x1314820 + 0x10)
  void* mSentinel08;    // 0x08 - list sentinel, init &this+0x08 (self ptr)
  void* mHead10;        // 0x10 - first node ptr, init &this+0x08; D-tor drains from here
  uint64_t mCount18;    // 0x18 - node count, init 0; D-tor loop guard
  void* mOwner20;       // 0x20 - owner/device ptr (arg-derived; VirtualInternet keeps two: +0x20/+0x28)
  uint8_t mPad28[0x8];  // 0x28 - padding (only VirtualInternet writes it)
};
}  // namespace nn::nex
