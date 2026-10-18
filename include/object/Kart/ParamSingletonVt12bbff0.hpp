#pragma once

#include <cstdint>

namespace object {
// ParamSingletonVt12bbff0 - lazily-built global singleton (factory 0x707900),
// size 0x98 EXACT (operator new(0x98, 8) at 0x707928). Two RTTI-less rows:
// primary 0x12bbff0 at [this], secondary 0x12bbfd0 at [this+8] registered in
// extent 0x98 - details: doc/object/Kart/ParamSingletonVt12bbff0.md
class ParamSingletonVt12bbff0 {
 public:
  void* mVtable;       // 0x00 - primary vptr 0x12bbff0 (GOT cell 0x130e610
                       //   holds vptr-0x10 0x12bbfe0)
  void* mSecondary08;  // 0x08 - secondary vptr 0x12bbfd0 (cell 0x130e600);
                       //   also copied into global holder 0x13587c8
  uint8_t m10[0x18];   // 0x10 - unproven (ctor does not touch 0x10..0x27)
  void* mPtr28;        // 0x28 - heap ptr, deleted in D1 0x7079d4
  void* mPtr30;        // 0x30 - heap ptr, deleted in D1
  void* mPtr38;        // 0x38 - heap ptr, deleted in D1
  void* mPtr40;        // 0x40 - heap ptr, deleted in D1
  uint32_t mCount48;   // 0x48 - count paired with array at 0x50 (0 + null)
  uint8_t pad4c[4];    // 0x4c - unproven padding
  void* mArr50;        // 0x50 - array, delete[]'d in D1 (count 0x48 zeroed)
  uint32_t mCount58;   // 0x58 - count paired with array at 0x60 (0 + null)
  uint8_t pad5c[4];    // 0x5c - unproven padding
  void* mArr60;        // 0x60 - array, delete[]'d in D1 (count 0x58 zeroed)
  uint32_t mW68;       // 0x68 - zeroed by ctor
  uint8_t pad6c[4];    // 0x6c - unproven padding
  void* mPtr70;        // 0x70 - zeroed by ctor
  uint8_t pad78[4];    // 0x78 - unproven padding (gap to 0x7c)
  uint32_t mW7c;       // 0x7c - word read from global 0xf6e5f4 (cell
  uint32_t mW80;       // 0x80   0x12fce50); same word again at 0x80
  uint32_t mW84;       // 0x84 - word from global 0xf6e5f4
  uint32_t mW88;       // 0x88 - word from global 0xf6e5f0 (cell 0x12fce10)
  uint8_t mB8c;        // 0x8c - 0
  uint8_t mB8d;        // 0x8d - 1
  uint8_t mB8e;        // 0x8e - 0
  uint8_t pad8f;       // 0x8f - unproven padding
  void* mSelf90;       // 0x90 - set to this by factory 0x707900
};
}  // namespace object
