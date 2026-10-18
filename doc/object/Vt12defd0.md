# object::Vt12defd0

PLACEHOLDER name (identity not proven). vptr 0x12defd8 (vt_ctors row 0x12defd0 = the zero offset-to-top slot at vptr-8). GOT cell 0x1313bb0 holds vptr-0x10 (add #0x10 at both install sites). 5 slots at 0x12defd8: 0x97da50 (slot 0), 0x9a88d8 (slot 1), 0x9a88dc (slot 2), 0x9a86f0 (slot 3), 0x9a89d8 (slot 4). Typeinfo slot non-null (points to 0x12df000, an RTTI blob at vptr-0x18..vptr-0x10 region; interpretation unverified).

## Member notes

- Layout from the C1 fragment at 0x9a859c-0x9a85bc (inlined in composite ctor FUN_71009a8514): vptr at member+0, qwords at +0x8/+0x10/+0x18/+0x20 zeroed, byte +0x28 zeroed, nested member constructed at +0x30 via 0x92a1e0 (which installs the vptr from GOT cell 0x1312438 into the nested object).
- FUN_71009a8a54 (slot 3 region, 0x9a8a54) builds a stack temporary of this class and serializes its fields byte-by-byte big-endian into a buffer at [this+0x20] (0x9a8ae0-0x9a8b98): u16 @+0x00, u16 @+0x10, flag bytes @+0x15/+0x16 (OR-composed with +0x30/+0x31 into one flag byte), u64 @+0x28, u64 @+0x08, u16 @+0x18 — a network-message packing routine. Field views disagree with the zeroed ctor layout; interpretation unverified.
- Caller context: FUN_71009a8514 is called at 0x9a7e80 with (x0 = [GOT cell 0x1313b50], w1 = byte [x19+0x19]) after a virtual bool probe at slot 0x50 — a notification/report record appended to a global sink.

## Construction / init order

- C1 = the fragment at 0x9a859c (composite ctor FUN_71009a8514, itself called from 0x9a7e80): zero fields, install vptr, construct nested member at +0x30 (0x92a1e0 → 0x929fd4).
- Slot 2 (0x9a88dc, 0x260 bytes) and slot 4 (0x9a89d8) are inside the same TU; slot 0/1 entries are mid-function thunks (0x97da50 = FUN_710097da0c+0x44, 0x9a88d8 = FUN_71009a88d4+4). No separately recovered D1/D0 pair; dtor identification unverified.
- Extent: lower bound 0x40 (byte store at member+0x28 plus nested member at +0x30, size unknown); no operator-new site found. Exact size unverified.
