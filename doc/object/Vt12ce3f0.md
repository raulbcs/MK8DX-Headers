# Vt12ce3f0

PLACEHOLDER name (address-anchored). 44-slot interface object created by the
unnamed subsystem factory at 0x3835e8 (its slot-6 virtual (offset 0x30) is
called with w1=4 right after construction, 0x3837bc..0x3837cc).

- Identity: no RTTI; no owned string recoverable. Name stays PLACEHOLDER.
- vptr convention: GOT cell 0x1310df8 holds 0x12ce3e0 (vt-0x10); installed
  vptr = cell+0x10 = 0x12ce3f0, i.e. the table row address is the vptr.
- Table 0x12ce3f0: 44 slots (0x12ce3f0..0x12ce550); the offset-to-top and
  typeinfo words at 0x12ce3e0/0x12ce3e8 are zero.
- Ctor FUN_7100853c80 (0x853c80..0x853e4c, 460 bytes): calls helper
  FUN_71008561cc first (0x7100853c94), clears bits 0-1 of +0x58
  (0x7100853c98..0x7100853cac), memset(this+0x60, 0, 0x125)
  (0x7100853ca0..0x7100853cb0), zeroes +0x1a8/+0x1b0, stores an empty
  doubly-linked-list head (both words = this+0x1c0) at +0x1c0
  (0x7100853cbc..0x7100853cc4), then installs the vptr (0x7100853cd8).
- Extent: caller 0x3837b4 allocates 0xf60 via operator new
  (0x3837a8..0x3837b4) then calls the ctor; the ctor initializes only the
  leading ~0x220 bytes, the rest is unproven.
- Sibling: Vt12cdf48 shares the 44-slot layout with near-identical slot
  clusters; the two are distinct leaf implementations.

## Member notes

- +0x1c0: self-referencing empty list head (stp x9, x9 with x9 = this+0x1c0,
  0x7100853cc0) - unverified semantics.
- +0x58 bitfield: ctor reads, ANDs with 0xfc, stores back.
- Slot 6 (0x8558a4) is the factory's post-construction call target.

## Construction / init order

1. Factory 0x3835e8: operator new(0xf60) (0x3837a8..0x3837b4).
2. Ctor FUN_7100853c80: helper FUN_71008561cc (0x7100853c94); +0x58 bitfield
   clear; memset(this+0x60, 0, 0x125); +0x1a8/+0x1b0 zeroed; +0x1c0 empty
   list head; vptr 0x12ce3f0 at +0x00 (0x7100853cd8).
3. Factory: slot-6 virtual call with w1=4 (0x3837bc..0x3837cc).
