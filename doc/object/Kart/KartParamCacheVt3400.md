# KartParamCacheVt3400

## Identity

KartParamCacheVt3400 — address-anchored name (vptr 0x12b3400, GOT cell
0x130dae8; the cell holds vt-0x10 and code stores cell+0x10 into [this],
sites 0x710065df8c and 0x710065e18c). Large Mid2-derived variant of the
param-cache family. Size 0xb80 proven by operator new(0xb80) at
0x71003d0a4c immediately followed by C1 0x710065df30 (other C1 callers:
0x71006c3c68, 0x71007381a4, 0x71008cd4b0, 0x71008cd514).

## Vtable (13 slots, row = installed vptr)

- slot 0x00 (0x65e178, 572 B) — D1 complete destructor (restores the class
  vptr at 0x65e18c before destroying; called by D0 at 0x65e3fc and by
  holders at 0x6c37c4).
- slot 0x08 (0x65e3ec, 36 B) — D0 deleting destructor (calls D1, then
  operator delete).
- slot 0x10 (0x65eb2c, 52 B), slot 0x28 (0x65eb60, 500 B) — own overrides
  (unverified semantics).
- slots 0x18/0x38/0x40/0x60 — shared `ret` stubs (0x63c700/0x63c724/0x63c728/
  0x63c72c); slot 0x20 — shared return-1 stub (0x63c704).
- slot 0x30 (0x63c710, paramCacheSharedTypeIdEquals) — shared ID compare
  ([x1] == [this+0x28]).
- slots 0x48/0x50/0x58 — shared record trio: 0x669208 (agl::Debug::xml
  loader), 0x66979c (apply-from-record), 0x6697f8 (apply pair).

## Member notes

Notes in field order; proven from C1 0x710065df30 unless cited.

- 0x1d0 / 0x1e8 — self-referential pointer pairs (0x65df74/0x65df84).
- 0x1e0, 0x1f8 — ctor zeros.
- 0x200..0x288 — six intrusive-list heads (stride 0x18; pairs + u32 counts,
  all zeroed 0x65df98-0x65dff4).
- 0x290..0x440 — seven 0x48-stride sub-objects, ctor 0x7100669954, vptr from
  cell 0x130d980 (0x65e000-0x65e058).
- 0x580 — member ctor 0x7100645410; 0x748 — 0x710063ecbc; 0x7b0 —
  0x710063f778; 0x988 — 0x7100692a90 (0x65e05c-0x65e078).
- 0x578, 0x9b8 — 29 (0x65e134/0x65e138).
- 0x9cc..0x9d8 — flags/zero block (0x65e084-0x65e098).
- 0x9e0 — member ctor 0x710066a2a4, vptr cell 0x130d988 (0x65e09c-0x65e0ac).
- 0xa10 — channel-pair member (ctor pair 0x7100662f30/0x7100662f70, cell
  0x130d908; registration calls with strings 0xef9a66/0xef9a6c/0xef9a82).
- 0xa28 — 1; 0xa30 — ctor 0x71006611bc with -1.
- Tail 0xa30..0xb80 — name-table call 0x7100689f00 with string 0xef9ab9;
  contents unverified.
- 0x568/0x570/0x580(u64)/0x768/0x980/0x984 — zeroed/assigned in the ctor
  epilogue (0x65e144-0x65e15c).

> Naming: address-anchored; no ctor strings (generic 'default'/'param' names
> only, dictionary-built at runtime).

## Construction / init order

- C1 0x710065df30: base Mid2 ctor 0x7100668d40 (0x65df6c), then in field
  order: 0x1d0/0x1e8 pairs, list heads 0x200..0x288, primary vptr (0x65df8c),
  sub-objects 0x290..0x440, 0x580/0x748/0x7b0/0x988 members, flag block
  0x9cc..0x9d8, 0x9e0 member, 0xa10 channel pair (0x662f30/0x662f70 +
  0x662f70 registration), 0xa30 member, name-table call, epilogue zeros.
- Factory: operator new(0xb80) at 0x71003d0a4c then C1; result stored to
  [mgr+0x380] and passed to 0x710065e410 (0x3d0a5c-0x3d0a6c).
