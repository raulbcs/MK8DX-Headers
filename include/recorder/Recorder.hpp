#pragma once

#include <cstdint>

/*
 * Ghost/replay recorder framework (400 binary; layout authority for
 * the family). All addresses are original VMAs. Full codec behavior
 * LAYOUT only.
 *
 * Family: object::RecorderDirector (makeGhostData vt slot 0x98);
 * recorder::Mgr 0x210 (ctor 71007b7634, cell 0x710130f7c8, new
 * 71007aadd4); recorder::Binder 0x288 (ctor FUN_71007aae24, calc
 * FUN_71007aaf68, addChannel FUN_71007ac0cc); recorder::Registry;
 * quant-float factory 71007b9400; QuantChannel factory FUN_71001ca6e8
 * (see recorder/QuantChannel.hpp).
 *
 * Ghost file: per-block substreams of mask+tokens per channel. Decoder
 * FUN_71007aa86c via bridge vt slot +0xd0 = 0x7acd68; encoder
 * FUN_71003acb10 (makeGhostData FUN_71003aca18) materializes frames by
 * calling the same decoder via FUN_71007acc98. Key block = 16x s16
 * key/offset table (FUN_71007a9c5c) + one u64 mask per substream
 * (FUN_71007a9cc0, ring 0x3ffff). Substream = mask u64 -> init (bit0)
 * -> tokens (per set bit 1..63).
 *
 * File channel directory (stored uncompressed in the .dat; ctx setup
 * FUN_71007a8fa8, hdr @file 0xc00): offtbl = hdr+u32[hdr+0x28], nchan =
 * u32[hdr+0x2c], blob = hdr + 4*ceil(u32[hdr+0x10]/64) + 4*u32[hdr+0x20]
 * + 4*nchan + 0x48, blob_len = u32[hdr+0x30] - 4*nchan. sg001: offtbl
 * @0xf04, blob @0xf44..0x1720. dir = {u32 time_key; u16 count; u16 pad;
 * entries[12 B]}; entry = {u32 key; u32 packed; float step}; packed: w
 * = >>17, low16 = init/tail bytes, absent = bit16.
 *
 * Channel key = zlib CRC32 of the registration name (poly 0xEDB88320,
 * CRC fn 0x710062fc50, sanitizer FUN_71007a9704); verified 34/34 + 1
 * hold (key 0x2b78e699, no matching name).
 *
 * Vtable cells (.rela.dyn addends, verified on 400 main.elf):
 *   0x710130fb08 -> 0x71012c4778  async read-thread channel
 *   0x710130fb10 -> 0x71012c50d0  QUANT channel
 *   0x710130fb18 -> 0x71012c4c30  large data channel
 *   0x710130fb20 -> 0x71012c4528  notify/observer, per player
 *   0x710130fb28 -> 0x71012c4650  2nd notify group, per player
 *   0x71013001d8 -> 0x71002037e4  (code) thunk table, mgr+0x298 sub-obj
 *   0x71012fb308 -> 0x71012c3c68  generic ctor-array table (NOT a channel)
 *   rot/trans (71007ae16c): 0x710130f908 -> 0x71012c4358,
 *   0x710130f910 -> 0x71012c4108 (trans), 0x710130f918 -> 0x71012c3fe0
 *
 * NOTE (proven): substream mask = RDP keep-bitmap (FUN_71007b37d8), not
 * a tick mask; substreams are INTERLEAVED in a channel slice, not
 * concatenated (no constant (init,W) pair closes all blocks).
 * NOTE: playback reuses the recording calc (FUN_71007aaf68) as the only
 * write path — no special warp path.
 * OPEN: ch15 = lap counter; its registration call-site is unlocated.
 * NOTE: no RTTI typeinfo names in the 400 binary — "Binder"/"Mgr"/
 * "Registry" are our layout names; only object::RecorderDirector is
 * upstream named.
 */

