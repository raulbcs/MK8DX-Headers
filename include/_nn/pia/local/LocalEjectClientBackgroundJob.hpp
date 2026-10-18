#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalEjectClientBackgroundJob — RTTI-named (typeinfo 0x12e2260, name
// "N2nn3pia5local29LocalEjectClientBackgroundJobE"; base nn::pia common
// StepSequenceJob, ti 0x12f8d30). 6 slots; GOT cell 0x1314170 holds vptr-0x10
// extent 0x78 - details: doc/_nn/pia/local/LocalEjectClientBackgroundJob.md
class LocalEjectClientBackgroundJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e2228 (cell 0x1314170 + 0x10)
  uint8_t mBase08[0x50]; // 0x08 - StepSequenceJob base region (base C1 0xb4a5e0, covers 0x08-0x58)
  void* mPtr58;          // 0x58 - inner job ptr, zeroed by C2 0x9d4850; polled by cancel helper 0x9d4804 (checks u32==1 at [ptr], cmd 0x6c05)
  void* mSubVtable60;    // 0x60 - member subobject vptr 0x12d9580 (StationAddress family, cell 0x1312438 + 0x10); C2 builds via 0x92a1e0(this+0x60)
  uint64_t mSub68;       // 0x68 - member data, destroyed by D0/D1 via 0x92a014(this+0x68)
  void* mPtr70;          // 0x70 - C2 arg x1 (factory passes heap handle)
  };
}  // namespace nn::pia::local
