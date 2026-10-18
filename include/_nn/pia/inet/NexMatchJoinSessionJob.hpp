#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet22NexMatchJoinSessionJobE). Typeinfo-row vtable:
/// assigned 0x12daf10, real vptr 0x12daf18 (GOT cell 0x1312d60 holds vt-0x10).
/// Factory 0x931bb0: new(0x160) at 0x931bc4; ctor 0x93f430.
/// extent 0x160 - details: doc/_nn/pia/inet/NexMatchJoinSessionJob.md
struct NexMatchJoinSessionJob {
    virtual void dtor();                  // 0x00 slot0 (0x93f46c, b 0x98242c)
    virtual void dtorDeleting();          // 0x08 slot1 (0x93f470, base + operator delete)
    virtual void slot10();                // 0x10 slot2 (0xb4a654, shared nex-job slot)
    virtual void slot18();                // 0x18 slot3 (0xb4a67c, shared nex-job slot)
    virtual void slot20();                // 0x20 slot4 (0x933314, shared nex-job slot)
    virtual void slot28();                // 0x28 slot5 (0x941180)
    virtual void slot30();                // 0x30 slot6 (0x940ee8)
    virtual void slot38();                // 0x38 slot7 (0x940fd0)
    virtual void slot40();                // 0x40 slot8 (0x983158)
    virtual void slot48();                // 0x48 slot9 (0x983180)
    virtual void slot50();                // 0x50 slot10 (0x9831a4)
    virtual void slot58();                // 0x58 slot11 (0x941184)
    virtual void slot60();                // 0x60 slot12 (0x93f494)
    virtual void slot68();                // 0x68 slot13 (0x941174)
    virtual void slot70();                // 0x70 slot14 (0x94077c)
    virtual void slot78();                // 0x78 slot15 (0x940824)
    virtual void slot80();                // 0x80 slot16 (0x940ba8)
    virtual void slot88();                // 0x88 slot17 (0x940bc8)
    uint8_t mBase8[0x118];                // 0x08 — base region (base ctor 0x9823d8), see doc
    uint8_t mPad120[0x40];                // 0x120 — zeroed by ctor (+0x120 qword, +0x128 block, +0x150 qword)
};
}  // namespace nn::pia::inet
