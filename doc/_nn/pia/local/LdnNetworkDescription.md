# LdnNetworkDescription (nn::pia::local::LdnNetworkDescription)

- vptr 0x12e01b8 installed from GOT cell 0x1313d50 (RELATIVE addend 0x12e01a8 =
  vt-0x10; code does `cell+0x10`). vt_ctors.tsv row 0x12e01b0 is the typeinfo
  slot. Typeinfo 0x12e0210, name
  "N2nn3pia5local21LdnNetworkDescriptionE", base
  nn::pia::local::LocalNetworkDescription (typeinfo 0x12e0200).
- Size 0x488, proven by the heap allocation `0x568aa0(0x488)` at 0x9bf0ac whose
  object gets this vptr at +0 and a 0x480-byte memset at +0x08 (mgr init around
  0x9bf070, result stored at [mgr+0x2e0]). Also embedded at +0x10 of the
  0xbe0 LdnSessionInfo (C2 0x9c1a80) and at +0x00 of a 0x6cc0 init
  (0x9bf71c region, vptr override target).

## Identity

Data carrier describing the current LDN network; its vtable is a pure getter
set over a 0x480-byte zeroed payload — no D1/D0 slots observed.

## Slots

Primary vtable 0x12e01b8, 9 slots (all getters over the payload):
- slot 0 = 0x9c1930: if byte +0x53 == 2 return (signed) byte +0x6f else 0
- slot 1 = 0x9c194c: same guard, returns (signed) byte +0x6e
- slot 2 = 0x9c1968 (U, 280): guard +0x53==2, returns (+0x6a == 0)
- slot 3 = 0x9c198c: returns u16 +0x50
- slots 4..8 = 0x9c1994 / 0x9c19bc / 0x9c19ec / 0x9c19d8 / 0x9c19dc
  (0x9c1994 takes an argument; rest unrecovered)

## Member notes

- 0x00 — vptr.
- 0x08..0x487 — 0x480-byte payload, memset to 0 by every init path
  (0x9bf0d8, 0x9bf738, 0x9c1acc). Getters read +0x50, +0x53, +0x6a, +0x6e,
  +0x6f inside it; exact field semantics unverified.

## Construction / init order

1. Heap form: `0x568aa0(0x488)` (0x9bf0ac), vptr from cell 0x1313d50 stored at
   +0, memset(+0x08, 0, 0x480).
2. Embedded form: LdnSessionInfo C2 0x9c1a80 installs the LocalNetworkDescription
   base vptr (cell 0x1313d60 + 0x10) at [this] and this vptr at [this+0x10],
   then memset(+0x18, 0, 0x480).
3. Collection form: init 0x9bf71c news 0x6cc0, installs this vptr at +0,
   memsets the 0x480 payload, then builds sibling 0x480-byte blocks at
   +0x490/+0x918/+0xda0/+0x1228/+0x16b0/+0x1b38 (template pointer x21 stored
   ahead of each block).
