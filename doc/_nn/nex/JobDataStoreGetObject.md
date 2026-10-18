# JobDataStoreGetObject (nn::nex::JobDataStoreGetObject<...>)

## Identity

- RTTI: typeinfo data 0x12f7330, mangled name
  `N2nn3nex21JobDataStoreGetObjectINS0_25DataStoreApiVersionTraitsILNS0_21DATASTORE_API_VERSIONE1EEEEE`
  = `nn::nex::JobDataStoreGetObject<nn::nex::DataStoreApiVersionTraits<(nn::nex::DATASTORE_API_VERSION)1>>`.
- Row 0x12f6c00 is a typeinfo slot (offset-to-top slot at 0x12f6bf8 is the
  previous table's tail). Installed vptr = 0x12f6c08; GOT cell 0x1315900
  holds vptr-0x10 (addend 0x12f6bf8). 17 slots, 0x12f6c08..0x12f6c88.
- Secondary vptr row 0x12f6ca0 installed at this+0xa0 (header 0x12f6c90/98).
- Member of the nn::nex job vtable family: shared slots 0x5917a0 / 0x5917b0 /
  0x5917cc / 0x5917d4 / 0x5917d8 (compare include/_nn/nex/JobAcquireAccessToken.hpp).

## Size

size 0x320, proven twice: both factories execute
`mov w0, #0x320; bl 0x573f04` (nex operator-new wrapper) — sites 0xb18288 and
0xb1b204.

## Construction / init order

1. Factory FUN_7100b18220 (0xb18220) / FUN_7100b1b190 (0xb1b190): checks the
   request via 0x5822fc and a virtual gate (vtable+0x48) on the caller, then
   new(0x320) and calls shared job base ctor 0x588b04(this, 2, sp-buf).
2. Zeroes 0xa8, 0xb0..0xe0, (B variant) sets byte 0xc0 = 1; stores primary
   vptr 0x12f6c08 at +0x00 and secondary vptr 0x12f6ca0 at +0xa0.
3. Remaining subobject members (+0x100, +0x230, +0x298, arrays) are built by
   the shared tail; D1 0xb26804 tears them down in reverse (0xb8 virtual, 0x298
   via 0x58c97c, 0x278 block via 0x5763ac, 0x258 array stride 0x60, 0x230 via
   0x5790b4, 0x208 array stride 0x28, 0x100 via 0xa2c1e8). All teardown
   addresses are from FUN_7100b26804.

## Slots

| slot | addr | notes |
|---|---|---|
| 0 | 0xb26804 | D2/complete dtor (size 0x328) |
| 1 | 0xb2694c | D0/deleting dtor |
| 2 | 0x5917a0 | shared family stub (vt+0x18 dispatch) |
| 3 | 0x58ff6c | recovered, size 0x220 |
| 4 | 0x5917ac | shared stub |
| 5 | 0x590148 | shared stub |
| 6 | 0x59014c | unrecovered |
| 7 | 0x5917b0 | shared stub |
| 8 | 0x5917cc | shared ret-0 stub |
| 9 | 0x58b7d8 | unrecovered |
| 10 | 0x5917d4 | shared stub |
| 11 | 0x5917d8 | shared stub |
| 12 | 0x59189c | unrecovered |
| 13 | 0xb26998 | recovered, size 0x816 (request handler) |
| 14 | 0xb278d4 | recovered, size 0x388 |
| 15 | 0xb27a60 | recovered, size 0x360 |
| 16 | 0xb27bd0 | recovered, size 0x592 |
