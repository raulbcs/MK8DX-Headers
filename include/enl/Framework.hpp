#pragma once

#include <cstdint>

#include "SendManager.hpp"
#include "TransportManager.hpp"
#include "Peer/PeerManagerCommon.hpp"

namespace enl {
class Framework {
 public:
  static inline Framework* sInstance;

  // Unproven — Switch ctor not identified (no RTTI, stripped binary);
  // extent fixed by mPeerManager at 0x28.
  uint8_t mPad00[0x28];                 // unproven - extent fixed by mPeerManager at 0x28
  PeerManagerCommon* mPeerManager;      // 0x28
  uintptr_t mPad30;                     // 0x30 — unproven padding
  TransportManager* mTransportManager;  // 0x38
  SendManager* mSendManager;            // 0x40
};
}  // namespace enl
