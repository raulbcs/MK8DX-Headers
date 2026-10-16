# gear::SaveDataManagerThread

nn::ae::AppletThread subclass (vptr 0x12d3eb8, cell 0x1311970, n=18, site 0x8b0578, ctor 0x8b050c).

Evidence: thread name "SaveDataManager" passed to the shared nn::ae ctor 0x7100628a54 (SaveData init: userdata.dat / ghostlist.dat).

Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).

## Member layout

- 0x00 — vptr — passed by the caller (cell+0x10). Own fields unmapped.

## Construction / init order

1. Allocation/creation site 0x8b0578.
2. Ctor entry 0x8b050c.
3. Shared nn::ae AppletThread base ctor 0x7100628a54 with thread name "SaveDataManager".
