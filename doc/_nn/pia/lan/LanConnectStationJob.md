# LanConnectStationJob (nn::pia::lan::LanConnectStationJob)

- vptr 0x12dca88 = first slot row; typeinfo 0x12dcad0 at 0x12dca80
  ("N2nn3pia3lan20LanConnectStationJobE", base
  nn::pia::transport::ConnectStationJob, ti 0x12dec80 →
  nn::pia::common::StepSequenceJob 0x12f8d30 → nn::pia::common::Job).
  GOT cell 0x1313400 holds addend 0x12dca78 = vptr-0x10.
- Size 0x130, exact: factory 0x96ce60 — `operator new(0x130)` via 0x568aa0
  (0x96ce84-0x96ce88) then C1 0x974ca4 (0x96ce98).

## Identity

pia LAN station-connection job; LAN override of
nn::pia::transport::ConnectStationJob on the
StepSequenceJob/Job framework. Slot 1 carries the csv-named body
LanConnectStationJob::TryCurrentAddress (0x974d30).

## Member notes

- +0x08..0x4f: base job region, initialized by base C1 0x9a2264 (0x974cb4);
  slot 1 reads +0x1ac (0x974c98).
- +0x50 u64 = 0x0100000000000000 (0x974cd8-0x974cdc).
- +0x80 member subobject (0x38 bytes to next init), C1 0x9b38b8 (0x974ccc).
- +0xb8 member subobject (rest of object), C1 0x9b1fe8 (0x974cd0).

## Construction / init order

- C1 = 0x974ca4: base C1 0x9a2264, vptr from GOT cell 0x1313400 (+0x10),
  subobject C1s at +0x80 and +0xb8, +0x50 store.
- D1 = slot 0, 0x974cec (re-installs vptr, then base tail); D0 = slot 1,
  0x974d30 (csv: LanConnectStationJob::TryCurrentAddress).
- Slots (9): 0=0x974cec (D1), 1=0x974d30 (D0/TryCurrentAddress), 2=0xb4a654,
  3=0xb4a67c, 4=0x933314 (slots 2-4 shared StepSequenceJob stubs), 5=0x974f70,
  6=0x974d7c, 7=0x9a2eb0, 8=0x9a2b98. Slots 5-8 unrecovered.
