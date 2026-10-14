#pragma once

// KartPhysicsSurfaceQuery — docblock-only mirror of the per-core pair
// collection + surface/wheel query pipeline (decomp facts, no code).
// Shared manager entry: getPhysManager_71007f7ac0(); the slot-4 entry is
// [mgr+0x190+4*8] (double-get pattern). Per-core id source: TLS cell
// 0x710012fad88 (value - 1, fallback nn::os::GetCurrentCoreNumber).
// Current-pair filter cell: *(void**)0x71012fb3e8 (packed {u16,u16}).

// perCorePairCollectorTick_71000002b0 (extent 0x84c, ret 0x710070afc;
// per-core job entry, no direct bl callers). x0 = pair collector with
// three buckets at +0x38/+0x48/+0x58 (s32 count + ptr array each).
// mgr2 = getPhysManager -> [0x190+4*8]; x21 = mgr2->[0x240]. Classifies
// bodies from the intrusive list (node link +0x8, end sentinel
// head+0x68, body = node->[0x10]; walk via FUN_7100003a20(mgr2, &core),
// passes 0..0x12) into bucket 0 (body byte +0x71 in 5..6, or
// [+0x2e8]==1), bucket 1 (+0x71==3) or bucket 2 (+0x71==4). Pair test
// FUN_71000013e0; on contact (gated by FUN_71007cf128 transforms) the
// response hooks dispatch cand->vt[0x110] for type pairs (4,0)/(1,0)
// when cand->[0x58]==0xb or ([0x58]<=0x10 && (1<<v)&0x482010000), and
// symmetrically (0,4)/(0,1) for the body side; two 0x30-byte contact
// records (body side from [x21+0x40]->[0x10]+0x3c, negated floats for
// the cand side) are initialized by FUN_710001a740 and queued via
// FUN_710000a1c0(mgr2->[0x240]->[0xf8], &recBody, &recCand). Hit key
// dedup through FUN_71008629f4(body->[0x5c]) (default 1 when mgr bit3
// of +0x24 clear); sweep loops re-check via FUN_71007c4d90 /
// FUN_71007c53b8 with callback FUN_710019cfb8.

// FUN_710080f660 — item-box/nearest-object slot resolution (extent
// 0x2ac, ret 0x710080f908; called from FUN_710080f51c). Args (pos vec3,
// packed id, filter, flags, nullable mgr x4, extra records x5/x6,
// vec s0/s1). x4 == 0 resolves via slot-4 chain -> [+0x220] -> [+0x190]
// -> [+0xe0]; engine via the same chain -> [+0x100] (vtable slot +0x10
// gate). Gate FUN_710002d2b0(engine, pos, id, filter, flags&1, ...):
// scan result is discarded when hi16 of the score != 0xffff. Nearest
// scan: seed = *(0x71012fb7c8); best = seed>>16; players at
// [engine+0x20+i*0x30], entries rec[+0x20][j], squared dist of
// e+0xc..0x14 vs pos; min d below *(0xed54a00) wins. Pack: (best_lo &
// 0xffff) | ((best_hi & 0xffff) << 16).

// FUN_7100814c7c — item scoring/query used by FUN_710002d2b0 (extent
// 0x528, ret 0x8151a0; file_list size 680 is a gap-split — a duplicated
// variant with an extra w4 flag starts at 0x814efc). Gate: byte
// this+0x2e5 == 0 -> return 0. base = this+0x90 (falls back to this+0x9c
// when equal to *(0x71012fb148)); v = base * 5.0f; corner = v +
// *(vec3*)(this+0xc); dist = |(v + x2) - corner|; skip when dist +
// *(float)0xed500934 < *(float)0xed5008e0. Per-core query cell =
// x1 + core*8 + 0x50 (post-increment); record init zeroes [0x00]/[0x08],
// fills [0x0c..0x17] from *(0x71012fb168), sets [0x1c]=[0x28]=0x7f7fffff
// (FLT_MAX). Surface sweep delegated to surfaceWheelSweepQuery_
// 71007cdc30(cand, seed, corner, dir, 4, 0x7fff0000, id2) where id2
// comes from the slot-4 chain ([0x218]->[0x58], entry table +0x48,
// stride 0x78, id = x1->[0x68]). Returns byte (*cell)->[0x1a] != 0.

