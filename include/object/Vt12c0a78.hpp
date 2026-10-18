#pragma once

#include <cstdint>

namespace object {
// Vt12c0a78 - PLACEHOLDER name; keyed registry entry owned by Vt12c0a38
// (host link, intrusive node at +0x20, owner refcount, guarded-global pair).
// No RTTI. extent 0x58 - details: doc/object/Vt12c0a78.md
class Vt12c0a78 {
 public:
  void* mVtable;    // 0x00 - 0x12c0a78 (GOT cell 0x130ee00 holds vt-0x10;
                    //        first set to the 0x11ad140-style host vptr by
                    //        0x61561c, then overwritten by the factory)
  void* mHost;      // 0x08 - host/parent passed to 0x61561c
  void* m10;        // 0x10 - ctor 0 (0x74760c stp xzr, xzr)
  void* m18;        // 0x18 - ctor 0
  void* mNodeNext;  // 0x20 - intrusive list node (offset [owner+0x3c]=0x20)
  void* mNodePrev;  // 0x28 - list node prev
  void* m30;        // 0x30 - ptr member, ctor 0 via 0x736b5c; released by
                    //        0x736b64 (0x747874)
  uint32_t m38;     // 0x38 - ctor 0 (0x747618)
  uint32_t m3C;     // 0x3c - no ctor store (unproven padding)
  void* m40;        // 0x40 - ctor 0 (0x747620 stp xzr, x22)
  void* mOwner;     // 0x48 - owning Vt12c0a38 registry
  void* m50;        // 0x50 - entry key; ctor 0 (0x74761c), written by
                    //        virtual slot 4 (0x7478f4), read by the
                    //        registry find loop 0x7476a0
};
}  // namespace object
