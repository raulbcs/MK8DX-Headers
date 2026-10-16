// Address-anchored name ("Vt71"): base of the kart body family — 665 vtables (71-101
// extent 0x208
class KartBodyVt71 : public gear::Actor {
 public:
  char mSub38[0xf0];   // 0x38 — embedded member (ctor 0x86838c); the
  uint64_t mField128;  // 0x128 — per-combo data/object: written by the
  uint64_t mField130;  // 0x130 — byte pair read by slot 0xa0
  uint64_t mField138;  // 0x138
  uint64_t mField140;  // 0x140 — sub-object read by slots 0x98/0x1c0
  uint64_t mField148;  // 0x148
  uint64_t mField150;  // 0x150 — zeroed on ctor
  uint64_t mField158;  // 0x158 — zeroed on ctor
  uint32_t mField160;  // 0x160 — zeroed on ctor
  char mPad164[0x2];   // 0x164 — unproven padding
  uint8_t mFlag166;    // 0x166 — flag read by slot 0xa0
  char mPad167[0x41];  // 0x167 — unproven padding
  void* mField1a8;     // 0x1a8 — cleared by the re-init slot 0x18
  char mPad1b0[0x58];  // 0x1b0 — to end (0x208)
};
}  // namespace object
