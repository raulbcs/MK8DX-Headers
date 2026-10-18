# object::RecorderVisibleObject

Identity proven: vtable slot 8 thunk returns the literal name string 0xf0cda0 "RecorderVisibleObject". vptr 0x12d1d98 (35 slots, offset-to-top/typeinfo slots NULL). GOT cell 0x13113a0 holds row 0x12d1d88 (vt-0x10); installed vptr = cell+0x10.

Derived from the recorder channel base (raw s16 channel vtable 0x12c3c78 / recorder::Binder family, see doc/object/Vt12cc638.md siblings): slots 9-15 (0x7ab904/0x7abca8/0x7ac1d8 + sead::ExpHeap::isResizable 0x1ac84 group), 24 (0x7ac728) and 29-34 are the base set; slot 0/1 dtor pair 0x7ad278/0x7ad344 is also inherited unchanged.

## Member notes

- [this+0x1C0] u32 — init 4; [this+0x1C4] u32 — init 0 (setup 0x88b7f8-0x88b804).
- [this+0x1D4] s32 — index into the caller-provided value buffer used by the per-frame read/write slots (0x88baac-0x88bab8, 0x88bad0-0x88bad4).
- [this+0x278] ptr — zeroed in the 0x294-flagged setup variant (0x88b7fc).
- [this+0x280] ptr — observed object ([parent+0x278], copied at 0x88b810); its +0xA4 halfword bit0 is the visibility flag; its vtable slot +0x50 is invoked for the apply path (0x88ba44-0x88ba4c).
- size 0x288 (operator new 0x288 at 0x88b7e4).

## Construction / init order

- FUN_710088b76c (KartUnit channel-setup family): guard on [parent+0x294]; operator new(0x288) (0x88b7e4), base C1 0x7aae24 (0x88b7f4), then stores 0x1C0=4 / 0x1C4=0 / [0x278]=0 / [0x280]=[parent+0x278], vptr = GOT 0x13113a0+0x10 (0x88b808-0x88b824), registered via recorderAddChannel_71007ac0cc(parent, this, 0) (0x88b828).
- Per-class slots: slot 17 = 0x88baac (read: out[idx] = [target+0xA4] & 1), slot 18 = 0x88bd80 (return 1), slot 19 = 0x88bac4 (write: target->vtbl+0x50(target, in[idx] > 0)). Slots 2-7 are global-pointer getters (GOT 0x13113D0..0x13113F8), slot 8 = name thunk.
