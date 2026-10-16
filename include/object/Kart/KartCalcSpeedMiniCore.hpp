// Kart speed calculation runtime, "mini core" variant. Vtable .data
// extent 0x300
class KartCalcSpeedMiniCore : public gear::Actor {
 public:
  uint8_t mPad8[0x30];    // 0x8 — sead::hostio::Node base members (see
  uint64_t mField38;      // 0x38 — ctor: [0x13063a0]+0x2a8 secondary vtable
  uint8_t mPad40[0xe8];   // 0x40 — unproven gap; ctor passes this+0x90 as arg to
  uint64_t mField128;     // 0x128 — ctor: [0x13063a0]+0x340 secondary vtable
  uint8_t mPad130[8];     // 0x130 — unproven gap
  void* mField138;        // 0x138 — pointer: copied wholesale into the 0x300 clone
  void* mField140;        // 0x140 — pointer, same clone copy (0x34d1b0/0x34d1b8)
  uint8_t mPad148[0xb0];  // 0x148 — unproven gap
  void* mField1f8;        // 0x1F8 — ctor: 0x133c7b0 (static table 0x133c790,
  void* mField200;        // 0x200 — ctor: 0x133c798 (0x34d408)
  uint64_t mField208;     // 0x208 — ctor: [0x13063a0]+0x370 secondary vtable
  uint8_t mPad210[0x50];  // 0x210 — unproven gap (no ctor write, no located access)
  uint64_t mField260;     // 0x260 — ctor: [0x13063a8]+0x10 vtable (0x34d388)
  uint8_t mField268;      // 0x268 — ctor 2 (0x34d410); loop bound vs 3 at 0x34d468
  uint8_t mPad269;        // 0x269 — ctor zero
  uint8_t mPad26a;        // 0x26a — ctor zero
  uint8_t mField26b;      // 0x26b
  uint32_t mZero26c;      // 0x26c — ctor zero
  void* mSelf270;         // 0x270 — ctor stores `this`
  uint64_t mField278;     // 0x278 — ctor: new[](0x20) array, zeroed 32B
  uint64_t mField280;     // 0x280 — ctor: new[](0x20) array, zeroed 32B
  uint64_t mField288;     // 0x288 — ctor: call result (new[](0x20) at 0x34d43c,
  uint8_t mPad290;        // 0x290 — ctor zero (0x34d374); read as flag arg by
  uint8_t mPad291[0x7];   // 0x291 — untouched by ctor; no located access
  uint64_t mField298;     // 0x298 — ctor: [0x12fb038]+0x10 (0x34d35c-0x34d390)
  uint64_t mZero2a0;      // 0x2a0 — ctor zero (0x34d378)
  uint8_t mPad2a8;        // 0x2a8 — ctor zero (0x34d37c)
  uint8_t mPad2a9[0x7];   // 0x2a9 — untouched by ctor; no located access
  uint32_t mField2b0;     // 0x2b0 — ctor constant 0x437a0000 = 250.0f (0x34d380)
  uint32_t mZero2b4;      // 0x2b4 — ctor zero (0x34d39c)
  uint32_t mZero2b8;      // 0x2b8 — ctor zero (0x34d3a0)
  uint32_t mZero2bc;      // 0x2bc — ctor zero (str 1<<32 at 0x34d3a4 covers
  uint32_t mOne2c0;       // 0x2c0 — ctor 1 (same store, 0x34d3a4)
  uint32_t mField2c4;     // 0x2c4
  uint8_t mField2c8;      // 0x2c8
  uint8_t mZero2c9;       // 0x2c9 — ctor zero (strh wzr at 0x34d3b0 covers
  uint8_t mZero2ca;       // 0x2ca — ctor zero (0x34d3ac); read by
  uint8_t mPad2cb;        // 0x2cb — untouched by ctor; no located access
  uint64_t mField2cc;     // 0x2cc — ctor copy of *(void**)0x12fb0148 (0x34d398-
  uint32_t mField2d4;     // 0x2d4
  uint64_t mField2d8;     // 0x2d8
  uint32_t mField2e0;     // 0x2e0
  uint64_t mField2e4;     // 0x2e4 — ctor copy of *(void**)0x12fb0148 (0x34d3e4-
  uint32_t mField2ec;     // 0x2ec
  uint64_t mField2f0;     // 0x2f0
  uint32_t mField2f8;     // 0x2f8
  uint8_t pad_2FC[0x4];   // 0x2FC — untouched by ctor 0x34d2d8 and by the derived
};
}  // namespace object
