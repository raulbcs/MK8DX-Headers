# nn::nex::PseudoGlobalVariable&lt;MatchmakeExtensionDDLDeclarations&gt;

RTTI-confirmed: typeinfo record 0x12f5560 = {0x10, name 0xf887b0
(`N2nn3nex20PseudoGlobalVariableINS0_33MatchmakeExtensionDDLDeclarationsEEE`),
base 0x128d6c0 = nn::nex::PseudoGlobalVariableRoot, 0}. Note the nex
pattern from batch 27: the typeinfo record lives elsewhere in .data, not
adjacent to the vtable.

- Vtable: vptr = 0x12f5518. GOT cell 0x1315750 holds 0x12f5508 =
  vptr-0x10 (offset-to-top at 0x12f5508 = 0; typeinfo slot at
  0x12f5510). The vt_ctors.tsv row address 0x12f5510 is the typeinfo
  slot, not slot 0.
- Slots (8): +0x00 0xb0aa14 (C2: installs vptr, inserts this into the
  global registry tree via cell 0x130b940 / 0x58c4d8, then virtually
  calls slot +0x18 on itself), +0x08 0xb12340 (D1: same registration
  dance, destroys two members via 0xb4ba2c, tail delete wrapper
  0x573f48), +0x10 0xb123b8, +0x18 0xb124c4 (walks the element array at
  +0x10, stride 0x20, virtually calls each element; gated on a global
  stage counter at cell 0x1314188 being >= 2), +0x20 0xb12554 (2828 B),
  +0x28/+0x30/+0x38 0xb1257c/0xb12584/0xb1258c (small helpers).
- No plain operator-new factory found; size only lower-bounded by the
  member cleanup at +0x18/+0x30-ish offsets (unverified upper bound).
- Registry: the object registers itself in a global tree (root cell
  0x130b940) at construction; the PseudoGlobalVariable family stores
  typed global values consumed by the nex DDL/matchmake layer.

## Construction / init order

1. Storage provided by the enclosing DDL registration unit (no factory
   new found; constructor sites: 0xb0aa28 inline, 0xb12354 in the
   matching C1/D1 pair).
2. C2 installs vptr and links this into the registry tree.
3. Virtual slot +0x18 runs the type-specific post-registration step.
