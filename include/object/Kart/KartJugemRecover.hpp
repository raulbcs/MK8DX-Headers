#pragma once
#include <cstdint>

namespace object {
class LapRankChecker;  // layout unmapped

// Lakitu (Jugem) recover handler. Size 0x1D8, held at KartVehicle+0x90.
// Respawn applies the +0x88 matrix via generic set-pose 0x7100175974 —
// no dedicated warp function.
class KartJugemRecover {
 public:
  void* vtable0;             // 0x00 — vtable pair (multiple inheritance)
  void* vtable8;             // 0x08
  uint8_t playerByte10;      // 0x10 — player-id init (overwritten with 9)
  uint8_t state11;           // 0x11 — recovery state: 1 tick early-out, 4 sink done,
                             //        8 = penalty-count query (10 - [+0x14])
  uint8_t state11Copy12;     // 0x12 — ctor copy of +0x11
  uint8_t spawnCommitted13;  // 0x13 — set when the spawn transform is committed
  int32_t spinFrames14;      // 0x14 — spin/wrong-way frame counter; commit threshold
                             //        0x29 (mode 0x7a) / 0xb (else)
  void* self18;              // 0x18 — self pointer
  void* dispTable20[3];      // 0x20/+0x28/+0x30 — three char[0x90] dispatch tables
                             //        (9 fn-ptrs each)
  uint8_t state38;           // 0x38 — state byte: 0 idle, 1 gates +0x13, 4 sink finish;
                             //        set from owner+0xe7 (4 or 7)
  uint8_t pad39[7];          // 0x39 - 0x3F — unproven padding
  void* obj40;               // 0x40
  void* handle48;            // 0x48
  void* owner50;             // 0x50 — owner KartVehicle
  void* model58;             // 0x58 — optional Jugem obj model/animator
  void* obj60;               // 0x60 — 0x48-byte sub-object
  void* lapCounter68;        // 0x68 — stores 5400 at +8; magic-index accessors
                             //        0xf48c3000 (lap counter) / 0xf4903000 (sink table)
  uint16_t playerIdx70;      // 0x70
  uint16_t frameCt72;        // 0x72 — frame counter
  int32_t sentinel74;        // 0x74 — -1 init; bit31 checked
  float stuckTimer78;        // 0x78 — stuck/approach timer: += 0.1, clamp <= 1.0,
                             //        caps 13.0 or 40.0 (team branch). Consumer UNCERTAIN
  uint16_t respawnId7c;      // 0x7c — respawn point id (-1 unset; mode table
                             //        idx*0x70 -> +0x58 -> idx*0x790)
  uint16_t respawnId7e;      // 0x7e — second respawn point id
  uint16_t mirror80;         // 0x80 — per-tick mirror of +0x7c
  uint16_t mirror82;         // 0x82 — per-tick mirror of +0x7e
  uint16_t animId84;         // 0x84 — anim id (-1 init)
  uint16_t animId86;         // 0x86 — anim id (-1 init)
  float respawnMat88[12];    // 0x88 — respawn transform matrix (target pose); written
                             //        from the KartVehicle+0x350 OOB query result
  float matB8[12];           // 0xb8 — matrix 2
  float matE8[12];           // 0xe8 — matrix 3; the pose handed out by query 0x71001459fc
  uint8_t pad118[8];         // 0x118 - 0x11F — mirrors of +0xc4/+0xcc
  uint32_t fromGot120;       // 0x120 — from GOT 0x12fb150 obj (ctor)
  uint8_t pad124[0xc];       // 0x124 - 0x12F — unproven padding
  uint8_t flags130;          // 0x130 — bit5 spin/penalty active; bit6 sound/obj trigger;
                             //        bit7 model visible gate; bit0
  uint8_t flags131;          // 0x131 — bit0 -> scale fn arg 1; bit1 -> skip branch
  uint8_t pad132[2];         // 0x132 - 0x133 — unproven padding
  uint32_t modeBits134;      // 0x134 — mode/rule bitfield: config [x0+8]==3 &&
                             //        [x0+0xc]=={1,2,3,4} -> bits 1/2/4/8; ==4 -> bit6;
                             //        bits 0x10/0x20 = (low nibble != 0)
  uint8_t pad138[4];         // 0x138 - 0x13B — unproven padding
  uint32_t const13c;         // 0x13c — constant f32 bits 0x126f3b83
  float workMat140[12];      // 0x140 — working copy of the respawn matrix
                             //        (distance-to-target check)
  float sinkPair170;         // 0x170 — int-scaled sink value
  float sinkTimer174;        // 0x174 — += 0.2; limit 3599
  uint8_t zero178[4];        // 0x178 - 0x17B — unproven padding
  uint32_t lapValue17c;      // 0x17c — [[+0x68]+0xf4903000] lap value
  uint32_t sinkCountdown180; // 0x180 — sink countdown (lap value + 60 frames)
  uint8_t pad184[0xc];       // 0x184 - 0x18F — unproven padding
  float mat190[12];          // 0x190 — 4th matrix
  uint32_t resCount1c0;      // 0x1c0 — count of 0x30-byte resource entries
  uint32_t pad1c4;           // 0x1c4 — unproven padding
  void* resList1c8;          // 0x1c8 — array
  uint32_t pair1d0;          // 0x1d0 — (20,120) normally; (0,30) if owner [+0x1cc] bit2
  uint32_t pair1d4;          // 0x1d4
                             // extent 0x1d8

  // Respawn triggers: (1) fall-out OOB — KartVehicle mAirFramesForJugem
  // (+0x258) > 300; counter force-reset while any recovery is active.
  // (2) stuck — +0x78 proximity timer, threshold (2.5*speed^2)^2.
  // (3) sink/spin — +0x14 >= 0x29 (mode 0x7a) / 0xb else.
  // (4) wrong-way (JugemObjReverse) — UNCERTAIN, sub-object not located.
  // Penalty: if +0x130 bit5, tick calls 0x7100172f54(owner, 1) after the
  // pose call — arg 1 semantics UNCERTAIN.
};
}  // namespace object
