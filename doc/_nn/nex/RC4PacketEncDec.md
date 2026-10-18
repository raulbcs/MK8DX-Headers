# RC4PacketEncDec

- RTTI-named: typeinfo 0x12e4290, name string 0xf84580
  "N2nn3nex15RC4PacketEncDecE"; base typeinfo 0x12e4270 (PacketEncDecInf,
  itself based on RootObject 0x128c3b0).
- GOT cell convention: cell 0x1314560 holds 0x12e3230 = vptr - 0x10
  (offset-to-top word; row: offset-to-top 0 at 0x12e3230, typeinfo at
  0x12e3238). Installed vptr = 0x12e3240. 9 fn slots at vptr+0x00..+0x40.

## Member notes

- +0x08/+0x10/+0x18 vector<void*>: C1 allocates 8 bytes via 0x576368 and
  pushes one null element (0x9f359c-0x9f35c4). D1 (slot 0) iterates the
  elements and releases each via its [vt+8] entry (0x9f36d8-0x9f36e8), then
  frees the buffer (0x5763ac).
- +0x20/+0x28/+0x30 second vector<void*>: same pattern (0x9f35c8-0x9f35e8).
- +0x38: heap object, alloc 0x298 via 0x573f04; body init 0x583dc8 +
  0x584230(x, 0); stored by C1 at 0x9f3690. D1 releases it via [vt+8]
  (0x9f371c-0x9f372c).
- +0x40: member, init 0x58b7dc (0x9f35ec); destroyed by 0x58bc04 (0x9f3740).
- +0x68 / +0x90: members, init 0x58b958(x, 0x20) (0x9f35f8 / 0x9f3604);
  destroyed by 0x58bc04 (0x9f3738 / 0x9f3730). (Body of 0x58b958 unverified.)
- +0xb8 u8 = 0 (0x9f3610); +0xba u16 = 1 (0x9f3614).
- Size 0xc0: max field store 0xba/0xbb; the sole embedder
  (DummyPacketEncDec, size 0xd0 proven) holds this object at +0x10, leaving
  exactly 0xc0.

## Construction / init order

- C1 = 0x9f3574 (in-place; sole caller is the inlined DummyPacketEncDec
  construction at 0xa038a4, this+0x10). Order: vptr install, vector +0x08,
  vector +0x20, +0x40 member, +0x68 member, +0x90 member, three 0x298
  allocations (two stored into the vectors' null slots, third at +0x38),
  finally +0xb8/+0xba flags.
- D1 = slot 0, 0x9f36a0 (re-installs vptr, releases vector elements, +0x38,
  members +0x90/+0x68/+0x40, frees both vectors).
- D0 = slot 1, 0x9f37c4 (calls D1, then operator delete 0x573f48).
- Slots (9): 0 = 0x9f36a0 (D1), 1 = 0x9f37c4 (D0), 2 = 0x9f3b38, 3 = 0x9f3dfc,
  4 = 0x9f4544, 5 = 0x9f3e50, 6 = 0x9f3cf0, 7 = 0x9f3eac, 8 = 0x9f43fc.
  Bodies unrecovered in functions.csv except slots 0/1.
