# RaceDirectorVt2 (gear::RaceDirectorVt2)

- PROVISIONAL vtable-anchored name (no MethodTree string). Vtable 0x11b3098 (.data anchor 0x11b3088, GOT 0x12fbca0), custom-RTTI fn 0x4e268. Ctor 0x710004e2f4. Size 0xA0, proven by the sole plain allocation site 0x710006f108 (new 0xA0).

Mid-level base of the primary derived-director set: Vt4/Vt5/Vt6/Vt7 and Vt3 all chain through its ctor 0x710004e2f4.

Naming: mid-level base of the primary director set; typeinfo 0x4e268 is a predicate function, not a name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x90 mCtxPtr90 — race-context object selected at ctor: vcall slot 0xe8 on [this+0x58] yields an index, helper 0x7100024e70 returns RaceInfo container element ([ri+0x1b0] -> {count@0x60, ptrs@0x68}, RTTI-checked); NOT a new allocation (ctor 0x4e338).
- 0x98 mU98 — ctor zero; reset by slot 0x100 (0x4e354).
- 0x9A mU9a — ctor zero; same reset.
- 0x9B — unproven gap.

NO explicit tail pad: the derived directors (Vt3-Vt7) start their first field at 0x9C, i.e. INSIDE this class's tail padding (Itanium tail-padding reuse; allocation is 0xA0).

## Construction / init order

1. Derived ctors call 0x710004e2f4 (after their RaceDirector base).
2. Ctor 0x4e338: mCtxPtr90 (0x90) = RaceInfo container element via vcall slot 0xe8 on [this+0x58] + helper 0x7100024e70 (no new allocation).
3. 0x98/0x9A = 0.
4. Allocation proof: 0x710006f108 (new 0xA0).
