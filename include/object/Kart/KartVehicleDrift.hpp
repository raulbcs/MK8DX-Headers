#pragma once

#include <cstdint>

// KartVehicleDrift — drift state object (name from the recorder channel
// string "RecorderKartVehicleDrift", rodata 0xee602a). Held through the
// KartVehicleMove+0x110 (str @0x71001815d8 after new(0x118) at 0x71001815bc;
// extent 0x118). Drift ctor family entry: 0x710017b304; accessors 0x710017b9xx-0x710017bfb4
// + calc 0x710017b578.
namespace object {
struct KartVehicle;      // KartVehicle.hpp
struct KartVehicleMove;  // kart/KartVehicleMove.hpp
struct KartVehicleBody;  // KartVehicleBody.hpp

struct KartVehicleDrift {
  uint8_t pad_00[8];          // 0x00 — vtable/untouched head
  KartVehicle* kart_vehicle;  //0x08 — read by 0x17bab4/0x17bd6c/0x17bcc4
                              // (deref +0x28 -> KartVehicleMove, +0x38 -> KartVehicleBody)
  uint32_t state_10;          //0x10 — drift state: 0 none, 1 (0x17bc84), 2 wheel/
                              // pre-drift (0x17bc48), 4 = drift LEFT (0x17bae4), 5 = drift RIGHT
                              // (0x17baf4), 6 glide+drift (0x17bc28), 7 (0x17bc38).
                              // drifting family = (state|3)==7; glide = (state|1)==5.
                              // Setter 0x710017bd14: target = (arg&1)?5:4; it also
                              // resets +0x58/+0x70/+0x8c, writes +0x6c = ±1.0 and
                              // KartVehicleMove+0x3c4 = 0.04f .
                              // 6/7 are read by predicates but have NO located
                              // producer (only store to +0x10 is the setter's 4/5;
                              // hop-release 17cc08 passes 4/5 via csel) — UNCERTAIN.
                              // State open is event-driven via the kart body
                              // trigger queue.
  uint8_t b14;                //0x14 — hop/drive latch: written (arg&1) by
                              // FUN_710017b518 (0x17b520), read by the drift calc
                              // 0x17b7ac (gates the Body force calls)
  uint8_t b15;                //0x15 — written (arg&1) by FUN_710017b518 (0x17b528),
                              // read by the calc (0x17b6ec, gates the Move+0x208/
                              // +0x26c branch)
  uint8_t b16;                //0x16 — derived flag: ([x0+0x1c] > 0) written by
                              // FUN_710017b518 (0x17b558)
  uint8_t b17;                //0x17 — written (arg&1) by FUN_710017b518 (0x17b54c),
                              // read by calc2 FUN_710017c020 (0x17c1f8)
  uint8_t b18;                //0x18 — written (arg&1) by FUN_710017b518 (0x17b55c);
                              // cleared by the reset FUN_710017b4a4 (0x17b4bc)
  uint8_t pad_019[3];         //0x19 — untouched by the whole accessor family
  int32_t s1c;                //0x1C — counter: set to 1 when arg3 of
                              // FUN_710017b518 is set (0x17b538), otherwise
                              // max(0, [0x1c]-1) (0x17b550-0x17b560); ctor-zeroed by
                              // the memset at 0x17b340
  float f20;                  //0x20 — ctor float from the rodata table 0xf200f8c8
                              // indexed by ([kart_vehicle+0xda] != 0) * 4
                              // (0x17b3b4/0x17b418); zeroed every calc (0x17c184)
  float f24;                  //0x24 — scaled by a KartUnit wheel stat (0x17c0f8/0x17c154)
  float f28;                  //0x28
  float f2c;                  //0x2C — accumulates rodata [0xed5a5c] per frame, resets to 1.5625f
  float f30;                  //0x30 — ctor float from rodata table 0xf200f8c8 (0x17b418)
  uint32_t u34;               //0x34 — ctor constant word 0x80343a37 (0x17b42c)
  uint64_t zero_38;           //0x38 — zeroed each calc (0x17c180)
  float f40;                  //0x40 — ctor float from rodata table 0xf200f8d8 (0x17b420);
                              // predicate FUN_710017b0ac returns state_10 != 0 &&
                              // [0x40] > 0 (0x17b0b4-0x17b0bc)
  float f44;                  //0x44 — ctor float, same rodata value as f40 (0x17b424)
  float f48;                  //0x48 — steer-related, clamped by rodata [0xed5c4c]
  float f4c;                  //0x4C — ctor float from rodata table 0xf200f8d0 (0x17b41c)
  float f50;                  //0x50 — ctor float from rodata table 0xf200f8e8 (0x17b438)
  int32_t s54;                //0x54 — zeroed in calc
  float f58;                  //0x58 — zeroed on drift-state change; ratio num in 0x17b9e4
  float f5c;                  //0x5C — ratio denominator (|f5c|)
  float f60;                  //0x60 — ctor float from rodata table 0xf200f8e8 (0x17b438);
                              // no other access found in the accessor family
  float f64;                  //0x64 — threshold vs KartVehicleMove+0x380 (0x17bab4)
  float f68;                  //0x68 — ctor stores 1.0f (0x17b35c); no family access since
  float f6c;                  //0x6C — drift direction: -1.0 state 4, +1.0 otherwise
  float f70;                  //0x70 — drift charge (FUN_710017be98), zeroed on state change
  float f74;                  //0x74 — denominator when veh+0xD2 (mIsCpu) set
  uint8_t pad_078[8];         //0x78 — ctor-zeroed (0x17b36c, xzr covers 0x74..0x7b);
                              // never accessed by the accessor family
  float f80;                  //0x80 — denominator (cpu-select path)
  uint8_t pad_084[8];         //0x84 — ctor-zeroed (0x17b364, xzr covers 0x84..0x8b);
                              // never accessed by the accessor family
  int32_t s8c;                //0x8C — drift tier 0..3; predicates (s|3)==7 && tier==k
                              // (k=1/2/3) in 0x17bb04/0x17bb40/0x17bb68; zeroed on state change
  // 0x90..0xBF — array of 4 per-wheel drift entries { int32 id; float a;
  // float b; } set by FUN_710017b120 (entry 0), FUN_710017b184 (entry 1),
  // FUN_710017b1e8 (entry 2), FUN_710017b24c (entry 3); each setter folds
  // arg0 through the KartConfig singleton 0x87fcd0 ([ret+0x10] compared to 3).
  int32_t s90;         //0x90 — wheel entry[0].id (setter FUN_710017b120,
                       // 0x17b13c); ctor-zeroed 0x17b350
  uint8_t b94;         //0x94 — direction latch: entry[0].a low byte; setter
                       // FUN_710017bd58 writes 1 here for state 4 (0x17bd88)
  uint8_t b95;         //0x95 — direction latch: setter writes 1 here otherwise
                       // (0x17bd98); entry[0].a high byte
  uint8_t b96;         //0x96 — ctor-zeroed (0x17b348), reset-zeroed (0x17b4d4),
                       // cleared by FUN_710017b568 (0x17b56c)
  uint8_t pad_097;     //0x97 — untouched by the whole accessor family
  float f98;           //0x98 — wheel entry[0].b (0x17b170); ctor-zeroed
                       // (0x17b378, xzr covers 0x98..0x9f)
  uint32_t s9c;        //0x9C — KartVehicle mPlayerID copy? (read at 0x17bdf4);
                       // also wheel entry[1].id per setter FUN_710017b184
                       // (0x17b1a0)
  float fa0;           //0xA0 — wheel entry[1].a (0x17b1d0)
  float fa4;           //0xA4 — wheel entry[1].b (0x17b1d4)
  int32_t sa8;         //0xA8 — wheel entry[2].id (0x17b204); read as index into
                       // a KartVehicle actor table at 0x17bdf4/0x17be7c
  float fac;           //0xAC — wheel entry[2].a (0x17b234)
  float fb0;           //0xB0 — wheel entry[2].b (0x17b238)
  int32_t sb4;         //0xB4 — wheel entry[3].id (0x17b268); calc2 also stores a
                       // clamped float here (0x17c3f8)
  float fb8;           //0xB8 — wheel entry[3].a (0x17b298); calc2 zeroes it
                       // (0x17c404, stp wzr,w8 covers 0xb8/0xbc)
  int32_t sbc;         //0xBC — wheel entry[3].b; calc2 stores (int)(a *
                       // rodata[0xed58e8]) here (0x17c404); checked > 0
                       // (FUN_710017bc94), zeroed in calc
  uint8_t fc0;         //0xC0 — flag: clears itself + Body floats (+0x10c/+0x58/+0x60)
                       // when [Move+0x5DC] < 1 or [Move subobj +0x201] (0x17bfb4)
  uint8_t pad_0c1[3];  //0xC1 — untouched by ctor (only 0xc0 is cleared,
                       // 0x17b374) and by the whole accessor family
  float fc4;           //0xC4 — charge: fC4 += fC8, saturating at 1.0 (0x17bea0,
                       // dis 17bea0..17beb8); gate fC4 >= 0.6f releases the
                       // mini-turbo (rodata [0xed5930] = 0.6)
  float fc8;           //0xC8 — charge increment
  float fcc;           //0xCC — fCC += [0xed5934] (= -0.2), clamped to
                       // [rodata 0xed58ec = 0.1, rodata 0xed58a8 = 0.8]
                       // (dis 17bec4..17bef8); mirrored to KartVehicleBody+0x114

