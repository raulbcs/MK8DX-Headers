# nn::ae::TimeSyncThread

An nn::ae::AppletThread subclass (vptr 0x12d0148, cell 0x1310f88, n=18, ctor 0x870f54, alloc sites 0x3de754 / 0x8bc1f4: new 0x6a0). Evidence: Thread name "TimeSyncThread" (rodata 0xf0cbc5, prio 10, attr 0x4000) passed to the shared nn::ae ctor 0x7100628a54.

NOTE: the AppletThread base sub-object sits at 0x4c0 (the shared ctor stores the class vptr there), NOT at 0x00 — 0x00..0x4c0 are nn::account state owned before the thread base. Modelled flat.

## Ctor field map (ctor 0x870f54)

0x00 u64 = 0 (later reused: site stores GlobalCacheCount); 0x08 u16 = 0; 0x10 void* = nn::account::UserHandle (written after OpenPreselectedUser fills 0x688); 0x18 sub-object (ctor 0xb542f0, extent 0x68, to 0x80); 0x80 u32 = 0; 0x88 buffer, memset 0x79; seven 0x7d buffers, 0x80 stride, at 0x104/0x184/0x204/0x284/0x304/0x384/0x404 (all memset 0); 0x484 u32 = 0; 0x488 u64 = 0; 0x490 u8 = 0 (work counter, incremented by 0x871154); 0x494 array of 6 fn ptrs (built by 0x630f64 from GOT cells 0x1307170..0x1307198); 0x4b0 u32 = 0; 0x4b8 sub-object (ctor 0x63115c); 0x4c0 AppletThread base (0xf8); 0x5b8 ptr = this+0x5d0; 0x5c0 = 10; 0x5c8 u32 = 0; 0x620 sub-object (ctor 0x628628); 0x660 secondary vptr (cell 0x1310f90); 0x668/0x670/0x678 = 0; 0x680 u16 = 0; 0x688 nn::account::UserHandle.

## Construction / init order

1. Allocation 0x3de754 / 0x8bc1f4: operator new(0x6a0).
2. Ctor 0x870f54, in field order: zeros/buffers as mapped above — 0x18 sub-object ctor 0xb542f0; 0x88 memset 0x79; seven 0x7d memsets at 0x104..0x404 stride 0x80; 0x494 fn-ptr array built by 0x630f64 (GOT cells 0x1307170..0x1307198); 0x4b8 sub-object ctor 0x63115c; 0x4c0 AppletThread base via shared nn::ae ctor 0x7100628a54 (thread name "TimeSyncThread", rodata 0xf0cbc5, prio 10, attr 0x4000); 0x620 sub-object ctor 0x628628; secondary vptr cell 0x1310f90 at 0x660.
3. Post-ctor: OpenPreselectedUser fills mUserHandle688 (0x688); mUserHandlePtr10 (0x10) points at it; work counter 0x490 incremented by 0x871154.
