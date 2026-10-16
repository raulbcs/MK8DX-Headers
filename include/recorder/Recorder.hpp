#pragma once

#include <cstdint>

// Ghost/replay recorder framework (400 binary; layout authority for the
// family). All addresses are original VMAs. LAYOUT only.

namespace recorder {
// recorder::Mgr — instance ptr bss 0x710130f7c8; ctor FUN_71007b7634; 0x210 B.
// Offsets proven by playback tick FUN_71007b8480. extent 0x210 (ctor 71007b7634)
struct Mgr {
  uint8_t pad00[0x20];   // unproven
  uint8_t armed;         // 0x020 — tick gate (with +0x22)
  uint8_t enabled;       // 0x021 — calc gate; 0 disables all binders
  uint8_t dirGate;       // 0x022 — gate set by director 0x71003ab8d0
  uint8_t pad23[0x5];    // unproven
  uint32_t binderCount;  // 0x028 — binder count
  uint8_t pad2c[0x4];    // 0x2c — unproven gap
  void* binderList;      // 0x030 — binder list
  uint8_t pad38[0x20];   // 0x38 — unproven gap
  void* stream;          // 0x058 — stream (frame source)
  uint8_t pad60[0x20];   // unproven
  void* dataTable;       // 0x080 — base added to per-channel idx for cb args 1
  uint8_t pad88[0x50];   // unproven
  int32_t state;         // 0x0d8 — state ∈ {0,1,5,6}
  int32_t substate;      // 0x0dc — substate (zeroed at tick)
  int32_t flagOffA;      // 0x0e0 — binder byte offset (added to +0x1bb) for the src gate
  int32_t flagOffB;      // 0x0e4 — binder byte offset (added to +0x1bb) for the s8 seed gate
  uint8_t useMatrixArg;  // 0x0e8 — selects arg layout/seed path in binder calc
  uint8_t padE9[0x7];    // unproven
  int32_t* tableA;       // 0x0f0 — int table (src read / cb arg 2)
  int32_t* tableB;       // 0x0f8 — int table (dst read / cb arg 3)
  float frameTime;       // 0x100 — frame time f32 (decoded by FUN_71007b8480)
  uint8_t pad104[0x4];   // unproven
  uint32_t frameKey;     // 0x108 — int key decoded from frameTime
  uint8_t pad10c[0x4];   // unproven
  float seed;            // 0x110 — frac of frameTime / cb arg 4 seed when binder+0x1b8 clear
  uint8_t pad114[0xfc];  // unproven
};

// Playback-side function index: doc/recorder/Recorder.md

// recorder::Binder — ctor FUN_71007aae24; 0x288 B; calc FUN_71007aaf68;
// addChannel FUN_71007ac0cc touches +0x1e8/+0x208, links +0xe8/+0xf8;
// float-channel setup FUN_71003aef8c stores src +0x000, owner +0x278.
// extent 0x288 (ctor FUN_71007aae24)
struct Binder {
  void* vtable;               // 0x000 — cell 0x710130f7d0 + 0x10
  uint32_t field08;           // 0x008 — zeroed
  uint8_t pad0c[0x4];         // unproven
  void* vt10;                 // 0x010 — cell 0x710130f7d8
  uint64_t pad18;             // 0x018 — zeroed
  void* vt20;                 // 0x020 — cell 0x710130f7d8
  uint64_t pad28;             // 0x028 — zeroed
  void* vt30;                 // 0x030 — cell 0x710130f7d8
  uint8_t pad38[0x10];        // 0x038 — zeroed (ctor memset 0x38..0x111)
  uint8_t pad_48[0x8];        // 0x48 — unproven gap
  void (*calcStep)(Binder*);  // 0x048 — called by calc when +0x1a8 set
  uint8_t pad50[0x40];        // unproven
  uint8_t pad_90[0x8];        // 0x90 — unproven gap
  struct {
    void* obj;
    void (*fn)(void*, void*, void*, void*, float);
  }* list4Begin;        // 0x090 — 4-arg+float cb list
  void* list4End;       // 0x098
  uint8_t padA0[0x8];   // unproven
  uint8_t pad_A8[0x8];  // 0xA8 — unproven gap
  struct {
    void* obj;
    void (*fn)(void*);
  }* list1Begin;          // 0x0a8 — 1-arg cb list
  void* list1End;         // 0x0b0
  uint8_t padB8[0xe0];    // unproven
  uint32_t field198;      // 0x198 — zeroed
  int32_t state;          // 0x19c — calc disabled while < 0 (ctor: -1)
  void* src;              // 0x1a0 — live source (calc: primary read path)
  uint8_t flag1a8;        // 0x1a8 — run calcStep before the cb-list tail
  uint8_t pad_1A9[0x7];   // 0x1A9 — unproven gap
  void* dst;              // 0x1b0 — fallback source
  uint8_t flag1b8;        // 0x1b8 — seed selection in calc tail
  uint8_t flags1b9[0x2];  // 0x1b9 — zeroed
  uint8_t flags1bb[0x2];  // 0x1bb — gate bytes read via Mgr::flagOffA/B
  uint8_t pad_1BD[0x2];   // 0x1BD — unproven gap
  uint8_t pad1bf;         // 0x1BF — unproven padding
  uint64_t field1c0;      // 0x1c0 — zeroed (float-channel flags per setup)
  uint64_t field1c8;      // 0x1c8 — zeroed
  uint32_t field1d0;      // 0x1d0 — zeroed
  int32_t indexA;         // 0x1d4 — channel index into Mgr tables (ctor: -1)
  uint32_t field1d8;      // 0x1d8 — ctor: -1
  int32_t indexB;         // 0x1dc — ctor: -1
  uint8_t pad1e0[0x8];    // unproven
  void* mgrId;            // 0x1e8 — *(Mgr*) read at ctor; == registry's +0x1e8
  float eps;              // 0x1f0 — quantization step (ctor 1.0f; quant channel: eps)
  float quantStep;        // 0x1f4 — (exp2f(n)-1)/range for quant channels (ctor 256.0f)
  float quantStepInv;     // 0x1f8 — 1/quantStep (ctor 0.00390625f = 1/256)
  uint8_t flag1fc;        // 0x1fc — 1 (cleared for one quant-channel variant)
  uint8_t pad_1FD[0x3];   // 0x1FD — unproven gap
  uint32_t field200;      // 0x200 — zeroed
  uint8_t pad_204[0xC];   // 0x204 — unproven gap
  const char* name;       // 0x208 — registration name (NULL until addChannel)
  uint8_t flag210;        // 0x210 — 1
  uint8_t pad_211[0x3];   // 0x211 — unproven gap
  uint32_t field214;      // 0x214 — zeroed
  uint32_t field218;      // 0x218 — 1
  uint8_t pad_21C[0x4];   // 0x21C — unproven gap
  uint64_t field220;      // 0x220 — zeroed
  uint64_t field228;      // 0x228 — zeroed
  uint64_t field230;      // 0x230 — zeroed
  void* vt238;            // 0x238 — cell 0x710130f7e0 + 0x10
  void* vt240;            // 0x240 — GOT cell 0x71012fae28 + 0x10
  uint8_t pad_248[0x8];   // 0x248 — unproven gap
  const char* emptyName;  // 0x248 — "" (rodata 0xed6af8)
  void* vt250;            // 0x250 — cell 0x710130f7f0 + 0x10
  Binder* self;           // 0x258 — self pointer
  void* field260;         // 0x260 — bss cell 0x710130f7e8
  uint64_t field268;      // 0x268 — zeroed
  uint8_t field270;       // 0x270 — zeroed
  uint8_t pad271[0x7];    // unproven
  void* owner;            // 0x278 — owner/target object (calc writes flag byte here)
  uint8_t pad280[0x8];    // unproven
};

// recorder::Registry — owner of the channel lists. Layout from addChannel
// reads only: heads +0xe0/+0xf0, links +0xe8/+0xf8, type gate vs +0x1e8.
// extent 0x1f0 (type field end; addChannel reads only)
struct Registry {
  uint8_t pad00[0xe0];   // unproven
  void* head_e0;         // 0x0e0 — first channel list head
  void* next_e8;         // 0x0e8 — node link
  void* head_f0;         // 0x0f0 — second list head
  void* next_f8;         // 0x0f8 — node link
  uint8_t pad100[0xe8];  // unproven
  void* type;            // 0x1e8 — vtable/owner type checked on registration
};

// FUN_71007b7634 — Mgr constructor (0x210-byte object).
void mgrCtor_71007b7634(Mgr* /*uninitialized*/);

// FUN_71007aadd4 — create global state (bss cells 0x710130f7c0/0x710130f7c8).
void createMgr_71007aadd4(void);

// FUN_71003aef8c — per-kart channel setup (owner block 0x70 B at kart).
void setupKartChannels_71003aef8c(Binder*, void* kart);

// FUN_71007aae24 — Binder constructor (0x288 B).
void recorderBinderCtor_71007aae24(Binder* /*uninitialized*/);

// FUN_71007aaf68 — Binder per-frame calc; result (0/1) at binder + 0x21b.
void recorderBinderCalc_71007aaf68(Binder*);

// FUN_71007ac0cc — append binder to both registry lists, stamp name.
void addChannel_71007ac0cc(Registry*, Binder*, const char* name);

// FUN_71007b9400 — quantized-float channel factory (write side; 0x280 B;
// variants FUN_71007b95a8 0x288 B; playback mirror FUN_71001ca6e8).
Binder* createQuantChannel_71007b9400(void* owner, float min, float max,
                                      float eps);

// FUN_710088ad40 — "rot" channel factory (rodata 0xf0a965; 0x290/0x288 pair).
void createRotChannel_710088ad40(void* ctx, void* param, int selA, int selB);

// FUN_71000c9c64 — affine 3x4 inverse; returns false on zero det.
int invertAffine3x4_71000c9c64(void* out /*12 floats*/, const void* in);

// PlaybackKartCtx — per-kart replay ctx (0x2e0 B; ctor FUN_71007b19f4).
// extent 0x2e0 (ctor FUN_71007b19f4)
struct PlaybackKartCtx {
  void* vtable;          // 0x000 — bss cell 0x710130fb38 + 0x10
  uint8_t pad08[0x270];  // unproven
  void* binder278;       // 0x278 — binder link
  void* binder280;       // 0x280 — binder link
  void* stream;          // 0x288 — stream (registry; table at +0x38)
  uint32_t frameIdx;     // 0x290 — u32 frame idx (u32 store zeroes +0x292)
  int16_t chanA_sub;     // 0x294 — second channel sub (-1 = absent; ctor -1)
  int16_t chanB_sub;     // 0x296 — second channel idx (-1 = absent; ctor -1)
  void* cache;           // 0x298 — cached matrix (raw multiply source; ctor null)
  uint8_t applyLens;     // 0x2a0 — u8; scale state rot columns by lens when set
  uint8_t pad2a1[0x3];   // unproven
  float lens[3];         // 0x2a4 — lens triplet (sibling binder points here)
  float state[3][4];     // 0x2b0 — 3x4 state; identity seed by FUN_71007ae16c
  uint8_t pad2e0[0x00];  // unproven
};

// FUN_71007b19f4 — playback ctx ctor (0x2e0).
void playbackKartCtxCtor_71007b19f4(void* ctx, void* stream, int idx, int flag);

// FUN_71007b1874 — sibling playback ctx ctor (vptr cell 0x710130fb30+0x10).
void playbackKartCtxCtorScale_71007b1874(void* ctx, void* stream, int idx,
                                         int flag);

// FUN_71007b1f8c — per-tick state update with commit (FUN_71006a0058,
// stream vtable slot +0x68).
void playbackKartCtxTick_71007b1f8c(void* ctx);

// FUN_71007b1460 / FUN_71007b151c — delta-cache ctx pull / write-back pair.
void playbackDeltaPull_71007b1460(void* ctx);
void playbackDeltaWriteback_71007b151c(void* ctx);

// FUN_71007b16d0 — incremental matrix delta (interior commit 0x7b17ac).
void playbackDeltaMatrixUpdate_71007b16d0(void* ctx);

// FUN_710020c6fc — mgr-side playback setup.
void playbackSetupMgr_710020c6fc(void* mgr);

// FUN_7100889278 — attach ctx to mgr (gated on byte mgr+0x1d0).
void playbackAttach_7100889278(void* mgr, void* child);

// FUN_710069ff88 — registry lookup by name key; (inner << 16) | entryIdx.
long registryLookupByName_710069ff88(void* registry, void* key);

// FUN_71006a0080 — push dispatcher; tail-calls obj vtable slot +0xa8.
void pushDispatcher_71006a0080(void* self);

// FUN_710062ee28 — xorshift128 state seed from nn::os::GetSystemTick.
void xorshift128Seed_710062ee28(void* t);

// FUN_71006b9394 — name->meta trie lookup; returns meta ptr or NULL.
void* streamableRegistryLookup_71006b9394(void* self, void* key);

// KartContext — per-kart state for the per-frame calcs (recovered from
// 0x71003afaa4 / 0x71003b0124 / 0x71003af2f4 / 0x71003af3f8).
// extent 0x348 (last field end 0x318+0x30; recovered from the calcs)
struct KartContext {
  uint8_t pad00[0x280];  // unproven
  Mgr* mgr;              // 0x280
  void* out;             // 0x288 — output struct for the kart matrix calc rows
  void* matrixStruct;    // 0x290 — source 3x4 read by the point calcs
  uint8_t pad298[0x18];  // unproven
  void* point;           // 0x2b0 — world point (vec3) in/out
  float snapRows[3][4];  // 0x2b8 — transposed snapshot of *out (0x2b8/0x2c8/0x2d8)
  void* idxHi;           // 0x2e8 — packed byte split: *idxHi = byte >> 3
  void* idxLo;           // 0x2f0 — *idxLo = byte & 7
  uint8_t pad2f8[0x20];  // 0x2f8 — unproven gap
  float invRows[3][4];   // 0x318 — combined inverse rows (0x318/0x328/0x338)
};

// Static singletons and global cells (bss): doc/recorder/Recorder.md
}  // namespace recorder
