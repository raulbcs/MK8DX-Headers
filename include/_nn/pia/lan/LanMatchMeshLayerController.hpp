#pragma once

#include <cstdint>

namespace nn::pia::lan {
// nn::pia::lan::LanMatchMeshLayerController — RTTI-named (typeinfo 0x12dd090,
// "N2nn3pia3lan27LanMatchMeshLayerControllerE"); derived from
// nn::pia::session::MeshLayerController (base C1 0x710098b06c).
// extent 0x2b8 - details: doc/_nn/pia/lan/LanMatchMeshLayerController.md
class LanMatchMeshLayerController {
 public:
  void* vtable;         // 0x00 - primary vptr 0x12dcfd8 (cell 0x13135c8 + 0x10);
                        //   cell holds 0x12dcfc8 = vptr-0x10
  void* vtable08;       // 0x08 - secondary base vptr 0x12d7ec8 (cell 0x13123d8
                        //   + 0x10, no RTTI name); installed by base C1
  char pad10[0x298];    // 0x10..0x2a7 - base state; +0x10 self-ptr to the
                        //   +0x24 entry head; entries zeroed by base C1 loops
  uint64_t m2a8;        // 0x2a8 - ctor zero (str xzr)
  char pad2b0[0x08];    // 0x2b0..0x2b7 - tail slack to the 0x2b8 allocation
};
}  // namespace nn::pia::lan
