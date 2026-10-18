# SessionInfoList&lt;LdnSessionInfo&gt; (nn::pia::session::SessionInfoList&lt;nn::pia::local::LdnSessionInfo&gt;)

- vptr 0x12dfe38 installed from GOT cell 0x1313d28 (RELATIVE addend 0x12dfe28 =
  vt-0x10; code does `cell+0x10`). vt_ctors.tsv row 0x12dfe30 is the typeinfo
  slot. Typeinfo 0x12dfe80, name
  "N2nn3pia7session15SessionInfoListINS0_5local14LdnSessionInfoEEE", base
  nn::pia::session::ISessionInfoList.
- Size 0x18 (lower bound: max field store 0x10+8; no heap alloc of the list
  itself found — C2 0x9be4ac has no direct callers; it runs as the base ctor of
  derived classes, e.g. the network-description family).

## Identity

Owns a fixed-capacity array of `LdnSessionInfo*` (each entry a 0xbe0 heap
object holding an LdnNetworkDescription at +0x10, C2 0x9c1a80).

## Slots

Primary vtable 0x12dfe38, 9 slots:
- slot 0 = 0x9be5a0 (D2: virtually destroys and deletes every entry, then
  `operator delete[]` on the array)
- slot 1 = 0x9be640 (D0: D2 body + `operator delete` on this)
- slot 2 = 0x9be6d8 (quality O, 8 bytes)
- slots 3..7 = 0x9be6e0 / 0x9be6e8 / 0x9be6f8 / 0x9be708 / 0x9be710
  (unrecovered)
- slot 8 = 0x9be718 (U, 268 bytes: clears count +0x08 to 0 and virtually calls
  vtable slot +0x50 on every entry — release/reset of all session infos)

## Member notes

- 0x08 — live count (u16), reset by slot 8.
- 0x0a — capacity (u16), taken from C2 arg w1.
- 0x10 — entry array: `0x568aa0(capacity * 8)` zero-filled at C2, then
  `capacity` entries allocated (`0x568aa0(0xbe0)` + C2 0x9c1a80).

## Construction / init order

1. C2 0x9be4ac(this, w1 = capacity): stores count 0 at +0x08, capacity at
   +0x0a, installs vptr 0x12dfe38.
2. Allocates and zero-fills the pointer array (capacity*8) into +0x10.
3. If capacity != 0, loops capacity times: `0x568aa0(0xbe0)` + LdnSessionInfo
   C2 0x9c1a80, storing each pointer into the array.
4. D2/D0 release every entry virtually, delete the array, delete this.
