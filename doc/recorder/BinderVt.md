# recorder::BinderVt (0x12c3af8)

Primary vtable of `recorder::Binder` (see include/recorder/Recorder.hpp for
the object layout; shared head ctor FUN_71007aae24 = recorderBinderCtor).

- Identity: ctor FUN_71007aae24 installs vptr 0x12c3af8 at +0x000 via GOT
  cell 0x130f7d0 (holds addend 0x12c3ae8 = vt-0x10; installed vptr =
  cell+0x10). 206 call sites construct this head; every QuantChannel variant
  and both mapped derived rows (0x12c3c78, 0x12c3da0) override it afterwards.
- Secondary pointers written by the ctor at +0x010 / +0x020 / +0x030 come
  from GOT cell 0x130f7d8, which holds the FUNCTION address 0x7aaf64 stored
  raw (no +0x10) — these are callback fields, not vptrs (corrects the
  "vt10/vt20/vt30" note in Recorder.hpp; unverified downstream use).
- Extent 0x288: Binder per Recorder.hpp; the base ctor stores up to +0x270
  and the mapped derivations extend to +0x288 (0x12c3da0) / stay 0x280
  (0x12c3c78).

## Slot notes

- Slots 0/1 (0x71003a8a0c / 0x71003a8a7c 92 B): presumed D2/D1 pair, shape
  unverified — the Binder D-path was not traced.
- Slots 6-8 (0x71007ab904 72 B, 0x71007abca8 208 B, 0x71007ac1d8 236 B) and
  the +0x80..+0xb0 accessor run (0x710001acd4, 0x71000a13d0, 0x710001acf4,
  0x71000a1404) are shared verbatim with rows 0x12c3b00, 0x12c3c78 and
  0x12c3da0 — the common channel/binder interface set.
- Slot 9 is the 8-byte thunk at 0x710001ac84 whose csv symbol is
  sead::ExpHeap::isResizable (shared generic thunk, not a heap call).
- recorderChannelFlag0_71003afce8 (8 B) sits at +0x68.

## Construction / init order

1. Owner allocates the channel/binder object and calls FUN_71007aae24:
   vptr at +0x000, +0x008 = 0, callback 0x7aaf64 at +0x010/+0x020/+0x030
   (+0x018/+0x028 zeroed), memset 0x38..0x111, counters/gates at +0x198,
   +0x19c = -1, +0x1a0..+0x1d0 init, floats 1.0/200.0/0.00390625 at
   +0x1f0/+0x1f4/+0x1f8, +0x238/+0x240/+0x250 interface ptrs (cells
   0x130f7e0/0x12fae28/0x130f7f0 + 0x10), +0x258 = this, +0x260 raw cell,
   +0x268 = 0, +0x1e8 via [cell 0x130f7c8]+0x00.
2. Variant ctor (see BinderVt derivations QuantChannelRawVt.md /
   QuantChannelReadVt.md) overrides +0x000 afterwards.
