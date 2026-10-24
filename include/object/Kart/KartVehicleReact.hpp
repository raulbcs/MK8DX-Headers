#pragma once

#include <cstdint>

#include <math/seadVector.h>

namespace object {
class KartVehicle;  // cycle-safe forward declaration

// extent 0xD8 — operator new(0xD8) at 0x71001815f4 inside the
// KartVehicleMove ctor, immediately followed by bl 0x710017eb94.
// Stored at KartVehicleMove+0x120 (str @0x7100181608). The ctor stores the
// KartVehicle arg at +0x08 (stp x8,x1,[x19] @0x710017ebd8); +0x10/+0x18 are
// two new(0xC0) children initialized by 0x7100196ff0.

class KartVehicleReact {
 public:
  uint8_t mPad00[8];          // 0x00 — vptr
  KartVehicle* mKartVehicle;  // 0x08 — ctor arg (stp @0x710017ebd8)
  void* mChild10;             // 0x10 — new(0xC0), init 0x7100196ff0
  void* mChild18;             // 0x18 — new(0xC0), init 0x7100196ff0
  uint8_t mPad20[0x18];       // 0x20 - 0x37 — unproven gap
  void* mVptr38;              // 0x38 — secondary vptr 0x71011bae90 (ctor
                              //  0x710017ec04-0x710017ec10 writes the same
                              //  vtable at +0x38, +0x90 and +0xA0 — subobject
                              //  vs value UNCERTAIN)
  uint8_t mPad40[0x20];       // 0x40 - 0x5F — unproven gap
  float f60;                  // 0x60 — ctor 1.0f
  uint8_t mPad64[0x18];       // 0x64 - 0x7B — unproven gap
  float f7c;                  // 0x7C — ctor FLT_MAX
  uint8_t mPad80[8];          // 0x80 - 0x87 — unproven gap
  float f88;                  // 0x88 — ctor 0.0f (pair store with +0x8C)
  float f8c;                  // 0x8C — ctor 0.3f (0x3e99999a)
  uint8_t mVtWrites90[0x20];  // 0x90 - 0xAF — vtable 0x71011bae90 written at
                              //  +0x90 and +0xA0 (subobject vs value UNCERTAIN)
  void* mSubB0;               // 0xB0 — new(0x70) via 0x71007c55cc when
                              //  [KartVehicle+0xD0] (0x710017ec48-0x710017ec64)
  uint8_t mPadB8[0x20];       // 0xB8 - 0xD7 — to the allocation end 0xD8

  void requestBattleDropCoin(int, sead::Vector3<float> const&);

  class EAcdType {
   public:
    enum EAcdType_ : int32_t {
      Spin1,           // 0x00
      Spin2,           // 0x01
      Spin1_,          // 0x02
      Spin2_,          // 0x03
      Spin2_Oil,       // 0x4
      Spin1_Fire,      // 0x05
      Spin2__,         // 0x06
      Spin1_Electric,  // 0x07
      Spin2___,        // 0x08
      CrashDir,        // 0x09
      CrashDirBig,     //0x0A
      CrashLR,         // 0x0B
      CrashLRSmall,    // 0x0C
      CrashLRBig,      // 0x0D
      CrashSmall,      // 0x0E
      CrashFwd,        // 0x0F
      Hop,             // 0x10
      Freeze,          // 0x11
      Freeze_Press,    // 0x12
      Spin2_NoSound,   // 0x13
      None,            // 0x14
    };

    EAcdType_ mValue;

    EAcdType(EAcdType_ acdType) : mValue(acdType) {}
    EAcdType(int32_t acdType) : mValue(static_cast<EAcdType_>(acdType)) {}

    ~EAcdType() {}
  };
};
}  // namespace object
