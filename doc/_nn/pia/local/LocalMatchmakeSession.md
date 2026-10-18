# LocalMatchmakeSession (nn::pia::local::LocalMatchmakeSession)

- Primary vptr 0x12e1e38, installed from GOT cell 0x1314128 (RELATIVE addend
  0x12e1e28 = vt-0x10). The vt_ctors.tsv row 0x12e1e78 is NOT the vptr: it is
  slot 8 (0x71009d3644); the detector aligned on the first slot after the pure
  virtual at slot 7 (0x12e1e70 = __cxa_pure_virtual). Real header: typeinfo
  slot 0x12e1e30 -> typeinfo 0x12e1fc0, name string 0xf83738
  "N2nn3pia5local21LocalMatchmakeSessionE", offset-to-top 0x12e1e28.
- Size unverified; 0x60 is a lower bound (ctor store reach 0x5f).

## Identity

Session-object base for pia local matchmake jobs. A derived class (ctor
0x71009cc4b0, vptr from runtime cell 0x13130eb0) extends it to >=0x12f0 with
four 0x480-byte memset blocks and secondary vptrs at +0xb8/+0x550/+0x9d8/
+0xe60 — that derived object is allocated at 0x71009be418's caller chain.

## Slots

27 slots, mostly unrecovered FUN_*: slot 0 = 0x71009d31e8 (D2: installs
vptr 0x12e1e38, finalizes the +0x48 subobject via 0x7100929ee0), slot 1 =
0x71009d36d4, slot 7 = pure virtual, slot 8 = 0x71009d3644. State machine on
mState30 (0x71009d3254 switches on ==3 / ==4, reading +0x18).

## Member notes

- 0x08..0x17 — base subobject: base ctor 0x710097df48 installs a vptr from
  runtime cell 0x13130688 and zeroes the flag byte at +0x10; setter
  0x710097df6c writes the pointer at +0x8.
- 0x18 — ctor arg (C1 0x71009d319c x1).
- 0x30 — state word, 0 at ctor.
- 0x48..0x5f — trailing subobject: ctor 0x7100929ec0 zeroes +0x48 and the
  byte +0x60; D2 finalizes via 0x7100929ee0. Internal layout unproven.

## Construction / init order

1. C1 0x71009d319c: base ctor 0x710097df48, vptr 0x12e1e38 at [this],
   +0x18 = arg, +0x20/+0x28/+0x30w/+0x38/+0x40b = 0, subobject ctor
   0x7100929ec0 at +0x48.
2. Derived ctor 0x71009cc4b0 re-inits +0x68/+0x70/+0xb4, installs its own
   vptr, and memsets the four 0x480 blocks at +0xc0/+0x558/+0x9e0/+0xe68.
3. D2 0x71009d31e8 restores vptr 0x12e1e38 and finalizes +0x48;
   D0 0x71009d3204 wraps it with operator delete.
