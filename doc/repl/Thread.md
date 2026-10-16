# repl::Thread

An nn::ae::AppletThread subclass (vptr 0x12c5478, cell 0x130fe68, n=18, ctor 0x7b6d40, sole alloc 0x7b5c00: new 0x108). Evidence: Thread name "repl::Thread" passed to the shared nn::ae ctor 0x7100628a54 via the stack pair at the construction site. Sibling SZSThread shares the exact same shape.

Ctor: 0xf8 = arg x1 (a caller-owned pointer, consumed by the member-init call 0x628dc4(this, arg x4)); 0x100/0x101/0x102 are flag bytes zeroed by the ctor (also re-zeroed by the D2/D0 paths). 0x101 gates the request path (0x7b6e74), 0x102 the teardown path (0x7b6f14: slot-0x30 vcall on [0xf8], then 0x628f24 drain loop).

## Construction / init order

1. Sole alloc 0x7b5c00: operator new(0x108).
2. Ctor 0x7b6d40: shared nn::ae ctor 0x7100628a54 with the "repl::Thread" stack-pair name; member-init 0x628dc4(this, arg x4) consumes arg x1 into 0xf8; flag bytes 0x100/0x101/0x102 zeroed.
3. Teardown D2/D0 paths re-zero the flag bytes; teardown path 0x7b6f14 (slot-0x30 vcall on [0xf8], then 0x628f24 drain loop).
