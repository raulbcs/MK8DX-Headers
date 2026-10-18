# KartParamCacheVt2f70

KartParamCacheVt2f70 — address-anchored name for secondary vtable
0x12b2f70 (offset-to-top -0xd0, null typeinfo slot, no RTTI). GOT cell
0x130d9f0 holds 0x12b2e98; code installs cell+0x10 (0x12b2ea8, primary) at
[base+0x00] and cell+0xd8 (0x12b2f70, this secondary row) at [base+0x30].
No direct reloc or adrp reference targets the row.

## Identity

- Slot row 0x12b2f70 (8 slots): slot0 D2 0x710064e4f0, slot1 D0
  0x710064e5d8, slots 2-5 the same shared thunks as Vt2e68 (0x7100648094 /
  0x71006480a0 / 0x71006480a8 / 0x71006480b4), slots 6-7 null.
- The primary row 0x12b2ea8 carries D1 0x710064e480 /
  paramNodeVt2ea8CompleteDtorSlot0 and D0 0x710064e560
  (paramNodeVt2ea8DeletingDtorSlot1) plus the shared paramNode stub band
  0x7100647f40..0x7100647f68.

## Member notes

Proven from D2 0x710064e4f0 / D0 0x710064e5d8 (this = base+0x30 after the
x19 -= 0x30 adjust; offsets below are from that this):

- 0x00 — primary vptr 0x12b2ea8 stored at [this-0x30].
- 0x30 — secondary vptr 0x12b2f70 stored at [this].
- 0x110/0x138/0x160/0x188/0x1a8/0x1c8 — six subobject vptrs rewritten from
  cell 0x130d918+0x10 = 0x12b3af0 (KartParamCacheChanBase) during
  destruction; the dtor skips 0x1b0.
- 0x1c0 — owned pointer: deleted (0x710060b4d4) if non-null, then nulled
  at 0x1f0 with the u32 at 0x1e8.
- 0x1e8/0x1f0 — {u32, ptr} pair cleared by both dtors.
- D2 tail-calls the shared base dtor 0x71006472c8; D0 tail-calls it then
  operator delete 0x710060b470.

## Construction / init order

No static C1 was located (the dtor pair is the only code touching the
vptrs). Proven lower bound 0x1f8 from the 0x1f0 field store; the tail is unproven
(unverified).
