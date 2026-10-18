#pragma once

#include <cstdint>

namespace nn::nex {
// SharedCounter<SocketDriver::Socket, Socket, SocketDriverDeleter> — RTTI
// (ti 0x12e44a0; bases TransportBufferThreadInterface ti 0x12e4480,
// SharedCounterInterface<Socket> ti 0x12e44c0, root 0x128c3b0). vptr
// 0x12e35a0, cell 0x1314628. 6 slots, all unrecovered.
// extent 0x328 - details: doc/_nn/nex/SharedCounterSocket.md
class SharedCounterSocket {
 public:
  void* mVtable;          // 0x00 - vptr 0x12e35a0 (cell 0x1314628 + 0x10)
  uint8_t mFlag08;        // 0x08 - C2 writes 0
  uint8_t mPad09[0x3];    // 0x09 - padding
  uint32_t mField0c;      // 0x0c - u32 from 0x57b07c helper (guarded by byte at 0x130b528)
  uint8_t mSub10[0xe0];   // 0x10 - member subobject #1 (ctor 0x9f99d8; C2 zeroes +0xf0 inside it)
  uint32_t mZeroF0;       // 0xf0 - C2 zero
  uint8_t mPadF4[0x4];    // 0xf4 - padding
  uint8_t mSubF8[0xe8];   // 0xf8 - member subobject #2, ctor 0x9f99d8
  uint8_t mSub1e0[0xe8];  // 0x1e0 - member subobject #3, ctor 0x9f99d8
  uint8_t mZero2c8[0x8];  // 0x2c8 - C2 init call 0x57ceac(this+0x2c8, 0)
  uint8_t mBuf2d0[0x8];   // 0x2d0 - C2 init 0x574a70(this+0x2d0.., 0x8000, 0)
  void* mFp2d8;           // 0x2d8 - fn ptr cell 0x1314888 + 0x10 (= 0xa1f744)
  uint8_t mPad2e0[0x40];  // 0x2e0 - unproven gap
  void* mZero320;         // 0x320 - C2 zero
};
}  // namespace nn::nex
