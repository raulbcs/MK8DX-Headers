# gear::ControllerRaceNX

Unproven — Switch ctor not identified (no RTTI, stripped binary); extent fixed by mController at 0x158. The //0x144 comment in the header is a Wii U (32-bit) relic.

## Member layout

- 0x00 — 0x144 — unproven padding
- 0x144 — mController (sead::Controller*)
- 0x14C — 0x158 — unproven padding

Global: ControllerRaceNX* GetControllerRace(int).
