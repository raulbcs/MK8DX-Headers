#pragma once

#include <cstdint>

#include "object/Kart/KartRigidBody.hpp"

// KartVehicleMove — size 0x5F8, proven by operator new(0x5F8) in the KartVehicle
// ctor 0x71001701e4, stored at KartVehicle+0x28). Derives from
// KartRigidBody (ctor 0x71001812b4 calls 0x710014ddb4 first). Name
// confirmed by the recorder channel string "RecorderKartVehicleMove".
//
// MISATTRIBUTED FIELDS: earlier revisions declared fields at +0x1680
// (flag bitfield) and +0x2288/+0x2298 (float pairs) — those lie beyond
// the proven 0x5F8 allocation and belong to another, unnamed class.
namespace object {
struct KartVehicle;
}  // namespace object

struct KartVehicleMove : public object::KartRigidBody {
  void* static_table_e0;              //0xE0 — ctor overwrites with (0x12fd668+0x40)
  uint8_t pad_e8[0x10];               //0xE8 - 0xF7 — unproven padding
  object::KartVehicle* kart_vehicle;  //0xF8 — ctor arg (0x1812d0); object whose +0x1cc
                                      // flags word gates the antigrav spin
  uint8_t pad_100[8];                 //0x100 — unproven padding
  uint8_t pad_108[0x20];              //0x108 - 0x127 — ctor zeroes
  float f128[2];                      //0x128 — ctor sets {1.0f, 1.0f}
  uint8_t pad_130[8];                 //0x130 — unproven padding
  float f138;                         //0x138 — ctor sets 1.0f
  uint8_t pad13c[4];                  //0x13C — unproven padding
  uint8_t zero_140[0xd0];             //0x140 - 0x20F — memset 0
  uint8_t flag210;                    //0x210 — ctor sets 1
  uint8_t pad_211[5];                 //0x211 - 0x215 — ctor zeroes
  uint8_t course_flag216;             //0x216 — 0 on course IDs 0x61/0x5E, else 1 (0x181520)
  uint8_t course_flag217;             //0x217 — 1 on course 0x6E (0x18156c)
  uint8_t course_flag218;             //0x218 — 1 on course 0x71 (0x181584)
  uint8_t pad_219;                          //0x219 — unproven padding
  uint16_t course_flag21a;            //0x21A — 0x101 on course 0x65 (0x181558);
                                      // byte +0x21B = 1 on course 0x71 (0x181584/0x18158c)
  uint8_t pad_21c[3];                       //0x21C — unproven padding
  uint8_t zero_220[0xc];              //0x220 - 0x22B — ctor zeroes
  uint8_t antigravSpinTimer22c;       //0x22C — body calc requests boost tier 0x200
                                      // (trigger type 2) when mbAntiGColSpin (+0x3EC)
                                      // is set and this < 1.0 (0x18b9f4)
  uint8_t pad_22d[7];                       //0x22D — unproven padding
  uint32_t surfaceKind234;            //0x234 — surface kind: bits 0..4 of the wheel-hit
                                      // hword+0x4 (0x18a200..0x18a220); read by the
                                      // 12-byte getter FUN_7100142588. gear::ESurfaceType
  uint32_t mOnDirtRate238;            //0x238 — mOnDirtRate: raw u32, bits 5..7 of the same
                                      // hword (3-bit surface sub-code 0..7, -1 = no hit;
                                      // producer 0x18a21c/0x18a25c/0x18a264). Bound by the
                                      // recorder mOnDirtRate channel as 1x4 quant. NOT read
                                      // as float by the off-road penalty (that uses +0x4B4)
  uint8_t zero_23c[0x60];             //0x23C - 0x29B — ctor zeroes
  uint8_t block_29c[0x30];            //0x29C — 0x30-byte memcpy from the shared default
                                      // block (GOT 0x12fd108 -> bss 0x7101328d28; same
                                      // source as KartChassis)
  uint8_t block_2cc[0x30];            //0x2CC — same source
  uint8_t zero_2fc[0x84];             //0x2FC - 0x37F — memset 0; 0x71000181f98 builds the
                                      // normalized drive dir at +0x2FC/+0x300/+0x304
  float glideThreshold380;            //0x380 — glide decision: compare vs Drift+0x64
                                      // (0x17bab4)
  float f388;                         //0x388 — ctor sets 1.0f
  uint8_t pad_38c[0x14];              //0x38C - 0x39F — unproven padding
  float f3a0;                         //0x3A0 — ctor sets 1.0f
  uint8_t pad_3a4[0x10];
  float f3b8;                         //0x3B8 — ctor sets 0.75f
  uint8_t zero_3bc[8];                //0x3BC - 0x3C3 — ctor zeroes
  float driftReset3c4;                //0x3C4 — drift state setter writes 0.0392f here
                                      // (0x17bda0..0x17bdac)
  uint8_t zero_3c8[0x24];             //0x3C8 - 0x3EB — ctor zeroes
  uint8_t mbAntiGColSpin3ec;          //0x3EC — antigrav wall-spin flag. Writers:
                                      // FUN_71001873d8 (0x187b20: (w23!=0) & [+0x3ED]!=0,
                                      // then spin event 0xb0c90 w1=0x1f) and
                                      // FUN_71001891e0 (0x1892b8: gated by flags word
                                      // [[+0xF8]+0x1CC] bits 14/21, value bit 12; negates
                                      // the contact normal when set). Reader
                                      // FUN_7100182f38 (0x183410) with constant 0xed5a6c.
                                      // Ctor init 0 (0x181440)
  uint8_t antigravSpinAllowed3ed;     //0x3ED — enable byte set in ctor (0x18144c);
                                      // semantics UNCERTAIN (likely "wall-spin allowed")
  uint8_t zero_3ee[2];
  uint8_t zero_3f0[0x2c];             //0x3F0 - 0x41B — memset 0
  float speedNorm420;                 //0x420 — normalization denominator of the surface
                                      // speed term: +0x420 = max(+0x420, 1.0); scale =
                                      // dot / +0x420 (0x182274..0x18229c)
  float f43c[24];                     //0x43C..0x4B3 — ctor sets all to 1.0f (twelve
                                      // {1.0, 1.0} pairs, 0x181458..0x1814d0); the
                                      // 0x4B4 member is overwritten by the sub-ctor
  float offroadMult4b4;               //0x4B4 — off-road speed multiplier, head of the
                                      // family +0x4B4..+0x510 (sub-ctor 0x1816f8..0x1818c4):
                                      // init 1.0; body-type switch [+0x10] (jt 0xf244b0):
                                      // 0->0.8, 1->0.9, 2->1.0, 3->1.5 (+0x58C=1,
                                      // 0x594=1.24742f, +0x59C=0.9, [[+0x118]+0xC0]=1.1);
                                      // surface-word variant reads table 0xf20950 indexed
                                      // by an outer byte (0x1818b0, index UNCERTAIN);
                                      // floor clamp derives +0x590 (>= 0.65 when <= 1.0).
                                      // Per-axle consumers 0x71000172da8/0x71000182390 use
                                      // the +0x4B8/+0x4BC..+0x4CC pairs; other members in
                                      // the zero run below: +0x4D4=0.0157f,
                                      // 0x4E0/+0x4F0/+0x4F8/+0x500=32767.0f,
                                      // 0x4E8/+0x508=-75.0f, +0x510=0.1f
  uint8_t zero_4b8[0xd4];             //0x4B8 - 0x58B — memset 0 EXCEPT the family members
                                      // listed in the +0x4B4 comment
  uint8_t bodyType3Flag58c;           //0x58C — set 1 by the body-type-3 branch (0x1817a4)
  uint8_t zero_58d[3];                //0x58D - 0x58F — unproven padding
  float floorClamp590;                //0x590 — derived from the +0x4B4 floor clamp
                                      // (>= 0.65 when mult <= 1.0; 0x181818..0x181874)
  float f594;                         //0x594 — default 1.0f; 1.24742f on body-type 3
  uint8_t zero_598[4];                //0x598 — unproven padding
  float f59c;                         //0x59C — default 1.0f; 0.9f on body-type 3
  uint8_t zero_5a0[0x3c];             //0x5A0 - 0x5DB — memset 0
  uint8_t driftGate5dc;               //0x5DC — drift flag byte +0xC0 path: clears +0xC0 and
                                      // Body floats when this < 1 or [subobj +0x201]
                                      // (drift 0x17bfb4)
  uint8_t zero_5dd[0x17];             //0x5DD - 0x5F3 — unproven padding
  float f5f4;                         //0x5F4 — ctor sets 0.1f (last field)
};
