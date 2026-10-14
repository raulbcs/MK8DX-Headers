#pragma once

#include <cstdint>

/*
 * Ghost stream trans/rot codec + record-layout builder .
 *
 * All addresses are original VMAs verified against the ported TUs.
 * Playback-side frame/ring facts live in recorder/Recorder.hpp; this
 * header documents the write-path codec family, the node-class bundle
 * (FB20/FB28/FB38), and the record-layout builder unit.
 *
 * WORLD-SPACE SEMANTICS :
 *   - The dat "trans" channel `d` IS the kart world translation, raw:
 *     prep FUN_71007ae350 copies the three latched u32 slots VERBATIM
 *     (no transform at any stage; RDP 0.2f and scale 1/16 happen only
 *     at stream pack time). Spawn value = JugemPath[0] of the course
 *     muunt (e.g. sg001: -599.65, 3007.0, 804.88).
 *   - Reference point = origin of the chassis MOVE MATRIX
 *     (kart+0x20, channel p_move_mtx) — not a wheel, not the camera.
 *   - The "rot" record is a HALF rotation vector: rot channel Calc
 *     FUN_71007adeac converts row-major 3x4 matrices (36 B, stride
 *     desc[+0]) via recorderMatrixToQuat_71001963a0, then
 *     recorderQuatToHalfRotVec_71003b2a64 -> out = (phi/sin(phi)) *
 *     (q0,q1,q2) = phi*axis (rotation angle = 2*phi), 3 f32 (12 B),
 *     zeroed when sin(phi) <= *(f32*)[0x1307c00]. Playback R rows =
 *     Rodrigues(2phi). Records land at *(char**)desc[+0x18] + 0x20,
 *     stride 0xc, then go to the frame writer; quantize 3x s16 over
 *     [-10240, +10240] with step = *(f32*)(chan + 0x1f8)
 *     (9.7659e-05). desc: +0x00 u32 src stride, +0x04 u32 count,
 *     +0x18 ptr to holder-array base. Channel source (binder +0x288)
 *     = kart holder object (KartVehicleMove kart block slot +0x20).
 *     Vtable 0x71012c4358 slot +0xd8 = 0x7adeac; +0xb8 pack 0x7b46a4
 *     (3x s16), +0xc8 read 0x7b4714, +0xe0 exp-map 0x7adf64, +0xe8
 *     interp 0x7ae664.
 *
 * TRANSCODER PIPELINE (per channel, per block):
 *   record prep -> [optional re-quant Calc] -> RDP mask -> frame
 *   writer FUN_71007a9d48 -> token ring (see Recorder.hpp).
 *
 *   FUN_71007ae350 (vt 0x71012c4108 +0x98) — trans record prep: copies
 *     [chan+0x280] slot table entries +0x0c/+0x1c/+0x2c (filled by
 *     latch 0x7ae824 from the holder record at byte [chan+0x1d4])
 *     verbatim into records + [chan+0x1d4]. Consumed by Calc
 *     FUN_71007b42ec (3 u32 verbatim), packed with RDP 0.2f, scale
 *     1/16.
 *
 *   FUN_71007b0178 (FB20 vt +0xd8, unit 0x7b0178..0x7b0640, write-path
 *     only, NOT used by playback) — twin of FUN_71007b0a70 for the
 *     token-table channel: slot stride 0x28, period scale at slot+0x4c
 *     (double deref), cyclic flag slot+0x48 bit 2, TWO floats per
 *     keyframe (+0x8/+0xc), TWO FrameWrite sub-writers per key
 *     (ctx+0x290 / ctx+0x294). Wrap-by-+/-period (half = period*0.5)
 *     re-quantization before FrameWrite; tail 0x7a9d48([info+8], node,
 *     kfs, stride).
 *
 *   FUN_71007b0a70 (FB28 vt +0xd8, unit 0x7b0a70..0x7b0e94, write-path
 *     only) — re-quantizes a block of keyframes before FrameWrite:
 *     period = 0x6a749c(ch, kf->0), cyclic = 0x6a7544(...) & 1
 *     (+1 when cyclic), d = kfval - prev wrapped to +/- period*0.5;
 *     bit-clear slots get scratch = 0, kf = -1; key mismatch ->
 *     scratch = next kf word. Ends with FUN_71007ace40 (bitmap) and
 *     FUN_71007a9d48.
 *
 *   FUN_71007b0e94 (unit 0x7b0e94..0x7b100c) — cyclic angle eval used
 *     by the FB28 playback tail 0x7b3174: lerp a[4]+(b[8]-a[4])*frac
 *     when the mask bit (1<<s16[kf]) is set in [node+0x28c] and keys
 *     match, else kf[+4] verbatim; then wrap by period from
 *     0x6a749c/0x6a7544. Interior 0x7b0fb4 = plain lerp variant
 *     (out[4]=out[8]=lerp, fallback a[4]).
 *
 *   FUN_71007b4404 — Ramer-Douglas-Peucker on 3-float points (vec3 /
 *     trans RDP): argmax of squared error vs the subdivision
 *     A+(B-A)*(j/n) over the open interval (i, count); marks the best
 *     point in the u32 mask (decrementing *budget when the bit was
 *     clear) while budget > 0, recursing (i, best) and tailing
 *     (best, count). Args: x0 mask u32*, x1 points (stride 12 B),
 *     w2 i, w3 count, s0 threshold, x4 budget s32*.
 *     Vec2 sibling: FUN_71007b37d8 (stride 2 floats, same
 *     argmax/mask/budget contract; called through wrapper
 *     FUN_71007b3734, which resets the bitmap chain, computes pending
 *     = base([node+0x1fc] ? [writer+0xb0] 0x40) - [slot+0x10], and
 *     passes tol = *(f32*)(node+0x1f0); ends 0x7a9d48 stride 8).
 *
 *   FUN_71007b42ec (unit 0x7b42ec..0x7b4404; head branches to the
 *     non-inline wrapper half 0x7b4360) — trans/vec3 frame emit:
 *     gathers the accumulated 12 B points (stride [container+0x4]?
 *     see TU: stride [container], count [container+4], both reloaded
 *     per iteration) plus the last point (x2) into the scratch at
 *     [container+0x18]->+0x20; budget = ([chan+0x1fc] ? [writer+0xb0]
 *      0x40) - [frameSlot+0x10]; RDP FUN_71007b4404(mask=*frameSlot,
 *     threshold = *(f32*)(chan+0x1f0)); frame writer FUN_71007a9d48
 *     stride 0xc. container: +0x00 stride, +0x04 count, +0x08 writer,
 *     +0x10 flag byte, +0x18 frame slot.
 *
 *   FUN_71007b5370 — trans record-side frame wrapper (semantic port):
 *     count = [chan+0x1fc] ? *(u32*)(*(char**)desc[+0x8] + 0xb0) :
 *     0x40; span = count - *(u32*)(W+0x10) as the RDP budget;
 *     recorderTransRdp3D_71007b4c04(mask = *(void**)W, keyframes, 0,
 *     desc[+0x4] - (desc[+0x10] ? 1 : 0), &span, *(f32*)(chan+0x1f0));
 *     then FUN_71007a9d48(writer = desc[+0x8], chan, W, keyframes, 12).
 *
 *   FUN_71007b4ad8 (vt 0x71012c3fe0 slot +0xc8) — trans point
 *     DEQUANTIZER (read side, byte-exact port): st = *(cfg+0x30);
 *     out[i] = *(f32*)(st + 4*i) + (float)((s16*)in)[i] /
 *     (float)(1 << *(s32*)(st+0xc)); returns [ch+0x1c4].
 *
 * FRAME WRITER FUN_71007a9d48 (unit 532 B, semantic port; ring facts
 *   shared with FUN_71007a9cc0 are in Recorder.hpp):
 *   frame = [mask u64, bit0 = init][nested init payload if bit0][
 *   payload per set point]. The 8 B record (*recordSlot) is
 *   ring-written first; bit0 init payload comes from channel vtable
 *   +0xa0 (e.g. trans thunk 0x7b394c -> 0x7acd68 -> reader 0x7aa86c)
 *   staged through [writer+0x130]; each set bit 1..63 payload comes
 *   from vtable +0xa8 with a cursor starting at payload+stride,
 *   advanced by `stride` per point (callers pass 8 or 12). Writer
 *   cursor +0xc8 advances by every returned size.
 *
 * LABEL SANITIZER / KEY GENERATOR FUN_71007a9704 (0x7a9704..0x7a9914,
 *   528 B): takes the channel name from binder+0x208 (fallback
 *   vt[0xf0]), scans for the separator byte *(u8*)0x12fada8 with a
 *   3-byte sliding window (stride 3, i in [2, 0x80000)), truncates at
 *   the first separator (cap 0x40) into the inline string
 *   (0x12fada0+0x10, ctor FUN_710061cc48), appends the separator at
 *   [len] (via SDK import 0x79588 + rodata 0xed9028), producing the
 *   registration name whose CRC32 becomes the channel key (key rule
 *   in Recorder.hpp). Called from FUN_71007a98e0 with w1 in {0,1,2}.
 *
 * GHOST FRAME RECORD BUILD ghostFrameRecordBuild_7100a7b414 (mode =
 *   *(char*)(track+8) & 0x7000; ghost desc selects mode != 0; the
 *   mode-0 Euler-sum path at 0x7a7b71c is NOT the ghost path):
 *   builds the per-frame 0x60-byte records consumed by apply()
 *   FUN_71006ada8c:
 *     out+0x00 u32 flags    = in[+0x24] & 0x0f870000
 *     out+0x10 12B snapshot = {in[+0x28].f0, in[+0x28].f1,
 *                              in[+0x30].u32, 0} (verbatim)
 *     out+0x20 4x4 f32 matrix from packed-angle groups in+0x34
 *               {f,f,u32} / in+0x44 {f,f,u32}: polynomial sincos
 *               (nn::util::detail-style coefficients), angles wrapped
 *               to [-pi/2, pi/2] (cos sign flip only), composed as
 *               STANDARD Euler XYZ R = Rz(c)*Ry(b)*Rx(a) with
 *               {a,b,c} = lanes 0/1/2 (lane 2 = u32 reinterpreted as
 *               transmitted f32):
 *                 q11 -> out+0x20, q20 -> out+0x30, q0 -> out+0x40
 *                 (q10 = group B verbatim -> out+0x50)
 *               Orthogonality err 5e-8, det = 1 (interpreter-verified).
 *
 * YAZ0 FUN_7100a886a4 (0xa886a4..0xa88800, 348 B): standard Yaz0
 *   decompress — magic bswap32 ('Yaz0') else -1; size bswap32 at
 *   src+4 (assembled bfi 24/16/8) else -2 when > maxSize; group byte
 *   at src+0x10+, mask 0x80; bit1 = literal, bit0 = RLE (2 B: len
 *   nibble, nibble 0 -> u8 extension + 0x12, else len+2; dist =
 *   ((b0&0xf)<<8)|b1, copy from dst - dist - 1). Success path leaves
 *   w0 unwritten in the original (return undefined by construction);
 *   bswap is an indirect import call (table 0x1307500).
 *
 * RECORD-LAYOUT BUILDER UNIT FUN_7100045f78 (0x45f78..0x4647c; the
 *   builder at 0x4607c is reached only by the ctor's TAIL BRANCH —
 *   bl-vs-b is the prologue root — no separate symbol):
 *   ctor 0x45f7c: +0x00=1, +0x01=1, +0x02=0, +0x04=-1 (u64),
 *   memset(+0xc, 0, 0x90), zero +0xa0..+0xaf, init sub-object +0xb0
 *   (FUN_710062ee28), memset(+0xc0/+0x11c/+0x178, 0xff, 92 each),
 *   +0x1d4=0 (u64), +0x1dc=0, init sub-object +0x1e0 (FUN_710062ee28),
 *   +0x250..+0x370 = 22 x u32 -1 (stride 0xc); falls into the builder.
 *
 *   builder 0x4607c fills (type = *(u32*)(entry+0x8), sub =
 *   *(u32*)(entry+0x18); entry from helper 0x710087fcd0):
 *     layout+0x00 u8  0x100 >> ((sub-1)*8), or 1 when sub-1 >= 4
 *     layout+0x01 u8  (sub==9 && 2 <= *(u32*)(entry+0x180) < 5)
 *     layout+0x04 u32 bytes/tick sub-stream A
 *     layout+0x08 u32 bytes/tick sub-stream B
 *     layout+0xa0 vptr cell +0x10 (GOT cells 0x12fbb90/98/a0/b0/b8 by
 *                 type/count branch; type 1 uses rodata tables
 *                 0xf21370/0xf21390 indexed by sub-1)
 *     layout+0x1d4 i32 record-array offset / slot count of the +0xc0
 *                  list; +0x1d8 count of +0x11c; +0x1dc count of +0x178
 *   slot lists: sub-9 (0x46244) walks bits 0..23 of the mask pair at
 *   [entry+0x18] ([lo]=[x0], [hi]=[x0+4]): +0x27 != 0 -> lo bit ->
 *   +0x11c[n1++], hi bit -> +0x178[n2++]; +0x27 == 0 -> single list
 *   +0xc0 (counter +0x1d4). Counters wrap 23->0; empty list falls back
 *   to slot 15, count 1. type 3 (0x46300): fixed mask 0x08a40100 over
 *   bits 0..20 -> +0xc0. other (0x4636c): identity 0..20,22 (21
 *   skipped) -> +0xc0, count 22. tail 0x46410: type<=1 && sub in
 *   {0,7,8} -> +0x02=1 and +0x1f0..+0x24f filled with f32 -98.0 pairs.
 *   OPEN (do not guess): [entry+0x18] is READ as u32 "sub" 1..9 here,
 *   yet helper 0x87fd00 returns the same field as a 64-bit POINTER to
 *   the {lo,hi} mask pair — whoever populates entry+0x18 resolves
 *   this .
 */

