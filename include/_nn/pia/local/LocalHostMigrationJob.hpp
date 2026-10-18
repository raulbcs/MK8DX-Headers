#pragma once

#include <cstdint>

// nn::pia::local::LocalHostMigrationJob — RTTI-confirmed (descriptor 0x12e18f0,
// name N2nn3pia5local30LocalHostMigrationJobE, shared pia/nex job base 0x12f8d30).
// vptr 0x12e1888 = tsv row + 8. extent 0x88 - details: doc/_nn/pia/local/LocalHostMigrationJob.md
namespace nn::pia::local {
class LocalHostMigrationJob {
 public:
  void* mVtable;         // 0x00 — 0x12e1888 (GOT cell 0x1313ff0 = vptr-0x10)
  char mJobBase8[0x50];  // 0x08 — shared base C1 0xb4a5e0 region (unproven gap)
  void* m58;             // 0x58 — 0 (0x9cfaec)
  void* m60;             // 0x60 — sub-object: new(0x20) 0x568aa0, ctor 0x929ec0
  uint8_t m68;           // 0x68 — 0 (0x9cfaf8)
  char mPad69[0x7];      // 0x69 — unproven
  void* m70;             // 0x70 — 0 (0x9cfafc)
  void* m78;             // 0x78 — C1 x1 arg (0x9cfafc)
  void* m80;             // 0x80 — 0 (0x9cfb08)
};
}  // namespace nn::pia::local
