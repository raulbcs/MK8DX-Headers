# recorder::Mgr / Binder / Registry (Recorder.hpp)

All addresses are original VMAs verified against the 400 binary. Full codec behavior: LAYOUT only.

## Family

- object::RecorderDirector (makeGhostData vt slot 0x98)
- recorder::Mgr 0x210 (ctor 71007b7634, cell 0x710130f7c8, new 71007aadd4)
- recorder::Binder 0x288 (ctor FUN_71007aae24, calc FUN_71007aaf68, addChannel FUN_71007ac0cc)
- recorder::Registry
- quant-float factory 71007b9400; QuantChannel factory FUN_71001ca6e8 (see recorder/QuantChannel.md)

## Ghost file

Per-block substreams of mask+tokens per channel. Decoder FUN_71007aa86c via bridge vt slot +0xd0 = 0x7acd68; encoder FUN_71003acb10 (makeGhostData FUN_71003aca18) materializes frames by calling the same decoder via FUN_71007acc98. Key block = 16x s16 key/offset table (FUN_71007a9c5c) + one u64 mask per substream (FUN_71007a9cc0, ring 0x3ffff). Substream = mask u64 -> init (bit0) -> tokens (per set bit 1..63).

File channel directory (stored uncompressed in the .dat; ctx setup FUN_71007a8fa8, hdr @file 0xc00): offtbl = hdr+u32[hdr+0x28], nchan = u32[hdr+0x2c], blob = hdr + 4*ceil(u32[hdr+0x10]/64) + 4*u32[hdr+0x20] + 4*nchan + 0x48, blob_len = u32[hdr+0x30] - 4*nchan. sg001: offtbl @0xf04, blob @0xf44..0x1720. dir = {u32 time_key; u16 count; u16 pad; entries[12 B]}; entry = {u32 key; u32 packed; float step}; packed: w = >>17, low16 = init/tail bytes, absent = bit16.

Channel key = zlib CRC32 of the registration name (poly 0xEDB88320, CRC fn 0x710062fc50, sanitizer FUN_71007a9704); verified 34/34 + 1 hold (key 0x2b78e699, no matching name).

## Vtable cells (.rela.dyn addends, verified on 400 main.elf)

```
0x710130fb08 -> 0x71012c4778  async read-thread channel
0x710130fb10 -> 0x71012c50d0  QUANT channel
0x710130fb18 -> 0x71012c4c30  large data channel
0x710130fb20 -> 0x71012c4528  notify/observer, per player
0x710130fb28 -> 0x71012c4650  2nd notify group, per player
0x71013001d8 -> 0x71002037e4  (code) thunk table, mgr+0x298 sub-obj
0x71012fb308 -> 0x71012c3c68  generic ctor-array table (NOT a channel)
rot/trans (71007ae16c): 0x710130f908 -> 0x71012c4358,
0x710130f910 -> 0x71012c4108 (trans), 0x710130f918 -> 0x71012c3fe0
```

## Notes

- Proven: substream mask = RDP keep-bitmap (FUN_71007b37d8), not a tick mask; substreams are INTERLEAVED in a channel slice, not concatenated (no constant (init,W) pair closes all blocks).
- Playback reuses the recording calc (FUN_71007aaf68) as the only write path — no special warp path.
- Binders notified via FUN_71007abd78 (tag 2 when state == 6, else 1); calc dispatched through vtable slot +0x100 of context *(mgr+0x00).
- OPEN (unlocated): ch15 = lap counter; its registration call-site is unlocated.
- No RTTI typeinfo names in the 400 binary — "Binder"/"Mgr"/"Registry" are our layout names; only object::RecorderDirector is upstream named.

## Playback-side function index

```
FUN_710020c6fc  mgr playback setup (new 0x278 Binder @mgr+0x2f0;
                new 0x2e0 PlaybackKartCtx; addChannel)
FUN_7100889278  attach ctx to mgr (gated on byte mgr+0x1d0)
FUN_710069ff88  registry lookup by name key: ret (inner<<16)|entryIdx
FUN_71006a0080  push dispatcher (vt slot +0xa8 = playback PUSH slot)
FUN_71006b9394  name->meta critical-bit trie lookup (meta==0 = absent)
FUN_710062ee28  xorshift128 seed (4x u32) from GetSystemTick
FUN_71007b19f4  PlaybackKartCtx ctor (vptr cell 0x710130fb38+0x10)
FUN_71007b1874  sibling ctx ctor (vptr cell 0x710130fb30+0x10; state
                at +0x2a4, applyLens at +0x294, frame idx +0x290)
FUN_71007b1f8c  per-tick state update + commit (FUN_71006a0058,
                stream vt slot +0x68)
FUN_71007b1460 / FUN_71007b151c  delta-cache ctx pull / write-back
                (flag bytes +0x290/0x291/0x292, mask +0x298, result
                +0x29c, lens triplet +0x2a0/04/08)
FUN_71007b16d0  incremental matrix delta (interior commit 0x7b17ac,
                no own symbol; cache A rows +0x298/0x2a8/0x2b8)
```

## Function notes

