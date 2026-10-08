#pragma once
#include <cstdint>

namespace gear {
// rodata name table 0xee5b64 (order = table order) — online session
// lifecycle states (sits next to the session-error table 0xee4e78)
class ESessionState {
 public:
  enum ESessionState_ : int32_t {
    Null,      //0x00
    Invalid,   //0x01
    Ready,     //0x02
    In,        //0x03
    Run,       //0x04
    Open,      //0x05
    Complete,  //0x06
    Out,       //0x07
    Exit       //0x08
  };

  ESessionState_ mValue;

  const char* text_(int);

  ESessionState() : mValue(ESessionState_::Null) {}
  ESessionState(ESessionState_ item) : mValue(item) {}
  ESessionState(int32_t item) : mValue(static_cast<ESessionState_>(item)) {}

  bool operator==(const ESessionState& other) const {
    return mValue == other.mValue;
  }
  bool operator!=(const ESessionState& other) const {
    return mValue != other.mValue;
  }
  bool operator<(const ESessionState& other) const {
    return mValue < other.mValue;
  }

  ~ESessionState() {}
};
}  // namespace gear
