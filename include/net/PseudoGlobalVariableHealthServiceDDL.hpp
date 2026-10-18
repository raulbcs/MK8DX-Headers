#pragma once

#include <cstdint>

// PseudoGlobalVariableHealthServiceDDL — RTTI-confirmed nn::nex::PseudoGlobalVariable<nn::nex::HealthServiceDDLDeclarations>.
// vptr 0x12e6868 (GOT cell 0x1314940 holds vptr-0x10; nex typeinfo descriptor 0x12e68b0 at vptr-8).
// extent 0x58 - details: doc/net/PseudoGlobalVariableHealthServiceDDL.md

struct PseudoGlobalVariableHealthServiceDDL {
  uint64_t vptr;           // 0x00 — 0x12e6868, installed inline (0xa32410)
  uint8_t mPad8[0x10];     // 0x08 — unverified (tree-node fields, inserted via 0x58c4d8)
  uint8_t member18[0x20];  // 0x18 — member C1 0xb4ae90, own vptr = *(0x1314ad0)+0x10
  uint8_t member38[0x20];  // 0x38 — same member class; both torn down by D2 0xa29070
};
