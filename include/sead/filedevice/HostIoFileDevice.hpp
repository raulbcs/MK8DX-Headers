#pragma once

#include <cstdint>

namespace sead {

/// FileDevice subclass; device name "hostio" (cf. upstream sead::NinHostIOFileDevice).
/// Singleton-ish device mounted by FUN_7100688840's factory as mount "agl_hostpc".
/// extent 0x90 - details: doc/sead/filedevice/HostIoFileDevice.md
struct HostIoFileDevice {
    virtual ~HostIoFileDevice();                     // 0x00 shared D2 0x633470
    virtual void dtorDelete();                       // 0x08 D1 0xa7fdfc (base dtor 0x60cd24 + delete)
    virtual void slot10();                           // 0x10 (0xa7fe20, guard-protected static compare)
    virtual void slot18();                           // 0x18 (0xa7ff40)
    virtual void slot20();                           // 0x20 (0x60e170)
    virtual void slot28();                           // 0x28 (0x60e17c)
    virtual void slot30();                           // 0x30 (0x60e188)
    virtual void slot38();                           // 0x38 (0x60e194)
    virtual bool isMatchDevice_(const void*) const;  // 0x40 (0x60d97c)
    virtual bool doIsAvailable_() const;             // 0x48 (0xa7fdec, returns false)
    virtual void slot50();                           // 0x50 (0x60cdf4)
    virtual void slot58();                           // 0x58 (0x60d3cc)
    // ... slots 0x60..0xf0 inherit the shared FileDevice table (0x633830..0x6344e0)
    virtual bool slotF8() const;                     // 0xf8 (0xa7fdf4, returns false)

    uint8_t mPad8[0x8];    // 0x08 — gap (base init via FUN_71006336a8)
    uint8_t mPad10[0x80];  // 0x10 — never accessed from this class; FileDevice base fields (unproven)
};

}  // namespace sead
