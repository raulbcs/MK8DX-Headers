# SessionInfoList\<LanSessionInfoPrivate\>
(nn::pia::session::SessionInfoList\<nn::pia::lan::LanSessionInfoPrivate\>)

- vptr 0x12dc3e8 = first slot row; typeinfo 0x12dc430 at 0x12dc3e0
  ("N2nn3pia7session15SessionInfoListINS0_3lan21LanSessionInfoPrivateEEE",
  base nn::pia::session::ISessionInfoList, ti 0x12d9f20 — base-of slot
  empty, root). GOT cell 0x1313318 holds addend 0x12dc3d8 = vptr-0x10.
- Size 0x18: deepest store +0x10 (8-byte array pointer); no factory
  allocation — always constructed in place (0x96d5ec).

## Identity

Template instance of the pia session info list for LAN private session
infos; owns a heap array of `cap` element pointers allocated in the C1.

## Member notes

- +0x08 u16 count = 0, +0x0a u16 capacity = C1 arg w1 (0x96d750/0x96d760).
- +0x10 ptr = alloc(cap*8) via allocator 0x563b70 / 0x568aa0 (0x96d76c,
  size `cap<<3` at 0x96d778), entries zeroed by an unrolled loop
  (0x96d788-0x96d7c8); NULL/0-cap skips (0x96d780-0x96d784).

## Construction / init order

- C1 = 0x96d738(this, u16 cap): count/cap stores, vptr from GOT cell
  0x1313318 (+0x10), array alloc + zero-fill, ptr store (unverified exact
  store site; +0x10 proven by D1 load 0x96d870).
- D1 = slot 0, 0x96d854: virtual-calls each non-null element's slot 0, then
  frees the array (0x568bb0) and the element buffer (0x568b64); D0 = slot 1,
  0x96d8f4 (same tail, then operator delete).
- Slots (9): 0=0x96d854 (D1), 1=0x96d8f4 (D0), 2=0x96d98c, 3=0x96d994,
  4=0x96d99c, 5=0x96d9ac, 6=0x96d9bc, 7=0x96d9c4, 8=0x96d9cc.
  Slots 2-8 unrecovered.
