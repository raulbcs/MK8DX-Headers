# KartCamera

## Identity


## Member notes

Notes in field order; proven from the cited addresses.

- 0x00 — unproven padding (fields before mUpDir not yet mapped)
- 0x158
- 0x164
- 0x170 — unproven padding (to mTilt)
- 0x19C extent 0x1A0 (allocation size 0x1a0 — movz w0,#0x1a0; bl 0x710060afec _Znwm @0x7100cc8b0 → ctor 0x71007ecba0, whose zero-stores walk mUpDir/mForwardDir/pad/mTilt and reach 0x1a0: str wzr [x19,#0x19c] @0x71007eccc0)

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x19C extent 0x1A0 (allocation size 0x1a0 — movz w0,#0x1a0; bl 0x710060afec _Znwm @0x7100cc8b0 → ctor 0x71007ecba0, whose zero-stores walk mUpDir/mForwardDir/pad/mTilt and reach 0x1a0: str wzr [x19,#0x19c] @0x71007eccc0)
