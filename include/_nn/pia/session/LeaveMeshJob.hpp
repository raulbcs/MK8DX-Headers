#pragma once

#include <cstdint>

namespace nn::pia::session {
/// RTTI "N2nn3pia7session12LeaveMeshJobE", derives from
/// nn::pia::common::StepSequenceJob (base typeinfo 0x12f8d30, base C1 0xb4a5e0).
/// extent 0x80 (proven: factory operator new 0x80 at 0x96cf64) - details: doc/_nn/pia/session/LeaveMeshJob.md
struct LeaveMeshJob {
  virtual void dtor();          // 0x00 slot0 (0x984ab4, tail `b 0xb4a62c` base D1)
  virtual void dtorDeleting();  // 0x08 slot1 (0x984ab8, D1 -> operator delete)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x933314)
  virtual void slot28();        // 0x28 slot5 (0x98505c, reset: re-runs base C1 0xb4a5e0)
  uint8_t mBase8[0x50];  // 0x08 — StepSequenceJob base region (base C1 0xb4a5e0)
  void* m58;             // 0x58 — zeroed by C2
  uint32_t m60;          // 0x60 — C2 stores 5000 (0x1388)
  uint8_t mPad64[4];     // 0x64 — ctor writes nothing
  uint64_t m68;          // 0x68 — zeroed by C2
  uint64_t m70;          // 0x70 — zeroed by C2
  uint8_t m78;           // 0x78 — zeroed by C2
  uint8_t mPad79[7];     // 0x79 — unproven (allocator padding, extent 0x80)
};
}  // namespace nn::pia::session
