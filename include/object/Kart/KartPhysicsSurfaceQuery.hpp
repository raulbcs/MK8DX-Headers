#pragma once

// KartPhysicsSurfaceQuery — docblock-only mirror (no struct: interior
// layout beyond the fields below is unproven). Shared manager entry:
// getPhysManager_71007f7ac0(); slot-4 entry = [mgr+0x190+4*8] (double-get).
// Per-core id: TLS cell 0x710012fad88 (value-1, fallback
// nn::os::GetCurrentCoreNumber). Current-pair filter cell: *(void**)0x71012fb3e8.
//
// Proven fields of the query object reached as [body+0x98] (all from
// FUN_7100012090 / FUN_7100012784):
//   +0x30  u32   entry count (0x120c4: ldr w23,[x8,0x30]; loop bound)
//   +0x38  ptr   entry-pointer array, indexed [i*8] (0x120f8-0x12100)
//   +0xa?  bool  vtable slot 0x80 = validity check, called at 0x12810
//          and 0x14720 with the axis getters below gated on its result
// Scale override path: getters 0x71001425c4/0x71001425f0 read the
// manager at [x0+0x48]; when the body's cached axis scale 0xe8-0xf4
// drifts from the fresh value the calc re-applies it via 0x71006a1194.

// perCorePairCollectorTick_71000002b0 (extent 0x84c, ret 0x710070afc): x0 = pair
// collector, buckets +0x38/+0x48/+0x58 (s32 count + ptr array each); classifies
// intrusive-list bodies by byte +0x71 (5..6 or [+0x2e8]==1 / ==3 / ==4) and queues
// two 0x30-byte contact records via FUN_710001a740 / FUN_710000a1c0.

// FUN_710080f660 (extent 0x2ac, ret 0x710080f908): item-box/nearest-object slot
// resolution; x4==0 resolves via slot-4 chain -> [+0x220] -> [+0x190] -> [+0xe0];
// nearest scan seeded from *(0x71012fb7c8) over [engine+0x20+i*0x30].

// FUN_7100814c7c (extent 0x528, ret 0x8151a0; file_list size is a gap-split —
// duplicate variant with extra w4 flag at 0x814efc): item scoring/query used by
// FUN_710002d2b0; gate byte this+0x2e5; per-core query cell = x1 + core*8 + 0x50;
// delegates to surfaceWheelSweepQuery_71007cdc30; returns byte (*cell)->[0x1a] != 0.

// FUN_71008167a4 (extent 0x2cc, ret 0x816970, hit tail 0x816974..0x816a70):
// ray-hit resolution for the physics pair BFS callers; hit items at rec->[0x18] +
// i*0x68 tested by FUN_71007f23c8.

// FUN_7100817730 (extent 0x817730..0x817798): flag-byte clearer over per-kart
// records, holder { u16 count@+0x10, void* data@+0x58 }, stride 0x790; clears
// k*0x790+0x77c and +0x778 (loop step 0xf20).

// surfaceWheelSweepQuery_71007cdc30 (extent 0x23c, ret 0x7cde6c): forwards to
// reg=[this+0x98] when (flags & 0x10000)==0; loop over [this+0x1388] entries of
// ptr array this+0xc8; 0x2c-byte probe record from singletons 0x71012fb148/0x71012fb168.

// surfaceWheelQuery_71007cd8b8 (true extent 0x7cd8b8..0x7cdc30, 888 bytes, ret
// 0x7cdc2c; file_list size correct): registers a wheel/contact object (x6 + w6*0xf0)
// into slot tables *(0x7100130ff80)[w6] and *(0x710012fb170) (stride 0x218); return
// bits: |2 = new attachment, |4 = (vt+0x88 result & 4).

// conditionalHitRecordUpdate_71007c8d84 (extent 0xa0, ret 0x7c8e24; file_list size
// 0x12c is a gap-split — FUN_71007c8e24 at +0xa0 is the next function): conditional
// 0x30-record update via flags [this+0x28] (&7 selects overrides +0x5c/+0x2c/+0x50).

// hitRecordTransformApply_71007c7ee8 (extent 0x7c7ee8..0x7c894f, 2664 bytes):
// (src, dst, scaleVec, mulVec, addVec, idx); 0xf0-stride sub-records, 0x2d0 = 5*0xf0,
// per sub-record gated by ctrl byte src+off+0xdc and u32 src+off+0xd0.

// surfaceHitRegistrar_71007c7b24 (extent 0x7c7b24..0x7c7ee7, 964 bytes): (self, idx);
// u8 flags self+0x28, per-slot state *(self + (idx sxtw << 3) + 0x350); guarded static
// table at 0x710135a008 (guard word 0x710135a878); record = table + idx*0x2d0.

// FUN_71007cc490 (shares file with ContactDataGet 0x71007c8bc8): contact data getter
// by index; base = x0 + w1*0xf0; returns *(base+0xe0+0x368) when *(base+0xe0) non-null.

// FUN_71008d04f8 (0x8d04f8..0x8d05f4): physics closure slice — fixed-point quaternion/
// axis blend between two 0xc-stride vec3 slots; tables 0xf2d380 / 0xf746b8 at cmdIdx*4.

// FUN_71009a37d4 (0x9a37d4..0x9a3900): physics closure slice — apply/restore per-wheel
// state from a save buffer; per wheel i: vt+0x10 restore on self+0x2e0+i*0x48 and
// self+0x120+i*0x70; byte +0x400+i, 0x40 block +0x20+i*0x40, u64 +0x410+i*8.

// FUN_71009b3838 (true extent 0x9b3838..0x9b386c, 52 bytes; extent mismatch in
// phys_remaining.json/file_list, not a gap-split): intrusive sorted-list lookup;
// returns *(u32*)(node+0x18) on key match at +0x10, else 0xfd.

// respawnRayPipeline_7100016340 (true extent 0x7d0, ret 0x16b0c; file_list size 444 is
// a gap-split — unnamed sibling at 0x16b10): kart-body respawn/ray pipeline; tbl =
// body->[0x1b8]; ray gate via FUN_71008167a4; two surfaceWheelQuery_71007cd8b8 rounds
// store results at tbl2 + core*4 + 0x40. OPEN: three cbz paths branch to 0x16b10 past
// the ret (unreachable crash path; manager always populated in practice).

// playerKartContextInit_7100003f08 (extent 0x120; ret 0x7100003fa8 fast / 0x7100004030
// null-mgr): packs id fields into [self+0x0] (bfxil/ubfiz 0x48/0x7f/0x13), u16
// [self+0x104] |= 0x100. OPEN: null-mgr cbz jumps into next function at 0x7100003fac
// (gap-split tail-call crash path) — documented as unreachable.
