#pragma once

#include <cstdint>

namespace nn::pia::lan {
/// RTTI-confirmed (N2nn3pia3lan22LanMatchJoinSessionJobE). Typeinfo-row vtable:
/// assigned 0x12dcd70, real vptr 0x12dcd78 (GOT cell 0x1313480 holds vt-0x10).
/// Factory 0x96d288: new(0x130) at 0x96d29c; ctor 0x976338.
/// extent 0x130 - details: doc/_nn/pia/lan/LanMatchJoinSessionJob.md
struct LanMatchJoinSessionJob {
    virtual void dtor();                  // 0x00 slot0 (0x976370, b 0x98242c)
    virtual void dtorDeleting();          // 0x08 slot1 (0x976374, base + operator delete)
    virtual void slot10();                // 0x10 slot2 (0xb4a654, shared nex-job slot)
    virtual void slot18();                // 0x18 slot3 (0xb4a67c, shared nex-job slot)
    virtual void slot20();                // 0x20 slot4 (0x933314, shared nex-job slot)
    virtual void slot28();                // 0x28 slot5 (0x976ff0)
    virtual void slot30();                // 0x30 slot6 (0x976f10)
    virtual void slot38();                // 0x38 slot7 (0x976ff4)
    virtual void slot40();                // 0x40 slot8 (0x983158, shared with NexMatchJoinSessionJob)
    virtual void slot48();                // 0x48 slot9 (0x983180)
    virtual void slot50();                // 0x50 slot10 (0x976fc8)
    virtual void slot58();                // 0x58 slot11 (0x941184)
    virtual void joinMatchmakeSession();  // 0x60 slot12 (0x976398, LanMatchJoinSessionJob::JoinMatchmakeSession)
    virtual void slot68();                // 0x68 slot13 (0x9831a0)
    virtual void slot70();                // 0x70 slot14 (0x97696c)
    virtual void slot78();                // 0x78 slot15 (0x976af8)
    virtual void slot80();                // 0x80 slot16 (0x976d44)
    virtual void slot88();                // 0x88 slot17 (0x976e70)
    uint8_t mBase8[0x118];                // 0x08 — base region (base ctor 0x9823d8), see doc
    uint8_t mPad120[0x10];                // 0x120 — zeroed by ctor (+0x120 qword, +0x128 w32)
};
}  // namespace nn::pia::lan
