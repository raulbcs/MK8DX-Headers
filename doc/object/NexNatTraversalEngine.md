# nn::nex::NATTraversalEngine

## Identity

- Assigned row 0x12e30f0; installed vptr = 0x12e30f8.
- GOT cell 0x1314480 holds addend 0x12e30e8 = vptr-0x10; installed vptr =
  cell+0x10. Typeinfo pointer at vptr-8 = 0x12e30f0 points to RTTI record
  0x12e41f0 "nn::nex::NATTraversalEngine" (offset-to-top slot 0x12e30e8 = 0).
- 8 vtable slots at 0x12e30f8: 0x9eb400 (D2, unlinks the +0x1b0 qVector),
  0x9eb604 (D1; both inside FUN_71009e9bf0 cluster), 0x9f09e8 (1554 B),
  0x9f0c4c (1120 B), 0x9f0e18 (1824 B), 0x9f0f88.
- GOT cell 0x13144a8 (addend 0x12e30e0) is NOT a vtable row: consumers
  (0x9ef784) do `ldrsw` on it - it is the integer constant pair
  {0x2710, 0x5} = nex timeout config data, adjacent in .data only.

## Member notes

- Size 0x1c8 PROVEN: factory FUN_71009f2474 allocates w0 = 0x1c8 via
  0x573f04 (0x9f2644..0x9f2648).
- +0x08 zero word, +0x10..0x2f zeroed, +0x30..0x48 self-referencing list
  node (factory stores this+0x38 at +0x38/+0x40), +0x50..0x6f init pairs.
- +0xf8: secondary vptr 0x12e3580 from cell 0x1314428; its typeinfo record
  0x12e4450 = "nn::nex::URLProbeList"; vtable 0x12e3580 slots 0x9f9820/
  0x9f9898.
- +0x1b0..0x1c8: qVector of SharedPtr<SocketDriver::Socket> (elems +0x1b0,
  end +0x1b8, cap +0x1c0) unlinked by D2 0x9eb400.

## Construction / init order

1. FUN_71009f2474: operator-new 0x1c8 (0x9f2644, allocator 0x573f04).
2. Zero/tag fields +0x08..+0x48; install primary vptr 0x12e30f8 (0x9f265c,
   cell 0x1314480); init list node and +0x50/+0x58 pairs.
3. Sub-init of the +0xf8 URLProbeList secondary: install vptr 0x12e3580
   from cell 0x1314428 (0x9f2680..0x9f269c), then further member inits.
4. Destruction: D2 0x9eb400 (cell 0x1314480) unlinks +0x1b0 vector and
   destroys elements before base teardown.
