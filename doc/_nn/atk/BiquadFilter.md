# nn::atk::BiquadFilterCallback family

Fully RTTI-confirmed. The recensus flagged a 10-entry vtable cluster at 0x12ae7a0-0x12ae9f8 (n=3 each, stride 0x40, shared first slot 0x5e3c30): every cell is one subclass vtable followed by its typeinfo, i.e. ten named nn::atk::detail::BiquadFilter* classes deriving from nn::atk::BiquadFilterCallback (base typeinfo 0x12ae7b8; base vtable not part of the cluster).

The 10 vptrs form a static table at 0x12ae090..0x12ae0d8 which the sound-driver constructor (FUN_71005e483c region, site 0x5e4df8) stores entry-by-entry into fields +0x1e8..+0x220 of the driver object — one pre-bound filter per BiquadFilterType. No other construction sites.

Slot layout per subclass: +0x00 shared 0x5e3c30 (base operation), +0x08/+0x10 unique per class (filter apply + deleting dtor; mapping pending). Each vtable has full RTTI (offset-to-top 0, ti at vptr-0x8).

Subclass vtables (vptr / slots +0x08 / +0x10 / typeinfo) — see the per-class comments in include/_nn/atk/BiquadFilter.hpp (0x12ae7a0..0x12ae9f8, ti 0x12ae7d0..0x12aea10).

## Construction / init order

1. Static vptr table 0x12ae090..0x12ae0d8 (10 entries).
2. Sound-driver ctor (FUN_71005e483c region, site 0x5e4df8) stores the entries one-by-one into driver fields +0x1e8..+0x220 (one filter per BiquadFilterType). No other construction sites.
