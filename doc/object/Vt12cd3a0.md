# object::Vt12cd3a0

PLACEHOLDER name (theme unproven). vptr 0x12cd3a0, 71 slots, offset-to-top 0, typeinfo NULL (game-side).

GOT cell 0x1310c58 holds vptr-0x10 (R_AARCH64_GLOB_DAT addend 0x12cd390). Primary vptr installed at [this] by 0x846534; secondary-base vptr (vt 0x12cd650, cell 0x1310c60) installed at [this+0x90].

Ctor 0x846534: zeroes [this+0x70..0xa8], installs both vptrs, then builds an intrusive linked-list / free-array structure over [this+0xb0..] (self-pointers at +0x8/+0x18/+0x28/+0x38 pairs, node slots of 0x20 bytes). Created by factory 0x83f598: `operator new(0x158)` then 0x846534, result stored at [owner+0x2c8]. Sibling of Vt12cd098 (same factory cluster 0x83f570, same first call 0x841c00, shared vtable slots); neighboring functions call nn::ldn MakeIpv4Address — LAN/ldn-adjacent role unverified.

Extent 0x158 (operator new 0x158 at 0x83f598).

## Construction / init order

- Factory 0x83f598: `mov w0, #0x158; bl operator new(0x60afec)` (0x83f590-0x83f598).
- Ctor 0x846534 at 0x83f5a0: calls 0x841c00 (0x846550), stores vptr 0x12cd3b0 at [this] (0x846554-0x84656c), zeroes 0x70-0x98, stores secondary vptr (cell 0x1310c60, vt 0x12cd650) at [this+0x90] (0x846580-0x846594).
- Member at [this+0xb0]: zeroed head at +0x0, node-pointer table at +0x8/+0x18/+0x28/+0x38/+0x58 (0x846598-0x8465bc).
- Result stored at [owner+0x2c8] (0x83f5a8).
