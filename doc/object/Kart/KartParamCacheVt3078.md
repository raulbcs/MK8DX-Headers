# KartParamCacheVt3078

KartParamCacheVt3078 — address-anchored name for secondary vtable
0x12b3078 (offset-to-top -0xd0, null typeinfo slot, no RTTI). GOT cell
0x130d9f8 holds 0x12b2fa0; code installs cell+0x10 (0x12b2fa8, primary) at
[base+0x00] and cell+0xd8 (0x12b3078, this secondary row) at [base+0x30].
No direct reloc or adrp reference targets the row.

## Identity

- Slot row 0x12b3078 (15 slots): slot0 D2 0x710064ec50, slot1 D0
  0x710064ed78, slots 2-5 shared thunks 0x7100648094/0x71006480a0/
  0x71006480a8/0x71006480b4, slots 6-7 null, slot8 D1
  0x7100650520 (colorCorrectionCompleteDtorSlot0), slot9 D0 0x71006506e0
  (deletingDtorColorCorrectionSub), slots 10-12 paramCache stub band
  0x710063c6f8/0x710063c700/0x710063c704, slot13
  0x7100651814 (colorCorrectionUpdateDirtyBitsSlot5), slot14
  0x710063c710 (paramCacheSharedTypeIdEquals).
- The ColorCorrection slots tie this class to the
  KartParamCacheColorCorrection/KartParamCacheColorCorrectionSub family
  (the primary row 0x12b2fa8 region carries their dtor pair).

## Member notes

Proven from D2 0x710064ec50 / D0 0x710064ed78 (this = base+0x30 after the
x19 -= 0x30 adjust; offsets below are from that this):

- 0x00 — primary vptr 0x12b2fa8 stored at [this-0x30].
- 0x30 — secondary vptr 0x12b3078 stored at [this].
- 0x110/0x138/0x160/0x180/0x1a0/0x1c8/0x1f0/0x210/0x230 — nine subobject
  vptrs rewritten from cell 0x130d918+0x10 = 0x12b3af0
  (KartParamCacheChanBase) during destruction.
- 0x238 — owned pointer: deleted (0x710060b4d4) if non-null, then nulled
  at 0x268 with the u32 at 0x260.
- 0x258 — second owned pointer: deleted if non-null, then nulled at 0x258
  with the u32 at 0x250.
- 0x250/0x258 and 0x260/0x268 — two {u32, ptr} pairs cleared by both dtors.
- D2 tail-calls the shared base dtor 0x71006472c8; D0 0x710064ece0-region
  twin stores 0x110 too before the shared delete path.

## Construction / init order

No static C1 was located (the dtor pair is the only code touching the
vptrs). Extent >= 0x270 from the 0x268 field store; the tail is unproven
(unverified).
