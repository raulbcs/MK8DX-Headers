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
 */
namespace recorder {

struct QuantChannelCommon {
  uint8_t pad_00[0x1c0];
  uint32_t type_1c0;       //0x1C0 — 4 = scalar-ish, 8 = vec2/raw
  uint32_t width_1c4;      //0x1C4 — token bytes consumed per fresh tick
                           //      (readers: 0x1cb584 u16, 0x1cb0cc vec2 s16,
                           //       0xa1404 raw memmove, 0x26a00 u8)
  uint8_t pad_1c8[0x28];   //0x1C8
  float step_1f0;          //0x1F0 — step (s2 argument)
  float inv_step_1f4;      //0x1F4 — quantization multiplier (1/step-derived)
  float step2_1f8;         //0x1F8 — secondary step (1/inv when step != 0)
  uint8_t pad_1fc[0x7c];   //0x1FC
  void* owner_278;         //0x278 — x19 argument (owning hub object)
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
