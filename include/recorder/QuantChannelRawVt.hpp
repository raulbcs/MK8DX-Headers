#pragma once

#include <cstdint>

// Vtable of the raw (no-quant) s16 vec2 QuantChannel variant - 0x280-byte
// channels built as recorder::Binder head (0x71007aae24) + in-place override
// of the primary vptr at ~54 construction sites; owner ptr lands at +0x278,
// width words +0x1c0/+0x1c4 = 4/4, then recorderAddChannel_71007ac0cc.
// GOT cell 0x12fb308 holds 0x12c3c68 = vt-0x10.
// extent 0x280 - details: doc/recorder/QuantChannelRawVt.md

namespace recorder {
struct QuantChannelRawVt {
  // Slot map (row 0x12c3c78; vptr = row, slots start here). NOTE: slots 0/1
  // are NOT a dtor pair - this row is the meta/interface table:
  //  +0x00 slot 0: 0x71007ad278 (compare arg vs guard-inited singletons,
  //    cells 0x12fb218 / 0x12fade0 rows +0x10)
  //  +0x08 slot 1: 0x71007ad344 (92 B, returns the 0x12fb218 singleton)
  //  +0x10..+0x38 slots 2-7: 0x71007ad3a0..0x71007ad3e8 (getters returning
  //    cells 0x130f890..0x130f8b8 / string 0xf0a94c)
  //  +0x40 slot 8: 0x71007ad3f4 (return 1)
  //  +0x48 slot 9: 0x71007ad3fc (read byte [[this+0x278]] -> [x1+idx +0x1d4])
  //  +0x50 slot 10: 0x71007ad410 (return 1)
  //  +0x58 slot 11: 0x71007ad418 (write bool -> [[this+0x278]])
  //  +0x60 slot 12: 0x71007ad434 (return 1)
  //  +0x68 slot 13: 0x71007ad43c (copy u32)
  //  +0x70..+0x88 slots 14-17: 0x71007ad448/0x71007ad45c/0x71007ad464/
  //    0x71007ad480 (read/write dups; 0x71007ad48c/0x71007ad490 = ret)
  //  +0x90..+0xe0 slots 18-23: 0x71007ab904, 0x71007abca8, 0x71007ac1d8,
  //    0x710001ac84..0x710001ac98 (shared Binder interface set)
  //  +0xe8..+0x130: 0x71007ad3f4, 0x71007ad3fc, 0x71007ad410, 0x71007ad418,
  //    0x71007ad434, 0x71007ad43c, 0x710001addc, 0x710001ade8, 0x710001adf4,
  //    0x710001adf8, 0x71007acd90, 0x71007ac020
};
}  // namespace recorder
