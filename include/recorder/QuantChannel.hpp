#pragma once

#include <cstdint>

/*
 * Quantized recorder channel — objects created by the channel factory
 * FUN_71001ca6e8(min[s0], max[s1], step[s2], flags[w1]) used by the
 * recorder channel setup (0x71003ad660..0x3af740, 50 sites) before each
 * recorderAddChannel_71007ac0cc(this, obj, name).
 *
 * Factory selection rule (all proven from the factory body):
 *   levels      = span / step, span = max(|min|, |max|) (x2 when the range
 *                 crosses zero and flags bit0 set — wrap mode)
 *   qbits       = int(log2(levels)) + 1 (+1 when wrap)
 *   qbits >= 17 -> alloc 0x290, raw memmove class (vptr [0x12fe718]+0x10),
 *                  +0x1c0 = 8, +0x1c4 = 0 (width set per payload)
 *   no quant    -> alloc 0x280, raw vec2-s16 class ([0x12fd000+0xb70]+0x10),
 *                  +0x1c0 = 4, +0x1c4 = 4
 *   9..16 bits  -> alloc 0x298, vec2 class ([0x12fe000+0x718/0x720/0x728]
 *                  +0x10), +0x1c0 = 8, +0x1c4 = 4 (wrap+interp) / 2
 *   < 9 bits    -> alloc 0x288, scalar class ([0x12fe000+0x730/0x738/0x740]
 *                  or [0x12fb000+0x500] +0x10), +0x1c0 = 4,
 *                  +0x1c4 = 2 (wrap/min-max) or 1 (u8)
 *
 * Field offsets below are proven by factory stores (object size is the
 * allocation size passed to operator new, 0x280/0x288/0x290/0x298 by
 * class). 0x71007aae24 initializes the shared head of every variant.
 *
 * Read-side quant object layout (setup FUN_71007b100c /
 * factory FUN_71007b9400): +0x1c0 = numValues (e.g. 12 for
 * p_move_mtx, 4 for scalar channels), +0x1c4 = token format in bytes
 * (1/4/6), +0x1f0/+0x1f4/+0x1f8 = min / step / 1/step, +0x278 = back
 * reference to the owning mgr, +0x288 = channel index,
 * +0x220/+0x228 = delta once-changed state (two u64s). Decoded value
 * = min + token*step (mod span); the per-block record reloads step
 * when its key matches the frame time key (FUN_71007aa490): that
 * record is the 12 B file entry { u32 key; u32 packed; float step }
 * of the channel directory (see recorder/Recorder.hpp) — the float
 * step at entry+0x8 is what lands in +0x1f4 (+0x1f8 = 1/step),
 * overwriting the setup-time values below for that block.
 *
 * Per-point quantizers (each returns [ch+0x1c4] = substream width):
 *   FUN_71007b424c — 2-comp byte quantizer: v = in[j]*[+0x1f4], clamp
 *     [+0x280,+0x284] (NaN falls through to the min/max branches), 1 B/comp.
 *   FUN_71007b45a4 — 3 comps packed into ONE u32 token: comp0 bits 0-9,
 *     comp1 bits 11-20, comp2 bits 21-30 (fcvtzs(in[j]*[+0x1f4]); clamps
 *     to the field half-ranges; bits 10/31 stay zero).
 */
namespace recorder {

struct QuantChannelCommon {
  uint8_t pad_00[0x1c0];
  uint32_t type_1c0;       //0x1C0 — numValues (12 = p_move_mtx 3x vec4,
                           //      4 = scalar channels; factory: 4/8/12)
  uint32_t width_1c4;      //0x1C4 — token bytes consumed per fresh tick
                           //      (readers: 0x1cb584 u16, 0x1cb0cc vec2 s16,
                           //       0xa1404 raw memmove, 0x26a00 u8);
                           //      formats seen: 1 (u8), 4 (u32), 6
  uint8_t pad_1c8[0x28];   //0x1C8
  float step_1f0;          //0x1F0 — step (s2 argument)
  float inv_step_1f4;      //0x1F4 — quantization multiplier (1/step-derived)
  float step2_1f8;         //0x1F8 — secondary step (1/inv when step != 0)
  uint8_t pad_1fc[0x24];   //0x1FC
  uint64_t deltaOnce_220;  //0x220 — delta once-changed state (u64 pair
  uint64_t deltaOnce_228;  //0x228   with the slot below)
  uint8_t pad_230[0x48];   //0x230
  void* owner_278;         //0x278 — x19 argument (owning hub object /
                           //      backref to the mgr on read-side objects)
};

struct RawVec2Channel {    // 0x280-byte variant (no-quant fallback)
  QuantChannelCommon head;
  uint8_t tail_280[0x00];  // no extra fields proven
};

struct ScalarQuantChannel { // 0x288-byte variant
  QuantChannelCommon head;
  float span_280;          //0x280 — (max - min), as u64 pair with 0x284
  float half_span_284;     //0x284 — span * 0.5f
  float min_288;           //0x288 — s0 argument
  uint8_t tail_28c[0x4];
};

struct Vec2QuantChannel {  // 0x298-byte variant
  QuantChannelCommon head;
  float span_280;          //0x280
  float half_span_284;     //0x284
  float min_288;           //0x288
  uint8_t packed_28c[8];   //0x28C — wrap-limit float pair (0xc3000000fe00... /
                           //      0xc7000000fe00... bit-packed constants)
};

struct RawMemmoveChannel { // 0x290-byte variant (qbits >= 17)
  QuantChannelCommon head;
  uint8_t tail_290[0x10];
};

}  // namespace recorder
