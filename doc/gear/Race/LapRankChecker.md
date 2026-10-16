# LapRankChecker (gear::LapRankChecker)

Global per-race lap state. RaceKartChecker::calc compares the kart lap counter against mLapTotal (byte at +0x64).

A recorder channel named "LapRankChecker" (rodata 0xf0ccf0) is created by the race-checker init 0x710087ffd0 for it (channel subclass vtable .data 0x12d0f60, base slots 0x71007ab904/0x71007abca8/0x71007ac1d8 in the recorder region).

## Fields

- 0x00..0x63 — unproven: the enclosing RaceKartChecker ctor is not yet located (no RTTI, stripped binary); extent fixed by the proven mLapTotal byte at 0x64 (compared by RaceKartChecker::calc).
- 0x64 mLapTotal.

## Construction / init order

Enclosing ctor not located (no RTTI, stripped binary) — no proven construction sequence. Recorder channel created by race-checker init 0x710087ffd0.

## Methods

- adaptCurrentSector(int, bool).
