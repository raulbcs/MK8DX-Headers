# nn::nex::JobHttpBuffered

RTTI-named (typeinfo 0x12e5830, mangled "N2nn3nex15JobHttpBufferedE"; no base typeinfo entry — the class has its own MI secondary table instead). Typeinfo-slot variant: assigned row 0x12e5550 is the typeinfo slot, offset-to-top 0 at 0x12e5548, installed vptr = 0x12e5558. GOT cell 0x13148b8 holds vptr-0x10. 18 primary slots (vt+0x08..vt+0x98).

Size 0x1a0: factory 0xa2149c allocates 0x1a0 via 0x573f04 (0xa214f8) and runs the inline C1 (0xa21520-0xa21608).

## Member notes

- [this+0x08..0x9f] — nex job base region built by the shared job ctor 0x588b04 (x1=0); primary base vptr 0x12e54d0 via cell 0x13148b0. Interior unverified.
- [this+0xa0] u32 zero; [this+0xa8] ptr zero — released in D1 (0xa22950): virtual release via [x0]slot8 at 0xa229b8, plus refcount cell 0x13148c0 (0x1366e78) decrement and singleton release through cell 0x13148c8.
- [this+0xb0] — nn::nex::Job secondary vptr 0x128c698 (cell 0x130b4a8).
- [this+0xb8] byte zero; [this+0xc8] = self-pointer to +0xb8; [this+0xd0] = 0x10.
- [this+0xe0]/[this+0xe8] — pointer pair reset by D1 (0x5763ac).
- [this+0x110] u32 — 10 or 5, selected by the byte at data 0x128cd98 (cell 0x130b808).
- [this+0x118] — own MI secondary vptr 0x12e5600 (vt+0xb0). Secondary table at vt+0xa0: offset-to-top -0x118 (0xfffffffffffffee8), typeinfo 0x12e5830, vptr 0x12e5600, slots 0xa22a3c (this adjustor, sub #0x118), 0xa22a68 (D0 thunk, sub #0x118 then primary D0), 0xa230fc, 0xa22eb8, 0xa22a9c, 0xa22d80, 0xa2343c, 0xa23738, 0xa23988 — all unrecovered in functions.csv.
- [this+0x138]/[this+0x140] — buffer from 0x576368 with use counter (init 0 then incremented to 1; byte at *buffer cleared). D1 resets the counter if it matches.
- [this+0x170] = pointer to +0x178; [this+0x160..0x190] zeroed; [this+0x198] byte = 1.

Slot map: slot0 = D1 0xa22950 (restores +0x118 and +0xb0 vptrs, releases members, ends in base destroy 0x5790b4), slot1 = D0 0xa22a44; slots +0x18..+0x68 are the shared nex::Job tail (0x5917a0, 0x58ff6c, 0x5917ac, 0x590148, 0x59014c, 0x5917b0, 0x5917cc, 0x58b7d8, 0x5917d4, 0x5917d8, 0x59189c) also found on JobNNIDLogin/JobFileServer; slots +0x70..+0x98 (0xa25578, 0xa22a90, 0xa22aa8, 0xa22d88, 0xa22ec0) unrecovered — override set unverified.

## Construction / init order

- Factory 0xa2149c: guard check 0x5822fc → new(0x1a0) at 0xa214f8 (0x573f04) → shared job ctor 0x588b04(this, 0, sp+0x48) → inline field init (0xa21520-0xa21608): +0xa0/+0xa8 zero, +0xb0 Job vptr, +0xb8 zero, +0xc8/+0xd0 self-ptr+0x10, +0xd8..+0x108 zero, +0x110 flag select, +0x118 secondary vptr, +0x120=0x10, buffer/counter init at 0xa215d0-0xa215f0, remaining zeros.
- D1 0xa22950 → D0 0xa22a44 (operator delete 0x573f48); secondary D0 thunk 0xa22a68 subtracts 0x118.
