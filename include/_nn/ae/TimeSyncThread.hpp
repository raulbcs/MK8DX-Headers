#pragma once

#include <cstdint>

namespace nn::ae {
// TimeSyncThread — an nn::ae::AppletThread subclass (vptr 0x12d0148,
// cell 0x1310f88, n=18, ctor 0x870f54, alloc sites 0x3de754 / 0x8bc1f4:
// new 0x6a0). Evidence: Thread name "TimeSyncThread" (rodata 0xf0cbc5,
// prio 10, attr 0x4000) passed to the shared nn::ae ctor 0x7100628a54.
//
// NOTE: the AppletThread base sub-object sits at 0x4c0 (the shared
// ctor stores the class vptr there), NOT at 0x00 — 0x00..0x4c0 are
// nn::account state owned before the thread base. Modelled flat.
//
// Ctor field map: 0x00 u64 = 0 (later reused: site stores
// GlobalCacheCount); 0x08 u16 = 0; 0x10 void* = nn::account::UserHandle
// (written after OpenPreselectedUser fills 0x688); 0x18 sub-object
// (ctor 0xb542f0, extent 0x68, to 0x80); 0x80 u32 = 0; 0x88 buffer,
// memset 0x79; seven 0x7d buffers, 0x80 stride, at
// 0x104/0x184/0x204/0x284/0x304/0x384/0x404 (all memset 0);
// 0x484 u32 = 0; 0x488 u64 = 0; 0x490 u8 = 0 (work counter, incremented
// by 0x871154); 0x494 array of 6 fn ptrs (built by 0x630f64 from GOT
// cells 0x1307170..0x1307198); 0x4b0 u32 = 0; 0x4b8 sub-object
// (ctor 0x63115c); 0x4c0 AppletThread base (0xf8); 0x5b8 ptr =
// this+0x5d0; 0x5c0 = 10; 0x5c8 u32 = 0; 0x620 sub-object (ctor
// 0x628628); 0x660 secondary vptr (cell 0x1310f90); 0x668/0x670/0x678
// = 0; 0x680 u16 = 0; 0x688 nn::account::UserHandle.
class TimeSyncThread {
 public:
  uint64_t mZero00;           // 0x00 — ctor zero
  uint16_t mZero08;           // 0x08 — ctor zero (strh)
  uint32_t pad0a;             // 0x0a — unproven padding
  void* mUserHandlePtr10;     // 0x10 — points at mUserHandle688 after ctor
  uint8_t mSub18[0x68];       // 0x18 — sub-object (ctor 0xb542f0, nn::account cache info)
  uint32_t mZero80;           // 0x80 — ctor zero
  uint8_t mBuf88[0x7c];       // 0x88 — memset 0x79 (+pad to next member)
  uint8_t mBufs104[7][0x80];  // 0x104 — seven 0x80-stride buffers (0x7d memset each)
  uint32_t mZero484;          // 0x484 — ctor zero
  uint64_t mZero488;          // 0x488 — ctor zero
  uint8_t mWork490;           // 0x490 — ctor zero; work counter
  uint8_t pad491[3];          // 0x491 — unproven padding
  void* mFns494[6];           // 0x494 — 6 fn ptrs (init 0x630f64)
  uint32_t mZero4b0;          // 0x4b0 — ctor zero
  uint8_t mSub4b8[8];         // 0x4b8 — sub-object (ctor 0x63115c), extent to 0x4c0
  uint8_t mBase4c0[0xf8];     // 0x4c0 — nn::ae::AppletThread base sub-object
  void* mSelf5b8;             // 0x5b8 — ctor sets this+0x5d0
  uint32_t mTen5c0;           // 0x5c0 — ctor sets 10
  uint32_t mZero5c8;          // 0x5c8 — ctor zero
  uint8_t mSub620[0x40];      // 0x620 — member sub-object (ctor 0x628628)
  void* mVptr660;             // 0x660 — secondary sub-object vptr (cell 0x1310f90)
  uint64_t mZero668;          // 0x668 — ctor zero
  uint64_t mZero670;          // 0x670 — ctor zero
  uint64_t mZero678;          // 0x678 — ctor zero
  uint16_t mZero680;          // 0x680 — ctor zero (strh)
  uint8_t pad682[6];          // 0x682 — unproven padding
  void* mUserHandle688;       // 0x688 — OpenPreselectedUser out-param
  uint8_t pad690[0x10];       // 0x690 — to alloc size (unmapped tail)
                              // (0x6a0 total)
};
}  // namespace nn::ae
