#pragma once

#include <cstdint>

namespace nn::pia::lan {
/// RTTI-confirmed (N2nn3pia3lan26LanMatchRandomMatchmakeJobE). Typeinfo-row vtable:
/// assigned 0x12dd0b0, real vptr 0x12dd0b8 (GOT cell 0x13135d0 holds vt-0x10).
/// Factory 0x96d210: new(0x158) at 0x96d224; ctor 0x97854c.
/// extent 0x158 - details: doc/_nn/pia/lan/LanMatchRandomMatchmakeJob.md
struct LanMatchRandomMatchmakeJob {
    virtual void dtor();                  // 0x00 slot0 (0x978590, re-vptr + member/base dtor)
    virtual void dtorDeleting();          // 0x08 slot1 (0x9785c8, same + operator delete)
    virtual void slot10();                // 0x10 slot2 (0xb4a654, shared nex-job slot)
    virtual void slot18();                // 0x18 slot3 (0xb4a67c, shared nex-job slot)
    virtual void slot20();                // 0x20 slot4 (0x933314, shared nex-job slot)
    virtual void slot28();                // 0x28 slot5 (0x979440)
    virtual void slot30();                // 0x30 slot6 (0x979414)
    virtual void slot38();                // 0x38 slot7 (0x953688, shared with inet RandomMatchmake twin)
    virtual void slot40();                // 0x40 slot8 (0x979354)
    virtual void slot48();                // 0x48 slot9 (0x979444)
    virtual void randomMatchmake();       // 0x50 slot10 (0x978608, LanMatchRandomMatchmakeJob::RandomMatchmake)
    virtual void slot58();                // 0x58 slot11 (0x996b34)
    virtual void slot60();                // 0x60 slot12 (0x996ab8, shared with inet twin)
    virtual void slot68();                // 0x68 slot13 (0x978974)
    virtual void completeFailure();       // 0x70 slot14 (0x978b74, LanMatchRandomMatchmakeJob::CompleteFailure)
    virtual void completeFailure2();      // 0x78 slot15 (0x9789f4, LanMatchRandomMatchmakeJob::CompleteFailure#2)
    virtual void slot80();                // 0x80 slot16 (0x978d44)
    virtual void slot88();                // 0x88 slot17 (0x979094)
    uint8_t mBase8[0x118];                // 0x08 — base region (base ctor 0x9957dc), see doc
    uint8_t mPad120[0x38];                // 0x120 — subobject init at +0x120; +0x140..0x14f zeroed; byte +0x150 = 1
};
}  // namespace nn::pia::lan
