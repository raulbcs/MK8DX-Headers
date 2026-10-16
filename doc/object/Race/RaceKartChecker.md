# object::RaceKartChecker

One instance per kart. Vtable .data 0x12d0c48 (GOT cell 0x13110d0); ctor 0x710087ffd0 (allocation 0xb8 at 0x3a2008/0x87e2e0/0x87e354: operator new[](0xb8, nothrow)). Recorder channel "RaceKartChecker" (rodata 0xf0cccc) — the ctor builds the 0x280 recorder::Binder channel object and stores it at +0x90.

Vtable: 0x20 0x710007a26c  0x28 0x71008814fc (enter fwd)  0x30 0x7100881508 (calc fwd)  0x70 0x71008802f4 (enter body)  0xb8 0x7100881514 (calc body).

## Behavior

- enter tail-jumps slot 0x70 (0x71008802f4): resets 0x3c-0x50 and stamps time records at 0x48 and 0x54-0x74.
- calc tail-jumps slot 0xb8 (0x7100881514): walks the race-info singleton ([+0x190]->[+0x58]: count@0x40, base@0x48, stride 0x78, lapTotal byte@0x64) by kart index; mLap is compared to lapTotal.

## TimeRecord

{u32 id, u8 minutes, u8 seconds, u16 millis}, built by 0x7100888c30 (explicit) / 0x7100888c70 (from millis; writes the {min, sec, ms} tail at +4). The ctor stamps record 0 at 0x48 and the seven records of mTime with (9, 59, 999); the id word is left to enter. NOTE: records start at 0x54 (4 mod 8) — 4-byte aligned, NOT uint64_t.

## Calc body

Calc body 0x7100881514 (slot 0xB8): tail-jumps slot 0xC0 (FUN_710088214c, the TA/finished calc) when RaceCheckManager+8 == 2 (TimeAttack) or per-kart state kartState44[idx] == 3. Otherwise the walk runs (skip when +0x3C bit2 or byte +0x99 == 0): new lap number = signed byte entry+0x28; time from FUN_710088453c/FUN_7100888c70, accumulated by FUN_7100888cc4; when mLap >= lapTotal the final record comes from [entry+0xE0] -> +0x40. The lap byte entry+0x28 is maintained mode-independently:

- increment FUN_710088434c (wrap at 0x7f -> 0x80 - lapTotal; finish flags entry+0x12 bit8 + entry-owner+0x66); callers FUN_7100884184 (event/state; decrement case max(0, lap-1)) and FUN_7100885118 (lap-line crossing, point-in-area test).
- force-set FUN_71008844b0 (clamps <= -2 to -1, float at entry+0x20).

TA calc (slot 0xC0): slot 0xD8 increments +0xD8 saturating at 98; w20 = 0/5 from kartState byte +0x48 (modeByte27 != 0) else base kartListdc[idx] + LUT 0xF74440/0xF74470 by modeSel188; pushes into the ring +0xC4 (count +0xC0, max 6); notifies the director via container(idx 7)+0x2A8 -> vtable slot 0x1F8.

mCoinNum chain (runtime-verified): RaceSystem+0x1B0 -> +0x218 -> +0x68 -> idx*8 -> +0x50; live mirror at KartVehicle+0x184.

## Construction / init order

1. Allocation 0x3a2008 / 0x87e2e0 / 0x87e354: operator new[](0xb8, nothrow).
2. Ctor 0x710087ffd0: zeroed fields per header (0x3c, 0x40 = 1, 0x50, 0x8c, 0x98/0x99); stamps time record 0 at 0x48 and mTime[7] records 1..7 with (9, 59, 999); builds the 0x280 recorder::Binder channel (rodata name "RaceKartChecker" 0xf0cccc) and stores it at +0x90.
3. enter (slot 0x70, body 0x71008802f4): resets 0x3c-0x50, stamps time records at 0x48 and 0x54-0x74.
