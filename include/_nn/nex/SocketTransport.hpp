#pragma once

#include <cstdint>

namespace nn::nex {
// nn::nex::SocketTransport — RTTI-named (typeinfo 0x12e44e0, si-chain
// RootTransport → RootObject); vptr 0x12e3690 (GOT cell 0x1314678 = vt-0x10);
// ctor 0x9fc41c. Never instantiated alone (abstract in practice).
// extent 0x558 (allocation of derived UDPTransport) - details: doc/_nn/nex/SocketTransport.md
class SocketTransport {
 public:
  void* vtable;       // 0x00 - 0x12e3690, 22 slots; slot0 = D2 0x9fc7e0,
                      //   slot1 = D0 0x9fcfb0 (calls D2, then delete)
  char pad08[0x2c0];  // 0x08..0x2c7 - unproven gap (base RootTransport layout;
                      //   [0x120] ptr freed by D2 if non-null)
  void* mRingBuf2c8;  // 0x2c8 - ring-buffer head ptr (0x70-stride entries)
  void* mRingBuf2d0;  // 0x2d0 - ring-buffer tail ptr
  void* mRingEnd2d8;  // 0x2d8 - ring-buffer end ptr (zeroed by ctor 0x9fc44c)
  char pad2e0[0x28];  // 0x2e0..0x307 - unproven gap
  void* mField308;    // 0x308 - zeroed by ctor
  void* mField310;    // 0x310 - zeroed by ctor
  void* mField318;    // 0x318 - zeroed by ctor
  void* mField320;    // 0x320 - zeroed by ctor
  char pad328[0x8];   // 0x328..0x32f - unproven gap
  void* mField330;    // 0x330 - set from GOT cell by ctor
  void* mField338;    // 0x338 - zeroed by ctor
  char pad340[0xf8];  // 0x340..0x437 - unproven gap (0x340/0x348/0x350 zeroed
                      //   by ctor)
  void* mField438;    // 0x438 - set from GOT cell by ctor
  char pad440[0x8];   // 0x440..0x447 - unproven gap
  void* mList448;     // 0x448 - list object (new'd in ctor, linked +0x8/+0x20)
  void* mField450;    // 0x450 - result of 0xa14df8 in ctor
  char pad458[0xb0];  // 0x458..0x507 - unproven gap
  void* mField508;    // 0x508 - zeroed by ctor (0x9fc664)
  char pad510[0x48];  // 0x510..0x557 - unproven gap
};
}  // namespace nn::nex
