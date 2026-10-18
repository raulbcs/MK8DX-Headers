# object::RecorderTransObject

Identity proven: vtable slot 8 thunk returns the literal name string 0xf0cdca "RecorderTransObject". vptr 0x12d1fe8 (35 slots, offset-to-top/typeinfo NULL). GOT cell 0x13113c0 holds row 0x12d1fd8 (vt-0x10); installed vptr = cell+0x10.

recorder::Channel subclass (base raw s16 channel vtable 0x12c3c78 family): slots 9-15, 24, 29-34 shared; slot 0/1 dtor pair overridden by 0x7b5680/0x7b57a0; slots 20-23 all overridden by the 0x7b47xx/0x7b4axx converter group (0x7b4764/0x7b49fc/0x7b4a70/0x7b4ad8).

## Member notes

- [this+0x1C0] u32 — init 0xC; [this+0x1C4] u32 — init 6 (setup 0x88b97c-0x88b994).
- [this+0x1D4] s32 — value-buffer index for the read/write slots (0x88bb7c-0x88bb80, 0x88bba4).
- [this+0x278] ptr — zeroed (0x88b988). [this+0x280] ptr — observed object ([parent+0x278], 0x88b9a0); its +0x90 is the vec3 translation, +0xA6 a u16 status word.
- size 0x288 (operator new 0x288 at 0x88b968).

## Construction / init order

- FUN_710088b76c: guard on [parent+0x293]; operator new(0x288) (0x88b96c), base C1 0x7aae24 (0x88b978), [0x1C0]=0xC, [0x278]=0, [0x1C4]=6, [0x280]=[parent+0x278], vptr = GOT 0x13113c0+0x10 (0x88b998-0x88b9ac), registered via recorderAddChannel_71007ac0cc(parent, this, 0) (0x88b9b0).
- Per-class slots: slot 17 = 0x88bb78 (read: out[idx..idx+2] = [target+0x90] vec3), slot 19 = 0x88bba4 (write: copy in[idx..idx+2] into [target+0x90] vec3 and update [target+0xA6] flags; 0x88bbcc-0x88bbd0). Slot 18 = 0x88be34 returns the name string.