namespace recorder {

/*
 * Mirror of the record-layout object built by FUN_7100045f78 (0x460
 * bytes; offsets proven by the ctor/builder stores above).
 */
struct GhostRecordLayout {
  uint8_t widthShift_00;   //0x00 — u8 0x100 >> ((sub-1)*8); 1 when sub-1 >= 4
  uint8_t flag_01;         //0x01 — sub==9 && 2 <= [entry+0x180] < 5
  uint8_t tailFlag_02;     //0x02 — set by the tail (type<=1, sub 0/7/8)
  uint8_t pad_03[0x1];     //0x03 — to the first u32 pair
  uint32_t bytesTickA_04;  //0x04 — bytes/tick sub-stream A
  uint32_t bytesTickB_08;  //0x08 — bytes/tick sub-stream B
  uint8_t pad_0c[0x94];    //0x0C — to the vptr slot at +0xA0
  uint8_t vptr_00a0[0x8];  //0xA0 — record-class vptr cell (GOT 0x12fbb90..b8)
  uint8_t pad_a8[0x8];     //0xA8 — to the +0xB0 sub-object
  uint8_t pad_b0[0x10];    //0xB0 — sub-object (init FUN_710062ee28; 0x10 B
                           //      up to the first slot list at +0xC0)
  uint8_t slotListA_c0[92];//0xC0 — slot list A (ctor = 0xff fill)
  uint8_t pad_11c[92];     //0x11C — slot list B (ctor = 0xff fill)
  uint8_t pad_178[92];     //0x178 — slot list C (ctor = 0xff fill)
  int32_t recOffset_1d4;   //0x1D4 — record-array offset / count of list +0xC0
  uint32_t count11c_1d8;   //0x1D8 — count of slots in list +0x11C
  uint32_t count178_1dc;   //0x1DC — count of slots in list +0x178
  uint8_t subObj_1e0[0x10]; //0x1E0 — sub-object (init FUN_710062ee28)
  uint8_t tail_1f0[0x60];  //0x1F0 — tail: f32 -98.0 pairs (type<=1, sub 0/7/8)
  uint8_t idList_250[22][12]; //0x250 — 22 x u32 -1, stride 0xc to +0x358
  uint8_t pad_358[0x18];   //0x358 — to the ctor-written end 0x370
};

/*
 * Mirror of the trans-channel write descriptor passed as x2 to
 * FUN_71007b5370 (and the same shape as the Calc `info` arg).
 */
struct TransWriteDesc {
  uint8_t pad_00[0x4];     //0x00 — head pad to the index word
  uint32_t lastIndex_04;   //0x04 — last sample index (minus 1 if flag_10)
  void* writer_08;         //0x08 — frame writer object (max kf count [w+0xb0])
  uint8_t flag_10;         //0x10 — nonzero: lastIndex is decremented
  uint8_t pad_11[0x7];     //0x11 — to the workspace pointer at +0x18
  void* workspace_18;      //0x18 — workspace W: *W = *(W+8) before the call;
                           //        RDP mask = *W; +0x10 = consumed kf count
};

/*
 * Frame-record layout produced by ghostFrameRecordBuild_7100a7b414
 * (mode != 0), consumed by apply() FUN_71006ada8c.
 */
struct GhostFrameRecord {
  uint32_t flags_00;       //0x00 — in[+0x24] & 0x0f870000
  uint8_t pad_04[0xc];     //0x04 — to the 12 B snapshot at +0x10
  float snapshot_10[2];    //0x10 — {in[+0x28].f0, in[+0x28].f1} verbatim
  uint32_t snapshot_18;    //0x18 — in[+0x30].u32 verbatim
  uint32_t pad_1c;         //0x1C — pad to the matrix at +0x20
  float m_20[16];          //0x20 — Euler XYZ matrix (q11/q20/q0 rows);
                           //      out+0x50 = input group B verbatim
};

}  // namespace recorder
