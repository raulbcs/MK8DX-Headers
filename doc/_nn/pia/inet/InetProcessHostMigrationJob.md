# nn::pia::inet::InetProcessHostMigrationJob

RTTI-named: typeinfo slot 0x12da890 -> typeinfo data 0x12da930, name string
0xf7ec50 "N2nn3pia4inet27InetProcessHostMigrationJobE"; base typeinfo listed at
0x12de220 = nn::pia::session::ProcessHostMigrationJob (name 0xf81990). GOT cell
0x1312ab8 holds 0x12da888 (vptr - 0x10; offset-to-top 0). Installed vptr =
0x12da898. 19 fn slots (0x12da898-0x12da928). This is the inet twin of
nn::pia::lan::LanProcessHostMigrationJob (same base C1 0x98ffbc and member-init
helpers).

## Member notes

- Slots: 0 = D1 entry 0x938ce8, 1 = D0 tail 0x938e68 (both inside
  FUN_7100938ce8); slots 2/3 = shared pia job-interface pair 0xb4a654/0xb4a67c;
  slots 4-6 include 0x933314/0x99034c family stubs; slot 7-10 = entries inside
  InetSendRankDecision / HostMigrationFailure; slot 11 =
  InetProcessHostMigrationJob::ManualHostMigration (0x938e8c); slots 15-18 =
  InetSendRankDecision override set (0x939570/0x93a064/0x939490/0x939510).
- this+0xd4: flag byte written by base C1 (gates lan-sibling conditional init;
  unverified here).
- this+0x128: owned child, new(0xc0) via 0xa2bf88 (C1 0x938c10-0x938c30).
- this+0x130: member subobject initialized by 0x929ec0, destroyed by 0x929ee0
  (size unknown, unverified).
- this+0x150/+0x160: zeroed; this+0x168 = 60000; this+0x208..+0x218 zeroed.

## Construction / init order

- Factory at 0x9318d4: thread-id getter 0x563b70, then operator new(0x220) via
  pia allocator 0x568aa0, then C1 0x938bc0 - size 0x220 proven.
- C1 0x938bc0: base C1 0x98ffbc -> vptr 0x12da898 -> member 0x929ec0(this+0x130)
  -> child new(0xc0) at +0x128 -> zero/constant stores above.
- D1/D0: single body FUN_7100938ce8; D1 tail chains 0x938e78 back into itself,
  destroys member +0x130 via 0x929ee0, then the base destroy path.
