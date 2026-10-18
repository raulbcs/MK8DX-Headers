# Vt12c2fd8 (placeholder object::Vt12c2fd8)

## Identity

- No RTTI (no offset-to-top/typeinfo rows). GOT cell 0x130f660 holds
  vt-0x10 (addend 0x12c2fc8); installed vptr = 0x12c2fd8.
- Slots 0/1 = 0x79a4b8 / 0x79a4bc — a shared `ret` / stub pair also used by
  the twin singleton Vt12c31b8 (common-base idiom, not a real dtor pair).

## Member notes

- Singleton factory FUN_710078f99c (0x78f99c): guard global via cell
  0x12fce70; on first call requests 0x24905000 bytes from 0x60b2a8 (arena
  reservation; committed use unverified), stores the base pointer in the
  guard, and never allocates again.
- +0x7d4 — embedded member: vptr from cell 0x130f650 installed directly, then
  ctor 0x799ec0; its address is cached in the global at cell 0x130f658.
- +0x7f8..+0x818 — three pointer pairs zeroed by the factory; slot9 (0x78fad0)
  releases [this+0x800] and slot10 (0x78fb44) releases [this+0x810] (both then
  re-install the vptr, confirming slot0/1 are not the dtors).
- +0x870 — element records of stride 0x28e0, seeded {ptr=-1, byte=0xff,
  {0,-1}, 0, byte 0} repeated from +0x870 up to arena+0x24705000; tail bytes
  at +0x24805000 (=1) and +0x24815000 (=0).
- size: the root object spans the whole arena allocation (bytes are written at
  +0x24815001); treat as arena-backed lower bound 0x24815002, layout above
  +0x870 unverified.

## Construction / init order

1. FUN_710078f99c reserves the arena (0x60b2a8, 0x24905000) and caches it.
2. Embedded member at +0x7d4 gets vptr (cell 0x130f650) and ctor 0x799ec0;
   global cell 0x130f658 keeps its pointer.
3. vptr 0x12c2fd8 stored at +0x00; +0x7f8..+0x818 zeroed; element loop seeds
   records from +0x870; tail flag bytes set; base pointer published to the
   guard global.
