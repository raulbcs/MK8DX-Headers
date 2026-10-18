# nn::nex::ConnectionManager

## Identity

- Assigned row 0x12e2bf0; installed vptr = 0x12e2bf8.
- GOT cell 0x13142b0 holds addend 0x12e2be8 = vptr-0x10; installed vptr =
  cell+0x10. Typeinfo pointer at vptr-8 = 0x12e2bf0 points to RTTI record
  0x12e3f30 "nn::nex::ConnectionManager"; record base ptr 0x12e3f10 =
  "nn::nex::TransportEventHandler" (offset-to-top slot 0x12e2be8 = 0).
- 8 vtable slots at 0x12e2bf8: 0x9e3a20 (D2), 0x9e3ab4 (D1, both inside the
  FUN_71009e3884 cluster), tiny thunks 0x9f8a54/0x9f8a58/0x9f8a60/0x9f8a5c,
  0x9e4364 (342 B), 0x9e429c.

## Member notes

- +0x108: StreamTable subobject; D2 installs secondary vptr 0x12e3488 from
  cell 0x13142c0 (typeinfo record 0x12e4370 "nn::nex::StreamTable").
- +0x110/+0x118/+0x120: intrusive list links unlinked by D2 0x9e3a20
  (pred/next swap, head at +0x120 checked non-null).
- Size: lower bound 0x128 from D2 stores. No allocating factory found;
  third install site FUN_71009e3570 (0x9e3590) also loads the secondary cell -
  exact extent unverified.

## Construction / init order

1. Install vptr 0x12e2bf8 from cell 0x13142b0 (sites 0x9e3590 in
   FUN_71009e3570; D-cluster 0x9e3a34/0x9e3ac8 in FUN_71009e3884).
2. Install StreamTable vptr 0x12e3488 at +0x108 from cell 0x13142c0.
3. Destruction (D2 0x9e3a20): reinstall both vptrs, unlink +0x110 list
   links, then recurse into base.
