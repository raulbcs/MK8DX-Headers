#pragma once

#include <cstdint>

// Vt12d8ac8 — PROVISIONAL placeholder (no RTTI; offset-to-top/typeinfo rows both 0, so
// vptr = 0x12d8ac8 directly; GOT cell 0x1312538 holds vt-0x10). Sole construction site
// 0x91d030: new(0x5b8), base ctor 0x55845c, result stored at [owner+0x38].
// extent 0x5b8 - details: doc/object/Vt12d8ac8.md

struct Vt12d8ac8 {
    virtual void dtor();             // 0x00 slot0 (0x91f6ec, unrecovered)
    virtual void dtorDeleting();     // 0x08 slot1 (0x91f7b8, unrecovered)
    virtual void slot10();           // 0x10 slot2 (0x5585d8)
    virtual void slot18();           // 0x18 slot3 (0x558718, unrecovered)
    virtual void slot20();           // 0x20 slot4 (0x55870c)
    virtual void slot28();           // 0x28 slot5 (0x558b1c)
    virtual void slot30();           // 0x30 slot6 (0x91f5d0, unrecovered)
    virtual void slot38();           // 0x38 slot7 (0x559010)
    virtual void slot40();           // 0x40 slot8 (0x559520)
    virtual void slot48();           // 0x48 slot9 (0x55874c, unrecovered)
    virtual void slot50();           // 0x50 slot10 (0x5596fc)
    virtual void slot58();           // 0x58 slot11 (0x559178)
    virtual void slot60();           // 0x60 slot12 (0x559724)
    virtual void slot68();           // 0x68 slot13 (0x55972c, unrecovered)
    virtual void slot70();           // 0x70 slot14 (0x559734)
    virtual void slot78();           // 0x78 slot15 (0x559378, unrecovered)
    virtual void slot80();           // 0x80 slot16 (0x559758)
    virtual void slot88();           // 0x88 slot17 (0x559760, unrecovered)
    virtual void slot90();           // 0x90 slot18 (0x91f3e4, unrecovered)
    uint8_t mBase8[0x90];            // 0x08 — base-ctor region (base ctor 0x55845c), see doc
    uint8_t mPad98[0x514];           // 0x98 — fields, see doc
    uint32_t mField5ac;              // 0x5ac — zeroed after base ctor
    uint32_t mField5b0;              // 0x5b0 — zeroed after base ctor
    uint8_t mTail5b4[0x4];           // 0x5b4 — tail pad to size
};
