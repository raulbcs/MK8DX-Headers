#pragma once

#include <cstdint>

// Per-kart recorder channel hub — size 0x2B8, proven by operator new(0x2B8)
// in the KartVehicle init (v400 0x71001704c0, stored at KartVehicle+0x88;
// setup 0x71003aed50 = recorderSetupKartStateChannels_71003aed50, see
// recorder/Recorder.hpp). A recorder::Registry subclass: registers child
// channels by name via recorderAddChannel_71007ac0cc(this, child, name) —
// the camera float channels "at"/"up"/"back"/"dist"/"fovy" — plus a
// recorder::Binder (0x288) and a quantized-float channel (0x280).
// Previously misnamed "KartPathJob".
//
// recorderSetupKartStateChannels_71003aed50 registration order (
// decomp; quant params = factory args min,max,step):
//   1. self        — NULL name, memcpy 0x40 of [x20+0] into +0x278 block
//   2. 0x288 u8    — p_anti_gravity_rate (0xee5e3a); +0x1f8 = 1/128,
//                    +0x284 = 255.0
//   3. 0x280 pair  — p_state_flag (0xee5e4e); type pair {4,4}
//   4. quant       — p_xlu_alpha (0xee5e5b); (0, 1, 0.1)
//   5. 0x280 w2    — p_control_flag (0xee5e67)
//   6. quant       — p_killer_end_ratio (0xee5e76); (0, 1, 0.1)
//   7. quant       — mSteerX (0xee5e89); (-1, 1, 0.1)
//   8. quant       — p_start_dash_charge (0xee5e91); (-1, 1, 0.05;
//                    tokens 0..40, idle = 20)
// Ghost channel ch15 (lap counter 3->2->1->0) matches NONE of these —
// its registration call-site is elsewhere (unlocated).
//
// Runtime cross-evidence: FUN_7100173140 (Path2Gate cluster) reads the int
// at +0x8 (==2 gate).
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
