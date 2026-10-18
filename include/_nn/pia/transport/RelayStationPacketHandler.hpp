#pragma once

#include <cstdint>

namespace nn::pia::transport {
// nn::pia::transport::RelayStationPacketHandler — RTTI-named (typeinfo
// 0x12df0e0, "N2nn3pia9transport25RelayStationPacketHandlerE"); derives from
// StationPacketHandler (base C1 0x71009b4a2c) and adds one tail pointer.
// extent 0x520 - details: doc/_nn/pia/transport/RelayStationPacketHandler.md
class RelayStationPacketHandler : public StationPacketHandler {
 public:
  void* m518;           // 0x518 - relay context pointer: zeroed by the C1,
                        //   stored from arg x6 by slot-3 override 0x71009ab988,
                        //   cleared again by slot-4 trampoline 0x71009ab9d0
};
}  // namespace nn::pia::transport
