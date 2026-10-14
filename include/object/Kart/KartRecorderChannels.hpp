#pragma once

#include <cstdint>

// Per-kart recorder channel hub — true size 0x2B8; operator new 0x2B8 @ 0x71001704c0, stored
// at KartVehicle+0x88; setup recorderSetupKartStateChannels_71003aed50). recorder::Registry
// subclass registering (via recorderAddChannel_71007ac0cc): self (NULL name, 0x40 copy into
// +0x278), 0x288 u8 p_anti_gravity_rate, 0x280 pair p_state_flag/p_control_flag, quant
// p_xlu_alpha/p_killer_end_ratio/mSteerX/p_start_dash_charge. OPEN: ghost ch15 matches none
// of these — registration call-site unlocated. Runtime: int +0x8, ==2 gate in FUN_7100173140;
// +0x1C4 — int of converter thunks 0x71003afc74/0x71003b0e50/0x71003ac03c (receiver UNCERTAIN).
namespace object {
struct KartRecorderChannels {
  uint8_t pad_00[8];        // 0x00 — vtable ptr (global 0x1307890+0x10)
  uint32_t state08;         //0x08 — int state, ==2 gate in FUN_7100173140
  uint32_t u0c;             //0x0C
  uint8_t pad_010[0x100];   //0x10 — unproven padding
  uint8_t flag110;          //0x110 — setup writes 1
  uint8_t pad_111[0x167];   //0x111 - 0x277 — unproven padding
  void* parent_278;         //0x278 — first pointer of the 0x40-byte param block
                            // copied from the KartVehicle init stack; the setup then registers
                            // this under it: recorderAddChannel(parent, this, 0)
  uint8_t block_280[0x38];  //0x280 — rest of the 0x40-byte param copy
};
}  // namespace object
