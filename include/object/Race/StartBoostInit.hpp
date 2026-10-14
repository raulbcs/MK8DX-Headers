#pragma once

// Player start-boost init / start-state refresh — owning class UNNAMED in
// the binary (cluster 0x7100027eb4 / 0x7100028990; slot-id resolver
// FUN_710087f030 of the 0x71008bd374 per-context table cluster maps player
// slot -> id, -1 on gate failure). Docblock-only: all offsets below are
// observed access sites, class identity unproven.

// FUN_7100027eb4 — start-boost init (range 0x7100027eb4..0x7100028188,
// 0x2d4 bytes). x0 = kart start-state object.
//   For slot p in [0,4): s = FUN_710087f030(p); s == -1 -> skip;
//   idx = min(s, 0xc); if byte [+0x48C+idx] set: byte [+0x498+p] = 1.
//   If any flag set: FUN_7100019518(this, [+0x4B0] + ([+0x4A8]==3 ? 0x48 : 0));
//   FUN_71006A0208([+0x328], 2); ([+0x330], 4); ([+0x338], 8).
//   Per body ([+0x98] and [+0x328/+0x330/+0x338]): [body+0x98] |= 1;
//   [body+0x80] = {1.0f, 1.0f}; [body+0x88] = 1.0f; idx0 also gets
//   FUN_71000173C4(this, [+0xD0], 1.0f, 0.0f, 0, [+0x430] + ([+0x428]>=2?8:0), 0);
//   idx1..3 also: byte 0 -> [+0x118] (idx1), FUN_71006A596C(holder=[+0x340/
//   0x348/0x350], 0, [+0x40C/0x410/0x414], 0), [[holder+0x40]+0x10] = 1.0f,
//   vt[[holder+0x40]+0x20](s0=0, s1=[+4], s2=[+8], x0=[+0x10]) result -> [holder+0x40].
//   Finally byte [+0x4C0] = 0.

// FUN_7100028990 — start-state refresh (file_list size 0xdc is a gap-split;
// true range 0x7100028990..0x7100028c2c).
//   - [+0x215] or [+0x214] set -> tail FUN_7100014E78(this, 1).
//   - FUN_7100028C2C(this + 0x440); [+0x71]==1 ? FUN_71000114B8(this,0)
//     : FUN_7100011468(this,0,1.0f).
//   - mgr = getRaceCheckManager_710087FCD0(); g=[mgr+0x24], f=[+0x449]:
//     (g bit2 && f!=0) -> FUN_71006A0208([+0x98], 0) and skip; (f==1) ->
//     w1 = 1 << [+0x4B8] when [+0x4C0]; else w1 = 1; FUN_71006A0208([+0x98], w1).
//   - FUN_7100016EA4(this,0); FUN_7100019B0C(this,0); FUN_710001732C(this).
//   - i in [0,3): if [+0x499+i] and body [+0x328+i*8]: w21 = FUN_710087F030(i+1);
//     when FUN_7100011204(this, w21) && FUN_7100142188(): slot path plays
//     FUN_71006A0208(body, 1 << (i+1)); copies 0x30 bytes from vec3
//     [+0x3E8+i*0xC] into the [+0x364+i*0x30] window and 0x30 bytes from
//     [+0x358+i*0x30] into body+0x50..0x80; [body+0x98] |= 1;
//     FUN_71006A1BC4(body); FUN_71006A245C(body).
//   - Alternate head (0x7100028A60): if [+0x449]==2 and [+0x498]:
//     w20 = FUN_710087F030(0); when FUN_7100011204 && !FUN_7100142188():
//     FUN_71006A0208([+0x98], [+0x480 + w20 (clamp <0xc)] ? 0 : 1).
