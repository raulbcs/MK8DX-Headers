# nn::nex::ClientProtocol

- Identity: RTTI-confirmed, typeinfo object 0x12e62e0, mangled name
  `N2nn3nex14ClientProtocolE`. Assigned row 0x12e59b8 is the typeinfo-slot
  row: offset-to-top 0 at 0x12e59b0, typeinfo at 0x12e59b8, installed vptr =
  0x12e59c0. GOT cell 0x1314930 holds 0x12e59b0 (vptr-0x10); the cell is
  consumed by the C1 and both D-variants.
- Size 0x90. Base class is constructed in place (no own factory `new` found
  in the un-recovered lump); derived protocol composites embed it at +0x140
  and allocate 0x150+ records via 0x573f04 (e.g. factory body at 0xb04b64,
  protocol id 0x6d = 109 at 0xb04b88). Matches the 0x90 nex protocol-client
  family from vt-map/9a (protocol ids 10/11).
- Base of the 24-slot DDL family 0x12f7070/0x12f85d0/0x12f89f0 (batch 9c);
  their base ctor 0xa27e78 is this class's C1.

## Member notes

| Offset | Field | Evidence |
|---|---|---|
| 0x00 | vptr | C1 store 0xa27f0c |
| 0x48 | u16, 0 | C1 0xa27ee4 (`strh wzr`) |
| 0x50/0x58 | ptrs, 0 | C1 0xa27ef0 (`stp xzr, xzr`) |
| 0x60 | u32 protocol id (w1 of C1) | C1 0xa27ee8 |
| 0x68/0x78 | ptrs, 0 | C1 0xa27ef4/0xa27efc |
| 0x70 | u8, 0 | C1 0xa27ef8 |
| 0x80 | u32, 0 | C1 0xa27f00 |
| 0x88 | refcounted handle ptr | D-variants atomically decrement
  `[ptr+8]` (ldar/ldaxr/stlxr at 0xa27f58..0xa27f6c) and free at 0 |

Registration: C1 builds a SafeString (data 0xf15048, the
"...b::AllowParticipating" suffix string) and inserts it into the global
`std::__tree` rooted at 0x130b4a8 (0x587544) — protocol-name registration;
0x587544/0x5790b4 build/destroy the stack node (0xa27ec8..0xa27ee0).

Slots (21): 0xa3045c, 0xa27f2c (D-variant, re-installs vptr then releases
+0x88), 0xa30318, 0xa30324, 0xa30384, 0x591864, 0x591868, 0x591874,
0xa2bd80, 0x591880, 0xa2bdb4, 0x591888, 0x5901e8 (`__tree` helpers),
0x5902dc, 0x591890, 0x591898, 0xa30388, 0xa30390, 0xa30394, 0xa30398,
0xa303a0. Sites installing the vptr: 0xa27f04 (C1), 0xa27f40 (D-variant),
0xa30470 / 0xa30564 / 0xa30718 (derived-class D-variants sharing the cell).

## Construction / init order

- C1 = 0xa27e78: tree registration first (0xa27ec8..0xa27ee0), then field
  zeroing (0xa27ee4..0xa27f00), +0x60 = protocol id (0xa27ee8), +0x88 = 0,
  vptr store last (0xa27f0c).
- Size 0x90: deepest store +0x88 + 8; consistent with the 0x90 protocol
  clients proven in vt-map/9a (unverified by a direct allocation of this
  exact type).