  // 0xD0..0xF7 — mini-turbo/boost scratch floats (ctor-zeroed 0x17b380-
  // 0x17b398, then partially rodata-initialized; reset zeroes the block
  // again at 0x17b4ec-0x17b4f8).
  float fd0;             //0xD0 — mini-turbo charge pair: loaded/stored as an
                         // ldp/stp pair with +0xd4 in FUN_710017bea0
                         // (0x17bf7c/0x17bf8c), zeroed (0x17bf9c), then
                         // fD0 = charge * select(+0xd4, +0xd8-half) (0x17bfbc)
  float fd4;             //0xD4 — pair element; reset-zeroed (0x17b4e8)
  int32_t sd8;           //0xD8 — countdown: set to 10 when the registered-actor
                         // check passes (0x17b760-0x17b764), then decremented
                         // per calc (0x17b768-0x17b774); NOT ctor-initialized
  float fdc;             //0xDC — accumulator scaled by rodata [0xed5ac4] and
                         // floored at -30.0f by calc2 (0x17c458-0x17c4b8)
  uint8_t pad_0e0[4];    //0xE0 — ctor-zeroed (0x17b398, xzr covers 0xdc..0xe3)
  float fe4;             //0xE4 — zeroed every calc2 pass (0x17c514); ctor-zeroed
  uint8_t pad_0e8[4];    //0xE8 — ctor-zeroed (0x17b394, xzr covers 0xe4..0xeb)
  float fec;             //0xEC — ctor: rodata [0xed58e8], or 0.0f when
                         // [kart_vehicle+0xda] is set (fcsel 0x17b408, str 0x17b428)
  float ff0;             //0xF0 — ctor float from rodata table 0xf200f8e0 (0x17b430)
  float ff4;             //0xF4 — ctor float from rodata table 0xf200f880 (0x17b434)
  void* mf8;             //0xF8 — heap subobject: operator new(0x2a0) constructed
                         // by 0x3aea10 when ([0x87fcd0]+0x8 | 2) != 7
                         // (0x17b470-0x17b488)
  uint8_t f100;          //0x100 — cleared by FUN_710017b9dc
  uint8_t b101;          //0x101 — read by getter FUN_71001423d8
  uint8_t b102;          //0x102 — written by calc2 (0x17c290); cleared by the
                         // reset (0x17b4b8) and FUN_710017b568 (0x17b570)
  uint8_t pad_103;       //0x103 — untouched by the whole accessor family
  uint32_t s104;         //0x104 — cleared by the state-change handler (0x17be84)
  uint32_t s108;         //0x108 — cleared in calc 0x710017b578 (0x17b914)
  int32_t s10c;          //0x10C — arg to 0x7100175f5c in the same calc
                         // The calc also mirrors floats into KartVehicleBody+0x110/0x114/0x118
                         // (0x17bf14-0x17bf74).
  uint8_t pad_110[0x8];  //0x110 — to the allocation end 0x118 (new at 0x71001815bc)
};
}  // namespace object
