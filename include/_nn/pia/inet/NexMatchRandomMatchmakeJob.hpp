#pragma once

#include <cstdint>

namespace nn::pia::inet {
/// RTTI-confirmed (N2nn3pia4inet26NexMatchRandomMatchmakeJobE). Typeinfo-row vtable:
/// assigned 0x12db2d0, real vptr 0x12db2d8 (GOT cell 0x1313080 holds vt-0x10).
/// Factory 0x931b38: new(0x170) at 0x931b4c; ctor 0x95171c.
/// extent 0x170 - details: doc/_nn/pia/inet/NexMatchRandomMatchmakeJob.md
struct NexMatchRandomMatchmakeJob {
    virtual void dtor();                  // 0x00 slot0 (0x951760, b 0x99582c)
    virtual void dtorDeleting();          // 0x08 slot1 (0x951764, base + operator delete)
    virtual void slot10();                // 0x10 slot2 (0xb4a654, shared nex-job slot)
    virtual void slot18();                // 0x18 slot3 (0xb4a67c, shared nex-job slot)
    virtual void slot20();                // 0x20 slot4 (0x933314, shared nex-job slot)
    virtual void slot28();                // 0x28 slot5 (0x953684)
    virtual void slot30();                // 0x30 slot6 (0x996b38)
    virtual void slot38();                // 0x38 slot7 (0x953688)
    virtual void slot40();                // 0x40 slot8 (0x953058)
    virtual void slot48();                // 0x48 slot9 (0x95318c)
    virtual void slot50();                // 0x50 slot10 (0x951788)
    virtual void slot58();                // 0x58 slot11 (0x95364c)
    virtual void slot60();                // 0x60 slot12 (0x996ab8)
    virtual void slot68();                // 0x68 slot13 (0x952950)
    virtual void completeProcess();       // 0x70 slot14 (0x952994, RandomMatchmakeJob::CompleteProcess)
    virtual void slot78();                // 0x78 slot15 (0x95296c)
    virtual void slot80();                // 0x80 slot16 (0x952a3c)
    virtual void slot88();                // 0x88 slot17 (0x952d54)
    uint8_t mBase8[0x118];                // 0x08 — base region (base ctor 0x9957dc), see doc
    uint8_t mPad120[0x50];                // 0x120 — zeroed by ctor (+0x120, +0x130..0x13f, +0x140, byte +0x15d, +0x160)
};
}  // namespace nn::pia::inet
