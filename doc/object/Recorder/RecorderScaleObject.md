# object::RecorderScaleObject

Identity proven: vtable slot 8 thunk returns the literal name string 0xf0cdb6 "RecorderScaleObject". vptr 0x12d1ec0 (35 slots, offset-to-top/typeinfo NULL). GOT cell 0x13113a8 holds row 0x12d1eb0 (vt-0x10); installed vptr = cell+0x10.

recorder::Channel subclass (base raw s16 channel vtable 0x12c3c78 family): slots 9-15, 24 and 29-34 shared with the base; slot 0/1 dtor pair overridden by 0x7b5414/0x7b54e0; slots 20/22 and 21/23 overridden by the 0x7b47xx/0x7b4axx converter group.

## Member notes

- [this+0x1C0] u32 — init 0xC; [this+0x1C4] u32 — init 4 (setup 0x88b854-0x88b858).
- [this+0x1D4] s32 — value-buffer index for the read/write slots (0x88bab0-0x88bab4, 0x88bad0).
- [this+0x1F0] f32 = 0.01f, [this+0x1F4] f32 = 64.0f — defaults stored as an aligned pair at 0x88b864-0x88b890.
- [this+0x278] ptr — zeroed (0x88b848). [this+0x280] ptr — observed object ([parent+0x278], 0x88b88c); its +0x98/+0x9C/+0xA0 is the vec3 scale, +0xA4 bit0 the "valid/visible" gate, +0xA6 a u16 status word.
- size 0x288 (operator new 0x288 at 0x88b834).

## Construction / init order

- FUN_710088b76c: guard on [parent+0x291]; operator new(0x288) (0x88b838), base C1 0x7aae24 (0x88b844), [0x278]=0, [0x1C0]=0xC, float defaults, [0x1C4]=4, [0x280]=[parent+0x278], vptr = GOT 0x13113a8+0x10 (0x88b84c-0x88b860), registered via recorderAddChannel_71007ac0cc(parent, this, 0) (0x88b894).
- Per-class slots: slot 17 = 0x88bae8 (read: out[idx..idx+2] = [target+0x98/+0x9C/+0xA0]), slot 19 = 0x88bb10 (write: if [target+0xA4] bit0, clamp the three incoming floats against a large negative constant (float 0xED6000+0x420, 0x88BB20-0x88BB28) and store to [target+0x98..], then [target+0xA6] |= 4). Slot 18 = 0x88bdd0 returns the name string.
