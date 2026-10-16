# ParamContainerVtc338

 ParamContainerVtc338 — address-anchored name (vptr 0x12bc338, GOT cell 0x130e660).
 Large container of the 0x647f40 hook-band cluster (param-cache super-family ring);
 n=25 slots, allocation 0x370 @ 0x712cac. Interior array region unproven.
 Vtable slot facts: slot 10 (0x60) one-time-guarded singleton getter (guard 0x71012fd3c8,
 instance cell 0x71012fd3d8 = [0x71012fd3d0]+0x10; paramContainerVtc338StaticInstanceSlot10_7100712e64);
 slot 24 (0xd0) spot light update 0x7100712ed4 (light node +0x358, id +0x360, angle accum i32
 +0x364/+0x368, mask +0x36c); slot 32 (0x210) byte-identical masked variant 0x710072f618
 (light +0x470, id +0x478, mask +0x484; 5 differing insns).

## Vtable and extent facts

 Vtable slot 24 (0xd0) = SpotLightRig::Obj update — 0x7100712ed4, range through 0x71007132cc.
 Self fields: +0x358 light node ptr, +0x360 id u16, +0x364/+0x368 angle accum i32, +0x36c mask u16.
 Semantics condensed: gate vt[0x90/8](arg,[+0x360]) bit0 && *(u8*)(lt+0x58); [+0x36C] =
 *(u16*)(arg+0xC) & mask; color combine vs lt[0x468/0x46C/0x470] (plain add if byte lt+0x490,
 else 3x3 rows); mode *(int*)(lt+0x290): 0 static / 1 double-rng hue (FUN_710062eecc) /
 2 multiply; merge lt+0x2D0/0x2F0, alpha lt[0x388], final vt+0xe0 apply. Globals:
 0x712fc990 / 0x712fb0160 / 0x71307cb8.

 Vtable slot 32 = MaskedSpotLightRig update — 0x710072f618, size 0x3f8, byte-identical to
 slot 24 except self offsets +0x470/+0x478/+0x484.

## Naming and additional notes

 Naming: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only).

## Construction / init order

- ParamContainerVtc338 — address-anchored name (vptr 0x12bc338, GOT cell 0x130e660). Large container of the 0x647f40 hook-band cluster (param-cache super-family ring); n=25 slots, allocation 0x370 @ 0x712cac. Interior array region unproven. Vtable slot facts: slot 10 (0x60) one-time-guarded singleton getter (guard 0x71012fd3c8, instance cell 0x71012fd3d8 = [0x71012fd3d0]+0x10; paramContainerVtc338StaticInstanceSlot10_7100712e64); slot 24 (0xd0) spot light update 0x7100712ed4 (light node +0x358, id +0x360, angle accum i32 +0x364/+0x368, mask +0x36c); slot 32 (0x210) byte-identical masked variant 0x710072f618 (light +0x470, id +0x478, mask +0x484; 5 differing insns). Vtable slot 24 (0xd0) = SpotLightRig::Obj update — 0x7100712ed4, range through 0x71007132cc. Self fields: +0x358 light node ptr, +0x360 id u16, +0x364/+0x368 angle accum i32, +0x36c mask u16. Semantics condensed: gate vt[0x90/8](arg,[+0x360]) bit0 && *(u8*)(lt+0x58); [+0x36C] = *(u16*)(arg+0xC) & mask; color combine vs lt[0x468/0x46C/0x470] (plain add if byte lt+0x490, else 3x3 rows); mode *(int*)(lt+0x290): 0 static / 1 double-rng hue (FUN_710062eecc) / 2 multiply; merge lt+0x2D0/0x2F0, alpha lt[0x388], final vt+0xe0 apply. Globals: 0x712fc990 / 0x712fb0160 / 0x71307cb8.  Vtable slot 32 = MaskedSpotLightRig update — 0x710072f618, size 0x3f8, byte-identical to slot 24 except self offsets +0x470/+0x478/+0x484. Naming: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only).
