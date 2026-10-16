# recorder QuantChannel

Quantized recorder channel — objects created by the channel factory FUN_71001ca6e8(min[s0], max[s1], step[s2], flags[w1]) used by the recorder channel setup (0x71003ad660..0x3af740, 50 sites) before each recorderAddChannel_71007ac0cc(this, obj, name).

## Factory selection rule (all proven from the factory body)

```
levels      = span / step, span = max(|min|, |max|) (x2 when the range
              crosses zero and flags bit0 set — wrap mode)
qbits       = int(log2(levels)) + 1 (+1 when wrap)
qbits >= 17 -> alloc 0x290, raw memmove class (vptr [0x12fe718]+0x10),
               +0x1c0 = 8, +0x1c4 = 0 (width set per payload)
no quant    -> alloc 0x280, raw vec2-s16 class ([0x12fd000+0xb70]+0x10),
               +0x1c0 = 4, +0x1c4 = 4
9..16 bits  -> alloc 0x298, vec2 class ([0x12fe000+0x718/0x720/0x728]
               +0x10), +0x1c0 = 8, +0x1c4 = 4 (wrap+interp) / 2
< 9 bits    -> alloc 0x288, scalar class ([0x12fe000+0x730/0x738/0x740]
               or [0x12fb000+0x500] +0x10), +0x1c0 = 4,
               +0x1c4 = 2 (wrap/min-max) or 1 (u8)
```

Field offsets are proven by factory stores (object size = the allocation size passed to operator new: 0x280/0x288/0x290/0x298 by class). 0x71007aae24 initializes the shared head of every variant.

## Read-side quant object layout

Setup FUN_71007b100c / factory FUN_71007b9400: +0x1c0 = numValues (e.g. 12 for p_move_mtx, 4 for scalar channels), +0x1c4 = token format in bytes (1/4/6), +0x1f0/+0x1f4/+0x1f8 = min / step / 1/step, +0x278 = back reference to the owning mgr, +0x288 = channel index, +0x220/+0x228 = delta once-changed state (two u64s). Decoded value = min + token*step (mod span); the per-block record reloads step when its key matches the frame time key (FUN_71007aa490): that record is the 12 B file entry { u32 key; u32 packed; float step } of the channel directory (see recorder/Recorder.md) — the float step at entry+0x8 is what lands in +0x1f4 (+0x1f8 = 1/step), overwriting the setup-time values below for that block.

## Per-point quantizers (each returns [ch+0x1c4] = substream width)

- FUN_71007b424c — 2-comp byte quantizer: v = in[j]*[+0x1f4], clamp [+0x280,+0x284] (NaN falls through to the min/max branches), 1 B/comp.
- FUN_71007b45a4 — 3 comps packed into ONE u32 token: comp0 bits 0-9, comp1 bits 11-20, comp2 bits 21-30 (fcvtzs(in[j]*[+0x1f4]); clamps to the field half-ranges; bits 10/31 stay zero).

## Construction / init order

- FUN_71001ca6e8 — channel factory: computes levels/qbits, selects variant per the rule above, operator new(0x280/0x288/0x290/0x298), installs the class vptr (cell listed above) + 0x10.
- 0x71007aae24 — initializes the shared head of every variant (fields per include/recorder/Recorder.hpp Binder ctor).
- Factory stores set +0x1c0 (numValues) and +0x1c4 (width/format), +0x1f0/+0x1f4/+0x1f8 (min/step/1-step) per variant.
- recorderAddChannel_71007ac0cc(this, obj, name) registers the channel after setup.

## Unresolved conflict (unverified)

ScalarQuantChannel: the prior-survey allocation claim is 0x288 bytes, but the factory-store offsets place min_288 at 0x288..0x28c — field end 0x28c exceeds the claimed allocation. Both claims are recorded; the extent is cited as 0x28c (field end) pending re-verification of the allocation site.
