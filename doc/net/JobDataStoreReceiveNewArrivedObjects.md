# object::JobDataStoreReceiveNewArrivedObjects

RTTI-CONFIRMED:
nn::nex::JobDataStoreReceiveNewArrivedObjects<nn::nex::DataStoreApiVersionTraits<nn::nex::DATASTORE_API_VERSION_0>>.
Typeinfo record 0x12f7480; typeinfo pointer at vptr-8 = 0x12f6ee0 —
tools/vt_ctors.tsv's "0x12f6ee0" is the typeinfo slot. Installed vptr =
0x12f6ee8 (GOT cell 0x1315978 holds 0x12f6ed0 = row-0x10; sites add +0x10).

## Identity

- Factory (nex JobDataStore workflow function): `operator new(0x508)` at
  0xb1a6b4, base C1 0x588b04(this, 2, &out), then field init and vptr
  0x12f6ee8 -> [this] (0xb1a6fc).
- vptr installed at 0xb1a6d4 (C1) and 0xb2bd28 (inside slot-0 function
  0xb2bd1c — vptr reinstall, dtor/clone path).

## Member notes

- [this+0xB8] u8 = 1 (0xb1a6e4); [this+0xBC] u32 zero.
- [this+0xC0] — member initialized by FUN_7100a2bf88 (0xb1a700, arg 0).
- [this+0x188] — nn::nex::Socket secondary base, vptr 0x128c698 (GOT cell
  0x130b4a8 -> row 0x128c688); initialized by 0x578f98 with the empty
  C-string at 0xed6af8 (0xb1a730).
- [this+0x190/0x198/0x1A0/0x1A8] — {self ptr to +0x190, 0x10} pair repeated
  (0xb1a71c-0xb1a72c): a 0x10-capacity inline buffer header.
- [this+0x1D8] and [this+0x338] — two 0x160-byte memset-zero buffers
  (0xb1a750/0xb1a760).
- [this+0x498..0x4CF] — seven zeroed qwords (0xb1a764-0xb1a77c).
- Slots: slot 0 0xb2bd1c (276 B, D0-like), slot 1 0xb2be30 (36 B, D2-like),
  slots 2-5 shared with JobDataStoreGetRating (0x5917a0, 0x58ff6c, 0x5917ac,
  0x590148), slot 13 0xb2be54 (828 B), slot 14 0xb2c3c8 (816 B); slots 6-12
  unrecovered (same shared nex job stubs).

## Construction / init order

- new 0x508 -> base C1 0x588b04 -> zero/flag +0xA0..0xBC -> vptr -> member C1
  0xa2bf88 at +0xC0 -> Socket base at +0x188 -> buffer headers -> memsets ->
  trailing zeros.
- Extent 0x508 proven by the alloc size at 0xb1a6b4.
