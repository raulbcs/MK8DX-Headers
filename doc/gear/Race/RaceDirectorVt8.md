# RaceDirectorVt8 (RaceDirector-family director)

Shares the prepare/enter/calc/exit hook block, slot4 SharedThunk_30vtables_710004cfbc. Vtable .data 0x12d0a60 (GOT cell 0x1311088), ctor 0x710087d9b8, 0x168 bytes (allocation at 0x398964: operator new[](0x168, nothrow)).

Base of a derived director (ctor 0x3a16a8 calls this then swaps the vptr to 0x1260dd8's; same 0x168 size). Both are spawned by the race job manager init (count at manager+0x1c0, list at +0x210, owner back-ptrs at +0x28/+0x30 per child).

## Fields

- 0x38 — zeroed on ctor; 0x3c unproven padding.
- 0x40 — zeroed on ctor (to 0x80).
- 0x80 — untouched by ctor (to 0xe8).
- 0xe8..0xef — {u32 id, u8 min, u8 sec, u16 ms} time record — same record shape as RaceKartChecker (builder 0x888c30): mTimeId_e8/mTimeMin_ec/mTimeSec_ed/mTimeMs_ee.
- 0xf0 — untouched by ctor.
- 0xf8..0x168 — three 0x28-byte recorder channel descriptors, as built by the ctor (cells are GOT addresses):
  - +0x00 0xf8 vt (cell 0x1311090); +0x08 fn (cell 0x12fae28); +0x10 name "" (rodata 0xed6af8); +0x18 vt2 (cell 0x13110a0); +0x20 owner = this.
  - second 0x120: vt (cell 0x1311098), 0x128 = 0, 0x130 cell 0x1311098.
  - third 0x148: vt (cell 0x13110a0), 0x150 owner = this, 0x158 fn, 0x160 = 0.
  The channel shape matches the recorder channel shape of RaceCheckerVt3's 0x38 sub-object.
- 0x108/0x140 — unproven gap (per header gap fields).

## Construction / init order

1. Ctor 0x710087d9b8 (allocation 0x398964: operator new[](0x168, nothrow)).
2. 0x38 = 0 (u32); 0x40-0x80 zeroed.
3. Time record built at 0xe8 with (9, 59, 999).
4. Three 0x28-byte channel descriptors at 0xf8/0x120/0x148 — {vptr, fn ptr (GOT 0x12fae28), name "" (rodata 0xed6af8), owner = this}.
5. Derived director ctor 0x3a16a8 calls this ctor, then swaps the vptr to 0x1260dd8's.

## Spawn

Race job manager init spawns both this and the derived director (count at manager+0x1c0, list at +0x210, owner back-ptrs at +0x28/+0x30 per child).
