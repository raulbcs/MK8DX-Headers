# nn::pia::transport::PacketHandler

RTTI-named: typeinfo slot 0x12dee10 -> typeinfo data 0x12deeb0, name string
0xf821c0 "N2nn3pia9transport13PacketHandlerE"; base typeinfo listed at
0x12def00 = nn::pia::transport::ProcessConnectionRequestJob (name 0xf821f0).
GOT cell 0x1313b48 holds 0x12dee08 (vptr - 0x10; offset-to-top 0). Installed
vptr = 0x12dee18. 19 fn slots (0x12dee18-0x12deea8).

## Member notes

- Slots: 0 = D1 entry 0x9a6aec (tail of FUN_71009a6a94), 1 = D0 0x9a6b5c;
  slots 2-8 = entries inside the FUN_71009a54a4 blob (C1 region); slots 9-18 =
  FUN_71009a6a94 / FUN_71009a670c / FUN_71009a674c / FUN_71009a67c0 /
  FUN_71009a6938 / FUN_71009a6b5c entries — none recovered by name in
  functions.csv (unresolved override set).
- this+0x18: subobject ctor 0x9a89e0 (size unknown, unverified).
- this+0x418: subobject ctor 0x9a859c (0x60 to +0x478 by store pattern,
  unverified).
- this+0x490: self-pointer (C1 stores this); +0x498..+0x4b0 zeroed.
- this+0x4b8: subobject ctor 0x929fc4.
- this+0x4d0/+0x4d8/+0x4e0: zeroed.
- Size: deepest C1 store at +0x4e0 -> lower bound 0x4e8; no new-size site found
  (C1 also called in-place from array contexts, e.g. 0x9a5224), unverified.

## Construction / init order

- C1 0x9a54a4 (ctor body 0x9a5710): zero +0x10 -> vptr 0x12dee18 at [this] ->
  subobject +0x18 (0x9a89e0) -> subobject +0x418 (0x9a859c) -> zero
  +0x478..+0x4b0, self-ptr +0x490 -> subobject +0x4b8 (0x929fc4) -> zero
  +0x4d0..+0x4e8.
- D1 0x9a6aec / D0 0x9a6b5c reinstall the vptr from cell 0x1313b48 and chain
  the member destructors above (body FUN_71009a6b5c re-runs the +0x418
  subobject destruction at 0x9a5784).
