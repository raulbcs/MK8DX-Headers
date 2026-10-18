# object::Vt12da1a0

PLACEHOLDER name. 0x270-byte dispatch object in the nn::pia/Nex region (the
ctor cluster neighbors the mapped Vt12d9c20 constant-getter jobs). 39-entry
getter-style table: most slots are constant/field getters (slot 3 FUN_7100933444 returns
[this+0x8]; slot 13 FUN_7100933454 returns [this+0x268]).

- vptr 0x12da1a8 installed by the ctor FUN_7100933318 at +0x00
  (0x7100933324..0x7100933368; GOT cell 0x1312960 holds 0x12da198 = vt-0x8, so
  the installed vptr is cell+0x10; row 0x12da1a0 itself is the typeinfo slot).
- Secondary vptr 0x12da318 installed at +0x258 (GOT cell 0x1312968 holds
  0x12da308; 0x710093336c..0x7100933378).
- Extent 0x270: the array-element factory loop at 0x7100932418..0x7100932484
  allocates 0x270 per element (w20 = 0x270, 0x7100932428), memsets it, calls
  the ctor FUN_7100933318 (0x710093245c) and then OVERWRITES the primary vptr
  with 0x12d9f58 (GOT cell 0x1312938 holds 0x12d9f48 = vt-0x8; 0x7100932420..
  0x7100932460). So Vt12da1a8 is the ctor-installed table and 0x12d9f58 is the
  runtime table of the same object layout (mapped as Vt12d9f50).
- Slots 0/1/2 are `ret` stubs (0x7100933bc/0x7100933c0 region) in this table;
  the runtime table overrides slot 1 with FUN_710093268c (wraps 0x7100933bc).
  Slots 4-38 are shared verbatim between the two tables.

## Member notes

- Field getters confirm layout: slot 3 FUN_7100933444 = [this+0x8] (u32, so
  +0x08 is a field, unproven in the header pad), slot 4 FUN_71009344c = +0xc,
  slot 13 FUN_7100933454 = +0x268.
- +0x30..+0x230 is a 0x200-byte zeroed block (memset 0x710093390, w2 = 0x200).
- The manager owning the element array keeps u16 count at +0xa and the array
  pointer at +0x10 (factory loop 0x7100923a0..0x710092484).

## Construction / init order

1. Manager factory loop: alloc 0x270 (0x7100932428..0x7100932440), memset 0
   (0x7100932454), ctor FUN_7100933318 (0x710093245c).
2. Ctor FUN_7100933318: zeroes the fields listed above in ascending order,
   installs secondary vptr 0x12da318 at +0x258 then primary vptr 0x12da1a8 at
   +0x00 (0x7100933368).
3. Factory: primary vptr override to 0x12d9f58 (0x7100932460), element stored
   into the manager array (0x7100932470).
