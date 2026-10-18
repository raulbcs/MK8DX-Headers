# nn::nex::AcquireNsaIdTokenClient

## Identity

- vtable 0x12e7c78, 14 slots. GOT cell 0x1314e28 holds 0x12e7c68 = vptr-0x10
  (offset-to-top row 0x12e7c68 = 0, descriptor slot 0x12e7c70 = 0x12e7e40);
  installed vptr = cell+0x10.
- RTTI: descriptor 0x12e7e40 = {0x10, name 0xf86490, base 0x128d520, 0};
  name 0xf86490 = "N2nn3nex23AcquireNsaIdTokenClientE"
  (nn::nex::AcquireNsaIdTokenClient); base 0x128d520 = StepSequenceJob.
- Slot map (14): 0 D1 0xa45298 (552 B), 1 D0 0xa45334, then the shared
  nex-family cluster 2 0x5917a0, 3 0x58ff6c, 4 0x5917ac, 5 0x590148,
  6 0x59014c, 7 0x5917b0, 8 0x5917cc, 9 0x58b7d8, 10 0x5917d4, 11 0x5917d8,
  12 0x59189c, and a 14th trailing slot 0x0 (null).
- D1 0xa45298: re-installs vptr 0x12e7c78; if [+0xc8] is set, polls
  nn::account::AsyncContext::HasDone (0xb54fd0), reports via 0x577ab4 with
  the rodata string at 0xf157c6, cancels the context (0xb54fe0) and waits on
  the +0xd0 nn::os::SystemEventType (0xb53690); then destroys +0x108 via
  0x589720; if [+0xf8], DestroySystemEvent (0xb52800); AsyncContext D1
  (0xb54ff0); tail 0x588bd0 (shared job-base D1).
- Sites (vt_ctors): 0xa452ac (inside D1) and 0xa44e64 (factory
  FUN_7100a44e08, which also runs the placement constructor inline).

## Member notes

- Size 0x150 PROVEN: operator new(0x150) at 0xa44e40 (alloc helper 0x573f04),
  then shared job ctor 0x588b04(this, 2, scratch) at 0xa44e5c.
- Shared job region [0x00,0xa0) from 0x588b04 (see JobTerminate.md),
  including secondary vptr 0x128d9f8 at +0x78; factory overwrites [this]
  with 0x12e7c78 (0xa44e74).
- +0xa8 nn::account::AsyncContext (0x20 bytes): C1 at 0xa44e78
  (nn::account::AsyncContext::AsyncContext), D1 at 0xa45318.
- +0xc8 u8 busy flag; +0xd0 nn::os::SystemEventType (0x28 bytes) with the
  created flag at +0xf8; +0x100 u32 = 0; +0x108 member (init 0x5896c0 /
  destroy 0x589720); +0x130..+0x150 zeroed (0xa44e90-0xa44e94).

## Construction / init order

1. FUN_7100a44e08: operator new(0x150) (0xa44e40).
2. Shared job ctor 0x588b04(this, 2, scratch) (0xa44e5c).
3. Factory: +0xa0 = 0; nn::account::AsyncContext C1 at +0xa8; +0xc8 = 0;
   +0xf8 = 0; +0x100 = 0; 0x5896c0(this+0x108); zero +0x130..+0x150
   (0xa44e68-0xa44e94).
