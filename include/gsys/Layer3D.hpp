#pragma once

#include <cstdint>

// Layer3D (size 0x1090) — gsys 3D render layer; ctor named gsys::Layer3D in
// functions.csv (0x710069d770). Allocated by RenderLayerManager::LayerHeap.
// extent 0x1090 - details: doc/gsys/Layer3D.md

struct Layer3D {
  uint64_t vptr;             //0x00 — *0x130def0 + 0x10 = 0x12b5fb8 (ctor 0x69d78c; D2 0x69d9d4, D1 0x69da24)
  uint8_t base_08[0x1018];   //0x08..0x101f — base class body (base ctor 0x69cae4), not yet mapped
  uint64_t field_1020;       //0x1020 — ctor zero (0x69d790)
  uint64_t member_1028;      //0x1028 — embedded object, vptr *0x1307e58 + 0x10 = 0x12b4780 (ctor 0x69d7d4); init 0x6155bc (0x69d7a4)
  uint8_t field_1030[0x18];  //0x1030..0x1047 — unwritten
  uint64_t member_1048;      //0x1048 — embedded object, vptr *0x12fae28 + 0x10 = 0x11ad210 (ctor 0x69d7e4)
  uint64_t name_1050;        //0x1050 — string ptr 0xed6af8 (ctor 0x69d7c4; "3D Main | Sub0" family used by the manager)
  uint32_t field_1058;       //0x1058 — ctor 0
  int32_t field_105c;        //0x105c — ctor -100 (0x69d7f4)
  uint32_t field_1060;       //0x1060 — ctor 1 (0x69d7cc)
  uint8_t pad_1064[8];       //0x1064..0x106b — unwritten
  uint8_t self_106c[8];      //0x106c — self pointer (ctor 0x69d810, unaligned)
  uint8_t tail_1074[0x14];   //0x1074..0x1087 — unwritten
  uint8_t flag_1088;         //0x1088 — ctor 0xff (0x69d7e8)
  uint8_t flag_1089;         //0x1089 — ctor 0 (0x69d7f0)
  uint8_t tail_108a[6];      //0x108a..0x108f — tail padding to extent
};