namespace recorder {
/*
     * Global recorder manager (instance pointer in bss cell
     * 0x710130f7c8; ctor FUN_71007b7634, 0x210 bytes). Gate/state/stream
     * offsets proven by the playback tick FUN_71007b8480.
     */
struct Mgr {
  uint8_t pad00[0x20];
  uint8_t armed;      // 0x020 — tick gate (with +0x22)
  uint8_t enabled;    // 0x021 — calc gate; 0 disables all binders
  uint8_t dirGate;    // 0x022 — gate set by director 0x71003ab8d0
  uint8_t pad23[0x5];
  uint32_t binderCount;  // 0x028 — binder count
  void* binderList;      // 0x030 — binder list
  void* stream;          // 0x058 — stream (frame source)
  uint8_t pad60[0x20];
  void* dataTable;  // 0x080 — base added to per-channel idx for cb args 1
  uint8_t pad88[0x50];
  int32_t state;         // 0x0d8 — state ∈ {0,1,5,6}
  int32_t substate;      // 0x0dc — substate (zeroed at tick)
  int32_t flagOffA;      // 0x0e0 — binder byte offset (added to +0x1bb) for the src gate
  int32_t flagOffB;      // 0x0e4 — binder byte offset (added to +0x1bb) for the s8 seed gate
  uint8_t useMatrixArg;  // 0x0e8 — selects arg layout/seed path in binder calc
  uint8_t padE9[0x7];
  int32_t* tableA;  // 0x0f0 — int table (src read / cb arg 2)
  int32_t* tableB;  // 0x0f8 — int table (dst read / cb arg 3)
  float frameTime;  // 0x100 — frame time f32 (decoded by FUN_71007b8480)
  uint8_t pad104[0x4];
  uint32_t frameKey;  // 0x108 — int key decoded from frameTime
  uint8_t pad10c[0x4];
  float seed;  // 0x110 — frac of frameTime / cb arg 4 seed when binder+0x1b8 clear
  uint8_t pad114[0xfc];
};
// NOTE: binders notified via FUN_71007abd78 (tag 2 when state == 6, else 1);
// calc dispatched through vtable slot +0x100 of context *(mgr+0x00).

/*
 * Playback-side function index (details at the listed addresses):
 *   FUN_710020c6fc  mgr playback setup (new 0x278 Binder @mgr+0x2f0;
 *                   new 0x2e0 PlaybackKartCtx; addChannel)
 *   FUN_7100889278  attach ctx to mgr (gated on byte mgr+0x1d0)
 *   FUN_710069ff88  registry lookup by name key: ret (inner<<16)|entryIdx
 *   FUN_71006a0080  push dispatcher (vt slot +0xa8 = playback PUSH slot)
 *   FUN_71006b9394  name->meta critical-bit trie lookup (meta==0 = absent)
 *   FUN_710062ee28  xorshift128 seed (4x u32) from GetSystemTick
 *   FUN_71007b19f4  PlaybackKartCtx ctor (vptr cell 0x710130fb38+0x10)
 *   FUN_71007b1874  sibling ctx ctor (vptr cell 0x710130fb30+0x10; state
 *                   at +0x2a4, applyLens at +0x294, frame idx +0x290)
 *   FUN_71007b1f8c  per-tick state update + commit (FUN_71006a0058,
 *                   stream vt slot +0x68)
 *   FUN_71007b1460 / FUN_71007b151c  delta-cache ctx pull / write-back
 *                   (flag bytes +0x290/0x291/0x292, mask +0x298, result
 *                   +0x29c, lens triplet +0x2a0/04/08)
 *   FUN_71007b16d0  incremental matrix delta (interior commit 0x7b17ac,
 *                   no own symbol; cache A rows +0x298/0x2a8/0x2b8)
 */

/*
     * Channel binder (ctor FUN_71007aae24; size 0x288; calc
     * FUN_71007aaf68; addChannel FUN_71007ac0cc touches +0x1e8/+0x208
     * and links +0xe8/+0xf8; float-channel setup FUN_71003aef8c stores
     * source at +0x000 and owner at +0x278).
     */
struct Binder {
  void* vtable;      // 0x000 — cell 0x710130f7d0 + 0x10
  uint32_t field08;  // 0x008 — zeroed
  uint8_t pad0c[0x4];  // unproven
  void* vt10;                 // 0x010 — cell 0x710130f7d8
  uint64_t pad18;             // 0x018 — zeroed
  void* vt20;                 // 0x020 — cell 0x710130f7d8
  uint64_t pad28;             // 0x028 — zeroed
  void* vt30;                 // 0x030 — cell 0x710130f7d8
  uint8_t pad38[0x10];        // 0x038 — zeroed (ctor memset 0x38..0x111)
  uint8_t pad_48[0x8];  //0x48 — unproven gap
  void (*calcStep)(Binder*);  // 0x048 — called by calc when +0x1a8 is set
  uint8_t pad50[0x40];  // unproven
  uint8_t pad_90[0x8];  //0x90 — unproven gap
  struct {
    void* obj;
    void (*fn)(void*, void*, void*, void*, float);
  }* list4Begin;   // 0x090 — 4-arg+float cb list
  void* list4End;  // 0x098
  uint8_t padA0[0x8];  // unproven
  uint8_t pad_A8[0x8];  //0xA8 — unproven gap
  struct {
    void* obj;
    void (*fn)(void*);
  }* list1Begin;   // 0x0a8 — 1-arg cb list
  void* list1End;  // 0x0b0
  uint8_t padB8[0xe0];  // unproven
  uint32_t field198;      // 0x198 — zeroed
  int32_t state;          // 0x19c — calc disabled while < 0 (ctor: -1)
  void* src;              // 0x1a0 — live source (calc: primary read path)
  uint8_t flag1a8;        // 0x1a8 — run calcStep before the cb-list tail
  uint8_t pad_1A9[0x7];  //0x1A9 — unproven gap
  void* dst;              // 0x1b0 — fallback source
  uint8_t flag1b8;        // 0x1b8 — seed selection in calc tail
  uint8_t flags1b9[0x2];  // 0x1b9 — zeroed
  uint8_t flags1bb[0x2];  // 0x1bb — gate bytes read via Mgr::flagOffA/B
  uint8_t pad_1BD[0x2];  //0x1BD — unproven gap
  uint8_t pad1bf;       // 0x1BF — unproven padding
  uint64_t field1c0;  // 0x1c0 — zeroed (float-channel flags per setup)
  uint64_t field1c8;  // 0x1c8 — zeroed
  uint32_t field1d0;  // 0x1d0 — zeroed
  int32_t indexA;     // 0x1d4 — channel index into Mgr tables (ctor: -1)
  uint32_t field1d8;  // 0x1d8 — ctor: -1
  int32_t indexB;     // 0x1dc — ctor: -1
  uint8_t pad1e0[0x8];  // unproven
  void* mgrId;            // 0x1e8 — *(Mgr*) read at ctor; must equal registry's +0x1e8
  float eps;              // 0x1f0 — quantization step (ctor 1.0f; quant channel: eps)
  float quantStep;        // 0x1f4 — (exp2f(n)-1)/range for quant channels (ctor 256.0f)
  float quantStepInv;     // 0x1f8 — 1/quantStep (ctor 0.00390625f = 1/256)
  uint8_t flag1fc;        // 0x1fc — 1 (cleared for one quant-channel variant)
  uint8_t pad_1FD[0x3];  //0x1FD — unproven gap
  uint32_t field200;      // 0x200 — zeroed
  uint8_t pad_204[0xC];  //0x204 — unproven gap
  const char* name;       // 0x208 — registration name (NULL until addChannel)
  uint8_t flag210;        // 0x210 — 1
  uint8_t pad_211[0x3];  //0x211 — unproven gap
  uint32_t field214;      // 0x214 — zeroed
  uint32_t field218;      // 0x218 — 1
  uint8_t pad_21C[0x4];  //0x21C — unproven gap
  uint64_t field220;      // 0x220 — zeroed
  uint64_t field228;      // 0x228 — zeroed
  uint64_t field230;      // 0x230 — zeroed
  void* vt238;            // 0x238 — cell 0x710130f7e0 + 0x10
  void* vt240;            // 0x240 — GOT cell 0x71012fae28 + 0x10
  uint8_t pad_248[0x8];  //0x248 — unproven gap
  const char* emptyName;  // 0x248 — "" (rodata 0xed6af8)
  void* vt250;            // 0x250 — cell 0x710130f7f0 + 0x10
  Binder* self;           // 0x258 — self pointer
  void* field260;         // 0x260 — bss cell 0x710130f7e8
  uint64_t field268;      // 0x268 — zeroed
  uint8_t field270;       // 0x270 — zeroed
  uint8_t pad271[0x7];  // unproven
  void* owner;  // 0x278 — owner/target object (calc writes flag byte here)
  uint8_t pad280[0x8];  // unproven
};

/*
     * Registry (owner of the channel lists). addChannel walks head
     * +0xe0 / link +0xe8 and head +0xf0 / link +0xf8; type gate against
     * +0x1e8. Layout from addChannel reads only.
     */
struct Registry {
  uint8_t pad00[0xe0];
  void* head_e0;  // 0x0e0 — first channel list head
  void* next_e8;  // 0x0e8 — node link
  void* head_f0;  // 0x0f0 — second list head
  void* next_f8;  // 0x0f8 — node link
  uint8_t pad100[0xe8];
  void* type;  // 0x1e8 — vtable/owner type checked on registration
};

// FUN_71007b7634 — Mgr constructor (0x210-byte object).
void mgrCtor_71007b7634(Mgr* /*uninitialized*/);

// FUN_71007aadd4 — create global state: the -1 slot array into bss
// cell 0x710130f7c0 and a new Mgr (mgrCtor) into cell 0x710130f7c8.
void createMgr_71007aadd4(void);

// FUN_71003aef8c — per-kart channel setup: constructs the Binder,
// copies the 0x70-byte owner block to binder+0x278, registers it via
// addChannel and initializes the float channels.
void setupKartChannels_71003aef8c(Binder*, void* kart /*+0x70 owner block*/);

// FUN_71007aae24 — Binder constructor.
void recorderBinderCtor_71007aae24(Binder* /*uninitialized, 0x288 bytes*/);

// FUN_71007aaf68 — Binder per-frame calc. Result (0/1) stored at
// binder + 0x21b.
void recorderBinderCalc_71007aaf68(Binder*);

// FUN_71007ac0cc — append a binder to both registry lists and stamp
// its name. Type gate: binder->mgrId == registry->type ==
// *(global mgr cell 0x710130f7c8).
void addChannel_71007ac0cc(Registry*, Binder*, const char* name);

// FUN_71007b9400 — quantized-float channel factory (write side; obj
// 0x280 B). Tokens from eps over [min,max]: <1 -> raw 0x290-class
// variant, >=17 -> saturated quant (cell 0x710130fe78), 11..16 -> pow2
// step, <11 -> fine quant (cell 0x710130fb10; +0x1f4/+0x1f8 = step).
// FUN_71007b95a8 = 0x288 B variant; playback mirror = FUN_71001ca6e8.
Binder* createQuantChannel_71007b9400(void* owner, float min, float max,
                                      float eps);

// FUN_710088ad40 — "rot" channel factory (rodata 0xf0a965): a
// 0x290/0x288 binder pair whose writers copy 3 or 9 ints through
// binder+0x288 indexed by binder+0x1d4.
void createRotChannel_710088ad40(void* ctx, void* param, int selA, int selB);

// FUN_71000c9c64 — affine 3x4 inverse (rows at in+0x0/0x10/0x20,
// translation column +0xc/0x1c/0x2c); returns false on zero det.
int invertAffine3x4_71000c9c64(void* out /*12 floats*/, const void* in);

/*
     * Per-kart replay ctx (0x2e0 bytes; ctor FUN_71007b19f4). Mirrored
     * from the ctor / FUN_71007b1f8c reads.
     */
struct PlaybackKartCtx {
  void* vtable;         // 0x000 — bss cell 0x710130fb38 + 0x10
  uint8_t pad08[0x270];
  void* binder278;      // 0x278 — binder link
  void* binder280;      // 0x280 — binder link
  void* stream;         // 0x288 — stream (registry; table at +0x38)
  uint32_t frameIdx;    // 0x290 — u32 frame idx (u32 store zeroes +0x292)
  int16_t chanA_sub;    // 0x294 — second channel sub (-1 = absent; ctor -1)
  int16_t chanB_sub;    // 0x296 — second channel idx (-1 = absent; ctor -1)
  void* cache;          // 0x298 — cached matrix (raw multiply source; ctor null)
  uint8_t applyLens;    // 0x2a0 — u8; scale state rot columns by lens when set
  uint8_t pad2a1[0x3];
  float lens[3];        // 0x2a4 — lens triplet (sibling binder points here)
  float state[3][4];    // 0x2b0 — 3x4 state, seeded identity by
                        //         recorderCreateRotTransChannels_71007ae16c
                        //         (selA=selB=0)
  uint8_t pad2e0[0x00];
};

// FUN_71007b19f4 — playback ctx ctor (0x2e0; see docblock above).
void playbackKartCtxCtor_71007b19f4(void* ctx, void* stream, int idx, int flag);

// FUN_71007b1874 — sibling playback ctx ctor (vptr cell 0x710130fb30+0x10;
// state at +0x2a4, applyLens u8 at +0x294).
void playbackKartCtxCtorScale_71007b1874(void* ctx, void* stream, int idx,
                                          int flag);

// FUN_71007b1f8c — per-tick state update with commit (FUN_71006a0058,
// stream vtable slot +0x68).
void playbackKartCtxTick_71007b1f8c(void* ctx);

// FUN_71007b1460 / FUN_71007b151c — delta-cache ctx pull / write-back
// pair (family layout: flags +0x290/91/92, mask +0x298, result +0x29c,
// lens +0x2a0/04/08, binder link +0x278).
void playbackDeltaPull_71007b1460(void* ctx);
void playbackDeltaWriteback_71007b151c(void* ctx);

// FUN_71007b16d0 — incremental matrix delta maintenance (interior commit
// at 0x7b17ac has no own symbol).
void playbackDeltaMatrixUpdate_71007b16d0(void* ctx);

// FUN_710020c6fc — mgr-side playback setup.
void playbackSetupMgr_710020c6fc(void* mgr);

// FUN_7100889278 — attach ctx to mgr (gated on byte mgr+0x1d0;
// stream-side register FUN_71007b7758, child+0x214 zeroed).
void playbackAttach_7100889278(void* mgr, void* child);

// FUN_710069ff88 — registry lookup by name key; returns
// (inner << 16) | entryIdx, 0xffffffff on miss.
long registryLookupByName_710069ff88(void* registry, void* key);

// FUN_71006a0080 — push dispatcher over the container entry table
// (+0x30 count, +0x38 table); tail-calls obj vtable slot +0xa8.
void pushDispatcher_71006a0080(void* self);

// FUN_710062ee28 — xorshift128 state seed (4x u32 at t) from
// nn::os::GetSystemTick; caller directorTickSlot17_710013eaec.
void xorshift128Seed_710062ee28(void* t);

// FUN_71006b9394 — name->meta trie lookup; returns meta ptr or NULL.
void* streamableRegistryLookup_71006b9394(void* self, void* key);

/*
     * Kart recorder context (per-kart state consumed by the per-frame
     * calcs; recovered from 0x71003afaa4/0x71003b0124/0x71003af2f4/
     * 0x71003af3f8).
     */
struct KartContext {
  uint8_t pad00[0x280];
  Mgr* mgr;            // 0x280
  void* out;           // 0x288 — output struct for the kart matrix calc rows
  void* matrixStruct;  // 0x290 — source 3x4 read by the point calcs
  uint8_t pad298[0x18];
  void* point;           // 0x2b0 — world point (vec3) in/out
  float snapRows[3][4];  // 0x2b8 — transposed snapshot of *out (rows 0x2b8/0x2c8/0x2d8)
  void* idxHi;           // 0x2e8 — packed byte split: *idxHi = byte >> 3
  void* idxLo;           // 0x2f0 — *idxLo = byte & 7 (see point calcs)
  float invRows[3][4];   // 0x318 — combined inverse rows (0x318/0x328/0x338)
};

/*
     * Static singletons and global cells (bss):
     *   - 0x710130f7c8  Mgr instance pointer
     *   - 0x7101307768..0x71013077d0  Audio/Voice/Item channel instances
     *   - 0x71013078b8..0x71013078d8  five channel instances (Warp/KartBody/
     *                   KartPart/KartWheel/KartEffect writers)
     *   - 0x71013078e8..0x7101307958  per-kart channel instances (Chassis
     *                   through Vehicle), one cell per channel class
     *   - 0x710130f7d0/d8/e0/e8/f0, 0x71012fae28 (GOT)  vtable cells
     *                   consumed by the Binder ctor
     * Each instance getter (getRecorderInstance_*, one per
     * descriptor cluster) returns one cell.
     */
}  // namespace recorder
