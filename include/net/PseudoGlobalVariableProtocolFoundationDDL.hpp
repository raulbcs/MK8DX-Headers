#pragma once

#include <cstdint>

// PseudoGlobalVariableProtocolFoundationDDL — RTTI-confirmed nn::nex::PseudoGlobalVariable<nn::nex::ProtocolFoundationDDLDeclarations>.
// vptr 0x12e6948 (GOT cell 0x13149c8 holds vptr-0x10; nex typeinfo descriptor 0x12e6990 at vptr-8).
// extent 0x58 - details: doc/net/PseudoGlobalVariableProtocolFoundationDDL.md

struct PseudoGlobalVariableProtocolFoundationDDL {
  uint64_t vptr;           // 0x00 — 0x12e6948, installed inline (0xa32580 region)
  uint8_t mPad8[0x10];     // 0x08 — unverified (tree-node fields, inserted via 0x58c4d8)
  uint8_t member18[0x20];  // 0x18 — member C1 0xb4ae90
  uint8_t member38[0x20];  // 0x38 — same member class; both torn down by D2 0xa2c458
};
