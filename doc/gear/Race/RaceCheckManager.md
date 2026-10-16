# RaceCheckManager (gear::Race::RaceCheckManager)

Race-rules/checker singleton. Getter getRaceCheckManager_710087fcd0 = *(FUN_71007f7a90() + 0x10).

Helper FUN_710087fb60: walks the 12 per-kart words (stride 0x1C) counting nonzero — finished-kart census.

## Fields

- 0x00-0x07 — unproven padding.
- 0x08 raceRule8 — ERaceRule mirror: 2 = TimeAttack (branches in every checker helper); 5 forces water state 2.
- 0x0C-0x26 — unproven padding.
- 0x27 modeByte27 — TA mode byte; gates the per-kart +0x48 check.
- 0x28-0x43 — unproven padding.
- 0x44-0xDB kartBlock44 — per-kart blocks, stride 0x1C: +0x44+idx*0x1C u32 state (== 3 = kart finished its race); +0x48+idx*0x1C byte gates the TA push (0 -> 0, else 5).
- 0xDC kartListdc[12] — 0xDC + idx*4, per-kart u32 list read by the TA calc.
- 0x10C-0x187 — unproven padding.
- 0x188 modeSel188[6] — 0x188 + i*4, mode-select words (== 1 selects LUT 0xF74440 over 0xF74470 in the TA calc).
- 0x1A0-0x1A7 — unproven padding. Extent 0x1a8 (TA calc snapshot).

## Construction / init order

No ctor identified in this unit; the only proven writer evidence is the TA calc snapshot fixing extent 0x1a8 and the getter *(FUN_71007f7a90() + 0x10).
