#pragma once

#include <cstdint>

// Quantized recorder channel — factory FUN_71001ca6e8(min, max, step,
// flags), used by channel setup 0x71003ad660..0x3af740 (50 sites) before
// recorderAddChannel_71007ac0cc(this, obj, name). Variants below.

namespace recorder {

// Shared head of every variant (init 0x71007aae24); offsets proven by
// factory stores. Variant-dependent tail regions are modeled per variant.
// extent 0x280 (head end = owner field end; read-side objects carry an
// unproven 0x280..0x298 tail, see doc/recorder/QuantChannel.md)
struct QuantChannelCommon {
  uint8_t pad_00[0x1c0];   // unproven
  uint32_t type_1c0;       //0x1C0 — numValues (12 = p_move_mtx, 4 = scalar;
                           //      factory: 4/8/12)
  uint32_t width_1c4;      //0x1C4 — token bytes per fresh tick (readers:
                           //      0x1cb584 u16, 0x1cb0cc vec2 s16, 0xa1404
                           //      raw memmove, 0x26a00 u8); formats 1/4/6
  uint8_t pad_1c8[0x28];   //0x1C8 // unproven
  float step_1f0;          //0x1F0 — step (s2 argument)
  float inv_step_1f4;      //0x1F4 — quantization multiplier (1/step-derived)
  float step2_1f8;         //0x1F8 — secondary step (1/inv when step != 0)
  uint8_t pad_1fc[0x24];   //0x1FC // unproven
  uint64_t deltaOnce_220;  //0x220 — delta once-changed state (u64 pair
  uint64_t deltaOnce_228;  //0x228   with the slot below)
  uint8_t pad_230[0x48];   //0x230 // unproven
  void* owner_278;         //0x278 — x19 argument (owning hub object /
                           //      backref to the mgr on read-side objects)
};

// extent 0x280 (factory alloc; no-quant fallback)
struct RawVec2Channel {     // 0x280-byte variant (no-quant fallback)
  QuantChannelCommon head;  // 0x000..0x280 (extent 0x280)
  uint8_t tail_280[0x00];   // no extra fields proven
};

// extent 0x28c (field end; prior-survey alloc claim 0x288 — unresolved
// conflict, see doc/recorder/QuantChannel.md)
struct ScalarQuantChannel {  // 0x288-byte variant
  QuantChannelCommon head;   // 0x000..0x280 (extent 0x280)
  float span_280;            //0x280 — (max - min), as u64 pair with 0x284
  float half_span_284;       //0x284 — span * 0.5f
  float min_288;             //0x288 — s0 argument
  uint8_t tail_28c[0x0];     // allocation ends 0x288
};

// extent 0x298 (factory alloc)
struct Vec2QuantChannel {   // 0x298-byte variant
  QuantChannelCommon head;  // 0x000..0x280 (extent 0x280)
  float span_280;           //0x280
  float half_span_284;      //0x284
  float min_288;            //0x288
  uint8_t packed_28c[8];    //0x28C — wrap-limit float pair (0xc3000000fe00... /
                            //      0xc7000000fe00... bit-packed constants)
  uint8_t pad_294[0x4];     //0x294 — unproven gap
};

// extent 0x290 (factory alloc; qbits >= 17)
struct RawMemmoveChannel {  // 0x290-byte variant (qbits >= 17)
  QuantChannelCommon head;  // 0x000..0x280 (extent 0x280)
  uint8_t tail_290[0x0];    // no extra fields proven
};

}  // namespace recorder
