#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"
#include "_nn/ae/ControllerAppletThread.hpp"
#include "_nn/ae/ErrorAppletThread.hpp"
#include "_nn/ae/KeyboardAppletThread.hpp"
#include "_nn/ae/MiiEditAppletThread.hpp"
#include "_nn/ae/NifmAppletThread.hpp"
#include "_nn/ae/NSAAppletThread.hpp"
#include "_nn/ae/OfflineWebAppletThread.hpp"

// AppletThreadHost — PROVISIONAL name; vtable 0x12d02c8 (cell 0x1310fb0);
// ctor 0x7100872004 (base 0x71007b976c) builds 7 in-place applet threads;
// sole site 0x8bca3c; extent >= 0xda0.

namespace nn::err {
// fwd — SDK type, no header in nnheaders vendor; ctor C1 via plt
// (host 0x872004 site 0x872240); size unverified.
struct ErrorResultVariant;
}  // namespace nn::err

namespace nn::ae {
class AppletThreadHost {
 public:
  void* vptr;                             // 0x00
  uint8_t pad08[0x30];                    // 0x08 — base 0x71007b976c region
  ControllerAppletThread mController38;   // 0x38 "ControllerAppletThread" (0x318)
  KeyboardAppletThread mKeyboard350;      // 0x350 "KeyboardAppletThread" (0x548)
  OfflineWebAppletThread mOfflineWeb898;  // 0x898 "OfflineWebAppletThread" (0xf8)
  MiiEditAppletThread mMiiEdit990;        // 0x990 "MiiEditAppletThread" (0x100)
  ErrorAppletThread mErrorA90;            // 0xa90 "ErrorAppletThread" (0xfc)
  void* mZeroB8c;                         // 0xb8c
  nn::err::ErrorResultVariant* mErrB94;   // 0xb94 — ErrorResultVariant C1'd IN PLACE here (0x872240); modelled as ptr placeholder, size unverified
  uint32_t mZeroBa0;                      // 0xba0
  uint8_t padBa4[4];                      // 0xba4 — unproven padding
  NifmAppletThread mNifmBa8;              // 0xba8 "NifmAppletThread" (0x100)
  NSAAppletThread mNsaCa8;                // 0xca8 "NSAAppletThread" (0xf8)
  // (extent >= 0xda0, tail unmapped)
};
}  // namespace nn::ae
