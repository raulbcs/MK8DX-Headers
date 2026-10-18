# nn::pia::session::JoinSessionJob

## Identity

- vtable row 0x12ddbd0 (tsv row = typeinfo slot), vptr 0x12ddbd8 = row + 8, 18 slots.
  GOT cell 0x1313760 holds 0x12ddbc8 = vptr - 0x10 (offset-to-top row 0x12ddbc8 = 0,
  descriptor slot 0x12ddbd0 = 0x12ddc70); installed vptr = cell + 0x10.
- RTTI: descriptor 0x12ddc70 = {0x10, name 0xf81560, base 0x12f8d30, 0};
  name 0xf81560 = "N2nn3pia7session14JoinSessionJobE"; base 0x12f8d30 = shared
  pia/nex job-base descriptor (same base as LocalHostMigrationJob).
- Slots: 0 D1 0x98242c, 1 D0 0x982470, 2 0xb4a654, 3 0xb4a67c, 4 0x933314
  (shared pia-job cluster; slots 2-4 identical in Ldn/LocalHostMigrationJob),
  5-7 0x983244/0x983248/0x976ff4 (unrecovered), 8 0x983158, 9 0x983180,
  10 0x9831a4, 11 0x941184, 12 null (reloc addend 0), 13 0x9831a0,
  14 0x98313c `JoinSessionJob::CompleteProcess`, 15-17 null relocs.
- D1 0x98242c: installs vptr at [this] and at [this+0x60] (post-increment store
  0x982450), destroys the +0x80 sub-object (0x9b20b4), the +0x60 sub-object
  (0x929ee0), tail 0xb4a62c (shared job-base D0). D0 0x982470: same body then
  operator delete 0x60b470.
- extent 0x118 is a LOWER BOUND (max C1 store 0x110 + 8); no operator-new site
  recovered (unverified tail).

## Member notes

- +0x58 = 0 (C1 0x9823f4); +0x60 sub-object vptr = 0x12ddbd8 (same table;
  D1 post-inc store), sub-ctor 0x929ec0; +0x80 sub-object built by 0x9b1fe8;
  +0xf8/+0x108/+0x110 = 0, +0x100 byte 0 (0x982410-0x98241c).
- [0x08,0x58) initialized by the shared base C1 0xb4a5e0 — unproven gap.
- Nearby function 0x9823b8 (stores a MethodTree string at [this+0x40] from
  0xf12118 and cell 0x1312a78 at [this+0x30]) belongs to the neighbouring
  JoinMeshJob-family layout — not attributed here (unverified).

## Construction / init order

1. C1 0x9823d8: base C1 0xb4a5e0(this) (0x9823e8).
2. vptr 0x12ddbd8 -> [this] (0x982400); [this+0x58] = 0 (0x9823f4).
3. Sub-object ctor 0x929ec0(this + 0x60) (0x982404).
4. Sub-object ctor 0x9b1fe8(this + 0x80) (0x98240c).
5. Tail zeroes: [0xf8] = 0, [0x100] byte = 0, [0x108] = 0, [0x110] = 0
   (0x982410-0x98241c).
