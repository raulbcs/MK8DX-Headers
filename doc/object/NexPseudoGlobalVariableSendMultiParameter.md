# nn::nex::PseudoGlobalVariable<SendMultiParameter>

## Identity

- Assigned row 0x12e2860; installed vptr = 0x12e2868.
- GOT cell 0x1314180 holds addend 0x12e2858 = vptr-0x10; installed vptr =
  cell+0x10. Typeinfo pointer sits at vptr-8 = 0x12e2860 and points to the
  RTTI record 0x12e28b0 (offset-to-top slot 0x12e2858 = 0).
- RTTI: "nn::nex::PseudoGlobalVariable<SendMultiParameter>" (name data at
  0xf83b30, record 0x12e28b0). The neighbouring record 0x12e2840
  ("nn::nex::SharedPtr<nn::nex::SocketDriver::Socket>") belongs to a different
  vtable (vptr 0x12e2828, ti at 0x12e2820) - not this class.

## Member notes

- 8 vtable slots at 0x12e2868: 0x9d4b98 (D1), 0x9e0114 (D0), 0x9e0180
  (800 B), 0x9e02c0 (320 B), 0x9e034c (1878 B), 0x9e038c (getter
  `ldr x0,[x0,#8]; ret`), 0x9e0394 (setter `str x1,[x0,#8]`), 0x9e039c.
- D1 0x9d4b98 / D0 0x9e0114: reinstall vptr from cell 0x1314180, unlink from
  the global nex instance __tree rooted at 0x130b940 (balance call
  0x58c4d8/0x58c448), destroy the member at +0x168 and further subobjects
  (+0x20 vptr-indirect call into slot 3).
- Size: member destroy at +0x168 gives lower bound 0x170. No allocating
  factory found (all three install sites 0x9d4aa0/0x9d4ba8/0x9e0124 are in
  D-cluster FUN_71009d4a80/FUN_71009d4b98/FUN_71009e0114); objects are static
  globals - exact extent unverified.

## Construction / init order

1. Instances are static globals registered by init code (see tree insert at
   0x9d4bc4 with root 0x130b940); no heap factory observed.
2. D1/D0 reverse the registration: vptr reinstall (0x9d4ba8/0x9e0124),
   tree unlink, member destruction in reverse order.
