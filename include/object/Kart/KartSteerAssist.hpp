#pragma once

#include <cstdint>

namespace object {
class KartVehicleMove;  // object/Kart/KartVehicleMove.hpp
// Size 0x120: operator new(0x120) in the KartVehicle ctor (v400
// 0x710017025c), allocated only when KartVehicle+0xD0 mIsMaster != 0 (else
// nullptr at KartVehicle+0xA0). Ctor 0x71001502a8; evidenced: +0xC0 stores
// the KartVehicle*, +0xC8 the KartVehicleMove*. Assist level (u32) at +0x28
// (ctor arg *x3, overridden by global u32 [0x12fd548] when nonzero); auto
// level s32 at +0x2c; active flag at +0x3c; steering target f32 at +0x50;
// decay timer f32 at +0xf4.
class KartSteerAssist {
 public:
  // Proven sub-offset map from ctor 0x71001502a8 (everything listed is
  // ctor-store evidence; unlisted bytes are unproven gaps, not semantics):
  //   0x000 vptr (vtable 0x12fd548)
  //   0x008 ptr  = new(0x70) inited via 0x7c55cc
  //   0x010 ptr  = new(0xE4) + memset 0
  //   0x018 ptr  = new(0xE4) + memset 0
  //   0x020 ptr  = new(0x24), fully zeroed
  //   0x028 u32  = ctor arg x3 load
  //   0x02c s32  = -1
  //   0x030 u64  = 0
  //   0x038 s32  = -1
  //   0x03c u64  = 0
  //   0x044 u8   = 0
  //   0x048 s32  = -1
  //   0x04c/0x050 u32 = 0
  //   0x054 u8   = 1
  //   0x058 u64  = 0
  //   0x060..0x06f = 0 (two x stores)
  //   0x070 u32  = 0
  //   0x074/0x078/0x07c u32 = u32 global at [0x12fd540]
  //   0x080 u64  = self-pointer (&this + 0x80)
  //   0x088 u32  = 8
  //   0x08c u64  = 0
  //   0x094/0x09c/0x0a4/0x0ac u64 = -1 (sentinel block)
  //   0x0b8 u64  = 0
  //   0x0c0 KartVehicle* (ctor arg x1)
  //   0x0c8 KartVehicleMove* (ctor arg x2)
  //   0x0d0 u64  = ptr loaded from [0x12fb148]
  //   0x0d8 u32  = [that ptr + 8]
  //   0x0e8/0x0ec u32 = 0
  //   0x0f0 f32  = -1.0f
  //   0x0f4..0x0fb u64 = 0
  //   0x104 u16 = 0, 0x108 u32 = 0, 0x10c u16 = 0, 0x10e u8 = 0,
  //   0x110 u32 = 0, 0x114 u8 = 0, 0x118 u32 = 0
  // Extent 0x120 from the factory alloc at 0x710017025c; the ctor tail-calls
  // the re-init 0x710015042c in-line (0x1503ac), so its stores are ctor
  // evidence too.
  void* mVTable;                      //0x00 — ctor stores *0x12fd538 + 0x10
                                      // (0x1502b8..0x1502d0)
  void* mSub70;                       //0x08 — new(0x70) inited via 0x7c55cc
                                      // (0x150404..0x150418)
  void* mSubE4a;                      //0x10 — new(0xE4) + memset 0 (0x1503b0..0x1503d0)
  void* mSubE4b;                      //0x18 — new(0xE4) + memset 0 (0x1503d4..0x1503ec)
  void* mSub24;                       //0x20 — new(0x24), fully zeroed (0x1503e8..0x150400)
  uint32_t mAssistLevel28;            //0x28 — ctor arg x3 (0x1502d8)
  int32_t mAutoLevel2c;               //0x2C — ctor -1 (0x1502d8), overwritten by the
                                      // re-init with 0x710015090c() (0x150508..0x150510)
  uint64_t mU30;                      //0x30 — ctor 0 (0x1502e0); re-init sets 1
                                      // (0x150518..0x15051c)
  int32_t mI38;                       //0x38 — ctor -1 (0x1502e4)
  uint8_t mBlock3c[8];                //0x3C - 0x43 — ctor-zeroed u64 (stur xzr,
                                      // 0x1502ec); +0x3C = active flag, +0x43 = parity
                                      // bit (setter 0x7100150a80)
  uint8_t mB44;                       //0x44 — ctor 0 (0x1502e8)
  uint8_t mPad45[3];                  //0x45 - 0x47 — no ctor store; no accessor evidence
  int32_t mI48;                       //0x48 — ctor -1 (0x1502f0; re-init re-stores -1,
                                      // 0x15043c..0x150440)
  uint32_t mU4c;                      //0x4C — ctor 0 (0x1502f0)
  uint32_t mU50;                      //0x50 — ctor 0 (0x1502f4); steering target f32
                                      // written by the per-frame calc 0x7100150a8c
  uint8_t mB54;                       //0x54 — ctor 1 (0x15030c)
  uint8_t mPad55[3];                  //0x55 - 0x57 — no ctor store; no accessor evidence
  uint64_t mX58;                      //0x58 — ctor 0 (0x150308)
  uint8_t mZero60[0x10];              //0x60 - 0x6F — ctor 0 (0x1502fc)
  uint32_t mU70;                      //0x70 — ctor 0 (0x1502f8)
  uint32_t mGlobals74[3];             //0x74/0x78/0x7C — u32 global at [0x12fd540]
                                      // (0x150310..0x150320)
  uint64_t mCursor80;                 //0x80 — ctor stores this+0x94 (walk cursor,
                                      // 0x150338)
  uint32_t mCap88;                    //0x88 — ctor 8 (0x150334/0x150340)
  uint64_t mZero8c;                   //0x8C — ctor 0 (0x15033c)
  uint64_t mSentinel94[4];            //0x94..0xB3 — ctor -1 block (0x150324..0x150330)
  uint8_t mPadB4[4];                  //0xB4 - 0xB7 — no ctor store; no accessor evidence
  uint64_t mZeroB8;                   //0xB8 — ctor 0 (0x150344); lazy cache filled by
                                      // 0x7100150a90: *(*(RS+0x190+idx*8)+0x238)+0xB8
                                      // (0x150b08..0x150b14)
  KartVehicle* mOwnerKartVehicle;     //0xC0 — ctor arg x1 (0x150348)
  KartVehicleMove* mKartVehicleMove;  //0xC8 — ctor arg x2 (0x150350)
  void* mD0;                          //0xD0 — ptr from [0x12fb148] (0x150364/0x1504ac)
  uint32_t mD8;                       //0xD8 — [that ptr + 8] (0x15035c/0x1504b0)
  uint8_t mPadDc[0xc];                //0xDC - 0xE7 — no ctor store; no accessor evidence
  uint32_t mE8;                       //0xE8 — ctor 0 (0x15036c)
  uint32_t mEc;                       //0xEC — ctor 0 (0x15036c)
  float mFf0;                         //0xF0 — ctor -1.0f (0x150370)
  uint64_t mZeroF4;                   //0xF4 - 0xFB — ctor 0 (0x150374)
  uint32_t mFc;                       //0xFC — re-init stores 0xFFFFFFFF (0x15043c/
                                      // 0x150470)
  uint32_t mX100;                     //0x100 — re-init 0 (upper half of the same u64)
  uint16_t mX104;                     //0x104 — ctor 0 (0x150378)
  uint8_t mPad106[2];                 //0x106 - 0x107 — no ctor store; no accessor evidence
  uint32_t mX108;                     //0x108 — ctor 0 (0x150398)
  uint16_t mX10c;                     //0x10C — ctor 0 (0x150394)
  uint8_t mX10e;                      //0x10E — ctor 0 (0x150388)
  uint8_t mPad10f;                    //0x10F — no ctor store; no accessor evidence
  uint32_t mX110;                     //0x110 — ctor 0 (0x15037c)
  uint8_t mX114;                      //0x114 — ctor 0 (0x150380); re-init sets the
                                      // courseId flag (<= 0x2D bitmask / [0x4C,0x7B))
  uint8_t mPad115;                    //0x115 — no ctor store; no accessor evidence
  uint8_t mX116;                      //0x116 — re-init sets (courseId == 0x79)
  uint8_t mPad117;                    //0x117 — no ctor store; no accessor evidence
  uint32_t mX118;                     //0x118 — ctor 0 (0x15045c)
  uint8_t mPad11c[4];                 //0x11C - 0x11F — no ctor store; no accessor evidence

