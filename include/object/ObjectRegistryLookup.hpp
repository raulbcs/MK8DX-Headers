#pragma once

#include <cstdint>

namespace object {
// Object-registry bulk (re)registration and name lookups over the global
// registry manager (mgr = *(cell 0x7101309218)). Docblock facts.

// Stage-table entry shared by the name lookups (PROVADO: 0xc stride reads in
// FUN_710063ff98 at table+0x3c and FUN_710063fb98 at table+0x30 — different
// table objects, same entry shape) — extent 0xc.
struct RegistryStageTableEntry {
    char* name;               // 0x00 const char*
    uint32_t id;              // 0x08
};
// Entry stride is 0xc (C++ sizeof would pad to 0x10; binary layout ends at +0xc).

// FUN_710063d324 (0x710063d324) — bulk re-registration; table from
// FUN_710063d570(this), BinaryBlockHeader block at [t+0x30]; groups at
// [this+0x28] stride 0x78, entries stride 0xb8, sub-entries +0x90 stride 0x78.
// FUN_710063fb98 (0x710063fb98) — three-stage name lookup with tree-walk
// fallback (cell 0x71012fada8 delim, cap 0x108000).
// FUN_710063ff98 (0x710063ff98) — three-slot name lookup; any miss -> 0xff.
// FUN_71006327a8 (0x71006327a8) — masked multi-object dispatch + registry
// push at [self+0x90] (idx [self+0x98], bound [self+0x88]).
// NOTE: OPEN — medium confidence on the FUN_710063fb98 fused byte-scan.
}  // namespace object
