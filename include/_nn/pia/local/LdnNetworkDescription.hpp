#pragma once

#include <cstdint>

namespace nn::pia::local {
// nn::pia::local::LdnNetworkDescription — RTTI-named (typeinfo 0x12e0210,
// name "N2nn3pia5local21LdnNetworkDescriptionE", base
// LocalNetworkDescription). Getter-vtable data carrier.
// extent 0x488 - details: doc/_nn/pia/local/LdnNetworkDescription.md
class LdnNetworkDescription {
 public:
  void* vtable;      // 0x00 - 0x12e01b8 (GOT cell 0x1313d50 + 0x10)
  char pad08[0x48];  // 0x08..0x4f - LocalNetworkDescription base payload
                     //   (start of the 0x480-byte memset; getters read
                     //   +0x50/+0x53/+0x6a/+0x6e/+0x6f ahead)
  char pad50[0x438]; // 0x50..0x487 - rest of the zeroed 0x480-byte payload
};
}  // namespace nn::pia::local
