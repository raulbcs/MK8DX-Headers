# object::Vt12cf7d8

PLACEHOLDER name (identity not proven). vptr 0x12cf7d8, 17 slots, no RTTI. GOT cell 0x1310f18 = vptr-0x10; C1 materializes cell+0x10 into [this] (0x8683b4-0x8683b8).

## Member notes

- C1 0x86838c (this-only): vptr store, then `memset(this+8, 0, 0x50)` (0x8683bc).
- +0x58/+0x68/+0x78 — f32 = 1.0f triplet with null ptrs at +0x60/+0x70/+0x80 (0x8683dc-0x86840c); +0x88/+0x90 = span {this+0x58, this+0x7c} over that triplet (0x8683cc).
- +0x98/+0xa0 — copied from config singleton via GOT cell 0x12fb058 (0x8683c0-0x8683d4).
- +0xa6 — u16 = 7; +0xac/+0xb4 — zeroed; +0xe8 — u32 zeroed (0x868400).
- In-place only: all three call sites construct it as a member at outer+0x38 (0x1988ac, 0x29d6f0, 0x7f8790) — no operator-new size found, so size 0xf0 is a lower bound (deepest store +0xe8), unverified.

## Construction / init order

- C1 = 0x86838c; slot0 = ret stub 0x8697d0, slot1 = tail-call operator delete 0x8697d4 (trivial-dtor stub pair; no real D1 body located). Recovered slots: slot5 0x1101d4, slot8 0x19cc20, slot9 0x19cc24, slot10 0x1101e0, slot12 0x869728, slot13 0x86976c, slot14 0x19cc28, slot15 0x8697bc; slot2 0x8687ec / slot3 0x8688a0 / slot6 0x868d10 / slot7 0x868d2c / slot16 0x7f9d58 unrecovered.
