# object::Vt12c1ad0

Placeholder name (identity not proven). vptr 0x12c1ad0, 6 slots, typeinfo NULL (RTTI-less). GOT cell 0x130f188 holds 0x12c1ac0 = vt-0x10 (installed vptr = cell+0x10).

## Member notes

- size 0x40, exact — operator new(0x40, align 8) at 0x760BA8 in the shared factory 0x760B38.
- [this+0x08] ptr — installed from GOT cell 0x12fae28 with +0x10 adjust (addend 0x11ad200, a .data object); interpretation unverified.
- [this+0x10] ptr — rodata (0xed6af8 / 0xf07baa written at 0x760BEC and via 0x61C9BC from [sp+8]); final value unverified.
- [this+0x18]=1.0f, [this+0x20]=1.0f, [this+0x24]=2.0f, [this+0x28]=2.0f, [this+0x2C]=0, [this+0x30..0x3B]=-0.0f x3, [this+0x3C]=-2.0f — float parameter defaults stored at 0x760C00-0x760C2C.
- Slots: 0 = 0x760ED4 `ret`; 1 = 0x760ED8 deleting dtor (tail `b operator delete`); 2 = 0x75174C `add x0,#8; b 0x61C9BC` (copies [x1+8] into [this+8]); 3/4/5 = 0x760EDC/0x760EE4/0x760EEC `mov w0,wzr; ret`.

## Construction / init order

- Factory FUN_7100760B38 (0x760B38) switches on [arg]-1 (5 cases) and allocates 0x40 per case; this case is the block at 0x760BA8-0x760C30.
- Init order: [this+8] from GOT, [this+0x10] rodata ptr, base vptr 0x12c1b10 at [this] (single inheritance, same offset), helper 0x61C9BC, then derived vptr 0x12c1ad0 overwrites [this] and the float defaults are stored (0x760BF8-0x760C2C).
- The sibling secondary-band table 0x12c1b10 is NOT in the assigned set; only the derived primary row is mapped here.
