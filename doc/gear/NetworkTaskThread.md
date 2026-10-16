# gear::NetworkTaskThread

nn::ae::AppletThread subclass (vptr 0x12cdd30, cell 0x1310da8, n=18, ctor 0x7100851060, sole alloc 0x83806c: new 0x258).

Evidence: thread name "gear::NetworkTaskThread" (rodata 0xf0c5ed, prio 25, attr 0x10000) passed to the shared nn::ae ctor 0x7100628a54.

## Own region

FIVE 0x38-byte descriptor records at 0xf8 (loop i=0..4, base 0xf8 + i*0x38). Each record (see `Record` below): void* bufA (+0x00, operator new[](0xc0, nothrow, dtor-arg GOT 0x12fae80)), u64 8 (+0x08), u32 0 (+0x10), void* bufB (+0x18, new 0xc0), u64 8 (+0x20), u32 0 (+0x28), u32 0 (+0x30). The scan path (0x8511b4+) walks the records (stride 0x38) and indexes bufB contents with a 0x18 stride.

0x210: member sub-object (ctor 0x628628, extent 0x40, to 0x250).

## Record (0x38 per record)

| Offset | Field | Notes |
|---|---|---|
| +0x00 | bufA | new[](0xc0, nothrow), dtor-arg GOT 0x12fae80 |
| +0x08 | lenA | ctor sets 8 |
| +0x10 | rsv10 | ctor zero |
| +0x14 | pad14 | untouched by ctor |
| +0x18 | bufB | new[](0xc0, nothrow) |
| +0x20 | lenB | ctor sets 8 |
| +0x28 | rsv28 | ctor zero |
| +0x2c | pad2c | untouched by ctor |
| +0x30 | rsv30 | ctor zero |
| +0x34 | pad34 | untouched by ctor |

## Member layout

- 0xf8 — mRecords[5] — 5 x 0x38
- 0x210 — mSub210[0x40] — member sub-object (ctor 0x628628)
- 0x250 — mFlag250 — ctor zero
- 0x251 — pad to alloc size
- extent 0x258 (ctor 0x7100851060, sole alloc 0x83806c: new 0x258)

## Construction / init order

1. Ctor entry 0x7100851060.
2. Shared nn::ae AppletThread base ctor 0x7100628a54, with thread name "gear::NetworkTaskThread" (rodata 0xf0c5ed), prio 25, attr 0x10000.
3. Loop i=0..4: per-record bufA allocation via operator new[](0xc0, nothrow) (dtor-arg GOT 0x12fae80), then bufB allocation new[](0xc0, nothrow); records at 0xf8 + i*0x38.
4. Member sub-object ctor 0x628628 at 0x210 (extent 0x40, to 0x250).
5. 0x250 flag zeroed.
