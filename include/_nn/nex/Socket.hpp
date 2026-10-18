#pragma once

#include <cstdint>

namespace nn::nex {
// Socket — RTTI-named (typeinfo 0x12e26a0, "N2nn3nex6SocketE"; secondary base
// InetAddress ti 0x12e2680, root ti 0x128c3b0). Primary vptr 0x12e2468
// (cell 0x13141e0), InetAddress vptr 0x12e2428 (cell 0x13141c8) at +0x08.
// extent 0xd8 - details: doc/_nn/nex/Socket.md
class Socket {
 public:
  void* mVtable;          // 0x00 - vptr 0x12e2468 (cell 0x13141e0 + 0x10)
  void* mVtableInet08;    // 0x08 - InetAddress secondary vptr 0x12e2428 (cell 0x13141c8 + 0x10)
  uint8_t mZero10[0x1];   // 0x10 - C2 memset(this+0x10, 0, 0x10)
  uint8_t mType11;        // 0x11 - C2 writes 2 (socket-type code)
  uint8_t mPad12[0x7e];   // 0x12 - unproven gap (C2 writes nothing here)
  uint32_t mZero90;       // 0x90 - C2 zero
  uint8_t mPad94[0x8];    // 0x94 - padding (C2 writes nothing)
  uint32_t mArg9c;        // 0x9c - C2 arg w1 (stp w20,w21,0x9c)
  uint32_t mArgA0;        // 0xa0 - C2 arg w2
  uint8_t mPadA4[0x4];    // 0xa4 - padding
  void* mSubVtableA8;     // 0xa8 - embedded subobject vptr 0x12e2828 (cell 0x13141e8 + 0x10), no RTTI resolved
  void* mSubZeroB0;       // 0xb0 - C2 zeroes; later holds alloc'd sub ptr (0x9d6b20)
  void* mTblB8;           // 0xb8 - entry [0x1361430 + w1*8], dispatched via slot +0x10 (0x9d6b30 region)
  uint32_t mZeroC0;       // 0xc0 - C2 zero
  uint8_t mFlagC4;        // 0xc4 - C2 zero
  uint8_t mFlagC5;        // 0xc5 - C2 writes 1
  uint8_t mPadC6[0x2];    // 0xc6 - padding
  void* mSubVtableC8;     // 0xc8 - embedded subobject vptr 0x12e2918 (cell 0x13141f0 + 0x10), no RTTI resolved
  void* mSubZeroD0;       // 0xd0 - C2 zeroes; later holds ptr (0x9d6e38)
};
}  // namespace nn::nex
