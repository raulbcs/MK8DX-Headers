# SecureConnectionClient

- RTTI-named: typeinfo 0x12e77b0, name string 0xf86100
  "N2nn3nex22SecureConnectionClientE"; base typeinfo 0x12e73c0
  (ServiceClient).
- GOT cell convention: cell 0x1314d48 holds 0x12e7000 = vptr - 0x10.
  Installed vptr = 0x12e7010. 10 fn slots at vptr+0x00..+0x48.
- Size 0xb0 proven: factory (function containing 0xa416ac) allocates 0xb0
  via 0x573f04, calls base C1 0xa326c8(this, 2) (0xa416c4), installs this
  vptr (0xa416cc-0xa416dc), then builds the +0x20 member; object stored to
  caller+0x38 (0xa416e8). C1 exists only inlined at this site.

## Member notes

- +0x08..+0x1f: ServiceClient base region — unverified contents.
- +0x20: member region (0x90 bytes to extent). Factory init 0xa2cd30(this+0x20,
  0xb) at 0xa416e0, then 0xa27820 (0xa416e4). D1 destroys it via 0xa3045c
  (0xa3eff8) before the ServiceClient D-tail 0xa32868 (0xa3f00c).

## Construction / init order

- C1 (inlined, site 0xa416cc): base C1 0xa326c8(this, 2), vptr install,
  member +0x20 init 0xa2cd30 / 0xa27820.
- D1 = slot 0, 0xa3efd0: re-installs vptr (cell + 0x10, 0xa3efec-0xa3eff0),
  destroys +0x20 member via 0xa3045c, tail-calls base D-tail 0xa32868.
- D0 = slot 1, 0xa3f010: same body; adds operator delete.
- Slots (10): 0 = 0xa3efd0 (D1), 1 = 0xa3f010 (D0), 2 = 0xa41cdc, 3 =
  0xa41ce0, 4 = 0xa41ef4, 5 = 0xa420dc, 6 = 0xa421d8, 7 = 0xa42250, 8 =
  0xa3f058, 9 = 0xa42204. Slots 2-7/9 = shared ServiceClient stub set;
  bodies unrecovered in functions.csv.
