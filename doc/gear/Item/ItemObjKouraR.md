# ItemObjKouraR (gear::ItemObjKouraR)

Derived from ItemObjKouraG.

## Fields

- 0x390-0x398 — unproven padding.
- 0x399 mLockOnState (EStateEx: Stop/Linear/Path/Target/ComeBack/Circle/Down/Burst, u8-backed; text_(int) provides names).
- 0x39A-0x427 — unproven padding.
- 0x428 mLockOnKartIdx; 0x42C-0x45F unproven padding.

## Construction / init order

- Extent 0x460 (allocation size 0x460 — movz w0,#0x460; bl 0x710060afec _Znwm @0x710035f10 → ctor 0x710030d50, stores reach 0x460 and call the KartPhysicsBodyMid base ctor 0x71003703c).

## EStateEx

Constructors: default = Stop; from EStateEx_; from int32_t (static_cast). Comparison against EStateEx, uint8_t, and EStateEx_.
