# nn::pia::inet::InetDisconnectStationJob

RTTI-confirmed via typeinfo name `N2nn3pia4inet24InetDisconnectStationJobE` (0xf7eae0). Typeinfo-row vtable 0x12da550: GOT cell 0x1312a38 holds vptr-0x10, installed vptr 0x12da558; word at 0x12da550 points to the embedded typeinfo object at 0x12da5a0 (base typeinfo 0x12decf0 = nn::pia::transport::DisconnectStationJob, itself a nn::pia::common::StepSequenceJob). Offset-to-top 0. 8 slots; slots 2-4 shared job overrides (0xb4a654/0xb4a67c/0x933314 `ret`).

## Member notes

- Slots 5/6 (0x9376e4, 0x9375c0) operate almost entirely through the global session-context GOT cells (0x1312a40/0x1312a48 family), not through `this`.
- Slot7 0x9a2f38 stores [this+0x68] (arg ptr) and clears [this+0x7c] after a `[x+0x30] == 5` state check - deepest `this` offset in the class.
- Secondary groups adjacent in .data (ti InetInputStream 0x12da630 and IPacketInput 0x12da618, offtops 0 / -0xe8) are unverified for this class - the C1 installs no secondary vptrs.
- Size: lower bound 0x80 from the slot7 store at +0x7c (byte). Exact size unverified.

## Construction / init order

- Ctor 0x937580: GOT cell 0x1312a38 -> +0x10 -> `[this]` = vptr; nothing else (0x937580..0x937594). The base job region is expected to be constructed by the caller; no `bl` callers and no relocs to the ctor were found - construction site unverified.
