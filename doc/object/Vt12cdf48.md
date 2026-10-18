# Vt12cdf48

PLACEHOLDER name (address-anchored). 44-slot interface object created by the
unnamed subsystem factory at 0x3835e8 (allocated with id w1=2 passed to the
base-ctor helper; the object's slot-6 virtual (offset 0x30) is then called
with w1=2 at 0x3836d4).

- Identity: no RTTI; no owned string recoverable. Name stays PLACEHOLDER.
- vptr convention: GOT cell 0x1310db0 holds 0x12cdf38 (vt-0x10); installed
  vptr = cell+0x10 = 0x12cdf48, i.e. the table row address is the vptr.
- Table 0x12cdf48: 44 slots (0x12cdf48..0x12ce0a8); offset-to-top and typeinfo
  words (0x12cdf30/0x12cdf38... actually at 0x12cdf30/0x12cdf38) are zero.
- Ctor FUN_71008513f4 (0x8513f4..0x851444, 84 bytes): calls helper
  FUN_7100852f44(this, w1=2) first (0x7100851408), then installs the vptr
  (0x710085141c) and zeroes +0x1c8/+0x1ca (0x710085142c/0x7100851430).
- Extent: caller 0x3836a8 allocates 0x1d0 via operator new (0x38369c..0x3836a8)
  then calls the ctor.
- Sibling: Vt12ce3f0 has a near-identical 44-slot layout and its own ctor; the
  two are distinct leaf implementations, not a base/derived pair (no shared
  ctor path observed).

## Member notes

- +0x1c8 u16 and +0x1ca u8 zeroed by ctor; only fields touched by the cited
  code; the 0x08..0x1c8 range is unproven.
- Slot 0 (0x85238c, 284 B) is the dtor family head; slot 2 (0x8524a8, 8 B) is
  a trivial stub. Slot 6 (0x852630) is the target of the factory's
  post-construction virtual call with the id argument.

## Construction / init order

1. Factory 0x3835e8: operator new(0x1d0) (0x38369c..0x3836a8).
2. Ctor FUN_71008513f4: helper FUN_7100852f44(this, 2) (0x7100851408);
   vptr 0x12cdf48 at +0x00 (0x710085141c); +0x1c8/+0x1ca zeroed
   (0x710085142c/0x7100851430).
3. Factory: slot-6 virtual call with w1=2 (0x3836c8..0x3836d4).
