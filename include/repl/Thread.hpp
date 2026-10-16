#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace repl {
// Thread — nn::ae::AppletThread subclass; vptr 0x12c5478 (cell 0x130fe68,
// n=18); ctor 0x7b6d40; sole alloc 0x7b5c00 (new 0x108). Sibling
// SZSThread same shape.
class Thread : public nn::ae::AppletThread {
 public:
  void* mTargetF8;    // 0xf8 — ctor arg; endpoint of the slot-0x30 teardown vcall
  uint8_t mFlag100;   // 0x100 — ctor zero; set 1 after the first request
  uint8_t mFlag101;   // 0x101 — ctor zero; request-pending gate
  uint8_t mFlag102;   // 0x102 — ctor zero; teardown-pending gate
  uint8_t pad103[5];  // 0x103 — to alloc size
                      // (0x108 total)
  // extent 0x108 (prior-survey total 0x108)
};
}  // namespace repl
