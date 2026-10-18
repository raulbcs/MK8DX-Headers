# KartParamCacheVt2e68

KartParamCacheVt2e68 — address-anchored name for secondary vtable
0x12b2e68 (offset-to-top -0xd0, null typeinfo slot, no RTTI). GOT cell
0x130d9e8 holds 0x12b2d90; code installs cell+0x10 (0x12b2da0, primary) at
[base+0x00] and cell+0xd8 (0x12b2e68, this secondary row) at [base+0x30].
No adrp/page-0x12b2000 reference and no RELATIVE reloc targets the row
directly — all installs go through the cell.

## Identity

- Slot row 0x12b2e68 (8 slots): slot0 D2 0x710064dc7c, slot1 D0
  0x710064dd64, slots 2-5 shared thunks 0x7100648094 (tail-call [this-0x30]
  slot 0x10), 0x71006480a0 (this+0xa0 ret), 0x71006480a8 (tail-call
  [this-0x30] slot 0x18), 0x71006480b4 (ret [this+0x82]&1); slots 6-7 null.
- The next row 0x12b2ea8 (sibling class KartParamCacheVt2f70's primary,
  cell 0x130d9f0) holds D1 0x710064e480 / D0 0x710064e560 and the shared
  paramNode stub band 0x7100647f40..0x7100647f68.

## Member notes

Proven from D2 0x710064dc7c / D0 0x710064dd64 (this = base+0x30 after the
x19 -= 0x30 adjust; offsets below are from that this):

- 0x00 — primary vptr 0x12b2da0 stored at [this-0x30].
- 0x30 — secondary vptr 0x12b2e68 stored at [this].
- 0x110/0x138/0x160/0x188/0x1a8/0x1d0 — six subobject vptrs rewritten from
  cell 0x130d918+0x10 = 0x12b3af0 (KartParamCacheChanBase) during
  destruction; the dtor skips 0x1b0.
- 0x1c8 — owned pointer: deleted (0x710060b4d4) if non-null, then nulled at
  0x1f8 with the u32 at 0x1f0.
- 0x1f0/0x1f8 — {u32, ptr} pair cleared by both dtors.
- D2 tail-calls the shared base dtor 0x71006472c8; D0 tail-calls it then
  operator delete 0x710060b470.

## Construction / init order

No static C1 was located (the dtor pair is the only code touching the
vptrs). Extent >= 0x200 from the 0x1f8 field store; the tail is unproven
(unverified). The six 0x12b3af0 channel subobjects and the owned pointer at
0x1c8 are the only members provable from the binary.
