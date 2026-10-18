#pragma once

#include <cstdint>

// Vt12c9828 - PLACEHOLDER name; named-subsystem engine sibling of
// Vt12c9268/CameraEngine/MiiEngine (shares slots 0x6108b0/0x610930/0x612ddc/
// 0x74828). 7+ container members (+0x250..+0x638); secondary ptrs at +0x548
// and +0x610 come from row 0x11ad240 (GOT cell 0x12fae68 + 0x10).
// extent 0x640 (lower bound) - details: doc/object/Vt12c9828.md

namespace object {
class Vt12c9828 {
 public:
  void* vtable;              // 0x00 - 0x12c9828 (D2 0x71003d69d8 / D1
                             // 0x71007f68c8; GOT cell 0x13080e0 holds
                             // 0x12c9818 = vt-0x10)
  char mPad08[0x248];        // 0x08 - unproven
  char mSub250[0x98];        // 0x250 - member (ctor 0x71006126d4 + 0x71006156b4)
  char mSub2e8[0x98];        // 0x2e8 - member (same ctor pair)
  char mSub380[0x98];        // 0x380 - member (same ctor pair)
  char mSub418[0x98];        // 0x418 - member (same ctor pair)
  char mSub4b0[0x98];        // 0x4b0 - member; +0x4b0 gets its own vptr from
                             // GOT cell 0x1307110 + 0x10 (0x71003d6a20)
  void* mPtr548;             // 0x548 - row 0x11ad240 + 0x10 (0x71003d6a18)
  char mSub550[0x20];        // 0x550 - unproven (0x98-byte member region)
  char mSub570[0x98];        // 0x570 - member (ctor 0x71006287b4)
  void* mPtr608;             // 0x608 - unproven
  void* mPtr610;             // 0x610 - row 0x11ad240 + 0x10 (0x71003d6a0c)
  char mSub618[0x20];        // 0x618 - unproven (0x98-byte member region)
  char mSub638[0x8];         // 0x638 - member tail (ctor 0x71006287b4)
};
}  // namespace object
