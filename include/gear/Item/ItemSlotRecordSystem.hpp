#pragma once

#include <cstdint>

namespace gear {
// Item-slot record system of the physics/item chain (0x5dbf48..0x79b854
// cluster). Docblocks only — no class ownership proven beyond the field
// offsets cited below; the 0x78-byte record produced by FUN_710079aee0 is
// mirrored at the bottom.

// FUN_710079ca24 (0x710079ca24, extent 0x1cc) — two-phase item-slot
// (re)assignment for a holder object (this), given a desired item id:
//  1. st = FUN_710079bdec(this->[0x30]); early-out when byte [st+0x74] == 0.
//  2. it = this->[0x30]->vt+0x38(); it->vt+0x10() (item context begin).
//  3. Phase 1: aux = this->[0x30]->[0x18]; unless aux->[0x18]->[0xa8] byte
//     set, FUN_710079df0c(aux, id). When this->[0x20] == 0: create via
//     this->vt+0x38(id) into this->[0x20], then FUN_710079cbf0(this, 0, id)
//     and FUN_710079aee0(this+0x78, 0, id).
//  4. Phase 2 (h = this->[0x30]->[0x18], only when h->[0x10] == 1 and
//     h->[0x20] has the [0xa8] byte set): want = st->[0xb8]; release the old
//     this->[0x28] via this->vt+0x40(this, old, 1); this->[0x28] =
//     this->vt+0x38(want); FUN_710079cbf0(this, 1, want);
//     FUN_710079aee0(this+0x78, 1, want); set byte [this+0xd0] bit0 and
//     this->[0x78] = 1.
//  5. it->vt+0x18() (context end). Final sweep over i < this->[0x30]->[0x44]
//     (u16 count): entry = [0x48][i]; when entry && entry->[0x60] <= 2,
//     this->[0x70][i] = 0.

// FUN_710079aee0 (0x710079aee0, extent 0x974) — (re)build of a 0x78-byte
// item-slot record from a 0x24-byte stage node. Args: (slots x0, slotIdx w1,
// arena x2). Slot pointer = slots + (slotIdx < 2 ? slotIdx : 0) * 8 + 8
// (clamp literal). Flow:
//  1. Release the previous record (FUN_710079ab6c) and clear the slot.
//  2. rec = FUN_710060b234(0x78, arena, 8), zeroed.
//  3. ctx = [slots-0x48]; node = ctx->[0x18][slotIdx]; stage = node->[8]
//     (0x2c-field header).
//  4. Three 0x28-entry arrays sized by stage->[0x1c] / [0x24] / [0x28]
//     (FUN_710060b3fc(count*0x28 + 8, arena, 4), 8-byte count header,
//     default entry {0, u8 1, 0, 0, 0xffff}) at rec+0x0/0x8, rec+0x10/0x18,
//     rec+0x20/0x28; a fourth array of auxCount 8-byte slots at
//     rec+0x30/0x38, zeroed.
//  5. For i < stage->[0x14] over 8-byte entries at stage->[0x38]: key =
//     cell 0x71012fb2e8 | e->[0] (+0x100000000 when e->[0] < cell
//     0x71012fb2e0); j = FUN_710079be14(ctx, key); when 0 <= j < auxCount,
//     a 0x40-byte object is built (FUN_71007a3f20) into rec->[0x38][j],
//     else error FUN_710079a5e0(ctx, 0x12, ...).
//  6. rec+0x40/0x48: array of snapshot-count 8-byte slots, zeroed.
//  7. w25 = mgr->[0x3c] (mgr = FUN_710079bdec(ctx)); when >= 1:
//     rec+0x50 = w25, rec+0x58 = FUN_710060b3fc(w25*8, arena, 8), zeroed.
//  8. For k < stage->[0x20] over 16-byte {u32 a, u32 b} entries at
//     stage->[0x50]: b != 0 -> j = FUN_710079a604(mgr, key(a)), 0x30-byte
//     object via FUN_71007a5484(slotIdx, rec+0x20 array, j, 1, e, ...)
//     into rec->[0x58][j]; b == 0 -> j = FUN_710079c30c(ctx), object into
//     rec->[0x48][j]. Failures report error code 0x13.
//  9. stage->[0x28] != 0 -> rec+0x60 = 0x20-byte alloc via
//     FUN_71007a4a84; growable {u32 count, u32 cap; T* data} list at
//     rec+0x68/0x70 with cap = stage->[0x14] + stage->[0x20] + 1
//     (FUN_710060b930).
// 10. Append every non-null pointer of rec->[0x38], rec->[0x48],
//     rec->[0x58], then rec+0x60, into the rec+0x68 list. Store rec into
//     the slot pointer.

// FUN_71005dbf48 (0x71005dbf48, extent 0x230, gap-split) — item-slot
// reassignment pass on a manager. Args: (this, keyA, keyB).
//  - Pass 1: scan i < [this+0x50]; FUN_71005de3dc([this+0x60] + i*0x28 -
//    0x14, &keys); first entry whose u32 at ([this+0x60] + i*0x28) == -1
//    selects the match index; none -> return 0.
//  - Pass 2: walk the live chain from [this+0x70] via +0x30 links; match on
//    [+0x280] when [+0x20] == 2 (against the selected entry's [+0x18]);
//    remove via FUN_71005dfe60 + FUN_71005ddd1c([this+0x230], node); then
//    FUN_71005dc950(this, keyA, keyB); resolve a record from the
//    [this+0x228]+0x90 table (kept when [rec+0x9] != 0), call
//    FUN_71005beefc and clear [rec+0x9].
//  - Pass 3: repeat the pass-1 scan; on a -1 entry write state 0xa at
//    [entry+0x1c]. Returns 1 on both normal exits.

// FUN_71005dc950 (0x71005dc950, extent 0x210, gap-split) — insert of a
// string-keyed record (called by FUN_71005dbf48). Scan i < [this+0x50]:
// FUN_71005de3dc([this+0x60] + i*0x28 + 0xc, &key); on a match with entry
// idx != -1: table = [[ [this+0x228]->[0x90] ]], gates [+0x9] != 0 and
// count [+0x4c] >= 1; str from [owner+0x58]->[+0x10]+0x10 when
// [owner+0x60][0] null. Candidates [list + j*8], j < [table+0x64] - 0x20,
// skipping null / [+0x9]==0 / FUN_71005bc524(cand, str) == -1; on a
// FUN_71005bc5d8 bit0 hit: node = vt [[[this+0x230]]+0x10](heap, 0x418,
// 0x80); memset(node+8, 0, 0x410); [node] = kind tag 0x5_41000000000;
// memcpy(node+8, str, strlen(str)); register through vtables of
// [this+0x248] and [this+0x230]. Returns 0 when nothing matched, 1 after
// insert (also when the candidate loop exhausts, 0x5dcab0).

// FUN_710079edb4 (0x710079edb4, 0x78 bytes) — pending-entries predicate.
// idx = [self+0x10] clamped to 0 when >= 2; slot = [mgr + idx*8 + 0x18];
// false when slot null, byte [slot+0xa8] == 0, or count
// ([slot->[0x8]]+0x20) == 0; otherwise scans count entries (stride 0x10)
// from [slot+0x50]+4 and returns 1 at the first nonzero u32, else 0.

// FUN_710065b6b4 (0x710065b6b4, extent 0x108, gap-split) — item-spawner
// release path. x0 = spawner, x1 = spawn info record.
//  1. FUN_7100628714(this+0x6a0) (acquire inner lock/event).
//  2. rec = info->[0x1a8]; kind = byte [info+0x1e2]; target =
//     (u32[rec+0] > kind) ? rec + kind*0xa0 : rec; chained = info->[0x180].
//     When spawner u32 [this+0x29] bit4 is clear: FUN_7100673c94(target,
//     chained, 1). When set: additionally push a 0x18-byte entry into the
//     spawner ring at this+0x718 (cap u32 +0x710, head u16 +0x720, stride
//     0x18) holding chained->[0x50]/[0x58]/[0x60] (when chained non-null),
//     then FUN_7100673c94(target, chained, 0).
//  3. info->[0x180] = 0; clear byte [info+0x1e9] bit0; release via
//     FUN_7100628714/2_724 pairs on this+0x660 and this+0x6a0. Returns 1.

// FUN_71006c5598 (0x71006c5598, true extent ..0x6c5770, gap-split) —
// item-slot activation / player-state apply. Gates: byte
// [this->[+8] + 0x700] != 0; s32 [this+0xd08] >= 1; float [this+0xd00] > 0.
// Then idx = byte [holder+0x8]; entry = [this+0xd10] + idx*0xb80 (clamped
// to [this+0xd10] when [this+0xd08] <= idx); entry gate:
// ([entry+0x1e0] >= 1 && [entry+0x1d8] != 0) || byte [entry+0xaf8].
// Descriptor { [singleton 0x12fa000 obj]+0x10, str 0xeff3cd }, then
// FUN_71006cd4ec(holder, key, &desc, 0, ...). Recompute entry; target =
// [this+0x248]; arm = ([target+0x8] > idx ? [target+0x10] + idx*0x3d68 :
// [target+0x10]); FUN_710065e7b0(entry, key, [arm+0x5d8]). When
// [entry+0x570] != 0: serializer block via FUN_710062ae2c/2_aeb0 with
// defaults from f = [this+0x00d00] when f in (0,1) (bytes 1, int pairs
// 0x63/0x64, floats 1.0f x3, f), else byte [block+0x24] = 0;
// FUN_710065c2a4(key, entry+0x580); FUN_710065e3b4(entry);
// FUN_71006b27ec(holder, key, 0) (unlock) at both ends.

// Item-slot record layout built by FUN_710079aee0 (0x78 bytes, mirror):
// +0x00/+0x08 {count, data} pair (0x28-byte entries, sized stage->[0x1c]);
// +0x10/+0x18 {count, data} (stage->[0x24]); +0x20/+0x28 {count, data}
// (stage->[0x28]); +0x30 count header / +0x38 auxCount 8-byte slots;
// +0x40 count header / +0x48 snapshot-count 8-byte slots; +0x50 u32 count
// from mgr->[0x3c] (when >= 1) / +0x58 its 8-byte slots (FUN_71007a5484
// targets); +0x60 0x20-byte alloc when stage->[0x28] != 0; +0x68 growable
// list {u32 count, u32 cap; T* data at +0x70} appended from the arrays
// above. Default array entry: {0, u8 1, 0, 0, 0xffff}.
//
// Spawner ring entry pushed by FUN_710065b6b4 (0x18 bytes, mirror):
// +0x00/+0x08/+0x10 <- info->[0x180]->[0x50]/[0x58]/[0x60].
}  // namespace gear
