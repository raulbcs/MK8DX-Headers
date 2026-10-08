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
//
// Additional slot facts (Koura vtable, evidence TUs under
// /Users/raul/projects/mk8dx-400/src/unknown/):
// slot 3 (0x28, kouraDeletingDtor_710002ff7c): same shape as the root
//   deleting dtor (vptr reset from cell 0x71012fb050+0x10, sub-object
//   dtor on 0x100, derived cleanup, operator delete).
// slot 15 (0x88, kouraSlot15ResetMediaState_710002c908): virtual 0xc0
//   on [this+0x480]; FUN_71006a01ac([this+0x470], 0), re-query mode 3
//   and FUN_71006a245c on success (media/effect reset).
// slot 28 (0xf0, kouraHandleDriverInputSlot28_710002c6c0): driver-input
//   /boost handler — boost path (input->0x38->+0x58 == 11) resets the
//   0x399/0x39a ring; driver path compares the hit idx against 0x4c8,
//   early-returns when byte 0x4ce is set, takes the driver-hit branch
//   at 0x39c >= 0x12, raises own slot 118 (vt+0x118).
// slot 34 (0x120, kouraSlot34_selectPtrAndTailcall_710002f500): picks
//   [this+0x388] (or +0x48 when word 0x380 > 3) for FUN_7100019518.
// slot 46 (0x180, kouraSlot46SelectRiderPoseTable_710002cc04): when
//   byte 0x37c is set, selects the pose table ([this+0x388], +0x90
//   when count word 0x380 > 6) for the collector [this+0x278].
// slot 51 (0x1a8, kouraResetWheelContacts_710002cc50): root slot 51
//   (kartBodyReleaseResSlot51_7100014200) then clears 0x154-0x15f.
// slot 64 (0x210, kouraResetAndClearSurfaceSlot64_710002c9a8): root
//   slot 64 (kartBodyResetSlot64_710003127c) then stores -1 in 0x4c8.
// slot 69 (0x238, kouraSlot69LoadRowDirection_710002f1e0): zeroes
//   0x378 and 0x350-0x358; normalizes the driver row's rec+0xa8 vector
//   into rec+0x40/44/48 (row stride 0xf0, flag bit 1) and copies it
//   to 0x1dc-0x1e4.
// slot 70 (0x240, kouraSlot70ApplyMoveOrTailcall_710002f2e4): when
//   state 0x399 == 1 with bytes 0x3c1/0x3c2 set, pushes the wheel
//   setup (0x370/0x368) into the collector and copies 0x388; otherwise
//   tail-calls the root slot 70 (bodyDriverNormalMoveDirSlot70_71000382d8).
// slot 82 (0x2a0, kouraStateSlot82_710002f374): body type 0x71 == 3,
//   player word 0x50 < the count at [this+0x1a8], state 0x399 == 1 and
//   counter 0x39c >= 0xb5 poll the manager (FUN_710080f90c virtual
//   +0x10) and on hit set byte 0x228 = 1, halfword 0x1ee = 0xffff.
// slot 86 (0x2c0, kouraSlot86CreateNamedRequest_710002e8ac): builds a
//   named request pair for [this+0x390].
// slot 88 (0x2d0, kouraSlot88CreateBodyRequest_710002e830): allocates a
//   0x2d8 request object built from [this+0x470] and links it in.
// slot 89 (0x2d8, kouraSlot89BindDualChannels_710002eb18): binds two
//   resource pairs onto 0x98/0xd0 and 0x470/0x478; stores the resolved
//   handle through the pointer at [this+0x490] and lookup words at
//   [this+0x4a0] (split to +4 when word 0x498 > 1).
// slot 90 (0x2e0, kouraBuildDriverSetupsSlot90_710002ec0c): allocates a
//   0x278-byte collector (stored through [this+0x480]) and copies the
//   wheel entry and 7 driver entries into [this+0x278] as root slot 90.
// slot 92 (0x2f0, kouraUpdateChainSlot92_710002eec8): drives the 0x478
//   controller chain (adds float 0x4a8), runs the wheel samplers and
//   the 0x3f0 virtual update, copies the 0xa0-0xd0 transform into the
//   0x470 trailer node and sets its +0x98 dirty bit.
// slot 94 (0x300, kouraSlot94_condStartEndurance_710002f1b8): when
//   state 0x399 == 7 and 0x39c == 1, tail-calls 0x7100421460 on
//   this+0x12c.
// slot 96 (0x310, kouraMoveSlot96_710002f520): flight/motion update —
//   refreshes the basis 0x344-0x34c, integrates position 0x12c-0x138
//   and stores axis velocity into 0x150-0x15c and 0x204-0x20c; 15/30
//   speed picks and the rodata clamp pair apply on race mode 0x7a/0x74.
// slot 99 (0x328, kouraGetFloatByState_710002fc78): float table lookup
//   keyed on state 0x399 == 3.
// slot 100 (0x330, kouraGetFloatByStates_710002fc94): returns 2.0f for
//   states 3/5, else 3.0f.
// slot 102 (0x340, clearFlag4ccResetRef_710002cd60): clears byte 0x4cc
//   and calls FUN_71006a00c4([this+0x470], 0, 0).
// slot 107 (0x368, kouraSlot107HandleStateTwo_710002cdb8): state-2
//   handler — transitions to state 3 when 0x428 != -1, else raises own
//   slot 118; when byte 0x4cf is set increments 0x4c4 and at 0xd2 sets
//   0x3c1 = 1 and transitions to state 1.
// slot 110 (0x380, kouraRespawnPlaceSlot110_710002cee4): respawn/start
//   placement — boost path when byte 0x3c1; resolves the start pair
//   into halfwords 0x3d0/0x3d2; tail places the body: entry position
//   into 0x3d4-0x3dc and 0x12c-0x134, entry u16s into 0x3cc/0x3ce,
//   +0x35e = 1, 0x150 = 0x338 = 20.0f, 0x428/0x4c8 = -1, forward basis
//   0x344-0x34c = start - pos normalized.
// slot 111 (0x388, kouraDriftAlignSlot111_710002dbc4): drift alignment
//   when byte 0x3c1 is clear; the far respawn branch sets 0x4d0 = 1.
// slot 112 (0x390, kouraStarRoastUpdateSlot112_710002debc): star roast
//   update — saves pos into 0x4b0-0x4b8, sets 0x4c0 from the manager
//   cell, copies 0x428 into 0x4c8 when negative, zeroes 0x154-0x15f
//   when the manager is up; jitter-integrates 0x12c-0x134, drives
//   float 0x4bc (+0.15f / -0.3f windows) and transitions 0x399 = 6
//   past tick 0x54.
// slot 115 (0x3a8, kouraStarRoastEndSlot115_710002e2c4): roast end —
//   sets byte 0x4ce when the manager entry age (field +0xe8) reaches
//   0x4c0 + 0x4f; end stage (0x39c >= 4) commits 0x71 = 4 / 0x399 = 7
//   with the ring save, +0x72 = old 0x71, +0x74 = 0, +0x73 = 1; cold
//   path transposes the body transform into 0xa0-0xc8.
// slot 117 (0x3b8, kouraSlot117ClampAndRespawn_710002e768): clamps
//   [this+0x128] into [3.0, 18.0] (+1.5 per tick); at 0x39c >= 0x23
//   calls FUN_71000443d8([this+0x40]); at 0x39c >= 0x3c clears 0x4ce
//   and 0x4cc and respawns.
// slot 118 (0x3c0, kouraItemHandlerSlot118_710002f6c4): item-use
//   handler — byte 0x4cd set fires the item trigger and clears it;
//   otherwise resolves the slot via FUN_710001a34c, distance-gates vs
//   rodata 1500.0f/500.0f and 490000.0f, stores w20 into 0x428 only
//   when negative, sets 0x4cf = 1 on the odd manager-accept path.
// slot 126 (0x400, kouraSlot126UpdateAccelClamp_710002f140): when body
//   type 0x71 == 3, adds own slots 100/101 and clamps [this+0x128]
//   into [1.0, slot-100 result].
// slot 127 (0x408, kouraResetChaseSlotsSlot127_710002fd14): resets the
//   chase pair (0x470/0x478) and zeroes 0x4ac/0x4bc/0x4c0/0x4cc/0x4d0.
// Slot 0-region isa check (kouraGuardedIsaCheck_710002fdc8) matches
//   against three guard-initialised static vtable cells; slot 1 (0x18,
//   kouraStaticDefaultVtableInstance_710002fee8) is the guard-protected
//   static default vtable-holder accessor.
//
// Extra field facts beyond the declared layout: byte 0x360 = spin/drift
//   active flag (root slot 92 clamps 0x128 under it; slot 98 sets it);
//   byte 0x37c = rider-pose-table enable (slot 46); word 0x380/count
//   0x388 pair = pose/driver table (also read by root slots 90/28);
//   float 0x430 = spin approach cap (slot 98); 0x450/0x454/0x458 =
//   spin basis coefficients, 0x45c = spin counter (threshold 0x257,
//   slot 98); 0x3c1/0x3c2 = boost/hop gate bytes (slots 70/82/110/111);
//   0x3d4-0x3dc = start position (slot 110 writes, slot 111 steers by
//   it); 0x4b0-0x4b8 = saved pre-roast position (slot 112).
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
  uint16_t mField3c4;  // 0x3c4 — zeroed on ctor; cleared by the wide
                       // reset (root slot 91)
  char mPad3c6[6];     // 0x3c6 — unproven padding; byte 0x3c1/0x3c2
                       // boost/hop gates, byte 0x3c3 roast-active
                       // (slot 98 phase gate)
  uint16_t mField3cc;  // 0x3cc — packed start/respawn id pair: written
  uint16_t mField3ce;  // 0x3ce — by slot 110 and the root slot 109 BFS
                       // refresh; -1 = unset
  uint16_t mField3d0;  // 0x3d0 — start-slot packed halfwords (slot 110);
  uint16_t mField3d2;  // 0x3d2
  char mPad3d4[0x24];  // 0x3d4 (state cluster 0x35c-0x3d2 is reset
                       // by slot 0x71000325ac per race)
  uint64_t mField3f8;  // 0x3f8
  char mPad400[0x60];  // 0x400 — to end (0x460)
};
}  // namespace object
