#pragma once

#include <cstdint>

namespace nn::pia::transport {
// nn::pia::transport::ConnectStationJob — RTTI-named (typeinfo 0x12dec80, name
// "N2nn3pia9transport17ConnectStationJobE", base StepSequenceJob). C2 0x9a2264.
// extent 0x80 - details: doc/_nn/pia/transport/ConnectStationJob.md
class ConnectStationJob {
 public:
  void* vtable;      // 0x00 - 0x12dec38 (GOT cell 0x1313ac8 + 0x10)
  char pad08[0x50];  // 0x08..0x57 - StepSequenceJob base subobject (base C2
                     //   0xb4a5e0; base vptr cell 0x13150f70; secondary vptr
                     //   0x12db178 = cell 0x1313040 + 0x10 at +0x28)
  void* m58;         // 0x58 - ctor zero
  char pad60[0x18];  // 0x60..0x77 - 0x60 = 0x2710 (10000), 0x64 zero,\n                     //   0x68..0x79 zeroed by ctor
  char pad78[0x08];  // 0x78..0x7f - ctor zero (byte 0x79)
};
}  // namespace nn::pia::transport
