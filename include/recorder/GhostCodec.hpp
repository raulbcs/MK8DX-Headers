#pragma once

#include <cstdint>

/*
 * Ghost stream trans/rot codec + record-layout builder. All addresses
 * are original VMAs verified against the disassembly.
 *
 * WORLD-SPACE SEMANTICS (proven):
 *   - dat "trans" channel d IS the kart world translation, raw (prep
 *     FUN_71007ae350 copies the latched u32 slots verbatim; RDP 0.2f /
 *     scale 1/16 happen only at pack time). Spawn = JugemPath[0].
 *   - Reference point = origin of the chassis MOVE MATRIX (kart+0x20,
 *     channel p_move_mtx).
 *   - "rot" record = HALF rotation vector: 3x4 row-major (36 B) ->
 *     recorderMatrixToQuat_71001963a0 -> recorderQuatToHalfRotVec_
 *     71003b2a64, out = (phi/sin(phi))*(q0,q1,q2); rotation angle =
 *     2*phi; playback R = Rodrigues(2phi).
 *
 * PLAYBACK ROT INTERP (vt+0xe8 slot; FUN_71007ae66c, extent 0x224):
 *   two 3x3 col-major stride-4 records (written by the exp-map
 *   FUN_71007adf64) -> quat via Shepperd interior 0x1963a0 -> slerp
 *   interior 0x2977b4 (frac = s0) -> quat -> 3x3 col-major 9 floats
 *   out. Facts:
 *   - Shepperd 0x1963a0: csinc `le` picks 2/1 (not 2/3); record diag
 *     read at words 0/4/8 = col-major stride 4; the y-max branch
 *     @196500 builds qx from (R10-R01); qx uses the standard
 *     (R01+R10).
 *   - Slerp 0x2977b4: thresholds +/-0.70710678 (rodata 0xed5cdc/d8);
 *     hemisphere fix via final sign (0x2979bc); |sin| < FLT_EPSILON
 *     (0xed58e0) -> nlerp (0x297950).
 *   - Angle via asin fixpoint helper 0x61b690: scale 128.0 (rodata
 *     0xed5a7c), LUT frac 2^-24. sincos LUT = rodata 0xf55d54 (256x4
 *     f32), reached through bss pointer cell 0x12fb160; asin LUT = bss
 *     cell 0x130d360, filled at runtime init (zero in the binary).
 *     rodata file offset = vaddr - 0x128.
 *
 * NOTE: the mode-0 Euler-sum path at 0x7a7b71c (inside
 * ghostFrameRecordBuild_7100a7b414) is NOT the ghost path.
 *
 * Codec family index (details at the listed addresses):
 *   FUN_71007ae350  trans record prep (vt 0x71012c4108 +0x98)
 *   FUN_71007b0178  token-table channel re-quant, write-path only
 *                   (FB20 vt +0xd8; slot stride 0x28, 2 floats/key)
 *   FUN_71007b0a70  keyframe re-quant before FrameWrite (FB28 vt +0xd8)
 *   FUN_71007b0e94  cyclic angle eval, FB28 playback tail (interior
 *                   0x7b0fb4 = plain lerp variant)
 *   FUN_71007b4404  RDP on vec3, stride 12 (sibling vec2 FUN_71007b37d8,
 *                   stride 8, via wrapper FUN_71007b3734)
 *   FUN_71007b42ec  trans/vec3 frame emit (writer FUN_71007a9d48,
 *                   stride 0xc; container: +0 stride, +4 count, +8
 *                   writer, +0x10 flag byte, +0x18 frame slot)
 *   FUN_71007b5370  trans record-side frame wrapper (desc = TransWriteDesc)
 *   FUN_71007b4ad8  trans point dequantizer (vt 0x71012c3fe0 +0xc8)
 *   FUN_71007a9d48  frame writer, 532 B ([mask u64][init if bit0][tokens])
 *   FUN_71007a9704  label sanitizer / key generator, 528 B (CRC32 rule
 *                   in Recorder.hpp); called from FUN_71007a98e0
 *   FUN_7100a7b414  ghostFrameRecordBuild (see GhostFrameRecord)
 *   FUN_7100a886a4  Yaz0 decompress, 348 B (magic/size bswap32; bit1 =
 *                   literal, bit0 = RLE; success leaves w0 unwritten)
 *   FUN_7100045f78  record-layout builder unit 0x45f78..0x4647c (builder
 *                   0x4607c reached only by the ctor tail branch; fills
 *                   GhostRecordLayout below)
 *   OPEN (do not guess): [entry+0x18] is READ as u32 "sub" 1..9 by the
 *   builder, yet helper 0x87fd00 returns the same field as a 64-bit
 *   POINTER to the {lo,hi} mask pair.
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

/*
 * GhostStreamSession — FUN_71008754c0 stream-session state machine
 * (offsets proven by its probes; reached via FUN_7100874cb0/74d68 from
 * loader tick FUN_71004a8978).
 */
struct GhostStreamSession {
  uint8_t pad00[0x38];
  void* region_38;      // 0x038 — region base
  uint32_t busy_40;     // 0x040 — busy flag
  uint32_t state_44;    // 0x044 — 0 open-pending / 1 discard / 2 close
  uint32_t size_48;     // 0x048 — size
  uint8_t forceClose_50;  // 0x050 — force-close
  uint8_t pad51[0x1af];
  void* stream_200;     // 0x200 — stream ptr
  uint8_t openFlag_208; // 0x208 — flag forwarded after open
  uint8_t pad209[0x27];
  int32_t cursor_230;   // 0x230 — cursor (init -1)
};

/*
 * Side unit index (read/playback path):
 *   FUN_71004a85a4  ghost file opener (612 B): path "Ghost/%s/%s"; mgr
 *                   singleton FUN_71008bd3c8, Fast base mgr+0x130C000,
 *                   Slow base mgr+0x653B0000; bucket adj 0/-27/-16;
 *                   0x24-byte metadata entry -> target+0x210..0x22C
 *   FUN_71006eccbc  default frame id: u16 w1 -> table[12*k+4] of the
 *                   record table at *(entryObj+0x68)
 *   FUN_71006abbf8  atomic frame-id gen: fetch-add at obj+0xCC, returns
 *                   prev & 0x7ff (wraps every 2048 frames)
 *   FUN_71003af93c  per-tick prep of the ghost playback ctx (kart pos /
 *                   frontal dir into ctx+0x308..0x330; snap at *(ctx+0x288)
 *                   is 12 words COLUMN-major)
 *   FUN_710069ee98  dat chunk-set load: stream+0x100 = target; per-frame
 *                   record array at hdr+0x18, stride 0x60 (apply
 *                   FUN_71006ada8c)
 */

}  // namespace recorder
