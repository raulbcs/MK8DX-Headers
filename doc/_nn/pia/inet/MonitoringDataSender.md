# MonitoringDataSender (nn::pia::inet::MonitoringDataSender)

- RTTI-named: word at 0x12da9b0 is the typeinfo pointer -> embedded pair at
  0x12daa20 = {0x10, name "N2nn3pia4inet20MonitoringDataSenderE"}.
- GOT cell 0x1312b70 holds 0x12da9a8 = vptr-0x10; installed vptr = 0x12da9b8,
  10 function slots at vptr+0x00..+0x48.
- Size 0x150 proven: alloc wrapper FUN_7100932300 does new(0x150) (0x932314,
  alloc 0x568aa0) then C1 FUN_710093a96c (0x932328).

## Identity

pia inet monitoring/telemetry sender. Owns three zero-initialized heap
buffers of 0xb90/0xbd0/0x2730 bytes (alloc via 0x568b00 with nn::os memory
tag arg from 0x563b70), stored at +0x08/+0x10/+0x18 (0x93a9b8-0x93aa60).

## Member notes

- +0x20 u64 = 0x3_00000000 (orr x8, xzr, #0x300000000, C1 0x93a994) — two
  u32 counters/ids, unverified.
- +0x28, +0xa8, +0x13c embedded members initialized by C1s 0x964764,
  0x93b340, 0x929fd4; internal layouts unrecovered.

## Construction / init order

- C1 = FUN_710093a96c (0x93a96c): vptr cell 0x1312b70 (+0x10) at [this];
  +0x20 = 0x300000000; member C1 at +0x28 (0x93a99c); member C1 at +0xa8
  (0x93a9a4); +0x138 = 0; member C1 at +0x13c (0x93a9b0); then the three
  buffer allocations (0x93a9b4-0x93aa60).
- Second tsv site 0x93aad8 (FUN_710093aad8, slot 0) is a reinit/clone ctor:
  re-installs the vptr, frees the old +0x08 buffer (0x568bb0/0x568b64) and
  rebuilds from an existing instance (0x93aaec-0x93ab14).

## Slots (10, at vptr 0x12da9b8..+0x48)

0 = 0x93aad8 (reinit ctor above), 1 = 0x93ab94 (224B), 2 = 0x93abb8 (176B),
3 = 0x93ac68 (200B), 4 = 0x93b318, 5 = 0x93b324, 6 = 0x93b334, 7 = 0x93acf0,
8 = 0x93ad30 (220B), 9 = 0x93b33c. Slot bodies unrecovered in functions.csv;
explicit dtor pair not identified (reinit slot doubles as teardown path).
