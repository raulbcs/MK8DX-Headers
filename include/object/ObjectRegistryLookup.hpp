#pragma once

#include <cstdint>

namespace object {
// Object-registry bulk (re)registration and name lookups over the global
// registry manager (mgr = *(cell 0x7101309218)). Docblocks only.

// FUN_710063d324 (0x710063d324, extent 0x24c) — bulk re-registration of
// table entries (called by FUN_7100639748). mgr = *(cell 0x7101309218);
// lock FUN_71005b03b4([mgrRoot+0x30]).
//  1. t = FUN_710063d570(this); null -> return.
//  2. blk = [t+0x30]; size = nn::util::BinaryBlockHeader::GetBlockSize(blk)
//     - 0x10; data = blk+0x10; FUN_71005931e0([t+0x40], [root+0x30], &st)
//     (stack 0x21-byte context {0, ..., 0x21}).
//  3. [t+0x48] = [t+0x40]; [t+0x50] = 0.
//  4. Loop e < u32 [t+0x3c] (count at [t+0x38]+4): ent = [t+0x28][e]:
//     - [[ent+0x88] + 0x40] = ent;
//     - FUN_710059705c(root+0x30, &ent[0x10..], size-scaled args from the
//       [ent+0x68] blocks);
//     - 0x40-byte stack record (FUN_7100a68d6c) filled from ent fields
//       (+0x5c u8, +0x58 u32, +0x1c u32, +0x80 ptr, +0x30 u32, +0x16 u16);
//     - FUN_7100597168([ent+0x88], root+0x30, &record);
//     - [ent+0x90] = FUN_7100639748(mgr, [ent+0x60], [[ent+0x88]+8],
//       [[ent+0x88]+0x10] + 2).
//  5. Nested group loops over u16 [this+0xbc], groups array [this+0x28]
//     stride 0x78: sub count u16 [grp+0x6c], entries [grp+0x40] stride
//     0xb8, each with u8 [ent+0xa8] sub-entries at +0x90 stride 0x78:
//     [[ [ptr+0x78*k] ] + l*8] = FUN_7100639274(mgr, ptr+0x78*k, 0).

// FUN_710063fb98 (0x710063fb98, extent ..0x63ff54) — three-stage registry
// name lookup with a tree-walk fallback. Args: (self x0, owner x1). self:
// u32 result at +0x0, fnptr-table at +0x8 (slot +0x18 called with
// self+8, discarded), const char* key at +0x10.
//  - Stages 0..2: FUN_710064249c(owner, stage) gate -> FUN_7100641c68(
//    owner, stage) -> obj; table = [obj+0x8]; count u32 [table+0x2c],
//    entries [table+0x30], stride 0xc; strcmp hit -> result =
//    u32 [entry+0x8].
//  - Fallback: x8 = *([owner+0x8]+0x58); NULL or u32 [x8+4] == 0 ->
//    result = -1. delim = *(cell 0x71012fada8) (byte 0x00 at 0xf57d30);
//    aux = *(cell 0x71012fae28)+0x10; limit 0x108000; node records at
//    x8+8 (s32 stride, u32 [node+8] = table addr per record). Outer loop
//    over u32 [x8+4] records: FUN_71006923d0(); slot-3 dispatch of the
//    result's fnptr table twice, then slot-3 of aux with pair
//    {aux, nodes+0xc}; fused 3-byte-at-a-time scan (cap 0x108000) of the
//    string at [r+8] against that length and delim -> node offset
//    u32 [node+8] into (nodes+0xc)+off, child count u32 [off+4]; inner
//    child loop with the same aux pattern and a strcmp of key vs result
//    -> u32 [child+4] on match. Exhausted -> -1. Result stored to
//    *(u32*)self. (Fallback is a structural translation; medium
//    confidence on the fused byte-scan details.)

// FUN_710063ff98 (0x710063ff98, extent ..0x640154) — three-slot registry
// name lookup. Args: (self x0, owner x1). self: u8 results at +0x0/+0x1/
// +0x2, fnptr-table ptr at +0x8 (slot +0x18 invoked as fn(self+8), result
// discarded — refresh side effect), const char* key at +0x10. For stage
// 0,1,2: FUN_710064249c(owner, stage) gate; gated -> FUN_7100641c68(
// owner, stage) -> obj; table = [obj+0x8]; on a table: fn-table slot
// +0x18 called with self+8, then count u32 [table+0x38], entries
// [table+0x3c], stride 0xc, entry = { const char* name; pad4; u32 id at
// +0x8 }; first strcmp hit -> result = u32 [entry+0x8]. Any miss ->
// result = 0xff. Stored byte-wise to self+stage.

// FUN_71006327a8 (0x71006327a8, extent ..0x6328b8) — masked multi-object
// dispatch + registration. Args: (self, arg, obj, mask w3, inVal x4,
// outVal x5).
//  1. stack[0x8] = *inVal; FUN_7100631ed8(obj, mask, &stack[0x8]).
//  2. vcall vtbl slot 0 on obj.
//  3. For i < [self+0x78] with (mask & (1 << i)): slot = ([self+0x78] > i)
//     ? [self+0x80] + i*8 : [self+0x80]; stack[0x0] = *outVal;
//     FUN_71006367f8(*slot, arg, obj, &stack).
//  4. Push obj into the registry at [self+0x90]: idx = [self+0x98];
//     base[idx] = obj when [self+0x88] > idx (csel keeps the raw base
//     pointer otherwise); [self+0x98]++.

// Stage-table entry format shared by the name lookups (0xc-byte stride;
// FUN_710063ff98 reads the count at table+0x38 / entries at table+0x3c,
// FUN_710063fb98 the count at table+0x2c / entries at table+0x30 —
// different table objects, same entry shape): +0x00 const char* name,
// +0x04 pad, +0x08 u32 id.
}  // namespace object
