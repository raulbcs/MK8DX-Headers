# Vt12dff50

PLACEHOLDER name (address-anchored). Large local-communications manager
object: the preceding static initializer FUN_71009becb4 fills nn::ldn IPv4
globals via nn::ldn::MakeIpv4Address (PLT 0xb52760), and the deleting
destructor sits next to LocalProcessHostMigrationJobNew functions
(FUN_71009c43e0 / FUN_71009c495c). Table row 0x12dff50 is the typeinfo slot:
offset-to-top 2 at 0x12dff48, typeinfo 0x12e0190 at 0x12dff50; the installed
vptr is 0x12dff58.

- Identity: no RTTI name, no owned string. Name stays PLACEHOLDER.
- Extent 0x82e0: caller FUN at 0x71009be25c requests a 0x82e0 buffer from a
  pool (global at cell 0x13125e0-held pointer + 0x10, guarded by a flag byte
  at +0x38) and passes it to the ctor (0x71009be25c..0x71009be26c).
- Ctor FUN_71009bed44: first calls FUN_71009c4c88 (initializes the low
  region), zeroes +0x15e0..+0x1608, installs vptr 0x12dff58 (GOT cell
  0x1313d38 holds 0x12dff48; 0x71009bed5c..0x71009bed70), initializes a
  container at +0x1610 with FUN_7100567ca0(-1) (0x71009bed74..0x71009bed94),
  zeroes u32 +0x8230 (0x71009bed98), initializes a second container at +0x8238
  with FUN_7100567ca0(-1) (0x71009beda0..0x71009bedac), zeroes byte +0x8258
  (0x71009bedb0), then registers this into global registry structures: call
  FUN_71009c315c with the holder at cell 0x1312638 (0x71009bedb8..0x71009bedc8)
  and slots +8/+0x10 of the holder at cell 0x13133c0 via FUN_71009c377c /
  FUN_71009c4218 (0x71009bedcc..0x71009bedf8).
- Deleting destructor FUN_71009b20ec (Vt12dff50 slot for D0 path): reinstalls
  the vptr, destroys two same-type members at +0x8 and +0x40 whose destructor
  is FUN_71009b3a40 (that member class installs vptr *0x1313c50 + 0x10 and a
  secondary vptr *0x1312438 + 0x10 at its +0x8, and has a member destructor
  FUN_710092a014 at its +0x30), then operator-deletes (0x71009b20ec..
  0x71009b212c).
- D1 FUN_71009bedfc (slot 0) tears down the 0x13133c0 registrations
  (0x71009bee20..0x71009bee48) before the base path.

## Construction / init order

1. Pool buffer 0x82e0 acquired by the caller (0x71009be25c..0x71009be26c).
2. Ctor FUN_71009bed44: FUN_71009c4c88; zero +0x15e0..+0x1608; vptr 0x12dff58;
   containers +0x1610 / +0x8238; zero +0x8230 / +0x8258; registry
   registrations (addresses above, in ascending order).
