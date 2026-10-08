#pragma once
#include <cstdint>

namespace gear {
// rodata name table 0xee514c (order = table order)
class ERaceMode {
 public:
  enum ERaceMode_ : int32_t {
    Invalid = -1,
    GP_50,       //0x00
    GP_100,      //0x01
    GP_150,      //0x02
    GP_200,      //0x03
    GP_MIRROR,   //0x04
    GP_RANDOM,   //0x05
    BT_BALLOON,  //0x06
    BT_KEIDORO,  //0x07
    BT_BOMB,     //0x08
    BT_COIN,     //0x09
    BT_SHINE,    //0x0A
    BT_RANDOM    //0x0B
  };

  ERaceMode_ mValue;

  const char* text_(int);

  ERaceMode() : mValue(ERaceMode_::Invalid) {}
  ERaceMode(ERaceMode_ item) : mValue(item) {}
  ERaceMode(int32_t item) : mValue(static_cast<ERaceMode_>(item)) {}

  bool operator==(const ERaceMode& other) const {
    return mValue == other.mValue;
  }
  bool operator!=(const ERaceMode& other) const {
    return mValue != other.mValue;
  }
  bool operator<(const ERaceMode& other) const {
    return mValue < other.mValue;
  }

  ~ERaceMode() {}
};
}  // namespace gear
