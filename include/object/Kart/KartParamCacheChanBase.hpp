#pragma once

#include <cstdint>

// KartParamCacheChanBase — address-anchored name (vptr 0x12b3af0,
// extent 0x18
namespace object::Kart {
class KartParamCacheChanBase {
 public:
  void* vptr;        // 0x00
  uint32_t mField8;  // 0x08 — ctor arg w0
  uint8_t pad0c[4];  // 0x0c — unproven padding
  void* mZero10;     // 0x10
};
}  // namespace object
