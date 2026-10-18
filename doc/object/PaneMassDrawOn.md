# PaneMassDrawOn

## Identity

- vtable 0x12bfe38, 29 slots + a second base table at 0x12bff30 (cell
  0x130ed20; both cells hold vt-0x10, installed vptr = cell+0x10).
- Factory: pane-tag dispatcher 0x7430bc branch at 0x743448 requires string
  "MassDrawOn" (0xf07576) in the pane resource; allocates 0x2c0 (align 0x10)
  and calls ctor 0x743c38 (0x74345c..0x743480).
- MI: derives PaneBase (C1 0x745624 called at 0x743c48, derived vptr
  re-installed 0x743c5c) plus a second base at +0x108 (base ctor 0x643fa0,
  0x743c60).

## Member notes

- +0x28 and +0x38: intrusive list heads; slot 31 (0x744114) is a D1 variant
  that walks and frees both lists (node dtors 0x5a0978 / 0xa6e540) and
  re-installs the second-base vptr 0x12bff30 at +0x00 (0x744138..0x744140).
- +0x40: pointer consumed by slot 31 (0x744130).
- +0x108: second base subobject (vptr 0x12bff30); D1 0x743f2c destroys it
  via 0x639f38 before the PaneBase D1 0x5a3e18.
- +0x288..+0x2b8: seven trailing fields zeroed by the C1 (0x743c64..0x743c7c);
  the update function 0x743c94 reads [this+0x290] and the +0x2b8 flag and
  drives per-item float transforms (unverified semantics).
- Dtor triple: D1 0x743f2c, D0 0x743f64 (+ operator delete); slot 31
  0x743c8c / slot 22 0x743c94 are the family's game overrides.
- Slot 30 (0x744e64): guarded static getter (double-checked init via cells
  0x130e9d0/0x130e9d8/0x130e9e0).

## Construction / init order

1. Factory 0x743448: "MassDrawOn" string check; aligned_alloc(0x2c0, align
   0x10) at 0x74345c.
2. C1 0x743c38: PaneBase ctor 0x745624 (0x743c48); vptr 0x12bfe38 at +0x00
   (0x743c5c); second base ctor 0x643fa0 at +0x108 (0x743c60); zero stores
   0x288..0x2b8 (0x743c64..0x743c7c).
