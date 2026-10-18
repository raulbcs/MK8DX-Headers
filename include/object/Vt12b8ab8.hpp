#pragma once

#include <cstdint>

namespace object {
// Vt12b8ab8 - one class of a 14-sibling resource-record family built by the
// registry loop in FUN_71006ceab0; this instance dispatches the "aglshpp"
// resource type. No RTTI; vptr installed directly (no GOT cell).
// extent 0x50 - details: doc/object/Vt12b8ab8.md
class Vt12b8ab8 {
 public:
  void* vtable;      // 0x00 - vptr 0x12b8ab8 (row 12b8aa8+0x10)
  void* mManager08;  // 0x08 - back-pointer to the owning registry object
                     //   (x22, fields +0xf90/+0xf98 read by its loop)
  uint32_t mTypeId10;// 0x10 - resource type id 0x16
  char pad14[0x04];  // 0x14..0x17 - unproven gap
  void* mHandler18;  // 0x18 - handler fn from table [mgr+0xf98]+0x160
  void* mList20;     // 0x20 - self-referential node (this+0x20 stored twice)
  void* mList28;     // 0x28 - second half of the stp pair
  char pad30[0x10];  // 0x30..0x3f - zeroed at construction
  uint32_t mParam40; // 0x40 - descriptor index 0x18 used by slot 0/1 to index
                     //   the static table at 0x12b7b28 (stride 0x38)
  uint32_t m44;      // 0x44 - return of FUN_710062fd48 (name-string call)
  uint32_t m48;      // 0x48 - return of FUN_710062fd48 (handler call)
  char pad4c[0x04];  // 0x4c..0x4f - tail padding
};
}  // namespace object
