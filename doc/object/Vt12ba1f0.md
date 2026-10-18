# object::Vt12ba1f0

PLACEHOLDER name. Manager-embedded polymorphic member with a kart-param
flavored secondary interface.

- Identity: ctor 0x6dd190, D1 0x6dd8d8 (0x468), D0 0x6ddab4 / reinit helper
  0x6dd8f0. The ctor is called from the giant manager ctor block
  (0x6bb390) as the member at manager+0x4d00; the next member init in the
  chain starts at manager+0x54b8, so this member occupies 0x4d00-0x54af.
- vtable convention: GOT cell 0x130e330, rela addend 0x12ba1e0 = vt-0x10;
  installed primary vptr = cell+0x10 = 0x12ba1f0 (row 0x12ba1f0, offset-to-top
  0, typeinfo 0).
- Primary slots (9): 0x6dd8d8 / 0x6ddab4 dtor pair; 0x6e1728 (0x860);
  0x6e1a84 (0x964); 0x6e0c68 (0x192); 0x6e1640 (0x132); 0x6e1e48 (0x540);
  0x6e1fc0 (unrecovered); 0x6e0248 (0x112).
- Secondary at [this+0x248]: the +0x248 subobject is first inited by
  KartParamChannel-family factory ctor 0x668d40 (bl at 0x6dd1e4), then the
  vptr is overwritten with cell+0x68 = 0x12ba248 (offset-to-top -0x248;
  slots 0x6ddaac / 0x6ddad8 dtor thunks + kart-param shared
  0x63c6f8 / 0x63c700 / 0x63c704 / 0x63c710 paramCacheSharedTypeIdEquals /
  0x63c724 / 0x63c728 / 0x6e0280 / 0x63c710 tail).

## Construction / init order

1. 0x6dd190: `bl 0x6c6128` (base ctor, x0=this).
2. Build descriptor on stack (cell 0x12fa000+0xe28; string 0xf028cf); then
   `bl 0x668d40` on this+0x248.
3. Zero 0x418-0x487 range (pairs at 0x418..0x480), h 0x440=2, h 0x442=0x40.
4. Install primary vptr 0x12ba1f0 at [this]; secondary 0x12ba248 at +0x248.
5. Member ctor 0x66a2a4 at this+0x488; member ctor 0x662f30 at this+0x4b8.
- D0 region: 0x6dd8f0 destroys members at 0x448-0x480 via their vtable slot 8
  and reinstalls the secondary vptr at +0x248.
- size 0x7b8 (member boundary: next manager member init at +0x54b8; max ctor
  store at 0x7a0).
