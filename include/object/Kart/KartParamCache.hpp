// KartParamCache — address-anchored name (slot-5 evidence: shared ret
// extent 0x40
class KartParamCache {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[8];     // 0x08 — unproven padding
  uint64_t mZero10;     // 0x10 — ctor zero
  uint64_t mZero18;     // 0x18 — ctor zero
  uint64_t mZero20;     // 0x20 — ctor zero
  uint32_t mParamId28;  // 0x28 — ctor: 0x7100663050([global 0x12fc190]) =
  uint8_t pad2c[4];     // 0x2c — unproven padding
  uint64_t mZero30;     // 0x30 — ctor zero
  uint64_t mZero38;     // 0x38 — ctor zero
};
}  // namespace object
