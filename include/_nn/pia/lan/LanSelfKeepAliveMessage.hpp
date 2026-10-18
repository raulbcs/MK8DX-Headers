#pragma once

#include <cstdint>

namespace nn::pia::lan {
/// RTTI "N2nn3pia3lan23LanSelfKeepAliveMessageE", derives from
/// nn::pia::lan::LanMessage (base vptr 0x12dd3e8, RTTI name proven).
/// extent 0x18 (ctor field stores; lower bound) - details: doc/_nn/pia/lan/LanSelfKeepAliveMessage.md
struct LanSelfKeepAliveMessage {
  virtual void slot00();  // 0x00 slot0 (0x97da50, `ret`, shared with LanMessage)
  virtual void slot08();  // 0x08 slot1 (0x97da44, returns 0xc)
  virtual void slot10();  // 0x10 slot2 (0x97d910, serialize-style, reg-x3 payload)
  virtual void slot18();  // 0x18 slot3 (0x97d96c, parse loop over x1 bytes)
  virtual void slot20();  // 0x20 slot4 (0x97da48, `ret`)
  virtual void slot28();  // 0x28 slot5 (0x97cf70, re-installs LanMessage vptr)
  uint32_t m8;         // 0x08 — zeroed then set to 7 by C2
  uint8_t mC[0xb];     // 0x0c — zeroed by C2 memset(this+0xc, 0, 0xb)
  uint8_t mPad17[1];   // 0x17 — unproven (extent 0x18 lower bound)
};
}  // namespace nn::pia::lan
