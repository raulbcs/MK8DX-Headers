# object::Vt12c9db0

PLACEHOLDER name (identity not proven). Vtable `.data 0x12c9db0`, GOT cell
`0x1308130` addend `0x12c9da0` (vt-0x10); installed vptr = cell + 0x10. No
typeinfo row (no RELA at vt-0x10/vt-8).

Primary table = 15 slots (0x78), then a zero offtop/typeinfo pair at +0x78,
and further MI sub-tables from +0x88 (offset-to-top -0xf0 at 0x12c9ff0).
Actor interface slots: +0x58/+0x60/+0x68 = 0x1cbc / 0x7b97a8 / 0x7b97b4.

## Member notes

- ctor 0x7f8488 (ICF clones: D2 0x3d7678, D1 0x3d76ac, 0x3d7678 slot +0x10,
  0x7f8488 slot +0x18): installs the vptr at [this], then constructs the
  embedded member at this+0xe0 (member ctor 0x6286a4; teardown helper
  0x7b978c). Slots +0x00/+0x08 = 0x3d7550 / 0x3d761c (unrecovered).
- Concrete init is inlined in the factories 0x3dfb54 and 0x8bd138
  (`new 0x128`, helper ctor 0x7b976c):
  - 0x38 `{x=-1,0}`, id pairs -1 at 0x48/0x60/0x78/0x90/0xa8, `{x=-1,0}` at
    0x50/0x68/0x80/0x98 (0x3dfb9c-0x3dfbd0).
  - 0xc0/0xc8 zeroed, 0xd0 = 2, 0xd8 = 0; 0x120 u16 / 0x122 byte zeroed.
  - 0x18 = this, 0x28 = owner (factory arg), 0x30 = owner+0x30 (0x3dfbe8).
  - 0x20 = refcounted member: release 0x60b630 / re-acquire 0x60b618 with
    [member+0x10] refcount (0x3dfc0c-0x3dfc34).
- After full init the factory overwrites [this] with the final derived vptr
  0x1264480 ([cell 0x1308340] + 0x10) — 0x12c9db0 is the pre-override vptr.

## Construction / init order

1. Factory: `new 0x128` → 0x7b976c(this) (embedded member init).
2. Factory: vptr ← 0x12c9db0, id table 0x38..0xd8, back-ptrs 0x18/0x28/0x30,
   member attach at 0x20, u16/byte 0x120/0x122.
3. Factory: bl 0x628628(this) then vptr ← derived 0x1264480 (0x3dfbd4-0x3dfbf8).
4. Destructors: vptr store, member teardown at this+0xe0 (0x6286a4), 0x7b978c,
   D1 additionally `operator delete` (0x60b470).
