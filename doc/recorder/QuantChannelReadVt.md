# recorder::QuantChannelReadVt (0x12c3da0)

Vtable of the read-side (playback) decoded channel: a Binder-head object that
replaces the primary vptr and attaches a `_Znam` payload.

- Identity: ctor FUN_71007ad494 (156 B, (this, w1, w2)) first calls the shared
  head ctor FUN_71007aae24 (0x71007ad4b0), then installs vptr 0x12c3da0 at
  +0x000 via GOT cell 0x130f8c0 (addend 0x12c3d90 = vt-0x10; installed vptr =
  cell+0x10). All 5 call sites are followed by further inlined init
  (e.g. 0x71003a7bd4: zeroes +0x288/+0x290/+0x410 and overrides +0x000 again
  with cell 0x1307748 + 0x10 — a deeper in-place derivation).
- Payload: `_Znam(w19*w20+4)` stored at +0x280 with [ptr] = 0; w19 -> +0x278,
  w20 -> +0x274, w19*w20+4 -> +0x1c0 AND +0x1c4, +0x210 = 0; tail-calls
  FUN_71007ab1b8 (596 B) with (this, NULL). Matches the read-side layout in
  doc/recorder/QuantChannel.md (+0x1c0 numValues, +0x1c4 token byte width).
- Extent 0x288 (lower bound): last field of this ctor is the +0x280 pointer;
  in-place derived users store up to +0x410. No dedicated allocation found
  for the bare class.
- Slots: slot 0/1 presumed D2/D1 (0x71003a8564 / 0x71003a8630 92 B,
  unverified). Slot 8 = getRecorderKeyStr_71007adb78; slots with
  recorderWriteZero/recorderWriteZero4 encode zero-padding writes. Slots 9
  and 12 are the shared Binder interface entries (0x71007ab904,
  0x710001ac84).

## Member notes (relative to the Binder head, see Recorder.hpp)

- +0x274 u32 = w20 (element byte width), +0x278 u32 = w19 (count),
  +0x1c0/+0x1c4 u32 = w19*w20+4, +0x210 = 0.
- +0x280 payload = new u32[w19*w20/4+1] zero-terminated ([ptr] = 0);
  freed/reinited by 0x71007ad508 (the slot-10 fn reads [this+0x280] and
  stores 0 — reset path).

## Construction / init order

1. Caller allocates the enclosing object (offset 0 = this channel).
2. FUN_71007ad494: Binder head init (0x71007aae24), vptr 0x12c3da0 at +0x000,
   counts at +0x274/+0x278, +0x1c0/+0x1c4, _Znam payload at +0x280,
   tail FUN_71007ab1b8(this, NULL).
3. Inlined site code (e.g. 0x71003a7bd4) zeroes +0x288/+0x290/+0x410 and
   overrides +0x000 with its own row (cell 0x1307748 + 0x10).
