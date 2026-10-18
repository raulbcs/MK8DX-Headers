#pragma once

#include <cstdint>

namespace nn::pia::local {
// nn::pia::local::LocalMatchMeshLayerController — RTTI-named (typeinfo
// 0x12e1d90, "N2nn3pia5local29LocalMatchMeshLayerControllerE"); derived from
// nn::pia::session::MeshLayerController (base C1 0x710098b06c).
// extent 0x2b0 - details: doc/_nn/pia/local/LocalMatchMeshLayerController.md
class LocalMatchMeshLayerController {
 public:
  void* vtable;         // 0x00 - primary vptr 0x12e1cd8 (cell 0x1313db8 + 0x10);
                        //   cell holds 0x12e1cc8 = vptr-0x10
  void* vtable08;       // 0x08 - secondary base vptr 0x12d7ec8 (cell 0x13123d8
                        //   + 0x10, no RTTI name); installed by base C1
  char pad10[0x298];    // 0x10..0x2a7 - base state; +0x10 self-ptr to the
                        //   +0x24 entry head; entries zeroed by base C1 loops
  void* m2a8;           // 0x2a8 - global manager pointer loaded from cell
                        //   0x1312638 (data 0x7101312638) by the factory
};
}  // namespace nn::pia::local