// FUN_71008167a4 — ray-hit resolution for the physics pair BFS callers
// (extent 0x2cc, ret 0x816970, hit tail 0x816974..0x816a70). cur =
// *(u32*)*(void**)0x71012fb3e8; q = FUN_710080fe3c(), miss when virtual
// q->vt+0x10(q) == false. res = perCorePairBfs_710081a51c(q, b, &probe,
// -1, 0,0,0,0) with probe zeroed when equal to cur; page = q->[0x20] +
// (res & 0xffff) * 0x70, hit count u16 at page+0x12; items rec->[0x18] +
// i*0x68 tested by FUN_71007f23c8; hit dir = t*(pos - o) - pos with
// o = (*item->[0x48])->vt floats +0x20..0x28, normalized, replaced by
// -pos when len < **(float**)0x71012fb158.

// FUN_7100817730 — flag-byte clearer over per-kart stride records
// (extent 0x817730..0x817798; called by FUN_7100819a20 / FUN_710081a474
// / FUN_710081aa54 / FUN_710081ad6c). Holder { u16 count@+0x10, void*
// data@+0x58 }, 0x790-byte stride per kart; start offset = (idx < 3) ?
// idx : 0; clears data + k*0x790 + 0x77c and the paired byte at
// k*0x790 + 0x778 (loop step 0xf20, x2-unrolled).

// surfaceWheelSweepQuery_71007cdc30 (extent 0x23c, ret 0x7cde6c).
// (this = physics world registry, info, origin, dir, flags, kind,
// packed). When (flags & 0x10000) == 0 the query is forwarded first to
// reg = [this+0x98] (guards FUN_71007c7260(reg, 0, kind), virtual
// reg->vt+0x90). Main loop over [this+0x1388] entries of the pointer
// array at this+0xc8: cooldown skip when FUN_710087ea34() and packed
// halves differ from *(0x71012fb3e8) and FUN_710019a838(obj->[0x368],
// &packed); radius r from [info+0x1a]/sqrtf([info+0x1c]) or v0;
// center = origin + 0.5f*r*dir; gates FUN_71007c7260 / FUN_71007c7280;
// 0x2c-byte probe record built from singletons 0x71012fb148/0x71012fb168
// (with u32 0x7f7fffff sentinels); virtual obj->vt+0x90 probe with
// v0 = 2*half; on hit byte rec+0x1a: conditionalHitRecordUpdate_
// 71007c8d84(obj, info, &rec) and info->[0x20] = obj.

// surfaceWheelQuery_71007cd8b8 (true extent 0x7cd8b8..0x7cdc30, 888
// bytes, ret 0x7cdc2c; file_list size is correct, not a gap-split).
// Called by the physics core (bodyPhysicsCoreSlot52_71000142d0, w4 =
// 0x145 | slope bit<<22). 7 register args + 3 stack slots (first stack
// slot unused/alignment). Registers a wheel/contact object (x6 +
// w6*0xf0) into the global slot table *(0x7100130ff80)[w6] and the
// per-core candidate table *(0x710012fb170) (stride 0x218, entry+0x200
// cleared). Flags word: w4 OR-ed with 0x80000 if !x2, 0x100000 if !x3,
// 0x200000 if !x7, 0x20000 when (w4 & 0xc)==0, low 2 bits forced to 01
// when (w4 & 0x20)==0. Candidates: primary from registry[idx*8+0x98]
// (when flag 0x10 clear) plus loop over registry[idx*0x320+0xc8] when
// registry[idx*4+0x1388] >= 1; x7 filter adds a virtual vt+0xa0 gate.
// Return bits: |2 = new attachment (vt+0x88 hit with bit0 set — also
// surfaceHitRegistrar_71007c7b24(candidate, w6) and candidate stored to
// obj+0xe0), |4 = (vt+0x88 result & 4).

