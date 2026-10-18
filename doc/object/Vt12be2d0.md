# object::Vt12be2d0

PLACEHOLDER name. 0x38-byte element class of an inline array owned by
the container whose D1 0x732660 / D0 0x7326ec are recovered in
config/functions.csv as gsys::IModelProcedural (FUN_7100732660). The
container keeps [this+0xc8] = element array ptr and [this+0xc0] = count;
each element is 0x38 bytes (stride in the D1 teardown loop
0x732690-0x7326c0: mul x22, x8, #0x38) and receives this vptr.

- Identity: vptr = 0x12be2d0; [vptr-0x10]/[vptr-8] = 0. GOT cell
  0x130e978 holds 0x12be2c0 = vt-0x10.
- Size proof: container D1 element stride 0x38 and its per-element flag
  write [elem+0x30] (0x73294c-0x732960); slot2 writes up to +0x16.
- Sibling rows in the same page family: 0x12be028 (cell 0x130e970,
  used by the container D1 when re-installing element vptrs) and
  0x12be350 (cell 0x130e980 — the base row installed by base C1
  0x732a90, which Vt12b69c8's ctor calls first).
- Base C1 0x732aac is a bare `ret` (element ctor adds no state beyond
  the vptr); 0x732ab0 is the 4-byte deleting path.

## Member notes

- Slots (14): +0x00 D1 0x7329a0 (12 B: vptr re-install then base),
  +0x08 D0 0x7329b4 (36 B: re-install, base, operator delete),
  +0x10 slot2 init 0x732ab4 (20 B: stores x1 to +0x08, halfword w2 to
  +0x14 and +0x16, returns 1), +0x18 0x7329e8 (returns 2),
  +0x20 0x7329f0 (out-param filler: writes cell 0x12fae28+0x10 vptr and
  [this+0x28] into the caller's struct), +0x28 0x732a0c (returns
  flags&1), +0x30 0x732a18 and +0x38 0x732a20 (return 1), +0x40
  0x732a28 (returns 0), +0x48 0x732a30 (copies the global triplet at
  [0x12fb148] — ptr, u32, 0x7f7fffff — into the out-struct; a default
  params getter), +0x50 0x732a58 (returns 0), +0x58 0x732a60 and +0x60
  0x732a68 (return 1), +0x68 slot13 0x732a70 (vcall [mField08] vtable
  slot 0x290 with ([mField08], +0x16, out)).
- The constant-returning middle slots (0/1/2) are capability/version
  queries, not pure-virtual sentinels — the class is concrete.

## Construction / init order

1. Elements live inside the container's [this+0xc8] array; storage comes
   from the container allocation, no own new.
2. Container D1/D0 re-install this vptr per element before the `ret`
   base dtor 0x732aac.
3. Slot2 (0x732ab4) is the real initializer: target ptr + two copies of
   a u16 (count/id) into +0x14/+0x16; flag bit0 at +0x30 is managed by
   the container (0x73294c).
