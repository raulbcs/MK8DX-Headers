#pragma once

#include <cstdint>

// nn::nex::NgsFacade - RTTI'd (typeinfo record 0x12e7d20, base record
// 0x12e7730 "nn::nex::RendezVous"). extent 0x270 - details:
// doc/object/NgsFacade.md

namespace object {

class NgsFacade {
 public:
  void* vtable;        // 0x00 - installed 0x12e79e8 (GOT cell 0x1314da0
                       //        holds 0x12e79d8 = vptr-8); ctor site
                       //        0xa42e5c, virtual site 0xa430c4
  char mPad08[0x1b0];  // 0x08..0x1b7 - nn::nex::RendezVous base init
                       //        (FUN_7100a3eccc); see NexRendezVous.md
  void* mPtr1B8[2];    // 0x1b8 - zeroed by ctor
  void* mPtr1C8;       // 0x1c8 - zeroed by ctor
  void* mList1D0;      // 0x1d0 - intrusive list node {this, x} stp'd late
  uint64_t mConst1D8;  // 0x1d8 - 0xc800000000 by ctor
  char mPad1E0[0x28];  // 0x1e0..0x1ff - semaphore-ish, init 0x5788e0 w/
                       //        (0x10001, sp); +0x1f8 word, +0x1fc half,
                       //        +0x1fe byte zeroed
  void* mPtr208;       // 0x208 - x24 by ctor, byte +0x210 zeroed
  char mPad210[0x8];   // 0x210..0x217 - unproven gap
  void* mPtr218[2];    // 0x218 - cell/ptr pair stored +0x220/+0x228
  char mPad228[0x8];   // 0x228..0x22f - unproven gap
  uint16_t mHw230;     // 0x230 - zeroed by ctor
  char mPad232[0x6];   // 0x232..0x237 - unproven gap
  void* mPtr238;       // 0x238 - x24 by ctor
  char mPad240[0x10];  // 0x240..0x24f - byte 0x240 zeroed, cell +0x250
  void* mPtr250;       // 0x250 - cell vptr by ctor
  void* mPtr258;       // 0x258 - x25 by ctor
  void* mPtr260;       // 0x260 - cell vptr by ctor
  void* mObj268;       // 0x268 - new'd 0xa8-byte object (site 0xa42fb4)
};

}  // namespace object
