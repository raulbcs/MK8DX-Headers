#pragma once

#include <cstdint>

namespace eui {

/// ButtonBase control (getClassName slot returns "ButtonBase"); derives eui::ControlBase.
/// Ctor FUN_7100739974; heap-created only via a derived class (new 0x70 at 0x73ab18).
/// extent 0x60 - details: doc/eui/Button/ButtonBase.md
struct ButtonBase {
    virtual const char* getClassName();               // 0x00 (0x739968 -> "ButtonBase", 0xf071f2)
    virtual void* getRuntimeTypeInfo();               // 0x08 (0x73a2dc)
    virtual ~ButtonBase();                            // 0x10 (0x7343a0, ControlBase empty D2)
    virtual void update(float);                       // 0x18 (0x73a36c)
    virtual void slot20();                            // 0x20 (0x73a00c)
    virtual void slot28();                            // 0x28 (0x73a02c)
    virtual void slot30();                            // 0x30 (0x73a0a0)
    virtual void slot38();                            // 0x38 (0x73a114)
    virtual void slot40();                            // 0x40 (0x73a1a8)
    virtual void slot48();                            // 0x48 (0x73a208)
    virtual void slot50();                            // 0x50 (0x73a210)
    virtual void slot58();                            // 0x58 (0x73a218)
    virtual void slot60();                            // 0x60 (0x73a220)
    virtual void slot68();                            // 0x68 (0x73a228)
    virtual void slot70();                            // 0x70 (0x73a22c)
    virtual void slot78();                            // 0x78 (0x73a230)
    virtual void slot80();                            // 0x80 (0x73a234)
    virtual void slot88();                            // 0x88 (0x73a238)
    virtual void slot90();                            // 0x90 (0x73a248)
    virtual void slot98();                            // 0x98 (0x73a258)
    virtual void slotA0();                            // 0xa0 (0x73a268)
    virtual void slotA8();                            // 0xa8 (0x73a278)
    virtual void slotB0();                            // 0xb0 (0x73a280)

    void* mLink;       // 0x08 — ControlBase list node (0x10 bytes)
    void* mLinkNext;   // 0x10
    uint32_t mPad18;   // 0x18 — ControlBase field
    uint32_t mPad1C;   // 0x1c — ControlBase field
    uint32_t mPad20;   // 0x20 — ControlBase field
    uint32_t mPad24;   // 0x24 — ControlBase field
    void* mControl;    // 0x28 — ControlBase::control
    void* mList0x30;   // 0x30 = &mList0x30 (self sentinel pair 0x30/0x38)
    void* mList0x38;   // 0x38 = &mList0x30
    uint16_t mFlags;   // 0x42 = 0x1f
    uint8_t mFlag40;   // 0x40 = 0
    uint8_t mFlag41;   // 0x41 = 0
    char mSSOBuf[4];   // 0x44 small inline string, capacity 3
    uint32_t mSSOLen;  // 0x48 = 0
    uint8_t mPad4C[0x14]; // 0x4c — gap (derived class fields start at +0x60; ctor writes nothing here)
};


}  // namespace eui
