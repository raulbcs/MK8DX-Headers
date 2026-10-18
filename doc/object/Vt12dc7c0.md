# object::Vt12dc7c0

PLACEHOLDER name. 36-slot vtable; the assigned address 0x12dc7c0 is the
typeinfo slot, the installed vptr is 0x12dc7c8.

- Identity: ctor C1 FUN_71009721ac (656 B) loads GOT cell 0x13133d8
  (addend 0x12dc7b8 = vt-8) and stores cell+0x10 = 0x12dc7c8 at [this+0x00]
  with +0x08 zeroed (0x71009721cc..0x71009721fc). The only other code
  reference pair is the D2 FUN_710097243c (0x7100972448) and D1-side site in
  FUN_71009721ac's siblings; no typeinfo name string was resolved.
- Slots: slot 0 = FUN_710097243c (D2: destroys the 16 members in reverse via
  FUN_71009749a0 and tails 0x71009b20b4 on +0x1d8), slot 1 = 0x9724f0 (D1).
  Remaining slots (0x9727dc..0x973820) are unrecovered FUNs; several 8-byte
  thunks (0x972b0c/0x972b14/0x972b24/0x972b34).
- Extent: deepest ctor store is the last array member at +0x7f0 (+0x60 =
  0x850). A caller at 0x7100845d9c embeds this object at +0xbe0 of an outer
  allocation, so 0x850 is a lower bound, not an allocation proof.

## Member notes

- +0x250..+0x850: 16 members of stride 0x60, each polymorphic — the ctor
  issues a slot-0 vcall on every member (0x7100972310..0x7100972380 range).
- +0x1d8 (0x78 bytes): string/alloc member — ctor 0x71009b1fe8 + copy
  0x71009b2130 from a stack temp; destroyed last (D2 tail 0x71009b20b4).
- +0x30 = 5 at construction; +0x10/+0x14/+0x16/+0x32 zeroed; memsets at
  +0x54 (0x180), +0x18 (0x18), +0x34 (0x20); +0x1d4 u32 zeroed.

## Construction / init order

1. Outer owner allocates and calls C1 FUN_71009721ac(this).
2. C1 stores vptr 0x12dc7c8 (+0x08 = 0), zeroes +0x10..+0x16, sets +0x30 = 5.
3. Member at +0x1d8 default-constructed (0x71009722fc..0x71009722ff),
   then assigned from a stack temporary (0x71009b2130).
4. 16 members constructed front to back with FUN_71009748f8
   (+0x250, +0x2b0, ..., +0x7f0), then each receives a slot-0 vcall.
5. D2 FUN_710097243c reverses steps 4-3 (member D FUN_71009749a0 back to
   front, then 0x71009b20b4 on +0x1d8).
