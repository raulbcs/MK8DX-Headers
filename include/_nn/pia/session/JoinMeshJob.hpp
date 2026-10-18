#pragma once

#include <cstdint>

namespace nn::pia::session {
// nn::pia::session::JoinMeshJob — RTTI-named (typeinfo 0x12ddbb0, name
// "N2nn3pia7session11JoinMeshJobE"); base of nn::pia::inet::InetJoinMeshJob.
// 11 slots; GOT cell 0x13136f8 holds vptr-0x10 (vptr 0x12ddb58).
// extent 0xd8 - details: doc/_nn/pia/session/JoinMeshJob.md
class JoinMeshJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12ddb58 (cell 0x13136f8 + 0x10);
                         //   job-base C1 0xb4a5e0 installs the base vptr
                         //   first
  uint8_t mPad08[0x28];  // 0x08 - job base fields
  struct Result {
    void* a;
    void* b;
  };
  Result m30;        // 0x30 — step result {ptr, null}
  const char* m40;   // 0x40 — step name (MethodTree string)
  void* m58;         // 0x58 — C1 stores 0 (0x97f7a8)
  void* m60;         // 0x60 — 0x20-byte subobject (ctor 0x929ec0, 0x97f7b4);
                     //   freed via 0x929f78 in dtor path 0x97f714
  uint32_t m68;      // 0x68 — C1 stores 0 (0x97f790)
  uint8_t mPad6c[0x2];  // 0x6c - unproven
  uint16_t m6e;      // 0x6e — slot/entry count, copied from u16 at cell
                     //   0x1312748+0xa8 (0x97f7ec-0x97f7f8)
  void* m70;         // 0x70 — array of m6e entries x 0x78 (elem ctor
                     //   0x9b1fe8, 0x97f820 loop)
  uint32_t* m78;     // 0x78 — u32 array of m6e entries (zero-filled)
  uint8_t m80;       // 0x80 — C1 stores 0
  uint8_t m81;       // 0x81 — C1 stores 0 (0x97f7b8)
  uint16_t m82;      // 0x82 — C1 stores 0 (0x97f7bc)
  uint8_t m84;       // 0x84 — C1 stores 3 (0x97f79c)
  uint8_t mPad85[0x13];  // 0x85 - unproven
  void* m98;         // 0x98 — C1 stores 0 (0x97f798)
  uint8_t mPada0[0x8];   // 0xa0 - unproven
  uint64_t mZeroa8;  // 0xa8 — C1 stp xzr (0x97f7ac)
  uint64_t mZerob0;  // 0xb0 — C1 stp xzr
  void* mSubb8;      // 0xb8 — member subobject (ctor 0x929ec0, 0x97f7b4)
  uint8_t mPadc0[0x18];  // 0xc0 - tail padding to 0xd8

  // 64-bit return (state ids: 0 ok, 1 step again, 5 done)
  uint64_t WaitJoinResponse() asm("JoinMeshJob::WaitJoinResponse");
};
}  // namespace nn::pia::session
