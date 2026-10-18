# MonitoringDataProtocol (nn::pia::inet::MonitoringDataProtocol)

- vptr 0x12db9a8 = first slot row; offset-to-top 0 at 0x12db998, typeinfo
  0x12dba00 at 0x12db9a0 ("N2nn3pia4inet22MonitoringDataProtocolE"). GOT cell
  0x13131f0 holds addend 0x12db998 = vptr-0x10.
- Size 0x20: C1 adds no fields to the abstract protocol base (base object is
  0x20 — base C1 0x9a79c8 only touches +0x00..+0x1a and D1 0x9a79f0 is `ret`
  beyond the vptr swap). No standalone factory found; instances are created
  through the protocol registry path (unverified).

## Identity

pia inet protocol handling "monitoring data" (one of the ~10 protocol classes
whose C1s call base C1 0x9a79c8; cf. nn::pia::nat::NatTraversalProtocol,
vt 0x12dbe50, which derives from the same base and grows it to 0xe78).

Registered at startup in the protocol descriptor map: stack-built node
{0x128d9f8, vptr-0x10 (cell 0x13131f0), 0, name string 0xed6af8} passed to
0x588f4c (0x903370-0x9033a4); node allocation twin at 0x90d3ac region for
NatTraversalProtocol.

## Member notes

- +0x18 u16: protocol max payload, copied from the u16 at cell 0x1313b98 by
  base C1 (0x9a79e4-0x9a79ec).

## Construction / init order

- C1 = 0x964628 (base C1 0x9a79c8, then vptr swap to 0x12db9a8, 0x964640-
  0x964648).
- D1 = slot 0, 0x964658 (tail `b` to base D1 0x9a79f0). D0 = slot 1,
  0x96465c (base D1, then operator delete 0x60b470).
- Slots (11): 0=0x964658 (D1, tail-branch to base D1), 1=0x96465c (D0),
  2=0x964758 (4-byte helper), 3=0x96475c, 4=0x9a7a2c (`str wzr,[x8]; ret`),
  5=0x964680 (`str wzr,[x8]; ret`), 6=0x9a7a3c (`ret`), 7=0x964688 (`ret`),
  8=0x964750, 9=0x9a7a4c (`str wzr,[x8]; ret`), 10=0x9a7a54 (`orr w0,wzr,#1`).
  Slot bodies unrecovered beyond the trivia above.
