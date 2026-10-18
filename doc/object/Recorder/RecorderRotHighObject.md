# object::RecorderRotHighObject

Identity proven: vtable slot 8 thunk returns the literal name string 0xf0cdf0 "RecorderRotHighObject". vptr 0x12d2238 (35 slots, offset-to-top/typeinfo NULL). GOT cell 0x13113b0 holds row 0x12d2228 (vt-0x10); installed vptr = cell+0x10.

recorder::Channel subclass (base raw s16 channel vtable 0x12c3c78 family): slots 9-15, 24, 30-34 shared; slot 0/1 dtor pair overridden by 0x7ae584/0x7ae608; slots 21/23 overridden by 0x7b46a4/0x7b4714; slot 25/26 = 0x7adeac/0x7adf64; slots 27-29 = 0x7ae664/0x7ae66c/0x7ae74c.

## Member notes

- [this+0x1C0] u32 — init 0x24; [this+0x1C4] u32 — init 6 (setup 0x88b8c0/0x88b8f4).
- [this+0x1D4] s32 — value-buffer index for the read/write slots.
- Float defaults: [0x1F0]=0xC28F3CF5 (-71.95f), [0x1F4]=0xFEC0461F (-1.88f), [0x1F8]=0xCE6638CC (0x88b8c8-0x88b8e8).
- [this+0x278] and [this+0x280] — zeroed (0x88b8f0). [this+0x288] — copy of [parent+0x278] (0x88b958); its [+0x88] is the 9-word rotation destination, same shape as RecorderRotObject.
- size 0x290 (operator new 0x290 at 0x88b8a4, shared allocation with RecorderRotObject).

## Construction / init order

- FUN_710088b76c: guard on [parent+0x292]; operator new(0x290) (0x88b8a8); base C1 0x7aae24 (0x88b8b4); sub-flag [parent+0x295] selects the variant: set -> this class (constants at 0x88b8c0-0x88b8fc, vptr = GOT 0x13113b0+0x10 at 0x88b8fc), clear -> RecorderRotObject; common tail stores [0x278]=0, [0x280]=0, [0x288]=copy, then recorderAddChannel_71007ac0cc(parent, this, 0) (0x88b95c).
- Per-class slots: slot 17 = 0x88bf08 (return 1), slot 19 = 0x88bcdc (write: 9 words from in[idx..idx+8] into [target_288+0x88], then [target+0xA6] |= 2; 0x88bcdc-0x88bd18). Slots 16/18 = return-1 thunks; slots 2-7 = global-pointer getters (GOT 0x1311428..0x1311440), slot 8 = name thunk 0x88befc.
