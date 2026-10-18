# sead::ControllerMgr

Identity from the heap name string "sead::ControllerMgr" (rodata 0xef7b6c) passed to the
base ctor chain; matches upstream sead::ControllerMgr : CalculateTask (SEAD_TASK_SINGLETON).
vptr 0x12b0c78 at [this], 23 slots (+0x00..+0xb0), no offset-to-top/typeinfo rows (both zero).
GOT cell 0x130d480 holds vt-0x10 (0x12b0c68); installed vptr = cell+0x10 = 0x12b0c78.
size 0x198: proven by the factory allocation (0x612078: `mov w0, #0x198` then ctor 0x629698).

## Member notes

- Overrides vs the TaskBase base vtable 0x12af938 (cell 0x130d138): slots 0-3, slot10
  (0x6296ec) and slot22 (0x629930). All other slots are the inherited TaskBase tail
  (0x6108b0..0x610a3c cluster, 0x612ddc..0x612e50, 0x6107ac..0x61080c, 0x74828).
- slot0 D1 0x629a18 / slot1 D0 0x629a40: reinstall vptr = [0x130d480]+0x10, clear the
  singleton cell 0x12fccb0 when [this+0x168] is set, then base dtor 0x6106fc (D0 adds
  operator delete 0x60b470).
- slot22 0x629930 iterates the arrays described by [+0x184]/[+0x188]/[+0x190] calling
  vtable slot +0x20 on each element (calc dispatch over controllers/addons).
- Singleton: SEAD_TASK_SINGLETON instance cell 0x12fccb0; createImpl helper 0x629678
  (compare-swap + flag byte at [this+0x168]); guard cell for the other task singleton
  family: 0x130d1d8/0x130d1e0 (not this class).
- Layout (upstream mDevices/mControllers): +0x170/+0x178 self-pointer pair
  (OffsetList<ControlDevice> mDevices heads), +0x180 = 0, +0x184 = 8 (max controllers),
  +0x188 count, +0x190 buffer (PtrArray<Controller>). Split of the two s32 fields at
  +0x180/+0x184 unverified.
- Base-region vptrs installed by the shared base ctor 0x6105d4: [this] = 0x12af938
  (cell 0x130d138, later overridden), [this+0x40] = 0x11ad210 (cell 0x12fae28),
  [this+0x50] = 0xed6af8 (rodata RTTI-ish), [this+0x58] = 0x12afa00 (cell 0x130d140),
  [this+0xd0] = 0x125f2e0 (cell 0x1307110). Unverified which upstream base each maps to.

## Construction / init order

1. Factory FUN_7100612078 (0x612078): allocates 0x198 (heap pointer taken through the
   ConstructArg vtable slot +0x24), then calls ctor 0x629698.
2. Ctor 0x629698 (GOT-cell site 0x6296bc): calls base ctor chain 0x6105d4 with name
   "sead::ControllerMgr"; then zeroes [this+0x168], [+0x180], [+0x188], [+0x190],
   stores the mDevices self-pair at +0x170/+0x178, mControllersMax = 8 at +0x184, and
   finally installs vptr 0x12b0c78 at [this] (0x6296d0).
- Dtors: 0x629a18 (D1) / 0x629a40 (D0); cell sites 0x629a1c/0x629a50.
