#pragma once

#include <cstdint>

namespace nn::pia::local {
// nn::pia::local::LocalMatchBrowseMatchmakeJob — RTTI-named (typeinfo
// 0x12e1a40, name "N2nn3pia5local28LocalMatchBrowseMatchmakeJobE", base
// session::BrowseMatchmakeJob). C2 0x9d14fc.
// extent 0x90 - details: doc/_nn/pia/local/LocalMatchBrowseMatchmakeJob.md
class LocalMatchBrowseMatchmakeJob {
 public:
  void* vtable;      // 0x00 - 0x12e19f8 (GOT cell 0x1314048 + 0x10)
  char pad08[0x50];  // 0x08..0x57 - StepSequenceJob grandbase (base C2
                     //   0xb4a5e0; secondary vptr 0x12db178 at +0x28 —
                     //   overlaps the next field per base layout 0xb4a5e0)
  void* m58;         // 0x58 - BrowseMatchmakeJob base field (base C2 0x97dc58
                     //   zero)
  void* m60;         // 0x60 - C2 arg x1 (context/handle)
  char pad68[0x20];  // 0x68..0x87 - member subobject (ctor 0x929ec0 / D
                     //   0x929ee0)
  void* m88;         // 0x88 - ptr stored by slot 7 (0x9d15b8)
};
}  // namespace nn::pia::local
