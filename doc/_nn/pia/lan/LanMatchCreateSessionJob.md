# nn::pia::lan::LanMatchCreateSessionJob

RTTI-confirmed via typeinfo name `N2nn3pia3lan24LanMatchCreateSessionJobE` (0xf80ea0). Typeinfo-row vtable 0x12dcc70: GOT cell 0x1313440 holds vptr-0x10, installed vptr 0x12dcc78; word at 0x12dcc70 points to the embedded typeinfo pair at 0x12dccd0. Offset-to-top 0. 10 slots; slots 2-4 shared job overrides (0xb4a654/0xb4a67c/0x933314).

## Member notes

- Ctor 0x975bcc: calls base C1 0x97e8f4 (the same base used by inet NexMatchCreateSessionJob), zeroes [this+0x84] (w) and [this+0x88] (q), sets [this+0x90] (b) to 1, installs the vptr.
- Base C1 0x97e8f4 (vptr cell 0x13136a8, slot0 0x97e934): zeroes +0x58, inits +0x60 via 0x929ec0, zeroes +0x80 (w).
- Size: lower bound 0x98 from the +0x90 byte. Never constructed (zero code references to the ctor); linked-but-unused SDK code.

## Construction / init order

1. Base C1 0x97e8f4.
2. Ctor 0x975bcc: vptr install, zero +0x84/+0x88, 1 to +0x90.
No construction sites found (unverified end-to-end).
