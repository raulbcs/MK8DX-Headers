#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::NexMatchMeshLayerController — RTTI-named (typeinfo 0x12db290,
// "N2nn3pia4inet27NexMatchMeshLayerControllerE"); derived from
// nn::pia::session::MeshLayerController (base C1 0x710098b06c).
// extent 0x2e0 - details: doc/_nn/pia/inet/NexMatchMeshLayerController.md
class NexMatchMeshLayerController {
 public:
  void* vtable;         // 0x00 - primary vptr 0x12db1b0 (cell 0x1313070 + 0x10);
                        //   cell holds 0x12db1a0 = vptr-0x10
  void* vtable08;       // 0x08 - secondary base vptr 0x12d7ec8 (cell 0x13123d8
                        //   + 0x10, no RTTI name); installed by base C1
  char pad10[0x298];    // 0x10..0x2a7 - base state; +0x10 self-ptr to the
                        //   +0x24 entry head; entries zeroed by base C1 loops
  uint64_t m2a8;        // 0x2a8 - ctor zero (str xzr)
  char pad2b0[0x28];    // 0x2b0..0x2d7 - unproven
  void* m2d8;           // 0x2d8 - new 0x1958 subobject (ctor 0x7100950408),
                        //   torn down by the deleting dtor 0x710094ebd4
};
}  // namespace nn::pia::inet