// conditionalHitRecordUpdate_71007c8d84 (extent 0xa0, ret 0x7c8e24;
// file_list size 0x12c is a gap-split — FUN_71007c8e24 at +0xa0 is the
// next function). Conditional 0x30-record update: tmp = stack copy of
// src; flags = [this+0x28]; if (flags & 7) != 0 the FUN_71007c8e24
// overrides use (flags&1) ? this+0x5c, (flags&2) ? this+0x2c,
// (flags&4) ? this+0x50; memcpy(dst, tmp, 0x30) only when
// (float)[tmp+0x1c] < [dst+0x1c] (unordered -> skip).

// hitRecordTransformApply_71007c7ee8 (extent 0x7c7ee8..0x7c894f, 2664
// bytes, no gap-split). Per-index state applier called by the hit
// registrar with a fresh 0x2d0-byte record from the static table
// 0x710135a008 + idx * 0x2d0. Signature (from caller FUN_71007c7b24):
// (src, dst, scaleVec, mulVec, addVec, idx); src/dst arrays of
// 0xf0-stride sub-records, 0x2d0 = 5 * 0xf0. memcpy(dst, src, 0x2d0)
// unconditional; scaleVec applies gated per sub-record by ctrl byte
// src+off+0xdc and u32 src+off+0xd0: ctrl&3 -> floats +0x04..+0x18
// *= scale, flags |= 1; +0x70/+0xa0 abs-scale; ctrl bit3 -> +0xa8..0xb0
// and +0xb4..0xbc, flags |= 2 | 4; bit4 -> +0x4c..0x54 and +0x94..0x9c;
// bit5 -> +0x78..0x80. mulVec (three vec3 rows) selects row copies
// +0x40/+0x88, +0xa8/+0xb4 and a FUN_71008d4b4c call (flags |= 1).

// surfaceHitRegistrar_71007c7b24 (extent 0x7c7b24..0x7c7ee7, 964
// bytes). Given (self, idx): u8 flags at self+0x28 — returns when
// (flags & 7) == 0. Per-slot state = *(self + (idx sxtw << 3) + 0x350).
// Guarded static table (guard word 0x710135a878) built at 0x710135a008
// (~0x7ec bytes) from the singleton *(0x71012fb148): repeated {u32
// size@[+8], void* ptr@[+0]} pairs at table+0x58/0x60, +0x148/0x150,
// +0x238/0x240, +0x328/0x330, +0x418/0x420, +0x508/0x510, +0x5f8/0x600,
// +0x6e8/0x6f0, +0x7d8/0x7e0, interleaved with groups of six zeroed
// pointer slots (stride 8; last slot of the final group at +0x7e4 gets
// the singleton ptr). Record = staticTable + idx * 0x2d0; calls
// hitRecordTransformApply_71007c7ee8(slotState, record, (flags&1) ?
// self+0x5c, (flags&2) ? self+0x2c, (flags&4) ? self+0x50, idx), then
// tail-calls FUN_71007c8950(*(0x710130ff80 + idx*8), record, idx)
// (wheel-object registry array 0x710130ff80).

// FUN_71007cc490 — contact data getter by index (TU shares its file
// with ContactDataGet 0x71007c8bc8). base = x0 + w1*0xf0; returns
// *(base+0xe0 + 0x368) when the pointer at base+0xe0 is non-null,
// else NULL.

// FUN_71008d04f8 (0xfc bytes, 0x8d04f8..0x8d05f4) — physics closure
// slice: fixed-point quaternion/axis blend between two 0xc-stride vec3
// slots. (base, cmdIdx, value): v = value * *(float)0xed5900; packed =
// fcvtzs(v); hi = packed >> 24, lo = packed & 0xffffff; idxA/idxB from
// i32 tables 0xf2d380 / 0xf746b8 at cmdIdx*4; t = lo * *(float)
// 0xed5904; axes = *(char**)0x71012fb160 + hi * 16 (four floats per
// entry); dst = base + idxA*0xc, src = base + idxB*0xc; blended weight
// = axes[0] + t*axes[1]; dst += src * weight, src -= dst * (t*axes[3]).

