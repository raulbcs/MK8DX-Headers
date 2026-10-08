#pragma once

#include <cstdint>

namespace object {
// Vt3dcf300bb8 — GAP PROVEN: generic named-worker nn::ae::AppletThread base; no single class
// name exists in the binary. The ctor wrapper 0x7100629270 fixes the vptr (cell 0x130d470)
// but receives the thread name from each caller; six instantiation sites use six different
// names: "MiiActorMgrDelegateThread" (0x3dfee0), "Prepare Thread" (0x61333c),
// "gear::VibrationThread" (0x7da958), "MiiDirectorDelegateThread" (0x81ebb0),
// "gsys::MiiResource" (0x8225ac), "Presentation Thread" (0xa84260).
// A per-site thread name is instance data, not class identity — renaming is impossible here.
// Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
// Field-evidence note: recorded ctor 0x7100628fc8 has exactly one direct
// this-write — w32 at +0xf0 (parameter pass-through). Everything between 0x08
// and 0xf0 is unproven; declared as padding.
class Vt3dcf300bb8 {
 public:
  void* vtable;          // 0x00
  uint8_t mPad08[0xe8];  // 0x08 — unproven gap
  uint32_t mFieldf0;     // 0xf0 — ctor-written (param pass-through)
                         // (extent unknown)
};
}  // namespace object
