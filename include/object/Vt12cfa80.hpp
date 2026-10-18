#pragma once

#include <cstdint>

namespace object {

/// PLACEHOLDER name (identity not proven). Animation-timing controller built from a config object
/// by the manager at 0x198ee8 (mode switch 0x198f18) and 0x142dcc; heap size 0x48.
/// extent 0x48 - details: doc/object/Vt12cfa80.md
struct Vt12cfa80 {
    virtual ~Vt12cfa80();          // 0x00 (0x86b6e4, shared empty D2)
    virtual void dtorDelete();     // 0x08 (0x86b49c)
    virtual void slot10();         // 0x10 (0x869b40, 308B)
    virtual void slot18();         // 0x18 (0x869d3c)
    virtual void slot20();         // 0x20 (0x869e58)
    virtual void slot28();         // 0x28 (0x86a090)
    virtual void slot30();         // 0x30 (0x86a128)
    virtual void slot38();         // 0x38 (0x86a13c)
    virtual void slot40();         // 0x40 (0x86a1d8)
    virtual void slot48();         // 0x48 (0x869c08)
    virtual void slot50();         // 0x50 (0x86b45c)
    virtual void slot58();         // 0x58 (0x86b4a0)
    virtual void slot60();         // 0x60 (0x86b4a8)
    virtual void slot68();         // 0x68 (0x86b4b0)
    virtual void slot70();         // 0x70 (0x86b4f4)
    virtual void slot78();         // 0x78 (0x86b4fc)
    virtual void slot80();         // 0x80 (0x86b504)
    virtual void slot88();         // 0x88 (0x86b50c)
    virtual void slot90();         // 0x90 (0x86b528)
    virtual void slot98();         // 0x98 (0x86b538)
    virtual void slotA0();         // 0xa0 (0x86a330)
    virtual void slotA8();         // 0xa8 (0x86a414)
    virtual void slotB0();         // 0xb0 (0x86a584)
    virtual void slotB8();         // 0xb8 (0x86a678)
    virtual void slotC0();         // 0xc0 (0x86a6e8)
    virtual void slotC8();         // 0xc8 (0x86a7e0)
    virtual void slotD0();         // 0xd0 (0x86b544)
    virtual void slotD8();         // 0xd8 (0x86b588)
    virtual void slotE0();         // 0xe0 (0x86b594)
    virtual void slotE8();         // 0xe8 (0x86b5b8)
    virtual void slotF0();         // 0xf0 (0x86b5dc)

    uint8_t mPad8[0x38];   // 0x08 — fields written by the ctor, see doc (+0x8 cfg, +0x10..+0x40)
    uint8_t mPad40[0x8];   // 0x40 — gap (ctor writes nothing here)
};

}  // namespace object
