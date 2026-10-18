# nn::pia::session::LeaveMeshJob

Identity: typeinfo-row vtable, assigned address 0x12dde50 (= typeinfo slot,
vptr-8); installed vptr **0x12dde58**. GOT cell 0x13137c0 holds vptr-0x10
(0x12dde48 = offset-to-top 0). Typeinfo data 0x12dde90, name
"N2nn3pia7session12LeaveMeshJobE", base typeinfo 0x12f8d30
("N2nn3pia6common15StepSequenceJobE"). 6 slots (0x12dde58..0x12dde88).

## Member notes

- Slot0 0x984ab4: D1, tail `b 0xb4a62c` (base D1). Slot1 0x984ab8:
  D1 then operator delete 0x60b470.
- Slot2/3 0xb4a654/0xb4a67c: shared StepSequenceJob stubs. Slot4 0x933314.
- Slot5 0x98505c: reset — re-runs base C1 0xb4a5e0 on this.
- [this+0x60] u32 = 5000 (0x1388) — timeout-style constant set by C2.
- [this+0x68]/[this+0x70] zeroed by C2 (stp), [this+0x78] u8 zeroed by C2.

## Construction / init order

1. C2 FUN_7100984a70 (0x984a70..0x984ab0): base C1 0xb4a5e0 (0x984a80),
   [+0x58] = 0, [+0x60] = 5000, stp xzr,xzr [+0x68], vptr 0x12dde58 =
   cell 0x13137c0 + 0x10 (0x984a88..0x984aa0), [+0x78] = 0.
2. Factories FUN at 0x96cf64 and 0x93188c: operator-new sized 0x80
   (`orr w0, wzr, #0x80`) then C2. Extent 0x80 is proven by the
   allocation size.
