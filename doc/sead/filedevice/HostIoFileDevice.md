# sead::HostIoFileDevice

PLACEHOLDER-adjacent name from behavior (device name "hostio"; cf. upstream sead::NinHostIOFileDevice, which uses mount "hostio" - this binary mounts it as "agl_hostpc"). vptr 0x12f1eb0, 32 slots (+0x00..+0xf8), typeinfo NULL. GOT cell 0x1314ff0 holds vt-0x10 (0x12f1ea0); installed vptr = cell+0x10.

## Member notes

- Single vptr at +0x00. Slot layout shares the binary's FileDevice family table: +0x40 = sead::FileDevice::isMatchDevice_ (0x710060d97c, named in functions.csv); +0x50..+0xf0 are the shared FileDevice slots (0x60cdf4, 0x60d3cc, 0x633830, 0x633a54, 0x633ab8, 0x633afc, 0x633bd0, 0x633c68, 0x633d00, 0x633da0, 0x633dd0, 0x633e88, 0x633ee4, 0x633fec, 0x6340f4, 0x6341d8, 0x6341f8, 0x63438c, 0x634460, 0x60d9a0, 0x6344e0).
- Class-specific overrides: slot +0x08 D1 = 0xa7fdfc (calls base dtor 0x60cd24, then operator delete); +0x10 = 0xa7fe20 (guard-protected static; loads static object and compares against a1 - identity/instance check, unverified); +0x18 = 0xa7ff40; +0x48 = 0xa7fdec (`mov w0, wzr; ret`, i.e. doIsAvailable_ = false); +0xf8 = 0xa7fdf4 (same shape, false).
- Object fields are initialized by the shared base ctor 0x6336a8, not by the derived ctor; no derived-specific stores were found.

## Construction / init order

- Ctor FUN_7100a7fd90(this): builds a stack pair {vptr cell 0x12fae28+0x10, "hostio" (0xf19d29)} twice (x1 = x2 = &pair) and calls the shared base ctor FUN_71006336a8(x0, x1, x2); then installs vptr = [0x1314ff0]+0x10 = 0x12f1eb0.
- Factory in FUN_7100688840 (0x688840-0x688854): operator new(nothrow, align 8) 0x90 bytes, then ctor; result stored at [manager+0x28] and registered with mount name "agl_hostpc" (rodata 0xefabc2). Also constructed on-stack by FUN_7100acf2f8's caller (0xacf2e0-0xacf2f8, sp+0x418), then used via tryRead/0x60d188.
