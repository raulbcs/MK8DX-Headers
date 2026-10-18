#pragma once

#include <cstdint>

namespace nn::nex {
// nn::nex::CurlHttpConnection — RTTI-named (typeinfo 0x12e5780, name string at
// 0xf852e0, base nn::nex::HttpConnection); vptr 0x12e53e8 (GOT cell 0x1314858
// holds 0x12e53d8 = vt-0x10); ctor 0xa1f7bc; factory news 0x2e0.
// extent 0x2e0 - details: doc/_nn/nex/CurlHttpConnection.md
class CurlHttpConnection {
 public:
  void* vtable;        // 0x00 - 0x12e53e8 (cell 0x1314858 + 0x10)
  char pad08[0x48];    // 0x08..0x4f - unproven gap
  char mSub50[0x150];  // 0x50..0x19f - subobject initialized by base-family
                       //   ctor 0x57a4e0 (bl at 0xa1f820 with this+0x50)
  char pad1a0[0x140];  // 0x1a0..0x2df - second init region (ctor writes
                       //   this+0x1a0 at 0xa1f824; contents unproven)
};
}  // namespace nn::nex
