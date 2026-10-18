#pragma once

#include <cstdint>

namespace nn::pia::transport {
// nn::pia::transport::StationConnectionInfo — RTTI-named (typeinfo 0x12df3c8,
// name "N2nn3pia9transport21StationConnectionInfoE", no base). D2 0x9b20b4.
// extent 0x78 - details: doc/_nn/pia/transport/StationConnectionInfo.md
class StationConnectionInfo {
 public:
  void* vtable;      // 0x00 - 0x12df380 (GOT cell 0x1313c40 + 0x10)
  char pad08[0x38];  // 0x08..0x3f - member A (ctor 0x9b38b8 / D 0x9b3a40 /
                     //   copy 0x9b39bc): own vptr 0x12df3e8 (cell 0x1313c50 +
                     //   0x10), member at +0x30 (ctor 0x929fd4), flags
                     //   +0x28..+0x2e zeroed by the ctor
  char pad40[0x38];  // 0x40..0x77 - member B, same 0x38 type as member A
};
}  // namespace nn::pia::transport
