# object::RecorderStateObserver

Identity proven: vtable slot 8 thunk returns the literal name string 0xf0ce29 "RecorderStateObserver". vptr 0x12d2360 (35 slots, offset-to-top/typeinfo NULL). GOT cell 0x1311520 holds row 0x12d2350 (vt-0x10); installed vptr = cell+0x10.

recorder::Channel subclass (base raw s16 channel vtable 0x12c3c78 family): slots 9-15, 24, 29-34 shared; slot 0/1 dtor pair overridden by 0x3b0894/0x3b0918; slot 2 = 0x88c618 (global getter, GOT 0x1311528); slots 21/23 overridden by 0x3afc74/0x3afc84 (the converter-thunk group also cited in KartRecorderChannels.hpp); slots 25-28 = 0x1ad10/0x1adbc/0x1adc0/0x1adc8.

## Member notes

- [this+0x1C0] u32 — init 4; [this+0x1C4] u32 — init 1 (C1 0x88c5bc-0x88c5cc).
- [this+0x1D4] s32 — value-buffer index for the read/write slots (0x88c5f8/0x88c608).
- [this+0x278] ptr — zeroed (0x88c5c8). [this+0x280] ptr — observed object (C1 arg x1, 0x88c5d8); its u8 +0x9 is the observed state byte.
- size 0x288 (operator new 0x288 at 0x3a88e0 in FUN_71003a80f8; a second construction at 0x3a56fc in FUN_71003a533c).

## Construction / init order

- Out-of-line C1 FUN_710088c5a4(this, target): base C1 0x7aae24 (0x88c5b8), [0x1C0]=4, [0x278]=0, [0x1C4]=1, [0x280]=target, vptr = GOT 0x1311520+0x10 (0x88c5d0-0x88c5e0). Callers then register via recorderAddChannel_71007ac0cc (e.g. 0x3a88dc before the new, 0x3a5708 after).
- Per-class slots: slot 17 = 0x88c5f0 (read: out[idx] = u8 [target+0x9]), slot 19 = 0x88c604 (write: u8 [target+0x9] = in[idx]). Slots 3-7 = global-pointer getters (GOT 0x1311530..0x1311540), slot 8 = name thunk 0x88c660.
