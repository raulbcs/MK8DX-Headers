#pragma once

#include <cstdint>

namespace nn::pia::session {
/// RTTI "N2nn3pia7session15JointSessionJobE", derives from
/// nn::pia::common::StepSequenceJob (base typeinfo 0x12f8d30, base C1 0xb4a5e0).
/// extent 0x110 (ctor field stores; lower bound) - details: doc/_nn/pia/session/JointSessionJob.md
struct JointSessionJob {
  virtual void dtor();        // 0x00 slot0 (0x983380, D2: reinstalls own vptr, releases +0xd8)
  virtual void dtorDeleting();  // 0x08 slot1 (0x983430, D1 -> D2 -> delete)
  virtual void slot10();      // 0x10 slot2 (0xb4a654, shared pia-job stub)
  virtual void slot18();      // 0x18 slot3 (0xb4a67c, shared pia-job stub)
  virtual void slot20();      // 0x20 slot4 (0x933314)
  virtual void slot28();      // 0x28 slot5 (0x984350, reset: re-runs base C1 0xb4a5e0)
  virtual void slot30() = 0;  // 0x30 slot6 (null in table)
  virtual void slot38();      // 0x38 slot7 (0x983454; also tail-called by C2)
  virtual void slot40();      // 0x40 slot8 (0x983560, reads +0xd8 subobject)
  virtual void slot48() = 0;  // 0x48 slot9 (null in table)
  virtual void slot50() = 0;  // 0x50 slot10 (null in table)
  virtual void slot58() = 0;  // 0x58 slot11 (null in table)
  virtual void slot60() = 0;  // 0x60 slot12 (null in table)
  virtual void slot68() = 0;  // 0x68 slot13 (null in table)
  virtual void slot70() = 0;  // 0x70 slot14 (null in table)
  virtual void slot78() = 0;  // 0x78 slot15 (null in table)
  virtual void slot80();      // 0x80 slot16 (0x977d94, `ret`)
  virtual void slot88();      // 0x88 slot17 (0x977d98, `ret`)
  virtual void slot90();      // 0x90 slot18 (0x977d9c, `ret`)
  virtual void slot98();      // 0x98 slot19 (0x977da0, `ret`)
  virtual void slotA0() = 0;  // 0xa0 slot20 (null in table)
  uint8_t mBase8[0x50];  // 0x08 — StepSequenceJob base region (base C1 0xb4a5e0)
  void* m58;             // 0x58 — zeroed by C2
  uint8_t m60[0x18];     // 0x60 — member in-place ctor 0x929ec0 (unverified size)
  uint8_t mPad78[8];     // 0x78 — ctor writes nothing
  uint64_t m80;          // 0x80 — zeroed by C2
  uint8_t mPad88[0x10];  // 0x88 — ctor writes nothing
  void* m98;             // 0x98 — zeroed by C2, then 0x56810c(this+0x98)
  void* mA0;             // 0xa0 — zeroed by C2
  uint8_t mPadA8[8];     // 0xa8 — ctor writes nothing
  void* mB0;             // 0xb0 — zeroed by C2, then 0x56810c(this+0xb0)
  void* mB8;             // 0xb8 — zeroed by C2
  uint8_t mPadC0[4];     // 0xc0 — ctor writes nothing
  uint32_t mC4;          // 0xc4 — zeroed by C2
  void* mC8;             // 0xc8 — zeroed by C2
  uint32_t mD0;          // 0xd0 — zeroed by C2
  uint8_t mPadD4[4];     // 0xd4 — ctor writes nothing
  void* mD8;             // 0xd8 — subobject ptr, zeroed by C2 (released by D2)
  uint32_t mE0;          // 0xe0 — zeroed by C2
  uint8_t mE4[0xc];      // 0xe4 — packed flags zeroed by C2 (strh/strb/strh/u32)
  uint8_t mPadF0[8];     // 0xf0 — ctor writes nothing
  uint8_t mF8[0x10];     // 0xf8 — zeroed by C2 (stp xzr,xzr)
  uint64_t m108;         // 0x108 — zeroed by C2 (last store reaches 0x10f)
};
}  // namespace nn::pia::session
