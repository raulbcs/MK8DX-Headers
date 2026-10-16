#pragma once

#include <cstdint>

// CourseTriggerRegistry — course trigger/object registry singleton;
// 0x4e8-byte singleton (alloc 0x7100383618), ctor chain 383618 -> 3935b0
// -> 3935f0 -> 396540; descriptor byte +0x8 = 4 (registry id).
// Details: doc/gear/Course/TriggerRegistry.md
namespace gear {
namespace Course {
struct TriggerRegistry {
  uint8_t pad_00[0x4e8];  // whole-object extent 0x4e8 from the alloc site
                          // proven sub-offsets: +0x8 registry-id byte (4),
                          // +0x58/+0x68 two 0x18-byte records, +0x80/+0x88
                          // 12-bucket array pointers, +0xf0 sublist head
};
}  // namespace Course
}  // namespace gear
