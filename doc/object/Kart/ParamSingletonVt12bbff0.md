# object::ParamSingletonVt12bbff0

## Identity

- vtable 0x12bbff0, 6 slots, no offset-to-top/typeinfo (both words read 0).
  GOT cell 0x130e610 holds vptr-0x10 (0x12bbfe0); factory stores cell+0x10
  into [this]. Secondary row 0x12bbfd0 (2 slots) installed at [this+8]; its
  cell is 0x130e600 (holds 0x12bbfc0 = vptr-0x10).
- Size 0x98 EXACT: factory 0x707900 allocates `operator new(0x98, 8)`
  (0x70791c-0x707928) and caches the instance in holder 0x13587d0
  (reached via cell 0x130dee0), instance-pointer-guarded (cbnz, 0x707918).
- Primary slots: 0x00 0x707d20 and 0x08 0x707d28 are probe stubs
  (`ldr wzr, [x1]; ret`), 0x10 0x707d30 and 0x18 0x707d34 are `ret`
  stubs; slot 0x20 = D1 0x7079d4, slot 0x28 = D0 0x707a58 (D1 + operator
  delete). All four trivial slots unrecovered in functions.csv.
- Secondary slots: 0x707828 (complete) / 0x70788c (deleting) dtors of the
  +8 interface; both re-install the secondary vptr (cell 0x130e600+0x10),
  and if the global interface holder 0x13587c8 still points at this+8 they
  clear it, invoke primary slot 0x20 (D1) on the singleton, and null holder
  0x13587d0; the deleting slot then operator-deletes the object.

## Member notes

- +0x28/+0x30/+0x38/+0x40: heap pointers, each checked non-null and
  operator-deleted by D1 0x7079d4 (0x7079ec-0x707a24).
- +0x48 (w) + +0x50 (ptr) and +0x58 (w) + +0x60 (ptr): count/array pairs,
  zero-initialized; D1 delete[]'s both arrays and zeroes the counts
  (0x707a24-0x707a48).
- +0x7c-0x88: four words copied from read-only globals: [0xf6e5f4] (cell
  0x12fce50) into 0x7c/0x80/0x84 and [0xf6e5f0] (cell 0x12fce10) into 0x88
  (0x707978-0x7079a4). Unverified semantics (version-like constants).
- +0x8c/+0x8d/+0x8e: bytes 0/1/0 (0x7079a8-0x7079b4).
- +0x90: self-pointer to the singleton (0x7079b8).
- +0x10..0x27: not written by the factory; helper 0x61561c is called with
  this+8, the caller argument and constant 3 (0x707934-0x707940) and may
  initialize the secondary subobject region - unverified.

## Construction / init order

1. Factory 0x707900 (takes one argument): loads holder 0x13587d0 via cell
   0x130dee0; early-outs if instance already built (0x707910-0x707918).
2. `operator new(0x98, 8)` (0x707928); x21 = this+8.
3. Secondary vptr (cell 0x130e600+0x10 = 0x12bbfd0) -> [this+8]
   (0x707944-0x707950); this+8 published to global holder 0x13587c8
   (0x707954-0x70795c).
4. Helper 0x61561c(this+8, arg, 3) (0x707934-0x707940).
5. Primary vptr (cell 0x130e610+0x10 = 0x12bbff0) -> [this]
   (0x707960-0x707974).
6. Count/array pairs and scalars zeroed (0x707968-0x707990); global words
   into +0x7c-0x88; flags 0x8c/0x8d/0x8e = 0/1/0; self-ptr at +0x90
   (0x707994-0x7079b8).
7. Instance stored to holder 0x13587d0 (0x7079bc); return instance.
