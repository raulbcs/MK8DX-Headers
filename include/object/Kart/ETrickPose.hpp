#pragma once
#include <cstdint>

namespace object::Kart {
// Trick pose ids — stored at KartVehicle+0x20C by the trick start
// (FUN_7100175f5c). Even/odd pairs are mirrored (spin direction from the
// stick sign). Window frames per pose: 4 → 30, 5/6 → 70 or 40, 7/8 → 36
// or 40, 2/3 → 40. Anim ids 0xE/0xA/0x10 map to the jump-action voices
// VOICE_JUMP_ACTION_SA (14) / VOICE_JUMP_ACTION_SB? (10) / VOICE_JUMP_ACTION
// (16) — voice enum at rodata 0xeda9c3.
enum ETrickPose : uint32_t {
  TrickPose_FlipA = 2,        // 40f window; mirror pair with 3
  TrickPose_FlipB = 3,
  TrickPose_Spin = 4,         // 30f window (plain jump action)
  TrickPose_SpinA5 = 5,       // 70f or 40f window
  TrickPose_SpinA6 = 6,       // mirrored
  TrickPose_SpinB7 = 7,       // 36f or 40f window
  TrickPose_SpinB8 = 8,       // mirrored
  TrickPose_Special23 = 0x23, // paired with a 35f sub-state timer
};
}  // namespace object::Kart
