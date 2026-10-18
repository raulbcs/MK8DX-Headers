# nn::nex::AnyDataAdapter

- Identity: RTTI-confirmed. Row 0x12e70d8 holds the typeinfo slot
  (ti 0x12e77f0 -> name "N2nn3nex14AnyDataAdapterE" at 0xf86160). GOT cell
  0x1314d68 holds 0x12e70d0 (row-0x8); installed vptr = cell+0x10 =
  0x12e70e0 (row+8). 38 slots (0x12e70e0..0x12e7208).
- slot0 D1 = 0xa40b24 (reinstalls vptr from cell 0x1314d68 at 0x7100a40b28,
  tail-calls base D1 0x9e56cc); slot1 D0 = 0xa40b38 (same reinstall, base D1,
  then operator delete 0x573f48); slot3 = FUN_7100a42328 (4 B). slots 4-14,
  16-28 are small
  thunks 0xa41284..0xa41470; slot15/33/34 shared stubs 0xa19260/0xa19270/
  0xa19278; slot29 = FUN_7100a40be4 (2056 B); slot30 = FUN_7100a40f0c (626 B);
  slot35-37 = 0xa41454/0xa41424/0xa4143c.
- Ctor: FUN_71009e55f4, called by the factory on raw memory
  (0x7100a41a3c) with (this, x1, x2).
- Factory: FUN at 0x7100a41a08 — allocates 0xd8 bytes (0x7100a41a24,
  allocator 0x573f04), calls the ctor, then zeroes +0xc0..+0xcf and +0xd0
  (0x7100a41a48-0x7100a41a4c) and overrides [this] with the final vptr
  0x12e70e0 (0x7100a41a50). Returns null on allocation failure.
- Extent: 0xd8 (factory allocation).
- Second construction path: 0x7100a41a44's enclosing block (0x7100a41908
  region) builds the same object inline from an outer 0x4? allocation — the
  same zero/vptr sequence at 0x7100a41a48-0x7100a41a54.

## Member notes

- +0xc0..+0xd3: zeroed post-ctor by the factory — unverified semantics.
- The vtable reinstall pattern (slots 0/1 re-derive the vptr from the GOT
  cell rather than storing a literal) matches the batch-3d pia-family style.

## Construction / init order

1. Factory allocates 0xd8 bytes.
2. FUN_71009e55f4 initializes the base subobject and members.
3. Factory zeroes +0xc0..+0xd3 and installs vptr 0x12e70e0.
