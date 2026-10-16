# KartChassis

## Identity

KartChassis — size 0x510, proven by operator new(0x510) in the KartVehicle
ctor (v400 0x7100170298, stored at KartVehicle+0x50; ctor 0x710011c0c4).
Name CONFIRMED by the recorder channel string "RecorderKartChassis"
(rodata 0xee5f99, plus a "RecorderKartChassisPackun" variant). Runtime cross-evidence: FUN_7100174ea8 reads a float at +0x198
(multiplied by KartVehicle+0x118), FUN_7100174cc4 a u8 at +0x1C0, and the
drift-state accessors (0x71001420e4/21b4/23d8, 0x710017b9xx-bcxx family)
reach a KartVehicleDrift object (name from the recorder channel
"RecorderKartVehicleDrift", rodata 0xee602a) through +0x110.

## Member notes

Notes in field order; proven from the cited addresses.

- KartVehicle.hpp
- 0x00 — vtable ptr
- 0x08 — ctor arg (0x11c100)
- 0x10 — ctor zeroes (incl. the +0x10 subcomponent handed to KartChassisAnim)
- 0x38 — ctor sets -1
- 0x3C — ctor sets -1
- 0x40 — unproven padding
- 0x48 — ctor sets -1
- 0x4C — unproven padding
- 0x58 — ctor sets -1
- 0x5C — unproven padding
- 0x60 - 0x6F — ctor zeroes ([0x60] and [0x68])
- 0x70..0x15F — five 0x30-byte blocks each memcpy'd from one shared default block (ctor 0x11c160-0x11c1a0: memsets at 0x70/0xA0/0xD0/0x100/0x130). Source block: GOT cell 0x12fd108 -> bss 0x7101328d28, a 0x30-byte default block populated by static init before any kart exists (not rodata). The ctor then overwrites nine cells with 1.0f inside the last block (0x13C..0x15F).
- 0x160 — ctor arg: KartUnit flagC9cSel (isKartUnitFlagC9cSel_710014c3a8)
- 0x161 — ctor arg: KartUnit fb1 && !fae (isKartUnitFlagFb1AndNotFae_710014c454)
- 0x162 — ctor arg: (KartVehicle+0xC4 == 1)
- 0x163 — unproven padding
- 0x16C — ctor sets 0.2f (0x3E4C0000)
- 0x170 — ctor sets 0x4CCCCCCC
- 0x174 — ctor sets -4.0f
- 0x178 — ctor sets 0xFFFFFFFF
- 0x17C — unproven padding
- 0x184 — ctor sets {1.0f, 1.0f}
- 0x18C — ctor sets 2.0f
- 0x190 — unproven padding
- 0x1B0 — ctor sets 1.0f
- 0x1B4 — ctor sets 0.1f (0x3DCCCCCD)
- 0x1B8 — ctor sets 0.1f
- 0x1BC — unproven padding
- 0x1C0 — small polymorphic subobject initialized by 0x710016f7e4 (vtable [0x12fd610]+0x10, zeros +0x10..0x20, flag +0x20); byte read by FUN_7100174cc4
- 0x1E8 - 0x223 — ctor zeroes (incl. 0x208 u8, 0x20C/0x214/0x21C u64s)
- 0x224..0x283 — two more 0x30 template blocks
- 0x284 - 0x2F7 — ctor zeroes (0x284-0x2B7 pairs, 0x2C0-0x2F7 u64s)
- 0x2F8 - 0x30F — unproven padding
- 0x310 — ctor sets {1.0f, 1.0f, 1.0f}
- 0x31C — ctor sets both to 0xFFFF
- 0x320
- 0x321 — unproven padding
- 0x324 — ctor zeroes through 0x343
- 0x344 — ctor sets -1 (unaligned u64 store 0x344)
- 0x348 — upper half of the -1 store
- 0x34C — ctor sets -1
- 0x350
- 0x351 — unproven padding
- 0x354 — ctor zero (unaligned u64 store 0x354)
- 0x358 — upper half
- 0x35C - 0x36F — ctor zeroes (0x360/0x368)
- 0x370 — ctor sets both to -1
- 0x378 — ctor sets all three to 0xFFFF
- 0x37E — unproven padding
- 0x380 — ctor sets -1
- 0x384 — ctor sets -4.0f
- 0x388 — ctor sets 0xFFFFFFFF
- 0x38C — unproven padding
- 0x394 — ctor sets 1.0f
- 0x398 — unproven padding
- 0x3A8 — second sub-init call 0x710016f7e4
- 0x3E0 — unproven padding
- 0x3EC — another 0x30 template block
- 0x41C — 0x510 total

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x08 — ctor arg (0x11c100)
- 0x10 — ctor zeroes (incl. the +0x10 subcomponent handed to KartChassisAnim)
- 0x38 — ctor sets -1
- 0x3C — ctor sets -1
- 0x48 — ctor sets -1
- 0x58 — ctor sets -1
- 0x60 - 0x6F — ctor zeroes ([0x60] and [0x68])
- 0x70..0x15F — five 0x30-byte blocks each memcpy'd from one shared default block (ctor 0x11c160-0x11c1a0: memsets at 0x70/0xA0/0xD0/0x100/0x130). Source block: GOT cell 0x12fd108 -> bss 0x7101328d28, a 0x30-byte default block populated by static init before any kart exists (not rodata). The ctor then overwrites nine cells with 1.0f inside the last block (0x13C..0x15F).
- 0x160 — ctor arg: KartUnit flagC9cSel (isKartUnitFlagC9cSel_710014c3a8)
- 0x161 — ctor arg: KartUnit fb1 && !fae (isKartUnitFlagFb1AndNotFae_710014c454)
- 0x162 — ctor arg: (KartVehicle+0xC4 == 1)
- 0x16C — ctor sets 0.2f (0x3E4C0000)
- 0x170 — ctor sets 0x4CCCCCCC
- 0x174 — ctor sets -4.0f
- 0x178 — ctor sets 0xFFFFFFFF
- 0x184 — ctor sets {1.0f, 1.0f}
- 0x18C — ctor sets 2.0f
- 0x1B0 — ctor sets 1.0f
- 0x1B4 — ctor sets 0.1f (0x3DCCCCCD)
- 0x1B8 — ctor sets 0.1f
- 0x1E8 - 0x223 — ctor zeroes (incl. 0x208 u8, 0x20C/0x214/0x21C u64s)
- 0x284 - 0x2F7 — ctor zeroes (0x284-0x2B7 pairs, 0x2C0-0x2F7 u64s)
- 0x310 — ctor sets {1.0f, 1.0f, 1.0f}
- 0x31C — ctor sets both to 0xFFFF
- 0x324 — ctor zeroes through 0x343
- 0x344 — ctor sets -1 (unaligned u64 store 0x344)
- 0x34C — ctor sets -1
- 0x354 — ctor zero (unaligned u64 store 0x354)
- 0x35C - 0x36F — ctor zeroes (0x360/0x368)
- 0x370 — ctor sets both to -1
- 0x378 — ctor sets all three to 0xFFFF
- 0x380 — ctor sets -1
- 0x384 — ctor sets -4.0f
- 0x388 — ctor sets 0xFFFFFFFF
- 0x394 — ctor sets 1.0f
- 0x3A8 — second sub-init call 0x710016f7e4
