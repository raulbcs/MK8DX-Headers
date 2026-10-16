#pragma once

#include <cstdint>

#include "object/Kart/KartRigidBody.hpp"

namespace object {
struct KartVehicle;
}  // namespace object

// KartVehicleMove — size 0x5F8 (operator new(0x5F8) in the KartVehicle
struct KartVehicleMove : public object::KartRigidBody {
  void* static_table_e0;  //0xE0 — ctor overwrites with (0x12fd668+0x40)
  //0xE8/0xF0 — pose-holder list links {prev, next}. The KartMove manager
  // ctor 0x710016f868 links the KartVehicleMove group (KartMove+0x28,
  // +0x30, +0x38) through these fields at 0x170284..0x1702a4; several
  // instances are cross-linked per player.
  KartVehicleMove* poseListPrev;      //0xE8
  KartVehicleMove* poseListNext;      //0xF0
  object::KartVehicle* kart_vehicle;  //0xF8 — ctor arg (0x1812d0); object whose +0x1cc
                                      // flags word gates the antigrav spin
  void* dataObj100;                   //0x100 — pointer copied from KartVehicle+0x18 in the
                                      // ctor (0x1815b0/0x1815b4). Used as an object pointer:
                                      // reset FUN_71001819d8 walks it (+0x28, 0x18243c..
                                      // 0x182454) and calc FUN_7100182f38 reads the ints at
                                      // +0x84/+0x88/+0x8C (0x18451c..0x184530), passes +0x84
                                      // to 0x8d4320 (0x184578) and reads float +0x30
                                      // (0x1853c0). Chosen over +0x108 when KartVehicle flag
                                      // +0xD3 is set (0x1853a0..0x1853ac)
  void* dataObj108;                   //0x108 — pointer copied from KartVehicle+0x20 in the
                                      // ctor (0x1815b8/0x1815c0). The float triple +0x3C/
                                      // +0x40/+0x44 is zero-tested in reset FUN_71001819d8
                                      // (0x182478..0x18249C); float +0x30 read at 0x1853c0.
                                      // Selected when KartVehicle flag +0xE7 is set instead
                                      // of +0xD3 (0x1853b4)
  void* subObj110;                    //0x110 — new(0xD0) sub-object (ctor 0x1815d4/
                                      // 0x1815d8, arg-ctor 0x17b304)
  void* subObj118;                    //0x118 — new(0xD8) sub-object (0x1815ec/0x1815f0,
                                      // ctor 0x17a0e4)
  void* subObj120;                    //0x120 — new(0x70) sub-object (0x181604/0x181608,
                                      // ctor 0x17eb94); carries the call target 0x17eda8 of
                                      // the f38c update (0x183878..0x183880)
  void* field128;                     //0x128 — ctor stores {0, 1.0f} (0x181318), then
                                      // overwrites with new(0x328) built from pointers to
                                      // +0x37C/+0x380/+0x27C/+0x188/+0x201/+0x204/+0x8/
                                      // +0x205/+0x234/+0x238/+0x22C/+0x3EC when the KartVehicle
                                      // flags word [+kv+8]+2 != 7 (0x181654..0x1816d0)
  float f130[2];                      //0x130 — float pair, NOT initialized by the ctor; the
                                      // per-race reset FUN_71001819d8 sets {1.0f, 1.0f}
                                      // (0x181aa4; +0x138 = 1.0f follows at 0x181aa8). Read as
                                      // a float in FUN_7100172ac0 (0x172d00; that this pointer
                                      // is kart-vehicle-move is corroborated by the +0x210 flag
                                      // and +0x338 accesses in the same function)
  float f138;                         //0x138 — ctor sets 1.0f (0x181314); reset re-sets it
                                      // (0x181aa8)
  uint8_t pad13c[4];                  //0x13C — never read or written on this class in the
                                      // kart region 0x170000-0x190000; the float writers at
                                      // 0x174a6c/0x178b60/0x178ea8 belong to a sibling class
                                      // (they store ints over this class's ctor-allocated
                                      // pointers at +0x148..+0x150). Also skipped by the ctor
                                      // init runs (only +0x138 is set, 0x181314)
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
  uint8_t course_flag219;             //0x219 — 1 on course 0x7A (ctor 0x181594..0x1815a8);
                                      // zeroed with the 0x219..0x21C word at 0x181338. Readers:
                                      // boost/dash gate FUN_7100186b0c/0x186bc8/0x186c6c/
                                      // 0x186e24 (0x186b88/0x186c2c/0x186d6c/0x186d9c/0x186e28 —
                                      // requires [+0x5DC] >= 1 and [+0x26C]-1 < 3 alongside the
                                      // +0x228 check); wheel-hit scaling at 0x18a03c (flag set
                                      // -> clamps >= 0 and scales by +0x1DC/+0x1E0); and
                                      // FUN_710017e838 reads it through [KartVehicle+0x28]
                                      // (0x17ea64..0x17ea78, which also proves KartVehicle+0x28
                                      // holds this object) to select state 18 over the default
  uint16_t course_flag21a;            //0x21A — 0x101 on course 0x65 (0x181558);
                                      // byte +0x21B = 1 on course 0x71 (0x181584/0x18158c)
  uint8_t pad_21c;                    //0x21C — ctor-zeroed (the 0x181338 str wzr covers
                                      // 0x219..0x21C) and never accessed on this class
  uint8_t pad_21d[3];                 //0x21D - 0x21F — never read or written on this class
                                      // (binary-wide hits are unrelated classes) and NOT
                                      // initialized by the ctor (no init covers 0x21D..0x21F)
  float wallBoostScale220;            //0x220 — wallBoostScale: per-axle calc clamps it to [0,1]
                                      // (0x182738), accumulates += (1 - n*axleDir) * (0.3 | 0.2 if
                                      // bodyType+0xB0) in the hit path, and calcHitReaction
                                      // FUN_710017b578 reads it at 0x17b580
  uint8_t pad_224[8];                 //0x224 - 0x22B — rest of the ctor zero run
  uint8_t antigravSpinTimer22c;       //0x22C — body calc requests boost tier 0x200
                                      // (trigger type 2) when mbAntiGColSpin (+0x3EC)
                                      // is set and this < 1.0 (0x18b9f4)
  uint8_t pad_22d[7];                 //0x22D - 0x233 — ctor-zeroed (the 0x181368 str xzr
                                      // covers 0x228..0x22F and 0x18136c covers 0x230..0x237)
                                      // and never accessed on this class
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
                                      // (0x17bab4); computed beside +0x384 by reset
                                      // FUN_71001819d8 (0x1822f4)
  float f384;                         //0x384 — second float of the +0x380/+0x384 pair:
                                      // reset FUN_71001819d8 zeroes it (0x181e68) and computes
                                      // it beside +0x380 with fmax/fcsel (0x1822e4..0x1822f4);
                                      // read by FUN_71001867a8 (0x18690c), FUN_710018694c
                                      // (0x186a80), FUN_71001873d8 (0x187474/0x187618/0x187690)
                                      // and calc FUN_7100182f38 (0x184fec). Semantics beyond
                                      // the pairing with +0x380 not proven — neutral name
  float f388;                         //0x388 — ctor sets 1.0f
  float f38c;                         //0x38C — float accumulator, ctor-zeroed (run
                                      // 0x38C..0x39B via the 0x1813d8/0x1813dc/0x1813e0 xzr
                                      // stores): calc FUN_7100182f38 stores a stack word into
                                      // it (0x183844), then when the call 0x17eda8 on [+0x120]
                                      // returns out > 0 takes max(prior, out) — with the
                                      // prior == 0 case falling back to +0x42C — and stores it
                                      // back (0x183884..0x1838ac); read again at 0x184e70
  uint8_t pad_390[0x10];              //0x390 - 0x39F — ctor zeroes
  float f3a0;                         //0x3A0 — ctor sets 1.0f
  float f3a4;                         //0x3A4 — float, exponential-approach update in calc
                                      // FUN_7100182f38 (0x1842dc..0x1842f4, clamped to rodata
                                      // constant ranges; second clamp/store 0x184324); zeroed
                                      // by the 0x1843bc path and ctor-zeroed (0x1813e4 covers
                                      // 0x3A4..0x3AB)
  float f3a8;                         //0x3A8 — sibling of the same pair (store 0x184328 with
                                      // clamps 0x18432c..0x18433c; fnmul write 0x1843b8)
  float f3ac;                         //0x3AC — float, ctor-zeroed (0x1813ec/0x18140c covers
                                      // 0x3AC..0x3B3); read in calc FUN_7100182f38 (0x18453c/
                                      // 0x184570) as an argument of the 0x8d4320 calls
  uint8_t pad_3b0[4];                 //0x3B0 - 0x3B3 — ctor zeroes
  float f3b4;                         //0x3B4 — float decay accumulator in calc
                                      // FUN_7100182f38: stored scaled (0x1857d4); if negative
                                      // += const and clamped to 0 (0x1857e4..0x185824), else
                                      // += const with a *0.75 fold-back (0x18582c..0x18584c);
                                      // zeroed by the ctor (0x181400) and by reset
                                      // FUN_71001819d8 (0x181bc8)
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
  uint8_t pad_3ee[2];                 //0x3EE - 0x3EF — never read or written on this class
                                      // (only the +0x3EC/+0x3ED bytes are accessed, e.g.
                                      // 0x187b20/0x1892b8) and NOT initialized by the ctor:
                                      // +0x3ED is set at 0x18144c and the next init is the
                                      // memset(0x3F0, 0x4C) at 0x1813f8/0x181450
  uint8_t zero_3f0[0x2c];             //0x3F0 - 0x41B — memset 0
  float f41c;                         //0x41C — float, last lane of the +0x40C/+0x410/+0x414/
                                      // +0x418/+0x41C acceleration set summed in the
                                      // boost-request calc (0x18bae0..0x18bafc); zeroed by
                                      // reset FUN_71001819d8 (0x181c58) and ctor-zeroed via
                                      // the memset 0x3F0..0x43B (0x1813f8/0x181450)
  float speedNorm420;                 //0x420 — normalization denominator of the surface
                                      // speed term: +0x420 = max(+0x420, 1.0); scale =
                                      // dot / +0x420 (0x182274..0x18229c); seeded from
                                      // [+0x4B8] by reset FUN_71001819d8 (0x181c0c)
  float f424;                         //0x424 — float; reset FUN_71001819d8 seeds it from
                                      // [+0x4B8] together with +0x420/+0x428/+0x42C/+0x430
                                      // (0x181c08..0x181c1c) and calc FUN_7100182f38 recomputes
                                      // the +0x420/+0x424/+0x428 trio from a product/clamp
                                      // chain (0x182bc0..0x182be4)
  float f428;                         //0x428 — float, third lane of the same trio (store
                                      // 0x182be4); seeded from [+0x4B8] by the reset (0x181c14)
  uint8_t pad_42c[4];                 //0x42C - 0x42F — ctor zeroes; +0x42C is the fallback
                                      // source for f38c (0x18389c) and is seeded from +0x4B8
                                      // by the reset (0x181c14) — same for +0x428/+0x430
  uint8_t pad_430[0xc];               //0x430 - 0x43B — ctor zeroes
  float f43c[24];                     //0x43C..0x49B — ctor sets all to 1.0f
  float f49c[6];                      //0x49C..0x4B3 — also ctor-set to 1.0f (pairs
                                      // 0x181458..0x1814d0); +0x49C is live: written from the
                                      // external param object [x11+0x8A8] at 0x186278 and
                                      // shuffled within the array (+0x49C -> +0x44C,
                                      // +0x494 -> +0x444, +0x464 -> +0x43C) at
                                      // 0x18ae44..0x18ae84; the +0x4B4 member is overwritten
                                      // by the sub-ctor memset
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
  uint8_t zero_58d[3];                //0x58D - 0x58F — never read or written anywhere; the
                                      // ctor zero run stops at +0x58C (memset 0x53C..0x58C,
                                      // 0x1814dc/0x1814f4) so these bytes are not even
                                      // initialized
  float floorClamp590;                //0x590 — derived from the +0x4B4 floor clamp
                                      // (>= 0.65 when mult <= 1.0; 0x181818..0x181874)
  float f594;                         //0x594 — default 1.0f; 1.24742f on body-type 3
  float f598;                         //0x598 — float, ctor-zeroed together with the +0x594
                                      // pair (the 0x1814f0 str xzr covers 0x594..0x59B) and
                                      // read as a float in calc FUN_7100182f38 immediately
                                      // before the call 0x17bb2c on [+0x110] (0x184efc..0x184f04)
  float f59c;                         //0x59C — default 1.0f; 0.9f on body-type 3
  uint8_t zero_5a0[0x3c];             //0x5A0 - 0x5DB — memset 0; +0x5D8 >= 1 gates the
                                      // trick trigger FUN_7100175f5c (and > 0 is an
                                      // alternate landing escape)
  uint8_t driftGate5dc;               //0x5DC — drift flag byte +0xC0 path: clears +0xC0 and
                                      // Body floats when this < 1 or [subobj +0x201]
                                      // (drift 0x17bfb4)
  uint8_t zero_5dd[0x17];             //0x5DD - 0x5F3 — ctor-zeroed (memset 0x5A0..0x5F3,
                                      // 0x1814f8..0x181508) and never accessed on this class
  float f5f4;                         //0x5F4 — ctor sets 0.1f (last field)
};
