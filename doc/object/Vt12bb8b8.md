# object::Vt12bb8b8

PLACEHOLDER name. 0xd890 (55440 B) destroy-once singleton manager; its
oversized C1 references the strings "Diffuse" and "Turbo_area0"
(rodata 0xf03a99/0xf03aa1), suggesting a course/turbo-area (boost panel)
related registry.

- Identity: vptr = 0x12bb8b8; [vptr-0x10]/[vptr-8] = 0. GOT cell
  0x130e560 holds 0x12bb8a8 = vt-0x10.
- Singleton mechanics: accessor FUN_71006ffe20 returns [0x130e558];
  creator FUN_71006ffd98 (guard at [0x12fce58]) allocates 0xd890 via
  0x60b2a8, installs the +0x08 member vptr (cell 0x130e550) and stores
  this+8 in [0x130e558], then calls C1
  FUN_71006ffe78 (1572 B, 0x6ffe78-0x70049c). Destroyer 0x6ffe4c: vcall
  slot0 (D1), then slot1 (D0 = operator delete), clears [0x12fce58].
- Size proof: the 0xd890 allocation size at 0x6ffdbc.

## Member notes

- Slots (14): +0x00 D1 0x703518 (re-installs this vptr at 0x703528),
  +0x08 D0 0x70356c (re-install at 0x70357c), +0x10 0x7035c8 (12 B),
  +0x18 0x7035d4 (unrecovered), +0x20 0x703610 (56 B), +0x28 0x703648,
  +0x30 0x703698 (88 B), +0x38 0x7036f0 (88 B), +0x40 0x7028d4,
  +0x48 0x702a48, +0x50 0x702bf8, +0x58 0x702d3c, +0x60 0x702f74 and
  +0x68 0x7031a4 (both unrecovered; large FUN-region members).
- Embedded member at +0x08: vptr row 0x12bb898 (GOT cell 0x130e550,
  addend 0x12bb888 = vt-0x10) — sibling row directly before this table.
- C1 zero-stores +0x58/+0x60/+0x68 (x22 walk 0x6ffea8-0x6ffeb4),
  initializes the +0x38 member via 0x63194c, then the 16-iteration loop
  (stride 0xc0, 0x6ffed0-0x6ffeec) writes a vptr pair into each
  sub-object at +0x160 + i*0xc0: primary row 0x12bb8a0 (cell
  0x130e568) and secondary from cell 0x12fae28 + 0x10. Init continues
  past the loop with further global-celled stores (region 0x6ffef0+).

## Construction / init order

1. Creator 0x6ffd98: allocate 0xd890, publish [0x130e558] and this+8.
2. C1 FUN_71006ffe78: this-vptr 0x12bb8b8, +0x58/+0x60/+0x68 zeroed,
   +0x38 member ctor 0x63194c, 16 x 0xc0 sub-objects at +0x160,
   remaining member/global initialization through 0x70049c.
3. Destruction via accessor slot0/slot1 vcalls, then pointer clear.
