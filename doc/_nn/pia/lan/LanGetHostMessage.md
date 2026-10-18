# nn::pia::lan::LanGetHostMessage

Identity: typeinfo-row vtable, assigned row 0x12dd460 = typeinfo slot;
installed vptr **0x12dd468**; GOT cell 0x13133d0 holds vptr-0x10 (note: cell
not adjacent to the other lan-message cells); typeinfo record 0x12dd590
("N2nn3pia3lan17LanGetHostMessageE", base LanMessage ti 0x12dd570). 7 slots
(0x12dd468..0x12dd487), last slot null.

## Member notes

- Base LanMessage extent 0x20; type tag 4 written at +0x8 by both C1s
  (0x97d198 / 0x97d20c `orr w8,#0x4`).
- +0x18 u32: 0 by default C1, w1 by the C1-with-arg.
- +0x20 embedded sub-object (placeholder `Member`): vptr installed from GOT
  cell 0x1313c40 (+0x10 -> vptr 0x1313c50). Default C1 0x9b1fe8 stores the
  vptr then inits sub-objects at +0x08 and +0x40 (both via 0x9b38b8, 0x40
  stride -> size >=0x80, full extent unverified). Copy C1 0x9b2020 (x1 =
  source). Member dtor tail = 0x9b20b4. Dynamic payload size: slot4 =
  0x97da0c calls 0x9b21c0(this+0x20) and returns result + 0x10.
- Size 0xa0 lower bound (0x20 + 0x80 member; tail unverified).

## Construction / init order

1. Default C1 0x97d148 (0x100 bytes): ISerializable base init (0x97d158),
   LanGetHostMessage vptr (cell 0x13133d0, 0x97d180), member C1 0x9b1fe8 at
   this+0x20 (0x97d18c-0x97d194), tag 4 (0x97d198), 0 at +0x18 (0x97d184).
2. C1 0x97d1ac (0x120 bytes): w1 -> +0x18 (0x97d1f4), x2 -> member copy C1
   0x9b2020 at this+0x20 (0x97d1fc-0x97d208), tag 4 (0x97d20c).
3. D-tor clones: complete 0x97d9c4, deleting 0x97d9d8 (re-install vptr,
   this += 0x20, tail `b 0x9b20b4` = member destroy; deleting variant then
   `operator delete`).
