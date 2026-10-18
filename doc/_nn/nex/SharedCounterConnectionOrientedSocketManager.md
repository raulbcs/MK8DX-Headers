# nn::nex::SharedCounterConnectionOrientedSocketManager

`nn::nex::SharedCounter<nn::nex::ConnectionOrientedSocketManager,
nn::nex::ConnectionOrientedSocketManager,
nn::nex::SharedPtrDefaultDeleter<ConnectionOrientedSocketManager>>`
(RTTI-confirmed; mangled name read at ti 0x12e4500 -> 0xf84850).

- Identity: RTTI slot precedes the table: row 0x12e3748 holds ti 0x12e4500.
  GOT cell 0x13146e8 holds 0x12e3740 (row-0x8); installed vptr = cell+0x10 =
  0x12e3750 (row+8). 38 slots (0x12e3750..0x12e3878).
- Multiple inheritance: the base C1 path installs a primary base vptr
  0x12e2d98 (cell 0x1314328) at [this] and a secondary base vptr 0x12e33e0
  (cell 0x1314330) at +0x10 (0x7100a032e8/0x7100a032f8); the final ctor then
  overrides [this] with 0x12e3750.
- slot1 D1 = FUN_7100a03cfc (reinstalls vptr from cell 0x13146e8 at
  0x7100a03d18, then tears down +0x100 refcount via 0xa0420c and a CAS
  decrement); slot3 = FUN_7100a0ba1c; slot4 = FUN_7100a0bbb0. Slots 7-15 and
  17-28 are 8-16 B thunks (0xa19304..0xa193a0 region); slot16 =
  FUN_7100a026c0 (552 B); slot30 = FUN_7100a0518c (5760 B).
- Ctor: FUN_7100a032b0 (site 0x7100a03384). Installs the two base vptrs,
  then zeroes +0x80..+0xc0 region pieces, allocates 8-byte list nodes into
  +0x18, +0xc8/+0xd0 (head/tail self-loop at 0x7100a033ac-0x7100a033b0) and
  +0xe0..+0xf0 (0x7100a033d0-0x7100a033f0), stores ctor arg x1 at +0x8 and
  the final vptr at [this] (0x7100a033a0).
- Extent: 0x4c8 — caller 0x7100a0cc04 allocates 0x4c8 bytes before calling
  the ctor (0x7100a0cc24) with (x1=0x7100a0cc1c x19, x2=x20, x3=x19+0xe0,
  x4=[x19+0x160]); the caller later writes +0xc0.h (0x7100a0cc38).

## Member notes

- +0x8: stored ctor argument (x1) — unverified semantics.
- +0x10: secondary base vptr 0x12e33e0 (MI).
- +0x18: pointer to an 8-byte allocation (0x7100a03344/0x7100a03360).
- +0xc8/+0xd0/+0xd8 and +0xe0/+0xe8/+0xf0: two intrusive list head/tail pairs
  seeded with self-referential nodes — unverified semantics.
- D1 reads +0x100 (refcount object) — field beyond the ctor's stores, inside
  the 0x4c8 allocation.

## Construction / init order

1. Caller allocates 0x4c8 bytes and calls FUN_7100a032b0.
2. Base C1 path installs base vptrs 0x12e2d98 / 0x12e33e0.
3. Members are zero-filled; list nodes are allocated and self-looped.
4. Final vptr 0x12e3750 overrides [this]; arg x1 stored at +0x8
   (0x7100a033a0).
