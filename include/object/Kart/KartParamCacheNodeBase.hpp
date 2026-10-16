// KartParamCacheNodeBase — address-anchored name (vptr 0x12b2198,
// extent 0x20
class KartParamCacheNodeBase {
 public:
  void* vptr;         // 0x00
  uint8_t pad08[8];   // 0x08 — unproven padding
  void* mLink10;      // 0x10 — ctor stores x1 (node link)
  uint32_t mField18;  // 0x18
  uint8_t pad1c[4];   // 0x1c — unproven padding
};
}  // namespace object
