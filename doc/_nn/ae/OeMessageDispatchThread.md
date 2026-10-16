# nn::ae::OeMessageDispatchThread

An nn::ae::AppletThread subclass (vptr 0x12d62a0, cell 0x1311f68, n=18, field ctor 0x8e8fe4). Evidence: Thread name "OeMessageDispatchThread" (rodata 0xf0d6e4, len 0xd, prio 13, attr 0x2000) passed to the shared nn::ae ctor 0x7100628a54 at site 0x8ea6d8; the site then writes 0xf4/0xf5/0xf6/0xf7 and the 0xf8 qword, and stores this at host+0x38. Constructed IN PLACE five times (host offsets 0xc4e8/0xd0e8/0xdce8/0xe8e8/0xf4e8 — stride 0xc00, the object size).

Field ctor: 0x08 u32 = 0; TWENTY 0x98-stride blocks starting at 0x00 (loop to 0xbe0): per block B, B+0x10 u64 = 0, B+0x18 u32 = 0, B+0x1c u8 = 0, memset(B+0x20, 0, 0x84); B+0x00..0x10 untouched (per-block gap). Final: 0xbf0/0xbf8 u64 = 0.

Site extras: 0xf4 u8 = 0; 0xf5 u8 = (nn::oe::GetOperationMode() == 0); 0xf6 u8 = (nn::oe::GetPerformanceMode() == 1); 0xf7 u8 = 0; 0xf8 u64 = 0x1'00000001 (two u32 1s).

## Construction / init order

1. Constructed IN PLACE five times at host offsets 0xc4e8/0xd0e8/0xdce8/0xe8e8/0xf4e8 (stride 0xc00); host+0x38 stores this.
2. Shared nn::ae ctor 0x7100628a54 at site 0x8ea6d8 (name "OeMessageDispatchThread" rodata 0xf0d6e4, prio 13, attr 0x2000) — vptr 0x12d62a0.
3. Field ctor 0x8e8fe4: 0x08 zero; 20x 0x98 blocks (B+0x10/B+0x18/B+0x1c zeros, memset(B+0x20, 0, 0x84)); 0xbf0/0xbf8 zeros.
4. Site extras: 0xf4=0, 0xf5=GetOperationMode()==0, 0xf6=GetPerformanceMode()==1, 0xf7=0, 0xf8=0x1'00000001.
