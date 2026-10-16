# nn::nex::EventLog

RTTI-confirmed (typeinfo mangled name: N2nn3nex11EventLogE, ti object 0x128c460). vptr 0x128c000 (n=5). Hottest live vtable missed by the strict census: 44 code references, all concentrated in the nn::nex event-log writer region 0x583154-0x583cxx (FUN_7100583154, FUN_710058358c, ...).

Secondary vtables in the same cluster: nn::nex::Log (vptr 0x128c038, ti 0x128c440) and nn::nex::LockChecker (vptr 0x128c050, ti 0x128c480) — both RTTI-confirmed, covered by this family header.

## Construction / init order

Each of the 44 writer sites: heap-allocates a 0x50-byte object (alloc helper 0x576368), installs the vptr from GOT cell 0x130b618 (+0x10) at +0x20 together with a caller-supplied qword, stlr-sets a flag at +0x30 and zeroes a bool at +0x34. Slot map: +0x00/+0x08 dtor pair (0x575c84/0x575d18), +0x10 0x57619c. Writer objects are 0x50 bytes; tail unmapped.
