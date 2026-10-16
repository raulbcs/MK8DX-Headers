# ItemDirector (gear::ItemDirector)

- 0x114 mFields114[23] — written by calcBefore (typing pending). Extent 0x170 (lower bound: ItemDirector::calcBefore 0x7100003208 writes fields 0x114..0x16c — str sweep @0x3236c-0x32450; declared as unproven padding, field typing pending).

## Fields

- 0x38 mItemManagers — sead::FixedPtrArray<ItemObjManagerBase, 19>.
- 0xE0 mItemOwners — sead::PtrArray<ItemOwner>.
- 0xF0 — unproven padding.
- 0xF8 mItemEventManager — ItemEventManager*.
- 0x100-0x113 — unproven padding.
- 0x114-0x16C — written by calcBefore (see above).

## Construction / init order

No ctor store map proven in this unit beyond the calcBefore write sweep (0x7100003208; 0x3236c-0x32450).

## Methods

- ItemDirector()
- emitItemKinoko(sead::Vector3f const&, sead::Vector3f const&, int32_t)
