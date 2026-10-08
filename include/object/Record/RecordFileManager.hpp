#pragma once

#include <cstdint>
#include <object/Record/RecordFileKart.hpp>
#include <container/seadPtrArray.h>

namespace object {
class RecordFileManager {
 public:
  // Unproven — Switch ctor not identified (no RTTI, stripped binary);
  // extent fixed by mFileKartRecords at 0x40.
  uint8_t mPad00[0x40];  // unproven - extent fixed by mFileKartRecords at 0x40
  sead::PtrArray<RecordFileKart> mFileKartRecords;

  RecordFileKart* getRecordFileKart(int);
};
}  // namespace object
