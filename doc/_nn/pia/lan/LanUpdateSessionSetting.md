# nn::pia::lan::LanUpdateSessionSetting

RTTI-confirmed via typeinfo name `N2nn3pia3lan23LanUpdateSessionSettingE` (0xf80dc0). Typeinfo-row vtable 0x12dca00: GOT cell 0x13133f8 holds vptr-0x10, installed vptr 0x12dca08; word at 0x12dca00 points to the embedded typeinfo pair at 0x12dca60. Offset-to-top 0. 10 slots, all local to this class (unlike the Match job siblings): slot0 = `ret`, slot1 = tail `b operator delete` (0x60b470).

## Member notes

- Ctor 0x974abc (0x188 bytes, unrecovered in functions.csv): calls base C1 0x99f488, sets [this+0xc] and [this+0xe] (h) to 0xffff, zeroes [this+0x10] (w), installs the vptr, zeroes [this+0x1ac] (w), memsets +0x14 (0x18 bytes) and tail-calls memset on +0x2c (0x180 bytes).
- Base C1 0x99f488 (vptr cell 0x1313a38): zeroes [this+0x8] (w) and installs the base vptr (0x12dd990 family).
- Size: lower bound 0x1b0 from the +0x1ac store. Never constructed (zero code references to the ctor); linked-but-unused SDK code.

## Construction / init order

1. Base C1 0x99f488 (w +0x8 = 0, base vptr).
2. Ctor 0x974abc: 0xffff halves, zero +0x10, vptr, memset +0x14/+0x2c, zero +0x1ac.
No construction sites found (unverified end-to-end).
