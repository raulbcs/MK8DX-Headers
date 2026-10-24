# DriverKart (object/Kart/DriverKart.hpp)

Per-driver model/animation object (`KartUnit + 0x10`).

## Method map (RoGamer97 symbols)

Most methods live inside the FUN_71000d2d58 compiler blob
(0xd2d58..0xe2508). None appear in any vtable (non-virtual):

| Method | Address |
|---|---|
| calcELink | 0xdbfdc |
| calcBoneMotion_ | 0xdc19c |
| calcMaterialAnim_ | 0xdc9fc |
| startActionAnim_ | 0xe0cf4 |
| setFaceAnim_ | 0xe4e6c |
| resetWarpPre | 0xe2508 |
| resetWarpPost | 0xe2518 |

## Field evidence

- resetWarpPre (0xe2508): `*(u32*)(this+0x78) |= 2`.
- resetWarpPost (0xe2518): gates on +0x334 (int32, -1 = idle, bit31 test);
  uses the +0x30/+0x38 resource pair (ldp) — [+0x38][+0x48] u32 selects one
  of two slots ([+0x50]/[+0x60]) fed to 0x6a749c/0x6a6770/0x6a617c; zeroes
  +0x1b0 when [+0x1b4] == 6; resets +0x334 to -1 on the warp-post path.
- calc* methods (x19 = this): frequent accesses at 0x10/0x20/0x38/0x78/0x7c/
  0xc4/0xd0/0x1a0..0x1bc (ELink cluster)/0x334/0x1530; far region 0xf6c..
  0xfb4 (anim-related).
