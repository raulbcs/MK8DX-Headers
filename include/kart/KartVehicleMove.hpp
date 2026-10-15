#pragma once

#include <cstdint>

#include "object/Kart/KartRigidBody.hpp"

// KartVehicleMove — size 0x5F8 (operator new(0x5F8) in the KartVehicle
// ctor 0x71001701e4, stored at KartVehicle+0x28). Derives from
// KartRigidBody (ctor 0x71001812b4 calls 0x710014ddb4 first). Name
// confirmed by the recorder channel string "RecorderKartVehicleMove".
//
// MISATTRIBUTED FIELDS: the bitfield at +0x1680 and the float pairs at
// +0x2288/+0x2298 lie beyond the 0x5F8 allocation and belong to another,
// unnamed class.
namespace object {
struct KartVehicle;
}  // namespace object

struct KartVehicleMove : public object::KartRigidBody {
  void* static_table_e0;              //0xE0 — ctor overwrites with (0x12fd668+0x40)
  //0xE8/0xF0 — pose-holder list links {prev, next}. The KartMove manager
  // ctor 0x710016f868 links the KartVehicleMove group (KartMove+0x28,
  // +0x30, +0x38) through these fields at 0x170284..0x1702a4; several
  // instances are cross-linked per player.
  KartVehicleMove* poseListPrev;      //0xE8
  KartVehicleMove* poseListNext;      //0xF0
  object::KartVehicle* kart_vehicle;  //0xF8 — ctor arg (0x1812d0); object whose +0x1cc
                                      // flags word gates the antigrav spin
  uint8_t pad_100[8];                 //0x100
  uint8_t pad_108[0x20];              //0x108 - 0x127 — ctor zeroes
  float f128[2];                      //0x128 — ctor sets {1.0f, 1.0f}
  uint8_t pad_130[8];                 //0x130
  float f138;                         //0x138 — ctor sets 1.0f
  uint8_t pad13c[4];                  //0x13C
  uint8_t zero_140[0xd0];             //0x140 - 0x20F — memset 0; +0x201 = trick-air flag
                                      // (landing gate, cleared by FUN_71001744a4 cleanup)
  uint8_t flag210;                    //0x210 — ctor sets 1
  uint8_t pad_211[5];                 //0x211 - 0x215 — ctor zeroes; +0x212 = trick anim
                                      // active (success-bit path vs mTrickFrames++),
                                      // +0x213 = landing boost tier-1 selector; both
                                      // cleared by FUN_71001744a4 cleanup
  uint8_t course_flag216;             //0x216 — 0 on course IDs 0x61/0x5E, else 1 (0x181520)
  uint8_t course_flag217;             //0x217 — 1 on course 0x6E (0x18156c)
  uint8_t course_flag218;             //0x218 — 1 on course 0x71 (0x181584)
  uint8_t pad_219;                          //0x219
  uint16_t course_flag21a;            //0x21A — 0x101 on course 0x65 (0x181558);
                                      // byte +0x21B = 1 on course 0x71 (0x181584/0x18158c)
  uint8_t pad_21c[3];                       //0x21C
  float wallBoostScale220;            //0x220 — wallBoostScale: per-axle calc clamps it to [0,1]
                                      // (0x182738), accumulates += (1 - n*axleDir) * (0.3 | 0.2 if
                                      // bodyType+0xB0) in the hit path, and calcHitReaction
                                      // FUN_710017b578 reads it at 0x17b580
  uint8_t pad_224[8];                 //0x224 - 0x22B — rest of the ctor zero run
  uint8_t antigravSpinTimer22c;       //0x22C — body calc requests boost tier 0x200
                                      // (trigger type 2) when mbAntiGColSpin (+0x3EC)
                                      // is set and this < 1.0 (0x18b9f4)
  uint8_t pad_22d[7];                       //0x22D
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
  uint8_t pad_38c[0x14];              //0x38C - 0x39F
  float f3a0;                         //0x3A0 — ctor sets 1.0f
  uint8_t pad_3a4[0x10];
  float f3b8;                         //0x3B8 — ctor sets 0.75f
  uint8_t zero_3bc[8];                //0x3BC - 0x3C3 — ctor zeroes; +0x3C0 = vertical gravity
                                      // trimmer: +/-0.005 per frame toward target 0.75 (0.75 when
                                      // flag(0x174ec8(outer,-1)), else s8), sum +0x3C0+0x3C4
                                      // clamped [0, 0.99] (0x184900..0x18498c)
  float gravityAccel3c4;              //0x3C4 — gravity accel (Y of the +0x3C0/+0x3C4/+0x3C8
                                      // accel vector), integrated into vel +0x50/+0x54/+0x58 by
                                      // FUN_71001ac038 (0x1ac170..0x1ac194). Values per state
                                      //  0.245f default
                                      // air (pool 0xed5ef8; inline writers 0x17c39c, 0x17c658,
                                      // 0x17d94c, 0x17d560); 0.04f glide/hop states 4/5 (inline
                                      // 0x17bda4 setter and 0x17ce20 every frame); 0 grounded
                                      // resets 0x181bf0/0x182ca8 and gate 0x184438.
  uint8_t zero_3c8[0x24];             //0x3C8 - 0x3EB — ctor zeroes; +0x3C8 = gravity accel Z,
                                      // zeroed by the move-gate at 0x184438 and lerped via
                                      // FUN_710016f138(rate 0.001, 0x184490)
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
                                      // the zero run below: +0x4D4=0.015f (0x3c75c28f),
                                      // 0x4E0/+0x4F0/+0x4F8/+0x500=32767.0f,
                                      // 0x4E8/+0x508=0.018046875f , +0x510=0.1f.
                                      // WALL BOUNCE : the accel/
                                      // wall-family slots +0x4B8..+0x4CC (bit-flag selected:
                                      // 0x1000 -> {+0x4C8,+0x4CC}; 0x800080 -> {+0x4C0,+0x4C4};
                                      // default {+0x4B8,+0x4BC}) feed calcHitReaction
                                      // FUN_710017b578 (called 0x1835a4): scaled reflection
                                      // v' = v + n*(wallMult - scale*dot(v,n)) with wallMult
                                      // from the selected slot pair and scale = (wallMult -
                                      // 0.04*s_contact)*(1 - a*(n*axleDir)) + boostSlot+0x60;
                                      // scale > 0.3 drops miniturbo (+0x60 *= 1-scale); no
                                      // runtime writer of +0x4B8..+0x4CC exists (init-only).
  uint8_t zero_4b8[0xd4];             //0x4B8 - 0x58B — memset 0 EXCEPT the family members
                                      // listed in the +0x4B4 comment
  uint8_t bodyType3Flag58c;           //0x58C — set 1 by the body-type-3 branch (0x1817a4)
  uint8_t zero_58d[3];                //0x58D - 0x58F
  float floorClamp590;                //0x590 — derived from the +0x4B4 floor clamp
                                      // (>= 0.65 when mult <= 1.0; 0x181818..0x181874)
  float f594;                         //0x594 — default 1.0f; 1.24742f on body-type 3
  uint8_t zero_598[4];                //0x598
  float f59c;                         //0x59C — default 1.0f; 0.9f on body-type 3
  uint8_t zero_5a0[0x3c];             //0x5A0 - 0x5DB — memset 0; +0x5D8 >= 1 gates the
                                      // trick trigger FUN_7100175f5c (and > 0 is an
                                      // alternate landing escape)
  uint8_t driftGate5dc;               //0x5DC — drift flag byte +0xC0 path: clears +0xC0 and
                                      // Body floats when this < 1 or [subobj +0x201]
                                      // (drift 0x17bfb4)
  uint8_t zero_5dd[0x17];             //0x5DD - 0x5F3
  float f5f4;                         //0x5F4 — ctor sets 0.1f (last field)
};
