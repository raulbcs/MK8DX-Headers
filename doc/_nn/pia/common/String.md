# nn::pia::common::String

Identity: typeinfo-row vtable, assigned address 0x12d9610 (= typeinfo slot,
vptr-8); installed vptr **0x12d9618**. GOT cell 0x1312820 holds vptr-0x10
(0x12d9608). Typeinfo record 0x12d9648, name "N2nn3pia6common6StringE".
6 slots (0x12d9618..0x12d9640). Base class of the
nn::pia::common::FixedString<N> instantiations (their typeinfo records list
0x12d9648 as base).

## Member notes

- +0x00 vptr 0x12d9618; +0x08 data pointer (char* or char16*, per mode).
- +0x10 u32 zeroed by both ctors; +0x14 u32 length in code units; +0x18 u32
  mode (1 = char, 2 = char16). Size 0x1c (lower bound - no allocating
  factory found; object always embedded or caller-provided).
- Slots: 0x9118d8 (slot0, shared `ret` stub), 0x92adb0 (slot1, tail-branch
  `operator delete` = deleting dtor, trivial dtor), 0x92a7e8 (slot2, shared;
  reads [x1+0x8] - assign/copy from source, unverified), 0x92aa5c (slot3,
  unrecovered), 0x92adac (slot4, shared `ret` stub), 0x92a6e4 (slot5,
  unrecovered). All absent from functions.csv.

## Construction / init order

1. C1 FUN_710092a664 (0x92a664..0x92a660-range, 64 B): [this] = vptr from
   cell 0x1312820 + 0x10 (0x92a668-0x92a674), [this+0x08] = x1 char*,
   [this+0x10] = 0, mode 1 at +0x18 (0x92a678), then strlen scan writes
   length to +0x14 (0x92a680-0x92a69c).
2. C1 FUN_710092a6a4 (0x92a6a4.., 168 B): same but char16 source; mode 2 at
   +0x18 (0x92a6b8), strlen16-style scan to +0x14 (0x92a6c0-0x92a6dc).
3. Both ctors take the buffer pointer as x1 - String itself owns no inline
   storage (contrast FixedString<N>, whose data pointer targets its own
   +0x1c inline buffer).
