# LanMatchBrowseMatchmakeJob (nn::pia::lan::LanMatchBrowseMatchmakeJob)

- vptr 0x12dcc08 = first slot row; typeinfo 0x12dcc50 at 0x12dcc00
  ("N2nn3pia3lan26LanMatchBrowseMatchmakeJobE", base
  nn::pia::session::BrowseMatchmakeJob, ti 0x12dd680 →
  nn::pia::common::StepSequenceJob 0x12f8d30 → nn::pia::common::Job).
  GOT cell 0x1313420 holds addend 0x12dcbf8 = vptr-0x10.
- Size 0x88, exact: factory 0x96d240 — `operator new(0x88)` via 0x568aa0
  (0x96d260-0x96d264) then C1 0x97578c (0x96d274).

## Identity

pia LAN browse-matchmake job; LAN override of
nn::pia::session::BrowseMatchmakeJob. Slots 7/8 carry the csv-named bodies
LanMatchBrowseMatchmakeJob::BrowseMatchmake (0x975838) and
::WaitRequestSessionInfo (0x975a4c).

## Member notes

- +0x08..0x5f: base job region, initialized by base C1 0x97dc58 (0x97579c).
- +0x60 member subobject (0x20 bytes), C1 0x929ec0 (0x9757b4); also touched
  by D1 slot 0 (0x9757d4 re-installs vptr, advances this+0x60, tail
  0x929ee0).
- +0x80 ptr = 0 (0x9757b8).

## Construction / init order

- C1 = 0x97578c: base C1 0x97dc58, vptr from GOT cell 0x1313420 (+0x10),
  subobject C1 at +0x60, +0x80 = 0.
- D1 = slot 0, 0x9757c8; D0 = slot 1, 0x9757fc.
- Slots (9): 0=0x9757c8 (D1), 1=0x9757fc (D0), 2=0xb4a654, 3=0xb4a67c,
  4=0x933314 (slots 2-4 shared StepSequenceJob stubs), 5=0x975bb0, 6=0x975b84,
  7=0x975838 (BrowseMatchmake), 8=0x975a4c (WaitRequestSessionInfo).
  Slots 5/6 unrecovered.