  // Runtime facts:
  // - Setter 0x7100150a40(assist, bool): bool==0 -> +0x28=0 (off); bool!=0
  //   and +0x28==0 -> re-init via 0x710015042c and +0x28 = +0x2c (auto
  //   level). Sole caller 0x71001726b0 gates on kartList[idx]+0x20C
  //   (via KartVehicle+0xA8 -> 0x710087edf8) and mirrors it into
  //   KartVehicle+0x1CC bit 0x2000. One-bit setter 0x7100150a80 sets
  //   +0x43 = arg&1 (constant 1 from wrappers 0x1925fc..0x192644).
  // - Auto level 0x710015090c (stored +0x2c by 0x710015042c): 3 if
  //   courseInfoSingleton+0x8 == 3; else 1 + (0x710087eb54() != 0);
  //   fallback 2 if courseId <= 0x37 has a bit in 0x1220_0810_0D02_0000,
  //   else 1. 0x710015042c also sets +0x114 (courseId <= 0x2D with bit in
  //   0x4040_0240_1000_0000, or courseId in [0x4C,0x7B)) and
  //   +0x116 = (courseId == 0x79).
  // - Per-frame calc 0x7100150a8c (KartVehicle drive calc, dis 1835e4,
  //   x1 = stack {u32, u32 speed=[kart+0x37C], f32, u8=0}, result written
  //   back to x1+0xC): kart+0x1CF bit0 -> hard reset (+0x3C, +0xD8/+0xD0
  //   = 0). +0x50 = Body+0x130-derived + (-8.12f) (course 0x6E or
  //   negative -> 0). +0xF4 += -0.025f clamped >= 0; +0xF0 = -1.0f/frame.
  //   CPUs run the same entry (mIsCpu branch copies the 0x18-byte input).
  //   Activation (dis 1518c4..151900): +0x3C = 1 only if +0x28 != 0 AND
  //   (target - [+0x50]) > 15.0f AND 0x7100186e24(KartVehicleMove) bit0
  //   == 0. Dispatch: level 1 -> 0x7100158c8c (+ 0x7100159394 +
  //   0x71001596ec); level 2 -> 0x7100158c8c + 0x71001596ec.
};
}  // namespace object
