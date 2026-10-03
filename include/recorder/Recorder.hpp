#pragma once

#include <cstdint>

/*
 * Ghost/replay recorder framework (reverse-engineered from the 400
 * binary; this header is the naming/layout authority for the family).
 *
 * Family map (all addresses are original VMAs):
 *
 *   object::RecorderDirector        scene director; makeGhostData()
 *                                   at vtable slot 0x98 (see
 *                                   object/Directors/RecorderDirector.hpp)
 *   recorder::Mgr                   global manager, 0x210 bytes (ctor
 *                                   recorderMgrCtor_71007b7634); instance
 *                                   pointer in bss cell 0x710130f7c8,
 *                                   created by recorderCreateMgr_71007aadd4
 *   recorder::Binder                ~0x288-byte per-channel binder,
 *                                   ctor FUN_71007aae24, per-frame calc
 *                                   FUN_71007aaf68; registered by
 *                                   addChannel FUN_71007ac0cc; per-kart
 *                                   float/channel setup
 *                                   recorderSetupKartChannels_71003aef8c
 *   recorder::Registry              owner of the two channel lists
 *   recorderCreateQuantChannel_71007b9400
 *                                   quantized-float channel factory
 *                                   (log2/exp2 buckets, 0x280 binder)
 *   recorderCreateRotChannel_710088ad40
 *                                   "rot" channel factory (0x290/0x288
 *                                   binder pair, 3/9-int writers)
 *   recorderSetupKartChannels_71003aef8c / recorderSetupKartStateChannels_71003aed50
 *                                   per-kart float channel setup
 *                                   (p_drive_speed..., mSteerX, p_*)
 *   recorderCalcKartMatrix_71003afaa4 / recorderUpdateKartInvMatrix_71003b0124
 *   recorderCalcKartPointDots_71003af2f4 / recorderCalcKartPosFromDots_71003af3f8
 *                                   per-kart per-frame float calcs
 *                                   (kart recorder context: mgr at
 *                                   +0x280, out at +0x288)
 *   getRecorderInstance_*           one bss cell per channel descriptor
 *                                   cluster (0x71013078b8..0x71013079xx)
 *   getRecorderKart*Name_*          vtable name getters returning the
 *                                   channel registration strings
 *
 * Channel registration names seen in rodata:
 *   RecorderKartUnit, RecorderKartChassis, RecorderKartChassisPackun,
 *   RecorderKartTire, RecorderKartTireMark, RecorderKartDriver,
 *   RecorderKartEvent, RecorderKartVehicleMove, RecorderKartCamera,
 *   RecorderKartVehicleDrift, RecorderKartVehicleDash,
 *   RecorderKartVehicle, RecorderModelMiiExpression, RecorderAudio,
 *   RecorderVoice, RecorderItem
 * plus float channels: p_drive_speed, p_drive_speed_ratio,
 *   p_gravity_vec, p_move_mtx, _dash_charge, p_collided_ground,
 *   p_collided_wall, p_ground_pos, p_air_counter, mGndAttr,
 *   mOnDirtRate, mbAntiGColSpin, p_collided_wall_object, at/up/back/
 *   dist/fovy.
 *
 * Schema/type tags in rodata (replay frame format):
 *   Recorder, RecorderValid, RecorderWarp, RecorderBool, RecorderKey,
 *   RecorderF32[Comp][Loop], RecorderFlg[Comp],
 *   RecorderVector2f/3f[Comp4/6[Auto]], RecorderLnQuatfComp4/6,
 *   RecorderMatrix33f/34f[Comp4/6], Recorder*MtxT, RecorderObject*,
 *   RecorderSkeletalAnm, RecorderMaterialAnm, RecorderModel[...],
 *   RecorderXLink*, RecorderEffect, RecorderRaceEvent.
 *
 * NOTE: the 400 binary carries no RTTI typeinfo names for game
 * classes, so "Binder"/"Mgr"/"Registry" are our layout names; the
 * rodata Recorder* strings above are registration/schema tags, not
 * proven class names. Only object::RecorderDirector is upstream named.
 */

namespace recorder
{
    /*
     * Global recorder manager (instance pointer in bss cell
     * 0x710130f7c8). Layout from Binder ctor/calc reads.
     */
    struct Mgr
    {
        uint8_t pad00[0x21];
        uint8_t enabled;       // 0x021 — calc gate; 0 disables all binders
        uint8_t pad22[0x5e];
        void* dataTable;       // 0x080 — base added to per-channel idx for cb args 1
        uint8_t pad88[0x58];
        int32_t flagOffA;      // 0x0e0 — binder byte offset (added to +0x1bb) for the src gate
        int32_t flagOffB;      // 0x0e4 — binder byte offset (added to +0x1bb) for the s8 seed gate
        uint8_t useMatrixArg;  // 0x0e8 — selects arg layout/seed path in binder calc
        uint8_t padE9[0x7];
        int32_t* tableA;       // 0x0f0 — int table (src read / cb arg 2)
        int32_t* tableB;       // 0x0f8 — int table (dst read / cb arg 3)
        uint8_t pad100[0x10];
        float seed;            // 0x110 — float seed for cb arg 4 when binder+0x1b8 is clear
        uint8_t pad114[0xfc];
    };

