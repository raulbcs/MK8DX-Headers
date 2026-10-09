#pragma once

#include <cstdint>

// CourseTriggerRegistry — course trigger/object registry singleton
// (2026-10-09 MECHANICS_101 closure; layout comments only — no headered
// consumers yet).
//
// Identity: 0x4e8-byte singleton allocated at 0x7100383618. The base
// descriptor byte +0x8 = 4 (ctor arg — a REGISTRY id, not a trigger type;
// the `strb w1,[x19,#8]` at 39655c is the only direct writer of +0x8 in
// the module). Ctor chain 383618 → 3935b0 → 3935f0 → 396540.
//
// Structure:
// - 0x71003935f0(this, w1=4, w2=0xc) allocates a 12-bucket array
//   (w20=0xc, 3*w20<<5 = 0x60*w20 bytes, pointers at this+0x80/+0x88)
//   with per-bucket intrusive linking at stride 0xb0 = 2*0x58 — twelve
//   trigger-type buckets, each holding a ground/air sublist pair,
//   matching the proven registry+0xf0 sublist layout. The < 0xc clamps
//   at 393c00/393ce4 are bounds checks on exactly this array.
// - The container's +0x58/+0x68 hold two 0x18-byte records inited by
//   0x7100556664(p,0,0x442).
// - 0x3947cc/0x394988/0x3949e0/0x394aac are the registry's VIRTUAL
//   methods (zero direct bl callers; exist only as .rela.dyn addends in
//   vtable cells). Insert family: 0x7100393960 / 0x7100394824; the
//   registry-internal re-add of type 1 is proven at 393c78 (w1=1).
//
// Trigger types 0..0xb (per-entry bytes +0x8/+0x9 of each entry; boost
// tiers resolved by the word table 0xf24460 — see kart/BoostSlot.hpp):
// - t2 CLOSED: antigrav spin-recovery boost (tier 0x200 requested by the
//   body calc at 18b9f4 when mbAntiGColSpin (Move+0x3ec) set and
//   +0x22c < 1.0).
// - t0: consistent with the zero-initialized default entry (descriptor
//   byte +0x8 never written => type 0 => tier 0x10000).
// - t11: one unexplained identity; static closure requires locating the
//   writer of the entry +0x8/+0x9 bytes (decompile the descriptor
//   population side — callers of the 0x710039549c/0x71003971a4 virtual
//   methods — or runtime-breakpoint the insert family).
// - The type byte is course_muunt placement/trigger-section data, NOT
//   objflow (MK8D objflow.byaml has no 0..0xb type field; verified by
//   full parse, 788 objects).
namespace gear {
namespace Course {
struct TriggerRegistry {
  uint8_t pad_00[0x4e8];  // whole-object extent 0x4e8 from the alloc site
                          // proven sub-offsets: +0x8 registry-id byte (4),
                          // +0x58/+0x68 two 0x18-byte records, +0x80/+0x88
                          // 12-bucket array pointers, +0xf0 sublist head
};
}  // namespace Course
}  // namespace gear
