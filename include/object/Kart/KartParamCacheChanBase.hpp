#pragma once

#include <cstdint>

namespace object {
// KartParamCacheChanBase — address-anchored name (vptr 0x12b3af0,
// GOT cell 0x130d918). Base of the recorder channel-pair member class: ctor 0x7100662f30
// (vptr, u32 @0x8, ptr zero @0x10); the callers overwrite the vptr with
// KartParamCacheChan (0x12b21e0) and finish via 0x7100662f70.
// Shared vtable slots of the 22-channel cluster (0x66496c cluster: Vt2a50/
// 2af0/32b8/...; evidence TUs paramChannelSharedEquals_710066496c /
// paramChannelSharedCopyFrom_71006649ec):
// - Slot 2 (0x20) Equals 0x710066496c: type-id compare via each object's
//   vtable+0x38, u32 +8 compare, then self vtable+0x18(self, other).
// - Slot 3 (0x28) CopyFrom 0x71006649ec: if src type id == 0x14 ->
//   dst=v+0x58, src=v+0x50, dst->v+0x10(dst,src); else byte-copy n (v+0x60)
//   bytes from src v+0x40 into self v+0x48.
class KartParamCacheChanBase {
 public:
  void* vptr;        // 0x00
  uint32_t mField8;  // 0x08 — ctor arg w0
  uint8_t pad0c[4];  // 0x0c — unproven padding
  void* mZero10;     // 0x10 — ctor zero
                     // (0x18 total)
};
// Vtable slot 0 (0x10) vtable-init ctor stub (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/vtInitChanBase_7100664f50.cpp):
// stores the class vtable pointer (global pointer at 0x710130918, +0x10) into *this.
// True extent 20 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
