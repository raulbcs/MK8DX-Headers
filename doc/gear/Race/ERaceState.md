# ERaceState (gear/Race/ERaceState.hpp)

The race state machine value driven by the race-state calc FUN_710039f79c
(target state at RaceStateChecker::mRaceState + 0x3C, the field itself at
+0x38). Observed walk (docs/MECHANICS_101.md, race-system.md):
menu=1 → pre-start=0 → countdown 2→3→4 → GO=5 → Run=6 → finish=7 → exit=8.

ui::Page_Race mirrors it in mSubState: the pause gate 0x710053509c allows
the toggle at GO (5) and blocks it at finish (7). FUN_710087b234 treats
6 (Run) as race-active. Countdown timing runtime-measured: state 3 ≈2.5 s,
state 5 ≈4 s.
