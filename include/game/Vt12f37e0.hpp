#pragma once

#include <cstdint>

namespace game {
// Unnamed parameter-definition node (ParamNode family: slots 3-8 are the
// shared paramNode stubs 0x647f48..0x647f6c). Ctor registers named
// properties "type", "形状" (shape), "range", "変化幅" (variation width).
// extent 0xe0 (in-place at +0x1378 of an aggregate, next member inited at
// +0x1458) - details: doc/game/Vt12f37e0.md
class Vt12f37e0 {
 public:
  void* vtable;           // 0x00 - vptr 0x12f37e0 (GOT cell 0x1315320 holds
                          // 0x12f37d0 = vptr-0x10; off-top 0, no typeinfo)
  uint8_t mPad8[0x28];    // 0x08 - unproven gap
  void* mMember30;        // 0x30 - property node (init 0x662f30/0x662f70 pair)
  uint8_t mPad38[0x10];   // 0x38 - unproven padding
  uint32_t mField48;      // 0x48 - ctor writes 0
  uint8_t mPad4c[0x4];    // 0x4c - unproven padding
  void* mMember50;        // 0x50 - property node
  uint8_t mPad58[0x10];   // 0x58 - unproven padding
  uint64_t mField68;      // 0x68 - 1.0f/1.0f float pair
  void* mMember70;        // 0x70 - property node
  uint8_t mPad78[0x10];   // 0x78 - unproven padding
  void* mMember88;        // 0x88 - pointer written by ctor
  void* mMember90;        // 0x90 - property node
  uint8_t mPad98[0x20];   // 0x98 - unproven padding
  uint32_t mFieldb8;      // 0xb8 - ctor arg w2
  uint8_t mPadbc[0x24];   // 0xbc - unproven padding
};
}  // namespace game
