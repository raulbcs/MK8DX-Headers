# recorder::ChannelSet (vtable 0x12c3ec8)

## Identity

Game-side recorder channel group of the ghost/replay recorder framework. 35 slots, no RTTI
(offset-to-top 0 and typeinfo 0 at 0x12c3ec8). Single GOT cell 0x130f8f8, whose RELA payload is
0x12c3eb8 (vptr-0x10); every site does `vptr = [cell] + 0x10` (GOT-cell convention: cell holds
vt-0x10). The only code site is 0x7ae194 inside recorderCreateRotTransChannels_71007ae16c,
which stores the vptr into `[this]` — so that function is the base-subobject constructor.

Constructed objects carry this vtable as their final vptr only when no derived override follows;
derived ctors call 0x7ae16c and then re-store their own vptr (e.g. site 0x7b18b8 re-stores after
the call and continues at +0x288). Smallest observed allocation of an object constructed by
0x7ae16c is 0x288 (`mov w0, #0x288` at 0x3ad69c); derived instances run larger (stores up to
+0x2b8 at setup FUN_71007b100c), so 0x288 is a lower bound for the derived space, exact for the
plain 0x288 instance. Derived-field observations beyond 0x288 (+0x288 void*, +0x290 u32,
+0x2b0 u32 count, +0x2b8 void* array) are unverified against this base and live only in the doc.

## Member notes

- 0x000 vptr — 0x12c3ec8.
- 0x1d4 int32 — write index used by the +0x110 writer slots recorderWrite3Ints_71007ae328 and
  0x7ae350 (`ldrsw x9, [x0, #0x1d4]`), added to the caller's out pointer.
- 0x278 void* — "rot" channel created by the ctor (see Construction).
- 0x280 void* — "trans" channel created by the ctor.
- Slot table: slot0 0x7aee48 / slot1 0x7aef14 (dtor pair, unverified which is D1/D0; both absent
  from functions.csv). Shared tail slots +0x90..+0xb0 (FUN_71007ab904/7abca8/7ac1d8) also appear
  in every channel vtable of this family. +0x100/+0x120 are recorderChannelFlag0_71003afce8 /
  _71003afcf4, +0x110/+0x130 recorderNoop_71003afcf0 / _71003afcfc. +0xc0 is
  sead::ExpHeap::isResizable (O) — shared sead-interface tail shared with the channel vtables.

## Construction / init order

recorderCreateRotTransChannels_71007ae16c(this, binder, kindTrans, kindRot), size 444 (W):

1. `[this+0x278] = [this+0x280] = 0`; vptr 0x12c3ec8 stored at `[this]` (0x7ae190-0x7ae1a4).
2. rot child (arg w3): 0 → `new 0x290` + vtable 0x12c4240, token 4; 1 → `new 0x290` + vtable
   0x12c4368, token 6; other → null. Stored at `[this+0x278]` (0x7ae1b8-0x7ae250).
3. trans child (arg w2): 0 → `new 0x288` + vtable 0x12c3ff0, token 6; 1 → `new 0x288` + vtable
   0x12c4118, token 4. Stored at `[this+0x280]` (0x7ae278-0x7ae2d8).
4. Each child is initialized with recorderBinderCtor_71007aae24 immediately after `operator new`
   (shared base init; formal inheritance unverified), then defaults: rot +0x1c0 = 36,
   trans +0x1c0 = 12; token at +0x1c4; min/step/inv-step at +0x1f0/+0x1f4/+0x1f8
   (rot min -70.0f at 0x7ae21c; trans min 0.2, step 16.0, inv-step 0.0625 at 0x7ae2f8-0x7ae314);
   owner pointer (arg x1) at rot +0x288 / trans +0x280.
5. recorderAddChannel_71007ac0cc(this, child, "rot" @0xf0a965 / "trans" @0xf0a969) registers
   each child (0x7ae268, 0x7ae2f0).

Callers: 0x25e8c, 0x1e2624, 0x3ad6b4, 0x3adce8, 0x7b10f8, 0x7b18b8, 0x7b1a38, 0x88ad64.
