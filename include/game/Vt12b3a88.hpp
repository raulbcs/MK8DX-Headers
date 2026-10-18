#pragma once

#include <cstdint>

// Vt12b3a88 — KartParamCache-cluster channel-group holder (member ctor
// 0x662070, embedded at +0x38 of Vt12b23a0). Holds a new[]-array of
// 0x168-stride channel objects (elem vptr 0x12b3ad0) plus an intrusive
// list; slot 4 does name-keyed lookup into a result pointer array.
// extent 0x58 - details: doc/game/Vt12b3a88.md
namespace game {
class Vt12b3a88 {
 public:
  void* mVtable;       // 0x00 - vptr 0x12b3a88 (GOT cell 0x130db48 holds
                       //   vptr-0x10 0x12b3a78; init adds 0x10)
  void* m08;           // 0x08 - subobject, dtor 0x60b984 (D1 calls it on
                       //   this+0x08 and this+0x28)
  uint32_t m10;        // 0x10 - 0 (init)
  uint32_t m14;        // 0x14 - 0 (init)
  uint32_t m18;        // 0x18 - element count (D1 reads it; stp-zeroed)
  uint32_t m1c;        // 0x1c - 0 (init)
  void* m20;           // 0x20 - new[] array of 0x168-stride channel
                       //   objects; allocation cookie holds the count and
                       //   D1 re-installs elem vptr 0x12b3ad0 (cell
                       //   0x130db50+0x10) into each before delete[]
  void* m28;           // 0x28 - subobject, dtor 0x60b984
  void* m30;           // 0x30 - 0 (init)
  void* m38;           // 0x38 - intrusive list head, self-initialized to
                       //   this+0x38 (unlinked by 0x60b79c in D1)
  void* m40;           // 0x40 - intrusive list tail, self-initialized to
                       //   this+0x38
  uint32_t m48;        // 0x48 - 0 (init)
  uint32_t m4c;        // 0x4c - 0x58 (88) written by init
  int32_t m50;         // 0x50 - -1 written by init
  uint16_t m54;        // 0x54 - 1 written by init
  uint16_t m56;        // 0x56 - tail pad to extent
};
}  // namespace game
