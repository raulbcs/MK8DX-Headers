# nn::pia::local::LdnForceDisconnectNetworkJob

## Identity

- vtable row 0x12e1150 (tsv row = typeinfo slot), vptr 0x12e1158 = row + 8,
  6 slots. GOT cell 0x1313e78 holds 0x12e1148 = vptr - 0x10 (offset-to-top
  0x12e1148 = 0, typeinfo slot 0x12e1150 = 0x12e1190); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12e1190 = {0x10, name 0xf831a0, base 0x12e1860, 0}; name =
  "N2nn3pia5local28LdnForceDisconnectNetworkJobE"; base 0x12e1860 =
  nn::pia::local::LocalForceDisconnectNetworkJob.
- Slots: 0 D1 0x9cb898 (4-byte tail b 0x9cf8cc = base D1), 1 D0 0x9cb89c
  (base D1 0x9cf8cc then operator delete 0x60b470), 2 ret 0xb4a654, 3 ret
  0xb4a67c, 4 ret 0x933314 (shared StepSequenceJob cluster), 5 bare `ret`
  0x9cb8c0.
- size 0x68 EXACT: operator new 0x68 at 0x9bfa94 (caller 0x9bfaac); sole site
  found.

## Member notes

- [0x08, 0x68) = LocalForceDisconnectNetworkJob base subobject (base C1
  0x9cf894) — unproven gap here; derived C2 adds no fields of its own.

## Construction / init order

1. C2 0x9cb868: base C1 0x9cf894(this) — LocalForceDisconnectNetworkJob C1
   (0x9cb878).
2. vptr 0x12e1158 -> [this] (0x9cb888, cell 0x1313e78 + 0x10).
- Factory: operator new 0x68 at 0x9bfa94, C2 0x9cb868 at 0x9bfaac.
