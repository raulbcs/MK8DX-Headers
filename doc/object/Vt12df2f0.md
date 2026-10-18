# object::Vt12df2f0

PLACEHOLDER name (identity not proven). vptr 0x12df2f8 (vt_ctors row 0x12df2f0 = the zero offset-to-top slot at vptr-8). GOT cell 0x1313c08 holds vptr-0x10. 5 slots at 0x12df2f8: 0x97da50 (slot 0), 0x9b0b30 (slot 1), 0x9af870 (slot 2), 0x9af954 (slot 3), 0x9b0b34 (slot 4). Typeinfo-adjacent blob at 0x12df320 (interpretation unverified).

## Member notes

- The whole class lives in one TU, FUN_71009af864: it allocates an array of n*0x5b0 bytes (0x9afc20-0x9afc2c, umull n*0x5b0), zero-memes each 0x5b0 element and installs vptr = cell+0x10 at element+0x10 (0x9afc74 first element, 0x9afcb8 unrolled pair loop, stride 0xb60 = 2*0x5b0). Array pointer/count stored at owner+0x20/+0x28 (0x9afcd4).
- Slot 3 (0x9af954) parses an incoming message into a stack temporary: install site 0x9aff94 stores vptr at temp+0, then 0x9af954 fills it from a big-endian buffer (x1 = arg+0x18). Caller 0x9aff50 checks [x20+8] u16 against a rodata constant via GOT cell 0x1313b98 and returns error code 0x2c03 on bad length (>0x17) — a dispatcher validating and decoding records.
- Parsed temp fields (0x9b0018-0x9b0064, x20 = owning manager): u32 count/capacity at +0x28/+0x2c, u32 read/write cursors at +0x30/+0x34, array ptr at +0x20, u16 at +0x8.

## Construction / init order

- Elements: zero-mem then vptr store; no per-element C1 call observed (plain memset + vptr = POD-style init).
- Slot 0/1/4 are mid-function thunks of FUN_71009af864 (+0xc/+0x12cc/+0x12d0); no separately recovered D1/D0 pair.
- Extent: element stride 0x5b0 exact; object begins at element+0x10, so class size <= 0x5a0; whether the leading 0x10 bytes belong to the object is unverified.
