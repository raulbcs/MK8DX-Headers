#pragma once

#include <cstdint>

namespace nn::pia::lan {
// nn::pia::lan::LanInputStream — RTTI-named (typeinfo slot 0x12de190 ->
// 0x12de220, "N2nn3pia3lan14LanInputStreamE"). vptr 0x12de198 (GOT cell
// 0x13138f8 holds 0x12de188 = vt-0x10).
// extent 0xf8 (lower bound; unverified) - details: doc/_nn/pia/lan/LanInputStream.md
class LanInputStream {
 public:
  void* vtable;      // 0x00 - 0x12de198 (cell 0x13138f8 + 0x10)
  char pad08[0x20];  // 0x08..0x27 - common nn base (base ctor 0x7100567cb8),
                     //   unproven
  void* m28;         // 0x28 - base subobject vptr 0x12db168 (ctor 0x7100b4a5e0)
  void* m30;         // 0x30 - base ctor zero
  void* m38;         // 0x38 - base ctor zero
  void* m40;         // 0x40 - base ctor zero
  uint8_t m48;       // 0x48 - base ctor zero (bool)
  char pad49[0x07];     // pad - unproven gap
  void* m50;         // 0x50 - base ctor zero; base ends at 0x58
  void* m58;         // 0x58 - C2 zero
  uint32_t m60;      // 0x60 - C2 sets 0x2710 (10000)
  char pad64[0x04];     // pad - unproven gap
  void* m68;         // 0x68 - C2 zero
  void* m70;         // 0x70 - C2 zero
  void* m78;         // 0x78 - C2 zero
  uint32_t m80;      // 0x80 - C2 zero
  char pad84[0x03];  // 0x84 - C2 zero (u16)
  char pad87[0x02];  // 0x87 - C2 zero (u16, sturh)
  char pad89[0x03];     // pad - unproven gap
  uint32_t m8c;      // 0x8c - C2 stores ctor arg w20
  void* m90;         // 0x90 - C2 zero
  char pad98[0x38];  // 0x98..0xcf - ctor arg word at +0x98; gap unproven
  uint16_t mD0;      // 0xd0 - C2 zero (u16)
  uint8_t mD2;       // 0xd2 - C2 zero (u8)
  char padD3;        // pad - unproven gap
  uint8_t mD4;       // 0xd4 - C2 sets (platform == 2), via global 0x1312748
  char padD5[0x20];  // 0xd5..0xf4 - memset(w20, 0x20); last store
  char padF5[0x03];  // 0xf5..0xf7 - pad to lower-bound size 0xf8
};
}  // namespace nn::pia::lan
