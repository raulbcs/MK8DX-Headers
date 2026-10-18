#pragma once

#include <cstdint>

namespace nn::pia::transport {
// nn::pia::transport::StationPacketHandler — RTTI-named (typeinfo 0x12df530,
// "N2nn3pia9transport20StationPacketHandlerE"); derived from
// nn::pia::transport::PacketHandler (base C1 0x71009a5700).
// extent 0x518 - details: doc/_nn/pia/transport/StationPacketHandler.md
class StationPacketHandler {
 public:
  void* vtable;         // 0x00 - primary vptr 0x12df470 (cell 0x1313c68 + 0x10);
                        //   cell holds 0x12df460 = vptr-0x10
  char pad08[0x10];     // 0x08..0x17 - base PacketHandler fields ([this+0x10]
                        //   zeroed by base C1)
  char pad18[0x4e8];    // 0x18..0x4ff - base state: +0x18 subobject (ctor
                        //   0x71009a89e0), +0x418 subobject (ctor 0x71009a859c),
                        //   +0x490 self-ptr, +0x4d0..0x4e0 zeroed
  char pad500[0x08];    // 0x500 - subobject initialized by C1 (0x71009bb5c0),
                        //   torn down first by the D-tors
  char pad508[0x10];    // 0x508 - subobject initialized by C1 (0x71009bb530
                        //   family), torn down before +0x500
};
}  // namespace nn::pia::transport
