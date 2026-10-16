# RaceDirectorVta260 (gear::RaceDirectorVta260)

- PROVISIONAL vtable-anchored name (vptr 0x12ca260, GOT cell 0x1310470). Far-family singleton: ctor 0x71007fd3d4 (cxa_guard getter 0x71007fd410 in the same region). Extent 0xc0.

Base: ctor 0x71007b976c (RaceDirectorBase38). The ctor zeroes 0x38 and 0x40..0x4f, then zeroes 0xb0..0xbf (final stp covers 0xb0..0xbf, so extent 0xc0). Everything between 0x50 and 0xaf is untouched by the ctor.

Naming: sole getter caller 0x13cfa4 sits in the nn::ldn/LAN init region (MakeIpv4Address + ErrorResultVariant setup) but never names the singleton; near-zero ctor gives no semantics. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zero; 0x3c unproven padding.
- 0x40/0x48 — ctor zero.
- 0x50 — untouched by ctor (0x60 bytes).
- 0xb0/0xb8 — ctor zero.

## Construction / init order

1. Ctor 0x71007fd3d4 runs base ctor 0x71007b976c (RaceDirectorBase38).
2. Zeroes 0x38 and 0x40..0x4f.
3. Zeroes 0xb0..0xbf (final stp, extent 0xc0).

Sole getter caller: 0x13cfa4 (nn::ldn/LAN init region).
