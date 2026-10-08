#pragma once

#include <cstdint>

namespace object {
// ParamNodeVtdba0 — address-anchored name (vptr 0x12bdba0, GOT cell
// 0x130e918 holds 0x12bdb90; stored vptr = cell+0x10). CLOSED AS PROVEN GAP
// (): subsystem and role proven, self name not present in binary.
//
// Proven role — named parameter-group node of the KartParamCache param tree
// (same 0x710072xxxx subsystem as KartParamCacheVtd608):
// - Primary base of factory-built composites: operator new(0x538) at
// 0x72f404 -> ctor 0x72e4f8, and new(0x488) at 0x72f460 -> ctor
// 0x72c35c (factory fn-pointers in GOT cells 0x130e930/0x130e938).
// - Ctor 0x72e4f8 registers children via the channel-pair registrars
// 0x662f30/0x662f70 with EN/JP name pairs + Min/Max range strings:
// "Direction"/方向 (node vptr cell 0x130d9c8), "IsFollowDir"/向きを追従,
// "Angle"/開き角度 (Min=0.01, Max=3.14), "AngleDamp"/角度減衰
// (Min=0, Max=5); sibling composite registers "AnmType"/アニメタイプ.
// Camera-flavored sibling params nearby (Radius, Length, DistDamp,
// ViewCoordinate; agl::pfx ColorCorrection/toycam/fxaa strings).
// - Tree root ctor 0x732d0c defaults node names to "untitled" (rodata
// 0xef8b75); named-string member ctor 0x61cc48 (shared with
// KartParamCacheVtd608's +0x98 member).
// - Also element type of node arrays: dba0 vptr stored at stride-0x28
// offsets 0x110..0x230 in the 0x64ecxx composites.
// - No RTTI (vtable[-8] == 0, family-wide).
//
// Why no self name: the EN/JP name strings belong to CHILD leaf nodes
// (vptrs 0x12b29a0/0x12b2900), never to dba0 itself; no typeinfo, no
// symbols. Renaming would be invention.
class ParamNodeVtdba0 {
 public:
  void* vtable;  // 0x00
  // (own fields unmapped; secondary hook-band vptr at +0x30 = cell+0x108)
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
