#pragma once

#include <cstdint>

namespace nn::pia::session {
/// RTTI "N2nn3pia7session19MeshLayerControllerE", derives from
/// nn::pia::common::StepSequenceJob (base typeinfo 0x12f8d30, base C1 0xb4a5e0).
/// extent 0x2a8 (ctor stores; derived factory news 0x2b0, ptr at +0x2a8) - details: doc/_nn/pia/session/MeshLayerController.md
struct MeshLayerController {
  virtual void dtor();          // 0x00 slot0 (0x98b868)
  virtual void dtorDeleting();  // 0x08 slot1 (0x98b86c, tail `b operator delete`)
  virtual void slot10();        // 0x10 slot2 (0x98b568, dtor-shaped x8 arg)
  virtual void slot18();        // 0x18 slot3 (0x98b674)
  virtual void slot20();        // 0x20 slot4 (0x98b3a0, large worker)
  virtual void slot28();        // 0x28 slot5 (0x98b504)
  virtual void slot30() = 0;    // 0x30 slot6 (null in table)
  virtual void slot38();        // 0x38 slot7 (0x98b864, `ret`)
  virtual void slot40();        // 0x40 slot8 (0x951678)
  virtual void slot48();        // 0x48 slot9 (0x9516a0)
  virtual uint32_t slot50();    // 0x50 slot10 (0x98b870, `mov w0, wzr`)
  virtual uint32_t slot58();    // 0x58 slot11 (0x98b878, `mov w0, wzr`)
  virtual uint32_t slot60();    // 0x60 slot12 (0x98b880, `mov w0, #1`)
  virtual void slot68();        // 0x68 slot13 (0x9516c0)
  virtual void slot70();        // 0x70 slot14 (0x978544)
  virtual void slot78();        // 0x78 slot15 (0x9516e0)
  virtual void slot80();        // 0x80 slot16 (0x9516f4)
  virtual void slot88();        // 0x88 slot17 (0x9516fc)
  virtual void slot90();        // 0x90 slot18 (0x951704)
  virtual void slot98();        // 0x98 slot19 (0x98b7d8)
  virtual void slotA0();        // 0xa0 slot20 (0x98b7dc)
  virtual void slotA8();        // 0xa8 slot21 (0x95170c)
  virtual void slotB0();        // 0xb0 slot22 (0x951714)
  void* mSecondaryVptr;  // 0x08 — secondary vptr 0x12d7ec8 (cell 0x13123d8)
  void* m10;             // 0x10 — C2 stores this+0x24 (first element array)
  uint8_t mUnits[0x220];  // 0x18 — 4x0x88 entries zeroed by C2 stride-3 loops;
                          // sub-vptr 0x12d7ec8 at 0x90/0x118/0x1a0 (entry+0x78)
  uint8_t mTail[0x70];   // 0x238 — ctor-initialized member region (0x929fc4 at
                         // +0x248; memsets +0x24c/+0x260; [+0x240]=1; zeros to +0x2a7)
};
}  // namespace nn::pia::session