- FUN_71007b7634 — Mgr constructor (0x210-byte object).
- FUN_71007aadd4 — create global state: the -1 slot array into bss cell 0x710130f7c0 and a new Mgr (mgrCtor) into cell 0x710130f7c8.
- FUN_71003aef8c — per-kart channel setup: constructs the Binder, copies the 0x70-byte owner block to binder+0x278, registers it via addChannel and initializes the float channels.
- FUN_71007aae24 — Binder constructor.
- FUN_71007aaf68 — Binder per-frame calc. Result (0/1) stored at binder + 0x21b.
- FUN_71007ac0cc — append a binder to both registry lists and stamp its name. Type gate: binder->mgrId == registry->type == *(global mgr cell 0x710130f7c8).
- FUN_71007b9400 — quantized-float channel factory (write side; obj 0x280 B). Tokens from eps over [min,max]: <1 -> raw 0x290-class variant, >=17 -> saturated quant (cell 0x710130fe78), 11..16 -> pow2 step, <11 -> fine quant (cell 0x710130fb10; +0x1f4/+0x1f8 = step). FUN_71007b95a8 = 0x288 B variant; playback mirror = FUN_71001ca6e8.
- FUN_710088ad40 — "rot" channel factory (rodata 0xf0a965): a 0x290/0x288 binder pair whose writers copy 3 or 9 ints through binder+0x288 indexed by binder+0x1d4.
- FUN_71000c9c64 — affine 3x4 inverse (rows at in+0x0/0x10/0x20, translation column +0xc/0x1c/0x2c); returns false on zero det.
- FUN_71007b19f4 — playback ctx ctor (0x2e0).
- FUN_71007b1874 — sibling playback ctx ctor (vptr cell 0x710130fb30+0x10; state at +0x2a4, applyLens u8 at +0x294).
- FUN_71007b1f8c — per-tick state update with commit (FUN_71006a0058, stream vtable slot +0x68).
- FUN_71007b1460 / FUN_71007b151c — delta-cache ctx pull / write-back pair (family layout: flags +0x290/91/92, mask +0x298, result +0x29c, lens +0x2a0/04/08, binder link +0x278).
- FUN_71007b16d0 — incremental matrix delta maintenance (interior commit at 0x7b17ac has no own symbol).
- FUN_710020c6fc — mgr-side playback setup.
- FUN_7100889278 — attach ctx to mgr (gated on byte mgr+0x1d0; stream-side register FUN_71007b7758, child+0x214 zeroed).
- FUN_710069ff88 — registry lookup by name key; returns (inner << 16) | entryIdx, 0xffffffff on miss.
- FUN_71006a0080 — push dispatcher over the container entry table (+0x30 count, +0x38 table); tail-calls obj vtable slot +0xa8.
- FUN_710062ee28 — xorshift128 state seed (4x u32 at t) from nn::os::GetSystemTick; caller directorTickSlot17_710013eaec.
- FUN_71006b9394 — name->meta trie lookup; returns meta ptr or NULL.

## Kart recorder context

Per-kart state consumed by the per-frame calcs; recovered from 0x71003afaa4 / 0x71003b0124 / 0x71003af2f4 / 0x71003af3f8. See field offsets in include/recorder/Recorder.hpp.

## Static singletons and global cells (bss)

- 0x710130f7c8 — Mgr instance pointer
- 0x7101307768..0x71013077d0 — Audio/Voice/Item channel instances
- 0x71013078b8..0x71013078d8 — five channel instances (Warp/KartBody/KartPart/KartWheel/KartEffect writers)
- 0x71013078e8..0x7101307958 — per-kart channel instances (Chassis through Vehicle), one cell per channel class
- 0x710130f7d0/d8/e0/e8/f0, 0x71012fae28 (GOT) — vtable cells consumed by the Binder ctor

Each instance getter (getRecorderInstance_*, one per descriptor cluster) returns one cell.

## Construction / init order

- FUN_71007aadd4 — create global state: -1 slot array into bss cell 0x710130f7c0, then new Mgr into cell 0x710130f7c8.
- FUN_71007b7634 — Mgr ctor (0x210).
- FUN_71007aae24 — Binder ctor (0x288): zeroed fields as marked in the header; ctor memset region 0x38..0x111; state 0x19c = -1; indexA 0x1d4 / 0x1d8 / 0x1dc = -1; mgrId 0x1e8 = *(Mgr*); name 0x208 = NULL until addChannel; self pointer at 0x258; emptyName 0x248 = "" (rodata 0xed6af8); vptr installs from cells 0x710130f7d0/d8/e0, GOT 0x71012fae28, cell 0x710130f7f0.
- FUN_71007ac0cc — addChannel: append to registry lists (head +0xe0/link +0xe8 and head +0xf0/link +0xf8), stamp name.
- FUN_71003aef8c — setupKartChannels: constructs the Binder, copies the 0x70-byte owner block to binder+0x278, addChannel, initializes the float channels.
- FUN_71007b19f4 — PlaybackKartCtx ctor (0x2e0; vptr cell 0x710130fb38+0x10); sibling ctor FUN_71007b1874 (vptr cell 0x710130fb30+0x10).
- recorderCreateRotTransChannels FUN_71007ae16c — seeds ctx state[3][4] (+0x2b0) identity (selA=selB=0).
