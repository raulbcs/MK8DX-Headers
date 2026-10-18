# Vt12f1dd8

Unnamed game class; no RTTI (off-top 0 at 0x12f1dc8, typeinfo slot 0x12f1dd0
= 0). Serves as the base subobject of a larger derived object constructed
in place by FUN_71007d5a78.

- Identity: unknown. The derived init (FUN_71007d5a78) touches
  nn::hid::SetSupportedNpadIdType and a 0xf73678 constants block, but no
  string evidence for the class itself.
- Ctor: FUN_7100a7ee00 (96 B, site 0xa7ee1c). Calls base ctor 0x635b58,
  installs vptr (GOT cell 0x1314fd8 holds 0x12f1dc8 = vptr-0x10, site adds
  0x10), stores 0x11 at +0x138, arg w2 at +0x178, 0 at +0x17c, 5 at +0x17d,
  tail-calls 0x635f4c(this, 0, 0).
- Derived product: size 0x298 EXACT (operator new 0x2940+ per-element
  0x298 alloc w0=0x298 at 0x7d5b48). After the base ctor, the caller
  overrides the vptr with the derived vptr (GOT cell 0x1310020, vptr
  0x12c7f90) and installs a secondary vptr 0x12c7fe8 (cell+0x68) at +0x180;
  then zeroes +0x188/+0x1b8/+0x1fc/+0x204 and memsets +0x230 len 0x5c.
- Slots (9): +0x00 0xa7f5b0 and +0x08 0xa7f6d0 are guard-initialized
  singleton accessors (unusual for slot0/1, unverified role); +0x10
  0x6332a4; +0x18 0xa7f72c = tail `b operator delete` (deleting dtor
  stub); +0x20 0x635bcc; +0x28 0xa7ee60 (returns byte +0x17c & 1, then-1
  getter); +0x30 0xa7ee6c; +0x38 0x635cf8; +0x40 0x635cfc. All unnamed in
  functions.csv.

## Construction / init order

1. Caller FUN_71007d5a78 allocates 0x298 bytes per element.
2. FUN_7100a7ee00(this, &mgr, idx): base 0x635b58, vptr, +0x138=0x11,
   +0x178=idx, +0x17c=0, +0x17d=5.
3. Caller overrides vptr to 0x12c7f90 and stores secondary vptr
   0x12c7fe8 at +0x180.
4. Sub-object init at +0x188, memset +0x230 len 0x5c.
