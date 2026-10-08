#pragma once

#include "KartPhysicsBodyMid.hpp"

namespace object {
// Koura (shell) physics body. Vtable .data 0x11b0d98 (GOT cell
// 0x12fb828), ctor 0x7100030d50(w1 = item id ptr), allocation 0x460
// (operator new at 0x35f10). Slot names carry ItemKoura_* evidence.
//
// TogezoBomb (vtable 0x11b0898, n=128) derives from this class — its
// inlined ctor calls 0x30d50.
//
// Ctor own-field writes (after the KartPhysicsBodyMid base ctor):
// secondary vptr at 0x390, byte flags 0x398-0x39b, u32 0x39c, zeros
// 0x3a0-0x3c0, u16/u32 cluster 0x3c0-0x3d2, u64 0x3f8.
//
// Slot semantics (extra 37 slots 0x2c8-0x3e8, item behavior machines;
// the reset/enter slot 0x71000325ac re-initializes the 0x35c-0x3cc
// state cluster from a race-info row [..+0x3e0/+0x3e8] and preserves
// flags 0x399/0x39a). The root's getVelocity3D (slot 0x68) forwards
// to slot 0x28 = pure ret on the root — items override to expose
// their velocity.
//
// State machine block (evidence: bodyRespawnHandlerSlot118_710003387c,
// kouraSlot107HandleStateTwo_710002cdb8, kouraHandleDriverInputSlot28_
// 710002c6c0, kouraDriftAlignSlot111_710002dbc4, kouraSlot117ClampAnd-
// Respawn_710002e768, kouraResetFlagsAndTrailer_710002ce60, kouraReset-
// ChaseSlotsSlot127_710002fd14, clearFlag4ccResetRef_710002cd60,
// kouraGetFloatByState_710002fc78, kouraBuildDriverSetupsSlot90_710002ec0c):
// 0x399 = shell state byte, 2 <-> 3 transitions; state-3 tested with
//   ==3 (kouraGetFloatByState picks table entry by it); basis reset
//   paths save the old value to 0x39a and zero 0x39c;
// 0x39a = saved-state byte (previous 0x399 on every transition);
// 0x39c = hop/lifetime counter, zeroed on transitions; thresholds:
//   >= 0x12d hop reset (slot 111), >= 0x12 driver-hit path (slot 28),
//   >= 0x23 respawn path (slot 117), 0x3c lifetime gate;
// 0x428 = target/hit word, paired with 0x4c8: -1 means unset (set on
//   respawn), only written when negative ("first target wins"); the
//   Koura vtable slot 101 writes the (0x428, 0x4c8) pair only while
//   0x4c8 has bit 31 set;
// 0x470 = effect/media sub-object pointer (FUN_71006a00c4 calls in
//   slots 102/117/127; collector build in slot 90);
// 0x478 = media/sound sub-object pointer (FUN_71006a5b50/6a6238 in
//   slot 117, object calls in slot 127);
// 0x4ac/0x4bc/0x4c0/0x4ce/0x4cf/0x4d0 = trailer cluster: 0x4ac u32 and
//   0x4bc u32 zeroed by the reset slots (0x710002ce60, 0x710002fd14);
//   0x4c0 pointer zeroed by slot 127; 0x4c8 = current driver-slot idx
//   (slot 28 compares the hit idx against it); 0x4ce gate byte (slot 28
//   early-return when set); 0x4cf flag gates the 0x4c4 counter in slot
//   107 and is cleared by 0x710002ce60; 0x4d0 mode byte written by
//   slots 111/127 (also read from the manager cell in slot 118
//   0x710002f6c4).
//
// EXTENT NOTE (contradiction, unresolved): the ctor/operator-new
// allocation at 0x35f10 is 0x460, but kouraResetFlagsAndTrailer_
// 710002ce60 writes +0x4cf and kouraDriftAlignSlot111_710002dbc4 /
// kouraResetChaseSlotsSlot127_710002fd14 write +0x4d0, implying an
// extent >= 0x4d4. The 0x460 claim and the >= 0x4d4 evidence conflict;
// re-prove before changing the extent either way.
class KartPhysicsBodyKoura : public KartPhysicsBodyMid {
 public:
  void* mSecVt390;  // 0x390 — secondary vtable (GOT cell +0x10)
  // Field-usage evidence (item behavior machines):
  // 0x398 = counter (fn 0x7100030ee0 str / 0x7100030f34 ldr);
  // 0x399/0x39a = state flags swapped by the reset slot 0x71000325ac;
  // 0x39c = state counter (slot 0x7100031624/0x7100031cd4);
  // 0x3a0-0x3b8 = four ptrs written by the ctor tail 0x7100030ee0+;
  // 0x3c0-0x3d2 = state/timer u16 cluster (readers 0x7100031d54,
  // 0x7100032fa8, 0x7100034900);
  // 0x3d4-0x3e8 = param block written by fns 0x7100030e4c-0x7100030eac
  // and 0x7100311xx (floats+u32); 0x3f0/0x400/0x404/0x408 state;
  // 0x428-0x45c = config block written by 0x7100031124-0x71000311a4.
  uint8_t mFlag398;    // 0x398 — zeroed on ctor
  uint8_t mFlag399;    // 0x399 — zeroed on ctor
  uint8_t mFlag39a;    // 0x39a — zeroed on ctor
  uint8_t mFlag39b;    // 0x39b — zeroed on ctor
  uint32_t mField39c;  // 0x39c — zeroed on ctor
  uint64_t mField3a0;  // 0x3a0 — zeroed on ctor
  uint64_t mField3a8;  // 0x3a8 — zeroed on ctor
  uint64_t mField3b0;  // 0x3b0 — zeroed on ctor
  uint64_t mField3b8;  // 0x3b8 — zeroed on ctor
  uint32_t mField3c0;  // 0x3c0 — zeroed on ctor
  uint16_t mField3c4;  // 0x3c4 — zeroed on ctor
  char mPad3c6[6];     // 0x3c6 — unproven padding
  uint16_t mField3cc;  // 0x3cc
  uint16_t mField3ce;  // 0x3ce
  uint16_t mField3d0;  // 0x3d0
  uint16_t mField3d2;  // 0x3d2
  char mPad3d4[0x24];  // 0x3d4 (state cluster 0x35c-0x3d2 is reset
                       // by slot 0x71000325ac per race)
  uint64_t mField3f8;  // 0x3f8
  char mPad400[0x60];  // 0x400 — to end (0x460)
};
}  // namespace object
