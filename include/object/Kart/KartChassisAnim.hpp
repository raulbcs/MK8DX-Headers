#pragma once

#include <cstdint>

// KartChassisAnim — size 0x130, proven by operator new(0x130) in the
// KartVehicle ctor (v400 0x7100170308, stored at KartVehicle+0x58; ctor
// 0x710012289c receives the KartVehicle* and KartChassis+0x10).
// Name mirrors KartVehicle::mKartChassisAnim (field-mirror evidence); no MethodTree
// string. The ctor also fills the 0x80..0xCB region with 0xFF and then
// patches cells from globals 0x12fae28 / 0x12fada8 (beyond the dumped tail).
namespace object {
struct KartVehicle;  // KartVehicle.hpp
struct KartChassis;  // KartChassis.hpp

struct KartChassisAnim {
  uint8_t pad_00[8];          // 0x00 — vtable ptr
  uint32_t u08;               //0x08 — ctor zero
  KartVehicle* kart_vehicle;  //0x10 — ctor arg
  void* chassis_10;           //0x18 — ctor arg: KartChassis+0x10 subcomponent
  uint8_t pad_020[0x30];      //0x20 — ctor zeroes through 0x4F
  uint16_t u50[0xC];          //0x50..0x67 — ctor sets -1 at 0x50/0x52/0x54/0x58/
                              // 0x5A/0x5C/0x60/0x62/0x64/0x66 (0x56 and 0x5E left untouched)
  int32_t s68;                //0x68 — ctor sets -1
  uint32_t u6c;               //0x6C — ctor zero
  uint64_t u70;               //0x70 — ctor zero
  uint64_t u78;               //0x78 — ctor sets 0xBFF80FFFFFFFFFFF (two raw u32 cells)
  uint8_t ffblock_80[0x4c];   //0x80..0xCB — memset 0xFF (ctor 0x122930),
                              // cells then patched from globals 0x12fae28 / 0x12fada8
  uint32_t ucc;               //0xCC — ctor zero
  float f_d0;                 //0xD0 — ctor sets 0.0f
  float f_d4;                 //0xD4 — ctor sets 1.5f (0x3FC00000)
  uint64_t s_d8;              //0xD8 — ctor sets -1
  uint64_t s_e0;              //0xE0 — ctor sets -1
  uint64_t s_e8;              //0xE8 — ctor sets -1
  int32_t s_f0;               //0xF0 — ctor sets -1
  uint32_t u_f4;              //0xF4 — ctor zero
  int32_t s_f8;               //0xF8 — ctor sets -1
  uint8_t pad_fc[4];          //0xFC — unproven padding
  uint32_t u100;              //0x100 — ctor zero
  uint64_t u108;              //0x108 — ctor zero
  uint32_t u110;              //0x110 — ctor zero
  uint64_t u118;              //0x118 — ctor zero
  int32_t s120;               //0x120 — ctor sets -1
  uint16_t u124;              //0x124 — ctor sets 0xFFFF
  int32_t s128;               //0x128 — ctor sets -1
  uint16_t u12c;              //0x12C — ctor sets 0xFFFF
  uint8_t pad_12e[2];         //0x12E — unproven padding
};
}  // namespace object
