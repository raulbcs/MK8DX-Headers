# recorder GhostCodec (GhostCodec.hpp)

Ghost stream trans/rot codec + record-layout builder. All addresses are original VMAs verified against the disassembly.

## World-space semantics (proven)

- dat "trans" channel d IS the kart world translation, raw (prep FUN_71007ae350 copies the latched u32 slots verbatim; RDP 0.2f / scale 1/16 happen only at pack time). Spawn = JugemPath[0].
- Reference point = origin of the chassis MOVE MATRIX (kart+0x20, channel p_move_mtx).
- "rot" record = HALF rotation vector: 3x4 row-major (36 B) -> recorderMatrixToQuat_71001963a0 -> recorderQuatToHalfRotVec_ 71003b2a64, out = (phi/sin(phi))*(q0,q1,q2); rotation angle = 2*phi; playback R = Rodrigues(2phi).

## Playback rot interp (vt+0xe8 slot; FUN_71007ae66c, extent 0x224)

Two 3x3 col-major stride-4 records (written by the exp-map FUN_71007adf64) -> quat via Shepperd interior 0x1963a0 -> slerp interior 0x2977b4 (frac = s0) -> quat -> 3x3 col-major 9 floats out. Facts:

- Shepperd 0x1963a0: csinc `le` picks 2/1 (not 2/3); record diag read at words 0/4/8 = col-major stride 4; the y-max branch @196500 builds qx from (R10-R01); qx uses the standard (R01+R10).
- Slerp 0x2977b4: thresholds +/-0.70710678 (rodata 0xed5cdc/d8); hemisphere fix via final sign (0x2979bc); |sin| < FLT_EPSILON (0xed58e0) -> nlerp (0x297950).
- Angle via asin fixpoint helper 0x61b690: scale 128.0 (rodata 0xed5a7c), LUT frac 2^-24. sincos LUT = rodata 0xf55d54 (256x4 f32), reached through bss pointer cell 0x12fb160; asin LUT = bss cell 0x130d360, filled at runtime init (zero in the binary). rodata file offset = vaddr - 0x128.

NOTE: the mode-0 Euler-sum path at 0x7a7b71c (inside ghostFrameRecordBuild_7100a7b414) is NOT the ghost path.

## Codec family index

```
FUN_71007ae350  trans record prep (vt 0x71012c4108 +0x98)
FUN_71007b0178  token-table channel re-quant, write-path only
                (FB20 vt +0xd8; slot stride 0x28, 2 floats/key)
FUN_71007b0a70  keyframe re-quant before FrameWrite (FB28 vt +0xd8)
FUN_71007b0e94  cyclic angle eval, FB28 playback tail (interior
                0x7b0fb4 = plain lerp variant)
FUN_71007b4404  RDP on vec3, stride 12 (sibling vec2 FUN_71007b37d8,
                stride 8, via wrapper FUN_71007b3734)
FUN_71007b42ec  trans/vec3 frame emit (writer FUN_71007a9d48,
                stride 0xc; container: +0 stride, +4 count, +8
                writer, +0x10 flag byte, +0x18 frame slot)
FUN_71007b5370  trans record-side frame wrapper (desc = TransWriteDesc)
FUN_71007b4ad8  trans point dequantizer (vt 0x71012c3fe0 +0xc8)
FUN_71007a9d48  frame writer, 532 B ([mask u64][init if bit0][tokens])
FUN_71007a9704  label sanitizer / key generator, 528 B (CRC32 rule
                in Recorder.md); called from FUN_71007a98e0
FUN_7100a7b414  ghostFrameRecordBuild (see GhostFrameRecord)
FUN_7100a886a4  Yaz0 decompress, 348 B (magic/size bswap32; bit1 =
                literal, bit0 = RLE; success leaves w0 unwritten)
FUN_7100045f78  record-layout builder unit 0x45f78..0x4647c (builder
                0x4607c reached only by the ctor tail branch; fills
                GhostRecordLayout)
```

OPEN (do not guess): [entry+0x18] is READ as u32 "sub" 1..9 by the builder, yet helper 0x87fd00 returns the same field as a 64-bit POINTER to the {lo,hi} mask pair.

## Mirrored structs

- GhostRecordLayout — mirror of the record-layout object built by FUN_7100045f78 (extent 0x378 — operator new(0x378) at the sole ctor caller 0x710002bd4, immediately before the bl FUN_7100045f78; offsets proven by the ctor/builder stores above).
- TransWriteDesc — mirror of the trans-channel write descriptor passed as x2 to FUN_71007b5370 (same shape as the Calc `info` arg).
- GhostFrameRecord — frame-record layout produced by ghostFrameRecordBuild_7100a7b414 (mode != 0), consumed by apply() FUN_71006ada8c.
- GhostStreamSession — FUN_71008754c0 stream-session state machine (offsets proven by its probes; reached via FUN_7100874cb0/74d68 from loader tick FUN_71004a8978).

## Side unit index (read/playback path)

```
FUN_71004a85a4  ghost file opener (612 B): path "Ghost/%s/%s"; mgr
                singleton FUN_71008bd3c8, Fast base mgr+0x130C000,
                Slow base mgr+0x653B0000; bucket adj 0/-27/-16;
                0x24-byte metadata entry -> target+0x210..0x22C
FUN_71006eccbc  default frame id: u16 w1 -> table[12*k+4] of the
                record table at *(entryObj+0x68)
FUN_71006abbf8  atomic frame-id gen: fetch-add at obj+0xCC, returns
                prev & 0x7ff (wraps every 2048 frames)
FUN_71003af93c  per-tick prep of the ghost playback ctx (kart pos /
                frontal dir into ctx+0x308..0x330; snap at *(ctx+0x288)
                is 12 words COLUMN-major)
FUN_710069ee98  dat chunk-set load: stream+0x100 = target; per-frame
                record array at hdr+0x18, stride 0x60 (apply
                FUN_71006ada8c)
```

## Construction / init order

- operator new(0x378) at sole ctor caller 0x710002bd4, then bl FUN_7100045f78 (record-layout ctor/builder unit 0x45f78..0x4647c).
- Builder 0x4607c is reached only by the ctor tail branch; fills GhostRecordLayout.
- Slot lists at +0xC0/+0x11C/+0x178 filled with 0xff by the ctor; idList +0x250..+0x370 receives 25 u32 -1 stores (0x250, 0x25c..0x370), final store idTail +0x370 ends 0x374.
- Sub-objects at +0xB0 and +0x1E0 initialized by FUN_710062ee28 (xorshift128 seed).
- Tail +0x1F0 (0x60 B) holds f32 -98.0 pairs (type<=1, sub 0/7/8).
