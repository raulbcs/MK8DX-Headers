#pragma once

#include <cstdint>

#include "_nn/pia/common/String.hpp"

namespace nn::pia::common {
/// FixedString<N> - inline-buffer string deriving from pia::common::String
/// (typeinfo base 0x12d9648). Mapped instantiations are added one per
/// commit; rows are typeinfo slots (vptr-8) and GOT cells hold vptr-0x10.
/// extent 0x20 (base 0x1c + buffer head; full inline size unverified) - details: doc/_nn/pia/common/FixedString.md
template <int N>
struct FixedString : public String {
  // base String extent 0x1c; extent 0x20 (lower bound; full inline size unverified)
  uint8_t mInlineBuffer[4];  // 0x1c - head of the inline buffer; +0x08 data
                             // pointer targets this (+0x1c). Capacity field
                             // +0x10 = 4*N (8 for N=2 at 0x92b658); full
                             // inline extent unverified (shared zero-fill
                             // clears 0x183 B).
};

using FixedString2 = FixedString<2>;  // vptr 0x12d96e8, cell 0x1312848, ti 0x12d9720
using FixedString8 = FixedString<8>;  // vptr 0x12d9748, cell 0x1312858, ti 0x12d9780
using FixedString32 = FixedString<32>; // vptr 0x12d95b8, cell 0x1312850, ti 0x12d95f0
using FixedString64 = FixedString<64>; // vptr 0x12d97a8, cell 0x1312860, ti 0x12d97e0
}  // namespace nn::pia::common
