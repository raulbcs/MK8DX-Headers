# object::Vt12d7ec8

PLACEHOLDER name (identity not proven). 6-slot row (0x12D7EC8..0x12D7EF0), offset-to-top 0 at 0x12D7EB8, typeinfo NULL. GOT cell 0x13123D8 holds vt-0x10 and is loaded at ~14 sites (0x910524, 0x9111D4, 0x911C90, 0x912624, 0x9163E0, 0x917A30, 0x923A50, 0x97B8CC, ...), so the component ctor is inlined into many embedding classes.

## Member notes

- Slots: 0x9118D8 (`ret` stub), 0x9118DC (tail branch to operator delete), 0x92A7E8 (field comparator: returns a struct via x8, compares [this+0x08]/[this+0x18] against the argument's), 0x9118A0 (reset: memset(this+0x1C, 0, 0x51), [this+0x08] = this+0x1C, [this+0x14] = 0), 0x92ADAC, 0x9118E0 (unclassified).
- Component layout (relative to the +0x28 vptr, from the 0x9104BC site): +0x00 vptr 0x12D7EC8, +0x10 u32 0x50 (0x910554), +0x1C buffer memset(0) 0x51 bytes (0x91055C) — matching reset fn 0x9118A0's this+0x1C/0x51 exactly.
- Host object at the 0x9104BC site: flags at +0x08/+0x09/+0x0A, [host+0x18] = [arg], component vptr at host+0x28; the host's primary goes through base row 0x12D7E30 ([cell 0x13123C8]) then final row [cell 0x13123D0]+0x10 = 0x12D7D78 (0x9104DC-0x91052C).

## Construction / init order

- 0x9104BC-0x910514: clear flags, install base row 0x12D7E30 at [host].
- 0x910514-0x91052C: install final primary 0x12D7D78 at [host], zero [host+0x10].
- 0x910524-0x910560: install 0x12D7EC8 at [host+0x28], [host+0x38] = 0x50, [host+0x18] = [arg], memset(host+0x44, 0, 0x51). Host extent >= 0x95; component extent >= 0x6D (cited 0x70 as unverified round-up).
