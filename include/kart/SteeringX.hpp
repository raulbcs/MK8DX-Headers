#pragma once

#include <cstdint>

// SteeringX (size 0x106; unpadded tail-pads to 0x108) — steering/start-dash
// object. DUPLICATE of object::KartSteerAssist (same object, same layout):
// +0x43 is the one-bit parity setter target (0x7100150a80 sets +0x43 = arg&1,
// constant 1 from wrappers 0x1925fc..0x192644), +0xB8 is the same lazy cache
// (*(*(RS+0x190+idx*8)+0x238)+0xB8, filled at 0x150b08..0x150b14 inside
// 0x7100150a90), +0xC0/+0xC8 are the same KartVehicle*/KartVehicleMove*
// ctor-arg pair, and the "mode" writer at +0x28 is the assist-level setter
// 0x7100150a40. Authoritative per-field notes: object/Kart/KartSteerAssist.hpp.
// PROVISIONAL: name has no MethodTree string (the ELF carries no name for
// this class; method-tree registrations at 0x6327a8 hold none).
//
// Layout evidence: ctor 0x71001502a8 with tail-called re-init 0x710015042c
// (call site 0x1503ac); all store sites cited below were verified in the
// v400 ELF.

struct SteeringX {
  void* vptr;                    //0x00 — *0x12fd538 + 0x10 (0x1502d0)
  void* subobject_70;            //0x08 — new(0x70) via 0x7c55cc (0x150404..0x150418)
  void* subobject_e4_a;          //0x10 — new(0xE4) memset 0 (0x1503b0..0x1503d0)
  void* subobject_e4_b;          //0x18 — new(0xE4) memset 0 (0x1503d4..0x1503ec)
  void* subobject_24;            //0x20 — new(0x24), zeroed (0x1503e8..0x150400)
  uint32_t mode;                 //0x28 — assist level; writer 0x7100150a40
                                 // (0 -> off, else re-init + auto level)
  int32_t mode_value;            //0x2C — ctor -1 (0x1502d8); re-init writes
                                 // 0x710015090c() (0x150508..0x150510)
  uint64_t flag_30;              //0x30 — ctor 0 (0x1502e0); re-init sets 1
                                 // (0x15051c)
  int32_t i38;                   //0x38 — ctor -1 (0x1502e4)
  uint8_t process_flag;          //0x3C — gate of the 2008 post-call; ctor
                                 // zeroed as u64 with 0x3D..0x43 (0x1502ec)
  uint8_t pad_3d[6];             //0x3D - 0x42 — ctor-zeroed with process_flag
                                 // (same u64 store)
  uint8_t parity;                //0x43 — bit&1 via 0x7100150a80
  float boost_output;            //0x44 — ctor byte-zero at +0x44 (0x1502e8);
                                 // upper bytes carry no ctor store
  int32_t i48;                   //0x48 — ctor -1 (0x1502f0; re-init -1,
                                 // 0x15043c..0x150440)
  float boost_output_1;          //0x4C — ctor 0 (0x1502f0)
  uint32_t u50;                  //0x50 — ctor 0 (0x1502f4); steering target
                                 // written by calc 0x7100150a8c
  uint8_t b54;                   //0x54 — ctor 1 (0x15030c)
  uint8_t pad_55[3];             //0x55 - 0x57 — no ctor store; no accessor
                                 // evidence
  uint32_t pad_58;               //0x58 — ctor-zeroed u64 with +0x5C (0x150308)
  uint32_t countdown;            //0x5C — countdown (mode-3 epilogue after GO);
                                 // ctor 0 (same store)
  uint8_t zero_60[0x10];         //0x60 - 0x6F — ctor 0 (0x1502fc)
  uint32_t u70;                  //0x70 — ctor 0 (0x1502f8)
  uint32_t globals_74[3];        //0x74/0x78/0x7C — u32 global [0x12fd540]
                                 // (0x150310..0x150320)
  uint64_t cursor_80;            //0x80 — ctor stores this+0x94 (0x150338)
  uint32_t cap_88;               //0x88 — ctor 8 (0x150334/0x150340)
  uint64_t zero_8c;              //0x8C — ctor 0 (0x15033c)
  uint64_t sentinel_94[4];       //0x94..0xB3 — ctor -1 block (0x150324..0x150330)
  uint8_t pad_b4[4];             //0xB4 - 0xB7 — no ctor store; no accessor
                                 // evidence
  uint64_t cache_lazyinit;       //0xB8 — ctor 0 (0x150344); lazy
                                 // *(*(RS+0x190+idx*8)+0x238)+0xB8
                                 // (0x150b08..0x150b14, 0x7100150a90)
  uint64_t kart_vehicle_ptr;     //0xC0 — KartVehicle* ctor arg x1 (0x150348)
  uint64_t kart_vehicle_move;    //0xC8 — KartVehicleMove* ctor arg x2 (0x150350)
  uint64_t decay_per_frame;      //0xD0 — ctor ptr from [0x12fb148] (0x150364);
                                 // x0.8 per frame in the f74c main path
  uint32_t u_d8;                 //0xD8 — [that ptr + 8] (0x15035c)
  uint8_t pad_dc[0xc];           //0xDC - 0xE7 — no ctor store; no accessor
                                 // evidence
  float charge;                  //0xE8 — start dash, target 1.5; ctor 0
                                 // (0x15036c)
  uint32_t counter;              //0xEC — ctor 0 (0x15036c)
  float f_f0;                    //0xF0 — ctor -1.0f (0x150370); -1.0f/frame
                                 // in the calc
  uint8_t zero_f4[8];            //0xF4 - 0xFB — ctor 0 (0x150374)
  uint32_t fc;                   //0xFC — re-init 0xFFFFFFFF (0x15043c/0x150470)
  uint32_t x100;                 //0x100 — 0 (upper half of the same u64 store)
  uint8_t zero_104;              //0x104 — ctor 0 (strh 0x104..0x105, 0x150378)
  uint8_t sign_latch;            //0x105 — ctor 0 (same store)
};
