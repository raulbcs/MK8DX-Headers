# object::Vt12e2ec8

PLACEHOLDER name (identity not proven; nn websocket/socket-driver style). Installed vptr 0x12e2ed0,
7 slots. GOT cell 0x1314340 holds vptr-0x10 (0x12e2ec0); the documented row address 0x12e2ec8 is the
typeinfo slot (typeinfo 0x12e4130), offset-to-top 0 at 0x12e2ec0. Size 0x58 exact (operator new w0=0x58
at 0x9F0AD8 -> 0x573F04, in-place init at 0x9F0AF8).

## Member notes

- [this+0x0] vptr 0x12e2ed0; [this+0x38] embedded member vptr from GOT cell 0x1314348 (0x12E4D08+0x10) — a distinct class, not a secondary base of this vtable (unverified offset semantics beyond the ctor store).
- [this+0xC]/[this+0xD]/[this+0xE] bytes zeroed; [this+0x18] set to 0xFF; [this+0x40] u16 zeroed — all in the merged ctor 0x9E5A04.
- [this+0x10] ctor arg x2 (context ptr); [this+0x28] zeroed.
- [this+0x48] zeroed and [this+0x50] = owner ptr stored by the factory caller (0x9F0B04-0x9F0B08).
- Secondary vtable 0x12E2EA0 (2 slots 0xA19278/0xA19280, typeinfo 0xA19270 at 0x12E2E98) exists in the rodata but has no GOT cell; relationship to this class unverified.
- Slots: D1 0x9E5C3C and D0 0x9E5C94 are mid-function entries inside the merged ctor/dtor function FUN_71009E5A04 (748B, C1/C0/D1/D0 merged; base ctor 0x9E4484). Slot 2 (0x9E5E8C) issues socket read/write through a peer object's vtable slots +0x18/+0x20. Slot 6 (0x9E6048) allocates 0x238-byte objects and constructs another instance of this family (new 0x58, w1=5 pattern shared with Vt12e31b8). Slots 3/4 are 8B/112B stubs (0xA19284, 0xA191C4 mid-entries).

## Construction / init order

- Factory caller 0x9F0AE0-0x9F0B1C: operator new(0x58) -> FUN_71009E5A04(this, w1=5, x2) -> caller fixes [this+0x48]=0, [this+0x50]=owner -> post-init call 0x9E5CF0.
- Ctor order: base ctor 0x9E4484; then byte/halfword field zeroing; [this+0x10]=arg; [this+0x28]=0; [this+0x38]=member vptr; vptr installed last (0x9E5A60).
- Derived class Vt12e31b8 overrides slots 1/3/5 and reuses the rest; see doc/object/Vt12e31b8.md.
