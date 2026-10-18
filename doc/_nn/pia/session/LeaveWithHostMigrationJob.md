# nn::pia::session::LeaveWithHostMigrationJob

Identity: typeinfo-row vtable, assigned address 0x12ddf60 (= typeinfo slot,
vptr-8); installed vptr **0x12ddf68**. GOT cell 0x1313838 holds vptr-0x10
(0x12ddf58 = offset-to-top 0). Typeinfo data 0x12ddfb0, name
"N2nn3pia7session25LeaveWithHostMigrationJobE", base typeinfo 0x12f8d30
("N2nn3pia6common15StepSequenceJobE"). 9 slots (0x12ddf68..0x12ddfa8).

## Member notes

- Slot0 0x985e34: D1, tail `b 0xb4a62c` (base D1). Slot1 0x985e38:
  D1 then operator delete 0x60b470.
- Slot2/3 0xb4a654/0xb4a67c: shared StepSequenceJob stubs. Slot4 0x933314.
- Slot5 0x986578: writes marker 0xc0810000 through global cell
  0x1312748 (logger-style; unverified).
- Slot7 0x9864ec: re-initializes [+0x70] = 0xfd and memsets the +0x74
  buffer (same constants as C2) — retry/reset-shaped. Unverified.
- Slots 6 and 8: null.
- [this+0x68] u32 = 5000 (0x1388), [this+0x70] u32 = 0xfd (253),
  [this+0x74..0x93] buffer zeroed by C2, [this+0x94] u8 zeroed by C2.

## Construction / init order

1. C2 FUN_7100985dd8 (0x985dd8..0x985e30): base C1 0xb4a5e0 (0x985de8),
   [+0x6c] = 0, stp xzr,xzr [+0x58], [+0x68] = 5000, [+0x70] = 0xfd,
   vptr 0x12ddf68 = cell 0x1313838 + 0x10 (0x985dec..0x985e10),
   memset(this+0x74, 0, 0x20), [+0x94] = 0.
2. Caller 0x9381c0 uses it as a base ctor and overrides the vptr with
   cell 0x1312aa8 + 0x10 (further-derived subclass); other callers
   (0x9318xx-region, 0x9d133c) similar. No dedicated factory operator new
   found; extent 0x98 is a lower bound from the +0x94 store.
