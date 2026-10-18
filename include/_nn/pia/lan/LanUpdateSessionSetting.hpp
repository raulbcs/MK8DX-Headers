#pragma once

#include <cstdint>

namespace nn::pia::lan {
/// RTTI-confirmed (N2nn3pia3lan23LanUpdateSessionSettingE). Typeinfo-row vtable:
/// assigned 0x12dca00, real vptr 0x12dca08 (GOT cell 0x13133f8 holds vptr-0x10). No construction sites found.
/// extent 0x1b0 (ctor field stores; lower bound) - details: doc/_nn/pia/lan/LanUpdateSessionSetting.md
struct LanUpdateSessionSetting {
  virtual void dtor();          // 0x00 slot0 (0x974b1c, ret)
  virtual void dtorDeleting();  // 0x08 slot1 (0x974b20, b operator delete 0x60b470)
  virtual void slot10();        // 0x10 slot2 (0x974bac)
  virtual void slot18();        // 0x18 slot3 (0x974c34)
  virtual void slot20();        // 0x20 slot4 (0x974c98)
  virtual void slot28();        // 0x28 slot5 (0x974ca0)
  virtual void slot30();        // 0x30 slot6 (0x99f4a8)
  virtual void slot38();        // 0x38 slot7 (0x99f4b0)
  virtual void slot40();        // 0x40 slot8 (0x99f4c8)
  virtual void slot48();        // 0x48 slot9 (0x974b24)
  uint8_t mBase8[4];            // 0x08 - base region (base ctor 0x99f488: zeroes w +0x8, installs own vptr)
  uint16_t mFieldc;             // 0x0c - set to 0xffff by ctor 0x974abc
  uint16_t mFielde;             // 0x0e - set to 0xffff by ctor 0x974abc
  uint32_t mField10;            // 0x10 - zeroed by ctor 0x974abc
  uint8_t mField14[0x18];       // 0x14 - memset 0 by ctor 0x974abc
  uint8_t mField2c[0x180];      // 0x2c - memset 0 by ctor 0x974abc (tail call)
  uint32_t mField1ac;           // 0x1ac - zeroed by ctor 0x974abc
};
}  // namespace nn::pia::lan
