# object::Vt12b9ef8

PLACEHOLDER name (identity not proven). vptr 0x12b9ef8, 8 slots, typeinfo NULL (game-side). GOT cell 0x130e280 holds vt-0x10; installed vptr = cell + 0x10.

## Member notes

- size 0x48 — LOWER BOUND: the observed instances are stack temporaries constructed in place (vptr store is inlined at each call site, no standalone C1 exists); deepest store is the u32 at temp+0x40 (0x6d48ec). Extent beyond 0x48 unverified.
- Slot 6 (0x623660) is the workhorse: it reads the object's vptr, blrs slot 7 to obtain a buffer, then blrs slot 2 and computes alignment via udiv/msub ([x1+0x30] pointer, [x1+0x38] u32, w-pair at [x1+8] are the parameters passed from the caller frame). Allocation/alignment-helper behavior; exact semantics unverified.
- D1 (slot 0, 0x6237f4) first re-installs the BASE vptr (cell 0x130d388 + 0x10) at [this], then unregisters `this` from the global registry list at [0x12fc3368] (head/links via 0x623da8/0x623dec, node slot +0x58 compared against this), then tail-calls member dtor chain 0x6156b4. So this vtable is a derived specialization of the 0x130d388-row family.
- The same vptr is also installed as a SECONDARY vptr at host+0x10 by other sites (0x767634, 0x771ee8) where the host primary vptr comes from cell 0x12fa0388 — multi-use/MI detail unverified.

## Construction / init order

- No standalone C1: callers materialize the vptr inline (sites 0x6d48bc, 0x736c8c, 0x767608, 0x771ebc — all `ldr [page+0x280]; add #0x10`).
- Typical stack-temp sequence (0x6d4858 block): build params on the caller frame, store vptr at temp+0x00, u32 4 at temp+0x40, call slot 6 directly (0x623660) with x1 = params, then slot 0 (0x6237f4) to destroy.
- Slots: 0 = D1 0x6237f4; 1 = 0x6d96ac (unrecovered, absent from functions.csv); 2 = 0x6d96d0; 3 = 0x6d97f0; 4 = 0x6234dc; 5 = 0x6233f0; 6 = 0x623660; 7 = 0x6d984c.
