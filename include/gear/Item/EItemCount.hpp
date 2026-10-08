#pragma once
#include <cstdint>

namespace gear {
// rodata name table 0xee52e5 (order = table order)
class EItemCount {
 public:
  enum EItemCount_ : int32_t {
    Invalid = -1,
    Set1,       //0x00
    Set4,       //0x01
    Set6,       //0x02
    Set8,       //0x03
    Set12,      //0x04
    Set16,      //0x05
    Set24,      //0x06
    Set32,      //0x07
    Set48,      //0x08
    Set5,       //0x09
    Set10,      //0x0A
    Set15,      //0x0B
    Set20,      //0x0C
    Set25,      //0x0D
    Unlimited,  //0x0E
    Set96       //0x0F
  };

  EItemCount_ mValue;

  const char* text_(int);

  EItemCount() : mValue(EItemCount_::Invalid) {}
  EItemCount(EItemCount_ item) : mValue(item) {}
  EItemCount(int32_t item) : mValue(static_cast<EItemCount_>(item)) {}

  bool operator==(const EItemCount& other) const {
    return mValue == other.mValue;
  }
  bool operator!=(const EItemCount& other) const {
    return mValue != other.mValue;
  }
  bool operator<(const EItemCount& other) const {
    return mValue < other.mValue;
  }

  ~EItemCount() {}
};
}  // namespace gear
