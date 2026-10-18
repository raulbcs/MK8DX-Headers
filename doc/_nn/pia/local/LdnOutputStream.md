# nn::pia::local::LdnOutputStream

## Identity

- vtable row 0x12dfea0 (tsv row = typeinfo slot), vptr 0x12dfea8 = row + 8, 9 slots.
  GOT cell 0x1313d30 holds 0x12dfe98 = vptr - 0x10 (offset-to-top 0x12dfe98 = 0,
  typeinfo slot 0x12dfea0 = 0x12dff10); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12dff10 = {0x10, name 0xf82c90, 0x200000000}; name =
  "N2nn3pia5local15LdnOutputStreamE"; plain class_type_info (no declared base),
  despite the structural job-base region — its vtable is unrelated to the
  StepSequenceJob cluster (slots 2-7 are its own, not 0xb4a654/0xb4a67c).
- Slots: 0 D1 0x9be864, 1 D0 0x9be8b0, 2 0x9bec9c (sret-style: *[x8] = 0),
  3 0x9be90c (large body, reads flag [this+0x18]), 4 0x9beac8 (large body,
  reads [this+0x18], touches global cell 0x130b278), 5 `mov w0, #1` 0x9beca4,
  6 `mov w0, #1` 0x9becac, 7 `ret` 0x9bec98 (all unrecovered beyond shape).
- Secondary vptr 0x12dfef8 at [this+0x10] (cell + 0x60; sub-group D1 0x9be88c,
  D0 0x9be8e0 tail-call the 0xb4a58c/0x9c41f0 chain).
- extent 0x600 EXACT: operator new 0x600 at 0x9be2f4-0x9be308 immediately
  followed by C1 0x9be824 (sole site; fields only reach 0x28 — large
  allocator-only tail, unverified content).

## Member notes

- Base C1 0x9c41dc installs an interface vptr (cell 0x1313dc0 + 0x10) at
  [this] which C1 0x9be824 then overrides with 0x12dfea8; it also zeroes [0x8].
- Sub-object at +0x10: sub C1 0xb4a570 installs vptr (cell 0x1315f68 + 0x10)
  at [+0x10], zeroes byte [+0x18] and [+0x20]; the final [0x10] store is the
  secondary vptr 0x12dfef8.
- The 0xb4a570/0xb4a58c sub-ctor/dtor family is shared with unrelated classes;
  the sub-object identity is unverified.

## Construction / init order

1. C1 0x9be824: base C1 0x9c41dc(this) (0x9be834).
2. Sub C1 0xb4a570(this + 0x10) (0x9be83c).
3. vptr 0x12dfea8 -> [this] and secondary 0x12dfef8 -> [this+0x10]
   (0x9be850, cell 0x1313d30 + 0x10 / + 0x60).
