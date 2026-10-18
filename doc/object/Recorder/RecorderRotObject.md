# object::RecorderRotObject

Identity proven: vtable slot 8 thunk returns the literal name string 0xf0cdde "RecorderRotObject". vptr 0x12d2110 (35 slots, offset-to-top/typeinfo NULL). GOT cell 0x13113b8 holds row 0x12d2100 (vt-0x10); installed vptr = cell+0x10.

recorder::Channel subclass (base raw s16 channel vtable 0x12c3c78 family): slots 9-15, 24, 30-34 shared; slot 0/1 dtor pair overridden by 0x7ae428/0x7ae430; slots 21/23 overridden by 0x7b45a4/0x7b462c (same overrides as the RotHigh variant); slot 25/26 = 0x7adbec/0x7adca4; slots 27-29 = 0x7ae48c/0x7ae494/0x7ae574.

## Member notes

- [this+0x1C0] u32 — init 0x24; [this+0x1C4] u32 — init 4 (setup 0x88b908/0x88b938).
- [this+0x1D4] s32 — value-buffer index for the read/write slots (0x88bea4 group).
- Float defaults: [0x1F0]=0xC28F3CF5 (-71.95f), [0x1F4]=0x431F0000 (159.5f), [0x1F8]=0x33673BCD (0x88b918-0x88b92c).
- [this+0x278] ptr — zeroed (0x88b8b8, common tail). [this+0x280] ptr — zeroed (0x88b8f0/0x88b934). [this+0x288] ptr — copy of [parent+0x278] (0x88b958); the +8 size bump vs the other variants exists to hold it; its [+0x88] is the 9-word rotation destination (0x88bc48-0x88bc64).
- size 0x290 (operator new 0x290 at 0x88b8a4).

## Construction / init order

- FUN_710088b76c: guard on [parent+0x292]; operator new(0x290) (0x88b8a8); base C1 0x7aae24 (0x88b8b4); sub-flag [parent+0x295] selects the variant: clear -> this class (constants at 0x88b904-0x88b940, vptr = GOT 0x13113b8+0x10), set -> RecorderRotHighObject (constants at 0x88b8c0-0x88b8fc, vptr = GOT 0x13113b0+0x10); common tail stores [0x278]=0, [0x280]=[parent+0x278], [0x288]=copy, then recorderAddChannel_71007ac0cc(parent, this, 0) (0x88b95c).
- Per-class slots: slot 17 = 0x88bbdc (read), slot 19 = 0x88bc38 (write: 9 words from in[idx..idx+8] into [target_288+0x88] — a 3x3 rotation block; 0x88bc38-0x88bc64). Slots 16/18 = 0x88bea4/0x88beac (return 1); slots 2-7 = global-pointer getters (GOT 0x1311408..0x1311420), slot 8 = name thunk 0x88be98.
