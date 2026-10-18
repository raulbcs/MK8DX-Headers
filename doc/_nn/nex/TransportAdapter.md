# nn::nex::TransportAdapter

## Identity

RTTI-confirmed: compact typeinfo record at 0x12e4390 = {0x10, name 0xf846a0 = "N2nn3nex16TransportAdapterE"}. Primary vtable row: offset-to-top 0 at 0x12e3498, typeinfo slot 0x12e34a0, vptr 0x12e34a8. GOT cell 0x13145d0 holds 0x12e3498 (vt-0x10 convention; installed vptr = cell+0x10). 13 slots (0x12e34a8-0x12e3508), row terminates at 0x12e3510.

size 0x1c8 — LOWER BOUND only: no operator-new site found; max member store xzr at +0x1c0 in the inline ctor (0x9f74f0). dtor chain touches members at +0x10/+0xa0/+0x130.

No C1 in the vtable: the ctor is inlined into the registry-init function at 0x9f7440-0x9f7500 (site 0x9f74c8 loads cell 0x13145d0, installs vptr at [x20]). The instance is a global singleton: pointer cell 0x1314518 -> .bss 0x13614c0; after construction it is registered via 0x58c448 into the nex transport ListBase (head cell 0x130b940 -> 0x1347798). Neighbor descriptors in the same nex RTTI blob: RootTransport 0x12e42b0, PacketEncDecInf 0x12e4270, RC4PacketEncDec 0x12e4290, UPnPProperties 0x12e42d0, Network 0x12e4250 (unverified relationships).

## Member notes

- +0x00 vptr (0x12e34a8).
- +0x08 u32 — init 0 (wzr at 0x9f74f4).
- +0x10 / +0xa0 / +0x130 — three 0x90-byte member objects, ctor 0x9d60b0 / dtor 0x9d6434 (inline ctor 0x9f74dc-0x9f74ec; D1 0x9f7e98 destroys in reverse order).
- +0x1c0 — xzr store (0x9f74f0); padding/object unverified.

Slot map (vptr 0x12e34a8):
- slot0 0x9f7e98 = D1, slot1 0x9f7edc = D0 (dtor pair; both re-install vptr with post-increment, D0 tail-calls operator delete 0x573f48).
- slot2 0x9f7f28 = largest recovered slot (1440 B, override; no cell load — not a ctor).
- slots3-12 0x9f8504/0x9f8568/0x9f8574/0x9f856c/0x9f8994/0xa192e8/0xa192ec/0x9f8448/0x9f84c8/0x9f84e8 — unrecovered (absent from functions.csv).
- slot12 0x9f84e8 carries csv name "Screening::NotFound#2" (csv naming artifact, unverified).

## Construction / init order

Inline ctor inside the registry init (0x9f7440-0x9f7500):

1. Clear u16 at this+0x18, xzr at this+0x10 (0x9f745c-0x9f7460).
2. Install vptr 0x12e34a8 at [this] (cell 0x13145d0 +0x10).
3. Register the instance via 0x58c448 (arg: cell 0x130b940 head).
4. Construct the three members at +0x10/+0xa0/+0x130 (ctor 0x9d60b0).
5. xzr at this+0x1c0; zero u32 at this+0x8.
