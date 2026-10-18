# Vt12baef8

Vt12baef8 — address-anchored name for secondary vtable 0x12baef8
(offset-to-top -0xd0, null typeinfo slot, no RTTI). No RELATIVE reloc and
no adrp reference targets the row or its vt-0x10 value (0x12baee8) — no
static install site exists, so the row is treated as the secondary
interface of an (otherwise unmapped) derived variant of the ParamNodeVt47a0
family.

## Identity

- Slot row 0x12baef8: slot0 D2 thunk 0x71006fb7c4 (`sub x0, x0, #0x30; b
  0x7100af2658`), slot1 D0 thunk 0x71006fb7cc (adjust -0x30, call
  0x7100af2658, then operator delete 0x710060b470 on the adjusted this),
  slot8 D1 0x7100af2658 (shared family dtor), slot9 0x71006fb7f4 (plain
  this + delete wrapper), then the shared paramNode stub band
  0x7100647f40..0x7100647f60.
- The -0x30 adjustment and the shared dtor 0x7100af2658 tie the class to
  ParamNodeVt47a0 (primary vptr 0x12f47a0, GOT cell 0x13154e8): that dtor
  stores cell+0x10 at [this] and cell+0x150 (0x12f48e0) at [this+0x30];
  this row overrides the +0x30 slot for the derived variant.

## Member notes

Proven only through the shared dtor 0x7100af2658 (from the
ParamNodeVt47a0 evidence):

- 0xec0 — manager-style field destroyed via 0x710060b984 (0xaf2718).
- 0xec8 — pointer array; entries are 0x78-stride records freed in the loop
  at 0xaf26c8-0xaf26f4.
- 0xed0/0xed4 — second count-driven list torn down at 0xaf2720..0xaf2760.

## Construction / init order

No C1 or factory was located for this row (unverified); the only size
evidence is inherited from the family: ctor stores of ParamNodeVt47a0
reach 0xeb4 and the shared dtor touches 0xed4, giving size >= 0xeb0 for
the complete object (lower bound, unverified). The row itself has 13+
slots; slots 1-7 beyond the dtor pair are unproven.