    /*
     * Channel binder (ctor FUN_71007aae24; size 0x288; calc
     * FUN_71007aaf68; addChannel FUN_71007ac0cc touches +0x1e8/+0x208
     * and links +0xe8/+0xf8; float-channel setup FUN_71003aef8c stores
     * source at +0x000 and owner at +0x278).
     */
    struct Binder
    {
        void* vtable;          // 0x000 — cell 0x710130f7d0 + 0x10
        uint32_t field08;      // 0x008 — zeroed
        uint8_t pad0c[0x4];
        void* vt10;            // 0x010 — cell 0x710130f7d8
        uint64_t pad18;        // 0x018 — zeroed
        void* vt20;            // 0x020 — cell 0x710130f7d8
        uint64_t pad28;        // 0x028 — zeroed
        void* vt30;            // 0x030 — cell 0x710130f7d8
        uint8_t pad38[0x10];   // 0x038 — zeroed (ctor memset 0x38..0x111)
        void (*calcStep)(Binder*); // 0x048 — called by calc when +0x1a8 is set
        uint8_t pad50[0x40];
        struct { void* obj; void (*fn)(void*, void*, void*, void*, float); }* list4Begin; // 0x090 — 4-arg+float cb list
        void* list4End;        // 0x098
        uint8_t padA0[0x8];
        struct { void* obj; void (*fn)(void*); }* list1Begin;  // 0x0a8 — 1-arg cb list
        void* list1End;        // 0x0b0
        uint8_t padB8[0xe0];
        uint32_t field198;     // 0x198 — zeroed
        int32_t state;         // 0x19c — calc disabled while < 0 (ctor: -1)
        void* src;             // 0x1a0 — live source (calc: primary read path)
        uint8_t flag1a8;       // 0x1a8 — run calcStep before the cb-list tail
        void* dst;             // 0x1b0 — fallback source
        uint8_t flag1b8;       // 0x1b8 — seed selection in calc tail
        uint8_t flags1b9[0x2]; // 0x1b9 — zeroed
        uint8_t flags1bb[0x2]; // 0x1bb — gate bytes read via Mgr::flagOffA/B
        uint8_t pad1bf[0x3];
        uint64_t field1c0;     // 0x1c0 — zeroed (float-channel flags per setup)
        uint64_t field1c8;     // 0x1c8 — zeroed
        uint32_t field1d0;     // 0x1d0 — zeroed
        int32_t indexA;        // 0x1d4 — channel index into Mgr tables (ctor: -1)
        uint32_t field1d8;     // 0x1d8 — ctor: -1
        int32_t indexB;        // 0x1dc — ctor: -1
        uint8_t pad1e0[0x8];
        void* mgrId;           // 0x1e8 — *(Mgr*) read at ctor; must equal registry's +0x1e8
        float eps;             // 0x1f0 — quantization step (ctor 1.0f; quant channel: eps)
        float quantStep;       // 0x1f4 — (exp2f(n)-1)/range for quant channels (ctor 256.0f)
        float quantStepInv;    // 0x1f8 — 1/quantStep (ctor 0.00390625f = 1/256)
        uint8_t flag1fc;       // 0x1fc — 1 (cleared for one quant-channel variant)
        uint32_t field200;     // 0x200 — zeroed
        const char* name;      // 0x208 — registration name (NULL until addChannel)
        uint8_t flag210;       // 0x210 — 1
        uint32_t field214;     // 0x214 — zeroed
        uint32_t field218;     // 0x218 — 1
        uint64_t field220;     // 0x220 — zeroed
        uint64_t field228;     // 0x228 — zeroed
        uint64_t field230;     // 0x230 — zeroed
        void* vt238;           // 0x238 — cell 0x710130f7e0 + 0x10
        void* vt240;           // 0x240 — GOT cell 0x71012fae28 + 0x10
        const char* emptyName; // 0x248 — "" (rodata 0xed6af8)
        void* vt250;           // 0x250 — cell 0x710130f7f0 + 0x10
        Binder* self;          // 0x258 — self pointer
        void* field260;        // 0x260 — bss cell 0x710130f7e8
        uint64_t field268;     // 0x268 — zeroed
        uint8_t field270;      // 0x270 — zeroed
        uint8_t pad271[0x7];
        void* owner;           // 0x278 — owner/target object (calc writes flag byte here)
        uint8_t pad280[0x8];
    };

    /*
     * Registry (owner of the channel lists). addChannel walks head
     * +0xe0 / link +0xe8 and head +0xf0 / link +0xf8; type gate against
     * +0x1e8. Layout from addChannel reads only.
     */
    struct Registry
    {
        uint8_t pad00[0xe0];
        void* head_e0;       // 0x0e0 — first channel list head
        void* next_e8;       // 0x0e8 — node link
        void* head_f0;       // 0x0f0 — second list head
        void* next_f8;       // 0x0f8 — node link
        uint8_t pad100[0xe8];
        void* type;          // 0x1e8 — vtable/owner type checked on registration
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

    // FUN_71007b9400 — quantized-float channel factory. Bucket count
    // from eps over [min,max] via logf/exp2f; descriptor cluster by
    // bucket count (cells 0x710130fb10 <=10 buckets, 0x710130fe80 for
    // 11..16, 0x710130fe78 fallback); fills eps/quantStep/quantStepInv
    // on the non-fallback paths.
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
     * Kart recorder context (per-kart state consumed by the per-frame
     * calcs; recovered from 0x71003afaa4/0x71003b0124/0x71003af2f4/
     * 0x71003af3f8).
     */
    struct KartContext
    {
        uint8_t pad00[0x280];
        Mgr* mgr;              // 0x280
        void* out;             // 0x288 — output struct for the kart matrix calc rows
        void* matrixStruct;    // 0x290 — source 3x4 read by the point calcs
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
     * Each instance getter (getRecorderInstance_* in the decomp, one per
     * descriptor cluster) returns one cell.
     */
}  // namespace recorder
