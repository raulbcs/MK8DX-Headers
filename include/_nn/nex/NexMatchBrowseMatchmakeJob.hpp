#pragma once

#include <cstdint>

namespace nex {

/// NEX matchmake browsing job (row contains NexMatchBrowseMatchmakeJob::WaitFindSessionByOwner,
/// 0x93b7ac, named in functions.csv). Array-allocated (0x688 each) by the manager at 0x932748.
/// extent 0x688 - details: doc/_nn/nex/NexMatchBrowseMatchmakeJob.md
struct NexMatchBrowseMatchmakeJob {
    virtual void dtorLike();  // 0x00 (0x93b6c0: re-installs primary vptr, returns; D1/D2 placement anomalous, see doc)
    virtual void waitFindSessionByOwner();  // 0x08 (0x93b7ac, NexMatchBrowseMatchmakeJob::WaitFindSessionByOwner)
    virtual void slot10();  // 0x10 (0x93b7bc)
    virtual void slot18();  // 0x18 (0x93b7d0)
    virtual void slot20();  // 0x20 (0x93b7e4)
    virtual void slot28();  // 0x28 (0x93b828)
    virtual void slot30();  // 0x30 (0x93b86c)
    virtual void slot38();  // 0x38 (0x93b87c)
    virtual void slot40();  // 0x40 (0x93b8c0)
    virtual void slot48();  // 0x48 (0x93b8d0)
    virtual void slot50();  // 0x50 (0x93b8e0)
    virtual void slot58();  // 0x58 (0x93b8f0)
    virtual void slot60();  // 0x60 (0x93b900)
    virtual void slot68();  // 0x68 (0x93b92c)
    virtual void slot70();  // 0x70 (0x93b97c)
    virtual void reset();   // 0x78 (0x93b6d4, bulk field reset)
    virtual void slot80();  // 0x80 (0x93b7b4, called by ctor tail and by factory 0x932768)
    uint8_t mPad8[0x38];   // 0x08 — ctor fields, see doc (+0x8 arg, +0x10 count, +0x14 globals copy)
    void* mVtable0x40;  // 0x40 - secondary vptr (row 0x12dabc8, vptr 0x12dabd8; slots 0x9118d8, 0x93b9d4, 0x92a7e8, 0x93b778, 0x92adac, 0x93b9d8)
    uint8_t mPad48[0x620]; // 0x48 — job table region (+0x5c 0x400-byte zeroed table), see doc
    void* mMember0x668; // 0x668 - member object vptr (cell 0x1312968+0x10 = 0x12da318)
    uint8_t mPad670[0x8];  // 0x670 — u16 fields zeroed by ctor
    void* mMember0x678; // 0x678 - second member sharing the 0x12da318 vptr
    uint8_t mPad680[0x8];  // 0x680 — gap (+0x682 u32 zeroed by ctor)
};


}  // namespace nex
