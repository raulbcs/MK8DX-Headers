# object::Vt12d8ac8

## Identity

PROVISIONAL placeholder name (identity not proven; no typeinfo). Both leading rows are zero (offset-to-top and typeinfo), so the installed vptr is the assigned address itself: **0x12d8ac8**, 19 slots (0x12d8ac8..0x12d8b58). GOT cell 0x1312538 holds vptr-0x10 (0x12d8ab8); the single install site at 0x91d064 computes cell+0x10.

size 0x5b8 — proven by the sole construction site 0x91d030: `mov w0,#0x5b8; bl 0x60afec` (_Znwm, 0x91d044-0x91d048).

## Member notes

- Constructed object is stored at [owner+0x38] (0x91d07c) by the creating function; ctor receives a parameter object in x1 whose bytes at +0x8, +0xa and +0x88 are forwarded to the base ctor 0x55845c(this, ...) (0x91d050-0x91d060).
- Base ctor 0x55845c runs first; the vptr is installed afterwards (0x91d064-0x91d078) — the tail w32 writes +0x5ac = 0 and +0x5b0 = 0 (0x91d06c-0x91d070) are the only post-base field stores visible at this site.
- Slots 0x5585xx-0x5597xx form a dense override cluster distinct from the nex/pia job families; slot18 0x91f3e4 and the dtor pair 0x91f6ec/0x91f7b8 are unrecovered, as are slots 3, 6, 9, 13, 15, 17.
- A sibling allocation site at 0x91d090 builds a different class (new 0x238, vptr from cell 0x1312540) plus an 8-byte member (cell 0x1312548) — not part of this class.

## Construction / init order

- Site 0x91d030: obj = _Znwm(0x5b8); base ctor 0x55845c(obj, arg); [obj+0x5ac] = 0; [obj+0x5b0] = 0; [obj] = vptr 0x12d8ac8 (cell 0x1312538+0x10); [owner+0x38] = obj.
