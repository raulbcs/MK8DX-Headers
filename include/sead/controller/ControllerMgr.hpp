#pragma once

#include <cstdint>

namespace sead {

/// sead::ControllerMgr (heap name "sead::ControllerMgr" @0xef7b6c; cf. upstream
/// seadControllerMgr.h, CalculateTask singleton). TaskBase-derived overrides at slots
/// 0-3, 10, 22 vs base vtable 0x12af938; singleton instance cell 0x12fccb0.
/// extent 0x198 - details: doc/sead/controller/ControllerMgr.md
struct ControllerMgr {
    virtual ~ControllerMgr();               // 0x00 D1 0x629a18 (reloads vptr, tail-calls base dtor 0x6106fc)
    virtual void dtorDelete();              // 0x08 D0 0x629a40 (base dtor + operator delete 0x60b470)
    virtual void slot10();                  // 0x10 (0x629a8c)
    virtual void slot18();                  // 0x18 (0x629bac)
    virtual void slot20();                  // 0x20 inherited TaskBase 0x6108b0
    virtual void slot28();                  // 0x28 inherited 0x610930
    virtual void slot30();                  // 0x30 inherited 0x610934
    virtual void slot38();                  // 0x38 inherited 0x6109b4
    virtual void slot40();                  // 0x40 inherited 0x6109b8
    virtual void slot48();                  // 0x48 inherited 0x610a38
    virtual void calc();                    // 0x50 override 0x6296ec
    virtual void slot58();                  // 0x58 inherited 0x612ddc
    virtual void slot60();                  // 0x60 inherited 0x612e48
    virtual void slot68();                  // 0x68 inherited 0x612e4c
    virtual void slot70();                  // 0x70 inherited 0x612e50
    virtual void slot78();                  // 0x78 inherited 0x61080c
    virtual void slot80();                  // 0x80 inherited 0x6108a0
    virtual void slot88();                  // 0x88 inherited 0x6108a4
    virtual void slot90();                  // 0x90 inherited 0x6108ac
    virtual void slot98();                  // 0x98 inherited 0x6107ac
    virtual void slotA0();                  // 0xa0 inherited 0x610a3c
    virtual void slotA8();                  // 0xa8 inherited 0x74828
    virtual void calcIterate();             // 0xb0 override 0x629930 (walks controller/addon arrays, calls slot +0x20)

    uint8_t mPad8[0x160];          // 0x08 - TaskBase/CalculateTask base region (bases at +0x00, +0x40, +0x50, +0x58, +0xd0)
    uint8_t mSingletonFlag;        // 0x168 - set by createImpl 0x629678 when this becomes the singleton
    uint8_t mPad169[0x7];          // 0x169 - alignment to 0x170
    void* mDevicesHead;            // 0x170 - OffsetList<ControlDevice> mDevices (self-pair, init in ctor 0x629698)
    void* mDevicesTail;            // 0x178
    uint32_t mDevicesOffset0;      // 0x180 - zeroed
    uint32_t mControllersMax;      // 0x184 - = 8
    uint32_t mControllerNums;      // 0x188 - PtrArray<Controller> count
    uint8_t mPad18C[0x4];          // 0x18c - alignment to 0x190
    Controller** mControllers;     // 0x190 - PtrArray<Controller> buffer (unproven element type); object ends at 0x198
};

}  // namespace sead
