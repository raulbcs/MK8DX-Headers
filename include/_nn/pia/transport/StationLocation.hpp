#pragma once

#include <cstdint>

namespace nn::pia::transport {
// StationLocation — RTTI-named (typeinfo 0x12df418, name
// "N2nn3pia9transport15StationLocationE"). 6 slots; GOT cell 0x1313c50
// holds vptr-0x10 (vptr 0x12df3e8); secondary vptr nn::pia::common::
// StationAddress (0x12d9580) at +0x8.
// extent 0x38 - details: doc/_nn/pia/transport/StationLocation.md
class StationLocation {
 public:
  void* mVtable;          // 0x00 - vptr 0x12df3e8 (cell 0x1313c50 + 0x10)
  uint8_t mBase08[0x28];  // 0x08 - nn::pia::common::StationAddress base
  uint8_t mSub30[0x8];    // 0x30 - member subobject, C1 0x929fd4
};
}  // namespace nn::pia::transport
