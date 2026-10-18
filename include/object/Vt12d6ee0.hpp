#pragma once

#include <cstdint>

// Vt12d6ee0 (size 0x98) — subclass of Vt12bfd58; PROVISIONAL name. Ctor
// 0x8f1128 runs base ctor 0x742048 then overwrites +0x00 with 0x12d6ee0;
// overrides slots 0/2/18/23. new(0x98) at 0x8f11c4.
// extent 0x98 - details: doc/object/Vt12d6ee0.md

struct Vt12d6ee0 {
  uint8_t data[0x98];                    //0x00 — layout identical to Vt12bfd58 (see doc)
};
