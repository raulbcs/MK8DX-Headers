# NexSessionSearchCriteriaParticipant (nn::pia::inet::NexSessionSearchCriteriaParticipant)

## Identity

- Assigned row 0x12da390 is the TYPEINFO SLOT, not the vptr: [0x12da390] =
  0x12da3c0 (reloc) = typeinfo record {0x10, name 0xf7e9d0, base 0x12de790}.
  Name is exact: "N2nn3pia4inet35NexSessionSearchCriteriaParticipantE"
  (35-char identifier). Base record 0x12de790 =
  "N2nn3pia7session21SessionSearchCriteriaE" (root).
- Installed vptr = 0x12da398 (row+8), 5 slots.
- GOT cell 0x13129a8 holds addend 0x12da388 = vt-0x10; C1 0x9352dc does
  `ldr cell 0x13129a8; add #0x10; str [this]` (0x935308).
- Extent 0x980: C1 0x9352dc writes 0x978 and bytes 0x97c..0x97f; zero-fill loop
  covers 0x18..0x977 in 0x20-byte entries (75 entries, 0x960 bytes).

## Slots (vptr 0x12da398, 5 slots)

- slot 0 = 0x93534c (D1: tail `b 0x99d2b0` = base SessionSearchCriteria D2).
- slot 1 = 0x935350 (D0: base D2 then `operator delete` 0x60b470).
- slot 2 = 0x9353f4 (error-code setter: stores 0x10000|0xc08 = 0x0c08_0000 via
  [x8]; result-code path).
- slot 3 = 0x935374 (88 B, functions.csv-unrecovered).
- slot 4 = 0x935404 (`ret` stub; 4 B before FUN_7100935408).

## Member notes

- 0x10 — C1 sets 2.
- 0x18..0x977 — array of 0x20-byte entries zeroed by C1 loop
  (0x935324..0x93533c); entry layout unverified.
- 0x978 — C1 zero; 0x97d/0x97e — C1 sets 1.

## Construction / init order

1. C1 0x9352dc (FUN_71009352dc): base C1 0x99d294 first (0x9352ec).
2. vptr 0x12da398 at [this] (0x935308); scalar init; 0x20-byte entry zero loop.
3. Always constructed into an owner subobject: caller 0x912d24 places it at
   owner+0x4218 of the large pia session aggregate (owner fields to 0x4bb1).
