#pragma once

#include <cstdint>

namespace nn::pia::nat {
/// RTTI "N2nn3pia3nat15NatDetectionJobE", derives from
/// nn::pia::common::StepSequenceJob. Installed vptr 0x12dbb88.
/// extent 0x90 (ctor field stores; lower bound) - details: doc/_nn/pia/nat/NatDetectionJob.md
struct NatDetectionJob {
  virtual void dtor();          // 0x00 slot0 (0x966bc0, tail `b 0xb4a62c` base D1)
  virtual void dtorDeleting();  // 0x08 slot1 (0x966bc4)
  virtual void slot10();        // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();        // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();        // 0x20 slot4 (0x966d14, releases +0x58/+0x60 subobjects)
  virtual void slot28();        // 0x28 slot5 (0xb4a7a4, `ret` stub)
  uint8_t mBase8[0x50];  // 0x08 - StepSequenceJob base region (base C1 0xb4a5e0)
  void* m58;             // 0x58 - subobject ptr (used by slot4)
  void* m60;             // 0x60 - subobject ptr, zeroed by C2
  uint8_t m68[0x8];      // 0x68 - pad (unverified)
  uint64_t m70;          // 0x70 - zeroed by C2
  uint64_t m78;          // 0x78 - zeroed by C2
  uint64_t m88;          // 0x88 - zeroed by C2 (last store reaches 0x8f)
  uint8_t mPad80[8]; // 0x80 - unproven (extent 0x90 lower bound)
};
}  // namespace nn::pia::nat
