#pragma once

#include <cstdint>

namespace object {

/// PLACEHOLDER name (identity not proven). Sibling of Vt12cfa80: same skeleton, but ctor derives
/// timing from cfg->0x50 (duration) and sets flag 0x3c = 0x1e. Heap size 0x48.
/// extent 0x48 - details: doc/object/Vt12cfb88.md
struct Vt12cfb88 {
    virtual ~Vt12cfb88();      // 0x00 (0x86b6e4, shared empty D2)
    virtual void dtorDelete(); // 0x08 (0x86b5e4)
    virtual void slot10();     // 0x10 (0x869b40)
    virtual void slot18();     // 0x18 (0x869d3c)
    virtual void slot20();     // 0x20 (0x869e58)
    virtual void slot28();     // 0x28 (0x86aa0c)
    virtual void slot30();     // 0x30 (0x86a128)
    virtual void slot38();     // 0x38 (0x86a13c)
    virtual void slot40();     // 0x40 (0x86ab68)
    virtual void slot48();     // 0x48 (0x869c08)
    virtual void slot50();     // 0x50 (0x86ab84)
    virtual void slot58();     // 0x58 (0x86b5e8)
    virtual void slot60();     // 0x60 (0x86b4a8)
    virtual void slot68();     // 0x68 (0x86b5fc)
    virtual void slot70();     // 0x70 (0x86b4f4)
    virtual void slot78();     // 0x78 (0x86b60c)
    virtual void slot80();     // 0x80 (0x86b504)
    virtual void slot88();     // 0x88 (0x86b50c)
    virtual void slot90();     // 0x90 (0x86b528)
    virtual void slot98();     // 0x98 (0x86b538)
    virtual void slotA0();     // 0xa0 (0x86a330)
    virtual void slotA8();     // 0xa8 (0x86a414)
    virtual void slotB0();     // 0xb0 (0x86a584)
    virtual void slotB8();     // 0xb8 (0x86a678)
    virtual void slotC0();     // 0xc0 (0x86ad64)
    virtual void slotC8();     // 0xc8 (0x86a7e0)
    virtual void slotD0();     // 0xd0 (0x86b544)
    virtual void slotD8();     // 0xd8 (0x86b644)
    virtual void slotE0();     // 0xe0 (0x86b650)
    virtual void slotE8();     // 0xe8 (0x86b67c)
    virtual void slotF0();     // 0xf0 (0x86b6ac)

    uint8_t mPad8[0x38];   // 0x08 — fields written by the ctor, see doc (+0x8 cfg, +0x10..+0x40)
    uint8_t mPad40[0x8];   // 0x40 — gap (ctor writes nothing here)
};

}  // namespace object
