# Vt12dd1f0

PLACEHOLDER name (address-anchored). 43-slot game class; typeinfo-slot row
convention: GOT cell 0x1313638 holds 0x12dd1e8 = vt-0x8, so the row address
0x12dd1f0 is the typeinfo-pointer slot and the installed vptr is 0x12dd1f8
(row + 8; its offset-to-top sits at 0x12dd1e8 and the typeinfo at 0x12dd350).
Extent 0x1e28.

- vptr 0x12dd1f8 installed at +0x00 by ctor FUN_7100979774 (0x979790..
  0x9797a4).
- Secondary vptr 0x12dc458 (cell 0x1313320, same typeinfo-slot convention)
  installed at BOTH +0x18 and +0x870 (0x9797c0/0x9797cc).
- Extent: caller FUN_710096d640 allocates 0x1e28 via allocFromHeapOrDefault
  (w0=0x1e28, 0x96d654..0x96d668) then calls the ctor.

## Member notes

- Base ctor FUN_710097df48 called first (0x97978c).
- Sub-object ctors: FUN_71009721ac at +0x18 (0x9797a8), +0x870 (0x9797c4) and
  +0x15c8 (0x979800); FUN_7100973a74 at +0x10c8 (0x9797d8) and +0x1320
  (0x9797e8); FUN_7100929ec0 at +0x15a8 (0x9797f4).
- +0x1580 pointer built from cell 0x13123e0 via a two-level dereference
  ([cell][0x158]) and stored at 0x979818; +0x1588 pointer zeroed (0x979864);
  +0x1590 u32 zeroed (0x979868); +0x1598 / +0x15a0 pointers zeroed
  (0x979870/0x979874); +0x08 pointer zeroed (0x97986c); +0x10 u8 zeroed
  (0x979878); +0x1e20 u8 zeroed (0x97987c).
- The ctor tail also issues virtual calls through +0x10c8 and +0x1320
  (slot 3) and through the +0x1580 object (slot 8) (0x979828..0x979854).

## Construction / init order

1. FUN_710096d640: allocFromHeapOrDefault(0x1e28, align 8)
   (0x96d654..0x96d668).
2. Ctor FUN_7100979774: base ctor FUN_710097df48 (0x97978c); vptr 0x12dd1f8
   at +0x00 (0x9797a4); secondary vptr 0x12dc458 at +0x18 / +0x870
   (0x9797c0/0x9797cc); sub-object ctors in ascending offset order
   (0x9797a8..0x979800); field stores listed above (0x979818..0x97987c).
