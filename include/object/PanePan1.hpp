#pragma once

#include <cstdint>

// PanePan1 - pane created for the "pan1" pane tag (factory 0x743198); vptr
// 0x12bf990; carries child pointers, a ref-counted pair at +0xf0 and
// subobjects at +0x110 / +0x178. Ctor 0x73fc50.
// extent 0x360 - details: doc/object/PanePan1.md

namespace object {
class PanePan1 {
 public:
  void* vtable;      // 0x00 - 0x12bf990 (C1 0x73fc50 at 0x73fc90)
  uint8_t pad_08[0xd2];   // 0x08 - 0xD9 - base ctor 0x5a22e4 region - unproven
  uint16_t fieldDA;  // 0xda - u16, init 0x100 (0x73fc78)
  uint8_t pad_DC[0x4];    // 0xdc - unproven
  void* ptrE0;       // 0xe0 - init 0; freed by D1 (0x74087c..0x740890)
  void* ptrE8;       // 0xe8 - init 0; child destroyed via [vt+8] by D1 (0x740894..0x7408a8)
  void* vfptrF0;     // 0xf0 - pair: vptr cell 0x1308f98+0x10 (0x73fca0)
  uint64_t fieldF8;  // 0xf8 - pair: init -1 (0x73fc94..0x73fca0)
  uint32_t field100; // 0x100 - init 0 (0x73fc84)
  uint8_t pad_104[0x4];    // 0x104 - 0x107 - unproven
  void* ptr108;      // 0x108 - subobject, freed by D1 (0x7408bc..0x7408d0)
  uint8_t pad_110[0x238]; // 0x110 - 0x347 - subobject ctors 0x63ecbc (+0x110), 0x63f778 (+0x178) - unproven
  void* ptr348;      // 0x348 - init 0; torn down by 0x6373a4 in D1 (0x7408ac..0x7408b8)
  uint32_t field350; // 0x350 - init 0 (0x73fcb4)
  uint8_t pad_354[0x4];    // 0x354 - 0x357 - unproven
  void* ptr358;      // 0x358 - init 0 (0x73fcbc)
};
}  // namespace object
