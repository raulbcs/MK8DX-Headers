#pragma once

#include <cstdint>

// RaceCheckManager — race-rules/checker singleton.
// Getter getRaceCheckManager_710087fcd0 = *(FUN_71007f7a90() + 0x10).
namespace gear {
namespace Race {
struct RaceCheckManager {
  uint8_t pad00[8];          // 0x00 - 0x07 — unproven padding
  uint32_t raceRule8;        // 0x08 — ERaceRule mirror: 2 = TimeAttack (branches in
                             //        every checker helper); 5 forces water state 2
  uint8_t pad0c[0x1b];       // 0x0C - 0x26 — unproven padding
  uint8_t modeByte27;        // 0x27 — TA mode byte; gates the per-kart +0x48 check
  uint8_t pad28[0x1c];       // 0x28 - 0x43 — unproven padding
  uint8_t kartBlock44[0x98]; // 0x44 - 0xDB — per-kart blocks, stride 0x1C:
                             //        +0x44+idx*0x1C u32 state (== 3 = kart
                             //        finished its race); +0x48+idx*0x1C byte
                             //        gates the TA push (0 -> 0, else 5)
  uint32_t kartListdc[12];   // 0xDC + idx*4 — per-kart u32 list read by the TA calc
  uint8_t pad10c[0x7c];      // 0x10C - 0x187 — unproven padding
  uint32_t modeSel188[6];    // 0x188 + i*4 — mode-select words (== 1 selects LUT
                             //        0xF74440 over 0xF74470 in the TA calc)
  uint8_t pad1a0[8];         // 0x1A0 - 0x1A7 — unproven padding
                             // extent 0x1a8 (TA calc snapshot)
};

// Helper FUN_710087fb60: walks the 12 per-kart words (stride 0x1C) counting
// nonzero — finished-kart census.
}  // namespace Race
}  // namespace gear
