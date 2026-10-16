# RaceListItemE (gear::RaceListItemE)

- PROVISIONAL vtable-anchored name ("E"). Manager list item of the far race family (NOT a RaceDirector child — reuses the enter/calc/exit slot block only). Vtable 0x11b89c8 (GOT 0x12fcc80). Ctor 0x71000c8138 (Actor base 0x7b976c). Size 0xB00.

Wired by its manager: child+0x18=self, +0x20 intrusive node, +0x28=&manager+0x178, +0x30=[manager+0x1A8]; manager+0x1C0++.

Naming: manager list item wired by the per-mode dispatcher (mgr+0x178/+0x1a8/+0x1c0); mode id selects ctor and size; no binary name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x70 mList70 — intrusive list head.
- 0x88 mList88 / 0x90 mList90 — list heads.
- 0x98 mFive98 — ctor sets 5.
- 0x140-0x38B mNodeArrays140 — fixed-stride node arrays (next/prev self-links).
- 0x3B0-0x5AF zero3B0 — ctor zeroes.
- 0x5B8/0x618/0x678/0x6D8 — four 0x30-byte copies of the global pair block [0x12fb188]; ctor overlays f32 10.0 at +0x38 and f32 1.0 at +0x4C of each block (0x5F0/0x650/0x6B0/0x710, 0x604/0x664/0x6C4/0x724).
- 0x730/0x7F0/0x8B0/0x970 — ctor 0x62c3a8 (stride 0xC0 members); 0x738-0x7E7 unproven gap.
- 0x9B0-0xAFF — unproven.

## Construction / init order

1. Ctor 0x71000c8138 with Actor base 0x7b976c; vtable 0x11b89c8.
2. 0x98 = 5; zeroes 0x3B0-0x5AF.
3. Four 0x30-byte copies of [0x12fb188] at 0x5B8/0x618/0x678/0x6D8; overlays f32 10.0 (+0x38) and f32 1.0 (+0x4C) per block.
4. Member ctors 0x62c3a8 at 0x730/0x7F0/0x8B0/0x970.
5. Manager wiring: child+0x18=self, +0x20 intrusive node, +0x28=&manager+0x178, +0x30=[manager+0x1A8]; manager+0x1C0++.
