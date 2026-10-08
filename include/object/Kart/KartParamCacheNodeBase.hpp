#pragma once

#include <cstdint>

namespace object {
// KartParamCacheNodeBase — address-anchored name (vptr 0x12b2198,
// GOT cell 0x130d920). Base of the linked-node member class: ctor 0x710066a2a4 (stores
// x1 into [this+0x10] and into [[this]]-style head, u32 @0x18). The
// embedders overwrite the vptr with KartParamCacheNode (0x12b26b0).
class KartParamCacheNodeBase {
 public:
  void* vptr;         // 0x00
  uint8_t pad08[8];   // 0x08 — unproven padding
  void* mLink10;      // 0x10 — ctor stores x1 (node link)
  uint32_t mField18;  // 0x18
  uint8_t pad1c[4];   // 0x1c — unproven padding
                      // (0x20 total)
};
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
