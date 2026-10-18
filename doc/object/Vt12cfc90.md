# object::Vt12cfc90

PLACEHOLDER name (theme unproven). vptr 0x12cfc90, 28 slots, typeinfo NULL, offset-to-top 0.
GOT cell 0x1310f40 holds 0x12cfc80 = vt-0x10; the row address IS the installed vptr
(cell + 0x10 stored into [this] at 0x86add4-0x86ade4).

Size 0x38: operator-new(0x38) at 0x198f58 followed by C1 0x86ad94 at 0x198f6c
(subsystem factory A; result stored at [mgr+0x150]); identical construction in factory B
(0x1e2f30/0x1e2f4c, stored [x19+0x300]) and factory C (0x204250/0x204270, stored
[x19+0x468]). After the C1 all three factories immediately call slot vt+0x58 with a float
in s0 (0x198f80 / 0x1e2f58 / 0x204278).

Slots: slot0 0x86b6e4 (4-byte thunk); slot1 0x86b6e8; slot2 0x869b40 (308 B); slot11
0x86b7ec is the vt+0x58 entry the factories call with a float; slot20 0x86b0f4 (536 B),
slot23 0x86b30c (336 B), slot26 0x86aebc (568 B — also called by the C1 via vt+0xd0);
slots 30-33 (0x8706f0/0x870760/0x86c2ac/0x86c2c0) form a secondary-base subtable pair;
rows 35+ hold rodata/far pointers (secondary region, unverified).

## Member notes

- 0x00 — vptr; 0x08 — [arg1] stored unconditionally (0x86ada8-0x86adb4 `stp x8, x0`).
- 0x10 — flags u32, zeroed (0x86add0); bit5 is set when [m28+0x20] == 0, cleared otherwise
  (read-modify-write 0x86ae1c-0x86ae30).
- 0x14..0x1f — 12 bytes copied from global cell 0x12fb148 ([0x12fb148] -> +0x14,
  [+0x12fb148+8] -> +0x1c; the same global the 0x869cxx anim-timing siblings read).
- 0x20 — initialized byte, zeroed then set to 1 after the first virtual update
  (0x86addc / 0x86ae0c-0x86ae10); 0x86ae40 checks it to make the vt+0xc8/vt+0xd0 pair
  run-once.
- 0x28 — [arg1+8]; when null, allocated via 0x8155cc (0x86adf0-0x86adfc); slot26 0x86aebc
  lazily re-creates it from [m08].

## Construction / init order

1. operator-new(0x38) at 0x198f58 (also 0x1e2f34 / 0x204258).
2. C1 0x86ad94 with (this, {ptr, ptr} pair on stack): +0x00 = vptr and +0x08 = [arg1]
   (0x86ada8-0x86adb4); +0x14/+0x1c from global 0x12fb148; +0x10 = 0; +0x20 = 0;
   +0x28 = [arg1+8] or allocation; virtual vt+0xd0 call; +0x20 = 1; flags bit5 update.
3. Caller stores the object and invokes vt+0x58 (slot 11) with s0 float (0.0 in two of
   the three factories, [x9+0x5c] in the first).
