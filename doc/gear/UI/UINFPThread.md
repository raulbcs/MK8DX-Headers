# gear::UINFPThread

nn::ae::AppletThread subclass (vptr 0x126f470, cell 0x1309f58, n=18, site 0x485a08, ctor 0x485390, alloc 0x240).

Evidence: thread name "UINFP" passed to the shared nn::ae ctor 0x7100628a54 (amiibo/NFP UI context: AmiiboSet, HandleELink).

Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).

## Member layout

- 0x00 — vptr — passed by the caller (cell+0x10)
- 0x8 — 0x240 — unproven gap

## Construction / init order

1. Allocation/creation site 0x485a08 (new 0x240).
2. Ctor entry 0x485390.
3. Shared nn::ae AppletThread base ctor 0x7100628a54 with thread name "UINFP".
