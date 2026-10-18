# object::SharedCounterSocket (nn::nex)

## Identity

RTTI-confirmed: typeinfo 0x12e44a0 = {0x10, "N2nn3nex26SharedCounterINS0_12SocketDriver6SocketES3_NS0_19SocketDriverDeleterEEE", 0x12e4480}; secondary ti 0x12e44c0 = SharedCounterInterface<SocketDriver::Socket> (root 0x128c3b0). vptr 0x12e35a0 (ti-slot row 0x12e3598); GOT cell 0x1314628 holds vptr-0x10.

## Member notes

- Slots (vptr 0x12e35a0, 6): 0x9f9bc8 (D-family; re-installs own vptr at 0x9f9bdc), 0x9f9d4c, 0x9fa0a8, 0x9fa4d8, 0x9f9d70, 0x9f9f20 — all absent from functions.csv (unrecovered).
- C2 = 0x9f9918: vptr, flag 0 at +0x08, u32 at +0x0c (result of 0x57b07c, guarded by global byte at 0x130b528), three 0xe8-byte member subobjects at +0x10/+0xf8/+0x1e0 (each via 0x9f99d8), 0x57ceac init at +0x2c8, 0x574a70 buffer init (len 0x8000) at +0x2d0, fn pointer 0xa1f744 (cell 0x1314888+0x10) at +0x2d8, zero at +0x320.
- Secondary SharedCounterInterface vptr install not observed in C2 (likely inside member/base ctor 0x9f99d8) — unverified.

## Construction / init order

- Factory 0x9fd1cc: operator new(0x328) -> C2 0x9f9918 -> stored at [outer+0x2b0] (an earlier sibling at [outer+0x2b8], ti 0x12e4f88 family). Size 0x328 EXACT (max ctor store +0x320; factory new 0x328).