// FUN_71009a37d4 (0x18c bytes, 0x9a37d4..0x9a3900) — physics closure
// slice: apply/restore per-wheel state from a save buffer (self, src;
// src == null -> return). memcpy(self, src, 0x20); per wheel i in 0..3:
// virtual vt+0x10 restore on self+0x2e0+i*0x48 and self+0x120+i*0x70;
// byte +0x400+i, 0x40-byte block at +0x20+i*0x40 and u64 +0x410+i*8
// copied; virtual vt+0x20(obj, 0x4000000) flags both. Bytes +0x404..0x406
// and u32 +0x408 copied after the loop.

// FUN_71009b3838 (true extent 0x9b3838..0x9b386c, 52 bytes, ret
// 0x9b386c; 48 bytes in phys_remaining.json / 56 in file_list — extent
// mismatch, not a gap-split). Intrusive sorted-list lookup, no direct
// bl callers (vtable/indirect). Self-terminated circular list (next at
// +8, first node at +8 of the head); returns *(u32*)(node+0x18) when
// *(node+0x10) == key, else 0xfd (253) as the not-found id.

// respawnRayPipeline_7100016340 — kart-body respawn/ray pipeline (true
// extent 0x7d0, ret 0x16b0c; file_list size 444 is a gap-split — an
// unnamed sibling starts at 0x16b10). (body, packed spawn record).
// tbl = body->[0x1b8]; ray gate byte [0x178] resolves via
// FUN_71008167a4 (result to byte [0x179], out dir at 0x180..0x188) or
// -*(0x71012fb150). Decodes a packed i48 trio from rec+0x28 (fields
// 0/22/43, 21-bit payloads, scaled by *(0x710ed5008ac)); back = dir *
// 5.0f; rcMgr tag = (getRaceCheckManager_710087fcd0()->[0x1a0] == 0x20)
// ? 0xfbff0000 : 0xfbff0400; per-core query cell = tbl + core*8 + 0x50
// (same init as FUN_7100814c7c); surfaceWheelSweepQuery_71007cdc30 with
// the slot-4 entryId chain. On hit bits (1 << [cell]->[0x18] & 0x1f) &
// 0x1fe0000: repositions [0x12c..0x134] using speed vt+0xb8 * vt+0xc8 /
// 3, second probe point [0x138..0x140] offset by h = max(vt+0x90 *
// vt+0xa0 * vt+0xb0, 7.0f) * vt+0x98. Two surfaceWheelQuery_
// 71007cd8b8 rounds (flags 0x119 | (((idw >> 2) & 1) << 22), w5 =
// 0x7e0000) store results at tbl2 + core*4 + 0x40; on bit0 accumulates
// wheel state from the 0xf0-stride per-core row at tbl2->[0x20] and
// fires vt+0x238(body, core) on (r & 0x1fe0000). ASM-FAITHFUL: three
// cbz paths on a null physics manager branch to 0x16b10, past this
// function's ret — into the adjacent function (unreachable crash path;
// the manager is always populated in practice).

// playerKartContextInit_7100003f08 — per-player kart context init
// (extent 0x120; ret paths 0x7100003fa8 fast / 0x7100004030 null-mgr
// tail). (self, packed word ptr, idA, idB). Fast path (slot-4 chain ->
// [+0x218] -> [+0x50]): packed = ([chain+0x48] & 0x7ffff)            (bfxil #0,#19)
//         | ((idA & 0xf) << 24)                        (ubfiz #24,#4)
//         | ((idB & 0xf) << 28)                        (bfi #28,#4)
//         | ((x1word & 0x1f) << 19);                   (bfi #19,#5)
// [self+0x0] = packed; u16 [self+0x104] |= 0x100. Null-mgr path: cbz
// jumps INTO the prologue of the next function at 0x7100003fac
// (gap-split tail-call crash path) — documented as unreachable.
