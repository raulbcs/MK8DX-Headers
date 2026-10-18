# sead::SaveFileDevice

PLACEHOLDER-adjacent name from behavior (base-ctor device name "save"; cf. upstream sead::NinSaveFileDevice). vptr 0x12f1fc0, 32 slots (+0x00..+0xf8), typeinfo NULL. GOT cell 0x1315008 holds vt-0x10 (0x12f1fb0); installed vptr = cell+0x10. Cell 0x1315008 is also read by ~30 consumer functions (0xa87118, 0xb04d08, 0xb12e3c, ...) - devirtualized `this`-type checks/loads against the save device, unverified individually.

## Member notes

- Single vptr at +0x00. Shares the FileDevice family table with 0x12f1eb0 (HostIoFileDevice): +0x40 = sead::FileDevice::isMatchDevice_ (0x710060d97c); +0x20..+0x38 and +0x50..+0xf0 identical.
- Class-specific overrides: +0x08 D1 = 0xa8003c (base dtor 0x60cd24 + operator delete); +0x10 = 0xa80060; +0x18 = 0xa80180; +0x48 = 0x633614; +0xf8 = 0x634468.

## Construction / init order

- Ctor FUN_7100a7ff9c(this, mountArg): stores mountArg-derived pair, calls the shared base ctor FUN_71006336a8 with {vptr cell 0x12fae28+0x10, "save" (0xf19d30)}, then installs vptr = [0x1315008]+0x10 = 0x12f1fc0. (0xa7ffac-0xa7ffe8)
- Factories: FUN at 0x8b0c94 (`new` 0x90, ctor, result -> [x22+0x168]) right after nn::fs::MountDeviceSaveData; second instance 0x8b0cd8 (`new` 0x90, -> [x22+0x170]) after nn::fs::MountSaveData. Both use mount strings 0xf0d394 / 0xf0d39f (unverified contents).
