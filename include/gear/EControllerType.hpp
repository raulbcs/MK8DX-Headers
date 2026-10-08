#pragma once
#include <cstdint>

namespace gear {
// rodata name table 0xf0d509 (order = table order)
class EControllerType {
 public:
  enum EControllerType_ : int32_t {
    Unknown,               //0x00
    NXDouble,              //0x01
    NXSingle,              //0x02
    NXFullkey,             //0x03
    DRCSwing,              //0x04
    DRCNoSwing,            //0x05
    WiiRemoteSoloSwing,    //0x06
    WiiRemoteSoloNoSwing,  //0x07
    WiiRemoteNunchuk,      //0x08
    WiiRemoteClassic,      //0x09
    WiiUPro,               //0x0A
    WiiUDebug,             //0x0B
    Win,                   //0x0C
    NinDebug               //0x0D
  };

  EControllerType_ mValue;

  const char* text_(int);

  EControllerType() : mValue(EControllerType_::Unknown) {}
  EControllerType(EControllerType_ item) : mValue(item) {}
  EControllerType(int32_t item) : mValue(static_cast<EControllerType_>(item)) {}

  bool operator==(const EControllerType& other) const {
    return mValue == other.mValue;
  }
  bool operator!=(const EControllerType& other) const {
    return mValue != other.mValue;
  }
  bool operator<(const EControllerType& other) const {
    return mValue < other.mValue;
  }

  ~EControllerType() {}
};
}  // namespace gear
