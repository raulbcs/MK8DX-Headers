#pragma once

#include <cstdint>

// Vt12d7ce8 - PLACEHOLDER name (9-slot member interface vtable, no RTTI;
// cell 0x1312338 holds vptr-0x10, installed vptr 0x12d7ce8). Member at the
// base of a sub-object built inline by enl::TaskThread::ThreadHeap ctor.
// extent 0xe4 (ctor field stores; lower bound) - details: doc/object/Vt12d7ce8.md
namespace object {
struct Vt12d7ce8 {
  virtual void slot00();  // 0x00 slot0 (0x91000c, mid FUN_710090fc08+0x404)
  virtual void slot08();  // 0x08 slot1 (0x9100d8, mid FUN_710090fc08+0x4d0)
  virtual void slot10();  // 0x10 slot2 (0x556a98)
  virtual void slot18();  // 0x18 slot3 (0x556abc, tail of FUN_7100556a98+0x24)
  virtual void slot20();  // 0x20 slot4 (0x55686c)
  virtual void slot28();  // 0x28 slot5 (0x910134, mid FUN_710090fc08+0x52c)
  virtual void slot30();  // 0x30 slot6 (0x9101ac, mid FUN_710090fc08+0x5a4)
  char mPad8[0x40];       // 0x08 - null slots 7/8 (empty vtable entries),
                          // rest unproven

  char mPad48[0x9c];  // 0x48 - unproven (ctor stores through +0xe4)
};
}  // namespace object
