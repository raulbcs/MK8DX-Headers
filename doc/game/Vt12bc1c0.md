# Vt12bc1c0 (placeholder name)

## Identity

- Assigned row 0x12bc1c0 = 6 slots, offset-to-top -0x30 at 0x12bc1b0,
  typeinfo NULL at 0x12bc1b8. It is the SECONDARY vptr (installed at
  [this+0x30]) of an undocumented base class whose primary vptr is
  0x12bc0f0 (row 0x12bc0e0, 24 slots, off/ti 0 at 0x12bc0e0/8).
- GOT convention: NO reloc targets this table. Cell 0x130e648 (plain
  .got data, no RELA entry) holds 0x12bc0e0 = primary row; code loads
  it and adds 0x10 (primary vptr) or 0xe0 (this secondary vptr).
- Base class of ParamContainerVtc338 (primary 0x12bc338, cell
  0x130e660, doc/object/Kart/ParamContainerVtc338.md): the derived
  factory 0x712c7c allocates 0x370, calls this base C2 0x71170c
  (0x712ca0), then OVERWRITES both vptrs with the derived pair
  (cell 0x130e660: +0x10 at [this], +0xe8 at [this+0x30]).

## Member notes

- Slots (vptr+0x00..+0x28): D1 0x7128e4, D0 0x71292c, then the shared
  hook-band thunks 0x648094 / 0x6480a0 / 0x6480a8 / 0x6480b4 (slot2
  forwards to primary vtable+0x80; slot3 `add x0,#0xa0; ret`; slot4
  adjusts -0x30 and vcalls vtable+0xb0; slot5 returns byte [x0+0x82]
  & 1).
- D1 0x7128e4 (0x7128e4-0x71292c): restores primary vptr
  (cell 0x130e648 +0x10 = 0x12bc0f0) at [this-0x30], restores the
  secondary vptr 0x12bc1c0 at [this], re-installs the ChanBase vptr
  0x12b3af0 (cell 0x130d918 +0x10) at [this+0x240..+0x2e0 step 0x20]
  (6 channel-pair members), then tail-calls 0x64ebc0 (dtor
  continuation: frees [x+0x268]/[x+0x258], restores its own vptrs).
- D0 0x71292c (0x71292c-0x71298x): same stores, framed variant.
- size 0x370 is the DERIVED class alloc (factory 0x712c7c:
  (0x712c8c `mov w0,#0x370`, new 0x712c98) — fix: factory 0x712c7c
 No base-exclusive factory
  exists, so the base-only size is a lower bound; the 0x370 shell
  (vptrs +0x00/+0x30, zeroed tail 0x338-0x36e) is what the only known
  allocation provides.

## Construction / init order

- Base C2 = 0x71170c (0x71170c-0x711950, 576 bytes): installs
  cell 0x130e648 +0x10 at [x19] and +0xe0 at [x19+0x30] (0x711744 /
  0x711754), then constructs the channel-pair members with the shared
  KartParamCacheChan ctor pair 0x662f30 / 0x662f70 (e.g. member at
  +0x270, name string 0xf03dc1, fn cell 0x12fae28 +0x10; owner
  back-ptr arg x4; 0x711758-0x7117f8), zeroing flag bytes between
  members (0x7117b0).
- The derived factory 0x712c7c finishes the object: nulls 0x338-0x348,
  writes 0xffff halves at 0x360/0x36c, zeroes 0x364/0x36e (0x712ca4-
  0x712ce8) — derived fields, not part of the base C2.
