# enl::LoggingStreamFormat

Behavior-named (PLACEHOLDER-quality) stream-format wrapper that routes every
read through FUN_7100626104 and mirrors the value into a printf-style log
line. Format-string table at 0xeeff31 ("%u", "%llu", "%d", "%lld", "%.8f").

- Identity: no RTTI. GOT cell 0x130d418 holds 0x12b08c0 (vt-0x10); the
  installed vptr is cell+0x10 = 0x12b08d0. Offset-to-top (0x12b08c0) and
  typeinfo (0x12b08c8) are both 0.
- Ctor FUN_7100625f60 (0x625f60..0x626060), reached through thunk
  FUN_7100625f1c (4 B). No operator-new site found; size 0xa0 is a
  lower-bound estimate from the max field store (unverified).
- Derives sead::StreamFormat (slot shape matches sead::BinaryStreamFormat,
  cf. doc/enl/Vt12b05f0.md): slots 0-7 are uniform 156-byte logging wrappers
  over the per-width read implementations, later slots (0x626a78 252 B,
  0x626c84 756 B, ...) are the bigger read/write methods.

## Member notes

- +0x00 vptr 0x12b08d0 (0x625f98).
- +0x08 subobject with its own vptr: pre-stored from cell 0x12fada0
  (0x625fa0), re-set by the subobject ctor call FUN_710061cc48 (0x625fac),
  then overwritten from cell 0x12fc1e0 (0x625fbc) and finally cell
  0x12fb180 (0x626054). Exact subobject type unverified.
- +0x10 pointer initialized to this+0x1c (0x625f84..0x625f8c); if it does
  not already point at the rodata literal 0xeef0f31 (" ", whitespace
  table), the ctor scans a long NUL-separated string for the delimiter
  byte (0x625fd4..0x62601c) and memcpy's up to 0x80 bytes into the
  internal buffer (0x626040), NUL-terminating (0x626044).
- +0x18 u32 = 0x80, the buffer capacity (0x625f9c, stored 0x625fa8).
- +0x1c..0x9b char buffer receiving the copied string; unverified content
  semantics (looks like a stream/channel name for the log lines).
- Usage: consumer at 0xac9404 loads [vptr+8]/[vptr+0x30] from the table via
  cell 0x130d418 and walks fields +0x30/+0x38 of the format object.

## Construction / init order

1. Caller allocates (site not isolated; thunk FUN_7100625f1c is a tail-call
   shim) and calls ctor FUN_7100625f60.
2. Ctor stores vptr 0x12b08d0 at +0x00 (0x625f98) and the subobject vptr
   cell at +0x08 (0x625fa0).
3. +0x10 = this+0x1c, +0x18 = 0x80 (0x625f8c, 0x625fa8).
4. Subobject ctor FUN_710061cc48 on +0x08 (0x625fac).
5. Delimiter scan + memcpy of the name into +0x1c, vptr fixups from cells
   0x12fc1e0 (0x625fbc) and 0x12fb180 (0x626054).
