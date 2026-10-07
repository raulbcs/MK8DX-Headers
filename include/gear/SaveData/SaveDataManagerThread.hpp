#pragma once

#include <cstdint>

namespace gear
{
    // SaveDataManagerThread — an nn::ae::AppletThread subclass (vptr 0x12d3eb8, cell 0x1311970, n=18, site 0x8b0578, ctor 0x8b050c).
    // Evidence: Thread name "SaveDataManager" passed to the shared nn::ae ctor 0x7100628a54 (SaveData init: userdata.dat / ghostlist.dat); suffixed Thread to avoid clashing with gear::SaveDataManager.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Own field map pending.
    class SaveDataManagerThread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
