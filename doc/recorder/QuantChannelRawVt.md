# recorder::QuantChannelRawVt (0x12c3c78)

Vtable of the no-quant ("raw vec2-s16") QuantChannel variant — the 0x280-byte
class in the QuantChannel factory rule (doc/recorder/QuantChannel.md).

- Identity: ~54 construction sites all share the same inlined sequence:
  `operator new(0x280)` (w0 = 0x280), shared head ctor FUN_71007aae24,
  then vptr override at +0x000 from GOT cell 0x12fb308 + 0x10 = 0x12c3c78,
  owner pointer at +0x278 (e.g. caller+0x348 at 0x710001e6c0, caller+0x37c at
  0x7100038730), +0x1c0 = 4 (and +0x1c4 = 4 per the factory rule), then
  recorderAddChannel_71007ac0cc(mgr, ch, name). Proven sites include
  0x710001e6c8, 0x7100038738 (kartPhysicsBodySlot88SpawnSubBody), 0x710003aa98,
  0x710003fa8c, 0x7100128708, 0x7100134bd0, 0x71001b2ce4, 0x71001c9778,
  0x71001d5b80 and 40+ more.
- Discrepancy: doc/recorder/QuantChannel.md cites cell 0x12fdb70 for the raw
  variant; cell 0x12fdb70 resolves to row 0x11c1aa0 (SDK region), while the
  proven inline sites above use cell 0x12fb308 -> 0x12c3c68. Both recorded;
  the 0x12c3c78 attribution here is from direct code evidence.
- Extent 0x280: allocation size passed to operator new at every site.

## Slot notes

- Slots 0/1 are NOT a dtor pair: slot 0 compares its argument against
  guard-initialized singletons (cells 0x12fb218 / 0x12fade0, +0x10) and slot 1
  returns the first singleton. Together with the constant getters
  (0x71007ad3a0..0x71007ad3e8) and read/write accessors (0x71007ad3fc /
  0x71007ad418 / 0x71007ad43c operating through [this+0x278] and idx
  [this+0x1d4]) this row is the meta/data-node interface of the binder
  family.
- Slots 18-23 are the shared Binder interface set (0x71007ab904,
  0x71007abca8, 0x71007ac1d8, 0x710001ac84..0x710001ac98), identical in rows
  0x12c3af8/0x12c3b00/0x12c3da0.
- The +0x70..+0x88 block duplicates the read/write slots with no-op tails
  (0x71007ad48c/0x71007ad490 = plain ret).

## Construction / init order

1. Caller: ch = new 0x280.
2. FUN_71007aae24(ch) initializes the shared Binder head (see
   doc/recorder/BinderVt.md).
3. ch->vptr = 0x12c3c78 (cell 0x12fb308 + 0x10); owner -> +0x278;
   +0x1c0 = 4 (+0x1c4 = 4).
4. recorderAddChannel_71007ac0cc(mgr, ch, name).
5. Destruction path not traced (no dtor pair on this row); the Binder dtor
   slots on 0x12c3af8 are the likely delegation target (unverified).
